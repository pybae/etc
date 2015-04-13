#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n, x;
int l, r;

int main(int argc, char *argv[])
{
    cin >> n >> x;
    int count = 0;
    int cur = 1;

    while (n--) {
        cin >> l >> r;
        count += (l - cur) % x;
        count += (r - l + 1);
        cur = r + 1;
    }

    cout << count << endl;

    return 0;
}
