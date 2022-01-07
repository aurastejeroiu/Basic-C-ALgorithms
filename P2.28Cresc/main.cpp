#include <iostream>

using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }

}
int PozMin (int n, int Y[]){ ///determina pozitia maximului
   int PozM=1;
   for(int i=2; i<=n;i++)
      if(Y[i]<Y[PozM]) PozM=i;
   return PozM;
}

void DeterminaPerm (int n, int X[], int P[]){
    int Y[100];
    for(int i=1;i<=n;i++) Y[i]=X[i];	    ///se copiaza X in Y

    int Max=X[1];                           ///se deterimina maximum
    for(int i=2;i<=n;i++)
        if(X[i]>Max) Max=X[i];

    for(int i=1;i<=n;i++){                  ///determ lui P
        int PM=PozMin(n,Y);
        P[i]  =PM;
        Y[PM] =Max+1;                       ///Y de pozitia minima(PM) se pune pe Max+1
    }

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
