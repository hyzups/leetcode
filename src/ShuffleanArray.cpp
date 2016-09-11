#include <vector> 
#include <cmath>
#include <ctime>

using namespace std;

class Solution {
private:
	vector<int> arr;
public:
	Solution(vector<int> nums) : arr(nums) {
		srand(time(NULL));
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return arr;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> temp(arr);
		for (int i = arr.size() - 1; i > 0; --i) {
			int p = rand() % (i + 1);
			swap(temp[p], temp[i]);
		}
		return temp;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/