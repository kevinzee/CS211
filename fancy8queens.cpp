#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
        for (int i = 0; i < c; ++i)
                if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
                        return false;
        return true;
}

void print(int q[]) {
        static int numSolutions = 0;

        int i, j, k, l;

        typedef char box[5][7];

        box bb, wb, *board[8][8];

        for (i = 0; i < 5; i++)
                for (j = 0; j < 7; j++) {
                        wb[i][j] = ' ';
                        bb[i][j] = '█';
                }

        static box bq = {
                '█', '█','█', '█', '█', '█', '█',
                '█', ' ', '█', ' ', '█', ' ', '█',
                '█', ' ', ' ', ' ', ' ', ' ', '█',
                '█', ' ', ' ', ' ', ' ', ' ', '█',
                '█', '█', '█', '█', '█', '█', '█'
        };

        static box wq = {
                ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                ' ', '█', ' ', '█', ' ', '█', ' ',
                ' ', '█', '█', '█', '█', '█', ' ',
                ' ', '█', '█', '█', '█', '█', ' ',
                ' ', ' ', ' ', ' ', ' ', ' ', ' '
        };

        for (i = 0; i < 8; i++)
                for (j = 0; j < 8; j++)
                        if ((i + j) % 2 == 0)
                                        board[i][j] = &wb;
                                else
                                        board[i][j] = &bb;
        for (i = 0; i < 8; i++)
                for (j = 0; j < 8; j++)
                        if ((i + q[i]) % 2 == 0)
                                        board[q[i]][i] = &bq;
                                else
                                        board[q[i]][i] = &wq;

        cout << "Solution #" << ++numSolutions << ":\n";

        // Print upper border
        cout << " ";
        for (int i = 0; i < 7*8; i++)
                cout << '_';
        cout << endl;

        //now print board
        for (i = 0; i < 8; i++)
                for (k = 0; k < 5; k++) {
                        cout << " " << char(179); //print left border
                        for (j = 0; j < 8; j++)
                                for (l = 0; l < 7; l++)
                                        cout << (*board[i][j][k][l]);
                                                        cout << char(179) << endl;
                                                        }
        cout << " ";
        for (i = 0; i < 7*8; i++)
                cout << char(196);
        cout << endl;
}

int main() {
        int q[8] = {};   // Initialize the array to 0.
        int c = 0;       // Start on the first column
        while (c >= 0) { // End the loop if you backtrack from the first column
                if (c == 7) { // If you are in the last column, print and backtrack
                        print(q);
                        --c;
                }
                else                  // Otherwise, move to one before the first row of the next column
                        q[++c] = -1;
        while (c >= 0) {
                q[c++];            // Move to the next row
                if (q[c] == 8)     // If you have passed the end of the column, backtrack
                        --c;
                else if (ok(q, c)) // Otherwise, if the queen is ok, break (go back to the beginning of the outer loop)
                        break;
      }
   }
   return 0;
}
