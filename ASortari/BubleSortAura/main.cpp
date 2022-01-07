#include <iostream>

using namespace std;

void Schimb(int& a, int& b){
   int aux=a;
       a=b;
       b=aux;
}
void Citire (int &n, int v[]){
 cout<<"n=";cin>>n;
 for(int i=1;i<=n;i++)
    cin>>v[i];
 cout<<endl;
}

void Afis(int n, int v[]){
 cout<<endl;
 for(int i=1;i<=n;i++)
    cout<<v[i]<<" ";
 cout<<endl;
}


void B1Cresc(int n,int v[]){
   int cont=0, sch=0;
   for(int k=1;k<n;k++){
     for(int i=1;i<n;i++)
        {cont++;
         if(v[i]>v[i+1]) { sch++;Schimb(v[i],v[i+1]);}
        }
    Afis(n,v);
   }
   cout<<endl<<cont<<" comparari B1 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
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

void B2Cresc(int n,int v[]){
   int cont=0, sch=0;
   bool ok;
   do
   { ok=true;
     for(int i=1;i<n;i++){
        cont++;
        if(v[i]>v[i+1]) {  Schimb(v[i],v[i+1]);
                           sch++;
                           ok=false;
                        }
     }
     Afis(n,v);
   }
   while (!ok);
   cout<<endl<<cont<<" comparari B2 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}

void B2Descr(int n,int v[]){
   int cont=0, sch=0;
   bool ok;
   do
   { ok=true;
     for(int i=1;i<n;i++){
        cont++;
        if(v[i]<v[i+1]) {  Schimb(v[i],v[i+1]);
                           sch++;
                           ok=false;
                        }
     }
     Afis(n,v);
   }
   while (!ok);
   cout<<endl<<cont<<" comparari B2 vecini"<<endl;
   cout<<endl<<sch<<" interschimbari vecini"<<endl;
}


void B3Cresc(int n,int v[]){
   bool ok;
   int cont=0, sch=0;
   int poz=n;
   int pozInter=1;
   do
   { ok=true;
     for(int i=1;i<poz;i++) {
        cont++;
        if(v[i]>v[i+1]) {  Schimb(v[i],v[i+1]);sch++;
                           ok=false;
                           pozInter=i;
                           cout<<endl<<"pozInter="<<pozInter<<" ";
                        }
     }
     poz=pozInter;
     cout<<endl<<"poz="<<poz;
     Afis(n,v);
   }
   while (!ok);
   cout<<endl<<cont<<" comparari B3 vecini"<<endl;
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

void BubleRec (int n,int x[], int i, bool Ok){  ///apelul primar cu i=1, Ok=true
    if(i<n){
        if(x[i]>x[i+1]) {
            Schimb(x[i],x[i+1]);
            Ok=false;
        }
        BubleRec(n,x,i+1,Ok);
    }
    if(!Ok) BubleRec(n,x,i=1,Ok=true);
}

void BubleRecDesc (int n,int x[], int i, bool Ok){  ///apelul primar cu i=1, Ok=true
    if(i<n){
        if(x[i]<x[i+1]) {
            Schimb(x[i],x[i+1]);
            Ok=false;
        }
        BubleRecDesc (n,x,i+1,Ok);
    }
    if(!Ok) BubleRecDesc (n,x,i=1,Ok=true);
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

void BubleRecPozDesc (int n,int x[], int i,int PozInter, bool Ok){
                        ///apelul primar cu i=1,PozInter=1; Ok=true
    if(i<n){
        if(x[i]<x[i+1]) {
            Schimb(x[i],x[i+1]);
            Ok=false;
            PozInter=i;
            cout<<i<<" ";
        }
        BubleRecPozDesc(n,x,i+1,PozInter,Ok);
    }
    else if(!Ok) {cout<<"la urmat iteratie: "<<PozInter<<endl;
                  BubleRecPozDesc (n=PozInter,x,i=1,1,Ok=true);
                 }
}

int main()
{   int v[100];
    int n,i,PozInter;
    bool ok;
    Citire(n,v);
    cout<<"inainte de sortare";
    Afis(n-1,v);
    //B1Cresc(n-1,v);
    //B2Cresc(n-1,v);
    //B3Cresc(n-1,v);
    //B1Descr(n-1,v);
    //B2Descr(n-1,v);
    //B3Descr(n-1,v);
    //BubleRec(n-1,v,i=1,ok=true);
    //BubleRecDesc(n-1,v,i=1,ok=true);
    //BubleRecPoz(n-1,v,i=1,PozInter=1,ok=true);
    //BubleRecPozDesc(n-1,v,i=1,PozInter=1,ok=true);
    cout<<endl;

    //cout << "\nVectorul sortat descresc:";
    //Afis (n-1,v);
    //B2Cresc(n-1,v);
    cout<<endl;;
    cout << "\nVectorul sortat cresc:";
    Afis (n-1,v);

    return 0;
}

