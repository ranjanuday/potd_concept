struct cmp {
    bool operator()(const pair<char,int> &a, const pair<char,int> &b) const {
        if (a.first != b.first)
            return a.first > b.first;  
        return a.second < b.second;    
    }
};

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> mini;

        for(int i = 0; i < n; i++) {
            if(s[i] == '*' && !mini.empty()) {
                mini.pop();
            } else {
                mini.push({s[i], i});
            }
        }

        vector<int> ans;
        while(!mini.empty()) {
            ans.push_back(mini.top().second);
            mini.pop();
        }

        sort(ans.begin(), ans.end());
        string res = "";
        for(int i = 0; i < ans.size(); i++) {
            res += s[ans[i]];
        }
        return res;
    }
};
