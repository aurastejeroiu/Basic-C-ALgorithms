#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{

    int x[100],n,vol=0,maxp1,maxp2,poz;

    cin>>n;

    for(int i=1; i<=n; i++)

    {
        cin>>x[i];
    }


    int i=1;

    while(x[i]==0)
    {
        i++;
    }

    maxp1=x[i];

    i++;

    while(i<=n/2)
    {
        if(x[i]<=maxp1)
        {
            vol+=maxp1-x[i];
        }
        else
        {
            maxp1=x[i];
        }
        i++;
    }

    i=n;

    while(x[i]==0)
    {
        i--;
    }

    maxp2=x[i];
    poz=i;

    while(i>n/2)
    {
        if(x[i]<=maxp2)
        {
            vol+=maxp2-x[i];
        }
        else
        {
            maxp2=x[i];
            poz=i;
        }
        i--;
    }

    vol-=abs(maxp1-maxp2)*(poz-n/2-1);
    cout<<vol;


    return 0;
}
