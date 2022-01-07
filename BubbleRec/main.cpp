#include <iostream>
#include<stdio.h>

using namespace std;

void buble(int a[],int n,int ok)
{if (ok==1) return 1;
 else { ok=1;
        for(int i=0;i<n-1;i++)
           if(a[i]>a[i+1])
              { int aux=a[i];
                   a[i]=a[i+1];
                 a[i+1]=aux;
                ok=0;
              }
        buble(a,n-1,ok);
      }
}



int main()
{  int n;
   int a[10]={10,9,8,7,6,5,4,3,2,1};
   n=10;
   buble(a,n,0);
   for(int i=0;i<n;i++)
      printf("%d ",a[i]);

   cout << "Hello world!" << endl;
   return 0;
}
