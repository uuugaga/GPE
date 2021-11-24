#include <iostream>

using namespace std;

int main(){
    long long int mul[100000];
    int n;
    while(cin >> n && n){
        for(int i = 0; i < 100000; i++)
            mul[i] = 0;
        mul[0] = 1;
        int len = 1;
        for(int i = n + 2; i <= 2 * n; i++){
            for(int j = 0; j < len; j++)
                mul[j] *= i;
            for(int j = 0; j < len; j++){
                mul[j + 1] += mul[j] / 10;
                mul[j] %= 10;
                if(mul[len]) len++;
            }
        }
        for(int j = len - 1; j >= 0; j--)
            cout << mul[j];
        cout << endl;
    }
    return 0;
}