#include <iostream>

using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }

}
void Schimba (int &a, int &b){ ///schimba a cu b
   int c=a;
       a=b;
       b=c;
}

void DeterminaPerm (int n, int X[], int P[]){
    for(int i=1; i<=n;i++) P[i]=i;      ///initializare P
    for (int i=1; i<n;i++)              ///simulare sortare X cu schimbari in P
      for (int j=i+1;j<=n;j++)
        if(X[P[i]]>X[P[j]])  Schimba(P[i],P[j]);

}

int main()
{   int n, X[100], P[100];
    CitireDate(n,X);
    DeterminaPerm(n, X, P);
    cout<<"sirul initial:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<X[i]<<" ";
    cout<<endl<<"sirul sortat crescator:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<X[P[i]]<<" ";
    cout << "\nProgram terminat" << endl;
    return 0;
}
