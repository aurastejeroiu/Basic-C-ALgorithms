#include <iostream>
#include <iomanip>
using namespace std;

void AfisMat(int n, int A[10][10])
{for(int i=1;i<=n;i++)
    {for (int j=1 ; j<=n;j++) cout<<setw(3)<<A[i][j];
       cout<<endl;
    }
}

void CreMat(int n, int A[10][10])   ///explicatii ???
{ int i,j,k;
  k=0;
  for(i=1;i<=n/2; i++)              ///i numara spiralele (se fac [n/2] spirale)
    { for(j=i;j<=n-i;j++)           ///pe linie de la stanga la dreapta
          A[i][j]=++k;              ///(n-i)-(i-1)=n-2i+1 elemente

      for(j=i;j<=n-i;j++)           ///pe coloana in jos
          A[j][n-i+1]=++k;          ///(n-i)-(i-1)=n-2i+1 elemente

      for(j=n-i+1;j>i;j--)          ///pe linie de la  dreapta la stanga
           A[n-i+1][j]=++k;         ///(n-i)-(i-1)=n-2i+1 elemente

      for(j=n-i+1;j>i;j--)          ///pe coloana in  sus,
           A[j][i]=++k;             ///(n-i)-(i-1)=n-2i+1 elemente
    }

   if(n%2==1) A[n/2+1][n/2+1]=++k;
}

int main()
{   int n=5;
    int A[10][10];
    CreMat(n,A);
    cout<<endl<<"matricea finala:"<<endl;
    AfisMat(n,A);
    cout<<endl<<"program terminat\n";
    return 0;
}
