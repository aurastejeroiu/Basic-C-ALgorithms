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
{   int v[5], i,j,k,l,ii,jj,kk,ll,nr=0;
    for (i=1;i<=9;i+=2)             ///se genreaza numerele de 4 cifre impare
     for (j=1;j<=9;j+=2)
        for (k=1;k<=9;k+=2)
            for (l=1;l<=9;l+=2)
           {
            v[1]=i, v[2]=j, v[3]=k; v[4]=l;
            int ind=1;
            do
                {ii=1;
                 while(ind && ii<=4)
                    {jj=1;
                     while(ind && jj<=4)
                         {kk=1;
                          while(ind && kk<=4)
                            { ll=1;
                              while(ind && ll<=4)
                                 { if(ii!=jj && ii!=kk && ii!= ll && jj!=kk && jj!=ll && kk!=ll )
                                     { nr=v[ii]*1000+v[jj]*100+v[kk]*10+v[ll];
                                       ind=Prim(nr);
                                       ///cout<<nr<<" "<<ind<<endl;
                                    }
                                  ll++;
                                 }
                             kk++;
                            }
                          jj++;
                         }
                     ii++;
                    }
                }while(ind&& ii<=4 && jj<=4 && kk<=4 && ll<=4);
         if(ind) cout<<nr<<endl;
         ///else    cout<<nr<<" nu e prim permutabil";
        }
    cout << "Program terminat" << endl;
    return 0;
}
