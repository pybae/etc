#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int t, c, n, m;
int x, y, p;
int a[100][3];

int main(int argc, char *argv[])
{
    cin >> t;
    while (t--) {
        cin >> c >> n >> m;


        map<pair<int, int>, int> mp;

        for (int i = 0; i < c; i++) {
            cin >> x >> y >> p;
            a[i][0] = x; a[i][1] = y; a[i][2] = p;
            mp[pair<int, int>(x, y)] = p;
        }

        int max = 0;
        int current;

        for (int i = 0; i < c; i++) {
            current = 0;

            cout << a[i][0] << " " << n << endl;

            for (x = a[i][0] - n + 1; a[i][0] + n - 1; x++) {
                for (y = a[i][1] - m + 1; y < a[i][1] + m - 1; y++) {
                    if (mp.find(pair<int, int>(x, y)) != mp.end()) {
                        current += mp[pair<int, int>(x, y)];
                    }
                }
            }
        }
    }

    return 0;
}
