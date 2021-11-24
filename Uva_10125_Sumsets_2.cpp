#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    int k[1000];
    while(cin >> n && n){
        bool NO = true;
        for(int i = 0; i < n; i++)
            cin >> k[i];
        sort(k, k + n);
        for(int d = n - 1; d > 0 && NO; d--)
            for(int a = 0; a < n && NO; a++)
                for(int b = a + 1; b < n && NO; b++)
                    for(int c = b + 1; c < n && NO; c++)
                        if(k[d] == k[a] + k[b] + k[c] &&
                            a != d && b != d && c != d){
                            cout << k[d] << endl;
                            NO = false;
                        }
    if(NO)
        cout << "no solution" << endl;        
    }
    return 0;
}