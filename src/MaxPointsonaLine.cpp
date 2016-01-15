#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        if (len < 2) {
            return len;
        }

        int res = 0;

        for (int i = 0; i < len - 1; i++) {
            int isSame = 0, isVertical = 0, tempMax = 0;
            map<pair<int, int>, int> counts;
            for (int j = i + 1; j < len; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    isSame++;
                }
                else if (points[i].x == points[j].x) {
                    isVertical++;
                    tempMax = max(tempMax, isVertical);
                }
                else {
                    int a = points[i].x - points[j].x;
                    int b = points[i].y - points[j].y;
                    int div = gcd(b, a);
                    a /= div; b /= div;
                    counts[pair<int, int>(a, b)]++;
                    tempMax = max(tempMax, counts[pair<int, int>(a, b)]);
                }
            }
            res = max(res, tempMax + isSame + 1);
        }
        return res;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

int main() {
    Solution S;
    Point p1(0, 0);
    Point p2(1, 0);
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    S.maxPoints(points);
}