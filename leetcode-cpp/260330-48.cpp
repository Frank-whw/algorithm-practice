// 先转置 再镜像
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout<<matrix[i][j]<< " ";
        //     }
        //     cout << endl;
            
        // }
        
        for (int  i = 0; i < n; i++)
        {
            for(int j = 0; j < n / 2; j++){
                // cout << j << " " << n - 1 - j << endl;
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        
    }
};