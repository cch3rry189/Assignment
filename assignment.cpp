#include <iostream>
#include <iomanip>

using namespace std;

double calculateAverage(int scores[], int numScores) {
    double sum = 0;
    for (int i = 0; i < numScores; i++) {
        sum += scores[i];
    }
    return sum / numScores;
}

char determineGrade(double avgScore) {
    if (avgScore >= 90) {
        return 'A';
    } else if (avgScore >= 80) {
        return 'B';
    } else if (avgScore >= 70) {
        return 'C';
    } else if (avgScore >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void displayResults(string names[], double averages[], char grades[], int numStudents) {
    cout << "\nResults:" << endl;
    cout << "-----------------------------" << endl;
    cout << left << setw(10) << "Student" << " | " << setw(8) << "Average" << " | " << "Grade" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(10) << names[i] << " | " << setw(8) << fixed << setprecision(2) << averages[i] << " | " << grades[i] << endl;
    }
    cout << "-----------------------------" << endl;
}

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    string names[numStudents];
    double averages[numStudents];
    char grades[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> names[i];

        int numScores;
        cout << "Enter number of test scores: ";
        cin >> numScores;

        int scores[numScores];

        for (int j = 0; j < numScores; j++) {
            do {
                cout << "Enter score " << j + 1 << ": ";
                cin >> scores[j];

                if (scores[j] < 0 || scores[j] > 100) {
                    cout << "Please enter a score between 0 - 100.\n";
                }
            } while (scores[j] < 0 || scores[j] > 100);
        }

        averages[i] = calculateAverage(scores, numScores);
        grades[i] = determineGrade(averages[i]);
    }

    displayResults(names, averages, grades, numStudents);

    return 0;
}
