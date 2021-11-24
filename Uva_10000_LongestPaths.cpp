#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

class point{
public:
    int start;
    int end;
    int cost;
    point(){}
    ~point(){}
    point(int start, int end, int cost): 
        start(start), end(end), cost(cost){}
};

int main(){
    int n;
    int times = 1;
    vector<point> p;
    while(cin >> n && n){
        int* answer = new int[n + 1];
        for(int i = 1 ; i <= n; i++)
            answer[i] = 1000;
        int start, p1, p2, min = 0, minIndex;
        cin >> start;
        answer[start] = 0;
        p.clear();
        while(cin >> p1 >> p2 && p1 && p2){
            p.push_back(point(p1, p2, -1));
        }
        for(int j = 0; j < p.size(); j++)
        for(int i = 0; i < p.size(); i++){
            if(answer[p[i].end] > answer[p[i].start] + p[i].cost && answer[p[i].start] < 1000)
                answer[p[i].end] = answer[p[i].start] + p[i].cost;
        }

        for(int i = 1; i <= n; i++)
            if(min > answer[i]){
                min = answer[i];
                minIndex = i;
            }
            printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", times++, start, -1 * min, minIndex);
    }
    return 0;
}