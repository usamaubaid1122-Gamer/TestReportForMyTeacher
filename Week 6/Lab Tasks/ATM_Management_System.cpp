#include<iostream>
using namespace std;
main()
{
 int Correct_Pin = 1234;
 int size = 3;
 int pin[size];
 int choice;
 int balance = 1000;
 int amount;
 bool login = false;

 for (int i = 0; i < size; i++)
 {
   cout<<"Enter ATM Pin: ";
   cin>>pin[i];
   if (pin[i] == Correct_Pin)
   {
      login = true;
      cout<<"Login Successfull\n";
      break;
   }
   else
   {
      cout<<"Incorrect Password\n";
   }
 }
 if (login == true)
 {
   while (true)
   {
      cout<<"\n------ATM MENU-------\n";
      cout<<"1. Check Balance\n";
      cout<<"2. Deposit Money\n";
      cout<<"3. Withdraw Money\n";
      cout<<"4. EXIT\n";
      cout<<"Enter the choice: ";
      cin>>choice;

      if (choice == 1)
      {
         cout<<"Current Balance: "<<balance;
      }
      else if (choice == 2)
      {
         cout<<"Enter the amount you want to deposit: ";
         cin>>amount;
         if (amount > 0)
         {
         balance = amount + balance;
         cout<<"Updated Balance: "<<balance<<endl;
         }
         else
         {
            cout<<"Invalid Amount\n";
         }
      }
      else if (choice == 3)
      {
         cout<<"Enter amount to withdraw: ";
         cin>>amount;
         if (amount <= balance && amount > 0)
         {
            balance = balance - amount;
            cout<<"Remaining Balance: "<<balance<<endl;
         }
         else
         {
            cout<<"Insufficient Balance";
         }
      }
      else if (choice == 4)
      {
         cout<<"Thanks for using the ATM";
         break;
      }
      else
      {
         cout<<"Invalid Choice";
      }
   }
 }
  else
  {
   cout<<"Too many incorrect attempts Access Denied.\n";
  }
}