#include<iostream>
using namespace std;
main()
{
    string username, password;

    string studentname = "";
    int studentAge = 0;
    string coursename = "";
    int choice;

    for (int i = 1; i <=3; i++)
    {
        cout<<"Enter the Username: ";
        cin>>username;

        cout<<"Enter Password: ";
        cin>>password;

        if (username == "admin" && password == "1234")
        {
            cout<<"login Successful"<<endl;
            break;
        }
        else
        {
            cout<<"Wrong Login"<<endl;
        }
        if (i == 3 && !(username == "admin" && password == "1234"))
        {
            cout<<"Too many attemptss. Program End."<<endl;
            return 0 ;
        }
        
    }
    for (int i = 1; i <= 5; i++)
    {
        cout<<endl<<"------- University Management System -----"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. View Student"<<endl;
        cout<<"3. Add Course"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter Choice: ";
        cin>>choice;

        if (choice == 1 )
        {
            cout<<"Enter Student Name: ";
            cin>>studentname;

            cout<<"Enter Student age: ";
            cin>>studentAge;

            cout<<"Student Added Successfully"<<endl;
        }
        else if (choice == 2)
        {
            if (studentname != "")
            {
                cout<<"Student Name: "<<studentname<<endl;
                cout<<"Student age: "<<studentAge<<endl;
            }
            else
            {
                cout<<"No Student Record found"<<endl;
            }
        }
        else if (choice == 3)
        {
            cout<<"Enter Corse name: ";
            cin>>coursename;

            cout<<"Course Added: "<<coursename<<endl;
        }
        else if (choice == 4)
        {
            cout<<"Program Exit"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
        }
        
    }
    
}