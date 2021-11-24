#include <iostream>

using namespace std;

int M, N, Q;
char s[101][101];
bool check(int x1, int y1, int x2, int y2, char target){
    if(x1 < 0 || x2 >= M || y1 < 0 || y2 >= N)
        return false;
    for(int i = x1; i <= x2; i++)
        if(s[i][y1] != target || s[i][y2] != target)
            return false;
    for(int i = y1; i <= y2; i++)
        if(s[x1][i] != target || s[x2][i] != target)
            return false;
    return true;
}

int solve(int x, int y){
    int dx = 1, dy = 1;
    int ans = 1;
    while(check(x - dx, y - dy, x + dx, y + dy, s[x][y])){
        dx++;
        dy++;
        ans += 2;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    for(n; n > 0; n--){
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << endl;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                cin >> s[i][j];
        int r, c;
        for(int i = 0; i < Q; i++){
            cin >> r >> c;
            
            cout << solve(r, c) << endl;
        }
    }
    
    return 0;
}