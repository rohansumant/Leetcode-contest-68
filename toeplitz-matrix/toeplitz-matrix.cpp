class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int r = a.size();
        int c = a[0].size();
        for(int i=1;i<r;i++) for(int j=1;j<c;j++) if(a[i][j] != a[i-1][j-1]) return 0;
        return 1;
    }
};
