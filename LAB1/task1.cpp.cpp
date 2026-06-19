#include <iostream>// Online C++ compiler to run C++ program online
#include <string>

using namespace std;

int main() {
    struct Student {
        int ID;
        string name;
        string course;
        int age;

        Student(int a, string b, string c, int d) {
            ID = a;
            name = b;
            course = c;
            age = d;
        }
    };
    //store record
    Student student[5] = {
        Student(101, "Alice", "CS", 20),
        Student(102, "Bob", "Math", 21),
        Student(103, "Charlie", "Physics", 19),
        Student(104, "David", "CS", 22),
        Student(105, "Eva", "Chemistry", 20)
    };

    //display all records
    for (int i = 0; i < 5; i++) {
        cout << "Student #"<< i<< endl;
        cout << student[i].ID << endl;
        cout << student[i].name << endl;
        cout << student[i].course << endl;
        cout << student[i].age << endl;
        cout << "" << endl;
    }
    int input;
    cout<<"Enter the student ID: ";
    cin>>input;


    //search by student id
    for (int i = 0; i < 5; i++) {
        if (input == student[i].ID) {
            cout <<"The student is "<< student[i].name << endl;
            break;
        }
        else
            cout<< "Student not found"<<endl;


    }

    //update student record
    student[0].ID = 6767;
    student[0].name = "Widy";
    student[0].course = "Business Management";
    student[0].age = 23;





    return 0;
}