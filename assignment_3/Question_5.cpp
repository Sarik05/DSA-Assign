#include <iostream>
#include <stack>
using namespace std;

int eval(string exp){
    stack<int> s;
    for(int i=0;i<exp.length();i++){
        char ch = exp[i];
        if(isdigit(ch)){
            s.push(ch - '0');
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            int v1 = s.top(); s.pop();
            int v2 = s.top(); s.pop();
            int res;
            switch(ch){
                case '+': res = v2 + v1; break;
                case '-': res = v2 - v1; break;
                case '*': res = v2 * v1; break;
                case '/': res = v2 / v1; break;
                case '^': res = 1;
                          for(int j=0;j<v1;j++) res *= v2;
                          break;
            }
            s.push(res);
        }
    }
    return s.top();
}

int main(){
    string exp;
    cin>>exp;
    cout<<eval(exp);
}