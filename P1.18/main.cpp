#include <iostream>

using namespace std;

int Prime(long n)               //cea mai eficienta metoda de primalitate
{  if(n<2) return 0;
   if(n>2 && n%2==0) return 0;
   for(int d=3;d*d<=n;d=d+2)   //pentru n=2,3,5,7 nu se intra in ciclu
      if(n%d==0) return 0;
   return 1;
}

long Y(long n)
{ return n*n-79*n+1601;
}


int main()
{  long i,C=0;
   for(i=1;i<=90; i++)
     if(Prime(Y(i))) {C++;
                      cout<<C<<"."<<Y(i)<<endl;
     }
   cout << "exista "<<C<<" numere prime "<< endl;
   return 0;
}
