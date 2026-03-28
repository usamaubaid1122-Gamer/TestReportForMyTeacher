#include<iostream>
using namespace std;
main()
{
    int n;
    cout << "enter the number of student:";
    cin >> n;
    string stu[n];
    cout <<"enter name of "<< n <<"student:";
    for(int i = 0; i < n; i++){
        cin >> stu[i];
    } 
     for(int i = 0;i < n-1 ;i++){
        for(int j = i + 1 ;j < n; j++){
            if(stu[i] > stu[j]){
            string temp = stu[i];
            stu[i] = stu[j];
            stu[j] = temp;
            }
        }
     }
     cout <<"name in alphabetical order:"<<endl;
     for(int i = 0;i < n;i++){
        cout << stu[i]<<endl;
     }
    }