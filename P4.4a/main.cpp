#include <iostream>
#include <iomanip>
using namespace std;

void EliminNegat(int &m, int n, int A[20][3]){
    for(int i=0;i<m;i++)
        {int ok=1;
         for(int j=0;j<n && ok==1; j++)
             if(A[i][j]<0) ok=0;
         if(!ok)
             {for(int j=i;j<m-1;j++)
                  for(int k=0;k<m;k++)
                      A[j][k]=A[j+1][k];
              m--;
              i--;
             }
        }
}

void Afis (int m, int n, int A[][3])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(5)<<A[i][j];
        cout<<endl;
    }

}
int main()
{   int m,n, A[5][3]={{-1,-2,30},{1,4,5},{-6,-7,8},{12,13,14},{9,10,-11}};
    m=5,n=3;
    Afis(m, n, A);
    EliminNegat(m, n, A);
    cout<<endl;
    Afis(m, n, A);
    cout<<endl;
    return 0;
}
