#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, r, avg;
long long grade, essay;

struct Exam {
    long long essay;
    long long grade;
};

// can sort by global array reference
bool compareExams(Exam a, Exam b) {
    return a.essay < b.essay;
}

int main(int argc, char *argv[])
{
    cin >> n >> r >> avg;

    long long sum = 0;
    vector<Exam> exams(n);
    for (int i = 0; i < n; i++) {
        cin >> grade >> essay;
        sum  += grade;

        exams[i].grade = grade;
        exams[i].essay = essay;
    }

    sort(exams.begin(), exams.end(), compareExams);

    if (sum >= avg * n) {
        cout << "0" << endl;
        return 0;
    }

    long long deficit = avg * n - sum;
    long long count   = 0;
    long long gap     = 0;

    for (int i = 0; deficit > 0; i++) {
        gap = min(r - exams[i].grade, deficit);
        count += gap * exams[i].essay;
        deficit -= gap;
    }

    cout << count << endl;
    return 0;
}
