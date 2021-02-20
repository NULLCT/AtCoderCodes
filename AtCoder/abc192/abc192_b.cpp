#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main(){
  string s; cin>>s;
  for(int i=0;i<s.size();i++){
    if(i % 2 == 0){
      if(isupper(s[i])){
        cout<<"No\n";
        return 0;
      }
    }else{
      if(islower(s[i])){
        cout<<"No\n";
        return 0;
      }
    }
  }
  cout<<"Yes\n";
}

