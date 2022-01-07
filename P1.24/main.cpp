#include <iostream>

using namespace std;

long CNK(long n, long k)
{ if(n==k || k==0) return 1;
  if(n<k)          return 0;
  return n*CNK(n-1,k-1)/k;
}

float SumInv(long k)
{ float S=0;
  for (float i=1.0; i<=k;i++)
    S=S+1.0/i;
  return S;
}

int main()
{ long n,k;
  cout<<"da n:";
  cin >>n;
  float S=0;
  for (k=1;k<=n;k++)
    S=S+CNK(n,k)*SumInv(k);
  cout<<endl<<S;


    return 0;
}
