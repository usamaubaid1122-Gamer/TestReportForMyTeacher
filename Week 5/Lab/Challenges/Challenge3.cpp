#include <iostream>
using namespace std;
int main()
{
    int num_1,num_2,a,b,gcd,lcm;
    cout<<"Enter first number: ";
    cin>>num_1;
    cout<<"Enter second number: ";
    cin>>num_2;
    a =num_1;
    b = num_2;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a= temp;
    }
    gcd = a;
    lcm = (num_1 * num_2) /gcd;
    cout<<"GCD: "<<gcd<<endl;
    cout<<"LCM: "<<lcm<<endl;
    return 0;
}
