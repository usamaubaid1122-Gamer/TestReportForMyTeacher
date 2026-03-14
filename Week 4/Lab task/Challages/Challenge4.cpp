#include<iostream>
using namespace std;
main()
{
    string user_enter,password;
    cout<<"Enter the Password: ";
    cin>> user_enter;
    password = "Pass@123";
    if (password == user_enter)
    {
        cout<<"You enters the right password";
    }
    else
    {
        cout<<"Try again";
    }
}