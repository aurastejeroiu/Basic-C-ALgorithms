#include <iostream>

using namespace std;
/// P1.15 Se dau datele de nastere (z1,l1,a1) si (z2,l2,a2) a doua persoane. Se cere
///      sa se conceapa un algoritm care sa precizeze prin indicatorul r din {0,1,2}
///      (0 au aceasi varsta, 1 prima persoana e mai tanara, 2 a doua persoana e mai tanara)

void Citire(string sir, int& z,int& l, int& a)
{ cout<<sir<<endl;
  cout<<"da ziua:"; cin>>z;
  cout<<"da luna:"; cin>>l;
  cout<<"da anul:"; cin>>a;
}



int Tanar(int z1,int l1, int a1,int z2,int l2, int a2){
  int r=1;
  if(a1<a2) r=2;
   else
      if (a1==a2)
            {if(l1<l2) r=2;
             else
                if(l1==l2)
                { if(z1<z2) r=2;
                   else
                     if(z1==z2) r=0;
                     else       r=1;
                }
                else r=1;
            }
            else   r=1;
  return r;
}

int main()
{  int z1,l1,a1,z2,l2,a2,r;
   Citire("data primei persoane",z1,l1,a1);
   Citire("data celeilalte persoane",z2,l2,a2);
   r=Tanar(z1,l1,a1,z2,l2,a2);
   switch(r){
       case 0: cout<<"aceasi varsta"<<endl;
               break;
       case 1: cout<<"prima mai mica"<<endl;
               break;
       case 2: cout<<" a doua mai mica"<<endl;
   }
   cout<<"Program terminat"<<endl;
   return 0;
}
