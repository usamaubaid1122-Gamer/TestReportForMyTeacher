#include<iostream>
using namespace std;
main()
{
    int pin,deposit,withdraw,choice;
    int checkbalance = 1000;
    for (int i = 1; i <= 3; i++)
    {
        cout<<"Enter the PIN: ";
        cin>>pin; 
        if (pin == 1234)
        {
            cout<<"Login Successful"<<endl;
            break;
        }
        else
        {
            cout<<"wrong pin"<<endl;
        }
        if (i==3 && !(pin == 1234))
        {
            cout<<"To many attempt"<<endl;
            return 0;
        }
    }
    for (int i = 1; i <=10; i++)
    {
        cout<<endl<<"------Welcome to allied band-----"<<endl;
        cout<<"1. Check Balance"<<endl;
        cout<<"2. Deposit Money"<<endl;
        cout<<"3. Withdraw Money"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        if (choice == 1)
        {
            cout<<"Your balnce is: "<<checkbalance;
        }
        else if (choice == 2)
        {
            cout<<"Enter the amount of deposit: ";
            cin>>deposit;
            checkbalance = checkbalance + deposit;
            cout<<"Total amount is: "<<checkbalance;
        }
        else if (choice == 3)
        {
            cout<<"Enter the amount of withdraw: ";
            cin>>withdraw;
            if ( withdraw <= checkbalance  )
            {
                checkbalance = checkbalance - withdraw;
                cout<<"Your remaining amount is "<<checkbalance;
            }
            else
            {
                cout<<"Insuficent balance."<<endl;
            }
            
        }
        else if (choice == 4)
        {
            cout<<"Exit"<<endl;
            break;
        }

    }
    
    
}