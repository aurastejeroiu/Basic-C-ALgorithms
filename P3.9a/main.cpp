#include <iostream>
#include <conio.h>

using namespace std;

void Produs(int m, int P[], int n, int Q[], int &r, int R[]){
    r=m+n;
    for(int i=0;i<=r;i++) R[i]=0; /// initializare
    for(int i=0;i<=m;i++)
      for(int j=0;j<=n;j++)
        R[i+j]+=P[i]*Q[j];
}

void Suma(int m, int P[], int n, int Q[], int &s, int S[]){
   s=(m>= n ? m : n);
   int Min=(m<=n?m:n);

   for(int i=0;i<=Min;i++)
     S[i]=P[i]+Q[i];

   for(int i=Min+1;i<=m;i++)        ///numai unul din cele 2 cicluri care urmeaza se executa
     S[i]=P[i];
   for(int i=Min+1;i<=n;i++)        ///numai unul din cele 2 cicluri care urmeaza se executa
     S[i]=Q[i];
}

void Scalar(int a, int m, int P[], int &r, int R[] ){
   for(int i=0;i<=m; i++)
     R[i]=a*P[i];
   r=m;
}

void AfisPol(int g, int G[100]){
    cout<<endl;
    cout<<G[0];
    for(int i=1;i<=g;i++)
        cout<<"+"<<G[i]<<"X^"<<i;
    cout<<endl;

}
void Copie(int m, int A[],int &n, int B[]){ ///copiere B=A
    n=m;
    for(int i=0;i<=n;i++)
        B[i]=A[i];
}

int main()
{   int m,n,r,a,pq;                         ///m,n,r,a,pq gradele
    m=2;n=2;                                ///trebuie citire polinoame
    int P[100],Q[100],R[100],PQ[100],A[100];
    Q[0]=1;Q[1]=1;Q[2]=1;
    P[0]=1;P[1]=1;P[2]=1;
    PQ[0]=P[0];
    pq=0;
    for(int i=1;i<=m;i++){
        Copie(n,Q,a,A);         ///A=Q
        Copie(n,Q,r,R);         ///R=Q
        for (int j=1;j<=i-1;j++){
            Produs(a,A,n,Q,r,R);
            Copie(r,R,a,A);     ///A=R
        }
        Scalar(P[i],r,R,r,R);   ///R=P[i]*R[i]
        Suma(pq,PQ,r,R,pq,PQ);  ///PO=R+PQ
     }
    cout<<endl;
    AfisPol(pq,PQ);
    cout << "Hello world!" << endl;
    return 0;
}

