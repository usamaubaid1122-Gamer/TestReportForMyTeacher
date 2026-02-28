#include<iostream>
using namespace std;
main()
{
int pointers1;
int pointers2;
int finalpoints;
cout << "Enter  pointer1 score:";
cin >> pointers1;
cout << "Enter  pointer2 score:";
cin >> pointers2;
finalpoints = (pointers1 * 2) + (pointers2 * 3);
cout << " final points score:"<<finalpoints;
}