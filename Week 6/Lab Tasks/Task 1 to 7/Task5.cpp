#include<iostream>
using namespace std;
int main ()
{
    int num[6];
    for (int i = 0; i < 6; i = i + 1)
    {
        cout<<"Enter "<<i + 1<<" numbers: ";
        cin>>num[i];
    }
    cout<<"The 1st element of array: "<<num[0]<<endl;
    cout<<"The 2nd element of array: "<<num[1]<<endl;
    cout<<"The 3rd element of array: "<<num[2]<<endl;
    cout<<"The 4th element of array: "<<num[3]<<endl;
    cout<<"The 5th element of array: "<<num[4]<<endl;
    cout<<"The last element of array: "<<num[5]<<endl;
}