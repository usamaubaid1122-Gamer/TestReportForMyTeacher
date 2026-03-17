#include<iostream>
using namespace std;

int main() 
{
    int age;
    double washingMachinePrice;
    int toyPrice;

    cout << "Enter Lilly's age: ";
    cin >> age;

    cout << "Enter the price of the washing mechine: ";
    cin >> washingMachinePrice;

    cout << "Enter the unit price of each toy: ";
    cin >> toyPrice;

    int toys = 0;
    double money = 0;
    int moneyGift = 10;
    int brotherTake = 0;

    for (int i = 1; i <= age; i++) 
    {
        if (i % 2 == 1) 
        {
            toys++;
        } 
        
        else 
        {
            money += moneyGift;
            brotherTake++;
            moneyGift += 10;
        }
    }

    money -= brotherTake;
    money += toys * toyPrice;

    if (money >= washingMachinePrice)
    {
        cout << "Yes! " << money - washingMachinePrice << endl;
    } 

    else 
    {
        cout << "No! " << washingMachinePrice - money << endl;
    }
}