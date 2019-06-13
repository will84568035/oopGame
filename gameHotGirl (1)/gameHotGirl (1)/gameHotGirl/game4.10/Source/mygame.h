/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
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
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/


#include "CHotGirl.h"
#include "CSchoolMap.h"
#include "CLuSnake.h"
#include "CScore.h"
#include "CSmallLove.h"
#include "CBitch.h"
#include "PKbackground.h"
#include "CTeacher.h"
#include "Cclock.h"
#include "CInvincibleLine.h"
#include "CArrow.h"
#include "CAllMusic.h"
#include "CGameOverMap.h"
#include "CEnding.h"
#include "CGameOverOption.h"
#include "CGameInitOption.h"
#include "CGameRlue.h"

static int total_score;					//遊戲總分

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	//主流程控制
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID1 {					// 定義各種音效的編號
		AUDIO_BACKGROUND = 1,			// 背景音樂1 陷阱妹
		AUDIO_BACKGROUND2 = 2,			// 背景音樂2 辣台妹
		AUDIO_BACKGROUND3 = 3,			// 背景音樂3 皇后區的皇后
		AUDIO_BACKGROUND4 = 4,			// 背景音樂4 場上稱霸


		AUDIO_REBACKGROUND = 5,			// RE背景音樂1 陷阱妹
		AUDIO_REBACKGROUND2 = 6,		// RE背景音樂2 辣台妹
		AUDIO_REBACKGROUND3 = 7,		// RE背景音樂3 皇后區的皇后
		AUDIO_REBACKGROUND4 = 8,		// RE背景音樂4 場上稱霸

		AUDIO_FIRSTMUSIC=22,			//開場音樂
		
	};

	

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyDown(UINT, UINT, UINT);				//若按下鍵盤
	protected:
		void OnMove();									//播放圖片動畫
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int enterMode;									//進入到哪個選項 0=還沒選 1=開始遊戲 2=關於我們
		CMovingBitmap initialBackground;				// 起始畫面的封面
		CMovingBitmap aboutBackground;					// 關於我們的的封面
		CGameInitOption	option;							//開始選項
		CGameRlue	rule;								//遊戲規則
		CAllMusic allMusic;								//音量鍵
		bool isPlayedFirstTimeMusic;					//是否播過開場音樂
		
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);				//按下鍵盤的反應
		void OnKeyUp(UINT, UINT, UINT);					//放開鍵盤的反應
		void CloseAllAudio();							//關閉所有遊戲音效
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap	gamebackground;					//教室背景
		CMovingBitmap	SecretKey;						//密技集圖片
		CTeacher		teacher;						//老師
		CHotGirl		hotgirl;						//女主角
		vector<CLuSnake*> lusnakes;						//魯蛇陣列
		CLuSnake		lusnake[27];					//魯蛇團
		CScore			eightBit_score[8];				//八位分數
		CSmallLove		ten_love[10];					//左上角愛心
		CBitch			bitchies[17];					//女生敵人團
		PKbackground    pk_background;					//PK的背景圖
		SchoolMap		schoolmap;						//背景
		CMovingBitmap	blackbroad;						//黑板
		Cclock			clock;							//時鐘
		CArrow			arrow;							//樓梯箭頭
		CAllMusic		allMusic;						//全部的音樂
		CInvincibleLine InvincibleLine;					//無敵時間條
		bool isShowSecretKey;							//密技是否要秀出
		int				picX, picY;
		int				whichBackgroungMusic;	
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnKeyDown(UINT, UINT, UINT);

	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CEnding ending;									//結局種類
		CGameOverOption	option;							//結局選項
		CScore eightBit_score[8];						//八位分數
		CAllMusic allMusic;								//音量鍵
	};

}