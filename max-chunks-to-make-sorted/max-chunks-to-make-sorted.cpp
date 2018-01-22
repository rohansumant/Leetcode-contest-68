//Solution same as part 2 because the problem statement is the same, just the constraints differ.
int dp[2005];
class Solution {
public:
    
    vector<int> a;
    int n;
    
    int go(int ix) {
        if(ix == n) return 0;
        if(dp[ix]) return dp[ix];
        vector<int> mn(n+1),mx(n);
        mn[n] = 1e9; mx[ix] = a[ix];        
        for(int i=n-1;i>=ix;i--) mn[i] = min(mn[i+1],a[i]);
        for(int i=ix+1;i<n;i++) mx[i] = max(mx[i-1],a[i]);
        int ans = 0;
        for(int i=ix;i<n;i++) if(mx[i] <= mn[i+1]) ans = max(ans,1+go(i+1));
        dp[ix] = ans;
        return ans;
    }
    
    
    
    int maxChunksToSorted(vector<int>& arr) {
        a = arr;
        n = a.size();
        for(int i=0;i<2005;i++) dp[i] = 0;
        return go(0);
    }
};
