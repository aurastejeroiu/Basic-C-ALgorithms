#include <iostream>

using namespace std;

void Citire(int&n,int X[], int&a, int &b){
    cout<<"cate numere dai:";
    cin >>n;                    ///citeste dimensiunea sirului
    for (int i=1;i<=n;i++)      ///citeste elementele sirului
    { cout<<"X["<<i<<"]=";
      cin >>X[i];
    }
    cout << "da capatul stang a:";
    cin  >> a;
    cout << "da capatul drept b:";
    cin  >> b;

}
double Media(int n,int X[], int a, int b){
    double m=0.0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    if(X[i]>=a && X[i]<=b) {
        m+=X[i];
        cnt++;
    }
    if(cnt==0) return 0.0;
               return (m/cnt);

}


void Afisare(int n, int X[],int a, int b){
    cout<<endl;
      for(int i=1; i<=n;i++)
         if(X[i]<a || X[i]>b) cout<<"("<<i<<","<<X[i]<<") ";
    cout<<endl;
}

int main()
{   int X[100];
    int n,a,b;
    double m;
    Citire      (n,X,a,b);
    if(m=Media  (n,X,a,b)) cout <<"media este:"<<m;
    else                   cout <<"nu exista numere intre "<<a<<" si "<<b;
    Afisare     (n,X,a,b);
    return 0;
}

