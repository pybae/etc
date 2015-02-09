// @pybae

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    for (int i = 0; i <= s.size(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            string o = s;
            s.insert(i, 1, c);
            if (equal(s.begin(), s.begin() + s.size()/2, s.rbegin())) {
                cout << s << endl;
                return 0;
            }
            s = o;
        }
    }

    cout << "NA" << endl;
    return 0;
}
