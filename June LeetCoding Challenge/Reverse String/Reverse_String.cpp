#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
		
		void printVector(vector<char>& s){
			for(int i=0;i<s.size();i++){
				cout<<s[i]<<' ';
			}
		}
		
		void reverseString(vector<char>& s) { // Runtime: 24 ms beats 99% of C++ solution
		    ios_base::sync_with_stdio(false);
		    cin.tie(NULL);
		    int l =s.size();
		    for(int i=0;i<l/2;i++){
		        char c = s[i];
		        s[i]=s[l-1-i];
		        s[l-i-1]=c;
		    }
		    // printVector(s); // Uncomment this print statement when testing
		}
		
/***	Using Custom Print Function and swapping 
	
		void reverseString(vector<char>& s){
			for(int i=0;i<s.size()/2;i++){
				char temp = s[i];
				s[i] = s[s.size()-i-1];
				s[s.size()-i-1] = temp;
			}
			printVector(s);
		}			
		
***/		
		
/***	This function would beat 82% C++ submission
		
		void reverseString(vector<char>& s) {
	        int left = 0, right = s.size()-1;
	        while(left<right){
	            swap(s[left], s[right]);
	            left++;
	            right--;
	        }
	        return;
	    }
	    
***/	    
};

int main(){
	Solution sol;
	vector<char> input {'H','a','n','n','a','h'};
	sol.reverseString(input);
	return 0;
}
