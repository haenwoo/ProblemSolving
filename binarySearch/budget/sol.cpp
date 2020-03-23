#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ComputeBudgetSum(vector<int> &budgets, int limit){
    int budget_sum = 0;
    for (int i = 0;i < budgets.size();i++){
        if(budgets[i] > limit){
            budget_sum += limit;
        }else{
            budget_sum += budgets[i];
        }
    }
    return budget_sum;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int prev_sum = 0;
    int max_budget = 0;
    
    for(int i = 0;i < budgets.size();i++){
        max_budget = max(max_budget, budgets[i]);
    }
    
    int mid_budget = 0, min_budget = 0;
    while(1){
        mid_budget = (min_budget + max_budget)/2;

        int tmp_sum = ComputeBudgetSum(budgets, mid_budget);
        
        if(prev_sum == tmp_sum){
            answer = mid_budget;
            break;
        }
        if(tmp_sum > M){
            max_budget = mid_budget-1;
        }else if(tmp_sum < M){
            min_budget = mid_budget+1;
        }else{
            answer = mid_budget;
            break;
        }
        prev_sum = tmp_sum;
    }

    return answer;
}