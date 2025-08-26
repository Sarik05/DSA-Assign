#include <iostream>
#include <stack>
using namespace std;

int main(){
    string exp;
    cin>>exp;
    stack<char> st;
    string res="";

    for(int i=0;i<exp.size();i++){
        char c=exp[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            res+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            int p;
            if(c=='^') p=3;
            else if(c=='*' || c=='/') p=2;
            else if(c=='+' || c=='-') p=1;
            else p=-1;

            while(!st.empty()){
                int q;
                if(st.top()=='^') q=3;
                else if(st.top()=='*' || st.top()=='/') q=2;
                else if(st.top()=='+' || st.top()=='-') q=1;
                else q=-1;

                if(q>=p){
                    res+=st.top();
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res;
}