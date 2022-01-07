#include <iostream>
using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }
}
void Scara (int i, int& j, int n, int X[]){  ///determina o scara care incepe la
   j=i;                                      ///pozitia i si se termina la j
   while(j<n && X[j]<X[j+1]) j++;
}
void CMLungaScara(int& St, int& Dr, int n, int X[]){
    int i,j;
    St=0;
    Dr=0;
    i=1;
    while(i<n){
      while(i<n && X[i]>=X[i+1]) i++;   ///se sare peste elementele care NU formeaza o scara

      if(i<n){                          ///acum incepe o scara
            Scara(i,j,n,X);             ///se determina o scara (i,j), de fapt j se determina
            if(j-i>Dr-St){              ///se retine scara cea mai lunga
                St=i;
                Dr=j;
            }
            i=j+1;			///se trece la poz. j+1
        }
    }
}

int  main()
{   int n, X[100];
    int St,Dr;
    CitireDate(n,X);

    CMLungaScara(St,Dr,n,X);

    if(Dr>St)
         {  cout<<"\nscara de lungime maxima:";
             for(int i=St;i<=Dr;i++) cout<<X[i]<<" ";
            cout<<endl;
         }
    else cout<<" nu exista scari";
    cout << "\nProgram terminat" << endl;
    return 0;
}
