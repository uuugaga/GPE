#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class toPoint{
public:
    int next;
    int weight;
    toPoint(){}
    ~toPoint(){}
    toPoint(int N, int W): next(N), weight(W){}
};

vector<toPoint> p[10001];
int answer = 0;
int u, v, cost;
int dfs(int to, int from){
    int route_max = 0;
    for(auto &P: p[to]){
        if(P.next == from)
            continue;
        int route = dfs(P.next, to) + P.weight;
        answer = max(route + route_max, answer);
        route_max = max(route, route_max);
    }
    return route_max;
}

void input(char line[])
{
    int p1, p2, L;
    sscanf(line, "%d%d%d", &p1, &p2, &L);
    
}


int main()
{
    char cmd[100];
    ele E;
    int x, y, v;
    while(gets(cmd)) {
        if(cmd[0] == '\0') {
            sol(x);
            init();
            continue;
        }
        sscanf(cmd, "%d %d %d", &u, &v, &cost);
        p[u].push_back(toPoint(v, cost));
        p[v].push_back(toPoint(u, cost));

        dfs(1,-1);
        printf("%d\n", answer);
    }
    return 0;
}