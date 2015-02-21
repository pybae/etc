#include <cstdio>

int n, m;

int main(int argc, char *argv[])
{
    scanf("%d%d\n", &n, &m);
    char graph[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            graph[n][m] = getchar();
        }
        getchar();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            putchar(graph[n][m]);
        }
        putchar('\n');
    }



    return 0;
}
