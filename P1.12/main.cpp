#include <iostream>

using namespace std;
//P1.12. Se dau numerele z,l,a naturale Sa se determine a data tripletul (z,l,a) reprezinta o data
//       calendaristica a secolului nostru.


//Idee:  Se verifica fiecare componenta a fie in plaja de valori corecta
//       al datei curente

void Citire(string Sir, int& Z,int& L, int& A)
{   cout<<Sir<<endl;
    cout<<"da ziua:";cin>>Z;
    cout<<"da luna:";cin>>L;
    cout<<"da anul:";cin>>A;
    cout<<endl;
}

int main()
{   int z,l,a;
    Citire("data calendaristica",z,l,a);

    if(a>1999 && a<2100) cout<<" anul este corect"<<endl;
    else                 cout<<" anul nu este din secolul nostru"<<endl;
    if(l>0 && l<13)
       { cout<<" luna este corecta"<<endl;


         switch (l) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if(z>0 && z<32) cout<<" ziua este corecta"<<endl;
                     else cout<<" ziua este incorecta"<<endl;
                     break;
            case 4:
            case 6:
            case 9:
            case 11: if(z>0 && z<31) cout<<" ziua este corecta"<<endl;
                     else cout<<" ziua este incorecta"<<endl;
                     break;
            case 2:  if(a%4==0 && (z>0 && z<30))     cout<<" ziua este corecta"<<endl;
                     else if(a%4!=0 &&(z>0 && z<29)) cout<<" ziua este corecta"<<endl;
                          else cout<<" ziua este incorecta"<<endl;
                    break;
         }
    }
    else   cout<<" luna nu este buna"<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
