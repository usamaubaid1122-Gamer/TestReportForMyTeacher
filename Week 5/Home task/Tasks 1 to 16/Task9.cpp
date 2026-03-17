#include<iostream>
using namespace std;

main() 

{
    double money;
    int year;

    cout << "Enter money: ";
    cin >> money;

    cout << "Enter Year: ";
    cin >> year;

    double totalSpent = 0;
    int age = 18;

    for (int y = 1800; y <= year; y++) 
    {
        if (y % 2 == 0) 
        {
            totalSpent += 12000;
        } 
        
        else 
        {
            totalSpent += 12000 + 50 * age;
        }

        age++;
    }

    double diff = money - totalSpent;

    if (diff >= 0) 
    {
        cout << "Yes! He will live a carefree life and will have " << diff << " dollars left." << endl;
    } 
    
    else 
    {
        cout << "He will need " << -diff << " dollars to survive." << endl;
    }

}