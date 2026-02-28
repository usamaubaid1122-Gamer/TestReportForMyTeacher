#include<iostream>
using namespace std;
main()
{
float imposter,player,percent;
cout<<"Enter Imposter Count: ";
cin>>imposter;
cout<<"Enter Player Count: ";
cin>>player;
percent = (imposter/player)*100;
cout<<"Chance of being an imposter: "<<percent<<"%";
}