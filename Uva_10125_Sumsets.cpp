#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int Max;

class add{
public:
    int a;
    int b;
    int sum;
    add(){}
    ~add(){}
    add(int sum, int& a, int& b): sum(sum), a(a), b(b){}
};

vector<add> second_array;

bool binary_search(int x, int n, int c, int d){
    int left = 0;
    int right = n - 1;
    int middle;
    while(left <= right)
    {
        middle = (left + right) / 2;
        if(second_array[middle].sum < x)
            left = middle + 1;
        if(second_array[middle].sum > x)
            right = middle - 1;
        if(second_array[middle].sum == x){
            for(int i = middle; second_array[i].sum == x; i++)
                if(second_array[i].a != c && second_array[i].a != d && second_array[i].b != c && second_array[i].b != d)
                    return true;
            for(int i = middle; second_array[i].sum == x; i--)
                if(second_array[i].a != c && second_array[i].a != d && second_array[i].b != c && second_array[i].b != d)
                    return true;
            return false;
        }
    }
    return false;
}

bool myCompare(add a, add b){
    return a.sum < b.sum;
}

int main(){
    int n;
    bool NO;
    int first_array[1000];
    while(cin >> n && n)
    {
        NO = true;
        for(int i = 0; i < n; i++)
            cin >> first_array[i];
        sort(first_array, first_array + n);
        
        second_array.clear();
        for(int a = 0 , k = 0; a < n; a++)
            for(int b = a + 1; b < n; b++)
                second_array.push_back(add(first_array[a] + first_array[b], first_array[a], first_array[b]));
        sort(second_array.begin(), second_array.end(), myCompare);
    
        for(int d = n - 1; d > 0 && NO; d--)
            for(int c = d - 1; c > 0 && NO; c--)
                if(binary_search(first_array[d] - first_array[c], second_array.size(), first_array[c], first_array[d]) && c != d){
                    cout << first_array[d] << endl;
                    NO = false;
                }        
        if(NO)
            cout << "no solution" << endl;
    }
    return 0;
}