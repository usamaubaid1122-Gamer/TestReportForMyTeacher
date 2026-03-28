#include<iostream>
using namespace std;
main()
{
    float coins[4];
    float due;
    string name[4] = {"quarters","dimes","nickels","pennies"};

    for (int i = 0; i < 4; i++)
    {
        cout<<"Enter "<<name[i]<<": ";
        cin>>coins[i];
    }
    cout << "Enter total due: $";
    cin>>due;

    float total = 0;
    total = total + coins[0]*0.25;
    total = total + coins[1]*0.10;
    total = total + coins[2]*0.05;
    total = total + coins[3]*0.01;

    if (total >= due)
    {
        cout<<"Can tou pay the amount? Yes ";
    }
    else
    {
        cout<<"Can tou pay the amount? No";
    }
    return 0 ;
}