#include <iostream>

using namespace std;
///P1.9 Fie functia lui Euler fi:N->N, fi(n) este numarul numerelor relativ prime cu n
///     si mai mici ca n. Sa se tipareasca valorile fi(k), k=1,2,...,m pentr m natural dat.

///Idee: Se contorizeaza valorile i<k pentru care CMMDC(i,k)=1.

long CMMDC(long a, long b)          ///cmmdc(a,b) recursiv prin scadere
{ if(a==b)  return a;
  if(a>b)   return CMMDC(a-b,b);
            return CMMDC(a,b-a);
}
long Euler(long n){
   int cont=0;
   for(long j=1;j<n;j++)
      if(CMMDC(j,n)==1) cont++;
   return cont;
}

int main()
{   long m;
    cout<<"da m:";
    cin >>m;
    cout<<"functia lui Euler:"<<endl;
    for(long k=1;k<=m;k++)
    { cout<<"fi("<<k<<")="<<Euler(k)<<endl;
    }

    cout << "Program terminat" << endl;
    return 0;
}
