#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <stdlib.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CHotGirl.h"


namespace game_framework {

	CHotGirl::CHotGirl()
	{
	}

	int CHotGirl::GetX1()
	{
		return x;
	}

	int CHotGirl::GetY1()
	{
		return y;
	}

	int CHotGirl::GetX2()
	{
		return x + RhotGirl.Width();
	}

	int CHotGirl::GetY2()
	{
		return y + RhotGirl.Height();
	}

	void CHotGirl::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CHotGirl::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CHotGirl::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}


	void CHotGirl::Initialize(SchoolMap *m)
	{
		const int X_POS = 450;	//女主角離螢幕的X距離
		const int Y_POS = 226;	
		x = 660;				//設定初始X座標
		y = Y_POS;				//設定初始Y座標
		m->SetSx(x - X_POS);	//設定初始螢幕座標

		isMovingLeft = isMovingRight = isLocked = isPK = isShotting = isLayDown =isInvincible=false;
		isPlayInvincibleAUDIO = false, isTouchStair = false, isTimeUpInterruptPK=false;
		isPlayCountScoreAudio = false, isPlayedGameOverAudio=false, isHaveInvincible=false;
		isPlayedDangerMusic=false;


		AttackedBoy = NULL;
		heart = NULL;
		PKline = NULL;


		total_score = 0;					//初始總分是0
		energy_score = 320;					//初始愛心有4顆
		floorNum = 1;						//初始樓層在1樓
		newNumber = 0;
		mode = 1;
		currentMode = 1;
		PKcount = 0;
		TouchStairLR = 1;


		if(follower.empty()==false){		//若有存留上次遊戲的跟隨者，就清空跟隨者
			follower.clear();
		}

	}

	void CHotGirl::LoadBitmap()
	{
		//正常的樣子
		RhotGirl.AddBitmap(IDB_SRHOTGIRL, RGB(255, 255, 255));
		LhotGirl.AddBitmap(IDB_SLHOTGIRL, RGB(255, 255, 255));
		WLhotGirl.AddBitmap(IDB_WLHOTGIRL1, RGB(255, 255, 255));
		WLhotGirl.AddBitmap(IDB_WLHOTGIRL2, RGB(255, 255, 255));
		WLhotGirl.AddBitmap(IDB_WLHOTGIRL3, RGB(255, 255, 255));
		WLhotGirl.AddBitmap(IDB_WLHOTGIRL4, RGB(255, 255, 255));
		WRhotGirl.AddBitmap(IDB_WRHOTGIRL1, RGB(255, 255, 255));
		WRhotGirl.AddBitmap(IDB_WRHOTGIRL2, RGB(255, 255, 255));
		WRhotGirl.AddBitmap(IDB_WRHOTGIRL3, RGB(255, 255, 255));
		WRhotGirl.AddBitmap(IDB_WRHOTGIRL4, RGB(255, 255, 255));
		DLhotGirl.AddBitmap(IDB_DLHOTGIRL, RGB(255, 255, 255));
		DRhotGirl.AddBitmap(IDB_DRHOTGIRL, RGB(255, 255, 255));
		ULhotGirl.AddBitmap(IDB_ULHOTGIRL, RGB(255, 255, 255));
		URhotGirl.AddBitmap(IDB_URHOTGIRL, RGB(255, 255, 255));


		//PK時的樣子
		PKGirl.AddBitmap(IDB_PKGIRL1, RGB(0, 0, 0));
		PKGirl.AddBitmap(IDB_PKGIRL2, RGB(0, 0, 0));
		PKGirl.AddBitmap(IDB_PKGIRL3, RGB(0, 0, 0));
		PKGirl.AddBitmap(IDB_PKGIRL4, RGB(0, 0, 0));
		PKGirl.AddBitmap(IDB_PKGIRL5, RGB(0, 0, 0));
		PKGirl.SetDelayCount(3);

		//左邊跌倒
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN0, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN1, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN2, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN3, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN4, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN5, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN6, RGB(0, 0, 0)); 
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN7, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN7, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN7, RGB(0, 0, 0)); 
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN7, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN7, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN7, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN8, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN8, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN8, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN9, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN9, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN9, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN8, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN8, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN8, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN9, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN9, RGB(0, 0, 0)); LlayDownGirl.AddBitmap(IDB_LLAYDOWN9, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN10, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN10, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN10, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN10, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN10, RGB(0, 0, 0));LlayDownGirl.AddBitmap(IDB_LLAYDOWN10, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN11, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN12, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN13, RGB(0, 0, 0));
		LlayDownGirl.AddBitmap(IDB_LLAYDOWN14, RGB(0, 0, 0));
		LlayDownGirl.SetDelayCount(3);


		//右邊跌倒
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN0, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN1, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN2, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN3, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN4, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN5, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN6, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN7, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN7, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN7, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN7, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN7, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN7, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN8, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN8, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN8, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN9, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN9, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN9, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN8, RGB(0, 0, 0)); RlayDownGirl.AddBitmap(IDB_RLAYDOWN8, RGB(0, 0, 0)); RlayDownGirl.AddBitmap(IDB_RLAYDOWN8, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN9, RGB(0, 0, 0)); RlayDownGirl.AddBitmap(IDB_RLAYDOWN9, RGB(0, 0, 0)); RlayDownGirl.AddBitmap(IDB_RLAYDOWN9, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN10, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN10, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN10, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN10, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN10, RGB(0, 0, 0));RlayDownGirl.AddBitmap(IDB_RLAYDOWN10, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN11, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN12, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN13, RGB(0, 0, 0));
		RlayDownGirl.AddBitmap(IDB_RLAYDOWN14, RGB(0, 0, 0));
		RlayDownGirl.SetDelayCount(3);


		//左邊被嚇到
		LFrightenedGirl.AddBitmap(IDB_endLhotgirl1, RGB(0, 0, 0));
		LFrightenedGirl.AddBitmap(IDB_endLhotgirl2, RGB(0, 0, 0));
		LFrightenedGirl.AddBitmap(IDB_endLhotgirl3, RGB(0, 0, 0));
		LFrightenedGirl.AddBitmap(IDB_endLhotgirl4, RGB(0, 0, 0));
		LFrightenedGirl.AddBitmap(IDB_endLhotgirl5, RGB(0, 0, 0));
		LFrightenedGirl.SetDelayCount(7);

		//右邊被嚇到
		RFrightenedGirl.AddBitmap(IDB_endRhotgirl1, RGB(0, 0, 0));
		RFrightenedGirl.AddBitmap(IDB_endRhotgirl2, RGB(0, 0, 0));
		RFrightenedGirl.AddBitmap(IDB_endRhotgirl3, RGB(0, 0, 0));
		RFrightenedGirl.AddBitmap(IDB_endRhotgirl4, RGB(0, 0, 0));
		RFrightenedGirl.AddBitmap(IDB_endRhotgirl5, RGB(0, 0, 0));
		RFrightenedGirl.SetDelayCount(7);

		//左邊笑著走
		LLaughGirl.AddBitmap(IDB_endwalkleft1, RGB(0, 0, 0));
		LLaughGirl.AddBitmap(IDB_endwalkleft2, RGB(0, 0, 0));
		LLaughGirl.AddBitmap(IDB_endwalkleft3, RGB(0, 0, 0));
		LLaughGirl.AddBitmap(IDB_endwalkleft4, RGB(0, 0, 0));
		LLaughGirl.SetDelayCount(5);

		//右邊笑著走
		RLaughGirl.AddBitmap(IDB_endwalkright1, RGB(0, 0, 0));
		RLaughGirl.AddBitmap(IDB_endwalkright2, RGB(0, 0, 0));
		RLaughGirl.AddBitmap(IDB_endwalkright3, RGB(0, 0, 0));
		RLaughGirl.AddBitmap(IDB_endwalkright4, RGB(0, 0, 0));
		RLaughGirl.SetDelayCount(5);


		//最後面向左邊跌倒
		FinalLlayDownGirl.AddBitmap(IDB_LLAYDOWN10, RGB(0, 0, 0));
		
		
		//最後面向右邊跌倒
		FinalRlayDownGirl.AddBitmap(IDB_RLAYDOWN10, RGB(0, 0, 0));
	}

	void CHotGirl::LoadAudio()
	{
		CAudio::Instance()->Load(9, "sounds\\PK.wav");
		CAudio::Instance()->Load(10, "sounds\\lighting.wav");
		CAudio::Instance()->Load(11, "sounds\\TouchHeart.wav");
		CAudio::Instance()->Load(12, "sounds\\laser.wav");
		CAudio::Instance()->Load(13, "sounds\\Scream.wav");
		CAudio::Instance()->Load(14, "sounds\\TOKYOHOT.wav");
		CAudio::Instance()->Load(15, "sounds\\transform.mp3");
		CAudio::Instance()->Load(17, "sounds\\FinalCountScore.wav");
		CAudio::Instance()->Load(19, "sounds\\外星人叫.wav");
		CAudio::Instance()->Load(23, "sounds\\小愛心警告.mp3");	
		CAudio::Instance()->Load(26, "sounds\\走路要看路啊.wav");
		CAudio::Instance()->Load(27, "sounds\\談戀愛很屌是啊.wav");
		CAudio::Instance()->Load(28, "sounds\\嘿嘿.wav");

	}

	void CHotGirl::ResetShow()
	{
		RlayDownGirl.Reset();
		RlayDownGirl.SetDelayCount(3);
		LlayDownGirl.Reset();
		LlayDownGirl.SetDelayCount(3);
	}

	void CHotGirl::IsLayDown()
	{
		if (RlayDownGirl.IsFinalBitmap())			//若撥到跌倒動畫的最後一張圖
		{											//設定現在不是跌倒
			isLayDown = false;
			this->SetMode(currentMode);
		}
		else if (LlayDownGirl.IsFinalBitmap())
		{
			isLayDown = false;
			this->SetMode(currentMode);
		}
		else
		{
			isLayDown = true;						//否則現在是跌倒
		}
	}

	bool CHotGirl::GetIsLayDown()
	{
		return isLayDown;
	}

	void CHotGirl::OnMove(SchoolMap *m)
	{
		int STEP_SIZE = 10;		  //移動速度絕對!不能改
		const int X_POS = 450;	  //移動時女主角在畫面中的x位置

		RhotGirl.OnMove();		  //撥放女主角所有模式的圖形動畫
		LhotGirl.OnMove();	
		WLhotGirl.OnMove();	
		WRhotGirl.OnMove();
		PKGirl.OnMove();
		LlayDownGirl.OnMove();
		RlayDownGirl.OnMove();
		LFrightenedGirl.OnMove();
		RFrightenedGirl.OnMove();
		LLaughGirl.OnMove();
		RLaughGirl.OnMove();
		FinalLlayDownGirl.OnMove();
		FinalRlayDownGirl.OnMove();
		

		floor_start = 0;							//分類每個樓層的起始跟結束座標
		floor_end = 0;				
		if (floorNum == 1) {
			floor_start = 0, floor_end = 4920;
		}else if (floorNum == 2) {
			floor_start = 4920, floor_end = 9840;
		}else if (floorNum == 3) {
			floor_start = 9840, floor_end = 14760;
		}else if (floorNum == 4) {
			floor_start = 14760, floor_end = 19680;
		}

		if (isInvincible == true) {					//判斷現在是不是無敵
			STEP_SIZE = 15;							//是的話加快移動速度
		}
		else {										//不是就正常速度
			STEP_SIZE = 10;
		}
		
		/*_________________________________________________女主角的基本移動_______________________________________________________*/

		if (isMovingLeft && this->mode == 3)		//若女主角要往左邊走
		{
			//螢幕是否開始移動是根據角色的座標是否在螢幕中間, 螢幕是否結束移動是根據螢幕的座標是否超過地圖
			if ((x - STEP_SIZE) >= floor_start+210) {					  //人物限制 ,樓梯寬度210
				x -= STEP_SIZE;
				if (x < floor_end-1024+X_POS && m->getSx()>floor_start) { //地圖限制 //人物 , 地圖
					m->SetSx(x - X_POS);
				}
					

				for (unsigned int i = follower.size(); i > 0; i--) {

					follower[i - 1]->SetMode(7);						//跟隨者面對左邊
					if (i == follower.size()) {
						follower[i - 1]->SetXY(x + 110, y);				//設第一個跟隨者跟著女主角移動
					}
					else {												//設後面的跟隨者跟著前一個跟隨者移動
						follower[i - 1]->SetXY(follower[i]->GetX1() + 90, y);
					}
				}
			}
			currentMode = 1;
		}
		else if (isMovingRight && this->mode == 4)							//若女主角要往右邊走
		{
			if (x + STEP_SIZE <= floor_end-120-210) {	//4380 = 4500 - 圖片寬度 ,人物寬度120-樓梯寬度210
				x += STEP_SIZE;
				if (x > floor_start+X_POS && m->getSx() < floor_end-1024) { //地圖限制 //人物, 地圖
					m->SetSx(x - X_POS);
				}
			}

			for (unsigned int i = follower.size(); i > 0; i--) {
				follower[i - 1]->SetMode(8);						//跟隨者面對右邊
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x - 90, y);				//設第一個跟隨者跟著女主角移動
				}
				else {												//設後面的跟隨者跟著前一個跟隨者移動
					follower[i - 1]->SetXY(follower[i]->GetX1() - 90, y);
				}
			}

			currentMode = 2;

		}

		/*__________________________________________判斷女主角是否碰到地上愛心________________________________________________*/
		for (unsigned int i = 0; i < hearts.size(); i++)
		{
			if (isPK == false) {
				if (hearts[i]->GetX1() + 25 <= GetX2() && hearts[i]->GetX2() - 25 >= x)	//如果女主角碰到掉在地上的愛心
				{
					CAudio::Instance()->Play(AUDIO_HEART, false);
					this->total_score = this->total_score + hearts[i]->GetScore(); //得到這顆愛心價值的分數
					this->energy_score = this->energy_score + hearts[i]->GetSmallEnergy();	//得到這顆愛心價值的小愛心分數
					CHeart *pointer;
					pointer = hearts[i];
					hearts.erase(hearts.begin() + i);							//刪除愛心
					delete pointer;
					pointer = NULL;
					break;
				}
			}
			else {
				if (hearts[i]->GetX1() + 30 <= GetX2() && hearts[i]->GetX2() - 30 >= x)	//如果女主角碰到掉在地上的愛心
				{
					CAudio::Instance()->Play(AUDIO_HEART, false);
					this->total_score = this->total_score + hearts[i]->GetScore(); //得到這顆愛心價值的分數
					this->energy_score = this->energy_score + hearts[i]->GetSmallEnergy();	//得到這顆愛心價值的小愛心分數
					CHeart *pointer;
					pointer = hearts[i];
					hearts.erase(hearts.begin() + i);							//刪除愛心
					delete pointer;
					pointer = NULL;
					break;
				}
			}
		}

		/*________________________________________________________________________________________________________________*/

		
		


		if (isShotting == true && isLocked == true)	//如果有鎖定目標並且按下空白
		{
			LoadingBullet(m);						//就裝填子彈
		}



		if (isLayDown == true)						//判斷現在是不是跌倒
		{	
			IsLayDown();
		}

		
		
		if (this->energy_score >= 800) {										//如果左上角的愛心分數大於800
			isInvincible = true;												//進入無敵模式
			if (isHaveInvincible == false) {									//若還沒進入過無敵模式
				isHaveInvincible = true;										//紀錄有進入過無敵模式
			}
			if (isPlayInvincibleAUDIO == false) {								//若無敵音樂還沒有被放過
				isPlayInvincibleAUDIO = true;
				CAudio::Instance()->Play(AUDIO_TOKYO,false);					//就放無敵音樂
				CAudio::Instance()->Play(AUDIO_TRANSFORM, false);
			}
		}

		//判斷女主角是否碰到樓梯
		if (floor_start + 195 <= this->GetX1() && this->GetX1() < floor_start + 225) {
			isTouchStair = true;
			TouchStairLR = 1;
		}
		else if (floor_end - 225 <= this->GetX2() && this->GetX2() < floor_end - 195) {
			isTouchStair = true;
			TouchStairLR = 2;
		}
		else {
			isTouchStair = false;
		}

	}

	void CHotGirl::OnShow(SchoolMap *m,CTeacher *teacher)
	{

		if (follower.empty() == false)								//如果跟隨者vector不是空的
		{
			if (!IsPK()) {
				for (unsigned int i = 0; i < follower.size(); i++)
				{
					follower[i]->OnShow(m);							//才列印vector的人物
				}
			}
		}

		if (isPK == false) {
			teacher->OnShow(m);										//老師的顯示
		}


		if (this->mode == 1)			//左邊站著
		{
			LhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			LhotGirl.OnShow();
		}
		else if (this->mode == 2)		//右邊站著
		{
			RhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			RhotGirl.OnShow();
		}
		else if (this->mode == 3)		//左邊走路
		{
			WLhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			WLhotGirl.OnShow();
		}
		else if (this->mode == 4)		//右邊走路
		{
			WRhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			WRhotGirl.OnShow();
		}
		else if (this->mode == 5)		//左邊抬頭
		{
			ULhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			ULhotGirl.OnShow();
		}
		else if (this->mode == 6)		//右邊抬頭
		{
			URhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			URhotGirl.OnShow();
		}
		else if (this->mode == 7)		//左邊低頭
		{
			DLhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			DLhotGirl.OnShow();
		}
		else if (this->mode == 8)		//右邊低頭
		{
			DRhotGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			DRhotGirl.OnShow();
		}
		else if (this->mode == 9)		//PK模式
		{
			PKGirl.SetTopLeft(-60, 100);	
			PKGirl.OnShow();
		}
		else if (this->mode == 11)		//左邊跌倒
		{
			LlayDownGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y)-35);
			LlayDownGirl.OnShow();
		}
		else if (this->mode == 12)		//右邊跌倒
		{
			RlayDownGirl.SetTopLeft(m->ScreenX(x)-250, m->ScreenY(y)-35);
			RlayDownGirl.OnShow();
		}
		else if (this->mode == 13)		//左邊被嚇到
		{
			LFrightenedGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y)-10);
			LFrightenedGirl.OnShow();
		}
		else if (this->mode == 14)		//右邊被嚇到
		{
			RFrightenedGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y)-10);
			RFrightenedGirl.OnShow();
		}
		else if (this->mode == 15)		//左邊笑著走
		{
			LLaughGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y)-20);
			LLaughGirl.OnShow();
		}
		else if (this->mode == 16)		//右邊笑著走
		{
			RLaughGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y)-20);
			RLaughGirl.OnShow();
		}
		else if (this->mode == 17)		//最後面向左邊跌倒
		{
			FinalLlayDownGirl.SetTopLeft(m->ScreenX(x), m->ScreenY(y) - 35);
			FinalLlayDownGirl.OnShow();
		}
		else if (this->mode == 18)		//最後面向右邊跌倒
		{
			FinalRlayDownGirl.SetTopLeft(m->ScreenX(x) - 250, m->ScreenY(y) - 35);
			FinalRlayDownGirl.OnShow();
		}


		

		if (hearts.empty() == false)	//所有愛心的顯示
		{
			for (unsigned int i = 0; i < hearts.size(); i++)
			{
				hearts[i]->OnShow(m);
			}
		}

		
		if (PKbitchies.empty() == false)												//PK條顯示設定
		{
			if (PKline == NULL && newNumber == 0)										//若還沒有PK條
			{																			//就新增PK條並給予座標、PK條能量

				if (isInvincible == true)												//如果現在是無敵模式
				{
					AttackedBoy->SetEnergy(80);											//魯蛇的愛心能量改成從60開始	
				}

				PKline = new CPKline(325, 196, this->AttackedBoy->GetEnergy());			//新增一條pk條，從中間開始pk
				PKline->LoadBitmap();
			}



			if (isPK == true) {										//PK模式的顯示跟排列
				if (PKbitchies.size() == 1)							//若一個敵人搶
				{
					PKbitchies[0]->SetPKPosition(720, 100);
				}
				else if (PKbitchies.size() == 2)					//兩個敵人搶
				{
					PKbitchies[0]->SetPKPosition(660, 80);
					PKbitchies[1]->SetPKPosition(810, 140);
				}
				else if (PKbitchies.size() == 3)					//三個敵人搶
				{
					PKbitchies[0]->SetPKPosition(650, 70);
					PKbitchies[1]->SetPKPosition(810, 170);
					PKbitchies[2]->SetPKPosition(600, 260);
				}
				else if (PKbitchies.size() == 4)					//四個敵人搶
				{
					PKbitchies[0]->SetPKPosition(650, 70);
					PKbitchies[1]->SetPKPosition(830, 60);
					PKbitchies[2]->SetPKPosition(600, 260);
					PKbitchies[3]->SetPKPosition(840, 250);
				}
			}
		}

		for (auto bitch : PKbitchies) {
			if (isPK == true)
			{
				if (PKline == NULL)							//若還沒有PK條
				{											//就新增PK條並給予座標、PK條能量
					PKline = new CPKline(325, 196, this->AttackedBoy->GetEnergy());

					PKline->LoadBitmap();
				}
				StartPK(m);
			}
		}
	}

	void CHotGirl::SetMode(int mode)
	{
		this->mode = mode;
	}

	int CHotGirl::GetMode()
	{
		return this->mode;
	}

	void CHotGirl::LockSnake(CLuSnake *lusnake, SchoolMap *m) {
		for (int i = 0; i < 27; i++) {
			if (i != 26 || (i == 26 && isHaveInvincible == true)) {		//若大帥哥已經出現，可以偵測大帥哥
				if (lusnake[i].GetX1() >= m->getSx() && lusnake[i].GetX2() <= m->getSx() + 1024
					&& lusnake[i].GetIsPkLose() == false) //判斷人物是否在顯示螢幕上且這個魯蛇還沒pk結束
				{
					if (this->GetMode() == 5)							//女生面對左上方
					{
						if (lusnake[i].GetX2() < this->GetX1() && lusnake[i].GetY2() < this->GetY2()) { //撸蛇是否在左上方
							if (lusnake[i].GetEnergy() < 120) {			//若魯蛇愛心能量還沒滿(未被俘虜)就可以被鎖定
								lusnake[i].SetMode(2);
								lusnake[i].SetMovingLeft(false);
								lusnake[i].SetMovingRight(false);
								this->Bx = lusnake[i].GetX1();			//紀錄被鎖定的撸蛇座標
								this->By = lusnake[i].GetY1();
								AttackedBoy = NULL;
								this->AttackedBoy = &lusnake[i];	//紀錄AttackedBoy為被鎖定的魯蛇
								isLocked = true;
								break;
							}
						}
					}
					else if (this->GetMode() == 7) {			//女生面對左下方
						if (lusnake[i].GetX2() < this->GetX1() && lusnake[i].GetY2() > this->GetY2()) { //撸蛇是否在左下方
							if (lusnake[i].GetEnergy() < 120) {	//若魯蛇愛心能量還沒滿(未被俘虜)就可以被鎖定
								lusnake[i].SetMode(2);
								lusnake[i].SetMovingLeft(false);
								lusnake[i].SetMovingRight(false);
								this->Bx = lusnake[i].GetX1();
								this->By = lusnake[i].GetY1();
								AttackedBoy = NULL;
								this->AttackedBoy = &lusnake[i];	//紀錄AttackedBoy為被鎖定的魯蛇
								isLocked = true;
								break;
							}
						}
					}
					else if (this->GetMode() == 6) {				//女生面對右上方
						if (lusnake[i].GetX2() > this->GetX1() && lusnake[i].GetY2() < this->GetY2()) { //撸蛇是否在右上方
							if (lusnake[i].GetEnergy() < 120) {		//若魯蛇愛心能量還沒滿(未被俘虜)就可以被鎖定
								lusnake[i].SetMode(1);
								lusnake[i].SetMovingLeft(false);
								lusnake[i].SetMovingRight(false);
								this->Bx = lusnake[i].GetX1();
								this->By = lusnake[i].GetY1();
								AttackedBoy = NULL;
								this->AttackedBoy = &lusnake[i];	//紀錄AttackedBoy為被鎖定的魯蛇
								isLocked = true;
								break;
							}
						}
					}
					else if (this->GetMode() == 8) {			//女生面對右下方
						if (lusnake[i].GetX2() > this->GetX1() && lusnake[i].GetY2() > this->GetY2()) { //撸蛇是否在右下方
							if (lusnake[i].GetEnergy() < 120) {	//若魯蛇愛心能量還沒滿(未被俘虜)就可以被鎖定
								lusnake[i].SetMode(1);
								lusnake[i].SetMovingLeft(false);
								lusnake[i].SetMovingRight(false);
								this->Bx = lusnake[i].GetX1();
								this->By = lusnake[i].GetY1();
								AttackedBoy = NULL;
								this->AttackedBoy = &lusnake[i];	//紀錄AttackedBoy為被鎖定的魯蛇
								isLocked = true;
								break;
							}
						}
					}
				}
			}
		}
	}

	void CHotGirl::UnLockSnake(CLuSnake *lusnake, SchoolMap *m) { //解鎖撸蛇鎖定
		if (this->AttackedBoy != NULL) {
			if (this->AttackedBoy->GetEnergy() < 120 || this->AttackedBoy->GetIsPkLose() == false) {	//若魯蛇愛心能量還沒滿(未被俘虜)就可以被解鎖
				for (int i = 0; i < 27; i++) {
					if (lusnake[i].GetMode() == 1) {			  //判斷是否有被鎖定的撸蛇面向左邊
						lusnake[i].SetMode(3);
						lusnake[i].SetMovingLeft(true);
						break;
					}
					else if (lusnake[i].GetMode() == 2) {		  //判斷是否有被鎖定的撸蛇面向右邊
						lusnake[i].SetMode(4);
						lusnake[i].SetMovingRight(true);
						break;
					}
				}
				isLocked = false;
			}
		}
	}

	void CHotGirl::LoadingBullet(SchoolMap *m)	//裝填子彈到bullets的vector裡面
	{
		bullets.push_back(new GirlBullet(x, y, Bx, By));
	}

	void CHotGirl::SetShotting(bool flag)		//設定是否射擊
	{
		isShotting = flag;
		if (isShotting == true) {
			CAudio::Instance()->Play(AUDIO_LASER,true); //重複播放涉及音效
		}
	}

	bool CHotGirl::IsShotting()
	{
		return isShotting;
	}

	bool CHotGirl::IsBulletEmpty()
	{
		return bullets.empty();
	}

	void CHotGirl::AttackLusnake(bool start) {
		if (start == true) {																	//若魯蛇被攻擊
			if (this->AttackedBoy->GetMode() == 1 || this->AttackedBoy->GetMode() == 3) {		//若魯蛇面向左邊
				this->AttackedBoy->SetMovingLeft(false);
				this->AttackedBoy->SetMode(5);													//魯蛇狀態改為被攻擊
			}
			else if (this->AttackedBoy->GetMode() == 2 || this->AttackedBoy->GetMode() == 4) {	//若魯蛇面向右邊
				this->AttackedBoy->SetMovingRight(false);
				this->AttackedBoy->SetMode(6);													//魯蛇狀態改為被攻擊
			}
		}
		else {												//若魯蛇被解除攻擊
			if (this->AttackedBoy->GetMode() == 5) {		//若魯蛇面向左邊
				this->AttackedBoy->SetMode(3);				//魯蛇狀態改為左邊走路
				this->AttackedBoy->SetMovingLeft(true);
			}
			else if (this->AttackedBoy->GetMode() == 6) {	//若魯蛇面向右邊
				this->AttackedBoy->SetMode(4);				//魯蛇狀態改為右邊走路
				this->AttackedBoy->SetMovingRight(true);
			}


		}
	}

	void CHotGirl::BitchSensor(CBitch * bitch, SchoolMap * m)
	{
		for (int i = 0; i < 17; i++)
		{																					 ////若是外國女生，女主角必須無敵過且目標是外國大帥哥才能偵測
			if (i != 16 || (i == 16 && isHaveInvincible == true && this->AttackedBoy->GetScore()==25000)) {							
				if (bitch[i].GetX1() >= m->getSx() && bitch[i].GetX2() <= m->getSx() + 1024) //判斷人物是否在顯示螢幕上
				{
					this->PKbitch = NULL;
					bitch[i].SetSensor(true);
					bitch[i].SetMovingLeft(false);
					bitch[i].SetMovingRight(false);
					if (bitch[i].GetX1() < AttackedBoy->GetX1() - 72)	//Bitch 是否在撸蛇左方
					{
						this->PKbitch = &bitch[i];
						bitch[i].SetMode(5);
						bitch[i].SetShowCount();
						bitch[i].SetBeforePKmode(2);
					}
					else	//Bitch 是否在撸蛇右方
					{
						this->PKbitch = &bitch[i];
						bitch[i].SetMode(6);
						bitch[i].SetShowCount();
						bitch[i].SetBeforePKmode(1);
					}
				}
			}		
		}
	}


	void CHotGirl::TrunAttackMode(CBitch * bitch, SchoolMap * m)
	{	
		if (isInvincible == false) {						//如果不是無敵模式
			if (this->AttackedBoy->GetEnergy() >= 120) {	//若偵測跑完之前就擄獲魯蛇，婊子狀態改回走路
				bitch->SetMode(3);
				bitch->SetMovingLeft(true);
			}
		}
		if (isLayDown == false) {							//如果沒有被撞倒就可進入pk模式
			if (bitch->GetMode() == 5 || bitch->GetMode() == 6) {
				CAudio::Instance()->Play(AUDIO_LIGHTING, false);
				this->isShotting = false;					//女主角就停止射擊
				this->isLocked = false;
				for (auto elementPtr : bullets)				//並把剩餘子彈刪除
				{
					delete elementPtr;
				}
				bullets.clear();

				delete heart;								//刪除愛心
				heart = NULL;

			
				bitch->SetMode(7);							//改為敵人pk時的狀態	
				if (mode == 1 || mode == 5 || mode == 7)	//紀錄當前狀態
				{
					currentMode = 1;
				}
				else if (mode == 2 || mode == 6 || mode == 8)
				{
					currentMode = 2;
				}

			
				this->SetMode(9);							//女主角改為pk狀態
				this->AttackedBoy->SetMode(9);				//魯蛇改為pk被射狀態
				PKbitchies.push_back(bitch);				//把這個bitch加入"處於pk模式的婊子們"
				isPK = true;								//進入pk模式
			}
		}
	}


	bool CHotGirl::IsLocked()
	{
		return isLocked;
	}

	void CHotGirl::AddFollower(SchoolMap *m) {

		if (this->currentMode == 1) {					//若女主角面對左邊
			for (unsigned int i = follower.size(); i > 0; i--) {
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x + 110, y);	//設最後一項(新加入的跟隨者)跟在女主角後面
				}
				else {									//若有兩位以上，調整後面跟隨者的位置
					follower[i - 1]->SetXY(follower[i]->GetX1() + 90, y);
				}
				follower[i - 1]->OnShow(m);

			}
		}
		else if (this->currentMode == 2) {				//若女主角面對右邊
			for (unsigned int i = follower.size(); i > 0; i--) {
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x - 90, y);	//設最後一項(新加入的跟隨者)跟在女主角後面
				}
				else {									//若有兩位以上，調整後面跟隨者的位置
					follower[i - 1]->SetXY(follower[i]->GetX1() - 90, y);
				}
				follower[i - 1]->OnShow(m);
			}
		}
	}

	void CHotGirl::ShowBullet(SchoolMap *m)	//子彈發射動畫
	{
		this->PKbitch = NULL;
		for (unsigned int i = 0; i < bullets.size(); i++)
		{
			bullets[i]->LoadBitmap(); //載入圖片
			bullets[i]->OnShow(m);	//映出圖片
			bullets[i]->OnMove(m);	//移動子彈
		}
		for (unsigned int i = 0; i < bullets.size(); i++)
		{
			if (bullets[0]->IsFinished())		//若第一顆子彈打到人
			{
				/*________________________________子彈控制________________________________*/
				GirlBullet *pointer;
				pointer = bullets[0];
				bullets.erase(bullets.begin());	//第一顆子彈消失
				delete pointer;
				pointer = NULL;

				/*____________________________腳色狀態、愛心控制___________________________*/
				AttackLusnake(true);							//魯蛇變成被攻擊狀態

				if (isInvincible == true && this->AttackedBoy->GetScore()!= 25000) {	//若在無敵時間，且男生不是外國大帥哥
					this->AttackedBoy->InvincibleAddEnergy();	//魯蛇的愛心能量就增加超快
				}
				else {
					this->AttackedBoy->AddEnergy();				//魯蛇的愛心能量就增加
				}
				
				
				
				this->total_score = this->total_score + 1;		//增加得到的總分,射完可得到24分(120/5)
				this->energy_score = this->energy_score - 1;
				if (heart == NULL)								//若還沒有愛心
				{												//就新增愛心並給予座標、愛心能量、價值分數
					heart = new CHeart(this->AttackedBoy->GetX1() + 15, this->AttackedBoy->GetY1() - 40,
						this->AttackedBoy->GetEnergy(), this->AttackedBoy->GetScore(), 80);

					heart->LoadBitmap();
					heart->OnShow(m);							//顯示愛心
				}
				else {											//如果已經有愛心
					heart->SetHeartLoveEnergy(this->AttackedBoy->GetEnergy());	//更新愛心能量
					heart->OnShow(m);											//顯示愛心
					if (heart->IsEnergyFull() == true) {						//若愛心能量集滿了
						CAudio::Instance()->Stop(AUDIO_LASER);					//停止射擊音效
						this->isShotting = false;								//就停止射擊
						this->isLocked = false;
						for (auto elementPtr : bullets)							//並把剩餘子彈刪除
						{
							delete elementPtr;
						}
						bullets.clear();

						if (this->mode % 2 != 0) {								//魯蛇狀態變為跟隨者
							this->AttackedBoy->SetMode(7);
						}
						else if (this->mode % 2 == 0) {
							this->AttackedBoy->SetMode(8);
						}
						follower.push_back(this->AttackedBoy);					//把這個魯蛇加入跟隨者vecctor
						AddFollower(m);											//將跟隨者的位置改到女主角後面
						CAudio::Instance()->Play(AUDIO_SCREAM, false);			//魯蛇慘叫
					}
					else {
						if (isLayDown == true) {
         					CAudio::Instance()->Stop(AUDIO_LASER);				//停止射擊音效
							this->isShotting = false;							//就停止射擊
							this->isLocked = false;								//解除鎖定
        					this->isPK = false;									//解除PK
							for (auto elementPtr : bullets)						//並把剩餘子彈刪除
							{
								delete elementPtr;
							}
							bullets.clear();
						}
					}
				}
			}
			break;
		}

		if (bullets.empty()) {							//當子彈打完
			CAudio::Instance()->Stop(AUDIO_LASER);		//停止射擊音效
			AttackLusnake(false);						//魯蛇解除被攻擊狀態
			if (AttackedBoy->GetEnergy() < 120)			//若愛心沒了
			{
				delete heart;							//刪除愛心
				heart = NULL;
			}
			else
			{
				hearts.push_back(heart);				//不然就加到愛心集合
				heart = NULL;
			}

			if (this->PKbitch != NULL) {
				if (this->PKbitch->GetMode() == 5 || this->PKbitch->GetMode() == 6) {	//若還沒進入偵測模式子彈就打完
					isPK = false;						//女主角、敵人女生回到正常狀態
					this->PKbitch->SetMode(3);
					this->SetMode(1);
					this->AttackedBoy->SetMode(6);
					this->PKbitch->SetMovingLeft(true);
					this->PKbitch = NULL;
				}
			}

		}
	}

	void CHotGirl::StartPK(SchoolMap * m) {
		int bitchies_num = PKbitchies.size();
		PKcount++;					//用來設計pk難度的counter

		if (bitchies_num == 1) {	//PKcount數到2才減pkLine的值
			if (PKbitchies[0]->GetIsForeign() == false) {						
				if (PKcount % 2 == 0)this->AttackedBoy->EnergyReduction();		//魯蛇的pk條能量就減少一次	
			}else {																//若是外國婊子，難度更難一點
				this->AttackedBoy->EnergyReduction();							//魯蛇的pk條能量就減少一次	
			}
		}
		else if (bitchies_num == 2) {//PKcount數到3才減pkLine的值，但同時有2人在打
			if (PKcount %3 == 0)this->AttackedBoy->EnergyReduction();			//魯蛇的pk條能量就減少一次	
		}
		else if (bitchies_num == 3) {//PKcount數到3才減pkLine的值，但同時有3人在打
			if (PKcount % 3 == 0)this->AttackedBoy->EnergyReduction();			//魯蛇的pk條能量就減少一次	
		}
		else if (bitchies_num == 4) {//PKcount數到3才減pkLine的值，但同時有4人在打
			if (PKcount % 3 == 0)this->AttackedBoy->EnergyReduction();			//魯蛇的pk條能量就減少一次	
		}
		



		PKline->SetLineEnergy(this->AttackedBoy->GetEnergy());	//更新PK條能量
		if (PKline->IsEnergyFull() == true) {					//若PK條能量集滿了(PK贏了)
			if (this->mode % 2 != 0) {							//魯蛇狀態變為跟隨者
				this->AttackedBoy->SetMode(7);
			}
			else if (this->mode % 2 == 0) {
				this->AttackedBoy->SetMode(8);
			}

			if (this->AttackedBoy->GetScore() == 500) {
				heart = new CHeart(this->AttackedBoy->GetX1() + 15, this->AttackedBoy->GetY1() - 40, 121, 1000, 160);
			}else{
				heart = new CHeart(this->AttackedBoy->GetX1() + 15, this->AttackedBoy->GetY1() - 40, 121, this->AttackedBoy->GetScore(), 160);
			}
			
			heart->LoadBitmap();
			heart->SetIsPKfull(true);
			hearts.push_back(heart);
			heart = NULL;

			follower.push_back(this->AttackedBoy);							//把這個魯蛇加入跟隨者vecctor
			AddFollower(m);													//將跟隨者的位置改到女主角後面



			for (auto bitch : PKbitchies)									//改變女主角以及婊子的狀態
			{
				this->SetMode(currentMode);									//女主角面向原始方向
				for (unsigned int i = follower.size(); i > 0; i--) {
					if (currentMode == 1)
					{
						follower[i - 1]->SetMode(7);						//跟隨者也跟著面向左邊
					}
					else if (currentMode == 2)
					{
						follower[i - 1]->SetMode(8);						//跟隨者也跟著面向右邊
					}
				}


				if (bitch->GetBeforePKmode() == 1) {						//若婊子pk前是面對左邊
					bitch->SetMode(1);
   					bitch->SetMoveMode(3);									//move模式改為右上飛天
					bitch->SetShowCount();
				}
				else if (bitch->GetBeforePKmode() == 2) {					//若婊子pk前是面對右邊
					bitch->SetMode(2);
					bitch->SetMoveMode(4);									//move模式改為左上飛天
					bitch->SetShowCount();
				}

				bitch = NULL;
				CAudio::Instance()->Stop(AUDIO_LASER);						//停止射擊音效
				CAudio::Instance()->Play(AUDIO_PK);							//播放PK贏的音效
				CAudio::Instance()->Play(AUDIO_SCREAM, false);				//魯蛇慘叫
			}

			delete PKline;
			PKline = NULL;
			PKbitchies.clear();
			isPK = false;
			PKcount = 0;
		}
		else {//------------------------------------------------------------------------------
			if (PKline->getEnergy() <= 0) {								//若PK輸了
				this->energy_score = this->energy_score - 120;

				CBitch* ClosetRbitch,* ClosetLbitch,*Leaderbitch;		
				int Ldifer, Rdifer,MinLdifer=1000, MinRdifer=1000;
				for (auto bitch : PKbitchies)							//改變女主角魯蛇以及婊子的狀態
				{
					Ldifer = bitch->GetX1() - m->getSx();				//婊子離左邊牆的距離
					Rdifer = (m->getSx() + 1024) - bitch->GetX2();		//婊子離右邊牆的距離

					if (Ldifer < MinLdifer) {							//若離左邊牆的距離 比 最小離左邊牆距離還小的話
						MinLdifer = Ldifer;								//更新最小離左邊牆距離
						ClosetLbitch = bitch;							//取得最靠近左邊的婊子
					}

					if (Rdifer < MinRdifer) {							//若離右邊牆的距離 比 最小離右邊牆距離還小的話
						MinRdifer = Rdifer;								//更新最小離右邊牆距離
						ClosetRbitch = bitch;							//取得最靠近右邊的婊子
					}
				}
				
				if (MinLdifer <= MinRdifer) {							//取得領導婊子
					Leaderbitch = ClosetLbitch;
					ClosetLbitch = NULL;
				}else {
					Leaderbitch = ClosetRbitch;
					ClosetRbitch = NULL;
				}

				for (auto bitch : PKbitchies)							//改變女主角魯蛇以及婊子的狀態
				{
					bitch->SetMoveMode(2);								//設定move模式為pk贏了
					if (Leaderbitch->GetX1() > m->getSx() + 512) {		//若領導婊子在螢幕右半邊
						bitch->SetMovingRight(true);					//婊子往右走
						bitch->SetMode(14);
						bitch->SetShowCount();
						this->AttackedBoy->SetMovingRight(true);		//魯蛇也往右走
					}else {												//若領導婊子在螢幕左半邊
						bitch->SetMovingLeft(true);						//婊子往左走
						bitch->SetMode(13);
						bitch->SetShowCount();
						this->AttackedBoy->SetMovingLeft(true);			//魯蛇也往左走
					}

					bitch = NULL;
				}	Leaderbitch= NULL;


				if (currentMode == 1)									//跌倒狀態判斷
				{
					this->SetMode(11);
					ResetShow();
					isLayDown = true;
				}
				else if (currentMode == 2)
				{
					this->SetMode(12);
					ResetShow();
					isLayDown = true;
				}
				for (unsigned int i = follower.size(); i > 0; i--) {
					if (currentMode == 1)
					{
						follower[i - 1]->SetMode(7);					//跟隨者也跟著面向左邊
					}
					else if (currentMode == 2)
					{
						follower[i - 1]->SetMode(8);					//跟隨者也跟著面向右邊
					}
				}
				CAudio::Instance()->Stop(AUDIO_LASER);					//停止射擊音效
				CAudio::Instance()->Play(AUDIO_PK);						//播放PK輸的音效
				CAudio::Instance()->Play(AUDIO_SCREAM, false);			//魯蛇慘叫


				this->AttackedBoy->SetIsPkLose(true);					//魯蛇離開地圖


				PKbitchies.clear();
				delete PKline;								//刪除pk條
				PKline = NULL;
				isPK = false;								//解除PK狀態
				PKcount = 0;
			}
		}
	}

	void CHotGirl::ShowPKLine(SchoolMap * m)
	{
		if (PKline != NULL)				//若要pk條存在
		{
			PKline->OnMove();
			PKline->OnShow(m);			//顯示pk條
		}
	}

	void CHotGirl::ComboPK(SchoolMap *m) {
		if (isInvincible == true && this->AttackedBoy->GetScore() != 25000) {	//如果在無敵狀態且目標不是外國帥哥的話
			this->AttackedBoy->InvincibleComboAddEnergy();						//超快增加pk條的能量
		}else {
			this->AttackedBoy->ComboAddEnergy();								//增加pk條的能量
		}

		this->total_score = this->total_score + 3;								//增加得到的總分,射完可得到24分(120/5)
		this->energy_score = this->energy_score - 1;
	}

	void CHotGirl::ShowPKPeople(SchoolMap *m)
	{
		AttackedBoy->OnShow(m);				//印出PK時的男生
		for (auto bitch : PKbitchies) {		//印出PK時的女生敵人
			bitch->OnShow(m);
		}
	}

	void CHotGirl::IsTouchTeacher(CTeacher * teacher)
	{	
		if (teacher->GetX1() + 30 <= GetX2() && teacher->GetX2() - 30 >= x) {
			if (teacher->GetisTouch() == false) {
				CAudio::Instance()->Play(AUDIO_PK);
				if (isShotting == false) {								//若是一般走路
					CAudio::Instance()->Play(AUDIO_TEACHERYELL1);		//老師:走路要看路阿!!
				}
				else {													//若正在射擊
					CAudio::Instance()->Play(AUDIO_TEACHERYELL2);		//老師:談戀愛很屌是阿!!
				}
				
				CAudio::Instance()->Stop(AUDIO_LASER);
				this->energy_score = this->energy_score - 120;			//扣兩顆愛心
				teacher->SetisTouch(true);

				if (currentMode == 1)
				{
					this->SetMode(11);
					ResetShow();
					isLayDown = true;
				}
				else if (currentMode == 2)
				{
					this->SetMode(12);
					ResetShow();
					isLayDown = true;
				}

			}
		}
		else {
			teacher->SetisTouch(false);
		}
	}


	bool CHotGirl::IsHeartEmpty()
	{
		return hearts.empty();
	}

	int CHotGirl::GetBitScore(int bit_number) {

		if (bit_number == 1) {			//若想要第一位的數字的話
			return total_score % 10;
		}
		else if (bit_number == 2) {
			return total_score % 100 / 10;
		}
		else if (bit_number == 3) {
			return total_score % 1000 / 100;
		}
		else if (bit_number == 4) {
			return total_score % 10000 / 1000;
		}
		else if (bit_number == 5) {
			return total_score % 100000 / 10000;
		}
		else if (bit_number == 6) {
			return total_score % 1000000 / 100000;
		}
		else if (bit_number == 7) {
			return total_score % 10000000 / 1000000;
		}
		else {
			return total_score % 100000000 / 10000000;
		}
	}

	int CHotGirl::GetTotalScore()
	{
		return total_score;
	}


	int CHotGirl::GetEnergyScore() {

		return energy_score;
	}
	

	void CHotGirl::SetEnergyScore(int score)
	{
		this->energy_score = score;
	}


	void CHotGirl::MoveHearts(SchoolMap *m)
	{
		for (unsigned int i = 0; i < hearts.size(); i++)
		{
			if (!hearts[i]->IsFinish())
			{
				hearts[i]->OnMove(m, By - 110, y + 135);
			}
		}
	}

	bool CHotGirl::IsPK() {
		return isPK;
	}

	void CHotGirl::SetIsPK(bool ispk)
	{
		isPK = ispk;
	}
	
	bool CHotGirl::GetIsInvincible()
	{
		return isInvincible;
	}

	void CHotGirl::SetIsInvincible(bool flag)
	{
		isInvincible = flag;
	}

	void CHotGirl::SetisPlayInvincibleAUDIO(bool flag)
	{
		isPlayInvincibleAUDIO = flag;
	}

	bool CHotGirl::GetIsTouchStair()
	{
		return isTouchStair;
	}

	int CHotGirl::GetTouchStairLR()
	{
		return TouchStairLR;
	}
	
	void CHotGirl::DemoAddEnergy()
	{
		energy_score += 80;
	}

	void CHotGirl::DemoMinusEnergy()
	{
		energy_score -= 80;
	}


	int CHotGirl::GetFloor()
	{
		return floorNum;
	}

	void CHotGirl::UpFloor(SchoolMap * m)
	{	
		if (floorNum < 4) {
			floorNum++;
			if (x < 4920 * (floorNum - 2) + 300) {				//若從左邊上樓
				x = 4920 * (floorNum - 1) + 210;		
				m->SetSx(4920 * (floorNum - 1));
				SetMode(1);
			}else if (GetX2() >= 4920 * (floorNum-1) - 300) {	//若從右邊上樓
				x = 4920 * floorNum - 210- RhotGirl.Width();
				m->SetSx(4920 * floorNum -1024);
				SetMode(2);
			}
		}
		
		
		if (mode == 1) {
			for (unsigned int i = follower.size(); i > 0; i--) {
									follower[i - 1]->SetMode(7);	//跟隨者面對左邊
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x + 110, y);				//設第一個跟隨者跟著女主角移動
				}
				else {												//設後面的跟隨者跟著前一個跟隨者移動
					follower[i - 1]->SetXY(follower[i]->GetX1() + 90, y);
				}
			}
		}else if (mode == 2) {
			for (unsigned int i = follower.size(); i > 0; i--) {
				follower[i - 1]->SetMode(8);						//跟隨者面對右邊
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x - 90, y);				//設第一個跟隨者跟著女主角移動
				}
				else {												//設後面的跟隨者跟著前一個跟隨者移動
					follower[i - 1]->SetXY(follower[i]->GetX1() - 90, y);
				}
			}
		}
	}

	void CHotGirl::DownFloor(SchoolMap * m)
	{
		if (floorNum > 1) {
			floorNum--;
			if (x < 4920 * floorNum  + 300) {					//若從左邊下樓
				x = 4920 * (floorNum - 1) + 210;
				m->SetSx(4920 * (floorNum - 1));
				SetMode(1);
			}
			else if (GetX2() >= 4920 * (floorNum + 1) - 300) {	//若從右邊下樓
				x = 4920 * floorNum - 210 - RhotGirl.Width();
				m->SetSx(4920 * floorNum - 1024);
				SetMode(2);
			}
		}


		if (mode == 1) {
			for (unsigned int i = follower.size(); i > 0; i--) {
				follower[i - 1]->SetMode(7);						//跟隨者面對左邊
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x + 110, y);				//設第一個跟隨者跟著女主角移動
				}
				else {												//設後面的跟隨者跟著前一個跟隨者移動
					follower[i - 1]->SetXY(follower[i]->GetX1() + 90, y);
				}
			}
		}
		else if (mode == 2) {
			for (unsigned int i = follower.size(); i > 0; i--) {
				follower[i - 1]->SetMode(8);						//跟隨者面對右邊
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x - 90, y);				//設第一個跟隨者跟著女主角移動
				}
				else {												//設後面的跟隨者跟著前一個跟隨者移動
					follower[i - 1]->SetXY(follower[i]->GetX1() - 90, y);
				}
			}
		}
	}

	void CHotGirl::InterruptPK()
	{	
		if (isPK == true) {
			if (isTimeUpInterruptPK == false) {
				for (auto bitch : PKbitchies) {						//敵人們的狀態改回來
					if (bitch->GetBeforePKmode() == 1) {
						bitch->SetMode(3);
						bitch->SetMovingLeft(true);
					}
					else if (bitch->GetBeforePKmode() == 2) {
						bitch->SetMode(4);
						bitch->SetMovingRight(true);
					}
				}

				if (energy_score > 0) {
					if (this->currentMode == 1) {					//女主角狀態改回來
						this->mode = 1;
						this->SetMovingLeft(true);
						this->SetMovingRight(false);
					}
					else if (this->currentMode == 2) {
						this->mode = 2;
						this->SetMovingRight(true);
						this->SetMovingLeft(false);
					}
				}
			

				this->AttackedBoy->SetMode(3);						//男生狀態改回來
				this->AttackedBoy->SetMovingLeft(true);
			}
			isTimeUpInterruptPK = true;
		}
	}
	bool CHotGirl::FinalCountScore(SchoolMap *m)
	{	
		//________________________________________人物移動_______________________________________________
		if (mode==1 ||mode==3 ||mode == 5 || mode == 7 || mode == 11) {					//若女主角面向左邊
			mode = 14;																	//模式改成右邊被嚇到
			RFrightenedGirl.Reset();
		}else if(mode == 2 || mode == 4 ||mode == 6 || mode == 8 || mode == 12){		//若女主角面向右邊
			mode = 13;																	//模式改成左邊被嚇到
			LFrightenedGirl.Reset();
		}
		
		if (mode==13 && LFrightenedGirl.IsFinalBitmap() == true) {						//若左邊被嚇到動畫跑完
			mode = 15;																	//往左邊離開畫面
			this->isMovingLeft = true;
		}else if (mode == 14 && RFrightenedGirl.IsFinalBitmap() == true) {				//若右邊被嚇到動畫跑完
			mode = 16;																	//往右邊離開畫面
			this->isMovingRight = true;
		}


		if (mode == 15) {			//女主角左邊離開畫面
			x = x - 5;
		}else if (mode == 16) {		//女主角右邊離開畫面
			x = x + 5;
		}


		if (mode == 13 || mode == 15) {								//跟隨者跟著女主角
			for (unsigned int i = follower.size(); i > 0; i--) {

				follower[i - 1]->SetMode(7);						//跟隨者面對左邊
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x + 110, y);				//設第一個跟隨者跟著女主角移動
				}
				else {												//設後面的跟隨者跟著前一個跟隨者移動
					follower[i - 1]->SetXY(follower[i]->GetX1() + 90, y);
				}
			}
		}else if (mode == 14 || mode == 16) {						//跟隨者跟著女主角
			for (unsigned int i = follower.size(); i > 0; i--) {
				follower[i - 1]->SetMode(8);						//跟隨者面對右邊
				if (i == follower.size()) {
					follower[i - 1]->SetXY(x - 90, y);				//設第一個跟隨者跟著女主角移動
				}
				else {												//設後面的跟隨者跟著前一個跟隨者移動
					follower[i - 1]->SetXY(follower[i]->GetX1() - 90, y);
				}
			}
		}
		//________________________________________結算跟隨者分數_______________________________________________
		bool isLastFollowerLeave = false;
		if (follower.size() != 0) {														//若有跟隨者
			for (unsigned int i = follower.size(); i > 0; i--) {
				if (mode == 15 && follower[i - 1]->GetX1() <= m->getSx()) {				//若該跟隨者碰到螢幕左側
					total_score = total_score + follower[i - 1]->GetFinalScore();		//獲得這個跟隨者的結尾加分
					if (follower[i - 1]->GetisPlayedDingAudio() == false) {				//若還沒播過得分音效
						
						if (follower[i - 1]->GetHandSomeLevel() == 1) {					//若是魯蛇
							CAudio::Instance()->Play(AUDIO_Alien, false);				//播放得分數音效:阿~
						}else{															//若是帥哥
							CAudio::Instance()->Play(AUDIO_HEY, false);					//播放得分數音效:嘿嘿~
						}
						
						follower[i - 1]->SetisPlayedDingAudio(true);
					}
					if (i == 1)isLastFollowerLeave = true;								//紀錄最後一位跟隨者已經離開畫面
				}
				else if (mode == 16 && follower[i - 1]->GetX2() >= m->getSx() + 1024) {	//若跟隨者碰到螢幕右側
					total_score = total_score + follower[i - 1]->GetFinalScore();		//獲得這個跟隨者的結尾加分
					if (follower[i - 1]->GetisPlayedDingAudio() == false) {				//若還沒播過得分音效
						
						if (follower[i - 1]->GetHandSomeLevel() == 1) {					//若是魯蛇
							CAudio::Instance()->Play(AUDIO_Alien, false);				//播放得分數音效:阿~
						}else{															//若是帥哥
							CAudio::Instance()->Play(AUDIO_HEY, false);					//播放得分數音效:嘿嘿~
						}
						follower[i - 1]->SetisPlayedDingAudio(true);
					}
					if (i == 1)isLastFollowerLeave = true;								//紀錄最後一位跟隨者已經離開畫面
				}
			}
		}else {																			//若沒有跟隨者(只有女主角)
			if (mode == 15 && x <= m->getSx()) {										//若女主角離開畫面
				isLastFollowerLeave = true;												//紀錄女主角離開畫面
			}else if (mode == 16 && GetX2() >= m->getSx() + 1024) {
				isLastFollowerLeave = true;
			}
		}
		//________________________________________結算愛心分數_______________________________________________
		if (isLastFollowerLeave == true) {							//若達到可以消除左上角愛心的條件
			if (energy_score >= 5) {								//直接消除左上角愛心得分
				energy_score = energy_score - 5;
				total_score = total_score + 5;

				if (isPlayCountScoreAudio == false) {				//播放結算分數音樂
					isPlayCountScoreAudio = true;
					CAudio::Instance()->Play(AUDIO_FINALCOUNTSCORE, false);
				}
			}
			else if (energy_score < 5 && energy_score >= 0) {
				if (isLastFollowerLeave == true) {
					total_score = total_score + energy_score;
					energy_score = 0;
					if (energy_score == 0) {						//若分數扣完停止音樂
						CAudio::Instance()->Stop(AUDIO_FINALCOUNTSCORE);
						
					}
					return true;									//分數結算完，回傳true
				}
			}
		}
		return false;												//分數還沒結算完，回傳fasle
	}

	void CHotGirl::GameOverReact()
	{
		if (mode == 11) {												//若是左邊跌倒
			if (LlayDownGirl.GetCurrentBitmapNumber() == 26) {			//且正在哭的話
				mode = 17;												//狀態改為一直哭
				tempMode = 17;
				if (isPlayedGameOverAudio == false) {					//若還沒播過遊戲失敗的音效
					isPlayedGameOverAudio = true;	
					CAudio::Instance()->Play(AUDIO_GAMEOVER, false);	//播放音效
				}
			}
		}
		else if (mode == 12) {											//弱勢右邊跌倒的話
			if (RlayDownGirl.GetCurrentBitmapNumber() == 26) {			//且正在哭的話
				mode = 18;												//狀態改為一直哭
				tempMode = 18;
				if (isPlayedGameOverAudio == false) {					//若還沒播過遊戲失敗的音效
					isPlayedGameOverAudio = true;
					CAudio::Instance()->Play(AUDIO_GAMEOVER, false);	//播放音效
				}
			}
		}
		
		if (isPlayedGameOverAudio == true) {							//保持哭泣的動作
			mode = tempMode;
		}
		
	}

	bool CHotGirl::GetIsHaveInvincible()
	{
		return isHaveInvincible;
	}

	bool CHotGirl::GetIsPlayedDangerMusic()
	{
		return isPlayedDangerMusic;
	}

	void CHotGirl::SetIsPlayedDangerMusic(bool flag)
	{
		isPlayedDangerMusic = flag;
	}
}