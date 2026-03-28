#include<iostream>
using namespace std;
main()
{
    string name;
    cout<<"Enter a string: ";
    getline(cin,name);
    char vowels[] = {'a','e','i','o','u'};
    bool isvowel;
    cout<<"string with vowels removed: ";

    for (int i = 0; i < name.length(); i++)
    {
        isvowel = false;
        for (int j = 0; j < 5; j++)
        {
            if (name[i] == vowels[j])
            {
                isvowel = true;
                break;
            }
        }
        if (!isvowel)
       {
            cout<<name[i];
       }
    }
    return 0;
}