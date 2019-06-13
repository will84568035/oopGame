#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <stdlib.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameOverOption.h"

game_framework::CGameOverOption::CGameOverOption()
{
	isBackClick = true;
	isLeaveClick = false;
}

void game_framework::CGameOverOption::LoadBitmap()
{
	optionBack.AddBitmap(IDB_home1, RGB(255, 255, 255));
	optionBack_click.AddBitmap(IDB_home2, RGB(255, 255, 255));

	optionLeave.AddBitmap(IDB_Leave, RGB(255, 255, 255));
	optionLeave_click.AddBitmap(IDB_Leave_click, RGB(255, 255, 255));
}

void game_framework::CGameOverOption::OnShow()
{
	if (isBackClick == true) {						//重新開始的按鈕顯示
		optionBack_click.SetTopLeft(280,385);
		optionBack_click.OnShow();
	}else {
		optionBack.SetTopLeft(280, 385);
		optionBack.OnShow();
	}

	if (isLeaveClick == true) {						//結束遊戲的按鈕顯示
		optionLeave_click.SetTopLeft(530, 385);
		optionLeave_click.OnShow();
	}else {
		optionLeave.SetTopLeft(530, 385);
		optionLeave.OnShow();
	}
}

void game_framework::CGameOverOption::OnMove()
{
	optionBack.OnMove();
	optionBack_click.OnMove();
	optionLeave.OnMove();
	optionLeave_click.OnMove();
}

void game_framework::CGameOverOption::SetIsBackClick(bool flag)
{
	isBackClick = flag;
}

bool game_framework::CGameOverOption::GetIsBackClick()
{
	return isBackClick;
}

void game_framework::CGameOverOption::SetIsLeaveClick(bool flag)
{
	isLeaveClick = flag;
}

bool game_framework::CGameOverOption::GetIsLeaveClick()
{
	return isLeaveClick;
}
