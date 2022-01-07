#include <iostream>
#include <iomanip>
using namespace std;

void CreVector(int m, int n, int A[20][3], int V[3]){
    for(int i=0;i<n;i++)
        {int mx=A[0][i];
         for(int j=0;j<m;j++)
             if(A[j][i]>mx) mx=A[j][i];
         V[i]=mx;
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
{
    int m,n, A[5][3]={{1,2,3},{-1,4,5},{6,7,8},{12,13,14},{-9,10,11}};
    int V[3];
    m=5,n=3;
    Afis(m, n, A);
    CreVector(m, n, A,V);
    for(int i=0;i<n;i++)
        cout<<V[i]<<" ";
    cout<<endl;
    //AfisVect(m, n, A);
    cout<<endl;
    return 0;
}
