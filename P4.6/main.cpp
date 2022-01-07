#include <iostream>
#include <iomanip>
using namespace std;

void Citeste (int &m, int&n, int A[][10])
{
    cout<<"Da linia si coloana:";
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];
}

void Elimin (int &m, int n, int A[][3], int lin)
{
    for(int i=lin;i<m;i++)
        for(int j=0;j<n;j++)
            A[i][j]=A[i+1][j];
    m--;
}

void Negative (int &m, int n, int A[][3])
{
    int i=0;
    while(i<m)
    {   int j=0;
        while(j<n && A[i][j]>=0) j++;
        if(j<n) Elimin(m, n, A, i);
        else    i++;
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
    int n, m, A[5][3]={{1,2,3},{-1,4,5},{6,7,8},{12,13,14},{-9,10,11}};
    m=5,n=3;
    Afis(m, n, A);
    Negative(m, n, A);
    cout<<endl;
    Afis(m, n, A);

    return 0;
}
