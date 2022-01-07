#include <iostream>

using namespace std;


void Citire(int &m){
    cout<<"cati termeni:";
    cin >>m;
}

void CreFibo(int m, long n[]){
    n[0]=n[1]=1;
    for(int i=2;i<m; i++)
        n[i]=n[i-2]+n[i-1];
}

void AfisFibo(int m, long n[]){
   cout<<"primele "<<m<<" numere fibonaci:"<<endl;
   for(int i=0; i<m; cout <<n[i]<<" " ,i++);
}
int main()
{   int m;
    long n[100];
    Citire(m);
    CreFibo(m,n);
    AfisFibo(m,n);
    cout << "\nProgram terminat" << endl;
    return 0;
}
