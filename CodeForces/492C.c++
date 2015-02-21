#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, r, avg;
int grade, essay;

struct Exam {
    int essay;
    int grade;
};

// can sort by global array reference
bool compareExams(Exam a, Exam b) {
    return a.essay <= b.essay;
}

int main(int argc, char *argv[])
{
    cin >> n >> r >> avg;

    int sum = 0;

    vector<Exam> exams(n);
    for (int i = 0; i < n; i++) {
        cin >> grade >> essay;
        sum += grade;

        exams[i].grade = grade;
        exams[i].essay = essay;
    }

    sort(exams.begin(), exams.end(), compareExams);

    if (sum >= avg * n) {
        cout << "0" << endl;
        return 0;
    }

    // the points I need
    int deficit = avg * n - sum;
    int count   = 0;

    for (int i = 0; i < n; i++) {
        if (deficit - r + exams[i].grade <= 0) {
            count += deficit * exams[i].essay;
            break;
        }
        deficit -= r - exams[i].grade;
        count += (r - exams[i].grade) * exams[i].essay;
    }

    cout << count << endl;
    return 0;
}
