#include <iostream>
#include <iomanip>
using namespace std;

void AfisMat(int n, int A[10][10])
{for(int i=1;i<=n;i++)
    {for (int j=1 ; j<=n;j++) cout<<setw(3)<<A[i][j];
       cout<<endl;
    }

}

void CreMat(int n, int A[10][10])
{ int i,j,k;
  k=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
       A[i][j]=0;
  for(i=1;i<=n/2+1;i++)
  {
      for(j=i;j<=n-i+1;j++)         //pe linie de la stanga la dreapta
          A[i][j]=++k;              //n-2*(i-1) elemente

      for(j=i+1;j<=n-i+1;j++)           //pe coloana in jos
          A[j][n-i+1]=++k;

      for(j=n-i;j>=i;j--)           //pe linie de la stanga la dreapta
           A[n-i+1][j]=++k;

      for(j=n-i;j>i;j--)            //pe coloana in  sus
           A[j][i]=++k;
      cout<<"dupa spirala:"<<i<<endl;
      AfisMat(n,A);
  }

}

int main()
{   int n=7;
    int A[10][10];
    CreMat(n,A);
    cout<<endl<<"matricea finala:"<<endl;
    AfisMat(n,A);
    cout<<endl<<"program terminat\n";
    return 0;
}
