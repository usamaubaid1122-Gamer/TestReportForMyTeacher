#include<iostream>
using namespace std;
main()
{
    int n , count;
    cout << "enter the numbers of customer:";
    cin >> n;
    char letter;
    string name[n];
    for(int i = 0;i < n; i++){
        cout << "enter the name of "<< i +1 << " customer:";
        cin >> name[i];
    }
    cout << "enter a letter to check :";
    cin >> letter;
    for (int i = 0; i < n; i++){
        if(name[i][0] == letter){
            count++;
        }
    }
    cout <<"total names starting with"<<letter<<":"<<count<<endl;
}