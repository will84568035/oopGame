#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <stdlib.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameInitOption.h"

game_framework::CGameInitOption::CGameInitOption()
{
	isStartClick = true;
	isAboutClick = false;
	isLeaveClick = false;
	enterMode = 0;
}

void game_framework::CGameInitOption::LoadBitmap()
{
	optionStart.AddBitmap(IDB_GameStart, RGB(255, 255, 255));
	optionStart_click.AddBitmap(IDB_GameStart_click, RGB(255, 255, 255));
	
	optionAbout.AddBitmap(IDB_About, RGB(255, 255, 255));
	optionAbout_click.AddBitmap(IDB_About_click, RGB(255, 255, 255));
	
	optionLeave.AddBitmap(IDB_Leave, RGB(255, 255, 255));
	optionLeave_click.AddBitmap(IDB_Leave_click, RGB(255, 255, 255));

	optionReturn_click.AddBitmap(IDB_Return, RGB(255, 255, 255));
	optionReturn_click.AddBitmap(IDB_Return2, RGB(255, 255, 255));

	optionDirectStart_click.AddBitmap(IDB_DirectStart, RGB(255, 255, 255));
	optionDirectStart_click.AddBitmap(IDB_DirectStart2, RGB(255, 255, 255));	
}

void game_framework::CGameInitOption::OnShow()
{
	if (enterMode == 0) {								//mode0
		if (isStartClick == true) {						//開始遊戲的按鈕顯示
			optionStart_click.SetTopLeft(180, 375);
			optionStart_click.OnShow();
		}
		else {
			optionStart.SetTopLeft(180, 375);
			optionStart.OnShow();
		}

		if (isAboutClick == true) {						//關於我們的按鈕顯示
			optionAbout_click.SetTopLeft(410, 375);
			optionAbout_click.OnShow();
		}
		else {
			optionAbout.SetTopLeft(410, 375);
			optionAbout.OnShow();
		}

		if (isLeaveClick == true) {						//結束遊戲的按鈕顯示
			optionLeave_click.SetTopLeft(640, 375);
			optionLeave_click.OnShow();
		}
		else {
			optionLeave.SetTopLeft(640, 375);
			optionLeave.OnShow();
		}
	}
	else if (enterMode == 1) {							//mode1
		optionDirectStart_click.SetTopLeft(410, 440);	//直接開始的按鈕顯示
		optionDirectStart_click.OnShow();
	}
	else if (enterMode == 2) {							//mode2
		optionReturn_click.SetTopLeft(580, 460);		//返回的按鈕顯示
		optionReturn_click.OnShow();
	}
}

void game_framework::CGameInitOption::OnMove()
{
	optionStart.OnMove();
	optionStart_click.OnMove();

	optionAbout.OnMove();
	optionAbout_click.OnMove();

	optionLeave.OnMove();
	optionLeave_click.OnMove();

	optionReturn_click.OnMove();

	optionDirectStart_click.OnMove();
}

void game_framework::CGameInitOption::SetIsStartClick(bool flag)
{
	isStartClick = flag;
}

bool game_framework::CGameInitOption::GetIsStartClick()
{
	return isStartClick;
}

void game_framework::CGameInitOption::SetIsAboutClick(bool flag)
{
	isAboutClick = flag;
}

bool game_framework::CGameInitOption::GetIsAboutClick()
{
	return isAboutClick;
}

void game_framework::CGameInitOption::SetIsLeaveClick(bool flag)
{
	isLeaveClick = flag;
}

bool game_framework::CGameInitOption::GetIsLeaveClick()
{
	return isLeaveClick;
}

void game_framework::CGameInitOption::SetEnterMode(int mode)
{
	enterMode = mode;
}
