#include <iostream>
#include <iomanip>
using namespace std;

void afis(int m, int n, int a[][10]){
   cout<<endl<<"afisare normala:\n";
   for(int i=1; i<=m; i++){
      for(int j=1; j<=n;j++)
        cout<<setw(4)<<a[i][j];
      cout<<endl;
   }
}

void afisR(int m, int n, int n2, int A[][10]){
   if(m>0)
     if(n>0){
        afisR(m,n-1,n2,A);
        cout<<setw(4)<<A[m][n];
     }
     else {afisR(m-1,n2,n2,A);
           cout<<endl;
          }
}

void citR(int m, int n, int n2, int A[][10]){
   if(m>0)
     if(n>0){
        citR(m,n-1,n2,A);
        cout<<"A["<<m<<"]["<<n<<"]=";
        cin >> A[m][n];
     }
     else citR(m-1,n2,n2,A);
}


int main()
{   int m,n;
    int A[10][10];
    cout<<"da nr de linii:"; cin>>m;
    cout<<"da nr. de coloane:"; cin>>n;
    citR(m,n,n,A);
    afis(m,n,A);
    cout<<endl<<"afisare recursiva:\n";
    afisR(m,n,n,A);
    cout << "\nHello world!" << endl;
    return 0;
}




