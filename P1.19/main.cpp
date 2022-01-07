#include <iostream>

using namespace std;


int main()
{   long s,i,k,SMon=0;
    cout<<"da suma:";
    cin >>s;
   long a[]={0,1,3,5,10,20,50,100};

    for(i=7;i>=1;i--)
       if(s>=a[i]){k=s/a[i];
                   SMon+=k;
                   s=s%a[i];
                   cout<<k<<'x'<<a[i]<<'\n'; ///afisare nr de monede de tipul a[i]
                  }
    cout<<endl<<SMon<<" monezi in total"<<endl;
    return 0;
}
