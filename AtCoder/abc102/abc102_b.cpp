#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> a(n);for(auto &&i:a)cin>>i;
  
  int ans=0;
  for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
    ans = max(ans,abs(a[i]-a[j]));
  }
              
  cout<<ans<<"\n";
}
