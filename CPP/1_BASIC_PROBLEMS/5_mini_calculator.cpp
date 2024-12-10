#include <iostream>
using namespace std;
int main() {
    int a,b,c;
  cout<<"enter 2 no:";
  cin>>a;
  cin>>b;
  do{
  cout<<"\nchoose an operation\n1.+,\n2.-,\n3.*,\n4./ \n5.Quit\n" ;
  cin>>c;
  cout<<"---------------------\n";
  switch(c)
  {
     case 1:
            cout<<"your ans is: "<<a+b<<"\n";
            break;
     case 2:
           cout<<"your ans is: "<< a-b<<"\n";
            break;
     case 3:
          cout<<"your ans is: "<<a*b<<"\n";
          break;
     case 4:
          if(a<=0|| b<=0){
            cout<<"ERROR!!!";
            break;
          }
          cout<<"your ans is: "<<(float)a/b<<"\n";
            break;
     case 5:
           break;
     default:
          cout<<"error\n";
          break;
    }
}while(c!=5);

  return 0;
  }