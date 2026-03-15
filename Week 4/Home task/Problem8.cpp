#include <iostream>
using namespace std;
main()
{
    int num;
    cout<<"Enter the number:";
    cin>>num;
    string ones[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string teens[] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tens[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if (num < 10)
    {
        cout << ones[num];        
    }
    else if (num == 10)
    {
        cout<<"ten";
    }
    
    else if (num <20)
    {
        cout<< teens[num-10];
    }
    
    else if (num < 100)
    {
        cout<< tens[num/10];
        if (num % 10 != 0)
        {
            cout<<""<<ones[num%10];
        }
        
    }
    else if (num == 100)
    {
        cout <<"one hundred";
    }
    
    
}