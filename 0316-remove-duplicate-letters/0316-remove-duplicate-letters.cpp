class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(26, 0);
        vector<bool> visited(26, false);
        for(auto x:s) v[x-'a']++;
        stack<char> st;
        for(auto x:s){
            v[x-'a']--;
            if (visited[x - 'a']) continue;
            while(st.size() and st.top()>x and v[st.top()-'a']){
                 visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(x);
            visited[x - 'a'] = true;
        }
        string ans;
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};