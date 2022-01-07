#include <iostream>

using namespace std;

void VectExp(long n, long& lung, long V[]){    ///determina numarul format din exponentii
  if(n<1) {                                  ///descompunerii in factori primi ai lul nr
           lung=0;                           ///si se pun intr-un vector v de lungime lung
           return;                           ///exemplu nr=100 lung=4, v =(2,2,5,5);
  }
  if (n==1) {
        lung=1;
        V[1]=1;
        return;
  }
  lung=0;
  for(long i=2;i<=n;i++)
   {while(n%i==0){
       V[++lung]=i;
       n/=i;
    }
   }
}

long Prim(long p){

   for(long d=3;d*d<=p;d+=2)
     if(p%d==0) return 0;
   return 1;


}

long UrmatPrim(long nr){
   if(nr==1 or nr==2) return ++nr;
   nr+=2;
   while(!Prim(nr))
     nr+=2;
   return nr;
}

long CalculNr(long lung, long V[] ){
   long Nr=1;
   long prim=2;
   while(lung>0){
      long Exp=V[lung];
      while(Exp>1){
        Nr=Nr*prim;
        Exp--;
      }
      cout<<endl<<"urmatorul prim="<<prim<<endl;
      prim=UrmatPrim(prim);

      lung--;
   }
   return Nr;



}

int main()
{   long n,lung,V[100];
    cout<<"da numarul de divizori:";
    cin >>n;
    VectExp(n,lung,V);
    cout<<"numarul cerut="<<CalculNr(lung, V);
    cout << "\nProgram terminated" << endl;
    return 0;
}
