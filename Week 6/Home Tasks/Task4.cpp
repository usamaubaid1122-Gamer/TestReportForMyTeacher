#include<iostream>
using namespace std;
main()
{
    string name [5];
    cout <<"enter name of 5 students:"<<endl;
    for(int i =0;i < 5;i++){
        cout << "enter student name:";
        cin >> name[i];
    }
    cout << "student name are:";
    for(int i = 0;i < 5; i++){
        cout << name[i]<<endl;
    }
}