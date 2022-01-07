#include <iostream>

using namespace std;

int Prime(long n)
{  if(n<2) return 0;
   long d=2;
   while(d*d<=n && n%d!=0)
        if(d==2) d=3;
        else     d+=2;
   if(d*d>n) return 1;
             return 0;
}

long Y(long n)
{ return n*n-79*n+1601;
}


int main()
{  long i,C=0;
   for(i=1;i<=90; i++)
     if(Prime(Y(i))) C++;
   cout << "exista "<<C<<" numere prime "<< endl;
   return 0;
}
