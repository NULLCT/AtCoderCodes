#include<iostream>
using namespace std;
int main(){

    int list[5];
    for(int i=0;i != 5;i++)cin>>list[i];
    for(int i=0;i != 5;i++){
        if(list[i]==list[i+1]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
