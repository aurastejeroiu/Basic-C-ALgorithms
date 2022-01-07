#include <iostream>

using namespace std;

void ParaLunga(int n, int V[], int &a, int &b)
{   a=0;
    b=0;
    for(int i=1;i<=n;i++)
        if(V[i]%2==0)
            {int j=i+1;
             while(j<=n && V[j]%2==0) j++;
             j--;
             if(j-i>b-a)
                 {a=i;
                  b=j;
                 }
             i=j;
            }
}

int main()
{   int n=12, V[]={0, 2, 4, 12, 30, 6, 8, 33, 44, 100, 36, 78, 17}, a, b;
    ParaLunga(n, V, a, b);
    for(int i=a;i<=b;i++)
        cout<<V[i]<<" ";
    return 0;
}
