#include<iostream>
#include<string>
using namespace std;
int main(void){

	int a,b;
	string c;
	cin>>a>>c>>b;

	if(c=="+"){
		cout<<a+b<<endl;
	}else if(c=="-"){
		cout<<a-b<<endl;
	}else if(c=="*"){
		cout<<a*b<<endl;
	}else if(c=="/"){
		if(b==0){
			cout<<"error"<<endl;
		}else{
		cout<<a/b<<endl;
		}
	}else{
		cout<<"error"<<endl;
	}
return 0;
}
