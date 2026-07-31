#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const Student& student)
{
    if (student.scores.empty())
        return 0;

    double sum = 0;

    for (int i = 0; i < student.scores.size(); i++)
    {
        sum += student.scores[i];
    }

    return sum / student.scores.size();
}

void addStudent(vector<Student>& students)
{
    Student student;
    int numScores;

    cin.ignore();

    cout << "Student name: ";
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++)
    {
        double score;

        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student \"" << student.name 
         << "\" added successfully." << endl;
}

void displayStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student records found." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    cout << "\nStudent Records\n";
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < students.size(); i++)
    {
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;

        cout << "Scores: ";

        for (int j = 0; j < students[i].scores.size(); j++)
        {
            cout << students[i].scores[j] << " ";
        }

        cout << endl;
        cout << "Average: " 
             << calculateAverage(students[i]) << endl;

        cout << "------------------------------------------------------------" << endl;
    }
}

void findStudentAverage(const vector<Student>& students)
{
    int id;
    bool found = false;

    cout << "Enter student ID: ";
    cin >> id;

    cout << fixed << setprecision(2);

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << students[i].name 
                 << "'s average score: "
                 << calculateAverage(students[i]) 
                 << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Error: Student ID not found." << endl;
    }
}

int main()
{
    vector<Student> students;
    int choice;

    do
    {
        cout << "\n================================" << endl;
        cout << "  STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                findStudentAverage(students);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}
