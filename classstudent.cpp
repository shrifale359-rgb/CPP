#include <iostream>
#include <string> 
using namespace std;   

class students{ 
    public:     
    int rollNo;     
    float marks;     
    string name; 
    // Member functions to accept and Display user input   

    void accept(){         
        cout << "Enter Roll Number: ";         
        cin >> rollNo;          
        cout << "Enter Name: ";         
        cin >> name;                  
        cout << "Enter Marks: ";         
        cin>> marks;     }      

    void display(){         
        cout << "\n--- Students Details ---" << endl;         
        cout << "Roll Number : " << rollNo << endl;         
        cout << "Name        : " << name << endl;         
        cout << "Marks       : " << marks << endl;     
    } 
};  
int main() {     
    //  Made 2 Data Members For the Class.     
    students s1;     
    students s2;          
    s1.accept();     
    s1.display();     
    s2.accept(); 
    s2.display();
    return 0; 
} 
