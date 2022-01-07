#include <iostream>

using namespace std;

int main()
{ int x[]={5,4,54,6,54,45,54,43};
   int V[100];
   int n,i,poz,maxim;
   n=8;
   maxim=x[0];
   poz=0;
   V[poz]=0;
   for(i=1;i<n;i++)
    { if(x[i]>maxim)
        {maxim=x[i];
         poz=0;
         V[poz]=i;
        }
      else
        if(x[i]==maxim)
        { poz++;
          V[poz]=i;
        }
    }
    for(i=0;i<=poz;i++)
        cout << V[i]<<" ";

     return 0;
}

