#include <iostream>

using namespace std;

int Ordinal(int z, int l, int a){
    int luni[]={0,31,28,31,30,31,30,31,31,30,31,30};
    if(a%4==0) luni[2]=29;
    if(a%400!=0 && a%100==0) luni[2]=28;
    int Ord=z;
    for(int i=1;i<l;i++)
        Ord+=luni[i];
    return Ord;
}


int Zile(int nz, int nl, int na, int cz, int cl, int ca  ){
    int zile=0;
    int OrdN=Ordinal(nz,nl,na);
    int OrdC=Ordinal(cz,cl,ca);
    if(na==ca)  return(OrdC-OrdN); ///daca anii coincid
    else {                         ///anii diferiti
           if(na%4==0) zile=366-OrdN;     ///adaugare nr de zile din anul nasterii
           else        zile=365-OrdN;

          for(int i=na+1;i<=ca-1;i++)     ///adunare pentru anii intregi
           {   zile+=365;
               if(i%4==0) zile++;
          }
          zile+=OrdC;                    ///adaugare nr de zile din anul curent

    }
    return zile;

}
void CitireData(int &zi,int& lu, int &an){
   cout<<"da ziua :";cin>>zi;
   cout<<"da luna :";cin>>lu;
   cout<<"da anul :";cin>>an;
}

int main()
{   int nz,nl,na,cz,cl,ca;
    long zile=0;
    cout<<"citim data nasterii\n";
    CitireData(nz,nl,na);
    cout<<"citim data curenta\n";
    CitireData(cz,cl,ca);
    cout<<endl<< Zile(nz,nl,na,cz,cl,ca)<<" zile"<<endl;
    cout<<endl<< "Program terminat" << endl;
    return 0;
}
