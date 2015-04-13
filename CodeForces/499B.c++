#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int n, m;
string s, t;

int main(int argc, char *argv[])
{
    cin >> n >> m;

    map<string, string> a;
    map<string, string> b;

    while (m--) {
        cin >> s >> t;
        a[s] = t;
        b[t] = s;
    }

    while (n--) {
        cin >> s;
        if (a.find(s) != a.end()) {
            if (a[s].size() < s.size()) {
                cout << a[s] << " ";
            } else {
                cout << s << " ";
            }
        }
        else if (b.find(s) != b.end()) {
            if (b[s].size() <= s.size()) {
                cout << b[s] << " ";
            } else {
                cout << s << " ";
            }
        }
    }

    cout << endl;

    return 0;
}
