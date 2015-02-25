#include <cstdio>
#include <iostream>

using namespace std;
string a;
string b;

int main(int argc, char *argv[])
{
    cin >> a >> b;

    int n = a.size() - 1;

    while (a[n] == 'z' && n) {
        a[n] = 'a';
        n--;
    }
    a[n]++;

    cout << (a < b ? a : "No such string") << endl;
    return 0;
}
