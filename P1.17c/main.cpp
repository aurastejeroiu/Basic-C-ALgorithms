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
{   long v[6], i,j,k,l,m,ii,jj,kk,ll,mm,nr=0;
    for (i=1;i<=9;i+=2)             ///se genreaza numerele de 5 cifre impare
     for (j=1;j<=9;j+=2)
        for (k=1;k<=9;k+=2)
            for (l=1;l<=9;l+=2)
                for (m=1;m<=9;m+=2)
                { v[1]=i, v[2]=j, v[3]=k; v[4]=l; v[5]=m;
                 long ind=1;
                 do
                {ii=1;
                 while(ind && ii<=5)
                    {jj=1;
                     while(ind && jj<=5)
                         {kk=1;
                          while(ind && kk<=5)
                            { ll=1;
                              while(ind && ll<=5)
                               { mm=1;
                                 while(ind && mm<=5)
                                 { ///if(ii!=jj && ii!=kk && ii!= ll && jj!=kk && jj!=ll && kk!=ll && ii!=mm && jj!=mm
                                   ///   &&kk!=mm && ll!=mm )
                                     { nr=v[ii]*10000+v[jj]*1000+v[kk]*100+v[ll]*10+v[mm];
                                       ind=Prim(nr);
                                       ///cout<<nr<<" "<<ind<<endl;
                                    }
                                   mm++;
                                 }
                                ll++;
                               }
                             kk++;
                            }
                          jj++;
                         }
                     ii++;
                    }
                }while(ind&& ii<=5 && jj<=5 && kk<=5 && ll<=5 && mm<=5);
         if(ind) cout<<nr<<endl;
         ///else    cout<<nr<<" nu e prim permutabil";
        }
    cout << "Program terminat" << endl;
    return 0;
}
