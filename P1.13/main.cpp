#include <iostream>

using namespace std;

//P1.13 Se da o zi sub forma datei (z,l,a) dintr-un an.
//      Se cere  sa se  determine a cata zi din acel an este aceasta zi.

//Idee: se aduna numarul de zile al fiecarei luni mai mici ca l cu z.

int Ordinal(int z, int l, int a){
    int luni[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(a%4==0) luni[2]=29;
    int Ord=0;
    for(int i=1;i<l;i++)
        Ord+=luni[i];
    Ord+=z;
    return Ord;
}

int main()
{   int a,l,z;
    cout<<"da ziua:";cin>>z;
    cout<<"da luna:";cin>>l;
    cout<<"da anul:";cin>>a;
    cout<<"data este a "<<Ordinal(z,l,a)<<" zi"<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
