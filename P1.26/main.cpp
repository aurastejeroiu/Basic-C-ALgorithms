#include <iostream>

using namespace std;

void AfisSume(long n)
{  long i,j,incep;
    for(i=1;i<=n;i++) {
        cout<<i*i*i<<"=";
        incep=i*(i-1)+1;
        for(j=0;j<i;j++)
            { if(j<i-1) cout<<incep+2*j<<"+";
              else      cout<<incep+2*j;   ///sa nu se mai afiseze + la sfarsit
            }
        cout<<endl;
    }
}

int main()
{  long n;
   cout<<"da n:";
   cin >>n;
   AfisSume(n);
   cout << "Program terminat" << endl;
   return 0;
}
