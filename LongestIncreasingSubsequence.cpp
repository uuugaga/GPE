class Solution {
public:
    int lengthOfLIS(vector<int>& s) {
    int n, Max = 1;
    vector<int> dp;
    for(int i = 0; i < s.size(); i++)
        dp.push_back(1); 
        
    for(int i = 0; i < s.size(); i++)
        for(int j = 0; j < i; j++){
            if(s[j] < s[i]){
                dp[i] = max(dp[i], dp[j] + 1);
                Max = max(Max, dp[i]);
            }
        }
    return Max;
    
    }
};