#include <iostream>

using namespace std;

struct Pol{
  int grad;
  int C[100];
};

void Suma(Pol P, Pol Q,  Pol& S){
   S.grad =(P.grad >= Q.grad ? P.grad : Q.grad);
   int Min=(P.grad <= Q.grad ? P.grad : Q.grad);

   for(int i=0;i<=Min;i++)
      S.C[i]=P.C[i]+Q.C[i];

   for(int i=Min+1;i<=P.grad;i++)        ///numai unul din cele 2 cicluri care urmeaza se executa
      S.C[i]=P.C[i];
   for(int i=Min+1;i<=Q.grad;i++)        ///numai unul din cele 2 cicluri care urmeaza se executa
      S.C[i]=Q.C[i];
}

void Citire(int &n, Pol P[10]){
   int i,j;
   cout<<"cate polinoame:"; cin>>n;
   for(i=1;i<=n;i++){
      cout<<"da grad:"; cin>>P[i].grad;
      for(j=0;j<=P[i].grad;j++)
        cin>>P[i].C[j];
   }
}

void Afisare(Pol S){
   cout<<endl<<"Polinomul suma:"<<endl;
   cout<<S.C[0];
   for(int i=1;i<=S.grad;i++)
      cout<<"+"<<S.C[i]<<"X^"<<i;

}

long ValPol(Pol P, int x){
   long VP=0;
   for(int i=P.grad;i>=0;i--){
      VP=VP*x+P.C[i];
   }
   return VP;
}

int main()
{   Pol P[10];     ///P[i].grad; P[i].c[j]
    int n;
    Citire (n,P);
    Pol S=P[1];
    for(int i=2;i<=n;i++)
        Suma(S,P[i],S);
    Afisare(S);
    cout<<endl<<ValPol(S,-1)<<endl;;
    cout << "Program terminat" << endl;
    return 0;
}
