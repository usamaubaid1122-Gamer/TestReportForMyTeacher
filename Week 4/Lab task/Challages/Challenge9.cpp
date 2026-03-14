#include<iostream>
using namespace std;
main ()
{
    string name1,name2,name3;
    int age1,age2,age3;
    cout <<"Enter first brother name: ";
    cin >> name1;
    cout <<"Enter first brother age: ";
    cin >> age1;
    cout <<"Enter second brother name: ";
    cin >> name2;
    cout <<"Enter second brother age: ";
    cin >> age2;
    cout <<"Enter third brother name: ";
    cin >> name3;
    cout <<"Enter third brother age: ";
    cin >> age3;
    if (age1 <= age2 && age1 <= age3)
    {
    cout << name1 << " is youngest" << endl;
    }
    else if (age1 <= age2 && age1 <= age3)
    {
    cout << name2 << " is youngest" << endl;
    }
    else
    {
    cout << name3 << " is youngest" << endl;
    }
    
}