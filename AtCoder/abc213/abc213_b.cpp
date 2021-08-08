#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;
int main(){
  int n;cin>>n;
  vector<pair<int,int>> a(n);
  for(int i=0;i<n;i++){
  	cin>>a[i].first;
    a[i].second = i+1;
  }
  
  sort(a.begin(),a.end(),[](auto l,auto r){
    return l.first > r.first;
  });
  
  cout<<a[1].second<<"\n";
}
