#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct to store student information
struct Student {
    string name;
    int rollNumber;
    string course;
    int totalMarks;
};

// Function to create a new student record
void createRecord(vector<Student> &records) {
    Student student;
    cout << "Enter Name of Student: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Roll Number of Student: ";
    cin >> student.rollNumber;
    cout << "Enter Course in which Student is Enrolled: ";
    cin.ignore();
    getline(cin, student.course);
    cout << "Enter Total Marks of Student: ";
    cin >> student.totalMarks;
    records.push_back(student);
    cout << "Record created successfully.\n";
}

// Function to delete a student record
void deleteRecord(vector<Student> &records) {
    int rollNumber;
    cout << "Enter Roll Number of Student to Delete: ";
    cin >> rollNumber;      //taking the roll number of the student as basis

    auto it = find_if(records.begin(), records.end(), [rollNumber](const Student &student) {
        return student.rollNumber == rollNumber;
    });

    if (it != records.end()) {
        records.erase(it);
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

// Function to show all student records
void showRecords(const vector<Student> &records) {
    if (records.empty()) {
        cout << "No records to show.\n";
    } else {
        for (const auto &student : records) {
            cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber<< ", Course: " << student.course << ", Total Marks: " << student.totalMarks << '\n';
        }
    }
}

// Function to search for a student
void searchRecord(const vector<Student> &records) {
    int rollNumber;
    cout << "Enter Roll Number of Student to Search: ";
    cin >> rollNumber;

    auto it = find_if(records.begin(), records.end(), [rollNumber](const Student &student) {
        return student.rollNumber == rollNumber;
    });

    if (it != records.end()) {
        cout << "Record Found:\n";
        cout << "Name: " << it->name << ", Roll Number: " << it->rollNumber
             << ", Course: " << it->course << ", Total Marks: " << it->totalMarks << '\n';
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    vector<Student> records;
    int choice;

    do {
        cout << "\nStudent Record Management System\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Delete Student Record\n";
        cout << "3. Show Student Records\n";
        cout << "4. Search Student Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createRecord(records);
                break;
            case 2:
                deleteRecord(records);
                break;
            case 3:
                showRecords(records);
                break;
            case 4:
                searchRecord(records);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
