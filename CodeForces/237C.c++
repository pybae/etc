#include <iostream>

using namespace std;

int a, b, k;

int main(int argc, const char *argv[])
{
    cin >> a >> b >> k;

    bool isPrime[b+1];
    for (int i = 0; i <= b; i++)
        isPrime[i] = true;

    for (int i = 2; i <= b / i; i++) 
        if (isPrime[i])
            for (int j = i * i; j <= b; j += i) 
                isPrime[j] = false;

    isPrime[1] = false;
    int l = a;
    int r = l - 1;
    while (r < b && k > 0) {
        r++;
        if (isPrime[r]) k--;
    }

    if (k > 0) { cout << -1; return 0; }

    while (r < b) {
        if (k > 0 || !isPrime[l] || isPrime[r+1]) {
            if (isPrime[l++]) k--;
            if (isPrime[++r]) k++;
        } else {
            if (isPrime[++r]) k++;
        }
    }

    cout << r - l + 1 << endl;

    return 0;
}
