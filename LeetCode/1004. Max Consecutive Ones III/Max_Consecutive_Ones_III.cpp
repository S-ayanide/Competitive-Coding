/***
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 
***/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int longestOnes(vector<int>& A, int K) {
			int count=0, j=0, i=0;
			int res = INT_MIN;
			
			for(i=0;i<A.size();i++){
				if(A[i] == 0){
					count++;
				}
				while(count > K && j < A.size()){
					if(A[j] == 0){
						count--;
					}
					j++;
				}
				res = max(res, i-j+1);
			}
			return res == INT_MIN ? ((count <= K) ? A.size() : 0) : res;
		}
};

int main(){
	Solution s;
	vector<int> input {1,1,1,0,0,0,1,1,1,1,0}; //Static Input [1,1,1,0,0,0,1,1,1,1,0]
	int K = 2; //Change K values from 0 to 1
	int result = s.longestOnes(input, K);
	cout<<result<<endl;
	return 0;
}
