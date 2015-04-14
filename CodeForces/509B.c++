#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int A[100];

int main(int argc, char *argv[])
{
    cin >> n >> k;

    int low = 101;
    int high = -1;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > high) {
            high = A[i];
        }
        if (A[i] < low) {
            low = A[i];
        }
    }

    if (high - low > k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < low; j++)
                cout << 1 << " ";
            for (int j = 1; j <= A[i] - low; j++)
                cout << j << " ";

            cout << endl;
        }
    }

    return 0;
}
