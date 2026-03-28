#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"enter the number of product :";
    cin >> n;
    string name[n];
    float price[n];
    float quantity[n];
    
     for(int i = 0;i < n; i++){
        cout<<"enter the name :";
        cin >> name[i];
        cout <<"enter the price"<<name[i] <<":$";
        cin >> price[i];
        cout <<"enter the quantity" <<name[i]<<":";
        cin >> quantity[i];
        cout<<"-------------------------------------------\n";
     } 
     for(int i = 0;i < n; i++){
       cout<< name[i]<<" :$"<<price[i]<<" , "<<quantity[i]
         <<" in stock, total value :$ "<<price[i] * quantity[i]<<endl;
     }
    }