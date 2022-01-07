#include <iostream>
#include <iomanip>
using namespace std;

void CreMat(int n, int A[10][10])
{ int i,j,k;
  k=0;
  for(j=1;j<=n;j++)
  {   for(i=1;i<=j;i++)         //pe coloana in jos pana la diag principala
          A[i][j]=++k;
      for(i=j-1;i>=1;i--)       //pe linia j spre stanga pana la col.1 1
          A[j][i]=++k;
  }
}
void CuFormula(int n, int A[10][10])
{
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(i<=j) A[i][j]=(j-1)*(j-1)+i;   ///deasupra diag. principale
      else     A[i][j]=i*i-j+1;         ///sub diag. principala

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
