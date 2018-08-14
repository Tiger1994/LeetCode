#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int stationNum = gas.size();
		for (int i = 0; i < stationNum; i++){
			int start = i;
			int count = 0;
			int restGas = 0;
			while (count < stationNum){
				int currStation = (start + count) % stationNum;
				restGas += gas[currStation];
				restGas -= cost[currStation];
				if (restGas < 0) break;
				count++;
			}
			if (count == stationNum) return i;
		}

		return -1;
	}

	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost){
		int sum = 0;
		int stationNum = gas.size();
		for (int i = 0; i < stationNum; i++){
			sum += gas[i] - cost[i];
		}
		if (sum < 0) return -1;

		int start = 0;
		sum = 0;
		for (int i = 0; i < stationNum; i++){
			sum += gas[i] - cost[i];
			if (sum < 0){
				start = i+1;
				sum = 0;
			}
		}

		return start;
	}
};

int main(void){
	vector<int> gas = { 1, 2, 3, 4, 5 };
	vector<int> cost = { 3, 4, 5, 1, 2 };

	Solution model;
	int res = model.canCompleteCircuit2(gas, cost);

	return 0;
}