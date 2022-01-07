#include <iostream>

using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }

}
int Pare (int i, int n, int X[]){  ///determina o scara care incepe la
   int j=i;                                     ///pozitia i si se termina la j
   while(j<=n && X[j]%2==0 ) j++;
   if(j>n)  return n;
            return j-1;
}

void CMLungaSecvPara(int&St, int&Dr, int n, int X[]){
    int i,j;
    i=1;
    while(i<=n){
      while(i<=n && X[i]%2==1) i++;     ///se sare peste elementele care NU sunt pare (impare)
      if(i<=n){
            j=Pare(i,n,X);              ///se determina o secventa de pare (i,j)
            if(j-i>Dr-St){              ///se retine cea mai lunga secventa
                St=i;
                Dr=j;
            }
            i=j+1;
        }

    }
}

int main()
{   int n, X[100];
    int St,Dr;
    CitireDate(n,X);
    St=1;
    Dr=0;
    CMLungaSecvPara(St,Dr,n,X);
    if(Dr>St)
         for(int i=St;i<=Dr;i++)
            cout<<X[i]<<" ";
    else cout<<" nu exista pare";
    cout << "\nProgram terminat\n";
    return 0;
}
