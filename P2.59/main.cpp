#include <iostream>

using namespace std;

struct Numar {
  int L=0;          ///nr de cifre
  int cif[20000];   ///spatiul de memorare al cifrelor, 123 se memoreaza ca 321
};

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
int DetKod(Numar A, Numar B){
    if(A.L<B.L)      return 1;
    else if(A.L>B.L) return 2;
         else{
            int i=0;
            while(i<A.L && (A.cif[i]==B.cif[i]))
                i++;
            if (i==A.L) return 0;
            if (A.cif[i]<B.cif[i]) return 1;
            else                   return 2;
    }
}
int main()
{   Numar A,B;
    Citire(A);
    Citire(B);
    AfisareNumar(A);
    AfisareNumar(B);
    int kod=DetKod(A,B);
    if(kod==0) cout<<"A=B";
    else if(kod==1) cout<<"A<B";
         else       cout<<"A>B";
    cout <<endl<< "Program terminat" << endl;
    return 0;
}
