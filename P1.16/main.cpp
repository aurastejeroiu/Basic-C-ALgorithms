#include <iostream>
#include <cstring>
using namespace std;


int main()
{   int x,y,z;
    cout<<"da ziua da 1 ianuarie:";
    cin >>z;
    cout<<"da numar de zile:";
    cin >>x;
    cout<<endl<<x<<endl;
    y=(z+x-1)%7;
    cout<<y<<endl;
    if(y==1)cout<<"luni";
    if(y==2)cout<<"marti";
    if(y==3)cout<<"miercuri";
    if(y==4)cout<<"joi";
    if(y==5)cout<<"vineri";
    if(y==6)cout<<"sambata";
    if(y==0)cout<<"duminica";
    return 0;
}
