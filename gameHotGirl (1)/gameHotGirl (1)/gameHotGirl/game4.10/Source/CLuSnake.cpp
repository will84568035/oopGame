#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CLuSnake.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CLuSnake::CLuSnake()
	{
		Initialize(0,0,false,false,1);
	}

	int CLuSnake::GetX1()
	{
		return x;
	}

	int CLuSnake::GetY1()
	{
		return y;
	}

	int CLuSnake::GetX2()
	{
		return x + RLuSnake.Width();
	}

	int CLuSnake::GetY2()
	{
		return y + RLuSnake.Height();
	}

	void CLuSnake::Initialize(int nx,int ny,bool flap1,bool flap2,int Level)
	{	
		loveEnergy = 0;
		SetXY(nx, ny);
		isMovingRight = flap1;
		isMovingLeft = flap2;
		isfollow = false;
		isPKlose = false;
		isGetFinalScore = false;
		isPlayedDingAudio = false;

		if (isMovingRight)
		{
			this->mode = 4;
			rangeX1 = nx;
			rangeX2 = nx + 280;
		}
		else
		{
			this->mode = 3;
			rangeX1 = nx - 130;
			rangeX2 = nx;
		}

		//根據不同帥度設定腳色的價值分數
		handSomeLevel = Level;
		if (handSomeLevel == 1) {			//一般男生
			score = 500;
			finalScore = 1000;
		}else if(handSomeLevel == 100){		//帥哥
			score = 10000;
			finalScore = 25000;
		}else if (handSomeLevel == 110) {	//大帥哥
			score = 24000;
			finalScore = 30000;
		}
		else if (handSomeLevel == 120) {	//外國大帥哥		
			score = 25000;
			finalScore = 40000;
		}
	}

	void CLuSnake::LoadBitmap()
	{	
		//載入圖片進去list裡面
			//----------------------------一般魯蛇
			RLuSnake.AddBitmap(IDB_RLOCKSNACK1, RGB(255, 255, 255));
			RLuSnake.AddBitmap(IDB_RLOCKSNACK2, RGB(255, 255, 255));
			RLuSnake.AddBitmap(IDB_RLOCKSNACK3, RGB(255, 255, 255));
			RLuSnake.AddBitmap(IDB_RLOCKSNACK4, RGB(255, 255, 255));
			RLuSnake.SetDelayCount(3);

			LLuSnake.AddBitmap(IDB_LLOCKSNACK1, RGB(255, 255, 255));
			LLuSnake.AddBitmap(IDB_LLOCKSNACK2, RGB(255, 255, 255));
			LLuSnake.AddBitmap(IDB_LLOCKSNACK3, RGB(255, 255, 255));
			LLuSnake.AddBitmap(IDB_LLOCKSNACK4, RGB(255, 255, 255));
			LLuSnake.SetDelayCount(3);

			WLLuSnake.AddBitmap(IDB_WLLUSNAKEBOY1, RGB(255, 255, 255));
			WLLuSnake.AddBitmap(IDB_WLLUSNAKEBOY2, RGB(255, 255, 255));
			WLLuSnake.AddBitmap(IDB_WLLUSNAKEBOY3, RGB(255, 255, 255));
			WLLuSnake.AddBitmap(IDB_WLLUSNAKEBOY4, RGB(255, 255, 255));

			WRLuSnake.AddBitmap(IDB_WRLUSNAKEBOY1, RGB(255, 255, 255));
			WRLuSnake.AddBitmap(IDB_WRLUSNAKEBOY2, RGB(255, 255, 255));
			WRLuSnake.AddBitmap(IDB_WRLUSNAKEBOY3, RGB(255, 255, 255));
			WRLuSnake.AddBitmap(IDB_WRLUSNAKEBOY4, RGB(255, 255, 255));


			RAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE1, RGB(255, 255, 255));
			RAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE2, RGB(255, 255, 255));
			RAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE3, RGB(255, 255, 255));
			RAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE4, RGB(255, 255, 255));
			RAtLuSnake.SetDelayCount(3);


			LAtLuSnake.AddBitmap(IDB_LATTACKEDLUSNAKE1, RGB(255, 255, 255));
			LAtLuSnake.AddBitmap(IDB_LATTACKEDLUSNAKE2, RGB(255, 255, 255));
			LAtLuSnake.AddBitmap(IDB_LATTACKEDLUSNAKE3, RGB(255, 255, 255));
			LAtLuSnake.AddBitmap(IDB_LATTACKEDLUSNAKE4, RGB(255, 255, 255));
			LAtLuSnake.SetDelayCount(3);
			
			RFollower.AddBitmap(IDB_RToolMan1, RGB(0, 0, 0));
			RFollower.AddBitmap(IDB_RToolMan2, RGB(0, 0, 0));
			RFollower.AddBitmap(IDB_RToolMan3, RGB(0, 0, 0));
			RFollower.AddBitmap(IDB_RToolMan4, RGB(0, 0, 0));



			LFollower.AddBitmap(IDB_LToolMan1, RGB(0, 0, 0));
			LFollower.AddBitmap(IDB_LToolMan2, RGB(0, 0, 0));
			LFollower.AddBitmap(IDB_LToolMan3, RGB(0, 0, 0));
			LFollower.AddBitmap(IDB_LToolMan4, RGB(0, 0, 0));

			PKAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE1, RGB(255, 255, 255));
			PKAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE2, RGB(255, 255, 255));
			PKAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE3, RGB(255, 255, 255));
			PKAtLuSnake.AddBitmap(IDB_RATTACKEDLUSNAKE4, RGB(255, 255, 255));
			PKAtLuSnake.SetDelayCount(3);
		
			//-------------------------------帥哥
			RBoy.AddBitmap(IDB_LRfuckBoy1, RGB(0, 0, 0));
			RBoy.AddBitmap(IDB_LRfuckBoy2, RGB(0, 0, 0));
			RBoy.AddBitmap(IDB_LRfuckBoy3, RGB(0, 0, 0));
			RBoy.AddBitmap(IDB_LRfuckBoy4, RGB(0, 0, 0));
			RBoy.SetDelayCount(3);

			LBoy.AddBitmap(IDB_LLfuckBoy1, RGB(0, 0, 0));
			LBoy.AddBitmap(IDB_LLfuckBoy2, RGB(0, 0, 0));
			LBoy.AddBitmap(IDB_LLfuckBoy3, RGB(0, 0, 0));
			LBoy.AddBitmap(IDB_LLfuckBoy4, RGB(0, 0, 0));
			LBoy.SetDelayCount(3);


			WLBoy.AddBitmap(IDB_WLfuckBoy1, RGB(0, 0, 0));
			WLBoy.AddBitmap(IDB_WLfuckBoy2, RGB(0, 0, 0));
			WLBoy.AddBitmap(IDB_WLfuckBoy3, RGB(0, 0, 0));
			WLBoy.AddBitmap(IDB_WLfuckBoy4, RGB(0, 0, 0));

			WRBoy.AddBitmap(IDB_WRfuckBoy1, RGB(0, 0, 0));
			WRBoy.AddBitmap(IDB_WRfuckBoy2, RGB(0, 0, 0));
			WRBoy.AddBitmap(IDB_WRfuckBoy3, RGB(0, 0, 0));
			WRBoy.AddBitmap(IDB_WRfuckBoy4, RGB(0, 0, 0));

			RFollowBoy.AddBitmap(IDB_RToolFuckBoy1, RGB(0, 0, 0));
			RFollowBoy.AddBitmap(IDB_RToolFuckBoy2, RGB(0, 0, 0));
			RFollowBoy.AddBitmap(IDB_RToolFuckBoy3, RGB(0, 0, 0));
			RFollowBoy.AddBitmap(IDB_RToolFuckBoy4, RGB(0, 0, 0));

			LFollowBoy.AddBitmap(IDB_LToolFuckBoy1, RGB(0, 0, 0));
			LFollowBoy.AddBitmap(IDB_LToolFuckBoy2, RGB(0, 0, 0));
			LFollowBoy.AddBitmap(IDB_LToolFuckBoy3, RGB(0, 0, 0));
			LFollowBoy.AddBitmap(IDB_LToolFuckBoy4, RGB(0, 0, 0));

			//-------------------------------大帥哥
			RCoolBoy.AddBitmap(IDB_LLBoy1, RGB(0, 0, 0));
			RCoolBoy.AddBitmap(IDB_LLBoy2, RGB(0, 0, 0));
			RCoolBoy.AddBitmap(IDB_LLBoy3, RGB(0, 0, 0));
			RCoolBoy.AddBitmap(IDB_LLBoy4, RGB(0, 0, 0));
			RCoolBoy.SetDelayCount(3);

			LCoolBoy.AddBitmap(IDB_LLBoy1, RGB(0, 0, 0));
			LCoolBoy.AddBitmap(IDB_LLBoy2, RGB(0, 0, 0));
			LCoolBoy.AddBitmap(IDB_LLBoy3, RGB(0, 0, 0));
			LCoolBoy.AddBitmap(IDB_LLBoy4, RGB(0, 0, 0));
			LCoolBoy.SetDelayCount(3);


			WLCoolBoy.AddBitmap(IDB_WLBoy1, RGB(0, 0, 0));
			WLCoolBoy.AddBitmap(IDB_WLBoy2, RGB(0, 0, 0));
			WLCoolBoy.AddBitmap(IDB_WLBoy3, RGB(0, 0, 0));
			WLCoolBoy.AddBitmap(IDB_WLBoy4, RGB(0, 0, 0));

			WRCoolBoy.AddBitmap(IDB_WRBoy1, RGB(0, 0, 0));
			WRCoolBoy.AddBitmap(IDB_WRBoy2, RGB(0, 0, 0));
			WRCoolBoy.AddBitmap(IDB_WRBoy3, RGB(0, 0, 0));
			WRCoolBoy.AddBitmap(IDB_WRBoy4, RGB(0, 0, 0));

			RFollowCoolBoy.AddBitmap(IDB_RToolBoy1, RGB(0, 0, 0));
			RFollowCoolBoy.AddBitmap(IDB_RToolBoy2, RGB(0, 0, 0));
			RFollowCoolBoy.AddBitmap(IDB_RToolBoy3, RGB(0, 0, 0));
			RFollowCoolBoy.AddBitmap(IDB_RToolBoy4, RGB(0, 0, 0));


			LFollowCoolBoy.AddBitmap(IDB_LToolBoy1, RGB(0, 0, 0));
			LFollowCoolBoy.AddBitmap(IDB_LToolBoy2, RGB(0, 0, 0));
			LFollowCoolBoy.AddBitmap(IDB_LToolBoy3, RGB(0, 0, 0));
			LFollowCoolBoy.AddBitmap(IDB_LToolBoy4, RGB(0, 0, 0));

			//-------------------------------外國大帥哥
			RForeignBoy.AddBitmap(IDB_LRCoolBoy1, RGB(0, 0, 0));
			RForeignBoy.AddBitmap(IDB_LRCoolBoy2, RGB(0, 0, 0));
			RForeignBoy.AddBitmap(IDB_LRCoolBoy3, RGB(0, 0, 0));
			RForeignBoy.AddBitmap(IDB_LRCoolBoy4, RGB(0, 0, 0));
			RForeignBoy.SetDelayCount(3);

			LForeignBoy.AddBitmap(IDB_LLCoolBoy1, RGB(0, 0, 0));
			LForeignBoy.AddBitmap(IDB_LLCoolBoy2, RGB(0, 0, 0));
			LForeignBoy.AddBitmap(IDB_LLCoolBoy3, RGB(0, 0, 0));
			LForeignBoy.AddBitmap(IDB_LLCoolBoy4, RGB(0, 0, 0));
			LForeignBoy.SetDelayCount(3);


			WLForeignBoy.AddBitmap(IDB_WLCoolBoy1, RGB(0, 0, 0));
			WLForeignBoy.AddBitmap(IDB_WLCoolBoy2, RGB(0, 0, 0));
			WLForeignBoy.AddBitmap(IDB_WLCoolBoy3, RGB(0, 0, 0));
			WLForeignBoy.AddBitmap(IDB_WLCoolBoy4, RGB(0, 0, 0));

			WRForeignBoy.AddBitmap(IDB_WRCoolBoy1, RGB(0, 0, 0));
			WRForeignBoy.AddBitmap(IDB_WRCoolBoy2, RGB(0, 0, 0));
			WRForeignBoy.AddBitmap(IDB_WRCoolBoy3, RGB(0, 0, 0));
			WRForeignBoy.AddBitmap(IDB_WRCoolBoy4, RGB(0, 0, 0));

			RFollowForeignBoy.AddBitmap(IDB_RToolCoolBoy1, RGB(0, 0, 0));
			RFollowForeignBoy.AddBitmap(IDB_RToolCoolBoy2, RGB(0, 0, 0));
			RFollowForeignBoy.AddBitmap(IDB_RToolCoolBoy3, RGB(0, 0, 0));


			LFollowForeignBoy.AddBitmap(IDB_LToolCoolBoy1, RGB(0, 0, 0));
			LFollowForeignBoy.AddBitmap(IDB_LToolCoolBoy2, RGB(0, 0, 0));
			LFollowForeignBoy.AddBitmap(IDB_LToolCoolBoy3, RGB(0, 0, 0));
	}

	void CLuSnake::OnMove(SchoolMap *m)
	{
		const int STEP_SIZE = 1; //移動速度絕對!不能改
		//一般魯蛇onMove
		RLuSnake.OnMove();	//執行物件的動畫
		LLuSnake.OnMove();	
		WLLuSnake.OnMove();	
		WRLuSnake.OnMove();
		RAtLuSnake.OnMove();
		LAtLuSnake.OnMove();
		RFollower.OnMove();
		LFollower.OnMove();
		PKAtLuSnake.OnMove();

		//帥哥onMove
		RBoy.OnMove();	
		LBoy.OnMove();
		WLBoy.OnMove();
		WRBoy.OnMove();
		RFollowBoy.OnMove();
		LFollowBoy.OnMove();

		//大帥哥onMove
		RCoolBoy.OnMove();
		LCoolBoy.OnMove();
		WLCoolBoy.OnMove();
		WRCoolBoy.OnMove();
		RFollowCoolBoy.OnMove();
		LFollowCoolBoy.OnMove();

		//外國大帥哥onMove
		RForeignBoy.OnMove();
		LForeignBoy.OnMove();
		WLForeignBoy.OnMove();
		WRForeignBoy.OnMove();
		RFollowForeignBoy.OnMove();
		LFollowForeignBoy.OnMove();

		
		if (isPKlose == false) {					//若女主角沒有pk輸

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
				if (x + STEP_SIZE <= rangeX2) {		//人物限制
					x += STEP_SIZE;
				}
				else
				{
					isMovingRight = false;
					isMovingLeft = true;
					this->mode = 3;
				}
			}
		}else {								//若女主角pk輸了
			if (isMovingLeft) {		
				mode = 7;					//狀態改為左邊跟隨
				x -= 6;						//往左邊飄走
			}
			else if(isMovingRight){	
				mode = 8;					//狀態改為左邊跟隨
				x += 6;						//往右邊飄走
			}
			
			if (GetX2() <= m->getSx() || x > m->getSx() + 1024) {		//若超出螢幕範圍
				x = -200;												//位置永遠設定在地圖之外
			}
			

		}
	}

	void CLuSnake::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CLuSnake::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CLuSnake::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CLuSnake::OnShow(SchoolMap *m)
	{	
		//如果是一般魯蛇
		if (handSomeLevel == 1) {
			if (this->mode == 1)				//1= 左邊站著
			{
				LLuSnake.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LLuSnake.OnShow();
			}
			else if (this->mode == 2)			// 2 = 右邊站著
			{
				RLuSnake.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RLuSnake.OnShow();
			}
			else if (this->mode == 3)			// 3 = 左邊走路 
			{
				WLLuSnake.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WLLuSnake.OnShow();
			}
			else if (this->mode == 4)			// 4 = 右邊走路
			{
				WRLuSnake.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WRLuSnake.OnShow();
			}
			else if (this->mode == 5) {			//5 = 左邊被射
				LAtLuSnake.SetTopLeft(m->ScreenX(x - 40), m->ScreenY(y - 45));
				LAtLuSnake.OnShow();
			}
			else if (this->mode == 6) {			//6 = 右邊被射
				RAtLuSnake.SetTopLeft(m->ScreenX(x - 30), m->ScreenY(y - 40));
				RAtLuSnake.OnShow();
			}
			else if (this->mode == 7) {			//7 = 左邊跟隨
				LFollower.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LFollower.OnShow();
			}
			else if (this->mode == 8) {			//8 = 右邊跟隨
				RFollower.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RFollower.OnShow();
			}
			else if (this->mode == 9) {			//9 = PK被射
				PKAtLuSnake.SetTopLeft(450, 226);
				PKAtLuSnake.OnShow();
			}
		}//如果是帥哥
		else if (handSomeLevel == 100) {
			if (this->mode == 1)				//1= 左邊站著
			{
				LBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LBoy.OnShow();
			}
			else if (this->mode == 2)			// 2 = 右邊站著
			{
				RBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RBoy.OnShow();
			}
			else if (this->mode == 3)			// 3 = 左邊走路 
			{
				WLBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WLBoy.OnShow();
			}
			else if (this->mode == 4)			// 4 = 右邊走路
			{
				WRBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WRBoy.OnShow();
			}
			else if (this->mode == 5) {			//5 = 左邊被射
				LAtLuSnake.SetTopLeft(m->ScreenX(x - 40), m->ScreenY(y - 45));
				LAtLuSnake.OnShow();
			}
			else if (this->mode == 6) {			//6 = 右邊被射
				RAtLuSnake.SetTopLeft(m->ScreenX(x - 30), m->ScreenY(y - 40));
				RAtLuSnake.OnShow();
			}
			else if (this->mode == 7) {			//7 = 左邊跟隨
				LFollowBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LFollowBoy.OnShow();
			}
			else if (this->mode == 8) {			//8 = 右邊跟隨
				RFollowBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RFollowBoy.OnShow();
			}
			else if (this->mode == 9) {			//9 = PK被射
				PKAtLuSnake.SetTopLeft(450, 226);
				PKAtLuSnake.OnShow();
			}
		}//如果是大帥哥
		else if (handSomeLevel == 110) {
			if (this->mode == 1)				//1= 左邊站著
			{
				LCoolBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LCoolBoy.OnShow();
			}
			else if (this->mode == 2)			// 2 = 右邊站著
			{
				RCoolBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RCoolBoy.OnShow();
			}
			else if (this->mode == 3)			// 3 = 左邊走路 
			{
				WLCoolBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WLCoolBoy.OnShow();
			}
			else if (this->mode == 4)			// 4 = 右邊走路
			{
				WRCoolBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WRCoolBoy.OnShow();
			}
			else if (this->mode == 5) {			//5 = 左邊被射
				LAtLuSnake.SetTopLeft(m->ScreenX(x - 40), m->ScreenY(y - 45));
				LAtLuSnake.OnShow();
			}
			else if (this->mode == 6) {			//6 = 右邊被射
				RAtLuSnake.SetTopLeft(m->ScreenX(x - 30), m->ScreenY(y - 40));
				RAtLuSnake.OnShow();
			}
			else if (this->mode == 7) {			//7 = 左邊跟隨
				LFollowCoolBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LFollowCoolBoy.OnShow();
			}
			else if (this->mode == 8) {			//8 = 右邊跟隨
				RFollowCoolBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RFollowCoolBoy.OnShow();
			}
			else if (this->mode == 9){			//9 = PK被射
				PKAtLuSnake.SetTopLeft(450, 226);
				PKAtLuSnake.OnShow();
			}
		}//如果是外國大帥哥
		else if (handSomeLevel == 120) {
			if (this->mode == 1)				//1= 左邊站著
			{
				LForeignBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LForeignBoy.OnShow();
			}
			else if (this->mode == 2)			// 2 = 右邊站著
			{
				RForeignBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RForeignBoy.OnShow();
			}
			else if (this->mode == 3)			// 3 = 左邊走路 
			{
				WLForeignBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WLForeignBoy.OnShow();
			}
			else if (this->mode == 4)			// 4 = 右邊走路
			{
				WRForeignBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				WRForeignBoy.OnShow();
			}
			else if (this->mode == 5) {			//5 = 左邊被射
				LAtLuSnake.SetTopLeft(m->ScreenX(x - 40), m->ScreenY(y - 45));
				LAtLuSnake.OnShow();
			}
			else if (this->mode == 6) {			//6 = 右邊被射
				RAtLuSnake.SetTopLeft(m->ScreenX(x - 30), m->ScreenY(y - 40));
				RAtLuSnake.OnShow();
			}
			else if (this->mode == 7) {			//7 = 左邊跟隨
				LFollowForeignBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				LFollowForeignBoy.OnShow();
			}
			else if (this->mode == 8) {			//8 = 右邊跟隨
				RFollowForeignBoy.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
				RFollowForeignBoy.OnShow();
			}
			else if (this->mode == 9) {			//9 = PK被射
				PKAtLuSnake.SetTopLeft(450, 226);
				PKAtLuSnake.OnShow();
			}
		}
	}

	void CLuSnake::SetMode(int mode)
	{
		this->mode = mode;
	}

	int CLuSnake::GetMode()
	{
		return this->mode;
	}

	void CLuSnake::AddEnergy() {
		loveEnergy = loveEnergy + 5;
	}

	void CLuSnake::SetEnergy(int energy)
	{
		loveEnergy = energy;
	}

	void CLuSnake::InvincibleAddEnergy() {
		loveEnergy = loveEnergy + 20;					//無敵模式下射擊，攻擊力更強
	}
	

	void CLuSnake::ComboAddEnergy() {		
		loveEnergy = loveEnergy + 9;					//正常的連打攻擊力
	}

	void CLuSnake::InvincibleComboAddEnergy() {
		loveEnergy = loveEnergy + 30;					//無敵模式的連打攻擊力
	}
	
	

	void CLuSnake::EnergyReduction()
	{
		loveEnergy -= 2;
	}

	int CLuSnake::GetEnergy() {
		return loveEnergy;
	}

	int CLuSnake::GetScore()
	{
		return score;
	}

	int CLuSnake::GetHandSomeLevel()
	{
		return handSomeLevel;
	}

	bool CLuSnake::IsShowFinish()
	{
		if (mode == 1)
		{
			return LLuSnake.IsFinalBitmap();	//回傳是否播放完圖片
		}
		else if (mode == 2)
		{
			return RLuSnake.IsFinalBitmap();	//回傳是否播放完圖片
		}
		else {
			return false;
		}
	}

	void CLuSnake::SetIsPkLose(bool flag)
	{
		isPKlose = true;
	}

	bool CLuSnake::GetIsPkLose()
	{
		return isPKlose;
	}

	int CLuSnake::GetFinalScore()
	{
		if (isGetFinalScore == false) {	//若還沒拿過這個分數
			isGetFinalScore = true;		//拿取分數
			return finalScore;
		}else {							//若拿過就不拿多的分數
			return 0;					
		}
	}

	bool CLuSnake::GetisPlayedDingAudio()
	{
		return isPlayedDingAudio;
	}

	void CLuSnake::SetisPlayedDingAudio(bool flag)
	{
		isPlayedDingAudio = flag;
	}

}