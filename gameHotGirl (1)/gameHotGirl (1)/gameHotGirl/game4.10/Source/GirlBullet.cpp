#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "GirlBullet.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	GirlBullet::GirlBullet(int Gx, int Gy, int Bx,int By)
	{
		Sx = Gx;
		Sy = Gy;
		Ex = Bx;
		Ey = By;
		x = Gx;
		y = Gy;
		mode = 0;
		SetMode();
		isFinished = false;
	}

	int GirlBullet::GetX1()
	{
		return x;
	}

	int GirlBullet::GetY1()
	{
		return y;
	}

	int GirlBullet::GetX2()
	{
		return x + bullet.Width();
	}

	int GirlBullet::GetY2()
	{
		return y + bullet.Height();
	}

	void GirlBullet::LoadBitmap()
	{
		//載入圖片進去list裡面
		bullet.AddBitmap(IDB_LOVE,RGB(255,255,255));
		
	}

	void GirlBullet::OnMove(SchoolMap *m)
	{
		bullet.OnMove();	//執行物件的動畫
		STEP_X = (Ex - Sx) / 15;
		STEP_Y = (Ey - Sy) / 15;

		if (mode==1)			//RightDown
		{
			
			if (x <= Ex ) {  
				x += STEP_X;
			}
			else
			{
				isFinished = true;
			}
			if (y <= Ey) {
				y += STEP_Y;
			}
		}
		else if (mode == 2)		//RightUp
		{
			if (x <= Ex) {
				x += STEP_X;
			}
			else
			{
				isFinished = true;
			}
			if (y <= Ey) {
				y += STEP_Y;
			}
			
		}
		else if (mode == 3) {			//LeftDown
			if (x >= Ex) {
				x += STEP_X;
			}
			else
			{
				isFinished = true;
			}

			if (y <= Ey) {
				y += STEP_Y;
			}
		}
		else if (mode == 4) {		//LeftUp
			
			if (x >= Ex) {
				x += STEP_X;
			}
			else
			{
				isFinished = true;
			}
			if (y <= Ey) {
				y += STEP_Y;
			}
		}
	}

	void GirlBullet::OnShow(SchoolMap *m)
	{
		bullet.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		bullet.OnShow();
	}
	void GirlBullet::SetMode()
	{
		if (Ex>=Sx && Ey>=Sy) {								//RightDown
			mode = 1;
			Sy += 28; Sx += 80;
			y = Sy;   x = Sx;
			Ex += 8;  Ey += 100;
		
		}else if (Ex >= Sx && Ey <= Sy) {						//RightUp
			mode = 2;
			Sy += 30;  Sx += 85;
			x = Sx;    y = Sy;
			Ex += 8;   Ey += 110;

		}else if (Ex <= Sx && Ey >= Sy) {						//LeftDown
			mode = 3;
			Sy += 28;  Sx += 25;
			y = Sy;    x = Sx;
			Ex += 70;  Ey += 100;
		}else if (Ex <= Sx && Ey <= Sy) {						//LeftUp
			mode = 4;
			Sy += 28;  Sx += 13;
			y = Sy;    x = Sx;
			Ex += 70;  Ey += 110;
		}
	}

	bool GirlBullet::IsFinished()
	{
		return isFinished;
	}
}