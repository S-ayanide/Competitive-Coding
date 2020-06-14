#define ll long long 
#define vc vector

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vc <vc < pair<ll, ll> >> graph(n);
        for(auto i: flights) {
            graph[i[0]].push_back({i[1], i[2]});
        }
        queue < vc<ll> > q;
        ll ans = INT_MAX;
        vc <ll> tmp = {src, k, 0};
        q.push(tmp);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            if(top[0] == dst) {
                ans = min(ans, top[2]);
            }
            ll curr_k = top[1];
            curr_k--;
            if(curr_k >= -1) {
                for(auto child: graph[top[0]]) {
                    // check for children!
                    if(top[2] + child.second <= ans) {
                        vc <ll> arr = {child.first, curr_k, top[2]+child.second};
                        q.push(arr);
                    }
                }
            }
        }
        if (ans == INT_MAX) return -1;
        else return ans;
    }
};
