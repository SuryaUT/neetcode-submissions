class Solution {
public:
    bool isPalindrome(string s) {
        char* c1 = &s[0];
        char* c2 = &s[s.length()-1];

        for(char& c:s){
            c = tolower(c);
        }

        while(c1 < c2){

            if(!isalnum(*c1)){
                c1++;
                continue;
            }

            if(!isalnum(*c2)){
                c2--;
                continue;
            }

            if(*c1 != *c2){
                return false;
            }

            c1++;
            c2--;
        }

        return true;
    }
};
