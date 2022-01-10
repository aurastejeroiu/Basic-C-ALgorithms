#include <iostream>

using namespace std;

struct Numar {
  int L=0;          ///nr de cifre
  int cif[20000];   ///spatiul de memorare al cifrelor, 123 se memoreaza ca 321

};


void Multiply(Numar a, Numar b, Numar& p){
  int i,j,Transport=0;
  p.L=a.L + b.L;            ///nr maxim de cifre ale produsului este suma nr de cifre
                            ///ale lui a si b;
  for (i=0; i< p.L; i++)    ///initializare cifre produs cu 0
     p.cif[i]=0;

  for (i=0; i< a.L;i++)
    for (j=0; j< b.L;j++)
           {p.cif[i+j]  +=a.cif[i]*b.cif[j];///se aduna la poz i+j a.c[i]*b.c[j]
            Transport    =p.cif[i+j] / 10;	///se determina transportul
            p.cif[i+j]   =p.cif[i+j] % 10;	///se retine in p.c[i+j] doar modulo 10
            p.cif[i+j+1]+=Transport;  		///aduna transportul pozitiei urmatoare
           }
     ///EliminZero();  				eliminare 0 nesemnificative}
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
{   int i=X.L-1;
    while(X.cif[i]==0) i--;  ///cifrele 0 nesemnificativi nu le afisez
    for(int j=i;j>=0;j--)
        cout<<X.cif[j];
    cout<<endl;
}

int main()
{   long k,i;
    Numar M,F,P;
    Citire(M);
    cout<<"da exponent:";
    cin >>k;
    ///AfisareNumar(M);
    F=M;		        /// F si M sunt egale
    Multiply(F,M,P);    /// P=M^2 (M*M)
    for(i=3;i<=k;i++)   /// P se inmulteste iterativ cu M
      { F=P;
        Multiply(F,M,P);
      }
    AfisareNumar(P);
    cout << "Hello world!" << endl;
    return 0;
}
