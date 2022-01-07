#include <iostream>

using namespace std;
// un polinon se poate scrie ca mai jos:
// P(x)=a[0]x^n+a[1]*x^(n-1)+...+a[n-1]*x+a[n]=(...((a[0]*x+a[1])*x+a[2])*x+...)*x+a[n]
// de aici si rezolvarea iterativa cat si recursiva e usoara


int ValPolRec(int n, int a[], int y){
    if(n==0) return a[0];
    else     return ValPolRec(n-1,a,y)*y + a[n];
}

int ValPolIter(int n, int a[], int y){
    int Val=0;
    for(int i=0;i<=n;i++)
       Val=Val*y+a[i];
    return Val;
}

int main()
{   int    a[]={1,3,3,1};
    cout   <<ValPolRec (3,a,-1)<<endl;
    cout   <<ValPolIter(3,a,-1)<<endl;
    cout   <<"Terminat    "    << endl;
    return 0;
}
