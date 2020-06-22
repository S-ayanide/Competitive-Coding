#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int res=0;
        for(int i=0;i<32;i++)
        {   int p=0;
            for(int j=0;j<nums.size();j++)
            {   int k=abs(nums[j]);
                p+=(k&(1<<i))!=0?1:0;
                 
            }
          
           p%=3;
          
          res+=pow(2,i)*p;
        } 
        int c=0;
        for(auto x:nums)   //for negative numbers
            c+=x==res?1:0;
        return c==1?res:-res;
    }
};

int main(){
	Solution s;
	vector<int> nums {2,2,3,2};
	int res = s.singleNumber(nums);
	cout<<res<<"\n";
	return 0;
}
