#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job{
    int request_time;
    int running_time;
    Job(int s, int r) : request_time(s), running_time(r){}
};

struct CompareJob{
    bool operator ()(Job &a, Job &b){
        if(a.running_time == b.running_time){
            a.request_time > b.request_time;
        }
        return a.running_time > b.running_time;
    }    
};

bool CompareVector(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int current = 0;
    int jobs_ind = 0;
    sort(jobs.begin(), jobs.end(), CompareVector);
    priority_queue<Job, vector<Job>, CompareJob > job_heap;
    
    while(true){
        while(jobs_ind < jobs.size() && jobs[jobs_ind][0] <= current){
            job_heap.push(Job(jobs[jobs_ind][0], jobs[jobs_ind][1]));
            jobs_ind += 1;
        }
        if(job_heap.empty()){
            current += 1;
            continue;
        }
        Job running_job = job_heap.top();
        int running_time = running_job.running_time;
        int start_time = current - running_job.request_time;

        current += running_time;
        answer += current - running_job.request_time;
        
        job_heap.pop();
        if(job_heap.empty() && jobs_ind == jobs.size())break;
    }
    return answer/jobs.size();
}
