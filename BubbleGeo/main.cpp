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
   int comp=0, sch=0;           ///comp contor pentru nr de comparatii
   for(int k=1;k<n;k++){        ///sch contor schimburi
     for(int i=1;i<n;i++)
        {comp++;
         if(v[i]>v[i+1]) { sch++;Schimb(v[i],v[i+1]);}
        }
    Afis(n,v);
   }
   cout<<endl<<comp<<" comparari B1 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}

void B2Cresc(int n,int v[]){
   int comp=0, sch=0;
   bool ok;
   do
   { ok=true;
     for(int i=1;i<n;i++){
        comp++;
        if(v[i]>v[i+1]) {  Schimb(v[i],v[i+1]);
                           sch++;
                           ok=false;
                        }
     }
     Afis(n,v);cout<<"ok="<<ok;
   }
   while (!ok);
   cout<<endl<<comp<<" comparari B2 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}


void B3Cresc(int n,int v[]){
   bool ok;
   int comp=0, sch=0;
   int poz=n;               //poz = pozitia ultimei schimbari dupa for
   do
   { ok=true;
     int pI=1;              //pI = pozitia unei schimbari
     cout<<"pozInter=";
     for(int i=1;i<poz;i++) {
        comp++;
        if(v[i]>v[i+1]) {  Schimb(v[i],v[i+1]);sch++;
                           ok=false;
                           pI=i;
                           cout<<pI<<" ";
                        }
     }
     poz=pI;
     cout<<endl<<"poz="<<poz;
     Afis(n,v);cout<<"ok="<<ok<<"  ";
   }
   while (!ok);
   cout<<endl<<comp<<" comparari B3 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}

int comp=0, sch=0;
void BubleRec (int n,int x[], int i, bool Ok){  ///apelul primar cu i=1, Ok=true
    if(i<n){
        comp++;
        if(x[i]>x[i+1]) {
            sch++;
            Schimb(x[i],x[i+1]);
            Ok=false;
        }
        BubleRec(n,x,i+1,Ok);
    }

    if(Ok==false) { //Afis(n,x);cout<<"ok="<<Ok<<"  ";
                    BubleRec(n-1,x,i=1,Ok=true);
                    }

}

void BubleRecPoz (int n,int x[], int i,int PozInter, bool Ok){
                        ///apelul primar cu i=1,PozInter=1; Ok=true
    if(i<n){
        if(x[i]>x[i+1]) {
            Schimb(x[i],x[i+1]);
            Ok=false;
            PozInter=i;
            cout<<i<<" ";
        }
        BubleRecPoz(n,x,i+1,PozInter,Ok);
    }
    else if(!Ok) {cout<<"la urmat iteratie: "<<PozInter<<endl;
                  BubleRecPoz(n=PozInter,x,i=1,1,Ok=true);
                 }
}

void B1Descr(int n,int v[]){
   int cont=0, sch=0;
   for(int k=1;k<n;k++){
     for(int i=1;i<n;i++){
        cont++;
        if(v[i]<v[i+1])  {Schimb(v[i],v[i+1]);sch++;}
     }
    Afis(n,v);
   }
   cout<<endl<<cont<<" comparari B1 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}
void B2Descr(int n,int v[]){
   int comp=0, sch=0;
   bool ok;
   do
   { ok=true;
     for(int i=1;i<n;i++){
        comp++;
        if(v[i]<v[i+1]) {  Schimb(v[i],v[i+1]);
                           sch++;
                           ok=false;
                        }
     }
     Afis(n,v);
   }
   while (!ok);
   cout<<endl<<comp<<" comparari B2 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}
void B3Descr(int n,int v[]){
   bool ok;
   int cont=0, sch=0;
   int poz=n;
   int pozInter=1;
   do
   { ok=true;
     for(int i=1;i<poz;i++){
        cont++;
        if(v[i]<v[i+1]) {  Schimb(v[i],v[i+1]);sch++;
                           ok=false;
                           pozInter=i;
                           ///cout<<endl<<"pozInter="<<pozInter;
                        }
     }
     poz=pozInter;
     cout<<endl<<"poz="<<poz;
     Afis(n,v);
   }
   while (!ok);
   cout<<endl<<cont<<" comparari vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}

int main()
{   int v[]={0,3,-9,123,17,-333,-56,7,27};
    int n=8,i,PozInter;
    bool ok;
    cout<<"inainte de sortare";
    Afis(n,v);
    cout<<"in timpul sortarii";
    B1Cresc(n,v);
    //B2Cresc(n,v);
    //B3Cresc(n,v);
    //BubleRec(n,v,i=1,ok=true);
    //cout<<endl<<comp<<" comparari B1 vecini"<<endl;
    //cout<<endl<<sch<<" interschimbari vecini"<<endl;

    //BubleRecPoz(n,v,i=1,PozInter=1,ok=true);
    //B2Descr(n,v);
    //B2Descr(n,v);
    cout<<endl;

    //cout << "\nVectorul sortat descresc:";
    //Afis (n-1,v);
    //B2Cresc(n-1,v);
    cout<<endl;;
    cout << "\nVectorul sortat cresc:";
    Afis (n-1,v);

    return 0;
}
