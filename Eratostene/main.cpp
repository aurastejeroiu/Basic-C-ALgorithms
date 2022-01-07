#include <iostream>

using namespace std;

void Eratos1(long n, long P[]){
  for(long i=2;i*i<=n;i++){
        for(long k=2*i;k<=n;k+=i)
            P[k]=1;
    }
}

void Eratos2(long n, long P[]){
  for(long i=2;i*i<=n;i++){
        for(long k=2*i;k<=n;k+=i)
            P[k]=0;
    }
}

void InitP1(long n, long P[]){
  for(int i =0;i<=n;i++)
    P[i]=0;
}

void InitP2(long n, long P[]){
  for(int i =0;i<=n;i++)
    P[i]=i;
}


void AfisP1(long n, long P[]){
    for(long i=2;i<=n;i++)
      if(P[i]==0) cout<<i<<" ";

}
void AfisP2(long n, long P[]){
    for(long i=2;i<=n;i++)
      if(P[i]) cout<<i<<" ";

}
int main()                      /// 2 variante de Eratostene
{   long P[10000];
    long n=100;

    InitP1(n,P);
    Eratos1(n,P);
    AfisP1(n,P);
    cout<<endl;

    InitP2(n,P);
    Eratos2(n,P);
    AfisP2(n,P);



    cout << "Hello world!" << endl;
    return 0;
}
