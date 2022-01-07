#include <iostream>

using namespace std;

bool Bilete(int n, int &p)
{   int C25, C50, C100;
    C25=C50=C100=0;
    while(p<=n)
        {int banc;
         cout<<"Da banii:";
         cin>>banc;
         if(banc==25)
            C25++;
         else
            if(banc==50)
                {if(C25>=1) {C25--;
                             C50++;
                             }
                 else return false;
                }
            else
                {C100++;
                 if(C25>=1&&C50>=1)
                    {C25--;
                     C50--;
                    }
                 else if(C25>=3) C25-=3;
                    else return false;
                }
         p++;
        }
    cout<<"Suma obtinuta="<<25*C25+50*C50+100*C100<<endl;
    return true;
}
int main()
{   int n;
    cout<<"Cate persoane:";
    cin>>n;
    int p=1;
    if(Bilete(n, p)) cout<<"DA";
    else             cout<<"NU"<<" la clientul:"<<p;
    return 0;
}
