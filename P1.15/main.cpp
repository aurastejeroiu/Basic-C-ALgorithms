#include <iostream>

using namespace std;
//P1.15 Se dau datele de nastere (z1,l1,a1) si (z2,l2,a2) a doua persoane. Se cere sa se conceapa un algoritm
//      care sa precizeze prin indicatorul r din {0,1,2} (0 au aceasi varsta, 1 prima persoana e mai tanara, 2 a
//      persoana e mi tanara)

void Citire(string sir, int& z,int& l, int& a)
{ cout<<sir<<endl;
  cout<<"da ziua:"; cin>>z;
  cout<<"da luna:"; cin>>l;
  cout<<"da anul:"; cin>>a;
}



int main()
{  int z1,l1,a1,z2,l2,a2,r;
   Citire("data primei persoane",z1,l1,z1);
   Citire("data celeilalte persoane",z2,l2,z2);
   if(a1<a2) r=2;
   else if (a1==a2)
            if(l1<l2) r=2
            else if(l1=l2)

    cout << "Hello world!" << endl;
    return 0;
}
