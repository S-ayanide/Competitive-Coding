class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
       priority_queue<pair<int,int>>sb;
        int half=costs.size()/2;
        int ans=0;
        for(int i=0;i<costs.size();i++){ //Filling priority queue with pair of difference and indexes
            sb.push(make_pair(costs[i][0]-costs[i][1],i));
        }
        for(int i=0;i<half;i++){        //Adding first N max differences to the 2nd set
            ans+=costs[sb.top().second][1];
            sb.pop();
        }        
        for(int i=0;i<half;i++){       //Adding other half to other set
            ans+=costs[sb.top().second][0];
            sb.pop();
        }
        return ans;                    //returning the sum
   }     
};
