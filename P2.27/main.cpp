#include <iostream>

using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }


}
void Scara (int i, int&j, int n, int X[]){
   j=i;
   while(j<n && X[j]<X[j+1]) j++;
}

void ToateScari(int&St, int&Fi, int n, int X[]){
    int i,j;
    i=1;
    while(i<n){
        while(i<n && X[i]>=X[i+1]) i++;
        if(i<n){
            Scara(i,j,n,X);
            if(j-i>Fi-St){
                St=i;
                Fi=j;
            }
            i=j+1;
        }
    }
}

int main()
{   int n, X[100];
    int St,Fi;
    CitireDate(n,X);
    St=1;
    Fi=0;
    ToateScari(St,Fi,n,X);
    if(Fi>St)
         for(int i=St;i<=Fi;i++)
            cout<<X[i]<<" ";
    else cout<<" nu exista scari";
    cout << "\nProgram terminat" << endl;
    return 0;
}
