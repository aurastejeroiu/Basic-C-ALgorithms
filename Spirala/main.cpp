#include <iostream>
#include <iomanip>

using namespace std;
void Spirala(int n, int a[10][10])
{
    int i,j,k=0;
    for(i=1;i<=n/2+1;i++)	///i cicluri (i spirale)
    { for(j=i;j<=n-i+1;j++)   	///pe oriz la dreapta
            a[i][j]=++k;
      for(j=i+1;j<=n-i+1;j++) 	/// pe verticala in jos
            a[j][n-i+1]=++k;
      for(j=n-i;j>=i;j--)
            a[n-i+1][j]=++k; 	///pe oriz. la stanga
      for(j=n-i;j>=i+1;j--)
            a[j][i]=++k;     	///pe vert. in sus
    }
}


int main()
{
    int n,a[10][10];
    cout<<"da n: ";
    cin>>n;
    Spirala(n,a);
    for(int i=1;i<=n;i++)
        { for(int j=1;j<=n;j++)
                cout<<setw(3)<<a[i][j];
            cout<<endl;
        }
    cout << "Hello world!" << endl;
    return 0;
}
