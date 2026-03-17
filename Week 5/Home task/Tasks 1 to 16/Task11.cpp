#include<iostream>
using namespace std;
main()
{
    int num1,num2,result;
    int choice;
    cout <<"----Simple calculator----"<<endl;
    cout <<"1.Addition"<<endl;
    cout <<"2.Subtraction"<<endl;
    cout <<"3.Multiplication"<<endl;
    cout <<"4.Division"<<endl;
    cout <<"5.Clear screen"<<endl;
    cout <<"Enter youe choice:";
    cin >>choice;
    if(choice ==1){
        cout <<"enter first number:";
        cin >> num1;
        cout <<"enter second number:";
        cin >> num2 ;
      result = num1 + num2;
      cout <<"result"<<result;
    }
    else if (choice == 2){
        cout <<"enter first number:";
        cin >> num1;
        cout <<"enter second number:";
        cin >> num2 ;
        result = num1 -num2 ;
     cout <<"result"<<result;
    }
    else if(choice == 3){
        cout <<"enter first number:";
        cin >> num1;
        cout <<"enter second number:";
        cin >> num2 ;
        result = num1 * num2;
        cout <<"result"<<result;
    }
    else if(choice == 4){
       cout <<"enter first number:";
        cin >> num1;
        cout <<"enter second number:";
        cin >> num2 ;
        result = num1 / num2;
          cout <<"result"<<result;
    }
    else if (choice == 5){
        cout<<"Clear Screen";
    
    }
    else{
        cout <<"Program Ends";
    }
}