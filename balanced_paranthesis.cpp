#include<iostream>
#include<stack>
using namespace std ;

void balanced_paranthesis(string str){
    stack<char> st;
    for(int i=0; i<str.length(); i++){

        // if string character is opening braket then push into the stack
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);
        }
        /*if string character is closing braket then cheak the same type of opening braket
         is present at the top in the stack if this is true then pop the opening braket */
        else if(str[i]==')' && st.top()=='('){
            st.pop();
        }
        else if(str[i]=='}' && st.top()=='{'){
            st.pop();
        }
        else if(str[i]==']' && st.top()=='['){
            st.pop();
        }
        // else continue
        else{
            continue;
        }
    }

    // check if stack is empty then paranthesis is balanced else unbalanced
    if(st.empty()){
        cout<<"Balanced Paranthesis "<<endl ;
    }
    else{
        cout<<"Unbalanced Paranthesis "<<endl ;
    }
}

int main(){
    string s1 = "[()]{}{[()()]()}" ;
    string s2 = "[(])" ;
    balanced_paranthesis(s1) ;
    balanced_paranthesis(s2) ;


    return 0;
}