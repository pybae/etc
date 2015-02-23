#include <cstdio>
#include <iostream>

int n1, n2;

using namespace std;

int main(int argc, char *argv[])
{
    cin >> n1 >> n2;
    cout << (n1 > n2 ? "First" : "Second") << endl;
    return 0;
}
