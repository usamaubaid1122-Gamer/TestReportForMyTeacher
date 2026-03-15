#include <iostream>
using namespace std;
main()
{
    int n, count;
    cout<<"Enter the number: ";
    cin>>n;
    for (int i = n; i > 0; i= i / 10)
    {
        count = count + 1;
    }
    cout<<"Total number of digits: "<<count;
    return 0;
}