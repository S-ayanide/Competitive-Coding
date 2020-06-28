class Solution {
private:
    stack <string> order;
    map <string, priority_queue<string, vector<string>, greater<string>>> g;
public:
    void build(string dep_code) {
        while(!g[dep_code].empty()) {
            string arr_code = g[dep_code].top();
            g[dep_code].pop();
            
            build(arr_code);
        }
        order.push(dep_code);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++) {
            string u = tickets[i][0], v = tickets[i][1];
            
            g[u].push(v);
        }
        
        build("JFK");
        
        vector <string> itinerary; 
        while(!order.empty()) {
            itinerary.push_back(order.top());
            order.pop();
        }
        return itinerary;
    }
};
