#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
    double dp[10][100];
    int k, n;

    string input;
    while(getline(cin, input) && input != ""){
        stringstream ss(input);
        ss >> k >> n;
        double d = (k + 1.0);
        
        for(int i = 0; i <= k; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = 0;
        
        for(int i = 0; i <= k; i++)
            dp[i][0] = 1 / d;

        for(int i = 1; i < n; i++)
            for(int j = 0; j <= k; j++){
                if(j > 0) dp[j][i] += dp[j - 1][i - 1];
                if(j < k) dp[j][i] += dp[j + 1][i - 1]; 
                dp[j][i] += dp[j][i - 1]; 
                dp[j][i] /= d;
            }

        double answer = 0;
        for(int i = 0; i <= k; i++)
            answer += dp[i][n - 1];

        cout << fixed << setprecision(5) << answer * 100 << endl; 
    }
    return 0;
}