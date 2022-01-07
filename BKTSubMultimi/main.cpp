#include <iostream>

using namespace std;

#define max 100

int  x[max];
int a[max];
int nsol=0;
int n;

void AfisSolutie()
{
    int i;
    cout<<"Solutia "<<++nsol<<". ";
    for(i=1; i<=n; i++)
        if(x[i]==1)  cout<<a[i]<<", ";
    cout<<endl;
}

void Citeste_Date()
{
    int i;
    n=max+1;
    while ((n>max) || (n<1))
    {
        cout<<"Dati n = ";
        cin >>n;
    }
    for (i=1; i<=n; i++)
    {
        cout<<"a["<<i<<"]=";
        cin >>a[i];
    }
}

void bkt(int k){
 int i;
 for (i=0;i<=1;i++){     ///pe fiecare componenta am valorile 0/1
     x[k]=i;
     if (k==n) AfisSolutie();
     else      bkt(k+1);
 }
}





int main()
{   Citeste_Date();
    bkt(1);
    cout << "Program terminat" << endl;
    return 0;
}
