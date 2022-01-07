#include <iostream>
#include <iomanip>
using namespace std;

void Sortare1(int m, int n, int A[20][3]){
    for(int i=0;i<m-1;i++)
        for(int j=i+1;j<m;j++)
            {if(A[i][0]>A[j][0])
                 for(int k=0;k<n;k++)
                     {int aux=A[i][k];
                      A[i][k]=A[j][k];
                      A[j][k]=aux;
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
    Sortare1(m, n, A);
    cout<<endl;
    Afis(m, n, A);
    cout<<endl;
    return 0;
}
