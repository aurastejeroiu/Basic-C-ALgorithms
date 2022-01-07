#include <iostream>

using namespace std;

struct Numar {
  int L=0;          ///nr de cifre
  int cif[20000];   ///spatiul de memorare al cifrelor, 123 se memoreaza ca 321
};

void Adunare(Numar a, Numar b, Numar& p){
  int i,Transport=0;
  p.L=a.L>b.L ? a.L : b.L;          ///nr maxim de cifre ale sumei este maximum din nr de cifre
                                ///ale lui a si b;
  for (i=0; i< p.L+1; i++)      ///initializare cifre suma cu 0
     p.cif[i]=0;
  int minL=a.L <b.L?a.L:b.L;    ///determinam lungimea minima
  for (i=0; i< minL;i++) {
    p.cif[i]    +=a.cif[i]+b.cif[i]; ///se aduna la poz i a.cif[i] si b.cif[i]
    Transport    =p.cif[i] / 10;	 ///se determina transportul
    p.cif[i]     =p.cif[i] % 10;	 ///se retine in p.cif[i] doar modulo 10
    p.cif[i+1]  +=Transport;  		 ///aduna transportul pozitiei urmatoare
  }
                            ///din urmatoarele 2 cicluri se executa doar unul
  for(i=minL;i<a.L;i++){
    p.cif[i]    +=a.cif[i];          ///se aduna la poz  a.cif[i] la p.cif[i]
    Transport    =p.cif[i] / 10;	 ///se determina transportul
    p.cif[i]     =p.cif[i] % 10;	 ///se retine in p.cif[i] doar modulo 10
    p.cif[i+1]  +=Transport;  		 ///aduna transportul pozitiei urmatoare
  }
  for(i=minL;i<b.L;i++){
    p.cif[i]    +=b.cif[i];           ///se aduna la poz  b.cif[i] la p.cif[i]
    Transport    =p.cif[i] / 10;	 ///se determina transportul
    p.cif[i]     =p.cif[i] % 10;	 ///se retine in p.cif[i] doar modulo 10
    p.cif[i+1]  +=Transport;  		 ///aduna transportul pozitiei urmatoare
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
    cout<<endl;
}

int main()
{   Numar A,B,Suma;
    Citire(A);
    Citire(B);
    AfisareNumar(A);
    AfisareNumar(B);
    Adunare(A,B,Suma);
    AfisareNumar(Suma);
    cout <<endl<< "Program terminat" << endl;
    return 0;
}
