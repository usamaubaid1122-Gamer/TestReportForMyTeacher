#include<iostream>
using namespace std;
main ()
{
char ch;
cout<<"Enter any character: ";
cin>>ch;
if (isdigit(ch))
{
    cout<<"it is a number";
    
}
else if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
{
    cout<<"it is vowel";
}
else if ((ch >= 'a'&& ch <='z') || (ch >= 'A'&& ch <='Z'))
{
    cout<<"it is constant";
}
else if (ch >= '1' && ch <= '9')
{
    cout<<"it is a number";
}
else
{
    cout<<"unknown character";
}

 
}