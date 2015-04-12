#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int t;
int l, x;
string s;

int multiply(int a, int b)
{
    if (a < 0 && b < 0)
        return multiply(abs(a), abs(b));
    else if (a < 0)
        return -1 * multiply(abs(a), b);
    else if (b < 0)
        return -1 * multiply(a, abs(b));

    if (a == 1)
        return b;
    if (b == 1)
        return a;
    if (a == 'i') {
        if (b == 'i') return -1;
        if (b == 'j') return 'k';
        else return -'j';
    }
    if (a == 'j') {
        if (b == 'i') return -'k';
        if (b == 'j') return -1;
        else return 'i';
    }
    if (a == 'k') {
        if (b == 'i') return 'j';
        if (b == 'j') return -'i';
        else return -1;
    }

    return 'd';
}

int power(int base, int exp)
{
    if (base < 0) {
        if (exp % 2)
            return -1 * power(abs(base), exp);
        return power(abs(base), exp);
    }

    if (base == 1)
        return 1;
    if (exp % 2) {
        int left = (exp - 1) / 2;
        if (left % 2)
            return -1 * base;
        else
            return base;
    } else {
        if (exp % 4)
            return -1;
        else
            return 1;
    }
}

int main(int argc, char *argv[])
{
    cin >> t;
    for (int n = 1; n <= t; n++) {
        cin >> l >> x;
        cin >> s;

        int total = 1;
        int i_index = -1;
        int j_index = -1;
        int k_index = -1;
        for (int i = 0; i < l*x; i++) {
            total = multiply(total, s[i % l]);
            if (total == 'i' && i_index == -1) {
                i_index = i;
                total = 1;
            } else if (total == 'j' && i_index > -1 && j_index == -1) {
                j_index = i;
                total = 1;
            } else if (total == 'k' && i_index > -1 && j_index > -1 && k_index == -1) {
                k_index = i;
                total = 1;
            }
        }

        if (i_index < j_index && j_index < k_index && total == 1) {
            printf("Case #%d: %s\n", n, "YES");
        } else {
            printf("Case #%d: %s\n", n, "NO");
        }
    }
    return 0;
}
