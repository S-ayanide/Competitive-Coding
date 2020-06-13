class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        if(n==0) return {};
        sort(a.begin(),a.end());
        vector<pair<int,int> > dp(n);
        int en=0,maxi=1;
        for(int i=0;i<n;i++) dp[i]={1,i};
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(a[i]%a[j]==0 && dp[j].first+1>dp[i].first) {
                    dp[i].first=dp[j].first+1;
                    dp[i].second=j;
                    if(dp[i].first>maxi) {
                        maxi=dp[i].first;
                        en=i;
                    }
                }
            }
        }
        vector<int> ans;
        int i=en;
        while(i>=0) {
            ans.push_back(a[i]);
            if(dp[i].second==i) break;
            i=dp[i].second;
        }
        return ans;
    }
};
