#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmpPairIntInt(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}


bool cmpPairStringInt(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string ,int> genres_map;
    unordered_map <string, vector<pair<int, int> >* > plays_map;
    for(int i = 0;i < genres.size();i++){
        genres_map[genres[i]] += plays[i]; // genres 별 재생횟수 기록
        if(plays_map.count(genres[i]) > 0){// 장르 별로 고유 번호와 재생횟수 기록
            plays_map[genres[i]]->push_back(make_pair(i, plays[i]));
        }else{
            plays_map[genres[i]] = new vector<pair<int, int> >;
            plays_map[genres[i]]->push_back(make_pair(i, plays[i]));
        }
    }
    vector<pair<string, int> > sorted_genres;
    
    for (auto iter = genres_map.begin();iter != genres_map.end(); iter ++){
           sorted_genres.push_back(make_pair(iter->first, iter->second));
    }//각 장르별로 재생횟수 순으로 정렬
    sort(sorted_genres.begin(), sorted_genres.end(), cmpPairStringInt);
    //가장 많은 장르 순으로 정렬
    for(int i = 0;i < sorted_genres.size();i++){//많이 재생된 장르 순으로
        sort(plays_map[sorted_genres[i].first]->begin(), plays_map[sorted_genres[i].first]->end(), cmpPairIntInt);
        auto igen_number = plays_map[sorted_genres[i].first]->begin();
        //재생횟수가 많은 play list 두개씩 정렬 (없다면 하나)
        answer.push_back(igen_number->first);
        if(plays_map[sorted_genres[i].first]->size()>1)
            answer.push_back((igen_number+1)->first);
    }
    
    
    return answer;
}
