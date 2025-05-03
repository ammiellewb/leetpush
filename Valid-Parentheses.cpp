class Solution {
public:
    bool isValid(string s) {
        stack<int> st; 
        unordered_map<char, char> matching = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (auto& c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != matching[c]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }   
};