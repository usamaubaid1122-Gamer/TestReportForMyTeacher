#include<iostream>
using namespace std;
void printBlue(int cars[][5] , int blue);
int TotalRedCars(int cars[][5],int sum);
int TotalNissanCars(int cars[5][5]);
main()
{

    int blue = 0;
    int sum = 0;
    const int rowSize = 5;
    const  int  colSize = 5;
    int cars[rowSize][colSize] = {
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}};
        int sum=TotalNissanCars(cars);
    printBlue(cars,blue);
    
    cout<<"Total Red Cars in company: "<<TotalRedCars<<endl;
    cout<<"Total Nissan Cars in company: "<<TotalNissanCars<<endl;
}
void printBlue(int cars[][5] , int blue)
{
    cout<<"Toyota Blue Cars: "<<cars[1][3]<<endl;    
}
int TotalRedCars(int cars[][5],int sum)
{
    for (int i = 0; i < 5; i++)
    {
        sum = sum + cars[i][0];
    }
    int solution = sum;
    return solution;
}
int TotalNissanCars(int cars[][5])
{
    int sum;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + cars[2][i];
    }
    int result= sum;
    return result;
    
}