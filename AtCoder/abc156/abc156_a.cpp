#include <iostream>
using namespace std;
int main(){
  cin.tie(0);

  int n,r;
  cin>>n>>r;


  if (n >= 10) {
    cout<<r<<"\n";
    return 0;
  }

  cout << r + 100 * (10 - n) << "\n";
}

