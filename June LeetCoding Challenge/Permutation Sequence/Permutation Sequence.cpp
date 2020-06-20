class Solution {
public:
    vector<int> fact;
    
    void findfact(int n)
    {
        fact = vector<int>(n);
        
        fact[0] = 1;
        
        if(n==1) return;
        
        fact[1] = 1;
        for(int i=2; i<n; i++)
            fact[i] = i*fact[i-1];
    }
    
    string getPermutation(int N, int K) {
        int n = N-1, k = K-1, nt, kt;
        
        findfact(N);
        vector<int> num(N);
        for(int i=0; i<N; i++)
            num[i] = i+1;
        vector<int>::iterator it; 
        
        string ans = "";
        
        while(n>=0)
        {
            nt = k/fact[n];
            kt = k%fact[n];

            ans += (num[nt]+'0');
            it = num.begin(); 
            num.erase(it+nt);
            n--;
            k = kt;   
        }

        return ans;
    }
};
