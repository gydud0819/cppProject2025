#include "RandomUtil.h"

int RandomUtil::GetRandomInt(int range)
{
    static random_device device;
    static mt19937 gen(device());             // 랜덤 난수 생성기
    uniform_int_distribution<> dist(1), range;

    return dist(gen);
}
