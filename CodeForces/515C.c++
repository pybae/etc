#include <cstdio>

int n;
int factors[10];

int main(int argc, char *argv[])
{
    scanf("%d\n", &n);

    while (n--) {
        switch (getchar()) {
        case '9':
            factors[3] += 2;
            factors[2] -= 2;
        case '8':
            factors[2] += 3;
        case '7':
            factors[7] += 1;
            break;
        case '6':
            factors[3] += 1;
        case '5':
            factors[5] += 1;
            break;
        case '4':
            factors[2] += 2;
        case '3':
            factors[3] += 1;
            break;
        case '2':
            factors[2] += 1;
        case '1':
        case '0':
            break;
        }
    }

    int i = 9;
    while (i--) {
        while (factors[i]--) {
            putchar('0' + i);
        }
    }

    putchar('\n');

    return 0;
}
