#include <iostream>
using namespace std;

void Monezi(long S, int NrMon[])
{ int Val[]={1,3,5,10,20,50,100};
  int n=6;
  while(n>=0)
  {  NrMon[n]=S/Val[n];
     S       =S-S/Val[n]*Val[n];
     n--;
  }

}

int AfisMeniu(){
    int Op;
    cout<<"\n------------------\n";
    cout<<"1.Introducere Suma\n";
    cout<<"2.Determinare Monezi\n";
    cout<<"0.Terminare program\n";
    cout<<"Optiunea ta(1,2,0):";
    cin >>Op;
    return Op;
}

int main()
{ int NrMon[7];
  int Val[]={1,3,5,10,20,50,100};
  long S;
  int Opt;
  Opt=AfisMeniu();
  while(Opt!=0){
    switch(Opt){
      case 1: { cout<<"da suma:";
                cin >>S;
                break;
              }
      case 2: { Monezi(S,NrMon);
                cout<<"Suma "<<S<<"=";
                for(int i=0;i<6;i++)
                    if(NrMon[i]) cout<<NrMon[i]<<"*"<<Val[i]<<"+";
                if(NrMon[6]) cout<<NrMon[6]<<"*"<<Val[6]<<endl;
                break;
             }
      default: {cout<<"\nAi gresit! Mai incearca\n";
                break;
               }
     }
   Opt=AfisMeniu();
  }
  cout<<"\nProgram terminat\n";


  return 0;
}
