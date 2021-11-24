#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int answer[26];

void dfs(int i, int j, char** chart){
    char target = chart[i][j];
    chart[i][j] = '#';
    if(chart[i + 1][j] == target)
        dfs(i + 1, j, chart);
    if(chart[i - 1][j] == target)
        dfs(i - 1, j, chart);
    if(chart[i][j + 1] == target)
        dfs(i, j + 1, chart);
    if(chart[i][j - 1] == target)
        dfs(i, j - 1, chart);
    
    
}

int main(){
    int TestCase;
    cin >> TestCase;
    for(int NumberCase = 1; NumberCase <= TestCase; NumberCase++){
        for(int i = 0; i < 26; i++)
            answer[i] = 0;
        int x, y;
        cin >> x >> y;
        char** chart = new char*[x + 2];
        for(int i = 0; i < x + 2; i++){
            chart[i] = new char[y + 2];
        }

        for(int i = 0; i < x + 2; i++)
            for(int j = 0; j < y + 2; j++)
                chart[i][j] = '#';

        for(int i = 1; i < x + 1; i++)
            for(int j = 1; j < y + 1; j++)
                cin >> chart[i][j];

        for(int i = 1; i < x + 1; i++)
            for(int j = 1; j < y + 1; j++)
                if(chart[i][j] != '#'){
                    answer[chart[i][j] - 'a']++;
                    dfs(i, j, chart);
                }
        for(int i = 0; i < x +2; i++)
            delete [] chart[i];
        delete [] chart;
        printf("World #%d\n", NumberCase);
        int Max = 0;
        for(int i = 0; i < 26; i++)
            Max = max(answer[i], Max);
        for(int i = Max; i > 0; i--)
            for(int j = 0; j < 26; j++){
                if(answer[j] == i)
                    printf("%c: %d\n", (j + 'a'), i);
            }
    }
    return 0;
}