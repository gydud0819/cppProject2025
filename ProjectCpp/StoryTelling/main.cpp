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
	actor.Tell("나레이션", "타자가 타석에 들어선다.");	// 대사

	baseball.move(0, 5, 10, 500);		// 플레이어 애니메이션
	actor.Tell("나레이션", "타자가 준비를 한다.");
	actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
	bool b1 = actor.Selection("타자", "초구를 지켜본다.", "방망이를 휘두른다.");
	bool b2 = actor.Selection("타자", "공을 지켜본다.", "방망이를 휘두른다.");


	if (b1)
	{
		cout << "초구를 지켜보았다." << endl;
		actor.Tell("나레이션", "초구는 스트라이크이다.");

		/*actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
		bool b2 = actor.Selection("타자", "공을 지켜본다.", "방망이를 휘두른다.");*/

		//bool b2 = actor.Selection("타자", "공을 지켜본다.", "방망이를 휘두른다.");
	}
	if (b2)
	{
		actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
		bool b2 = actor.Selection("타자", "공을 지켜본다.", "방망이를 휘두른다.");

		cout << "방망이를 휘둘렀다." << endl;
		actor.Tell("나레이션", "두번째 공도 스트라이크이다.");
	}
	if (b2)
	{
		actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
		bool b2 = actor.Selection("타자", "공을 지켜본다.", "방망이를 휘두른다.");

		cout << "방망이를 휘둘렀다." << endl;
		actor.Tell("나레이션", "세번째 공은 파울이다.");
	}
	if (b2)
	{
		actor.Tell("나레이션", "타자는 어떤 선택을 할까요?");
		bool b2 = actor.Selection("타자", "공을 지켜본다.", "방망이를 휘두른다.");

		cout << "방망이를 휘둘렀다." << endl;
		actor.Tell("나레이션", "네번째 공이 담장을 넘어간다. 홈런을 쳤다.");
	}



	//baseball.moveReverse(10, 5, 15, 500);

	while (true);
}