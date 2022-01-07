#include <iostream>

using namespace std;

int main()
{  int n=11,m=9;
   int x[]={0,-1,2,3,41,51,61,71,81,91,301,401};
   int y[]={0,1,21,41,86,87,88,91,92,402};
   int z[100]={0};
   int i,j,k,l;
   i=j=1;
   k=0;
   while(i<=n && j<=m)
   { k++;
     if(x[i]<y[j])      z[k]=x[i++];
     else if(x[i]>y[j]) z[k]=y[j++];
          else                  ///aici x[i]==y[j]
            { z[k]=x[i++];      ///se inainteaza cu indicii in ambele secvente x si y
              j++;
            }
   }
                                    ///doar unul din ciclurile for se executa
   for(l=i;i<=n;i++) z[++k]=x[l];   ///se scrie din x, daca s-a epuizat y
   for(l=j;j<=m;j++) z[++k]=y[l];   ///se scrie din y, daca s-a epuizat x.

   for(l=1;l<=k;l++)
         cout<<z[l]<<" ";

   cout << "\nProgram terminat" << endl;
    return 0;
}
