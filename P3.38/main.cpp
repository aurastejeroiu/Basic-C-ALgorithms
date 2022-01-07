#include <iostream>

using namespace std;

void Comp(int n, int F[], int G[], int GF[])
{   for(int i=1;i<=n;i++)
        GF[i]=G[F[i]];
}

bool Identitate(int n, int F[])
{   for(int i=1;i<=n;i++)
        if(F[i]!=i)
            return false;
    return true;
}

int Ordin(int n, int F[])
{
    int FG[5],i;
    for(i=1;i<=n;i++)     /// copiere F in FG
        FG[i]=F[i];
    i=0;
    while(i<=n && !Identitate(n,FG))
    {   Comp(n,FG,F,FG);
        i++;
    }
    for (int j=1;j<=n;j++) cout<<FG[j]<<" ";
    cout<<endl;
    return i;
}

int main()
{   int F[5]={0,4,1,2,3};
    int n,m,p;
    n=m=p=4;
    cout<<Ordin(n,F);
    cout<<endl;
    cout<<"Hello world!" << endl;
    return 0;
}
