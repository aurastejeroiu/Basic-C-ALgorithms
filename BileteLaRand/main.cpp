#include <iostream>

using namespace std;

bool rand(int n)
{
    int c25,c50,v;
    c25=c50=0;

    for(int i=1;i<=n;i++)
    {
        cin>>v;
        if(v==25) c25++;
        else  if(v==50)
               { c25--;
                c50++;
               }
             else
               {
                 if(c50>0 && c25>0)
                  { c25--;
                    c50--;
                  }
                else
                { if(c25>=3)c25-=3;
                  else return false;
                }
              }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    if(rand(n)) cout<<"Au fost serviti toti";
    else cout<<"NU";
    return 0;
}
