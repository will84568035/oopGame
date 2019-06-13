#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "PKbackground.h"

namespace game_framework {

	PKbackground::PKbackground()
	{
		x=0;
		y = 0;
		floor = 1;
	}


	void PKbackground::LoadBitmap()
	{
		//載入圖片進去list裡面
		
		background.AddBitmap(IDB_PKBACKGROUND1);
		background.AddBitmap(IDB_PKBACKGROUND2);
		background.AddBitmap(IDB_PKBACKGROUND3);
		background.AddBitmap(IDB_PKBACKGROUND4);
		background.AddBitmap(IDB_PKBACKGROUND5);
		background.AddBitmap(IDB_PKBACKGROUND6);
		background.SetDelayCount(2);

	}

	void PKbackground::OnMove()
	{
		background.OnMove();	//執行物件的動畫
	}

	void PKbackground::OnShow(SchoolMap *m)
	{
		if (this->floor == 1)				//若在一樓
		{
			background.SetTopLeft(0,100);
			background.OnShow();
		}
	}

	void PKbackground::Setfloor(int floor)
	{
		this->floor = floor;
	}
}