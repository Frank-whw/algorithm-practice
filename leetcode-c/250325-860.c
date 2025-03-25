// 860. 柠檬水找零
// 简单

// 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
// 顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

// 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。
// 你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

// 注意，一开始你手头没有任何零钱。

// 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。
// 如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

#include <stdbool.h>
bool lemonadeChange(int *bills, int billsSize)
{
    int five = 0, ten = 0, twenty = 0;
    for (int i = 0; i < billsSize; i++)
    {
        if (bills[i] == 5)
        {
            five += 1;
            continue;
        }
        else if (bills[i] == 10)
        {
            ten += 1;
            if (five >= 1)
            {
                five -= 1;
            }
            else
            {
                return false;
            }
        }
        else if (bills[i] == 20)
        {

            if (five >= 1 && ten >= 1)
            {
                five -= 1;
                ten -= 1;
            }
            else if (five >= 3)
            {
                five -= 3;
            }

            else
            {
                return false;
            }
        }
    }
    return true;
}

// 贪心算法的核心是局部最优->全局最优
// 本题局部最优：遇到20，优先消耗10+5，其次是5+5+5