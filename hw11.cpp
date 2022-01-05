#include <iostream>
#include <regex>
using namespace std;

int main(){
    string a,b;
    cin>>a;
    cin>>b;

  regex reg(b);

  if( regex_match(a, reg) ){
    cout << "true" << endl;
  }
  else{
    cout << "false" << endl;
  }

  return 0;
}
