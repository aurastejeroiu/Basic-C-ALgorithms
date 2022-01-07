#include <iostream>
#include <math.h>

using namespace std;
/* Enunt:...

*/
int Prim(long n, long d) //d=2 la apelul primar
{ if(n<2)    return 0;
  if(d*d>n)  return 1;
  if(n%d==0) return 0;
  else       return Prim(n,d+1);
}

long CMMDC(long x, long y)
{  while(x!=y)
    { if(x>y) x=x-y;
       else    y=y-x;
    }
   return x;
}

void RezolvEc2(long d, float p)
{float Delta=d*d-4*p;
 cout<<"Delta="<<Delta<<endl;
 if(Delta>0)
   { cout<<"x1="<<(-d-sqrt(Delta))/2<<endl;
     cout<<"x2="<<(-d+sqrt(Delta))/2<<endl;
   }
 else
    if(Delta==0.0)
       cout<<"x1=x2="<<-(float)d/2<<endl;
    else cout<<"radacini complexe conjugate"<<endl;
}


int main()
{   long a,b,c,D,k;
    float P;
    cout<<"da a:"; cin>>a;
    cout<<"da b:"; cin>>b;
    cout<<"da c:"; cin>>c;
    D=CMMDC(a,b);
    k=0;
    for(long i=2;i<=c;i++)
        if(Prim(i,2)) k++;
    P=(float)k/c;
    cout<<"D="<<D<<" P="<<P<<endl;
    RezolvEc2(D,P);
    cout << "\nProgram terminat!" << endl;
    return 0;
}
