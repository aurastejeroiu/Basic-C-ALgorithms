#include <iostream>
#include <conio.h>

using namespace std;

struct Polinom{
    int  grad;                          /// Polinom P => P.grad si P.C[i]
    long C[100];
};

void CitPol(Polinom &P){
  cout<<"da grad:"; cin>>P.grad;

  for (int i=0; i<=P.grad; i++){
    cout<<"coef["<<i<<"]=";
    cin >>P.C[i];
  }
}

void Produs(Polinom P, Polinom Q,  Polinom &R){
    R.grad=P.grad + Q.grad;
    
    for(int i=0;i<=R.grad;i++) R.C[i]=0; /// initializare produs

    for(int i=0;i<=P.grad;i++)
      for(int j=0;j<=Q.grad;j++)
        R.C[i+j] += (P.C[i]) * (Q.C[j]);
}

void Suma(Polinom P, Polinom Q, Polinom &S){
   
   S.grad =(P.grad >= Q.grad ? P.grad : Q.grad);
   int Min=(P.grad <= Q.grad ? P.grad : Q.grad);

   for(int i=0;i<=Min;i++)
     S.C[i]=P.C[i]+Q.C[i];

   for(int i=Min+1;i<=P.grad;i++)        ///numai unul din cele 2 cicluri care urmeaza se executa
      S.C[i]=P.C[i];
   for(int i=Min+1;i<=Q.grad;i++)        ///numai unul din cele 2 cicluri care urmeaza se executa
      S.C[i]=Q.C[i];
}

void Scalar(int a, Polinom P, Polinom &R ){/// R=a*P
   R.grad=P.grad;
   for(int i=0;i<=P.grad; i++)
      R.C[i]=a*P.C[i];
}

void AfisPol(Polinom G){
    cout<<endl;
    cout<<G.C[0];
    for(int i=1;i<=G.grad;i++)
        cout<<"+"<<G.C[i]<<"X^"<<i;
    cout<<endl;
}

void Compus(Polinom P, Polinom Q, Polinom &PQ){
    Polinom R,A;                ///in A se vor retine puterile lui Q
    PQ.C[0]=P.C[0];             ///in R se retine P.c[i]*Q[(x)^i
    PQ.grad=0;
    A=Q;
    for(int i=1;i<=P.grad;i++){
        Scalar(P.C[i],A,R);		///inmultire cu scalar a lui A=Q^i
        Suma  (PQ,R,PQ);		///adunarea P.c[i]*R la PQ
        Produs(A,Q,A);			///calcul Q^(i+1) in A
    }
}

int main()
{   Polinom P,Q,PQ;
    CitPol(P);
    CitPol(Q);
    Compus(P,Q,PQ);
    cout<<"P(Q(x)):";
    AfisPol(PQ);
    Compus(Q,P,PQ);
    cout<<"Q(P(x)):";
    AfisPol(PQ);
    cout << "Program terminat" << endl;
    return 0;
}

