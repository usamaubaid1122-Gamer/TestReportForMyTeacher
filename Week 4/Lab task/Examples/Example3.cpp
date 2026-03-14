#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string name;
    cout <<"Enter your name: ";
    cin>> name;
    if (name == "ali")
    {
        cout <<"Welcome Ali";
    }
    if (name != "ali" )
    {
        cout<<"Try again";
    }
    
    
    return 0;
}
