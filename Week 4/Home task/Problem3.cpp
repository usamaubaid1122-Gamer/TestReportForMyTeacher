#include <iostream>
using namespace std;
main()
{
    int City_1,City_2;
    cout<<"Temperature City 1: ";
    cin>>City_1;
    cout<<"Temperature City 2: ";
    cin>>City_2;
    if (City_1 - City_2 >10 || City_2 - City_1 >10 )
    {
        cout<<"Diffrence too big.";
    }
    else
    {
        cout<<"Program End";
    }
    
}