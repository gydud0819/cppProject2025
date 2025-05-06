/*
* 작성일	: 2025-05-06
* 작성자	: 박효영
* 주제	: 아스키 코드 아카이브를 활용하여 스토리있는 게임 간단하게 구현
*/
#include <iostream>
#include "Console.h"
#include "ImageMondel.h"
#include "Image.h"
#include "Actor.h"

/*
* 스토리 게임 구성 요소
* 콘솔 유틸리티 함수
* Image class
* IamgeModel 객체 구조체
* Actor = Tell(), Selection()
*/

/*
* 등장 인물
* 등장 배경
* "사건"
*/

int main()
{
	ImageModel model;
	Actor actor;

	/*Console::GotoXY(10, 1);
	std::cout << model.baseballPlayer << std::endl;*/

	Console::CursorVisible(false);

	Image baseball(model.baseballPlayer, 50);
	Console::GotoXY(20, 20);

	baseball.move(0, 5, 10, 500);		// 플레이어 애니메이션
	actor.Tell("나레이션", "9회말 2아웃 2사 2, 3루 5:4 홈팀이 지고 있는 상황.");	// 대사
	actor.Tell("나레이션", "타자가 타석에 들어서고 타격 준비를 한다.");	// 대사
	actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
	bool b1 = actor.Selection("타자", "초구를 지켜본다.", "방망이를 휘두른다.");

	while (true)
	{
		if (b1)
		{
			cout << "초구를 지켜보았다." << endl;
			actor.Tell("나레이션", "초구는 스트라이크이다.");

		}
		if (b1)
		{
			actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
			bool b2 = actor.Selection("타자", "공을 지켜본다.", "배트를 휘두른다.");

			cout << "방망이를 휘둘렀다." << endl;
			actor.Tell("나레이션", "두번째 공도 스트라이크이다.");
		}
		if (b1)
		{
			actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
			bool b2 = actor.Selection("타자", "공을 지켜본다.", "배트를 휘두른다.");

			cout << "타자는 배트를 휘둘렀다." << endl;
			actor.Tell("나레이션", "세번째는 헛스윙이다.");
		}
		if (b1)
		{
			actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
			bool b2 = actor.Selection("타자", "공을 지켜본다.", "배트를 휘두른다.");

			cout << "타자는 배트를 휘둘렀다." << endl;
			actor.Tell("나레이션", "네번째 공은 파울이다.");
		}
		if (b1)
		{
			actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
			bool b2 = actor.Selection("타자", "공을 지켜본다.", "배트를 휘두른다.");

			cout << "타자는 배트를 휘둘렀다." << endl;
			actor.Tell("나레이션", "다섯번 째 공이 좌익수 담장 뒤로 넘어간다.");
		}

		cout << "공이 담장을 넘어가며 역전 쓰리런 홈런을 쳤다.." << endl;
		actor.Tell("나레이션", "9회말 5:7로 역전을 하면서 홈팀이 경기를 이겼다.");

		break;
	}
}