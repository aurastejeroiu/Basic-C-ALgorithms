#include <iostream>

using namespace std;

int verificare(int x,int y)
{   int cx=1, cy=1,aux,auy,ox,oy;

    for(int i=0;i<=9;i++)
    {
        aux=x;                                       ///auxiliare
        auy=y;
        ox=0;                                        ///presetare - verificare
        oy=0;

        while(aux && auy)
        {
            if(aux%10==i)                          ///verificarea ultimei cifre din x daca este egala cu i
                ox=1;
            if(auy%10==i)                         ///verificare ultimei cifre din y daca este egala cu i
                oy=1;
            aux=aux/10;                            ///elimiarea ultimei cifre
            auy=auy/10;
        }
        if(ox!=oy)                                  ///verifica daca cifra este prezenta in ambele numere
            return 0;
    }
        return 1;                                    ///returneaza 1 daca programul ajunge la sfarsit
}

int main()
{   if(verificare(123,3121))cout <<"sunt asemenea"<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
