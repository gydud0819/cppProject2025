#pragma once
#include "Util.h"

int RandomUtil::GetRandomInt(int range)
{
    static random_device device;
    static mt19937 gen(device());             // 랜덤 난수 생성기
    uniform_int_distribution<> dist(1, range);

    return dist(gen);
}

void ConsoleUtil::GotoXY(int x, int y)
{
    static COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void SoundUtility::PlayTitleBGM(LPCWSTR sound)
{
    PlaySound(sound, NULL, SND_SYNC);
}

void SoundUtility::PlayBGM2(LPCWSTR sound)
{
    PlaySound(sound, NULL, SND_ASYNC);

}
