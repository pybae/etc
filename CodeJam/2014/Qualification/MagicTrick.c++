#include <iostream>
#include <algorithm>

using namespace std;
int t;
int a, b;
int x;

int A[4];
int B[4];

void skip_newline()
{
    for (int i = 0; i < 4; i++) {
        cin >> x;
    }
}

int main(int argc, const char *argv[])
{
    cin >> t;
    for (int n = 1; n <= t; n++) {
        cin >> a;
        for (int i = 1; i <= 4; i++) {
            if (i == a) {
                for (int j = 0; j < 4; j++) {
                    cin >> x;
                    A[j] = x;
                }
            } else {
                skip_newline();
            }
        }
        
        cin >> b;
        for (int i = 1; i <= 4; i++) {
            if (i == b) {
                for (int j = 0; j < 4; j++) {
                    cin >> x;
                    B[j] = x;
                }
            } else {
                skip_newline();
            }
        }
    
        int count = 0;
        int num = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (A[i] == B[j]) {
                    num = A[i];
                    count++;
                }
            }
        }

        cout << "Case #" << n << ": ";
        if (count == 1) {
            cout << num << endl;
        } else if (count > 1) {
            cout << "Bad magician!" << endl;
        } else {
            cout << "Volunteer cheated!" << endl;
        }
    }
    return 0;
}
