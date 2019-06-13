
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CSchoolMap.h"




namespace game_framework {

	SchoolMap::SchoolMap() :Sx(0), Sy(0), Sw(210), Cw(900), h(396) {	//設定地圖上小圖的排列方式
		int map_init[28] = { 11,0,0,0,0,0,12,
						     21,0,0,0,0,0,22,
						     31,0,0,0,0,0,32,
						     41,1,1,2,1,1,42 };

		for (int i = 0; i < 28; i++) {
			map[i] = map_init[i];
		}
	}

	void SchoolMap::LoadBitmap()
	{
		classrooom.LoadBitmap(IDB_ClassRoom);
		LStair1.LoadBitmap(IDB_Lstair1F);
		RStair1.LoadBitmap(IDB_Rstair1F);

		LStair2.LoadBitmap(IDB_Lstair2F);
		RStair2.LoadBitmap(IDB_Rstair2F);

		LStair3.LoadBitmap(IDB_Lstair3F);
		RStair3.LoadBitmap(IDB_Rstair3F);

		LStair4.LoadBitmap(IDB_Lstair4F);
		RStair4.LoadBitmap(IDB_Rstair4F);
		ROOF1.LoadBitmap(IDB_ROOF1);
		ROOF2.LoadBitmap(IDB_ROOF2);

		key.LoadBitmap(IDB_keyMap);
	}

	void SchoolMap::OnShow()
	{
		int x_sum = 0;
		int y = 100- Sy;

		for (int i = 0; i < 28; i++) {						//顯示地圖畫面
			switch (map[i]) {
			case 0:
				classrooom.SetTopLeft(x_sum, y);
				classrooom.ShowBitmap();
				x_sum = x_sum + Cw;
				break;
			case 1:
				ROOF1.SetTopLeft(x_sum, y);
				ROOF1.ShowBitmap();
				x_sum = x_sum + Cw;
				break;
			case 2:
				ROOF2.SetTopLeft(x_sum, y-2);
				ROOF2.ShowBitmap();
				x_sum = x_sum + Cw;
				break;
			case 11:
				x_sum = x_sum - Sx;
				LStair1.SetTopLeft(x_sum, y);
				LStair1.ShowBitmap();
				x_sum = x_sum + Sw;
				break;
			case 12:
				RStair1.SetTopLeft(x_sum, y);
				RStair1.ShowBitmap();
				x_sum = x_sum + Sw;
				break;
			case 21:
				LStair2.SetTopLeft(x_sum, y);
				LStair2.ShowBitmap();
				x_sum = x_sum + Sw;
				break;
			case 22:
				RStair2.SetTopLeft(x_sum, y);
				RStair2.ShowBitmap();
				x_sum = x_sum + Sw;
				break;
			case 31:
				LStair3.SetTopLeft(x_sum, y);
				LStair3.ShowBitmap();
				x_sum = x_sum + Sw;
				break;
			case 32:
				RStair3.SetTopLeft(x_sum, y);
				RStair3.ShowBitmap();
				x_sum = x_sum + Sw;
				break;
			case 41:
				LStair4.SetTopLeft(x_sum, y);
				LStair4.ShowBitmap();
				x_sum = x_sum + Sw;
				break;
			case 42:
				RStair4.SetTopLeft(x_sum, y);
				RStair4.ShowBitmap();
				x_sum = x_sum + Sw;
			default:
				ASSERT(0);
			}
		}

		key.SetTopLeft(0, 512);			//印出操作指令集
		key.ShowBitmap();

	}
	

	int SchoolMap::ScreenX(int x)
	{
		return x - Sx;
	}

	int SchoolMap::ScreenY(int y)
	{
		return y - Sy;
	}
	void SchoolMap::SetSx(int x)
	{
		Sx = x;
	}

	int SchoolMap::getSx()	
	{
		return Sx;
	}
	
}
