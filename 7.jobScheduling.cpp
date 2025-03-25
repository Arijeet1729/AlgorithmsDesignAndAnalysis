#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct job{
    string name;
    int value;
    int deadline;
}job;

bool operator<(const job &a, const job &b){
    return a.value>b.value;
}

void schedule(vector <job> jobs){
    sort(jobs.begin(),jobs.end());
    
    int maxded=jobs[0].deadline;
    
    for(int i=0;i<jobs.size();i++){
        if(jobs[i].deadline>maxded){
            maxded=jobs[i].deadline;
        }
    }
    
    
    vector<string> deadlines(maxded+1,"-1");
    int total_profit=0;
    
    for(auto j: jobs){
        int currded=j.deadline;
        for(int i=currded;i>0;i--){
            if(deadlines[i]=="-1"){
                deadlines[i]=j.name;
                total_profit+=j.value;
                break;
            }
        }
    }
    
    for(auto i:deadlines){
        cout << (i != "-1" ? i : "_")<<" ";
    }
    cout<<endl;
    cout <<total_profit<<endl;
}

int main() {
    // Hardcoded input as requested
    vector<job> jobs = {
        {"J1", 100, 2},
        {"J2", 19, 1},
        {"J3", 27, 2},
        {"J4", 25, 1},
        {"J5", 15, 1}
    };
    
    schedule(jobs);
    
    return 0;
}