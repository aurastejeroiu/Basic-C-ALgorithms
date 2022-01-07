#include <iostream>

using namespace std;
int numar_inv(int n,int F[])
{
    int contor=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)     /// contorizam nr de inv prin verificarea
        if(F[j]<F[i])               /// conditiei F[i]>F[j]
        contor++;
    return contor;
}
int main()
{
    int n,F[1000];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>F[i];
    cout<<numar_inv(n,F);
    return 0;
}
