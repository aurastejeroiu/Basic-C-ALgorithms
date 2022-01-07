#include <iostream>
#include <iomanip>

using namespace std;
int Prim(long n)
{
    long d=2;
    if(n<2) return 0;
    while(d*d<=n && n%d!=0)
        if(d==2)d=3;
        else d+=2;
    if(d*d>n) return 1;
    return 0;
}

int main()
{   int a[20][20];
    int lin=1,col=1;
    int n,i,j,k;            //k ne da sirul numerelor naturale
    cout<<"da n:"; cin>>n;  //i ne da numarul de elemente din X
    i=1;
    k=4;
    while(i<=n*n)           //in matrice avem n*n elemente
    {  if(!Prim(k))         //doar numerele compuse
        {   i++;
            a[lin][col]=k;  //la adaugare in matrice se verifca daca se trece la linia urmatoare
            col++;
            if(col>n)
                       { lin++;
                         col=1;
                       }

            j=2;
            while(i<=n*n && j<=k/2)
                { if(k%j==0)
                   { int jj=0;
                     while(i<=n*n && jj<j ) //divizorul j se pune in matrice de j ori
                     { a[lin][col]=j;       //la adaugare in matrice se verifca daca se trece la linia urmatoare
                       col++;
                       if(col>n)
                        { lin++;
                          col=1;
                        }
                       i++;
                       jj++;                //jj contorizeaza numarul de divizori
                     }
                   }
                  j++;                      //trecrea la urmatorul divizor(eventual)
                }
        }
       k++;
    }


    for(lin=1;lin<=n;lin++)
    { for(col=1;col<=n;col++)
        cout<<setw(3)<<a[lin][col];
      cout<<endl;
    }
    return 0;
}

