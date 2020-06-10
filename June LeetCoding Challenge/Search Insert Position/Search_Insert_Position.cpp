#include<bits/stdc++.h>
#include<vector>
#include<iterator>
using namespace std;

class Solution {
	public:		
    	
		int searchInsert(vector<int>& nums, int target){
			int l = 0;
	        int r = nums.size()-1;
	        int mid = 0;
	        while (l <= r) {
	            mid = l + (r - l)/2;
	            if (nums[mid] == target)
	                return mid;
	            if (nums[mid] < target)
	                l = mid + 1;
	            if (nums[mid] > target)
	                r = mid - 1 ;
	        } 
	       	return l;
		}
};

int main(){
	Solution s;
	vector<int> nums = {1,3,5,6}; 
    
    int index = s.searchInsert(nums, 9);
    cout<<index<<endl;
	
	return 0;
}
