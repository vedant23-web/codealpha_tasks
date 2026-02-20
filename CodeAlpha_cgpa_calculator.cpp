/*CGPA Calculator 
● Take input for the number of courses taken by the student. 
● For each course, input the grade and the credit hours. 
● Calculate the total credits and total grade points (grade × credit hours). 
● Compute the GPA for the semester and then the overall CGPA. 
● Display individual course grades and the final CGPA to the user. */

    
#include <iostream>
#include <iomanip>

int main() {

    int semesters;
    std::cout << "Enter number of semesters: ";
    std::cin >> semesters;

    double overallGradePoints = 0;
    double overallCredits = 0;

    for (int s = 1; s <= semesters; s++) {

        int numCourses;
        double semesterGradePoints = 0;
        double semesterCredits = 0;

        std::cout << "\n--- Semester " << s << " ---\n";
        std::cout << "Enter number of courses: ";
        std::cin >> numCourses;

        for (int i = 1; i <= numCourses; i++) {

            double grade, credit;

            std::cout << "\nCourse " << i << ":\n";
            std::cout << "Enter grade (on 10 scale): ";
            std::cin >> grade;

            std::cout << "Enter credit hours: ";
            std::cin >> credit;

            semesterGradePoints += grade * credit;
            semesterCredits += credit;

            std::cout << "Grade Entered: " << grade
                      << " | Credit Hours: " << credit << "\n";
        }

        double semesterGPA = semesterGradePoints / semesterCredits;

        std::cout << "\nSemester " << s << " GPA: "
                  << std::fixed << std::setprecision(2)
                  << semesterGPA << "\n";

        overallGradePoints += semesterGradePoints;
        overallCredits += semesterCredits;
    }

    double overallCGPA = overallGradePoints / overallCredits;

    std::cout << "\n============================";
    std::cout << "\nFinal Overall CGPA: "
              << std::fixed << std::setprecision(2)
              << overallCGPA << "\n";
    std::cout << "============================\n";

    return 0;
}

