#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int t;
int m;
string s;

int main(int argc, char *argv[])
{
    cin >> t;
    for (int n = 1; n <= t; n++) {
        cin >> m >> s;

        int count = 0;
        int diff = 0;
        for (int i = 0; i <= m; i++) {
            if (count < i && s[i] != '0') {
                diff += i - count;
                count = i;
            }
            count += s[i] - '0';
        }
        printf("Case #%d: %d\n", n, diff);
    }

    return 0;
}
