#include "SoundUtil.h"

void SoundUtil::PlayTitlesound(LPCWSTR fileName)
{
	PlaySound(fileName, NULL, SND_SYNC);
}

void SoundUtil::PlayBGM(LPCWSTR fileName)	// 코드와 사운드가 동시에 출력 (비동기)
{
	PlaySound(fileName, NULL, SND_ASYNC);
}
