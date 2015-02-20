#include <cstdio>
int n, m;
int b, g;
int total;

bool happyBoys[200];
bool happyGirls[200];

int main(int argc, char *argv[])
{
    scanf("%d%d", &n, &m);

    int x;
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        scanf("%d", &x);
        happyBoys[x] = true;
        total++;
    }

    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        scanf("%d", &x);
        happyGirls[x] = true;
        total++;
    }

    for (int i = 0; i < 2*n*m; i++) {
        if (happyBoys[i % n]) {
            if (!happyGirls[i % m]) {
                happyGirls[i % m] = true;
                total++;
            }
        } else {
            if (happyGirls[i % m]) {
                happyBoys[i % n] = true;
                total++;
            }
        }
    }

    printf("%s\n", total == n + m ? "Yes" : "No");
    return 0;
}
