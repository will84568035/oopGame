#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <stdlib.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CGameRlue.h"

game_framework::CGameRlue::CGameRlue()
{
	page = 1;
}

void game_framework::CGameRlue::LoadBitmap()
{
	rlue[0].AddBitmap(IDB_moveRule1);
	rlue[0].AddBitmap(IDB_moveRule2);
	rlue[0].AddBitmap(IDB_moveRule3);
	rlue[0].AddBitmap(IDB_moveRule4);
	rlue[0].AddBitmap(IDB_moveRule5);
	rlue[0].AddBitmap(IDB_moveRule6);
	rlue[0].AddBitmap(IDB_moveRule7);
	rlue[0].AddBitmap(IDB_moveRule8);
	rlue[0].AddBitmap(IDB_moveRule9);
	rlue[0].SetDelayCount(7);


	
	rlue[1].AddBitmap(IDB_stairRule1);
	rlue[1].AddBitmap(IDB_stairRule2);
	rlue[1].AddBitmap(IDB_stairRule3);
	rlue[1].AddBitmap(IDB_stairRule4);
	rlue[1].AddBitmap(IDB_stairRule5);
	rlue[1].AddBitmap(IDB_stairRule6);
	rlue[1].AddBitmap(IDB_stairRule7);
	rlue[1].AddBitmap(IDB_stairRule8);
	rlue[1].SetDelayCount(9);

	rlue[2].AddBitmap(IDB_attackRule1);
	rlue[2].AddBitmap(IDB_attackRule2);
	rlue[2].AddBitmap(IDB_attackRule3);
	rlue[2].AddBitmap(IDB_attackRule4);
	rlue[2].AddBitmap(IDB_attackRule5);
	rlue[2].AddBitmap(IDB_attackRule6);
	rlue[2].AddBitmap(IDB_attackRule7);
	rlue[2].AddBitmap(IDB_attackRule8);
	rlue[2].AddBitmap(IDB_attackRule9);
	rlue[2].SetDelayCount(7);

	rlue[3].AddBitmap(IDB_pkRule1);
	rlue[3].AddBitmap(IDB_pkRule2);
	rlue[3].AddBitmap(IDB_pkRule3);
	rlue[3].AddBitmap(IDB_pkRule4);
	rlue[3].AddBitmap(IDB_pkRule5);
	rlue[3].AddBitmap(IDB_pkRule6);
	rlue[3].AddBitmap(IDB_pkRule7);
	rlue[3].AddBitmap(IDB_pkRule8);
	rlue[3].AddBitmap(IDB_pkRule9);
	rlue[3].AddBitmap(IDB_pkRule7);
	rlue[3].AddBitmap(IDB_pkRule8);
	rlue[3].AddBitmap(IDB_pkRule9);
	rlue[3].AddBitmap(IDB_pkRule7);
	rlue[3].AddBitmap(IDB_pkRule8);
	rlue[3].AddBitmap(IDB_pkRule9);
	rlue[3].SetDelayCount(7);

	rlue[5].AddBitmap(IDB_teacherRule1);
	rlue[5].AddBitmap(IDB_teacherRule2);
	rlue[5].AddBitmap(IDB_teacherRule3);
	rlue[5].AddBitmap(IDB_teacherRule4);
	rlue[5].AddBitmap(IDB_teacherRule5);
	rlue[5].AddBitmap(IDB_teacherRule6);
	rlue[5].AddBitmap(IDB_teacherRule7);
	rlue[5].AddBitmap(IDB_teacherRule8);
	rlue[5].AddBitmap(IDB_teacherRule9);
	rlue[5].AddBitmap(IDB_teacherRule10);
	rlue[5].AddBitmap(IDB_teacherRule11);
	rlue[5].AddBitmap(IDB_teacherRule12);
	rlue[5].AddBitmap(IDB_teacherRule13);
	rlue[5].SetDelayCount(5);

	rlue[4].AddBitmap(IDB_normalRule);

	CAudio::Instance()->Load(AUDIO_Book, "sounds\\翻書聲.wav");		// 載入翻書音效
}

void game_framework::CGameRlue::OnShow()
{
	if (page == 1) {				//第一頁
		rlue[0].SetTopLeft(0, 0);
		rlue[0].OnShow();
	}else if(page==2){				//第二頁
		rlue[1].SetTopLeft(0, 0);
		rlue[1].OnShow();
	}
	else if (page == 3) {			//第三頁
		rlue[2].SetTopLeft(0, 0);
		rlue[2].OnShow();
	}
	else if (page == 4) {			//第四頁
		rlue[3].SetTopLeft(0, 0);
		rlue[3].OnShow();
	}
	else if (page == 5) {			//第五頁
		rlue[4].SetTopLeft(0, 0);
		rlue[4].OnShow();
	}
	else if (page == 6) {			//第六頁
		rlue[5].SetTopLeft(0, 0);
		rlue[5].OnShow();
	}
	
}

void game_framework::CGameRlue::OnMove()
{
	rlue[0].OnMove();
	rlue[1].OnMove();
	rlue[2].OnMove();
	rlue[3].OnMove();
	rlue[4].OnMove();
	rlue[5].OnMove();
}

void game_framework::CGameRlue::GoNextPage()
{
	if (page < 6) {		//若不是最後一張
		page++;			//換到下一張
		CAudio::Instance()->Play(AUDIO_Book,false);		//撥放翻書音效
	}
}

void game_framework::CGameRlue::GoLastPage()
{
	if (page > 1) {		//若不是第一張
		page--;			//回到上一張
		CAudio::Instance()->Play(AUDIO_Book, false);		//撥放翻書音效
	}
}


