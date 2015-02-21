#include <cstdio>
#include <iostream>

using namespace std;

int t, n, c;
string magic, checksum;
string file;

char bitOr(char a, char b) {
    if (a == b) {
        return '0';
    }
    return '1';
}

int main(int argc, char *argv[])
{
    cin >> t;
    while (t--) {
        cin >> n >> c;
        cin >> magic >> checksum;
        cin >> file;

        for (int a = 0; a < n; a++) {
            string nfile = file;

            for (int i = 0; i < c; i++) {
                nfile.append("0");
            }

            nfile[a] = bitOr(nfile[a], '1');

            for (int i = 0; i < file.length(); i++) {
                if (nfile[i] == '1') {
                    for (int j = 0; j < c && i + j < nfile.length(); j++) {
                        nfile[i + j] = bitOr(nfile[i + j], magic[j]);
                    }
                }
            }

            if (nfile.substr(nfile.length() - c, c) == checksum) {
                cout << a << endl;
                break;
            }
        }
    }

    return 0;
}
