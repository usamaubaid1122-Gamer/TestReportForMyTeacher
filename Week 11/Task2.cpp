#include <iostream>
using namespace std;
void printCars(int car[][5], int rowsize);
int main()
{
    const int rowSize = 5;
    const  int  colSize = 5;
    int car[rowSize][colSize] = {
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}};

    printCars(car, rowSize);
}
void printCars(int car[][5], int rowsize)
{
    for (int row = 0; row < rowsize; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << car[row][col] << "\t";
        }
        cout << endl;
    }
}