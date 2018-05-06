class Solution {

private:
    int rowNum; 
public:
    int totalNQueens(int n) {
        rowNum = n;
        return countQueens(0, 0, 0, 0);
    }

    int countQueens(int row, int r, int ld, int rd) {
        if (row == rowNum) {
            return 1;
        }

        int res = 0; 
        int avail = ~(r | ld << 1 | rd >> 1);

        for (int i = 0; i < rowNum; i++) {
            int curr = 1 << i;
            if (avail & curr) {
                res += countQueens(row + 1, r | curr, ld << 1| curr, rd >> 1| curr);
            }
        }

        return res;
    }
};