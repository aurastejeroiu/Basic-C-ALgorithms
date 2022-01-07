#include <iostream>

using namespace std;
int Prim(long n)
{
    long d=2;
    if(n<2) return 0;
    while(d*d<=n && n%d!=0)
        if(d==2)d=3;
        else d+=2;
    if(d*d>n) return 1;
    return 0;
}

int main()
{
    int n,x[100],i,j,k;
    cout<<"da n:"; cin>>n;
    x[1]=1;
    i=2;
    k=2;
    while(i<=n)
    {
        if(Prim(k))
        {
            j=1;
            while(i<=n && j<=k)
                {
                    x[i]=j;
                    i++;
                    j++;
                }
        }
        else
            {
                j=1;
                while(i<=n && j<=k)
                    {
                        x[i]=k;
                        i++;
                        j++;
                    }
            }
            k++;
    }


    for(i=1;i<=n;i++)
        cout<<x[i]<<" ";


    return 0;
}
