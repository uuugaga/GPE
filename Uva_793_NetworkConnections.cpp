    #include <iostream>
    #include <sstream>
    #include <vector>

    using namespace std;

    int main(){
        int n;
        cin >> n;
        for(int CaseNumber = 0; CaseNumber < n; CaseNumber++){
            if(CaseNumber >= 1)
                cout << endl;
            int RightAnswer = 0;
            int WrongAnswer = 0;
            int number_of_computers;
            cin >> number_of_computers;
            int* connection = new int[number_of_computers + 1];
            for(int i = 1; i <= number_of_computers; i++)
                connection[i] = -1;
            vector<int> index;
            for(int i = 1; i <= number_of_computers; i++)
                index.push_back(i);

            string input;    
            char qc;
            int c1, c2;
            cin.ignore();
            while( getline(cin, input) && input != ""){
                stringstream ss(input);
                ss >> qc >> c1 >> c2;
                if(qc == 'c'){
                if(connection[c1] == -1){
                    connection[c1] = index.back();
                    index.pop_back();
                }
                if(connection[c2] == -1){
                    connection[c2] = index.back();
                    index.pop_back();
                }
                if(connection[c1] != connection[c2])
                {
                    int INDEX = connection[c2];
                    index.push_back(INDEX);
                    for(int i = 1; i <= number_of_computers; i++)
                        if(connection[i] == INDEX)
                            connection[i] = connection[c1];
                }
                }
                else
                {
                    if((connection[c1] == connection[c2]  && connection[c1] != -1) || c1 == c2)
                        RightAnswer++;
                    else
                        WrongAnswer++;
                }
            }
            cout << RightAnswer << ',' << WrongAnswer << endl;
            delete [] connection;
        }
        return 0;
    }