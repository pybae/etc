#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int t;
int n;

double A[1000];
double B[1000];

int war()
{
    int count = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (A[index] < B[i]) {
            count++;
            index++;
        }
    }

    return n - count;
}

int deceitful_war()
{
    int count = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (B[index] < A[i]) {
            count++;
            index++;
        }
    }

    return count;
}

int main(int argc, char *argv[])
{
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> A[j];
        for (int j = 0; j < n; j++)
            cin >> B[j];

        sort(A, A + n);
        sort(B, B + n);

        printf("Case #%d: %d %d\n", i, deceitful_war(), war());
    }
    return 0;
}
