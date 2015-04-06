#include <iostream>

using namespace std;

int t;
int n = 6;
int m = 7;

char A[6][7];

long long heuristic(char c) {
    long long sum = 0;

    // count horizontal strips
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (A[i][j] == c) {
                count++;
            } else if (count > 0) {
                sum += count * count * count;
                count = 0;
            }
        }
        sum += count * count * count;
    }

    // count vertical strips
    for (int j = 0; j < m; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][j] == c) {
                count++;
            } else if (count > 0) {
                sum += count * count * count;
                count = 0;
            }
        }
        sum += count * count * count;
    }

    return sum;
}

char findMajority() {
    int countR = 0;
    int countB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'R') {
                countR++;
            } else if (A[i][j] == 'B') {
                countB++;
            }
        }
    }

    if (countR == countB) {
        return 'R';
    }
    return 'B';
}

int main(int argc, char *argv[])
{
    cin >> t;
    while (t--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }


        long long ans = -1;
        long long col = -1;
        long long temp = -1;
        long long row = -1;

        char piece = findMajority();
        char swap;
        int j;
        for (j = 0; j < m; j++) {
            int i;
            for (i = 0; i < n; i++) {
                if (A[i][j] != '.') {
                    break;
                }
            }

            if (i == 0) {
                // can't place
            } else if (i == n - 1) {
                swap = A[i][j];
                A[i][j] = piece;
                temp = heuristic(piece);
                if (temp > ans) {
                    ans = temp;
                    col = j;
                    row = i;
                }
                A[i][j] = swap;
            }
            else {
                swap = A[i-1][j];
                A[i-1][j] = piece;
                temp = heuristic(piece);
                if (temp > ans) {
                    ans = temp;
                    col = j;
                    row = i - 1;
                }
                A[i-1][j] = swap;
            }
        }

        cout << piece << " " << col + 1<< endl;
        A[row][col] = piece;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
