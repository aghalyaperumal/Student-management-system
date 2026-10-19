#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;

            cout << "Enter student ID: ";
            cin >> s.id;

            bool exists = false;
            for (const Student &st : students) {
                if (st.id == s.id) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "ID already exists!\n";
            } else {
                cout << "Enter student name: ";
                getline(cin >> ws, s.name);

                cout << "Enter marks: ";
                cin >> s.marks;

                students.push_back(s);
                cout << "Student added successfully!\n";
            }
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No student records found.\n";
            }

            for (const Student &s : students) {
                cout << "\nID: " << s.id;
                cout << "\nName: " << s.name;
                cout << "\nMarks: " << s.marks << "\n";
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            bool found = false;

            for (const Student &s : students) {
                if (s.id == id) {
                    cout << "Name: " << s.name << "\n";
                    cout << "Marks: " << s.marks << "\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;

            bool found = false;

            for (Student &s : students) {
                if (s.id == id) {
                    cout << "Enter new name: ";
                    getline(cin >> ws, s.name);

                    cout << "Enter new marks: ";
                    cin >> s.marks;

                    cout << "Record updated!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";
        }

        else if (choice == 5) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            bool found = false;

            for (auto it = students.begin();
                 it != students.end(); ++it) {
                if (it->id == id) {
                    students.erase(it);
                    cout << "Record deleted!\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";
        }

        else if (choice != 0) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    cout << "Thank you!\n";
    return 0;
}
