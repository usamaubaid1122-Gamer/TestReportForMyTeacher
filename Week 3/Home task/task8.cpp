#include <iostream>
using namespace std;
main ()
{
float fruit,vegetable,total,earning;

int fruitkg,vegetablekg;

cout<<"Enter vegetable price per kg (in coins): ";
cin>>vegetable;

cout<<"Enter fruit price per kg (in coins): ";
cin>>fruit;

cout<<"Enter total kg of vegetables: ";
cin>>vegetablekg;

cout<<"Enter total kg of fruits: ";
cin>>fruitkg;

total = (vegetable*vegetablekg) + (fruit*fruitkg);
earning = total / 1.94;
cout<<"Total earnings in Rupees(Rps): "<<earning;
}