#include <iostream>

using namespace std;

int Prime(long n){          ///retur 1, n e prim
    if(n<2)  return 0;      ///return 0, n nu este prim
    long d;                        ///d e in {2,3,5,7,...rad(n)}
    for(d=2; (d*d<=n && n%d!=0); (d==2)? d++ : d+=2);
    if(d*d>n) return 1;
    /*else*/  return 0;
}

void Citire(long &n){
   cout<<"da n>0:";
   cin >>n;
}

void AfisPrime(long n){
   for(long i=2;i<=n;i++)
      if(Prime(i)) cout<<i<<" ";
}

int main()
{   long n;
    Citire(n);
    AfisPrime(n);
    cout << "\nProgram terminat" << endl;
    return 0;
}
