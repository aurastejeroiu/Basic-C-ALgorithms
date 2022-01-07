#include <iostream>

using namespace std;

///P1.13 Se da o zi sub forma datei (corecta) (Z,L,A) dintr-un an.
///      Se cere  sa se  determine a cata zi din acel an este aceasta zi.

///Idee: se aduna numarul de zile al fiecarei luni mai mici ca L cu Z.

int Ordinal(int Z, int L, int A){
    int Luni[]={0,31,28,31,30,31,30,31,31,30,31,30};///pentru decembrie nu trebuie retinut
    if(A%4==0) Luni[2]=29;
    int Ord=0;
    for(int i=1;i<L;i++)
        Ord+=Luni[i];
    Ord+=Z;
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
