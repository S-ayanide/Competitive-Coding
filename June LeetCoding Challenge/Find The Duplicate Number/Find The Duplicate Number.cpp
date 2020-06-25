class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second >= 2){
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};
