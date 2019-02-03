#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    
    int n,list[100],a=0,b=0;
    cin>>n;
    for(int i=0;i != n;i++){
        cin>>list[i];
        if(a<list[i])a=list[i];
        b+=list[i];
    }
    if(b-a>a){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}

