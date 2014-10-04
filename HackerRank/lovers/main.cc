#include <iostream>

using namespace std;

int solve(long long n, long long r)
{
    if (n >= r && r >= 0) {
        unsigned long long nr = 1;
        unsigned long long rr = 1;
        for (unsigned long long i = 1; i <= min(r, n - r); i++) {
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
        unsigned long long a;
        unsigned long long b;
        cin >> a;
        cin >> b;
        cout << solve(a - b + 1, a - 2*b+1) % 100003 << endl;
    }

    return 0;
}
