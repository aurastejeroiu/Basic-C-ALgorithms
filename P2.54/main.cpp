#include <iostream>

using namespace std;

int main()
{  int n=11,m=9;
   int x[]={0,1,2,3,41,51,61,71,81,91,301,401};
   int y[]={0,1,21,81,86,87,88,91,92,401};
   int z[100]={0};
   int i,j,k,l;
   i=j=1;
   k=0;
   while(i<=n && j<=m)
   { if(x[i]<y[j])
       { k++;
         z[k]=x[i];
         i++;
       }
     else if(x[i]>y[j])
            { k++;
              z[k]=y[j];
              j++;
            }
          else                  //aici x[i]==y[j]
            { i++;
              j++;
            }
   }
   for(l=i;i<=n;i++) z[++k]=x[l];
   for(l=j;j<=m;j++) z[++k]=y[l];

   for(l=1;l<=k;l++)
         cout<<z[l]<<" ";

   cout << "Hello world!" << endl;
    return 0;
}
