#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<int> > cache;

vector<int> primeFactors(int n)
{
    int temp = n;

    if (cache.find(n) != cache.end()) {
        return cache[n];
    }

    set<int> factors;
    if (n % 2 == 0) {
        factors.insert(2);
    }

    while (n % 2 == 0) {
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            factors.insert(i);
        }
        while (n % i == 0) {
            n /= i;
        }
    }

    if (n > 2) {
        factors.insert(n);
    }

    cache[temp] = vector<int>(factors.begin(), factors.end());
    return cache[temp];
}

int n;
int m;
int l, r;
int temp;

int main(int argc, char *argv[])
{
    cin >> n;
    vector<vector<int> > x(n);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        x[i] = primeFactors(temp);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;

        int sum = 0;
        for (int j = 0; j < n; j++) {
            vector<int> v = x[j];
            int l_bound = lower_bound(v.begin(), v.end(), l) - v.begin();
            int r_bound = upper_bound(v.begin(), v.end(), r) - v.begin();

            sum += r_bound - l_bound;
        }
        cout << sum << endl;
    }

    return 0;
}
