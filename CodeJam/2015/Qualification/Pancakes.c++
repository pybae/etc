#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cassert>

using namespace std;

int t;
int d;
int P[1000];
int max_val;

int count_diners()
{
    int count = 0;
    for (int i = 0; i < d; i++) {
        if (P[i] > 0) {
            count++;
        }
    }

    return count;
}
int compute_value(int index)
{
    int ans = d - 1 - index;
    int second_max = 0;
    if (index > 0)
        second_max = P[index - 1];

    ans += max(second_max, (P[d - 1] + 1) / 2);
    return ans;
}

int split()
{
    int ans = P[d - 1];
    int index = -1;

    for (int i = 0; i < d; i++) {
        int val = compute_value(i);
        if (ans > val) {
            val = ans;
            index = i;
        }
    }

    return index;
}

int main(int argc, char *argv[])
{
    cin >> t;
    for (int n = 1; n <= t; n++) {
        cin >> d;
        max_val = 0;
        memset(P, 0, sizeof P);
        for (int i = 0; i < d; i++) {
            cin >> P[i];
        }

        sort(P, P + d);

        int count = 0;
        while (count_diners() > 0) {
            int index = split();
            if (index > -1) {
                int temp = d;
                for (int i = index; i < temp; i++) {
                    P[d++] = (P[i] + 1) / 2;
                    P[i] /= 2;
                    count++;
                }
                sort(P, P + d);
            } else {
                for (int i = 0; i < d; i++)
                    P[i]--;
                count++;
            }
        }

        printf("Case #%d: %d\n", n, count);
    }

    return 0;
}
