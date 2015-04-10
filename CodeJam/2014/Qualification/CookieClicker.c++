#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int t;
double c, f, x;

int main(int argc, const char *argv[])
{
    cin >> t;
    for (int n = 1; n <= t; n++) {
        cin >> c >> f >> x;
        double sum = 0.0f;
        double rate = 2.0f;
        double steps = 0;

        while (sum < x) {
            if ((x - sum) < c) {
                steps += (x - sum) / rate;
                sum = x;
            } else {
                steps += c / rate;
                sum += c;
                if ((x - sum) / rate > (x - sum + c) / (rate + f)) {
                    rate += f;
                    sum -= c;
                }
            }
        }
        printf("Case #%d: %0.7f\n", n, steps);
    }
    return 0;
}
