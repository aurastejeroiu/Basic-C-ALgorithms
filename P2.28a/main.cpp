#include <iostream>

using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }

}

void Schimb(int &a, int &b){
    int aux=a;
          a=b;
          b=aux;
}

void DeterminaPerm (int n, int X[], int P[]){
  for(int i=1;i<=n;i++) P[i]=i; //init vect. poziti cu i

  for(int i=1;i<n;i++)
   for (int j=i+1; j<=n;j++)
     if(X[P[i]] < X[P[j]]) Schimb(P[i],P[j]);
}


int main()
{   int n, X[100], P[100];
    CitireDate(n,X);
    DeterminaPerm(n, X, P);
    cout<<"sirul initial:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<X[i]<<" ";

    cout<<"\nvectorul indicilor:";
    for(int i=1;i<=n;i++)
        cout<<P[i]<<" ";

    cout<<endl<<"\nsirul sortat descrescator:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<X[P[i]]<<" ";

    cout << "\nProgram terminat" << endl;
    return 0;
}
