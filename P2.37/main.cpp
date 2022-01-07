#include <iostream>

using namespace std;

void Citeste (int &n, int X[]){
    cout<<"Da n:";
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>X[i];
}

void Elimin (int poz, int &n, int X[]) {
    for(int i=poz;i<n;i++)
        X[i]=X[i+1];
    n--;
}

void P2_37 (int a, int b, int &n, int X[]){
    int Min, Max;
                                ///initializarea lui Min si Max cu primul x[i]<=b
    int i=1;
    while(i<=n && X[i]>b) i++;
    if(i>n) cout<<" sirul nu are numere <=b ";
    else{
         Min=Max=X[i];             /// s-a gasit x[i]<=b
         for(int j=i;j<=n;j++){
            if(X[j]<=b) {
                 if(X[j]<Min) Min=X[j];
                 if(X[j]>Max) Max=X[j];
            }
         }
        cout<<"Min= "<<Min<<endl;
        cout<<"Max= "<<Max<<endl;
    }
    i=1;
    while(i<=n){
        if(X[i]<a||X[i]>b) Elimin(i, n, X);
        else i++;
    }


}

void Afis (int n, int X[])
{   if(n==0) cout<<"sirul a devenit vid";
    else
      for(int i=1;i<=n;i++)
          cout<<X[i]<<" ";

}
int main()
{
    int a, b, n, X[100];
    cout<<"a= "; cin>>a;
    cout<<"b= "; cin>>b;
    Citeste(n, X);
    P2_37(a, b, n, X);
    Afis (n, X);

    return 0;
}
