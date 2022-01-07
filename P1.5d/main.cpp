#include <iostream>

using namespace std;

///1.5 Doua numere diferite x si y sunt "prietene" daca suma divizorilor numarului x este egala
///    cu suma divizorilor numarului y. Sa se gaseasca numerele "prietene" din intervalul [a,b]

///Idee: se va verifica cate numere din [a,b] au aceeasi suma a divizorilor S
///

long SumDiv(long n)
{ long S=n+1;
  for(long d=2; d*d<=n; d++)		//O(rad(n))
    if(n%d==0)   			        //S+=i+n/i;
       { if(d==n/d) S+=d;
         else       S+=d+n/d;
      }
  return S;
}

void AfisPrietene(long a, long b)
{  for(int i=a;i<b;i++){
     int ok=0;
     long SI=SumDiv(i);
     for(int j=i+1;j<=b;j++){
        if(SI==SumDiv(j))
            if(ok==0) cout<<"Suma="<<SI<<" are priteni:"<<i<<","<<j, ok=1;
            else      cout<<","<<j;
     }
     if(ok) cout<<endl;
  }
}

int main()
{   long a,b;
    cout<<"da a:"; cin>>a;  //citire interval
    cout<<"da b:"; cin>>b;
    AfisPrietene(a,b);
    cout << "Program terminat" << endl;
    return 0;
}
