#include <iostream>
#include <iomanip>
using namespace std;

void CreMat(int n, int A[10][10])
{ int i,j,k;
  k=0;
  for(i=1;i<=n/2+1;i++)
  {
      for(j=i;j<=n-i+1;j++)         //pe linie de la stanga la dreapta
          A[i][j]=++k;
      for(j=i+1;j<=n-i+1;j++)       //pe coloana in jos
          A[j][n-i+1]=++k;
      for(j=n-i;j>=i;j--)           //pe linie de la stanga la dreapta
           A[n-i+1][j]=++k;
      for(j=n-i;j>i;j--)            //pe coloana in  sus
           A[j][i]=++k;
  }

}

int main()
{   int n=8;
    int A[10][10];
    CreMat(n,A);
    for(int i=1;i<=n;i++)
    {
        for (int j=1 ; j<=n;j++) cout<<setw(3)<<A[i][j];
        cout<<endl;
    }
    return 0;
}
