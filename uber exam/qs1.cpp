// lisp programming

#include<iostream>
#include<stack>
using namespace std;

int lisp(String s){
    stack<int> st;
    char op;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            if(st.empty()){
                op = s[i+1];
                i++;
                continue;
            }
            else{
                if(op=='+'){
                    while(!st.empty()){
                        ans = ans+ st.top();
                        st.pop();
                    }
                    st.push(ans);
                }


            }

        }

    }
}