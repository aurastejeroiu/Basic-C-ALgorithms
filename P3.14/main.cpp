#include <iostream>

using namespace std;

struct Numar{           ///reprezentarea numarului in vector, in oglinda
   int C[100]={0};
   int lung=0;
};

void EliminZero(Numar &D){
   while(D.C[D.lung-1]==0) D.lung--;
}

void Afisare (Numar S){
   //cout<<"lung="<<S.lung<<endl;
   for(int k=0;k<(10-S.lung);k++) ///afisare spatii pentru alinierea numerelor
      cout<<' ';
   for(int i=S.lung-1; i>=0; i-- ){
     cout<<S.C[i];
   }

  cout<<endl;
}

void InVector(long N, Numar& X){
  int i=0;
  while(N>0){
    X.C[i++]=N%10;
    N/=10;
  }
  X.lung=i;
}

void Multiply(int bb, Numar a, Numar b, Numar& p){
  int i,j,Transport;
  p.lung=a.lung + b.lung;            ///nr maxim de cifre ale produsului este suma nr de cifre
                            ///ale lui a si b;
  for (i=0; i< p.lung; i++)    ///initializare cifre produs cu 0
     p.C[i]=0;

  for (i=0; i< a.lung;i++)
    for (j=0; j< b.lung;j++)
           {p.C[i+j]  +=a.C[i]*b.C[j];    ///se aduna la poz i+j a.C[i]*b.C[j]
            Transport  =p.C[i+j] / bb;	  ///se determina transportul
            p.C[i+j]   =p.C[i+j] % bb;	  ///se retine in p.c[i+j] doar modulo 10
            p.C[i+j+1]+=Transport;  	  ///aduna transportul pozitiei urmatoare
           }
  EliminZero(p);
 }

int main()
{  Numar X, Y, P;
   long x=123;
   long y=1234;
   int b=10;
    InVector(x,X);
    cout<<"X=";Afisare(X);
    InVector(y,Y);
    cout<<"Y=";Afisare(Y);
    Multiply(b,X,Y,P);
    cout<<"P=";Afisare(P);
    cout << "\nHello world!" << endl;
    return 0;
}
