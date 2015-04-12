#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int t;
int x, r, c;

int main(int argc, char *argv[])
{
    cin >> t;
    for (int n = 1; n <= t; n++) {
        cin >> x >> r >> c;
        if (x > r * c) {
            printf("Case #%d: %s\n", n, "RICHARD");
        } else if (r * c % x) {
            printf("Case #%d: %s\n", n, "RICHARD");
        } else if (x > r && x > c) {
            printf("Case #%d: %s\n", n, "RICHARD");
        } else if (x >= 7) {
            printf("Case #%d: %s\n", n, "RICHARD");
        } else if (x <= 2) {
            printf("Case #%d: %s\n", n, "GABRIEL");
        } else if (x == 3 && (r == 1 || c == 1)) {
            printf("Case #%d: %s\n", n, "RICHARD");
        }
        else if (x == 4 && (r == 2 || c == 2)) {
            printf("Case #%d: %s\n", n, "RICHARD");
        } else {
            int right = min(r, c);
            for (int i = 1; i <= (x / 2); i++) {
                if (i > right && (x - i) > right) {
                    printf("Case #%d: %s\n", n, "RICHARD");
                    goto done;
                }
            }
            printf("Case #%d: %s\n", n, "GABRIEL");
        }
    done:
        ;
    }
    return 0;
}
