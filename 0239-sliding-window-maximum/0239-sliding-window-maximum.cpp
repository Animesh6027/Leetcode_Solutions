class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>&arr, int k) {
        int n=arr.size();
        deque<int>q;
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(q.empty()) q.push_back(i);
            else{
                auto it=arr[q.back()];
                if(it>=arr[i]) q.push_back(i);
                else{
                    while(!q.empty() && arr[q.back()]<arr[i]){
                        q.pop_back();
                    }
                    q.push_back(i);
                }
            }
        }
        ans.push_back(arr[q.front()]);

        int i=1,j=k;
        while(j<n){
            while(!q.empty() && q.front()<i){
                q.pop_front();
            }
            if(q.empty()) q.push_back(j);
            else{
                auto it=arr[q.back()];
                if(it>=arr[j]) q.push_back(j);
                else{
                    while(!q.empty() && arr[q.back()]<arr[j]){
                        q.pop_back();
                    }
                    q.push_back(j);
                }
            }
            i++;
            j++;
            ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};