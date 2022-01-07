#include <iostream>

using namespace std;
///solutiile sistemului ecuatiei ax+by=c cu x+y<n, a,b,c din Z si n> 0 natural

int main()
{   int a,b,c,n,Cont=0;
    cout<<"da coef a="; cin>>a;
    cout<<"da coef b="; cin>>b;
    cout<<"da coef c="; cin>>c;
    cout<<"da n=";      cin>>n;
    for(int x=0;x<=n;x++)
        for(int y=0;y<=n;y++)
          if((x+y<n) && (a*x+b*y==c))
             { Cont++;
               cout<<Cont<<"."<<"("<<x<<" "<<y<<")"<<endl;
             }
    cout << "Program terminated" << endl;
    return 0;
}
