#include <iostream>
#include <math.h>

int B[505][505];
int G[505][505];

int t;
int n, m, k, b;

using namespace std;

int blur(int x, int y) {
    int sum = 0;
    for (int i = x - b / 2; i <= x + b / 2; i++) {
        for (int j = y - b / 2; j <= y + b / 2; j++) {
            // check for out of bounds
            if (i < 0 || j < 0 || i >= n || j >= m) {
                // do nothing (add by zero)
            } else {
                sum += B[i][j];
            }
        }
    }

    return sum;
}

bool out_of_bounds(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

int main(int argc, char *argv[])
{
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        b = 2*k + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> B[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            G[i][0] = blur(i, 0);
            for (int j = 1; j < m; j++) {
                int sum = G[i][j-1];
                for (int x = i - b / 2; x <= i + b / 2; x++) {
                    if (!out_of_bounds(x, j - 1 - (b / 2))) {
                        sum -= B[x][j-(b/2)-1];
                    }
                }

                for (int x = i - b / 2; x <= i + b / 2; x++) {
                    if (!out_of_bounds(x, j + (b / 2) )) {
                        sum += B[x][j+(b/2) ];
                    }
                }

                G[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << round((G[i][j] * 1.0) / (b * b * 1.0)) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
