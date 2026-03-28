#include<iostream>
using namespace std;
main()
{
    string username;
    int loginPIN = 1234;
    int users[3];
    bool login = false;
    for(int i = 0;i < 3; i++){
        cout <<"Enter the username:";
        cin >> username;
        cout <<"Enter the login PIN:";
        cin >> loginPIN;
         users[i] ;
        if(username == "admin" && loginPIN == 1234){
            login = true;
            cout << "login successful"<<endl;
            break;
        }
        else{
            cout << "Incorret LoginPIN"; 
        }
    }
    if (!login){
        cout << "too many failed attempts";
    }
    string name[3];
    int age[3];
    string course[3];
    int scount = 0 , ccount = 0;
    int choice;
    while(true){
        cout << "-----University Managment System-----"<<endl;
        cout <<"1. Add student "<<endl;
        cout <<"2. View student "<<endl;
        cout <<"3. Add course "<<endl;
        cout <<"4. View course "<<endl;
        cout <<"5. Exit "<<endl;
        cout <<"Enter your choice:";
        cin >> choice;
        if(choice == 1){
            if (scount <3){
            cout<< "Enter the student name:";
            cin >> name[scount];
            cout << "Enter student age:";
            cin >> age[scount];
            scount++;
            cout <<"student add successfully"<<endl;
            }
        }
        else if (choice == 2){
            for(int i = 0; i < scount; i++){
            cout <<"name:"<<name[i]<<endl<<"age:"<<age[i]<<endl; 
        }
    }
        else if (choice == 3){
            if(ccount <3){
            cout <<"enter the course name:";
            cin >> course[ccount]; 
            ccount++;
            cout << "course add successfully"<<endl;
        }
    }
    else if(choice == 4){
        for(int i = 0; i < ccount; i++){
            cout <<"course:"<<course[i]<<endl;
        }
    }
    else if (choice == 5){
        cout << "Exit"<<endl;
        break;
    }
    else{
        cout <<"Invalid option"<<endl;
    }
    }
}