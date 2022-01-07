#include <iostream>

using namespace std;


bool Plata(int n, int& p){
    int B,dif;              ///b=bancnota cu care se plateste
    int c[4]={0};           ///c[0]=cate de 25, c[1]=cate de 50, c[2]=0, c[3]=cate de 100
    p=1;
    while (p<=n){
        cout<<"da banconota:";
        cin >>B;
        c[B/25-1]++;          ///se adauga la contorul de bancnote
        dif=B-25;
        switch(dif){
           case  0: break;
           case 25: if(c[0]>0)
                       { c[0]--;
                         break;
                       }
                    else return false;
           case 75: if(c[1]>0 && c[0]>0)
                       { c[1]--;
                         c[0]--;
                         break;
                       }
                    else
                        if(c[0]>2)
                            { c[0]-=3;
                              break;
                            }
                         else return false;
        }
        p++;
    }
    return true;
}


int main()
{   int n,p;
    cout<<"cati cumparatori:";
    cin >>n;
    if(Plata(n,p)) cout<<"DA, s-au vandut "<<n<<" bilete in valoare de "<<n*25<<" lei";
    else         cout<<"NU la pozitia "<<p;
    cout << "\n program terminat" << endl;
    return 0;
}
