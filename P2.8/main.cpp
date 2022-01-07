#include <iostream>

using namespace std;

void PMax(int x[], int n, int P[], int &k){
   P[k=1]=1;
   for(int i=2;i<=n;i++)
    { if(x[i]>x[P[1]]) P[k=1]=i;
      else
        if(x[i]==x[P[1]]) P[++k]=i;
    }
}


int main()
{ int x[]={0,5, 4,5,14,5,4,5,4,5,14,5,140,5,4,5,14,5,4,5,4};
   int  P[100];
   int  n,i,k;
   n    =20;
   PMax(x,n,P,k);
   for(i=1;i<=k;i++)
       cout << P[i]<<" ";
   return 0;
}

