#include<iostream>
#include<string>
using namespace std;
int main(void){

	int a[5];
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	for(int i=0;i != 4;i++){
		if(a[i]==a[i+1]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}
