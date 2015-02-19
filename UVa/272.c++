#include <cstdio>

int main(int argc, char *argv[])
{
    bool s = true;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\"') {
            if (s) {
                putchar('`');
                putchar('`');
            } else {
                putchar('\'');
                putchar('\'');
            }
            s = !s;
        } else {
            putchar(c);
        }
    }

    return 0;
}
