#include <iostream>

using namespace std;



void Dif ( long bb , long a , long b, long &c) ///a e mai lung ca b si a>=b
{  long p=1;
   int T=0;         /// T = transpprtul, initializat cu 0
   c=0;
   while(a>0||b>0)
    { int cifa=a%10;    /// cifa = ultima cifra a lui a
      int cifb=b%10;    /// cifb = ultima cifra a lui b
      if(cifa>=cifb)    /// se adauga T anterior la c si avem T = 0
         {c+=(cifa-cifb+T)*p;
          T=0;
         }
      else
         {c+=(bb+cifa-cifb+T)*p;        /// daca ultima cifra a lui b estte mai mare decat ultima
          T=-1;                         /// cifra a lui a, transportul devine -1
         }
      p*=10;            /// crestem ordinul
      a/=10;            /// stergem ultimele cifre ale lui a si b
      b/=10;
    }
}


void Suma ( long bb , long a , long b, long &c)
{
    int T=0;            /// T = transportul, initializat cu 0
    long p=1;           /// p = ordinul cifrei ( 1, 10, 100 etc. )
    c=0;                /// c = suma returnata
    while(a>0||b>0)     /// cat timp exista cifre in cel putin unul dintre termeni
    {
        int cifa=a%10;      /// cifa = ultima cifra a lui a
        int cifb=b%10;      /// cifb = ultima cifra a lui b
        int Suma=T+cifa+cifb;   /// suma = suma ultimelor cifre a lui a si b + transportul T
        c+=(Suma%bb)*p;         /// c = se retine modulo
        T=Suma/bb;              /// calculam transportul T
        p*=10;                  /// crestem ordinul
        a/=10;                  /// stergem ultimele cifre ale lui a si b
        b/=10;
    }
    if(T==1)                    /// daca transportul T = 1, se adauga cifra 1 la suma
        c+=1*p;
}
int Lungime(long x){
  int L=0;
  while(x>0){
    L++;
    x/=10;
  }
  return L;
}

void Afisare(long x){
  int L=Lungime(x);
  for(int i=10-L;i>0;i--) cout<<' ';
  cout<<x;

}

int main()
{   long X, Y, S,D;
    Y=123;
    X=12345;
    int b=6;
    Suma(b,X,Y,S);
    cout<<endl;
    cout<<"X   =";Afisare(X);cout<<endl;
    cout<<"Y   =";Afisare(Y);cout<<endl;
    cout<<"Suma=";Afisare(S);cout<<endl;
    //Y=S;
    Dif(b,X,Y,D);
    cout<<"X   =";Afisare(X);cout<<endl;
    cout<<"Y   =";Afisare(Y);cout<<endl;
    cout<<"Dif =";Afisare(D);
    cout<<endl;

    cout << "\nProgram terminat" << endl;
    return 0;
}
