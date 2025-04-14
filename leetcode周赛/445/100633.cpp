// 100633. 找到最近的人
// 给你三个整数 x、y 和 z，表示数轴上三个人的位置：

// x 是第 1 个人的位置。
// y 是第 2 个人的位置。
// z 是第 3 个人的位置，第 3 个人 不会移动 。
// 第 1 个人和第 2 个人以 相同 的速度向第 3 个人移动。

// 判断谁会 先 到达第 3 个人的位置：

// 如果第 1 个人先到达，返回 1 。
// 如果第 2 个人先到达，返回 2 。
// 如果两个人同时到达，返回 0 。
// 根据上述规则返回结果。

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        if(abs(x-z) < abs(y-z)){
            return 1;
        }else if(abs(x-z) == abs(y-z)){
            return 0;
        }else{
            return 2;
        }
    }
};