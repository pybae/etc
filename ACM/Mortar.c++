#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int t;
double d, m, theta;
double g = -9.8;

int main(int argc, char *argv[])
{
    cin >> t;
    while (t--) {
        cin >> d >> m;
        // the distance traveled is:
        // v^2 * sin(2 theta) / g
        if (abs(m * m / g) < d) {
            cout << "Impossible" << endl;
            continue;
        }

        theta = abs(asin((d * g) / (m * m))/2);

        printf("%.3f\n", theta * 180.000 / M_PI);
    }

    return 0;
}
