 #include <iostream>

 using namespace std;
 typedef long long ll;

 int main(void){
 ll H,W;
 cin >> H >> W;

 if(H == 1 || W == 1){
 cout << 1 << endl;
 } else {
 cout << (H * W + 1) / 2 << endl;
 }

 return 0;
 }
