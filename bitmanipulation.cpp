#ifndef STDCPLUSPLUS_H
#define STDCPLUSPLUS_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#endif // STDCPLUSPLUS_H


class Solution {

public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> volatileVector;

        volatileVector.push_back(nums[0]);  


        for (auto i : nums) {

            bool conflict=false;
            
            for (auto j : volatileVector) {
                if ((i & j) != 0) {
                   conflict=true; 
                }
            }
            
            while(conflict){
                volatileVector.erase(volatileVector.begin());
                for (auto j : volatileVector) {
                    if ((i & j) != 0) {
                       conflict=true; 
                    }
                }
            }

            
            volatileVector.push_back(i);
            ans.push_back(volatileVector);

            
        }
        
        

        int maxVal = 0;  

        for (auto& i : ans) {
            if (i.size() > maxVal) {
                maxVal = i.size();
            }
        }

        return maxVal;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 8, 48, 10}; 
    cout << "Result: " << sol.longestNiceSubarray(nums) << endl;
    return 0;
}
