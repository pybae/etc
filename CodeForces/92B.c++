#include <cstdio>
#include <iostream>

char c;
int count;

int main(int argc, char *argv[])
{
    while ((c = getchar()) != EOF) {
        while (c == '1') {
            ++count;
            c = getchar();
        }
        ++count;
    }

    printf("%d\n", count);
    return 0;
}
