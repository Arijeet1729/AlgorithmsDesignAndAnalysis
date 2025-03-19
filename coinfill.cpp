#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    public:
        int minimumAddedCoins(vector<int>& coins, int target) {
            sort(coins.begin(),coins.end());
            
            int minSum=1;
            int addedCoins= 0;

            for(int i: coins){
                if(minSum)
                if(minSum==i){
                    minSum+=i;
                }
                else{
                    addedCoins++;
                    minSum+=(2*minSum)+1;
                    minSum+=i;
                }
            }

            return addedCoins;

        }
    };

