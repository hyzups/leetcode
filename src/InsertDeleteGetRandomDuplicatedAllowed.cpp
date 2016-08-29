#include <unordered_map>
#include <cmath>

using namespace std;

class RandomizedCollection {
private:

	unordered_map<int, vector<int>> dic;
	vector<int> arr;

public:
	/** Initialize your data structure here. */
	RandomizedCollection() :dic(unordered_map<int, vector<int>>()), arr(vector<int>()) {
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		dic[val].push_back(arr.size());
		arr.push_back(val);
		return dic[val].size() == 1;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (dic[val].size() == 0) {
			return false;
		}

		int pos = dic[val].back();
		dic[val].pop_back();

		if (pos != arr.size() - 1) {
			int tmp = arr.back();
			dic[tmp].pop_back();
			dic[tmp].push_back(pos);
			arr[pos] = tmp;
		}

		arr.pop_back();
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		int rad = rand() % arr.size();
		return arr[rad];
	}
};

