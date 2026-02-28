#include<iostream>
using namespace std;
main()
{
float imposter , player, chance;

cout<<"Enter imposter: ";
cin>>imposter;
cout<<"Enter players: ";
cin>>player;
chance = 100*(imposter/player);
cout <<"Chance = "<<chance<<"%";
}