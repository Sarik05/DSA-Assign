#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){

        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
            
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(s.empty()) return false;
            char top = s.top();
            if(ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '['){
                s.pop();
            }
            else{ return false;}
        }

        
        
    }
    return s.empty();

}

int main(){
    string str;
    cout<<"Enter expression"<<endl;
    getline(cin, str);
   if(check(str)){
    cout<<"Balanced";

   }
   else{
    cout<<"Unbalanced";
   }

    

}