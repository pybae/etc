#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int t, n;

struct Soldier {
    string firstName;
    string lastName;
    int age;
};

bool compareSoldiers(Soldier a, Soldier b) {
    if (a.age != b.age) {
        return a.age < b.age;
    } else if (a.lastName != b.lastName) {
        return a.lastName < b.lastName;
    }
    return a.firstName < b.firstName;
}

int main(int argc, char *argv[])
{
    cin >> t;


    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<Soldier> soldiers(n);

        for (int j = 0; j < n; j++) {
            cin >> soldiers[j].firstName;
            cin >> soldiers[j].lastName;
            cin >> soldiers[j].age;
        }

        sort(soldiers.begin(), soldiers.end(), compareSoldiers);

        cout << "Test Case #" << i << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << soldiers[j].firstName << " " << soldiers[j].lastName << endl;
        }
    }

    return 0;
}
