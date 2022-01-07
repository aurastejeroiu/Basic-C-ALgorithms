#include <iostream>

using namespace std;

///1.5 Doua numere diferite x si y sunt "prietene" daca suma divizorilor numarului x este egala
///    cu suma divizorilor numarului y. Sa se gaseasca numerele "prietene" din intervalul [a,b]


long SumDiv(long n)
{ long S=n+1;
  for(long d=2; d*d<=n; d++)		//O(rad(n))
    if( n%d==0)   			        //S+=i+n/i;
        if(d==n/d) S+=d;
        else       S+=d+n/d;
  return S;
}

void Elim(long a[], long& n, long p){
  for(long j=p;j<n;j++) a[j]=a[j+1];
  n--;
}

int main()
{   long x[1000],n,i,j,a,b;
    cout<<"da a:"; cin>>a;  ///citire interval
    cout<<"da b:"; cin>>b;
    n=b-a;
    for(i=1;i<=n;i++)
        x[i]=a++;
    cout<<"numerele prietene sunt:"<<endl;
    for(i=1;i<n;i++){
        cout<<x[i]<<" ";
        for(j=i+1;j<=n;j++){
            if(SumDiv(x[i])==SumDiv(x[j])) cout<<x[j]<<" ";
            Elim(x,n,j);
            j--;
        }
        cout<<" cu suma diviz.="<<SumDiv(x[i])<<endl;
        Elim(x,n,i);
        i--;
    }


    cout << "Program terminat" << endl;
    return 0;
}
