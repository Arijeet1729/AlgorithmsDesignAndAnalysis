
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct job {
    string name;
    int profit;
    int deadline;
} jobs;

// Sort jobs by profit in descending order
bool comparator(job j1, job j2) {
    return j1.profit > j2.profit;
}

// Find the maximum deadline in the job list
int max_deadline(vector<jobs> &j) {
    int max1 = 0;
    for (auto &i : j) {
        if (i.deadline > max1) {
            max1 = i.deadline;
        }
    }
    return max1;
}

class job_scheduling {
    private:
        vector<jobs> j;
        
    public:
    job_scheduling(vector<jobs> jobs_list) {
        j = jobs_list;
    }

    void Schedule() {
        int profit_earned = 0;
        vector<string> jobs_scheduled;

        sort(j.begin(), j.end(), comparator); 

        int max_slots = max_deadline(j);
        
        vector<string> slots(max_slots, "-1");  

        for (auto &i : j) {

            for (int k =i.deadline - 1; k >= 0; k--) {
                if (slots[k] == "-1") {  // Slot is free
                    profit_earned += i.profit;
                    slots[k] = i.name;
                    break;
                }
            }
        }

        // Print total profit
        cout << profit_earned << endl;

        // Print scheduled jobs
        for (auto &i : slots) {
            if (i != "-1") {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

int main(){
    
    vector<jobs> job_list = {
        {"Job1", 20, 2},
        {"Job2", 60, 2},
        {"Job3", 40, 1},
        {"Job4", 100, 3},
        {"Job5", 80, 4}
    };

    job_scheduling scheduler(job_list);
    scheduler.Schedule();


    

    

    
    return 0;
}
