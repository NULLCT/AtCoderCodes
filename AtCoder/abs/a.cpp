#include<iostream>
#include<string>
using namespace std;
int ball=0;
int main(){

    string word;
    cin>>word;
    for(int i=0;i != 3;i++){
        if(word.substr(i,1) == "1"){
            ball++;
        }
    }

    cout<<ball<<endl;

    return 0;
}

