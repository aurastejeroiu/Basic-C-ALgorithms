#include <iostream>

using namespace std;

long prim(long k)
{   if(k<2)return 0;
    if(k%2==0 && k>2) return 0;
    long d=3;
    while(d*d<=k && k%d!=0)
        d+=2;
    if(d*d>k)return 1;
    return 0;
}

int desc2p(long x, long &p, long &q)
{
  long d=2;
  while(d*d<=x)
  { if(x==d*(x/d))
      { if(prim(d) && prim(x/d))
          {   p=d;
              q=x/d;
              return 1;
          }
      }
      if(d==2)d=3;
      else    d+=2;
  }
  return 0;
}

void consecutive(long a, long b)
{   long x=a,p1,p2,p3,p4;
    while(x<b)
    {if(desc2p(x,p1,p2) && desc2p(x+1,p3,p4))
        {   cout<<x<<"="<<p1<<"*"<<p2<<" ";
            cout<<x+1<<"="<<p3<<"*"<<p4<<endl;
        }
        x++;
    }
}

int main()
{ long a,b;
cout<<"Da valoarea lui a=";
cin>>a;
cout<<"Da valoarea lui b=";
cin>>b;
consecutive(a,b);
cout<<" Program terminat";
    return 0;
}
