#include <iostream>
#include <iomanip>
using namespace std;

void CreMat(int n, int A[10][10])
{ int i,j,k;
  k=0;
  for(j=1;j<=n;j++)
  {   for(i=1;i<=j;i++)         //pe coloana in jos pana la diag principala
          A[i][j]=++k;
      for(i=j-1;i>=1;i--)       //pe linia j spre stanga
          A[j][i]=++k;

  }

}

int main()
{   int n=5;
    int A[10][10];
    CreMat(n,A);
    for(int i=1;i<=n;i++)
    {
        for (int j=1 ; j<=n;j++) cout<<setw(3)<<A[i][j];
        cout<<endl;
    }
    return 0;
}
