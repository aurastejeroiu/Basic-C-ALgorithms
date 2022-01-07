#include <iostream>

using namespace std;


int Exista(int n, int X[], int val){
    for(int i=1;i<=n;i++)
        if(val==X[i])  return 1;
    return 0;

}

void A(int n, int X[], int m, int Y[], int &k, int Z[]){
    k=0;
    for (int i=1;i<=n;i++)
        if(Exista(m,Y,X[i])) Z[++k]=X[i];

}

void B(int n, int X[], int m, int Y[], int &k, int Z[]){
    k=0;
    for(int i=1;i<=n;i++)
        Z[++k]=X[i];

    for (int i=1;i<=m;i++)
        if(!Exista(m,X,Y[i])) Z[++k]=Y[i];

}
void C(int n, int X[], int m, int Y[], int &k, int Z[]){
    k=0;
    for (int i=1;i<=n;i++)
        if(!Exista(m,Y,X[i])) Z[++k]=X[i];

}


int main()
{   int X[6]={0,3,1,7,5,2};
    int Y[5]={0,3,70,5,111};
    int n=5,m=4;
    int k;
    int Z[10];
    A(n,X,m,Y,k,Z);
    for(int i=1;i<=k;i++)
        cout<<Z[i]<<' ';
    cout<<endl;

    B(n,X,m,Y,k,Z);
    for(int i=1;i<=k;i++)
        cout<<Z[i]<<' ';
    cout<<endl;
    C(n,X,m,Y,k,Z);
    for(int i=1;i<=k;i++)
        cout<<Z[i]<<' ';
    cout<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
