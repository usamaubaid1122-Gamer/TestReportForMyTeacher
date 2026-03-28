#include <iostream>
using namespace std;
int main ()
{
    int sum = 0;
    float avg = 0;
    int num[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i = i + 1 )
    {
        sum = sum + num[i];
    }
    avg = sum / 5;
    cout<<"sum = "<<sum<<endl;
    cout<<"average = "<<avg<<endl;
}