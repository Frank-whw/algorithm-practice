class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(auto c : s){
            if(c == '(' || c == '[' || c == '{'){
                sk.push(c);
            }else{
                if(sk.empty())  return false;
                int top_char = sk.top();
                sk.pop();
                if(top_char == '(' && c == ')'|| 
                   top_char == '[' && c == ']'||
                   top_char == '{' && c == '}'){
                    continue;
                   }else{
                    return false;
                   }
            }
        }
        return sk.empty();
    }
};