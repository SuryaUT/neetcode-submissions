class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string t:tokens){
            if(isalnum(t[t.length()-1])){
                s.push(stoi(t));
            } else {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();

                if(t == "+"){
                    s.push(first + second);
                } else if(t == "-"){
                    s.push(first - second);
                } else if(t == "*"){
                    s.push(first * second);
                } else { // '/' (divide)
                    s.push(first / second);
                }
            }
        }

        return s.top();
    }
};
