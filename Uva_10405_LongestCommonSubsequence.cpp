#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);
        int** dp = new int*[s1.length()+1];
        for(int i = 0; i <= s1.length(); i++)
            dp[i] = new int[s2.length()+1]{0};
        for(int i = 1; i <= s1.length(); i++)
            for(int j = 1; j <= s2.length(); j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        cout << dp[s1.length()][s2.length()] << endl;
    }
    return 0;
}