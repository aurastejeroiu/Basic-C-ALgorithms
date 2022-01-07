#include <iostream>

using namespace std;
///1.3. Sa se verifice daca numarul natural nenul, n este perfect.
///     Un numar natural n este perfect daca este egal cu suma divizorilor sai
///     (mai putin el insusi).
///     Exemplu 6=1+2+3

int  SumaDiv(long n, long d){    ///retur suma divizorilor lui n (fara n), d=2 apelul primar
     if(n<=1)   return 0;
     if(d*d>n)  return 1;
     if(d*d==n) return 1+d;
     if(n%d==0) return d+n/d +SumaDiv(n,d+1);
                return SumaDiv(n,d+1);
}

int main()
{   long n,d=2;
    do{                                 ///citire cu validare natural nenul
      cout<<"da numar natural, nenul:";
      cin >>n;
      if(n<=0) cout<<"ai gresit!!!";
    }
    while (n<=0);
    for(long i=1;i<=n;i++)
       if(SumaDiv(i,d)==i) cout<<i<<" este perfect "<<endl;

    cout << endl;
    cout << "Program terminat" <<endl;
    return 0;
}
