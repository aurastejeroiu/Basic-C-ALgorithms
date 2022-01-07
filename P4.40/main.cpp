#include <iostream>
#include <iomanip>
using namespace std;

void CreMat(int n, int A[10][10])
{ int i,j,k;
  k=0;
  for(i=1;i<=n;i++)             /// i reprezinta numarul de paralelele cu diag secundara
     for(j=1;j<=i;j++)          ///paralelele deasupra diag. secundare
          A[j][i-j+1]=++k;

  for(i=n-1;i>=1;i--)           /// i reprezinta numarul de paralelel cu diag secundara
     for(j=n-i+1;j<=n;j++)      ///paralele de sub diag. secundara
          A[j][2*n-i-j+1]=++k;

}


void CuFormula(int n, int A[10][10])
{ int i,j,k;
  for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
          A[i][j]=0;
  k=0;
  for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)         //paralelele deasupra diag. secundare
       if(i+j<=n+1)   A[i][j]=(i+j-2)*(i+j-1)/2+i;
       else           A[i][j]=n*n-n+j;     ///???

}
void Afis(int n, int A[10][10]){
  for(int i=1;i<=n;i++)
    { for (int j=1 ; j<=n;j++) cout<<setw(3)<<A[i][j];
        cout<<endl;
    }
}

int main()
{   int n=5;
    int A[10][10];
    CreMat(n,A);
    Afis(n,A);
    cout<<endl<<"cu formula:\n";
    CuFormula(n,A);
    Afis(n,A);
    return 0;
}
