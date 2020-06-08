#include<iostream>
using namespace std;

class Solution{
	public:
		Solution(){
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			cout.tie(NULL);
		}
		
		bool isPowerOfTwo(int n){
			/**
			
			if(n<0) return false;
			int count = 0;
			while(n){
				if(n&1) count++;
				n>>=1;
			}
			return count==1;
			
			**/
			//or
			
			return n == 1 || n > 0 && !(n % 2) && 2 * ((n >>= 1) - 1) + 1 == ((n - 1) ^ n);
		}
};

int main(){
	Solution s;
	int N = 16;
	bool result = s.isPowerOfTwo(N);
	cout<<result<<"\n";
	return 0;
}
