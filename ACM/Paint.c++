#include <iostream>
#include <set>

using namespace std;

int t;
int n, m, q;
int r, c;
char l;
char A[100][100];

void floodfill(int r, int c, char l, char prev, set<pair<int, int> >& visited) {
    if (r < 0 || c < 0 || r >= n || c >= m) {
        return;
    }
    if (A[r][c] != prev) {
        return;
    }

    A[r][c] = l;
    visited.insert(pair<int, int>(r, c));

    if (visited.find(pair<int, int>(r-1, c)) == visited.end()) {
        floodfill(r - 1, c, l, prev, visited);
    }
    if (visited.find(pair<int, int>(r+1, c)) == visited.end()) {
        floodfill(r + 1, c, l, prev, visited);
    }
    if (visited.find(pair<int, int>(r, c - 1)) == visited.end()) {
        floodfill(r, c - 1, l, prev, visited);
    }
    if (visited.find(pair<int, int>(r, c + 1)) == visited.end()) {
        floodfill(r, c + 1, l, prev, visited);
    }
}

int main(int argc, char *argv[])
{
    cin >> t;
    while (t--) {
        cin >> n >> m >> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }

        while (q--) {
            cin >> r >> c >> l;

            if (!(r < 0 || c < 0 || r >= n || c >= m)) {
                set<pair<int, int> > visited;
                floodfill(r, c, l, A[r][c], visited);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << A[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}
