#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {

		auto comp = [&matrix](const pair<int, int> &a, const pair<int, int> &b) {
			return matrix[a.first][a.second] > matrix[b.first][b.second];
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> que(comp);

		que.push(make_pair(0, 0));

		int count = 1;
		while (count < k) {
			auto p = que.top();
			que.pop();

			if (p.first + 1 < matrix.size()) {
				que.push(make_pair(p.first + 1, p.second));
			}
			if (p.first == 0 && p.second + 1 < matrix[0].size()) {
				que.push(make_pair(p.first, p.second + 1));
			}

			count++;
		}
		auto p = que.top();
		return matrix[p.first][p.second];
	}
};