//GPA CALCULATOR

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int numCourses;
    
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    string courseName[numCourses];
    float grade[numCourses];
    int creditHours[numCourses];
    float gradePoints[numCourses];

    int totalCredits = 0;
    float totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < numCourses; i++) {
        
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> courseName[i];

        cout << "Enter grade points: ";
        cin >> grade[i];

        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        gradePoints[i] = grade[i] * creditHours[i];

        totalCredits += creditHours[i];
        totalGradePoints += gradePoints[i];
    }

    // GPA Calculation
    float GPA = totalGradePoints / totalCredits;

    // Assuming only one semester
    float CGPA = GPA;

    // Display Results
    cout << "\n\n----- Course Details -----\n";

    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse Name   : " << courseName[i];
        cout << "\nGrade         : " << grade[i];
        cout << "\nCredit Hours  : " << creditHours[i];
        cout << "\nGrade Points  : " << gradePoints[i];
        cout << "\n---------------------------";
    }

    cout << fixed << setprecision(2);

    cout << "\n\nTotal Credits      : " << totalCredits;
    cout << "\nTotal Grade Points : " << totalGradePoints;
    cout << "\nSemester GPA       : " << GPA;
    cout << "\nFinal CGPA         : " << CGPA << endl;

    return 0;
}
