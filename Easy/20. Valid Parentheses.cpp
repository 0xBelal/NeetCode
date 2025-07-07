//
// Created by Belal on 28-Jun-25.
//
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mParentheses = {{'{','}'},
        {'(',')'},
        {'[',']'}};

        stack<char> st;

        for(char c : s){

            if(mParentheses.count(c)){
                st.push(c);
            }else{

                if(!st.empty() && c == mParentheses[st.top()]){
                    st.pop();
                }else{
                    return false;
                }
            }

        }
        return st.empty();
    }
};
