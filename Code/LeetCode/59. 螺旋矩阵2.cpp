// my solution
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1, i = 0, j = 0;
        vector<vector<int>> ans(n, std::vector(n, 0));
        ans[i][j] = num;
        num++;
        while(num <= n*n) {
            while(++j<n) {
                if(ans[i][j] == 0) {
                    ans[i][j] = num;
                    num += 1;
                } else {
                    break;
                }
            }
            j--;
            while(++i<n) {
                if(ans[i][j] == 0) {
                    ans[i][j] = num;
                    num += 1;
                } else {
                    break;
                }
            }
            i--;
            while(--j>=0){
                if(ans[i][j] == 0) {
                    ans[i][j] = num;
                    num += 1;
                } else {
                    break;
                }
            }
            j++;
            while(--i>=0) {
                if(ans[i][j] == 0) {
                    ans[i][j] = num;
                    num += 1;
                } else {
                    break;
                }
            }
            i++;
        }
        return ans;
    }
};

// offitial solution: https://leetcode.cn/problems/spiral-matrix-ii/submissions/492561851/
class Solution {
    public int[][] generateMatrix(int n) {
        int l = 0, r = n - 1, t = 0, b = n - 1;
        int[][] mat = new int[n][n];
        int num = 1, tar = n * n;
        while(num <= tar){
            for(int i = l; i <= r; i++) mat[t][i] = num++; // left to right.
            t++;
            for(int i = t; i <= b; i++) mat[i][r] = num++; // top to bottom.
            r--;
            for(int i = r; i >= l; i--) mat[b][i] = num++; // right to left.
            b--;
            for(int i = b; i >= t; i--) mat[i][l] = num++; // bottom to top.
            l++;
        }
        return mat;
    }
}
