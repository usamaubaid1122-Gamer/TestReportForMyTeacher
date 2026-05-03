#include <iostream>
using namespace std;
void add(int number1, int number2);
int main()
{
    int number1, number2;
    cout << "Enter Number01 :";
    cin >> number1;
    cout << "Enter Number02: ";
    cin >> number2;
    add(number1, number2);
    return 0;
}
void add(int number1, int number2)
{
    cout << "Sum: " << number1 + number2;
}