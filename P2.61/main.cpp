#include <iostream>

using namespace std;

int main()
{
    int n,x[100],i,j,k;
    cout<<"da n:"; cin>>n;
    x[1]=1;
    i=2;
    k=2;
    while(i<=n)
    {
        j=1;
        while(i<=n && j<=k){
                x[i]=j;
                i++;
                j++;
            }
        k++;
    }

    for(i=1;i<=n;i++)
        cout<<x[i]<<" ";


    return 0;
}
