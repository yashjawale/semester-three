#include <iostream>
#include <fstream>

using namespace std;

class Employee {
    string Name;
    int ID;
    double salary;
    public:
        void accept() {
            cout << "\nName: ";
            cin.ignore();
            getline(cin, Name);
            cout << "\nId: ";
            cin >> ID;
            cout << "\nSalary: ";
            cin >> salary;
            cout << "\n";
        }
        void display() {
            cout << "\nName: " << Name;
            cout << "\nId: " << ID;
            cout << "\nSalary: " << salary << "\n";
        }
};

int main() {
    Employee o[5];
    fstream f;
    int i, n;
    f.open("demo.txt", ios::out);
    cout << "\nEnter the number of employees you want to store: ";
    cin >> n;
    for (i=0; i<n; i++) {
        cout << "\n\nEnter information of employee " << i+1 << "\n";
        o[i].accept();
        f.write((char *) & o[i], sizeof o[i]);
    }
    f.close();
    f.open("demo.txt", ios::in);
    cout << "\n";
    cout << "Information of employees is as follows: ";
    for (i=0; i<n; i++) {
        cout << "\nEmployee " << i+1;
        f.write((char *) & o[i], sizeof o[i]);
        o[i].display();
    }
    f.close();
    return 0;
}