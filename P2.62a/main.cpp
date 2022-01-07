#include <iostream>

using namespace std;
bool prim (int x)
{
    for(int i=3;i*i<=x;i++)
        if(x%i==0) return false;
        return true;
}

void rezolv(int n,int V[])
{
    int p=3,q=5,nr=0;
    while(nr<n)
    {
        if(prim(p) && prim(q) && q-p==2)
        {
            V[++nr]=p;
            V[++nr]=q;

        }
        p=q;
        q=q+2;
    }
}

void afisare(int V[],int n)
{
    for(int i=1;i<=n;i++)
        cout<<V[i]<<" ";
}
int main()
{
    int n,V[100];
    cout<<"n: ";
    cin>>n;
    rezolv(n,V);
    afisare(V,n);
    return 0;
}
