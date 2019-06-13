#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Ccombo.h"

namespace game_framework {

	Ccombo::Ccombo()
	{
		Sx = 340;
		Sy = 120;
	}


	void Ccombo::LoadBitmap()
	{
		//載入圖片進去list裡面
		comboText.AddBitmap(IDB_combo1, RGB(0, 0, 0));
		comboText.AddBitmap(IDB_COMBO2, RGB(0, 0, 0));
		comboText.SetDelayCount(3);
	}

	void Ccombo::OnMove()
	{
		comboText.OnMove();	//執行物件的動畫
		
	}

	void Ccombo::OnShow()
	{
		comboText.SetTopLeft(Sx, Sy);
		comboText.OnShow();
	}

	void Ccombo::SetX(int x)
	{
		Sx = x -33;
	}

}