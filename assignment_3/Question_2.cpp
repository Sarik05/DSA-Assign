#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str;
    cout<< "Enter a String: ";
    cin>>str;

    stack<char> s;
    for(int i=0;i<str.size();i++){

        s.push(str[i]);
        }
        string rev = "";
        while(!s.empty()){
            
            rev = rev + s.top();
             s.pop();
        }
        cout<<"Reversed String :"<<rev;

}