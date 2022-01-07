#include <iostream>

using namespace std;

void Produs(int m, int P[], int n, int Q[], int &r, int R[]){
    r=m+n;
    for(int i=0;i<=r;i++) R[i]=0; /// initializare
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
          R[i+j]+=P[i]*Q[j];
}

void AfisPol(int g, int G[100]){
    cout<<endl;
    cout<<G[0];
    for(int i=1;i<=g;i++)
        cout<<"+"<<G[i]<<"X^"<<i;
    cout<<endl;

}

int main()
{   int m,n,r;
    m=1;n=1;
    int P[100],Q[100],R[100];
    P[0]=1;P[1]=1;
    Q[0]=1;Q[1]=1;
    AfisPol(m,P);
    for(int i=2;i<=12;i++){
        Produs(m,P,n,Q,r,R);
        AfisPol(r,R);
                    /// copiere Q=R;
        for(int j=0;j<=r;j++)
             Q[j]=R[j];
        n=r;

    }
    Produs(m,P,n,Q,r,R);

    cout << "Hello world!" << endl;
    return 0;
}
