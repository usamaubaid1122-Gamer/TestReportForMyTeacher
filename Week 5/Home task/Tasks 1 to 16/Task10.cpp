#include<iostream>
using namespace std;
main()
{
    while(true){
        int choice;
        cout <<"\n-----Restaurant Management System-----"<<endl;
        cout <<"1.View Food Menu"<<endl;
        cout <<"2.Place Order"<<endl;
        cout <<"3.View Order Status"<<endl;
        cout <<"4.Generate Bill"<<endl;
        cout <<"5.Contact Staff"<<endl;
        cout <<"Exit"<<endl;
        cout <<"enter your choice:";
        cin >>choice;
        if(choice == 1){
            cout <<"You Selected:View Food Mnenu.";
        }
        else if(choice ==2){
            cout <<"You Selected:Place Order.";
        }
        else if(choice ==3){
            cout <<"You Selected :View Order Status";
        }
        else if(choice ==4){
            cout <<"You Selected:Generate Bill.";
        }
        else if (choice ==5){
            cout <<"You Selected:Contact Staff.";
        }
        else if(choice ==6){
            cout <<"Exiting Resturant Manangment System.";
            break;
        }
        else{
            cout << "Program Ends";
        }
    }

}