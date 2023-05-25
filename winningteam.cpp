#include <iostream>
#include <cmath>
using namespace std;

int main() {
    while (true) {
        cout << "Enter the results for your race (write 'done' to exit): ";
        string results;
        cin >> results;
        if (results == "done") {
            break;
        }

        int teamCounts[26] = {0};
        int numTeams = 0;
        int resultsLength = results.length();
        for (int i = 0; i < resultsLength; i++) {
            int index = results[i] - 'A';
            teamCounts[index]++;
            if (teamCounts[index] == 1) {
                numTeams++;
            }
        }

        int numRunners = resultsLength / numTeams;
        cout << "There are " << numTeams << " teams." << endl;
        cout << "Each team has " << numRunners << " runners." << endl;
        cout << "Team Scores:" << endl;

        double maxScore = INFINITY;
        char maxTeam = 'A';
        for (int i = 0; i < 26; i++) {
            if (teamCounts[i] > 0) {
                char teamName = i + 'A';
                int teamSize = teamCounts[i];
                if (teamSize != numRunners) {
                    cout << "Error: Teams have a different number of runners." << endl;
                    break;
                }

                double score = 0;
                for (int j = 0; j < resultsLength; j++) {
                    if (results[j] == teamName) {
                        score += (j + 1);
                    }
                }
                score /= numRunners;
                cout << teamName << " " << score << endl;
                if (score < maxScore) {
                    maxScore = score;
                    maxTeam = teamName;
                }
            }
        }
	cout << "And the winning team is ..... " << maxTeam << "!" << " Team " << maxTeam << " scored a total of " << maxScore << ". Well done!" << endl;
    }

    return 0;
}
