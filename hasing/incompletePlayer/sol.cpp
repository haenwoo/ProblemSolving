#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> completion_map;
    
    for(int i = 0;i < completion.size();i++){
        completion_map[completion[i]] += 1;
        // if(completion_map.count(completion[i]) > 0){
        //     completion_map[completion[i]] += 1;
        // }else{
        //     completion_map[completion[i]] = 1;
        // }
        cout << completion_map[completion[i]] << endl;
    }

    
    for (int i = 0;i < participant.size();i++){
        if(completion_map[participant[i]] > 0){
            completion_map[participant[i]] -=1;
        }else{
            return participant[i];
        }
    }
    
    return answer;
}
