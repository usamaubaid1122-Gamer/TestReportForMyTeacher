#include<iostream>
using namespace std;
main()
{
    int Holiday,working_days,play_time,diffrence,hours,minutes;
    cout<<"Holidays: ";
    cin>>Holiday;
    working_days = 365 - Holiday;
    play_time = working_days * 63 + Holiday * 127;
    diffrence = 30000 - play_time  ;
    hours = diffrence / 60;
    minutes = diffrence % 60;
    if (play_time > 30000)
    {
        diffrence =play_time - 30000;
        hours = diffrence / 60;
        minutes = diffrence % 60;
        cout<<"Tom will run away"<<endl;
        cout<<hours<<" Hours and "<<minutes<<" Minutes for play";
    }
    else
    {
        diffrence = 30000 - play_time;
        hours = diffrence / 60;
        minutes = diffrence % 60;
        cout<<"Tom sleeps well"<<endl;
        cout<<hours<<" Hours and "<<minutes<<" Minutes less for play";
    }
    
}