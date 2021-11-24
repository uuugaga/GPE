#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

struct C{
public:
    bool team;
    int team_number;
    int Time;
    int solved;
    int error[10];
};

bool compare(C a, C b){
    if(a.solved != b.solved) 
        return a.solved > b.solved;
    if(a.Time != b.Time) 
        return a.Time < b.Time;
    if(a.team_number != b.team_number) 
        return a.team_number < b.team_number;
    return false;
}

int main(){
    int NumberCases;
    string input;
    stringstream ss;
    char L;
    int team, problem, time;
    C contestant[101];
    cin >> NumberCases;
    cin.ignore();
    cin.ignore();
    for(int TestCase = 0; TestCase < NumberCases; TestCase++){
        if(TestCase > 0) cout << endl;
        for( int j = 0 ; j < 101 ; j++ ){
        contestant[j].team = 0;
        contestant[j].team_number = j;
        contestant[j].Time = 0;
        contestant[j].solved = 0;
        memset( contestant[j].error, 0, sizeof(contestant[j].error) );
      }
        
        
        while(getline(cin, input) && input != ""){
            ss.clear();
            ss.str(input);
            ss >> team >> problem >> time >> L;
            contestant[team].team = true;
            if(contestant[team].error[problem] == -1)
                continue;
            if(L == 'C')
                contestant[team].Time += time + contestant[team].error[problem] * 20, contestant[team].solved++, contestant[team].error[problem] = -1;
            else if(L == 'I')
                contestant[team].error[problem]++;
        } 
        sort(contestant, contestant + 101, compare);
        for(int i = 0; i < 101; i++)
            if(contestant[i].team)
                cout << contestant[i].team_number << " " << contestant[i].solved << " " << contestant[i].Time << endl; 
    }
    
    return 0;
}