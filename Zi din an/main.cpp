#include <iostream>
using namespace std;

long data(long z, long l, long a)
{   long i=1, d=0;
    while(i<l)
        {if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))
            d=d+31;
         if((i==4)||(i==6)||(i==9)||(i==11))
            d=d+30;
         if(i==2)
            {if(a%4==0)
                 d=d+29;
             else
                 d=d+28;
            }
         i++;
        }
    d=d+z;
    return d;
}
int main()
{   long z, l, a;
    cout<<"Dati ziua din an:";
    cin>>z;
    cout<<"Dati luna din an:";
    cin>>l;
    cout<<"Dati anul:";
    cin>>a;
    cout<<z<<"/"<<l<<"/"<<a<<endl;
    cout<<"Data respectiva din an este a "<<data(z, l, a)<<"-a zi din an"<<endl;
    return 0;
}
