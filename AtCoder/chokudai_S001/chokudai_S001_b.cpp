#include<iostream>
using namespace std;
int main(){
  int a;
  cin>>a;
  int ans=0;
  for(int i=0;i<a;i++){
    int s;
    cin>>s;
    ans+=s;
  }
  cout<<ans<<endl;
}
