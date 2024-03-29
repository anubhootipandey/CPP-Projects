#include <iostream>
#include <iomanip>

using namespace std;

// Function to convert grade to grade points
float gradeToPoint(char grade) {
    switch (grade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    float totalCreditHours = 0;
    float totalGradePoints = 0;

    for (int i = 1; i <= numCourses; ++i) {
        float creditHours;
        char grade;

        cout << "Enter credit hours for course " << i << ": ";
        cin >> creditHours;

        cout << "Enter grade for course " << i << " (A/B/C/D/F): ";
        cin >> grade;

        float gradePoints = gradeToPoint(grade);

        if (gradePoints == -1.0) {
            cout << "Invalid grade entered. Exiting program." << endl;
            return 1; // Exit with an error code
        }

        totalCreditHours += creditHours;
        totalGradePoints += (creditHours * gradePoints);
    }

    // Calculate CGPA
    float cgpa = totalGradePoints / totalCreditHours;

    // Display CGPA
    cout << fixed << setprecision(2);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0; // Exit with success
}
