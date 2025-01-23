#include <stdio.h>

int biHua[10] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
int k = 0;

// 计算日期的笔画数
int bihua(int year, int month, int day) {
    int count = 0;
    if (month <= 9) count += 13;
    if (day <= 9) count += 13;

    while (year > 0) {
        count += biHua[year % 10];
        year /= 10;
    }
    while (month > 0) {
        count += biHua[month % 10];
        month /= 10;
    }
    while (day > 0) {
        count += biHua[day % 10];
        day /= 10;
    }
    return count;
}

// 检查是否是闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// 处理一年中的所有天数
void processYear(int year, int endMonth, int endDay) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) days[1] = 29;

    for (int month = 1; month <= endMonth; month++) {
        int lastDay = (month == endMonth) ? endDay : days[month - 1];
        for (int day = 1; day <= lastDay; day++) {
            if (bihua(year, month, day) > 50) {
                k += 1;
            }
        }
    }
}

int main() {
    for (int year = 2000; year < 2024; year++) {
        processYear(year, 12, 31);
    }
    processYear(2024, 4, 13); // 只处理 2024 年的前几个月
    printf("%d\n", k);
    return 0;
}
