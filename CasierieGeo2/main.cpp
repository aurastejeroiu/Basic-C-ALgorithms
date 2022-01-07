#include <iostream>

using namespace std;

bool Bilete(int n,int& poz){
    int Cont[3]={0};                    ///contoarele pentru cele 3 bancnote
    string Banc[3]={"25","50","100"};   ///terminatiile pentru afisare
    poz=1;
    while(poz<=n){
        int cateB;                      ///numarul de bilete ce se cumpara
        cout<<"cate bilete:";
        cin >>cateB;
        int B[3]={0};                   ///cele 3 tipuri de bancnote pe care le are cumparatorul
        int i=0;
        cout<<"Da banii:\n";
        while(i<3){
            cout<<"nr bancnote de "<<Banc[i]<<":";
            cin >>B[i];
            Cont[i]+=B[i];              ///se incrementeaza contoarele aferente
            i++;
        }
        int dif=(B[0]*25+B[1]*50+B[2]*100)-cateB*25;    ///calcul restul de plata, care paote fi 0/25/50/75
        ///cout<<"\nDif="<<dif;
        if(dif<0) return false;
        else if(dif==25)                     ///daca dif==25, se verifica daca poate da rest
                {if(Cont[0]>=1) Cont[0]--;
                 else  return false;
                }
             else  if(dif==50)               ///daca dif==50, se verifica daca poate da rest 1 de 25
                    {  if(Cont[0]>=1) Cont[0]--;
                       else           return false;
                    }
                   else if (dif==75)
                            {if(Cont[1]>=1 && Cont[0]>=1) {Cont[1]--; Cont[0]--;}
                             else
                                if(Cont[0]>=3) Cont[0]-=3;
                                else return false;
                            }

        poz++;
    }
    return true;
}

bool BileteSw(int n,int& poz){
    int Cont[3]={0};                    ///contorele pentru cele 3 bancnote
    string Banc[3]={"25","50","100"};   ///terminatiile pentru afisare
    poz=1;
    while(poz<=n){
        int cateB;                      ///numarul de bilete ce se cumpara
        cout<<"cate bilete:";
        cin >>cateB;
        int B[3]={0};                   ///cele 3 tipuri de bancnote pe care le are cumparatorul
        int i=0;
        cout<<"Da banii:\n";
        while(i<3){
            cout<<"nr bancnote de "<<Banc[i]<<":";
            cin >>B[i];
            Cont[i]+=B[i];              ///se incrementeaza contoarele aferente
            i++;
        }
        cout<<"inainte de rest\n";
        cout<<"de 25:"<<Cont[0]<<" ";
        cout<<"de 50:"<<Cont[1]<<" ";
        cout<<"de 100:"<<Cont[2]<<"\n";
        int dif=(B[0]*25+B[1]*50+B[2]*100)-cateB*25;    ///calcul restul de plata, care paote fi 0/25/50/75
        ///cout<<"\nDif="<<dif;
        if(dif<0) return false;
        switch(dif){
          case  0: break;
          case 25: if(Cont[0]>=1) { Cont[0]--; break;}
                   else  return false;
          case 50: if(Cont[1]>=1) {Cont[1]--; break;}
                   else if(Cont[0]>=2) { Cont[0]-=2; break;}
                        else  return false;
          case 75: {if(Cont[1]>=1 && Cont[0]>=1) {Cont[1]--; Cont[0]--;break;}
                    else
                        if(Cont[0]>=3) {Cont[0]-=3; break;}
                        else return false;
                    }
        }
        cout<<"dupa rest\n";
        cout<<"de 25:"<<Cont[0]<<" ";
        cout<<"de 50:"<<Cont[1]<<" ";
        cout<<"de 100:"<<Cont[2]<<"\n";
        poz++;
    }
    return true;
}

int main()
{
    int n,poz;
    cout<<"Da n: ";
    cin>>n;
    if(BileteSw(n,poz))
        cout<<"DA";
    else cout<<"NU la pozitia "<<poz;

    return 0;
}
