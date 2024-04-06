#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;
};

int main() {
    vector<Student> students;
    string name;
    double grade;
    char choice;

    do {
        cout << "Enter student's name: ";
        cin >> name;
        
        cout << "Enter student's grade: ";
        cin >> grade;

        students.push_back({name, grade});

        cout << "Do you want to enter another student (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    double total = 0.0;
    for (const auto& student : students) {
        total += student.grade;
    }
    double average = total / students.size();

    auto minMax = minmax_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });
    
    cout << "Average grade: " << average << endl;
    cout << "Highest grade: " << minMax.second->grade << " (Student: " << minMax.second->name << ")" << endl;
    cout << "Lowest grade: " << minMax.first->grade << " (Student: " << minMax.first->name << ")" << endl;

    return 0;
}