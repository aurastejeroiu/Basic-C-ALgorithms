#include <iostream>
using namespace std;
void CitireDate(int&n, int X[]){
   cout<<"cate dai:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }
}
int PozMax (int n, int Y[]){ 		///determina pozitia maximului
   int PozM=1;
   for(int i=2; i<=n;i++)
      if(Y[i]>Y[PozM]) PozM=i;
   return PozM;
}
void DeterminaPerm (int n, int X[], int P[]){
    int Y[100];
    for(int i=1;i<=n;i++) Y[i]=X[i];	///se copiaza X in Y

    int Min=X[1];			            ///se determina minimum
    for(int i=2;i<=n;i++)
        if(X[i]<Min) Min=X[i];

    for(int i=1;i<=n;i++){              ///determ lui permutarii P
        int PM=PozMax(n,Y);
        P[i]  =PM;
        Y[PM] =Min-1;                   ///Y de pozitia maxima(PM) se pune pe Min-1
    }
}

int main()
{   int n, X[100], P[100];
    CitireDate   (n,X);
    DeterminaPerm(n, X, P);

    cout<<"\nvectorul indicilor:";
    for(int i=1;i<=n;i++)
        cout<<P[i]<<" ";

    cout<<endl<<"\nsirul sortat descrescator:"<<endl;

    for(int i=1;i<=n;i++)
        cout<<X[P[i]]<<" ";
    cout << "\nProgram terminat" << endl;
    return 0;
}
