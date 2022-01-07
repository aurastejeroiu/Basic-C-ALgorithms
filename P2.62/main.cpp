#include <iostream>
using namespace std;

bool Prim(long n){
  if(n<2) return false;
  if(n>2 && n%2==0) return false;
  for(int d=3;d*d<=n;d+=2)
     if(n%d==0) return false;
  return true;
}

int main()
{   int n,V[1000],i,j,k;    ///i indice pentru V
    cout<<"da n:"; cin>>n;  ///k indice pentru perechile de gemene
    V[1]=3; V[2]=5;
    i=3;
    k=5;

    while(i<=n)
    {  while(!Prim(k) || !Prim(k+2)) k+=2;
       V[i++]=k;
       V[i++]=k+2;
       k+=2;
    }

    for(i=1;i<=n;i++)
        cout<<V[i]<<" ";
    return 0;
}
