#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBitch.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CBitch::CBitch()
	{
		Initialize(0, 0, false, false);
	}

	int CBitch::GetX1()
	{
		return x;
	}

	int CBitch::GetY1()
	{
		return y;
	}

	int CBitch::GetX2()
	{
		return x + RWBitch.Width();
	}

	int CBitch::GetY2()
	{
		return y + RWBitch.Height();
	}

	void CBitch::Initialize(int nx, int ny, bool flap1, bool flap2)
	{
		SetXY(nx, ny);
		isMovingRight = flap1;
		isMovingLeft = flap2;
		isSensor = false;
		isForeign = false;
		moveMode = 1;
		pkX, pkY = 0;
		beforePKmode = 0;


		if (isMovingRight)				//設定左右移動範圍
		{
			this->mode = 4;
			rangeX1 = nx;
			rangeX2 = nx + 100;
		}
		else
		{
			this->mode = 3;
			rangeX1 = nx - 100;
			rangeX2 = nx;
		}
	}

	void CBitch::LoadBitmap()
	{
		//載入圖片進去list裡面
		RStBitch.AddBitmap(IDB_RLOSEBITCH0, RGB(0, 0, 0));
		RStBitch.AddBitmap(IDB_RLOSEBITCH1, RGB(0, 0, 0));
		RStBitch.AddBitmap(IDB_RLOSEBITCH2, RGB(0, 0, 0));
		RStBitch.AddBitmap(IDB_RLOSEBITCH3, RGB(0, 0, 0));
		RStBitch.AddBitmap(IDB_RLOSEBITCH4, RGB(0, 0, 0));
		RStBitch.AddBitmap(IDB_RLOSEBITCH5, RGB(0, 0, 0));
		RStBitch.AddBitmap(IDB_RLOSEBITCH6, RGB(0, 0, 0));
		RStBitch.AddBitmap(IDB_RLOSEBITCH7, RGB(0, 0, 0));
		
		RWBitch.AddBitmap(IDB_WRBITCH1, RGB(0, 0, 0));
		RWBitch.AddBitmap(IDB_WRBITCH2, RGB(0, 0, 0));
		RWBitch.AddBitmap(IDB_WRBITCH3, RGB(0, 0, 0));
		RWBitch.AddBitmap(IDB_WRBITCH4, RGB(0, 0, 0));
		RWBitch.SetDelayCount(8);

		LStBitch.AddBitmap(IDB_LLOSEBITCH0, RGB(0, 0, 0));
		LStBitch.AddBitmap(IDB_LLOSEBITCH1, RGB(0, 0, 0));
		LStBitch.AddBitmap(IDB_LLOSEBITCH2, RGB(0, 0, 0));
		LStBitch.AddBitmap(IDB_LLOSEBITCH3, RGB(0, 0, 0));
		LStBitch.AddBitmap(IDB_LLOSEBITCH4, RGB(0, 0, 0));
		LStBitch.AddBitmap(IDB_LLOSEBITCH5, RGB(0, 0, 0));
		LStBitch.AddBitmap(IDB_LLOSEBITCH6, RGB(0, 0, 0));
		LStBitch.AddBitmap(IDB_LLOSEBITCH7, RGB(0, 0, 0));

		LWBitch.AddBitmap(IDB_WLBITCH1, RGB(0, 0, 0));
		LWBitch.AddBitmap(IDB_WLBITCH2, RGB(0, 0, 0));
		LWBitch.AddBitmap(IDB_WLBITCH3, RGB(0, 0, 0));
		LWBitch.AddBitmap(IDB_WLBITCH4, RGB(0, 0, 0));
		LWBitch.SetDelayCount(8);

		//左邊被嚇到
		LFrightenedBitch.AddBitmap(IDB_LNOTICEBITCH1, RGB(0, 0, 0));
		LFrightenedBitch.AddBitmap(IDB_LNOTICEBITCH2, RGB(0, 0, 0));
		LFrightenedBitch.AddBitmap(IDB_LNOTICEBITCH3, RGB(0, 0, 0));
		LFrightenedBitch.AddBitmap(IDB_LNOTICEBITCH4, RGB(0, 0, 0));
		LFrightenedBitch.AddBitmap(IDB_LNOTICEBITCH5, RGB(0, 0, 0));

		//右邊被嚇到
		RFrightenedBitch.AddBitmap(IDB_RNOTICEBITCH1, RGB(0, 0, 0));
		RFrightenedBitch.AddBitmap(IDB_RNOTICEBITCH2, RGB(0, 0, 0));
		RFrightenedBitch.AddBitmap(IDB_RNOTICEBITCH3, RGB(0, 0, 0));
		RFrightenedBitch.AddBitmap(IDB_RNOTICEBITCH4, RGB(0, 0, 0));
		RFrightenedBitch.AddBitmap(IDB_RNOTICEBITCH5, RGB(0, 0, 0));
		

		PKBitch.AddBitmap(IDB_PKBITCH1, RGB(0, 0, 0));
		PKBitch.AddBitmap(IDB_PKBITCH2, RGB(0, 0, 0));
		PKBitch.AddBitmap(IDB_PKBITCH3, RGB(0, 0, 0));
		PKBitch.AddBitmap(IDB_PKBITCH4, RGB(0, 0, 0));
		PKBitch.AddBitmap(IDB_PKBITCH5, RGB(0, 0, 0));
		PKBitch.SetDelayCount(3);
		
		//右邊笑著走
		WRWBitch.AddBitmap(IDB_WRWBITCH0, RGB(0, 0, 0));
		WRWBitch.AddBitmap(IDB_WRWBITCH1, RGB(0, 0, 0));
		WRWBitch.AddBitmap(IDB_WRWBITCH2, RGB(0, 0, 0));
		WRWBitch.AddBitmap(IDB_WRWBITCH3, RGB(0, 0, 0));

		//左邊笑著走
		WLWBitch.AddBitmap(IDB_WLWBITCH0, RGB(0, 0, 0));
		WLWBitch.AddBitmap(IDB_WLWBITCH1, RGB(0, 0, 0));
		WLWBitch.AddBitmap(IDB_WLWBITCH2, RGB(0, 0, 0));
		WLWBitch.AddBitmap(IDB_WLWBITCH3, RGB(0, 0, 0));

	}

	void CBitch::OnMove(SchoolMap *m)
	{
		const int STEP_SIZE = 1; //移動速度
		RStBitch.OnMove();	
		RWBitch.OnMove();	
		LStBitch.OnMove();	
		LWBitch.OnMove();
		LFrightenedBitch.OnMove();
		RFrightenedBitch.OnMove();
		PKBitch.OnMove();
		WLWBitch.OnMove();
		WRWBitch.OnMove();
		
		if (moveMode == 1) {						//若還沒pk
			if (isMovingLeft)
			{
				
				if ((x - STEP_SIZE) >= rangeX1) {  //人物限制
					x -= STEP_SIZE;
				}
				else
				{
					isMovingLeft = false;
					isMovingRight = true;
					this->mode = 4;
				}
			}
			else if (isMovingRight)
			{
				if (x + STEP_SIZE <= rangeX2) {	//人物限制
					x += STEP_SIZE;
				}
				else
				{
					isMovingRight = false;
					isMovingLeft = true;
					this->mode = 3;
				}
			}
		}else if(moveMode==2){					//若敵人女生pk贏
			if (isMovingLeft) {
				x -= 6;							//往左邊飄走
			}
			else if (isMovingRight) {
				x += 6;							//往右邊飄走
			}

			if (GetX2() <= m->getSx() || x > m->getSx() + 1024) {		//若超出螢幕範圍
				x = -200;												//位置永遠設定在地圖之外
			}
		}else if (moveMode == 3) {										//右上飛天
			x += 20;
			y -= 15;
			if (GetX2() <= m->getSx() || x > m->getSx() + 1024) {		//若超出螢幕範圍
				x = -200;												//位置永遠設定在地圖之外
			}
		}else if (moveMode == 4) {										//左上飛天
			x -= 20;
			y -= 15;
			if (GetX2() <= m->getSx() || x > m->getSx() + 1024) {		//若超出螢幕範圍
				x = -200;												//位置永遠設定在地圖之外
			}
		}
	}

	void CBitch::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CBitch::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CBitch::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CBitch::OnShow(SchoolMap *m)
	{
		if (this->mode == 1)				//1= 左邊旋轉
		{
			LStBitch.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			LStBitch.OnShow();
		}
		else if (this->mode == 2)			// 2 = 右邊旋轉
		{
			RStBitch.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			RStBitch.OnShow();
		}
		else if (this->mode == 3)			// 3 = 左邊走路 
		{
			LWBitch.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			LWBitch.OnShow();
		}
		else if (this->mode == 4)			// 4 = 右邊走路
		{
			RWBitch.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			RWBitch.OnShow();
		}
		else if (this->mode == 5)			// 5 = 左邊被驚嚇
		{
			RFrightenedBitch.SetTopLeft(m->ScreenX(x-20), m->ScreenY(y-37));
			RFrightenedBitch.OnShow();
		}
		else if (this->mode == 6)			// 6 = 右邊被驚嚇
		{
			LFrightenedBitch.SetTopLeft(m->ScreenX(x-20), m->ScreenY(y-37));
			LFrightenedBitch.OnShow();
		}
		else if (this->mode == 7)			// 7 = PK模式
		{
			PKBitch.SetTopLeft(pkX,pkY);
			PKBitch.OnShow();
		}
		else if (this->mode == 13)			// 13 = 左邊笑著走
		{
			WLWBitch.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			WLWBitch.OnShow();
		}
		else if (this->mode == 14)			// 14 = 右邊笑著走
		{
			WRWBitch.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			WRWBitch.OnShow();
		}
	}

	void CBitch::SetMode(int mode)
	{
		this->mode = mode;
	}

	void CBitch::SetSensor(bool flag)
	{
		isSensor = flag;
	}

	void CBitch::SetShowCount()				//設定所有模式的動畫撥放速度
	{
		LFrightenedBitch.Reset();
		RFrightenedBitch.Reset();
		RFrightenedBitch.SetDelayCount(7);
		LFrightenedBitch.SetDelayCount(7);
		LStBitch.Reset();
		LStBitch.SetDelayCount(1);
		RStBitch.Reset();
		RStBitch.SetDelayCount(1);
		WLWBitch.Reset();
		WLWBitch.SetDelayCount(5);
		WRWBitch.Reset();
		WRWBitch.SetDelayCount(5);

	}

	int CBitch::GetMode()
	{
		return this->mode;
	}
	bool CBitch::GetSensor()
	{
		return isSensor;
	}
	bool CBitch::IsShowFinish()
	{
		if (mode == 5)
		{
			return LFrightenedBitch.IsFinalBitmap();	//回傳是否播放完圖片
		}
		else if (mode == 6)
		{
			return RFrightenedBitch.IsFinalBitmap();	//回傳是否播放完圖片
		}
		else if (mode == 7)
		{
			return PKBitch.IsFinalBitmap();
		}
		else {
			return false;
		}
	}
	void CBitch::AttackBoy(CLuSnake * AttackBoy)
	{
		AttackBoy->EnergyReduction();
	}

	void CBitch::SetMoveMode(int mode)
	{
		moveMode = mode;
	}

	void CBitch::SetBeforePKmode(int mode)
	{
		beforePKmode = mode;
	}

	int CBitch::GetBeforePKmode()
	{
		return beforePKmode;
	}

	void CBitch::SetPKPosition(int x, int y)
	{
		pkX = x;
		pkY = y;
	}

	void CBitch::SetIsForeign(bool flag)
	{
		isForeign = flag;
	}

	bool CBitch::GetIsForeign()
	{
		return isForeign;
	}
	
}