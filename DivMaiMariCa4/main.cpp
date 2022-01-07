#include <iostream>

using namespace std;


long Div5Si(long n){
     long S=2;
     long d=2;
     for(d=2;d*d<n;d++)
        if(n%d==0) S+=2;
     if(d*d==n) S++;
     return S;

}

void NrDiv5Si(long n){
    long Div[10000];
    long contor=0;
    for(long i=1;i<=n;i++)
       if(Div5Si(i)>4) Div[++contor]=i;
    for(int i=1;i<=contor;i++)
        cout<<i<<":"<<Div[i]<<"\n";
}


int main()
{   long n;
    cout<<"da n:";
    cin >>n;
    NrDiv5Si(n);
    cout << "Hello world!" << endl;
    return 0;
}
