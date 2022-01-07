#include <iostream>
#include <iomanip>
using namespace std;

void PozMin(int m, int n, int A[20][3], int& lin, int& col){
    lin=-1, col=-1;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            {if(A[i][j]>=0 && lin==-1)
                 {lin=i;
                  col=j;
                 }
             else
                 if(A[i][j]>=0 && A[i][j]<A[lin][col] )
                     {lin=i;
                      col=j;
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
{
    int m,n, A[5][3]={{-1,-2,30},{-1,-4,-5},{-6,-7,8},{-12,-13,-14},{-9,-10,-11}};
    int V[3];
    m=5,n=3;
    Afis(m, n, A);
    int lin,col;
    PozMin(m,n,A,lin,col);
    if(lin==-1)
        cout<<"Nu exista elemente pozitive in matrice"<<endl;
    else
        cout<<"Elementul pozitiv cel mai mic se afla pe linia "<<lin+1<<" si coloana "<<col+1<<endl;
    cout<<endl;
    //AfisVect(m, n, A);
    cout<<endl;
    return 0;
}
