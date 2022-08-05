#include<iostream>
using namespace std;

int main(){
    const char *p = "baidu";
    string str = "";
    str.reserve(10);
    for(int i = 0; i < 5; i++){
        str[i] = p[i];
    }
    cout<<str<<endl;
    for(int i = 0; i < 5; i++){
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}