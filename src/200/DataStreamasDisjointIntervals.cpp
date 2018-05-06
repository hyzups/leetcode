#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
	map<int, Interval> tree;

	int getLowerKey(int val) {
		auto res = tree.lower_bound(val);
		if (res == tree.begin()) {
			return -1;
		}
		return (--res)->first;
	}

	int getHighKey(int val) {
		auto res = tree.upper_bound(val);
		if (res == tree.end()) {
			return -1;
		}

		return res->first;

	}

public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		if (tree.find(val) != tree.end()) {
			return;
		}

		int l = getLowerKey(val);
		int r = getHighKey(val);

		if (l != -1 && r != -1 && tree[l].end + 1 == val  && r == val + 1) {
			tree[l].end = tree[r].end;
			tree.erase(r);
		}
		else if (l != -1 && tree[l].end + 1 >= val) {
			tree[l].end = max(val, tree[l].end);
		}
		else if (r != -1 && r == val + 1) {
			tree[val] = Interval(val, tree[r].end);
			tree.erase(r);
		}
		else {
			tree[val] = Interval(val, val);
		}
	}

	vector<Interval> getIntervals() {
		vector<Interval> res;

		for (auto &i : tree) {
			res.push_back(i.second);
		}
		return res;
	}
};

/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges obj = new SummaryRanges();
* obj.addNum(val);
* vector<Interval> param_2 = obj.getIntervals();
*/