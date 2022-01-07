#include <iostream>

using namespace std;

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
{   int nz,nl,na,cz,cl,ca;
    cout<<"da ziua nast:";cin>>nz;
    cout<<"da luna nast:";cin>>nl;
    cout<<"da anul nast:";cin>>na;
    cout<<"da ziua c:";cin>>cz;
    cout<<"da luna c:";cin>>cl;
    cout<<"da anul c:";cin>>ca;
    long Zile;
    Zile=0;
    for(int i=na+1;i<ca;i++)                    //adunare pentru anii intregi
    {
        Zile+=365;
        if(i%4==0)Zile++;
    }
    Zile+=Ordinal(cz,cl,ca);                    //adaugare nr de zile din anul curent
    if(ca>na)
        if(na%4==0) Zile+=(366-Ordinal(nz,nl,na));  //adaugare nr de zile din anul nasterii
        else        Zile+=(365-Ordinal(nz,nl,na));
    else Zile=Ordinal(cz,cl,ca)-Ordinal(nz,nl,na);

    cout<<endl<<Zile<<" zile"<<endl;
    cout<<endl<< "Program terminat" << endl;
    return 0;
}
