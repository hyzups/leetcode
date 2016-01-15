#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) : m_nums(nums) {
        int len = nums.size();
        int size = (int)ceil(log2(len));
        int max_size = 2 * pow(2, size);
        m_st = vector<int>(max_size);

        buildTree(1, 0, len - 1);
    }

    void update(int i, int val) {
        int diff = val - m_nums[i];
        m_nums[i] = val;
        updateTree(1, 0, m_nums.size() - 1, i, diff);
    }

    int sumRange(int i, int j) {
        return sumTree(1, 0, m_nums.size() - 1, i, j);
    }

private:
    int buildTree(int index, int left, int right) {
        if (left > right) {
            return 0;
        }
        if (left == right) {
            m_st[index] = m_nums[left];
        }
        else {
            int mid = left + (right - left) / 2;
            m_st[index] = buildTree(index * 2, left, mid) + buildTree(index * 2 + 1, mid + 1, right);
        }
        return m_st[index];
    }

    void updateTree(int index, int uLeft, int uRight, int i, int diff) {
        if (i < uLeft || i > uRight) {
            return;
        }
        m_st[index] += diff;

        if (uLeft < uRight) {
            int mid = uLeft + (uRight - uLeft) / 2;
            mid >= i ? updateTree(index * 2, uLeft, mid, i, diff) : updateTree(index * 2 + 1, mid + 1, uRight, i, diff);
        }
    }

    int sumTree(int index, int iLeft, int iRight, int qLeft, int qRight) {
        if (qRight < iLeft || qLeft > iRight) {
            return 0;
        }

        if (qLeft <= iLeft && qRight >= iRight) {
            return m_st[index];
        }

        int mid = iLeft + (iRight - iLeft) / 2;

        return  sumTree(index * 2, iLeft, mid, qLeft, qRight) + sumTree(index * 2 + 1, mid + 1, iRight, qLeft, qRight);
    }

    vector<int> m_st;
    vector<int> m_nums;
};
//
//int main() {
//    vector<int> arr{ 0, 9, 5, 7, 3 };
//    NumArray numArray(arr);
//    numArray.sumRange(4, 4);
//    numArray.sumRange(2, 4);
//    numArray.sumRange(3, 3);
//    numArray.update(4, 5);
//    numArray.update(1, 7);
//    numArray.update(0, 8);
//    numArray.sumRange(1, 2);
//    numArray.update(1, 9);
//    numArray.sumRange(4, 4);
//}
//

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);