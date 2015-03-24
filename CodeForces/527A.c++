#include <cstdio>
#include <iostream>

using namespace std;

long long int a;
long long int b;
long long int temp;
long long int i;

int main(int argc, char *argv[])
{
    cin >> a >> b;

    if (a < b) {
        swap(a, b);
    }

    while (b) {
        i += a / b;
        temp = b;
        b = a % b;
        a = temp;
    }

    cout << i << endl;
    return 0;
}
