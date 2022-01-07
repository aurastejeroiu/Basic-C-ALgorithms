#include <iostream>

using namespace std;
///P2.6. Se dau m,k>0, naturale. Sa se determine cele n cifre ale numarului m^k.


struct Numar {
  int L;           ///nr de cifre
  int cif[5000];   ///spatiul de memorare al cifrelor, 123 se memoreaza ca 321, L=3
};

void Multiply(Numar a, Numar b, Numar& p){
  int i,j,Transport;
  p.L=a.L + b.L;            ///nr maxim de cifre ale produsului este suma nr de cifre
                            ///ale lui a si b;
  for (i=0; i< p.L; i++)    ///initializare cifre produs cu 0
     p.cif[i]=0;

  for (i=0; i< a.L;i++)
    for (j=0; j< b.L;j++)
           {p.cif[i+j]  +=a.cif[i]*b.cif[j];    ///se aduna la poz i+j a.cif[i]*b.cif[j]
            Transport    =p.cif[i+j] / 10;	    ///se determina transportul
            p.cif[i+j]   =p.cif[i+j] % 10;	    ///se retine in p.c[i+j] doar modulo 10
            p.cif[i+j+1]+=Transport;  		    ///aduna transportul pozitiei urmatoare
           }

 }

void Citire (Numar& M)
{   long 	m;
    cout<<	"da un natural:";
    cin >>	m;
    int 	i=0;
    while(m>0)				///se retine oglinditul, dar pe vector
    { 	M.cif[i]=m%10;
      	m/=10;
      	i++;
    }
    M.L=i;

}

void AfisareNumar(Numar X)
{   int i=X.L;
    while(X.cif[i]==0) i--;  ///cifrele 0 nesemnificative nu le afisez
    for(int j=i;j>=0;j--)
        cout<<X.cif[j];
    cout<<endl<<"are "<<i+1<<" cifre"<<endl;;

}
void MlaK(Numar M, int k, Numar &P){
    Multiply(M,M,P);        /// P=M^2 (M*M)
    for(int i=3;i<=k;i++)   /// P se inmulteste iterativ cu M, rezultatul tot in P
       Multiply(P,M,P);     /// pentru k=0,1 nu merge
}

void CitireDate(Numar &M, int &k){
    Citire(M);
    cout<<"da exponent:";
    cin >>k;
}

int main()
{   int k;
    Numar M,P;
    CitireDate(M,k);    ///citirea date
    AfisareNumar(M);    ///afisare numar initial
    MlaK(M,k,P);        ///determinare M^k, rezultat in P
    AfisareNumar(P);    ///afisare rezultat
    cout <<endl<< "Program terminat" << endl;
    return 0;
}
