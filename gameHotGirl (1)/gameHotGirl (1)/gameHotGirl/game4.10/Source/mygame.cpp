/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "PKbackground.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 主流程控制
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame *g)
		: CGameState(g)
	{
	}

	void CGameStateInit::OnInit()
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(0);	// 一開始的loading進度為0%
		//
		// 開始載入資料
		//

		CAudio::Instance()->Load(AUDIO_FIRSTMUSIC, "sounds\\開場音樂.mp3");		// 載入開場音樂
		initialBackground.LoadBitmap(IDB_BACKGROUNDINITIAL);	//載入背景圖片
		aboutBackground.LoadBitmap(IDB_AboutDetail);			//載入"關於我們"圖片
		option.LoadBitmap();									//載入選項圖片
		rule.LoadBitmap();										//載入規則圖片
		allMusic.LoadBitmap();									//載入音量鍵圖片



		
		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
		//
	}

	void CGameStateInit::OnBeginState()
	{
		option.SetIsStartClick(true);							//設定選項初始值
		option.SetIsAboutClick(false);
		option.SetIsLeaveClick(false);
		allMusic.SetEnterMode(1);								//設定音量鍵的階段型態
		enterMode = 0;											//設定場景為起始畫面
		isPlayedFirstTimeMusic = false;							//設定還沒播過開場音樂
	}

	void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{	
		const char KEY_LEFT = 0x25;		// keyboard左箭頭
		const char KEY_RIGHT = 0x27;	// keyboard右箭頭
		const char KEY_DOWN = 0x28;		// 下箭頭
		const char KEY_UP = 0x26;		// 上箭頭
		const char KEY_SPACE = ' ';		//空白鍵
		const char KEY_Q = 0x51;		// Q鍵




		if (nChar == KEY_RIGHT) {
			if (enterMode == 0) {
				if (option.GetIsStartClick() == true) {				//若目前選到"開始遊戲"
					option.SetIsStartClick(false);					//改選到"關於我們"
					option.SetIsAboutClick(true);
				}
				else if (option.GetIsAboutClick() == true) {		//若目前選到"關於我們"
					option.SetIsAboutClick(false);					//改選到"離開遊戲"
					option.SetIsLeaveClick(true);
				}
			}else if (enterMode == 1) {								//若現在在規則說明
				rule.GoNextPage();									//換到下一張規則
			}
		}

		if (nChar == KEY_LEFT) {
			if (enterMode == 0) {
				if (option.GetIsLeaveClick() == true) {				//若目前選到"離開遊戲"
					option.SetIsLeaveClick(false);					//改選到"關於我們"
					option.SetIsAboutClick(true);
				}
				else if (option.GetIsAboutClick() == true) {		//若目前選到"關於我們"
					option.SetIsAboutClick(false);					//改選到"開始遊戲"
					option.SetIsStartClick(true);
				}
			}else if (enterMode == 1) {								//若現在在規則說明
				rule.GoLastPage();									//回到上一張規則
			}
		}


		if (nChar == KEY_SPACE) {
			if (enterMode == 0) {
				if (option.GetIsStartClick() == true) {						//如果現在在起始畫面
					enterMode = 1;											//進到"規則說明"並記錄
					allMusic.SetEnterMode(2);								//改變音量鍵階段型態
					option.SetEnterMode(1);									//設定選項的群組類別
					CAudio::Instance()->Play(AUDIO_TRANSFORM);				// 播放轉換音樂
				}
				else if (option.GetIsAboutClick() == true) {
					enterMode = 2;											//進到"關於我們"並記錄
					allMusic.SetEnterMode(3);								//改變音量鍵階段型態
					option.SetEnterMode(2);									//設定選項的群組類別
					CAudio::Instance()->Play(AUDIO_TRANSFORM);				// 播放轉換音樂
				}
				else if (option.GetIsLeaveClick() == true) {
					PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
				}
			}
			else if (enterMode == 1) {										//如果現在在"遊戲開始"
				CAudio::Instance()->Play(AUDIO_TRANSFORM);					// 播放轉換音樂
				CAudio::Instance()->Stop(AUDIO_FIRSTMUSIC);					// 關閉開場音樂
				allMusic.SetEnterMode(4);									//改變音量鍵階段型態
				enterMode = 0;												//畫面回歸初始值
				option.SetEnterMode(0);										//選項回歸初始值
				GotoGameState(GAME_STATE_RUN);								//開始遊戲，轉換狀態
			}
			else if (enterMode == 2) {										//如果現在在"關於我們"
				enterMode = 0;												//回到起始畫面並記錄
				allMusic.SetEnterMode(1);									//改變音量鍵階段型態
				option.SetEnterMode(0);										//設定選項的群組類別
				CAudio::Instance()->Play(AUDIO_TRANSFORM);					// 播放轉換音樂
			}
		}

		if (nChar == KEY_Q) {							//英文Q
			allMusic.SetisCloseMusic();					//設定全部音樂，沒關就關，有關就打開

			if (allMusic.GetisCloseMusic() == false) {				//若音量鍵被開啟
				CAudio::Instance()->Play(AUDIO_FIRSTMUSIC, true);	//播放開場音樂
			}
			else {													//若音量鍵被關閉
				CAudio::Instance()->Stop(AUDIO_FIRSTMUSIC);			//關閉所有音效
				CAudio::Instance()->Stop(AUDIO_TRANSFORM);
			}
		}
			
	}

	void CGameStateInit::OnMove()
	{
		option.OnMove();					//播放選項動畫
		rule.OnMove();						//播放規則動畫
	}

	void CGameStateInit::OnShow()
	{
		if (enterMode == 0) {						//若現在在起始畫面
			initialBackground.SetTopLeft(0, 0);		//顯示背景圖片
			initialBackground.ShowBitmap();
		}

		if (enterMode == 1) {						//若現在在規則說明
			rule.OnShow();							//印出規則
		}

		if (enterMode == 2) {						//若現在在關於我們
			aboutBackground.SetTopLeft(0, 0);		//顯示"關於我們"圖片
			aboutBackground.ShowBitmap();
		}

		option.OnShow();							//顯示選項圖片
		allMusic.OnShow();							//顯示音量鍵圖片

		if (isPlayedFirstTimeMusic == false) {
			CAudio::Instance()->Play(AUDIO_FIRSTMUSIC, true);		// 播放開場音樂
			isPlayedFirstTimeMusic = true;							//記錄播過開場音樂
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	/////////////////////////////////////////////////////////////////////////////

	CGameStateOver::CGameStateOver(CGame *g)
		: CGameState(g)
	{
	}

	void CGameStateOver::OnMove()
	{
		ending.OnMove();		//播放結局動畫
		option.OnMove();		//播放選項特效
	}

	void CGameStateOver::OnBeginState()
	{
		ending.SetEnding(total_score);				// 依照得到的總分設定結局種類
		option.SetIsBackClick(true);				//設定按鈕初始值
		option.SetIsLeaveClick(false);
		allMusic.SetEnterMode(5);					//改變音量鍵階段型態

		eightBit_score[0].Initialize(375, 35);		//設定每位分數跟位置
		eightBit_score[0].SetMode(total_score % 100000000 / 10000000);

		eightBit_score[1].Initialize(410, 45);
		eightBit_score[1].SetMode(total_score % 10000000 / 1000000);

		eightBit_score[2].Initialize(445, 50);
		eightBit_score[2].SetMode(total_score % 1000000 / 100000);

		eightBit_score[3].Initialize(480, 55);
		eightBit_score[3].SetMode(total_score % 100000 / 10000);

		eightBit_score[4].Initialize(515, 55);
		eightBit_score[4].SetMode(total_score % 10000 / 1000);

		eightBit_score[5].Initialize(550, 50);
		eightBit_score[5].SetMode(total_score % 1000 / 100);
		
		eightBit_score[6].Initialize(585, 45);
		eightBit_score[6].SetMode(total_score % 100 / 10);

		eightBit_score[7].Initialize(620, 35);
		eightBit_score[7].SetMode(total_score % 10);
	}

	void CGameStateOver::OnInit()
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
		//
		// 開始載入資料
		ending.LoadBitmap();				//載入結局圖片
		allMusic.LoadBitmap();				//載入音量鍵圖片
		ending.LoadAudio();					//載入結局音效
		option.LoadBitmap();				//載入按鈕圖片
		for (int s = 0; s < 8; s++) {		//載入分數圖片
			eightBit_score[s].LoadBitmap();
		}

		//
		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 最終進度為100%
		//
		ShowInitProgress(100);
	}

	void CGameStateOver::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;		// keyboard左箭頭
		const char KEY_RIGHT = 0x27;	// keyboard右箭頭
		const char KEY_SPACE = 0x20;	// keyboard空白鍵
		const char KEY_Q = 0x51;		// keyboard英文Q

		if (nChar == KEY_LEFT) {						//左鍵
			option.SetIsBackClick(true);
			option.SetIsLeaveClick(false);
		}


		if (nChar == KEY_RIGHT) {						//右鍵
			option.SetIsBackClick(false);
			option.SetIsLeaveClick(true);
		}


		if (nChar == KEY_SPACE) {						//空白鍵
			if (option.GetIsBackClick() == true) {		//如果是選擇"重新開始"
				ending.StopAllAudio();									//關閉結局音效
				CAudio::Instance()->Play(AUDIO_TRANSFORM, false);		// 撥放轉換音效
				CAudio::Instance()->Play(AUDIO_FIRSTMUSIC, true);		// 播放開場音樂
				GotoGameState(GAME_STATE_INIT);							//回到遊戲起始畫面
			}

			if (option.GetIsLeaveClick() == true) {		//如果是選擇"離開遊戲"
				PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
			}
		}


		if (nChar == KEY_Q) {							//英文Q
			allMusic.SetisCloseMusic();					//設定全部音樂，沒關就關，有關就打開

			if (allMusic.GetisCloseMusic() == false) {				//若音量鍵被開啟
				if (ending.GetEnding() == 1) {										//若現在是結局1
					CAudio::Instance()->Play(AUDIO_ENDING1,true);					//播放結局1音效
				}
				else if (ending.GetEnding() == 2 || ending.GetEnding() == 3) {		//若現在是結局23
					CAudio::Instance()->Play(AUDIO_ENDING23, true);					//播放結局23音效
				}
				else if (ending.GetEnding() == 4) {									//若現在是結局4
					CAudio::Instance()->Play(AUDIO_ENDING4, true);					//播放結局4音效
				}
				else if (ending.GetEnding() == 5) {									//若現在是結局5
					CAudio::Instance()->Play(AUDIO_ENDING5, true);					//播放結局5音效
				}
			}
			else {													//若音量鍵被關閉
				CAudio::Instance()->Stop(AUDIO_ENDING1);			//關閉所有音效
				CAudio::Instance()->Stop(AUDIO_ENDING23);			
				CAudio::Instance()->Stop(AUDIO_ENDING4);
				CAudio::Instance()->Stop(AUDIO_ENDING5);
				CAudio::Instance()->Stop(AUDIO_TRANSFORM);
			}
		}
	}


	void CGameStateOver::OnShow()
	{
		ending.OnShow();							//印出結局動畫
		allMusic.OnShow();							//印出音量鍵
		allMusic.SetEnterMode(5);					//設定音量鍵型態
		option.OnShow();							//印出選項
		for (int s = 0; s < 8; s++) {				//印出分數圖片
			eightBit_score[s].OnShow();				
		}	
		
	}

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	/////////////////////////////////////////////////////////////////////////////

	CGameStateRun::CGameStateRun(CGame *g)
		: CGameState(g)
	{
		picX = picY = 0;
	}

	CGameStateRun::~CGameStateRun()
	{
	}

	void CGameStateRun::OnBeginState()
	{
		const int BALL_GAP = 90;
		const int BALL_XY_OFFSET = 45;
		const int BALL_PER_ROW = 7;
		const int HITS_LEFT = 10;
		const int HITS_LEFT_X = 590;
		const int HITS_LEFT_Y = 0;
		const int BACKGROUND_X = 60;
		const int ANIMATION_SPEED = 15;
		allMusic.SetEnterMode(4);					//改變音量鍵階段型態
		isShowSecretKey = false;					//一開始不秀出密技圖

		

		for (int s = 0; s < 8; s++) {									//左上角總分初始化設定
			eightBit_score[s].Initialize(800 - s * 30, 40);				//設定第s+1位圖片的座標
		}
		for (int energyNum = 0; energyNum < 10; energyNum++)
		{
			ten_love[energyNum].Initialize(20 + energyNum * 32, 50);
		}

		whichBackgroungMusic = (rand() % 4) + 1;				//隨機選擇要撥背景音樂1~4
		hotgirl.Initialize(&schoolmap);							//女主角初始化設定
		clock.ClockReSet();										//時鐘初始值重設
		clock.StartCountTime();									//在設定時鐘開始計時

		arrow.SetFloor(1);										//設定樓層箭頭一開始在1樓


		/*------------------------------第一層樓210~4710---------------------------------------------------------------------*/
		lusnake[4].Initialize(510, 296, false, true, 1);		//因為252 圖片會有出格子 false是設定初始方向(左邊),true 是右邊,1是帥的程度
		bitchies[0].Initialize(360, 190, true, false);
		bitchies[2].Initialize(710, 262, false, true);


		lusnake[0].Initialize(1210, 190, true, false, 1);		//魯蛇初始化設定，190第一道、262第三道、296第四道
		
		lusnake[2].Initialize(2210, 262, false, true, 1);
		bitchies[1].Initialize(1710, 296, true, false);
		lusnake[26].Initialize(2710, 190, false, true, 120);	//外國大帥哥
		bitchies[16].Initialize(2730, 190, false, true);		//超強女生敵人
		bitchies[16].SetIsForeign(true);			

		lusnake[1].Initialize(3010, 190, true, false, 1);
		

		lusnake[3].Initialize(4410, 262, false, true, 1);
		bitchies[15].Initialize(4210, 190, true, false);
		lusnake[5].Initialize(3810, 296, true, false, 1);

		teacher.Initialize(2710, 216, false, true);
		/*------------------------------第二層樓5130~9630---------------------------------------------------------------------*/
		lusnake[6].Initialize(5410, 190, true, false,1);		//魯蛇初始化設定，190第一道、262第三道、296第四道 
		lusnake[7].Initialize(5710, 190, true, false,1);
		lusnake[8].Initialize(5810, 296, false, true,1);
		bitchies[3].Initialize(5610, 262, true, false);

		lusnake[9].Initialize(7410, 190, false, true, 1);
		lusnake[10].Initialize(7610, 190, false, true, 1);
		lusnake[11].Initialize(7110, 296, true, false, 1);
		lusnake[12].Initialize(7210, 262, false, true, 1);
		lusnake[13].Initialize(7410, 296, true, false, 1);

		lusnake[14].Initialize(9210, 262, false, true, 1);
		lusnake[15].Initialize(8810, 190, true, false, 1);
		bitchies[4].Initialize(8910, 190, true, false);
		/*------------------------------第三層樓10050~14550---------------------------------------------------------------------*/
		lusnake[16].Initialize(10410, 190, true, false, 1);
		lusnake[17].Initialize(11010, 262, false, true, 1);
		bitchies[5].Initialize(11210, 296, true, false);

		lusnake[18].Initialize(12210, 262, true, false, 100);		//帥哥,分數為10000
		bitchies[6].Initialize(12110, 262, true, false);
		bitchies[7].Initialize(12410, 296, true, false);
		bitchies[8].Initialize(12310, 190, true, false);

		lusnake[19].Initialize(13810, 296, false, true,1);
		lusnake[20].Initialize(14010, 190, true, false, 1);
		bitchies[9].Initialize(13510, 262, true, false);
		bitchies[10].Initialize(13910, 296, true, false);
		/*------------------------------第四層樓14970~19470---------------------------------------------------------------------*/
		lusnake[21].Initialize(15310, 262, true, false, 1);
		lusnake[22].Initialize(16110, 296, false, true, 1);

		lusnake[23].Initialize(17260, 262, true, false,110);		//超級大帥哥,分數為24000
		bitchies[11].Initialize(17110, 262, false, true);
		bitchies[12].Initialize(17210, 190, true, false);
		bitchies[13].Initialize(17310, 296, false, true);
		bitchies[14].Initialize(17410, 262, true, false);

		lusnake[24].Initialize(18510, 190, false, true, 1);
		lusnake[25].Initialize(19010, 190, true, false, 1);
		/*-------------------------------------------------------------------------------------------------------------*/
		


		if (whichBackgroungMusic == 1) {
			CAudio::Instance()->Play(AUDIO_BACKGROUND, true);			// 撥放背景音樂1:陷阱妹
		}else if (whichBackgroungMusic == 2) {
			CAudio::Instance()->Play(AUDIO_BACKGROUND2, true);			// 撥放背景音樂2:辣台妹
		}else if (whichBackgroungMusic == 3) {
			CAudio::Instance()->Play(AUDIO_BACKGROUND3, true);			// 撥放背景音樂3:皇后區的皇后
		}else if (whichBackgroungMusic == 4) {
			CAudio::Instance()->Play(AUDIO_BACKGROUND4, true);			// 撥放背景音樂4:場上稱霸
		}
	}

	void CGameStateRun::OnMove()							// 移動遊戲元素
	{
		
		clock.CountTime();									//讀取遊戲開始到現在的秒數

		//如果現在是無敵模式
		if (hotgirl.GetIsInvincible() == true) {
			InvincibleLine.CountTime();						//讀取無敵模式開始到現在的秒數
			CAudio::Instance()->Stop(AUDIO_BACKGROUND);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND2);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND2);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND3);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND3);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND4);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND4);
		}


		if (!hotgirl.IsHeartEmpty())						//如果有愛心
		{
			hotgirl.MoveHearts(&schoolmap);					//愛心掉落
		}
		

		for (int s = 0; s < 8; s++) {
			eightBit_score[s].SetMode(hotgirl.GetBitScore(s + 1));	//設定第s+1位的數字為總分的第s+1位數子
		}


		for (int energyNum = 0; energyNum < 10; energyNum++)		//設定小愛心狀態動畫
		{
			ten_love[energyNum].OnMove();
		}


		int energy = hotgirl.GetEnergyScore();


		if (hotgirl.GetEnergyScore() < 160)				//若小愛心
		{	
			if (clock.GetIsTimeOut() != true) {			//若時間還沒到
				for (int i = 0; i < 10; i++)
				{
					ten_love[i].SetDanger(true);		//小愛心變成危險狀態
					
				}
			}else {										//若時間到(在結算小愛心時)
				for (int i = 0; i < 10; i++)
				{
					ten_love[i].SetDanger(false);		//小愛心呈正常狀態
				}
			}

			if (hotgirl.GetIsPlayedDangerMusic() == false) {	//若還沒撥放過危險警告音樂
				CAudio::Instance()->Play(AUDIO_DANGER,false);	//播放危險警告音樂
				hotgirl.SetIsPlayedDangerMusic(true);
			}
		}else
		{
			for (int i = 0; i < 10; i++)
			{
				ten_love[i].SetDanger(false);					//小愛心呈正常狀態
			}
		}

		for (int energyNum = 0; energyNum < 10; energyNum++)	//判斷小愛心的狀態
		{
			if (energy >= 80)
			{
				ten_love[energyNum].SetMode(8);
				energy = energy - 80;
			}
			else if (energy > 0)
			{
				if (energy > 70)
				{
					ten_love[energyNum].SetMode(7);
				}
				else if (energy > 60)
				{
					ten_love[energyNum].SetMode(6);
				}
				else if (energy > 50)
				{
					ten_love[energyNum].SetMode(5);
				}
				else if (energy > 40)
				{
					ten_love[energyNum].SetMode(4);
				}
				else if (energy > 30)
				{
					ten_love[energyNum].SetMode(3);
				}
				else if (energy > 20)
				{
					ten_love[energyNum].SetMode(2);
				}
				else if (energy > 10)
				{
					ten_love[energyNum].SetMode(1);
				}
				else if (energy > 0)
				{
					ten_love[energyNum].SetMode(0);
				}
				energy = 0;
			}
			else
			{
				ten_love[energyNum].SetMode(0);
			}

		}


		for (int bitchNumber = 0; bitchNumber < 17; bitchNumber++)						//女生敵人偵測判斷
		{	
			if (bitchNumber != 16 || (bitchNumber == 16 && hotgirl.GetIsHaveInvincible() == true)) {	//若不是外國婊，直接偵測，如果是，要有無敵過才能偵測
				if (bitchies[bitchNumber].GetSensor() == true)							//若這層的bitch都有偵測到可以Pk的話
				{
					if (hotgirl.GetIsInvincible() == true) {							//如果現在在無敵狀態
						hotgirl.TrunAttackMode(&bitchies[bitchNumber], &schoolmap);		//bitch狀態改為pk模式
					}
					else {																//如果不是無敵狀態
						if (bitchies[bitchNumber].IsShowFinish() == true)				//就等驚嘆號動畫放完
						{
							hotgirl.TrunAttackMode(&bitchies[bitchNumber], &schoolmap);	//bitch狀態再改為pk模式
						}
						else {															//若偵測的中途被老師撞倒
							if (hotgirl.GetIsLayDown() == true) {
								bitchies[bitchNumber].SetSensor(false);					//婊子們解除偵測狀態
								bitchies[bitchNumber].SetMode(3);
								bitchies[bitchNumber].SetMovingLeft(true);
							}
						}
					}
				}
			}
		}

		
		hotgirl.OnMove(&schoolmap);			//女主角移動



		pk_background.OnMove();
		lusnake[0].OnMove(&schoolmap);
		lusnake[1].OnMove(&schoolmap);
		lusnake[2].OnMove(&schoolmap);
		lusnake[3].OnMove(&schoolmap);
		lusnake[4].OnMove(&schoolmap);
		lusnake[5].OnMove(&schoolmap);
		lusnake[6].OnMove(&schoolmap);
		lusnake[7].OnMove(&schoolmap);
		lusnake[8].OnMove(&schoolmap);
		lusnake[9].OnMove(&schoolmap);
		lusnake[10].OnMove(&schoolmap);
		lusnake[11].OnMove(&schoolmap);
		lusnake[12].OnMove(&schoolmap);
		lusnake[13].OnMove(&schoolmap);
		lusnake[14].OnMove(&schoolmap);
		lusnake[15].OnMove(&schoolmap);
		lusnake[16].OnMove(&schoolmap);
		lusnake[17].OnMove(&schoolmap);
		lusnake[18].OnMove(&schoolmap);
		lusnake[19].OnMove(&schoolmap);
		lusnake[20].OnMove(&schoolmap);
		lusnake[21].OnMove(&schoolmap);
		lusnake[22].OnMove(&schoolmap);
		lusnake[23].OnMove(&schoolmap);
		lusnake[24].OnMove(&schoolmap);
		lusnake[25].OnMove(&schoolmap);
		lusnake[26].OnMove(&schoolmap);

		bitchies[0].OnMove(&schoolmap);
		bitchies[1].OnMove(&schoolmap);
		bitchies[2].OnMove(&schoolmap);
		bitchies[3].OnMove(&schoolmap);
		bitchies[4].OnMove(&schoolmap);
		bitchies[5].OnMove(&schoolmap);
		bitchies[6].OnMove(&schoolmap);
		bitchies[7].OnMove(&schoolmap);
		bitchies[8].OnMove(&schoolmap);
		bitchies[9].OnMove(&schoolmap);
		bitchies[10].OnMove(&schoolmap);
		bitchies[11].OnMove(&schoolmap);
		bitchies[12].OnMove(&schoolmap);
		bitchies[13].OnMove(&schoolmap);
		bitchies[14].OnMove(&schoolmap);
		bitchies[15].OnMove(&schoolmap);
		bitchies[16].OnMove(&schoolmap);

		
		if (hotgirl.IsPK() == false) {				
			teacher.OnMove(&schoolmap);			//若現在不在pk模式則老師可以動
		}

		// 若不是無敵模式、遊戲時間還沒結束、左上角愛心還有，判斷女主角是否碰到老師
		if (hotgirl.GetIsInvincible() == false && clock.GetIsTimeOut()==false && hotgirl.GetEnergyScore()>0) {
			hotgirl.IsTouchTeacher(&teacher);
		}
		

		//箭頭得到女主角現在所在的樓層
		arrow.SetFloor(hotgirl.GetFloor());
		arrow.SetArrowPosition(hotgirl.GetTouchStairLR());

		
		//若遊戲時間結束
		if (clock.GetIsTimeOut() == true) {
			CAudio::Instance()->Stop(AUDIO_BACKGROUND);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND2);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND2);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND3);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND3);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND4);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND4);
			CAudio::Instance()->Stop(AUDIO_TOKYO);
			CAudio::Instance()->Stop(AUDIO_PK);
			CAudio::Instance()->Stop(AUDIO_LIGHTING);
			CAudio::Instance()->Stop(AUDIO_HEART);
			CAudio::Instance()->Stop(AUDIO_LASER);
			CAudio::Instance()->Stop(AUDIO_SCREAM);
			CAudio::Instance()->Stop(AUDIO_TRANSFORM);
			CAudio::Instance()->Stop(AUDIO_DANGER);
			CAudio::Instance()->Stop(AUDIO_TEACHERYELL1);
			CAudio::Instance()->Stop(AUDIO_TEACHERYELL2);


			hotgirl.SetMovingLeft(false);
			hotgirl.SetMovingRight(false);
			hotgirl.InterruptPK();					//打斷PK狀態的顯示
			hotgirl.SetIsPK(false);					//解除pk狀態
			hotgirl.SetIsInvincible(false);			//解除無敵狀態
			InvincibleLine.InvincibleLineReSet();	//無敵時間條初始值重設
			bool isFinalCountUp=hotgirl.FinalCountScore(&schoolmap);	//結算最後成績
			
			if (isFinalCountUp == true && clock.GetIsAudioTimeUp() == true) {
				schoolmap.SetSx(0);					//調整螢幕畫面到起始點
				total_score = hotgirl.GetTotalScore();						//得到遊戲總分
				GotoGameState(GAME_STATE_OVER);		//若音樂放完且分數算完就結束遊戲
			}
		}


		//若左上角愛心能量沒了
		if (hotgirl.GetEnergyScore() <= 0 && clock.GetIsTimeOut() == false) {
			CAudio::Instance()->Stop(AUDIO_BACKGROUND);			//關閉所有音效
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND2);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND2);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND3);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND3);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND4);
			CAudio::Instance()->Stop(AUDIO_REBACKGROUND4);
			CAudio::Instance()->Stop(AUDIO_TOKYO);
			CAudio::Instance()->Stop(AUDIO_LIGHTING);
			CAudio::Instance()->Stop(AUDIO_HEART);
			CAudio::Instance()->Stop(AUDIO_LASER);
			CAudio::Instance()->Stop(AUDIO_SCREAM);
			CAudio::Instance()->Stop(AUDIO_TRANSFORM);
			CAudio::Instance()->Stop(AUDIO_FINALCOUNTSCORE);
			CAudio::Instance()->Stop(AUDIO_DANGER);
			CAudio::Instance()->Stop(AUDIO_TEACHERYELL1);
			CAudio::Instance()->Stop(AUDIO_TEACHERYELL2);
			CAudio::Instance()->Stop(AUDIO_HEY);

			hotgirl.SetMovingLeft(false);
			hotgirl.SetMovingRight(false);
			hotgirl.InterruptPK();					//打斷PK狀態的顯示
			hotgirl.SetIsPK(false);					//解除pk狀態
			hotgirl.SetIsInvincible(false);			//解除無敵狀態
			InvincibleLine.InvincibleLineReSet();	//無敵時間條初始值重設
			hotgirl.GameOverReact();				//女主角做出遊戲失敗的反應及音效
			clock.StartPlayGameOverAudio();			//紀錄遊戲失敗音效的播放起始時間點
			if (clock.GetIsGameOverAudioTimeUp() == true) {		//若遊戲失敗音效撥放完畢
				schoolmap.SetSx(0);											//調整螢幕畫面到起始點
				total_score = hotgirl.GetTotalScore();						//得到遊戲總分
				GotoGameState(GAME_STATE_OVER);		//就結束遊戲
			}
		}


		//如果現在進入無敵模式
		if (hotgirl.GetIsInvincible() == true) {
			InvincibleLine.StartCountTime();							//在設定無敵時間條開始計時
		}

		//如果無敵時間到了
		if (InvincibleLine.GetIsTimeOut() == true) {
			hotgirl.SetIsInvincible(false);			//解除無敵狀態
			hotgirl.SetEnergyScore(320);			//左上愛心分數變回三百
			InvincibleLine.InvincibleLineReSet();	//無敵時間條初始值重設

			if (whichBackgroungMusic == 1) {
				CAudio::Instance()->Play(AUDIO_REBACKGROUND, false);			// 撥放RE背景音樂1:陷阱妹
			}
			else if (whichBackgroungMusic == 2) {
				CAudio::Instance()->Play(AUDIO_REBACKGROUND2, false);			// 撥放RE背景音樂2:辣台妹
			}
			else if (whichBackgroungMusic == 3) {
				CAudio::Instance()->Play(AUDIO_REBACKGROUND3, false);			// 撥放RE背景音樂3:皇后區的皇后
			}
			else if (whichBackgroungMusic == 4) {
				CAudio::Instance()->Play(AUDIO_REBACKGROUND4, false);			// 撥放RE背景音樂4:場上稱霸
			}

			CAudio::Instance()->Stop(AUDIO_TOKYO);
			CAudio::Instance()->Play(AUDIO_TRANSFORM, false);
			hotgirl.SetisPlayInvincibleAUDIO(false);
		}
		

		if (picX <= SIZE_Y)
		{
			picX += 5;
			picY += 5;
		}
		else
		{
			picX = picY = 0;
		}

		
	}

	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		//
		// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
		//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
		//
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		//
		// 開始載入各樣物件、資料
		//
		clock.LoadBitmap();
		arrow.LoadBitmap();
		allMusic.LoadBitmap();
		InvincibleLine.LoadBitmap();

		schoolmap.LoadBitmap();
		SecretKey.LoadBitmap(IDB_warning);		
		pk_background.LoadBitmap();
		blackbroad.LoadBitmap(IDB_BLACKBROAD, RGB(0, 0, 0));
		for (int s = 0; s < 8; s++) {
			eightBit_score[s].LoadBitmap();
		}

		for (int energyNum = 0; energyNum < 10; energyNum++)
		{
			ten_love[energyNum].LoadBitmap();
		}

		hotgirl.LoadBitmap();
		hotgirl.LoadAudio();


		lusnake[0].LoadBitmap();
		lusnake[1].LoadBitmap();
		lusnake[2].LoadBitmap();
		lusnake[3].LoadBitmap();
		lusnake[4].LoadBitmap();
		lusnake[5].LoadBitmap();
		lusnake[6].LoadBitmap();
		lusnake[7].LoadBitmap();
		lusnake[8].LoadBitmap();
		lusnake[9].LoadBitmap();
		lusnake[10].LoadBitmap();
		lusnake[11].LoadBitmap();
		lusnake[12].LoadBitmap();
		lusnake[13].LoadBitmap();
		lusnake[14].LoadBitmap();
		lusnake[15].LoadBitmap();
		lusnake[16].LoadBitmap();
		lusnake[17].LoadBitmap();
		lusnake[18].LoadBitmap();
		lusnake[19].LoadBitmap();
		lusnake[20].LoadBitmap();
		lusnake[21].LoadBitmap();
		lusnake[22].LoadBitmap();
		lusnake[23].LoadBitmap();
		lusnake[24].LoadBitmap();
		lusnake[25].LoadBitmap();
		lusnake[26].LoadBitmap();

		bitchies[0].LoadBitmap();
		bitchies[1].LoadBitmap();
		bitchies[2].LoadBitmap();
		bitchies[3].LoadBitmap();
		bitchies[4].LoadBitmap();
		bitchies[5].LoadBitmap();
		bitchies[6].LoadBitmap();
		bitchies[7].LoadBitmap();
		bitchies[8].LoadBitmap();
		bitchies[9].LoadBitmap();
		bitchies[10].LoadBitmap();
		bitchies[11].LoadBitmap();
		bitchies[12].LoadBitmap();
		bitchies[13].LoadBitmap();
		bitchies[14].LoadBitmap();
		bitchies[15].LoadBitmap();
		bitchies[16].LoadBitmap();

		teacher.LoadBitmap();


		// 完成部分Loading動作，提高進度
		//
		ShowInitProgress(50);
		Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 繼續載入其他資料
		//
		CAudio::Instance()->Load(AUDIO_BACKGROUND, "sounds\\trap.wav");					// 載入背景音樂1
		CAudio::Instance()->Load(AUDIO_REBACKGROUND, "sounds\\REtrap.wav");				// 載入RE背景音樂1

		CAudio::Instance()->Load(AUDIO_BACKGROUND2, "sounds\\辣台妹.wav");				// 載入背景音樂2
		CAudio::Instance()->Load(AUDIO_REBACKGROUND2, "sounds\\RE辣台妹.wav");			// 載入RE背景音樂2

		CAudio::Instance()->Load(AUDIO_BACKGROUND3, "sounds\\皇后區的皇后.wav");		// 載入背景音樂3
		CAudio::Instance()->Load(AUDIO_REBACKGROUND3, "sounds\\RE皇后區的皇后.wav");	// 載入RE背景音樂3

		CAudio::Instance()->Load(AUDIO_BACKGROUND4, "sounds\\場上稱霸.wav");			// 載入背景音樂4
		CAudio::Instance()->Load(AUDIO_REBACKGROUND4, "sounds\\RE場上稱霸.wav");		// 載入RE背景音樂4

		CAudio::Instance()->Load(AUDIO_TIMEUP, "sounds\\timeup.mp3");					// 載入編號鐘聲
		CAudio::Instance()->Load(AUDIO_GAMEOVER, "sounds\\遊戲失敗.mp3");				// 載入遊戲失敗音效

		


		
		//CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
		//
		// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
		//
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;		// keyboard左箭頭
		const char KEY_RIGHT = 0x27;	// keyboard右箭頭
		const char KEY_UP = 0x26;		// keyboard上箭頭
		const char KEY_DOWN = 0x28;		// keyboard下箭頭
		const char KEY_SPACE = 0x20;	// keyboard空白鍵
		const char KEY_PLUS = 0x6B;		// keyboard+號
		const char KEY_MINUS = 0x6D;	// keyboard-號
		const char KEY_STAR = 0x6A;		// keyboard*號
		const char KEY_Q = 0x51;		// keyboard英文Q
		const char KEY_C = 0x43;		// keyboard英文C


		const char KEY_ONE = 0x61;		// keyboard數字1
		const char KEY_TWO = 0x62;		// keyboard數字2
		const char KEY_THREE = 0x63;	// keyboard數字3
		const char KEY_FOUR = 0x64;		// keyboard數字4
		const char KEY_FIVE = 0x65;		// keyboard數字5
		const char KEY_SIX = 0x66;		// keyboard數字6


		if (nChar == KEY_LEFT) {											//若按下左鍵
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.IsPK() == false && hotgirl.IsLocked() == false && hotgirl.IsShotting() == false && hotgirl.GetIsLayDown() == false) {
					hotgirl.SetMovingLeft(true);
					hotgirl.SetMode(3);
				}
			}
		}


		if (nChar == KEY_RIGHT) {											//若按下右鍵
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.IsPK() == false && hotgirl.IsLocked() == false && hotgirl.IsShotting() == false && hotgirl.GetIsLayDown() == false) {
					hotgirl.SetMovingRight(true);
					hotgirl.SetMode(4);
				}
			}
		}

		if (nChar == KEY_UP) {												//若按下"上"鍵
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.GetIsTouchStair() == true) {					//若女主角現在碰到樓梯
					arrow.SetIsUpClick(true);								//上箭頭變為被選擇

				}
				else {
					if (hotgirl.IsPK() == false && hotgirl.GetIsLayDown() == false) {
						if (hotgirl.GetMode() == 1 || hotgirl.GetMode() == 3)
						{
							hotgirl.SetMode(5);
							hotgirl.LockSnake(&lusnake[0], &schoolmap);		//鎖定附近上方撸蛇
						}
						else if (hotgirl.GetMode() == 2 || hotgirl.GetMode() == 4)
						{
							hotgirl.SetMode(6);
							hotgirl.LockSnake(&lusnake[0], &schoolmap);
						}
					}
				}
			}
		}

		if (nChar == KEY_DOWN) {												//若按下"下"鍵
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.GetIsTouchStair() == true) {						//若女主角現在碰到樓梯
					arrow.SetIsDownClick(true);									//下箭頭變為被選擇
				}
				else {
					if (hotgirl.IsPK() == false && hotgirl.GetIsLayDown() == false) {
						if (hotgirl.GetMode() == 1 || hotgirl.GetMode() == 3)
						{
							hotgirl.SetMode(7);
							hotgirl.LockSnake(&lusnake[0], &schoolmap);
						}
						else if (hotgirl.GetMode() == 2 || hotgirl.GetMode() == 4)
						{
							hotgirl.SetMode(8);
							hotgirl.LockSnake(&lusnake[0], &schoolmap);
						}
					}
				}
			}
		}

		if (nChar == KEY_SPACE && hotgirl.GetIsLayDown() == false) { //若按下空白建
			if (clock.GetIsTimeOut() != true  && hotgirl.GetEnergyScore() > 0) {
				if (arrow.GetClickUpDown() == 1) {					//如果要上樓
					hotgirl.UpFloor(&schoolmap);
					arrow.SetIsUpClick(false);
				}
				else if (arrow.GetClickUpDown() == 2) {				//如果要下樓
					hotgirl.DownFloor(&schoolmap);
					arrow.SetIsDownClick(false);
				}
				else if (arrow.GetClickUpDown() == 0) {				//如果沒有要上下樓
					if (hotgirl.IsPK() == false) {
						if (hotgirl.IsLocked() == true) {
							hotgirl.SetShotting(true);
							hotgirl.BitchSensor(&bitchies[0], &schoolmap);
						}
					}
					else {
						hotgirl.ComboPK(&schoolmap);
					}
				}
			}
		}

		if (nChar == KEY_PLUS)							//若按下+鍵
		{	
			hotgirl.DemoAddEnergy();
		}

		if (nChar == KEY_MINUS)							//若按下-鍵
		{
			hotgirl.DemoMinusEnergy();
		}

		if (nChar == KEY_ONE) {							//數字1:外掛鍵:直接跳到結局1
			total_score = 0;							//設定結局1的分數
			CloseAllAudio();							//關閉所有音效
			GotoGameState(GAME_STATE_OVER);				//直接跳到結局
		}
		
		if (nChar == KEY_TWO) {							//數字2:外掛鍵:直接跳到結局2
			total_score=39999;							//設定結局2的分數
			CloseAllAudio();							//關閉所有音效
			GotoGameState(GAME_STATE_OVER);				//直接跳到結局
		}

		if (nChar == KEY_THREE) {						//數字3:外掛鍵:直接跳到結局3
			total_score = 74999;						//設定結局3的分數
			CloseAllAudio();							//關閉所有音效
			GotoGameState(GAME_STATE_OVER);				//直接跳到結局
		}

		if (nChar == KEY_FOUR) {						//數字4:外掛鍵:直接跳到結局4
			total_score = 99999;						//設定結局4的分數
			CloseAllAudio();							//關閉所有音效
			GotoGameState(GAME_STATE_OVER);				//直接跳到結局
		}

		if (nChar == KEY_FIVE) {						//數字5:外掛鍵:直接跳到結局5
			total_score = 149999;						//設定結局5的分數
			CloseAllAudio();							//關閉所有音效
			GotoGameState(GAME_STATE_OVER);				//直接跳到結局
		}

		if (nChar == KEY_SIX) {							//數字6:外掛鍵:直接跳到結局6
			total_score = 150001;						//設定結局6的分數
			CloseAllAudio();							//關閉所有音效
			GotoGameState(GAME_STATE_OVER);				//直接跳到結局
		}

		if (nChar == KEY_STAR) {						//若按下*號
			clock.DemoSetIsTimeOut(true);
		}

		if (nChar == KEY_Q) {							//英文Q
			allMusic.SetisCloseMusic();					//設定全部音樂，沒關就關，有關就打開

			if (allMusic.GetisCloseMusic() == false) {						//若音量鍵被開啟
				if (clock.GetIsTimeOut() == true) {							//若遊戲時間結束
					CAudio::Instance()->Play(AUDIO_TIMEUP, true);			//播放鐘聲
				}else {
					if (hotgirl.GetIsInvincible() == true) {				//若女主角現在是無敵狀態
						CAudio::Instance()->Play(AUDIO_TOKYO, true);		//播放無敵音樂
					}else {
						if (whichBackgroungMusic == 1) {
							CAudio::Instance()->Play(AUDIO_BACKGROUND, true);			// 撥放背景音樂1:陷阱妹
						}
						else if (whichBackgroungMusic == 2) {
							CAudio::Instance()->Play(AUDIO_BACKGROUND2, true);			// 撥放背景音樂2:辣台妹
						}
						else if (whichBackgroungMusic == 3) {
							CAudio::Instance()->Play(AUDIO_BACKGROUND3, true);			// 撥放背景音樂3:皇后區的皇后
						}
						else if (whichBackgroungMusic == 4) {
							CAudio::Instance()->Play(AUDIO_BACKGROUND4, true);			// 撥放背景音樂4:場上稱霸
						}
					}
				}
			}else {													//若音量鍵被關閉
				CloseAllAudio();									//關閉所有音效
			}
		}

		if (nChar == KEY_C) {										//若按下c鍵
			isShowSecretKey = true;									//秀出密技圖
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;		// keyboard左箭頭
		const char KEY_UP = 0x26;		// keyboard上箭頭
		const char KEY_RIGHT = 0x27;	// keyboard右箭頭
		const char KEY_DOWN = 0x28;		// keyboard下箭頭
		const char KEY_C = 0x43;		// keyboard英文C
		const char KEY_SPACE = 0x20;	// keyboard空白建

		if (nChar == KEY_LEFT) {		//若放開左鍵
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.IsPK() == false && hotgirl.IsLocked() == false && hotgirl.IsShotting() == false && hotgirl.GetIsLayDown() == false) {
					hotgirl.SetMovingLeft(false);
					hotgirl.SetMode(1);
				}
			}
		}

		if (nChar == KEY_RIGHT)			//若放開右鍵
		{
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.IsPK() == false && hotgirl.IsLocked() == false && hotgirl.IsShotting() == false && hotgirl.GetIsLayDown() == false) {
					hotgirl.SetMovingRight(false);
					hotgirl.SetMode(2);
				}
			}
		}

		if (nChar == KEY_UP) {			//若放開上鍵
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.GetIsTouchStair() == true) {						//若女主角現在碰到樓梯
					arrow.SetIsUpClick(false);								//上箭頭改為沒被選到
				}
				else {
					if (hotgirl.IsPK() == false && hotgirl.GetIsLayDown() == false) {
						if (hotgirl.GetMode() == 5)
						{
							hotgirl.SetMode(1);
							hotgirl.UnLockSnake(&lusnake[0], &schoolmap); //解鎖附近上方撸蛇
						}
						else if (hotgirl.GetMode() == 6)
						{
							hotgirl.SetMode(2);
							hotgirl.UnLockSnake(&lusnake[0], &schoolmap);
						}
					}
				}
			}
		}

		if (nChar == KEY_DOWN) {			//若放開下鍵
			if (clock.GetIsTimeOut() != true  && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.GetIsTouchStair() == true) {						//若女主角現在碰到樓梯
					arrow.SetIsDownClick(false);							//下箭頭改為沒被選到
				}
				else {
					if (hotgirl.IsPK() == false && hotgirl.GetIsLayDown() == false) {
						if (hotgirl.GetMode() == 7)
						{
							hotgirl.SetMode(1);
							hotgirl.UnLockSnake(&lusnake[0], &schoolmap);
						}
						else if (hotgirl.GetMode() == 8)
						{
							hotgirl.SetMode(2);
							hotgirl.UnLockSnake(&lusnake[0], &schoolmap);
						}
					}
				}
			}
		}
		if (nChar == KEY_SPACE)				//若放開空白鍵
		{
			if (clock.GetIsTimeOut() != true && hotgirl.GetEnergyScore() > 0) {
				if (hotgirl.IsPK() == false && hotgirl.GetIsLayDown() == false) {
					hotgirl.SetShotting(false);
				}
			}
		}

		if (nChar == KEY_C) {				//若放開c鍵
			isShowSecretKey = false;		//不秀出密技圖
		}
	}
	

	void CGameStateRun::CloseAllAudio()
	{
		CAudio::Instance()->Stop(AUDIO_BACKGROUND);			//關閉所有音效
		CAudio::Instance()->Stop(AUDIO_REBACKGROUND);
		CAudio::Instance()->Stop(AUDIO_BACKGROUND2);
		CAudio::Instance()->Stop(AUDIO_REBACKGROUND2);
		CAudio::Instance()->Stop(AUDIO_BACKGROUND3);
		CAudio::Instance()->Stop(AUDIO_REBACKGROUND3);
		CAudio::Instance()->Stop(AUDIO_BACKGROUND4);
		CAudio::Instance()->Stop(AUDIO_REBACKGROUND4);
		CAudio::Instance()->Stop(AUDIO_TOKYO);
		CAudio::Instance()->Stop(AUDIO_PK);
		CAudio::Instance()->Stop(AUDIO_LIGHTING);
		CAudio::Instance()->Stop(AUDIO_HEART);
		CAudio::Instance()->Stop(AUDIO_LASER);
		CAudio::Instance()->Stop(AUDIO_SCREAM);
		CAudio::Instance()->Stop(AUDIO_TRANSFORM);
		CAudio::Instance()->Stop(AUDIO_TIMEUP);
		CAudio::Instance()->Stop(AUDIO_FINALCOUNTSCORE);
		CAudio::Instance()->Stop(AUDIO_GAMEOVER);
		CAudio::Instance()->Stop(AUDIO_Alien);
		CAudio::Instance()->Stop(AUDIO_DANGER);
		CAudio::Instance()->Stop(AUDIO_TEACHERYELL1);
		CAudio::Instance()->Stop(AUDIO_TEACHERYELL2);
		CAudio::Instance()->Stop(AUDIO_HEY);
	}

	void CGameStateRun::OnShow()
	{
		//
		//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
		//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
		//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。

		blackbroad.SetTopLeft(0, 0);		//印出黑板
		blackbroad.ShowBitmap();
		schoolmap.OnShow();					//印出地圖
		clock.OnShow();						//印出時鐘
		allMusic.OnShow();					//印出音量鍵
		allMusic.SetEnterMode(4);

		//------------------第一道----------------------//
		if (!hotgirl.IsPK()) {
			bitchies[0].OnShow(&schoolmap);
			bitchies[4].OnShow(&schoolmap);
			bitchies[8].OnShow(&schoolmap);
			bitchies[12].OnShow(&schoolmap);
			bitchies[15].OnShow(&schoolmap);
			if (hotgirl.GetIsHaveInvincible() == true)		//外國婊子，女主角有無敵過才出現
				bitchies[16].OnShow(&schoolmap);

			if (lusnake[0].GetEnergy() < 120)		//這個條件是因為變成跟隨者後,有些人物會列印的位置不正確,所以將他們從新在CHotGirl裡面再次列印出來
				lusnake[0].OnShow(&schoolmap);
			if (lusnake[1].GetEnergy() < 120)
				lusnake[1].OnShow(&schoolmap);
			if (lusnake[6].GetEnergy() < 120)
				lusnake[6].OnShow(&schoolmap);
			if (lusnake[7].GetEnergy() < 120)
				lusnake[7].OnShow(&schoolmap);
			if (lusnake[9].GetEnergy() < 120)
				lusnake[9].OnShow(&schoolmap);
			if (lusnake[10].GetEnergy() < 120)
				lusnake[10].OnShow(&schoolmap);
			if (lusnake[15].GetEnergy() < 120)
				lusnake[15].OnShow(&schoolmap);
			if (lusnake[16].GetEnergy() < 120)
				lusnake[16].OnShow(&schoolmap);
			if (lusnake[20].GetEnergy() < 120)
				lusnake[20].OnShow(&schoolmap);
			if (lusnake[24].GetEnergy() < 120)
				lusnake[24].OnShow(&schoolmap);
			if (lusnake[25].GetEnergy() < 120)
				lusnake[25].OnShow(&schoolmap);
			if (lusnake[26].GetEnergy() < 120 && hotgirl.GetIsHaveInvincible()==true)
				lusnake[26].OnShow(&schoolmap);

			//------------------第二道----------------------//
			if (!hotgirl.IsPK()) {
				//teacher.OnShow(&schoolmap);
				hotgirl.OnShow(&schoolmap,&teacher);
				
			}
			//------------------第三道----------------------//
			bitchies[2].OnShow(&schoolmap);
			bitchies[3].OnShow(&schoolmap);
			bitchies[9].OnShow(&schoolmap);
			bitchies[6].OnShow(&schoolmap);
			bitchies[11].OnShow(&schoolmap);
			bitchies[14].OnShow(&schoolmap);

			if (lusnake[2].GetEnergy() < 120)
				lusnake[2].OnShow(&schoolmap);
			if (lusnake[3].GetEnergy() < 120)
				lusnake[3].OnShow(&schoolmap);
			if (lusnake[12].GetEnergy() < 120)
				lusnake[12].OnShow(&schoolmap);
			if (lusnake[17].GetEnergy() < 120)
				lusnake[17].OnShow(&schoolmap);
			if (lusnake[18].GetEnergy() < 120)
				lusnake[18].OnShow(&schoolmap);
			if (lusnake[21].GetEnergy() < 120)
				lusnake[21].OnShow(&schoolmap);
			if (lusnake[23].GetEnergy() < 120)
				lusnake[23].OnShow(&schoolmap);
			//------------------第四道----------------------//
			bitchies[1].OnShow(&schoolmap);
			bitchies[5].OnShow(&schoolmap);
			bitchies[7].OnShow(&schoolmap);
			bitchies[10].OnShow(&schoolmap);
			bitchies[13].OnShow(&schoolmap);

			if (lusnake[4].GetEnergy() < 120)
				lusnake[4].OnShow(&schoolmap);
			if (lusnake[5].GetEnergy() < 120)
				lusnake[5].OnShow(&schoolmap);
			if (lusnake[8].GetEnergy() < 120)
				lusnake[8].OnShow(&schoolmap);
			if (lusnake[11].GetEnergy() < 120)
				lusnake[11].OnShow(&schoolmap);
			if (lusnake[13].GetEnergy() < 120)
				lusnake[13].OnShow(&schoolmap);
			if (lusnake[14].GetEnergy() < 120)
				lusnake[14].OnShow(&schoolmap);
			if (lusnake[19].GetEnergy() < 120)
				lusnake[19].OnShow(&schoolmap);
			if (lusnake[22].GetEnergy() < 120)
				lusnake[22].OnShow(&schoolmap);
			

		}



		if (!hotgirl.IsBulletEmpty())
		{
			hotgirl.ShowBullet(&schoolmap);			//發射子彈動畫
		}

		if (hotgirl.IsPK())							//印出PK時的人物
		{
			pk_background.OnShow(&schoolmap);
			hotgirl.OnShow(&schoolmap, &teacher);
			hotgirl.ShowPKPeople(&schoolmap);
			hotgirl.ShowPKLine(&schoolmap);


		}

		for (int s = 0; s < 8; s++) {				//印出右上角分數
			eightBit_score[s].OnShow();
		}

		if (hotgirl.GetIsInvincible() == false) {
			for (int energyNum = 0; energyNum < 10; energyNum++)
			{
				ten_love[energyNum].OnShow();		//印出左上角小愛心
			}
		}

		
		//如果現在是無敵模式
		if (hotgirl.GetIsInvincible() == true) {
			InvincibleLine.OnShow();
		}

		if (hotgirl.GetIsTouchStair() == true) {
			arrow.OnShow(&schoolmap);
		}

		if (isShowSecretKey == true) {
			SecretKey.SetTopLeft(0, 180);	//印出密技圖
			SecretKey.ShowBitmap();
		}
	}
}