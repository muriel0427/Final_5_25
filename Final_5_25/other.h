#pragma once
#include <cstdlib>
#include <ctime>

double GenerateRandomNumber() {
    // 设置随机数种子
    srand(static_cast<unsigned int>(time(nullptr)));

    // 生成0到RAND_MAX（包括RAND_MAX）之间的随机数
    int randomNumber = rand();

    // 将随机数归一化为0到1之间的小数
    double normalizedNumber = static_cast<double>(randomNumber) / RAND_MAX;

    return normalizedNumber;
}