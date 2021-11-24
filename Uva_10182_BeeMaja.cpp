#include <iostream>
#include <vector>
using namespace std;

int px = 1, py = 0, i = 0;



void upper_right(){
    px++;
    py--;
}

void upper_left(){
    px--;
}

void up(){
    py--;
}

void down(){
    py++;
}

void lower_right(){
    px++;

}

void lower_left(){
    px--;
    py++;
}

int main(){
    vector<pair<int, int>> p;
    p.push_back(pair<int, int>(0, 0));
    p.push_back(pair<int, int>(0, 1));
    p.push_back(pair<int, int>(-1, 1));
    p.push_back(pair<int, int>(-1, 0));
    p.push_back(pair<int, int>(0, -1));
    p.push_back(pair<int, int>(1, -1));
    p.push_back(pair<int, int>(1, 0));
     
    int n = 2;
    while(i < 100000){
        
        down();
        p.push_back(pair<int, int>(px, py));
        while(px > 0 && i < 100000){
            lower_left();
            p.push_back(pair<int, int>(px, py));
            i++;
        }
        while(px > -1 * n && i < 100000){
            upper_left();
            p.push_back(pair<int, int>(px, py));
            i++;
        }
        while(py > 0 && i < 100000){
            up();
            p.push_back(pair<int, int>(px, py));
            i++;
        }
        while(px < 0 && i < 100000){
            upper_right();
            p.push_back(pair<int, int>(px, py));
            i++;
        }
        while(px < n && i < 100000){
            lower_right();
            p.push_back(pair<int, int>(px, py));
            i++;
        }
        while(py < 0 && i < 100000){
            down();
            p.push_back(pair<int, int>(px, py));
            i++;
        }
        n++;
    }
    
    while(cin >> n){
        cout << p[n - 1].first << " " << p[n - 1].second << endl;
    }
    
    return 0;
}