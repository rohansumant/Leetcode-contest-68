class Solution {
public:
    
    bool check(string &a) {
        int n = a.length();
        for(int i=1;i<n;i++) if(a[i] == a[i-1]) return 0;
        return 1;
    }
    
    string reorganizeString(string a) {
        priority_queue<pair<int,char>> Q;
        map<char,int> mp;
        for(char ch:a) mp[ch]++;
        for(auto pr:mp) Q.push({pr.second,pr.first});
        string ans;
        while(!Q.empty()) {
            if(Q.size() == 1) {
                ans += string(Q.top().first,Q.top().second);
                Q.pop();
            } else {
                auto p1 = Q.top(); Q.pop();
                auto p2 = Q.top(); Q.pop();
                if(p1.second == ans.back()) {
                    ans += p2.second; p2.first--;
                    ans += p1.second; p1.first--;
                    if(p2.first) Q.push(p2);
                    if(p1.first) Q.push(p1);
                } else {
                    ans += p1.second; p1.first--;
                    ans += p2.second; p2.first--;
                    if(p2.first) Q.push(p2);
                    if(p1.first) Q.push(p1);
                }
            }
        }
        return check(ans) ? ans : "";
    }
};
