class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //     unordered_map<int, int> charIdx;
    //     int maxlen=0, left=0;
    //     for(int right=0; right<s.length(); right++){
    //         if(charIdx.find(s[right])!=charIdx.end() && charIdx[s[right]]>=left){
    //             left=charIdx[s[right]]+1;
    //         }
    //         char[s[right]]=right;
    //         maxlen=max(maxlen, right-left+1);
    //     }
    //     return maxlen;
    // }
        set<int> st;
        int ans=0;
        int i=0, j=0;
        while(i<s.size()){
            if(!st.count(s[i])){
                st.insert(s[i]);
                ans=max(ans, (int) st.size());
                i++;
            }else{
                st.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
    
};