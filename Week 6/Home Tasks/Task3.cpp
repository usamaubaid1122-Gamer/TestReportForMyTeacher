#include<iostream>
using namespace std;
main()
{
    int n;
    cout <<"enter number of elements:";
    cin >> n;
    int num[n];
    cout <<"enter"<< n <<"number:";
    for(int i = 0; i < n; i++){
        cin >> num[i];
        }
         int largest = num[0] ;
         int smallest = num[0] ;
        for(int i = 0;i < n; i++){
         if (num[i] > largest){
            largest = num[i];
        }
        if(num[i] < smallest){
            smallest = num[i];
        }
    }
    cout <<"largest number:"<<largest<<endl;
    cout <<"smallest number:"<<smallest<<endl;
}