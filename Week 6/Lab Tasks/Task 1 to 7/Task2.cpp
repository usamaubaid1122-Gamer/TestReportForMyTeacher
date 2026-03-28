#include<iostream>
using namespace std;
int main ()
{
    int num[5];
    for (int  i = 0; i < 5; i = i+1)
    {
        cout<<"Enter "<< i + 1<< " numbers: ";
        cin>>num[i];
    }
    cout<<"The 2nd element of array: "<<num[1]<<endl;
    cout<<"The 4th element of array: "<<num[3]<<endl;
}