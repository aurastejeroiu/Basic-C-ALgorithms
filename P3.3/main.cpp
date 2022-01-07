#include <iostream>

using namespace std;

void Derivata(int n, int P[], int &m, int PP[])
{  int i;
   for(i=0;i<=n;i++)
        PP[i]=(n-i)*P[i];
   m=n-1;
}
int main()
{   int P[100],PP[100];
    int n,m;
    cout<<"gradul:";
    cin >>n;
    for (int i=0;i<=n;i++)
    { cout<<"coef["<<i<<"]=";
      cin >>P[i];
    }

    Derivata(n,P,m,PP);

    for(int i=0; i<=m;i++)
        cout<<PP[i]<<" ";
    cout<<endl;
    return 0;
}
