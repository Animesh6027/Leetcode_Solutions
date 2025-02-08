
const int mod=1e9+7;

class Solution {
public:
    vector<int> f1(vector<int>&arr,int n){
        vector<int>ans(n);
        int idx=n-1;
        stack<int>s;
        while(idx>=0){
            if(s.empty()){
                s.push(idx);
                ans[idx]=n;
            }
            else{
                auto it=arr[s.top()];
                if(it>=arr[idx]){
                    while(!s.empty() && arr[s.top()]>=arr[idx]){
                        s.pop();
                    }
                    if(s.empty()) ans[idx]=n;
                    else ans[idx]=s.top();
                    s.push(idx);
                }
                else{
                    ans[idx]=s.top();
                    s.push(idx);
                }
            }
            idx--;
        }
        return ans;
    }
    vector<int> f2(vector<int>arr,int n){
        vector<int>ans(n);
        int idx=0;
        stack<int>s;
        while(idx<n){
            if(s.empty()){
                s.push(idx);
                ans[idx]=-1;
            }
            else{
                auto it=arr[s.top()];
                if(it>=arr[idx]){
                    while(!s.empty() && arr[s.top()]>arr[idx]){
                        s.pop();
                    }
                    if(s.empty()) ans[idx]=-1;
                    else ans[idx]=s.top();
                    s.push(idx);
                }
                else{
                    ans[idx]=s.top();
                    s.push(idx);
                }
            }
            idx++;
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsr=f1(arr,n);
        vector<int>nsl=f2(arr,n);
        // for(auto it:nsr){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:nsl){
        //     cout<<it<<" ";
        // }
        int ans=0;
        for(int i=0;i<n;i++){
            int c1,c2;
            if(nsr[i]==i) c2=0;
            else c2=nsr[i]-i-1;

            if(nsl[i]==i) c1=0;
            else c1=i-nsl[i]-1;

            ans=(ans+(1ll*(1ll*arr[i]*(c1+1))%mod*(c2+1)))%mod;
            cout<<"i: "<<c1<<" "<<c2<<endl;
        }
        return ans;
    }
};