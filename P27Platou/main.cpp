#include <iostream>

using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }


}
void Platou (int i, int&j, int n, int X[]){ ///determina un platou care incepe la
   j=i;                                     ///pozitia i si se termina la j
   while(j<n && X[j]==X[j+1]) j++;
}

void CMLungPlatou(int&St, int&Fi, int n, int X[]){
    int i,j;
    i=1;
    while(i<n){
        while(i<n && X[i]!=X[i+1]) i++; /// se sare peste elementele care nu formeaza platou
        
	if(i<n){
            Platou(i,j,n,X);    ///se determina un platou (i,j)
            if(j-i>Fi-St){      ///se retine platoul cel mai lung
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
    Fi=1;
    CMLungPlatou(St,Fi,n,X);
    if(Fi>St)
         for(int i=St;i<=Fi;i++)
            cout<<X[i]<<" ";
    else cout<<" nu exista platouri";
    cout << "\nProgram terminat" << endl;
    return 0;
}
