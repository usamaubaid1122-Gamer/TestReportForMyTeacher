#include<iostream>
using namespace std;
int main ()
{
    int size = 3;
    int num[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the "<< i+1<<" number: ";
        cin>>num[i];
        for (int j = 0; j < i ; j++)
        {
            if (num[i] == num[j])
            {
                cout<<"Already Enterd"<< endl;
                cout<<"Unique Number:";
                for (int k = 0; k < i; k++)
                {
                    cout<<num[k]<<" ";
                }
                
                return 0;
            }   
        }   
    }
        cout<<"Final numbers: ";
        for (int i = 0; i < size; i++)
        {
            cout<<num[i]<<" ";
        }
}