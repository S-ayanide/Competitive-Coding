/**
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all 
the elements of nums except nums[i].
**/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int* productExceptSelf(int nums[], int N){
			int leftproduct[N], rightproduct[N];
			leftproduct[0] = 1;
			rightproduct[N-1] = 1;
			
			int output[N];
			
			for(int i=1;i<N;i++){			
				leftproduct[i] = nums[i-1] * leftproduct[i-1];							
			}
			for(int i=N-2;i>=0;i--){
				rightproduct[i] = nums[i+1] * rightproduct[i+1];				
			}
			for(int i=0;i<N;i++){			
				output[i] = leftproduct[i] * rightproduct[i];				
			}
			return output;
		}
};

int main(){
	Solution s;
	int input[] = {1,2,3,4};
	int N = 4;
	int *output = s.productExceptSelf(input, N);		
	cout<<output[0]<<" "<<output[1]<<" "<<output[2]<<" "<<output[3];
	return 0;
}
