#include<iostream>
using namespace std;
int main ()
{
    int num[5];
    for (int i = 0; i < 5; i = i + 1)
    {
        cout<<"Enter "<<i + 1<<" numbers: ";
        cin>>num[i];
    }
    cout<<"The 1st element of array: "<<num[0]<<endl;
    cout<<"The last element of array: "<<num[4]<<endl;
}