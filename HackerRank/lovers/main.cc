#include <iostream>

using namespace std;

int solve(int n, int r)
{
    if (n >= r && r >= 0) {
        int nr = 1;
        int rr = 1;
        for (int i = 1; i < min(r, n - r); i++) {
            nr *= n;
            rr *= i;
            n -= 1;
        }
        return nr / rr;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int numCases = 0;
    cin >> numCases;
    for (int i = 0; i < numCases; i++) {
        int a;
        int b;
        cin >> a;
        cin >> b;
        cout << solve(a - b + 1, a - 2*b+1) % 100003
    }

    return 0;
}
