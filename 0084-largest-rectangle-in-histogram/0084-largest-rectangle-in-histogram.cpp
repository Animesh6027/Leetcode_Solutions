class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxarea=0;
        int n=heights.size();
        for(int i=0;i<=n;++i){
            int h=(i==n)? 0: heights[i];
            while(!s.empty() && h<heights[s.top()]){
                int height=heights[s.top()];
                s.pop();
                int width=s.empty()?i:i-s.top()-1;
                maxarea=max(maxarea, height*width);
            }
            
            s.push(i);
        }
        return maxarea;
    }
};