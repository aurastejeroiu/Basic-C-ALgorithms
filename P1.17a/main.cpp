#include <iostream>
#include <iomanip>

using namespace std;
long Prim(long i){   ///returneaza 1 daca i e prim
  long j;            ///si         0  daca i e compus
  if (i<2)     return 0;
  j=2;
  while ((j*j<=i) && ((i % j)!=0))
    if (j==2)  j=3;
    else j+=2;
  if (j*j>i) return 1;
             return 0;
}
int main()
{   int v[4], i,j,k,ii,jj,kk,nr=0;
    for (i=1;i<=9;i+=2)         ///se genereaza toate nr cu 3 cifre impare
     for (j=1;j<=9;j+=2)
        for (k=1;k<=9;k+=2)
        {   v[1]=i, v[2]=j, v[3]=k;
            int ind=1;
            do
                {ii=1;
                 while(ind && ii<=3)
                    {jj=1;
                     while(ind && jj<=3)
                         {kk=1;
                          while(ind && kk<=3)
                            { if(ii!=jj && ii!=kk && jj!=kk ){
                                 nr=v[ii]*100+v[jj]*10+v[kk];
                                 ind=Prim(nr);
                                 ///cout<<nr<<" "<<ind<<endl;
                               }
                             kk++;
                            }
                          jj++;
                         }
                     ii++;
                    }
                }while(ind&& ii<=3 && jj<=3 && kk<=3);
         if(ind) cout<<nr<<endl;
         ///else    cout<<nr<<" nu e prim permutabil"<<endl;
        }
    cout << "Program terminat" << endl;
    return 0;
}
