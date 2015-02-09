#include <stdio.h>

char s[2][100050]; // the input
int graph[2][100050]; // values are the number of steps to get there
int queue_x[200050]; // the queue of x coordinates
int queue_y[200050]; // the queue of y coordinates

int n;
int k;

int main(int argc, char *argv[])
{
    scanf("%d%d", &n, &k);
    scanf("%s", s[0]);
    scanf("%s", s[1]);

    int visited = 0;  //  the number of nodes visited so far
    int total = 1;    // the number of nodes possible to visit

    graph[0][0] = 1;

    while (visited < total) {
        int x = queue_x[visited];
        int y = queue_y[visited];
        ++visited;

        if (y >= n - k) {
            puts("YES");
            return -1;
        }

        // try to move downwards
        if (y > 0 && s[x][y-1] == '-' && graph[x][y-1] == 0 && y > graph[x][y]) { // unvisited node and water level is sufficient
            graph[x][y-1] = graph[x][y] + 1;
            queue_x[total] = x;
            queue_y[total] = y - 1;
            ++total;
        }

        // try to move upwards
        if (s[x][y+1] == '-' && graph[x][y+1] == 0) { // valid node and unvisited (no need to check water)
            graph[x][y+1] = graph[x][y] + 1;
            queue_x[total] = x;
            queue_y[total] = y + 1;
            ++total;
        }

        // try to jump across + k
        if (s[1-x][y+k] == '-' && graph[1-x][y+k] == 0) { // valid node across the jump and unvisited (no need to check water)
            graph[1-x][y+k] = graph[x][y] + 1;
            queue_x[total] = 1 - x;
            queue_y[total] = y + k;
            ++total;
        }
    }

    puts("NO");
    return 0;
}
