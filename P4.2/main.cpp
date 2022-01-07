#include <iostream>
#include <iomanip>
using namespace std;

void AdaugaSumaLinii(int m, int n, int A[20][4]){
    for(int i=0;i<m;i++)
        {int S=0;
         for(int j=0;j<n-1;j++)
             S+=A[i][j];
         A[i][n-1]=S;
         //cout<<S<<endl;
        }

}

void Afis (int m, int n, int A[][4])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(5)<<A[i][j];
        cout<<endl;
    }

}
int main()
{
    int m,n, A[5][4]={{1,2,3,0},{-1,4,5,0},{6,7,8,0},{12,13,14,0},{-9,10,11,0}};
    m=5,n=4;
    Afis(m, n, A);
    AdaugaSumaLinii(m, n, A);
    cout<<endl;
    Afis(m, n, A);
    cout<<endl;
    return 0;
}
