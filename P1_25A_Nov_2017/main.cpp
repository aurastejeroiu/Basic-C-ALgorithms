#include <iostream>
using namespace std;
struct Pereche{
    long P1;
    long P2;
};
void Citire(long &n, long A[]){
     n=0;
     long X;
     do{
        cout<<"mai da un numar:";
        cin >>X;
        if(X>0) A[++n]=X;
     }
     while (X!=0);          ///pe event. numere negative le ignora
}
/*Specif:
    In: n natural
    Out: true, daca n e prim
         false, daca n nu este prim
*/
bool Prim(long n){
   if(n<2)    return false;
   if(n==2)   return true;
   if(n%2==0) return false;
   for(long d=3;d*d<=n;d+=2)    ///se verifica doar numerel impare pana la rad(n)
     if(n%d==0) return false;
   return  true;
}
long Modul(long x){
   if(x>=0) return x;
   return -x;
}

void Schimb(long &x, long &y){
   long aux=x;
   x       =y;
   y       =aux;
}

bool EsteInRez(long x, long y, long k, Pereche Rez[]){
   int i=1;
   if(x>y) Schimb(x,y);
   while (i<=k and (Rez[i].P1!=x or Rez[i].P2!=y))  ///daca perechea (x;y) nu coincide (Rez[i].P1;Rez[i].P2)
          i++;                                      ///se increm. i
   if(i>k) return false;
   return true;
}
void AdaugInRez(long x, long y, long &k, Pereche Rez[]){
   if(x>y) Schimb(x,y);
   long i=k;
   while(i>0 and x < Rez[i].P1) {
       Rez[i+1].P1=Rez[i].P1;
       Rez[i+1].P2=Rez[i].P2;
       i--;
   }
   Rez[i+1].P1=x;
   Rez[i+1].P2=y;
   k++;                 ///se mareste lungimea lui Rez
}
/*
Spec:
    In: n, A
    Out:k,Rez cu perechi de numere prime gemene
*/
void CreRez(long n, long A[], long &k, Pereche Rez[]){
   k=0;
   for(int i=1;i<n;i++)
     for(int j=i+1; j<=n;j++)           ///se genereza toate perechile de indici (i,j), i<>j
        if(Modul(A[i]-A[j])==2 and Prim(A[i]) and Prim(A[j])){ ///se verifica daca A[i] si A[j] sunt prime gemene
            if(!EsteInRez(A[i],A[j],k, Rez)) AdaugInRez(A[i],A[j],k,Rez);///daca (A[i],A[j]) nu e in Rez atunci se adauga
       }
}
void AfisRez(long k, Pereche Rez[]){
   if(k>0){
        cout<< "perchile de prime gemene:";
        for(int i=1;i<=k;i++)
            cout<<"("<<Rez[i].P1<<","<<Rez[i].P2<<") ";

   }
   else cout <<"nu exista perechi de prime gemene:";

}

int main()
{   long A[100];            ///sirul initial
    Pereche Rez[100];       ///sirul de perechi de prime gemene obtinut
    long n,k;          ///lung. lui A si Rez
    Citire(n,A);            ///citirea sir initial
    CreRez(n,A,k,Rez);      ///crerea sirului de perechi
    AfisRez(k,Rez);         ///afisare rezultate
    cout <<endl<< "Program terminat" << endl;
    return 0;
}
