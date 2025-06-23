//
// Created by Belal on 03-May-25.
//
a
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};
/*class Solution {
public:
    int evalRPN(vector<string>& tokens) {

            //["10","6","9","3","+","-11","*","/","*","17","+","5","+"]

        stack<int> st;
        for(string &s : tokens ){

            if(s == "+" || s == "-" || s == "*" || s == "/" ){

                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();


                if(s == "+")       st.push(op1 + op2);
                else if(s == "-")  st.push(op1 - op2);
                else if(s == "*")  st.push(op1 * op2);
                else if(s ==  "/") st.push(op1 / op2);

            }else {

                int num = stoi(s);
                st.push(num);

            }


        }

        return st.top();
    }
};*/