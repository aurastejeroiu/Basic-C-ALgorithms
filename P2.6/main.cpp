#include <iostream>

using namespace std;

struct Numar {
  int L=0;
  int cif[1000];

};

void Multiply(Numar a, Numar b, Numar& p){
  int i,j,Transport=0;
  p.L=a.L + b.L;
  for (i=0; i< p.L; i++)            	//initializare cifre produs cu 0
     p.cif[i]=0;
  for (i=0; i< a.L;i++)
    for (j=0; j< b.L;j++)
           {p.cif[i+j]  +=a.cif[i]*b.cif[j];
            Transport    =p.cif[i+j] / 10;
            p.cif[i+j]   =p.cif[i+j] % 10;
            p.cif[i+j+1]+=Transport;  		//aduna transportul pozitiei urmatoare
           }
     //EliminZero();  				//eliminare 0 nesemnificative}
 }
void Citire (long m, Numar& M)
{
    cout<<"da un natural:";
    cin >>m;
    int i=0;
    while(m>0)
    { M.cif[i]=m%10;
      m/=10;
      i++;
    }
    M.L=i;
}
void AfisareNumar(Numar X)
{   int i=X.L-1;
    while(X.cif[i]==0) i--;  //cifrele o nesemnificativi nu le afisez
    for(int j=i;j>=0;j--)
        cout<<X.cif[j];
    cout<<endl;
}

int main()
{   long m,k,i;
    Numar M,F,P;
    Citire(m,M);
    cout<<"da exponent:";
    cin >>k;
    //AfisareNumar(M);
    F=M;
    Multiply(F,M,P);     //B=M^2 (M*M)
    for(i=3;i<=k;i++)    //B se inmulteste iterativ cu M
      { M=P;
        Multiply(F,M,P);
      }
    AfisareNumar(P);
    cout << "Hello world!" << endl;
    return 0;
}
