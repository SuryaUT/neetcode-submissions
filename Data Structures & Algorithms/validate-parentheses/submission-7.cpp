class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0){
            return false;
        }

        stack<char> stk;

        stk.push('s');

        for(char c:s){
            if(c == '(' || c == '{' || c == '['){
                stk.push(c);
            } else if((c == ')' && stk.top() != '(') ||
                (c == '}' && stk.top() != '{') || 
                (c == ']' && stk.top() != '[')){
                return false;
            } else {
                stk.pop();
            }
        }
        
        stk.pop();
        return stk.empty();
    }
};
