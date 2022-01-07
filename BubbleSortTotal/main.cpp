#include <iostream>

using namespace std;

void Schimb(int& a, int& b){
   int aux=a;
       a=b;
       b=aux;
}

void Afis(int n, int v[]){
 cout<<endl;
 for(int i=1;i<=n;i++)
    cout<<v[i]<<" ";
}


void B1Cresc(int n,int v[]){
   for(int cont=1;cont<n;cont++){
     for(int i=1;i<n;i++)
        if(v[i]>v[i+1])  Schimb(v[i],v[i+1]);
    Afis(n,v);
   }
}

void B2Cresc(int n,int v[]){
   bool ok;
   int poz=n;
   int pozInter;
   do
   { ok=true;
     for(int i=1;i<poz;i++)
        if(v[i]>v[i+1]) {  Schimb(v[i],v[i+1]);
                           ok=false;
                           pozInter=i;
                           ///cout<<endl<<"pozInter="<<pozInter;
                        }
     poz=pozInter;
     cout<<endl<<"poz="<<poz;
     Afis(n,v);
   }
   while (ok==false);
}

void B1Descr(int n,int v[]){
   for(int cont=1;cont<n;cont++){
     for(int i=1;i<n;i++)
        if(v[i]<v[i+1])  Schimb(v[i],v[i+1]);
    Afis(n,v);
   }
}
void B2Descr(int n,int v[]){
   bool ok;
   int poz=n;
   int pozInter;
   do
   { ok=true;
     for(int i=1;i<poz;i++)
        if(v[i]<v[i+1]) {  Schimb(v[i],v[i+1]);
                           ok=false;
                           pozInter=i;
                           ///cout<<endl<<"pozInter="<<pozInter;
                        }
     poz=pozInter;
     cout<<endl<<"poz="<<poz;
     Afis(n,v);
   }
   while (ok==false);
}

int main()
{   int v[]={0,3,-9,123,17,-333,56,7,27};
    int n=9;

    B2Descr(n-1,v);
    cout<<endl;

    cout << "\nVectorul sortat descresc:";
    Afis (n-1,v);
    B2Cresc(n-1,v);
    cout<<endl;;
    cout << "\nVectorul sortat cresc:";
    Afis (n-1,v);

    return 0;
}
