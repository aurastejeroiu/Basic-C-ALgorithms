#include <iostream>
using namespace std;

int NrDiv (int n,int X[],int p)
{ int NrP, Put,i;

  NrP=0;
  for (i=1;i<=n;i++)
    {
      Put=p;
      while((X[i]>=Put) and ((X[i] % p)==0))
        {
          NrP=NrP+1;
          X[i]=X[i]/p;
        }
    }

return NrP;
}

int main()
{int NrZero, p, n, X[100], Nr2,Nr5,i ;
  cout<<"da n=";
  cin>>n;
  for (i=1;i<=n;i++)
 	cin>>X[i];

  Nr2=NrDiv(n,X,2);
  Nr5=NrDiv(n,X,5);
  if(Nr2<Nr5) cout<<" produsul se termina in "<<Nr2<<" de 0";
  else        cout<<" produsul se termina in "<<Nr5<<" de 0";
  return 0;
}
