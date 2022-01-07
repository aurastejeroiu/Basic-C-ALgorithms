#include <iostream>

using namespace std;


void Afis(int n, int x[]){
    for(int i=1;i<=n;i++)
        cout<<x[i]<<' ';
    cout<<endl;
}

int main()
{   int  x[100001],st[100001],dr[100001];
    long long water = 0;
    int n,i;
    cout<<"da lungime:";
    cin >> n;
    for(i = 1; i <= n; ++ i)
        cin >> x[i];

    st[1] = x[1];
    dr[n] = x[n];
    for(i = 2; i <= n; ++ i)
        { st[i] = max(st[i-1],x[i]);
          dr[n-i+1]=max(dr[n-i+2],x[n-i+1]);
        }

    Afis(n,st);

    ///for(i = n-1; i >= 1; -- i)
    ///    dr[i] = max(dr[i+1],x[i]);

    Afis(n,dr);

    for(i = 1; i <= n; ++ i)
       water = water + min(st[i],dr[i]) - x[i];

    cout << water;


}
