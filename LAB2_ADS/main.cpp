#include <iostream>
#include <string>
using namespace std;

struct Student{
    string id;
    string name;
    string course;
    int age;
};

int main() {

    Student student[5]; 
    student[0].id = "24007271";
    student[0].name = "Reeyan";
    student[0].course = "IT";
    student[0].age = 25;

    student[1].id = "24006463";
    student[1].name = "Ananda";
    student[1].course = "CS";
    student[1].age = 18;

    for (int i = 0; i < 2; i++) {
        cout << student[i].id << endl;
        cout << student[i].name << endl;
        cout << student[i].course << endl;
        cout << student[i].age << endl;
        cout << endl;
    }

    return 0;
}