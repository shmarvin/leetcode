// 134. Gas Station
// https://leetcode.com/problems/gas-station/
// Difficulty: Medium

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        Track cost from starting point i,
        track cost from 0 to i-1
        if i makes it to the end, with remainder >= cost from 0 to i-1, then success

        If total gas >= total cost, there is a solution guaranteed (source: trust me bro).
        And if you start from station a and fail at b, then all the ones in between fail as well.
        */

        int prefix_gas = 0; // cost from 0 to start_ind - 1
        int start_ind = 0;
        int curr_gas = 0;

        for(int i = 0; i < gas.size(); ++i) {
            curr_gas += (gas[i] - cost[i]);
            // cout << "Index " << i<< " current gas: " << curr_gas << endl;
            if (curr_gas < 0) {
                prefix_gas += curr_gas;
                curr_gas = 0;
                start_ind = i+1;
                // cout << " * gas reset. Prefix gas: " << prefix_gas << endl;
            }
        }

        if (curr_gas + prefix_gas >= 0) return start_ind;
        return -1;
    }
};