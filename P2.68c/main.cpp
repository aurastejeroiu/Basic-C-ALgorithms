#include <iostream>

using namespace std;

int  P(long n){
  	  if(n<2) return 0;
  	  if(n>2 && n%2==0) return 0;
  	  for(int d=3;d*d<=n;d+=2)
     		if(n%d==0) return 0;
  	  return 1;
      }


void CreV (int n, int V[]){
    int i,j,k;
    V[1]=1;
    i=2;                    ///i indice penru V
    k=2;
    while(i<=n)
    {   j=2;                ///j pentru divizori
        if (P(k)) V[i++]=k;
        while(i<=n && j<=k/2){
                if(k%j==0)
                {   V[i++]=j;
                }
                j++;
            }
        k++;
    }
}

int main()
{   int n,V[1000];
    cout<<"da n:"; cin>>n;    ///n este lung. V
    CreV(n,V);
    for(int i=1;i<=n;i++)
        cout<<V[i]<<" ";
    return 0;
}
