#include <vector> 
#include <unordered_map>
#include <algorithm>

using namespace std;

struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &a) const {
      return std::hash<T>()(a.first) ^ std::hash<U>()(a.second);
    }
};

class Solution {

public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {

        unordered_map<pair<int, int>, int, pairhash> corners;

        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        for (auto &rect : rectangles) {
            minX = min(minX, rect[0]);
            minY = min(minY, rect[1]);
            maxX = max(maxX, rect[2]);
            maxY = max(maxY, rect[3]);

            if (!insert_corner(corners, rect[0], rect[1], 1)) return false;
            if (!insert_corner(corners, rect[0], rect[3], 4)) return false;
            if (!insert_corner(corners, rect[2], rect[1], 2)) return false;
            if (!insert_corner(corners, rect[2], rect[3], 8)) return false;
        }

        //step2: checking
        bool valid_interior[16] = { false };
        valid_interior[3] = valid_interior[5] = valid_interior[10] = valid_interior[12] = valid_interior[15] = true;

        for (auto &p : corners) {
            if ((p.first.first != minX && p.first.first != maxX) || (p.first.second != minY && p.first.second != maxY)) {
                if (!valid_interior[p.second]) {
                    return false;
                }
            }
        }
        return true;

    }

    bool insert_corner(unordered_map<pair<int, int>, int, pairhash> &corner, int x, int y, int pos) {
        int& i = corner[make_pair(x, y)];
        if (i & pos) {
            return false;
        }
        i |= pos;
        return true;
    }
};