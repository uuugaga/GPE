#include <iostream>
using namespace std;

int g(int n, int k){
    if(n == 1) return 0;
    else return (g(n-1, k) + k) % n;
}

int ans(int n){
    for(int i = 1; i <= n; i++)
        if(g(n, i) + 2 == 13)
            return i;
    return 0;
}

int main(){
    int n;
	while(cin >> n && n)
		cout << ans(n-1) << endl;
    return 0;
}