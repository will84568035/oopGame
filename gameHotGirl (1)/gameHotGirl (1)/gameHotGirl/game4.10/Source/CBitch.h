#ifndef CBITCH_H
#define CBITCH_H
#include "CSchoolMap.h"
#include "CLuSnake.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 女生敵人的class
	/////////////////////////////////////////////////////////////////////////////

	class CBitch
	{
	public:
		CBitch();
		int  GetX1();												// 人物左上角 x 座標
		int  GetY1();												// 人物左上角 y 座標
		int  GetX2();												// 人物右下角 x 座標
		int  GetY2();												// 人物右下角 y 座標
		void Initialize(int nx, int ny, bool flap1, bool flap2);	// 設定人物為初始值
		void LoadBitmap();											// 載入圖形
		void OnMove(SchoolMap *m);									// 移動人物
		void OnShow(SchoolMap *m);									// 將人物圖形貼到畫面

		void SetMovingLeft(bool flag);								// 設定是否正在往左移動
		void SetMovingRight(bool flag);								// 設定是否正在往右移動
		void SetXY(int nx, int ny);									// 設定人物左上角座標

		void SetMode(int mode);										//設定人物狀態
		int GetMode();												//回傳現在的人物狀態
		void SetSensor(bool flag);									//設定是否在偵測
		bool GetSensor();											//回傳是否在偵測


		void SetShowCount();										//設定動畫撥放速度
		bool IsShowFinish();										//回傳是否播放完圖片 mode = 5 or mode = 6

		void AttackBoy(CLuSnake *AttackBoy);						//攻擊目標男生
		
		void SetMoveMode(int mode);									//設定移動模式

		void SetBeforePKmode(int mode);								//設定pk前的狀態
		int GetBeforePKmode();										//得到pk前的狀態
		void SetPKPosition(int x, int y);							//設定pk時的座標

		void SetIsForeign(bool flag);								//設定他是不是外國女生
		bool GetIsForeign();										//取得他是不是外國女生

	protected:
		CAnimation RStBitch;
		CAnimation	RWBitch;
		CAnimation LStBitch;
		CAnimation	LWBitch;
		CAnimation LFrightenedBitch;
		CAnimation RFrightenedBitch;
		CAnimation PKBitch;
		CAnimation WLWBitch;
		CAnimation WRWBitch;
		
		
		int x, y;					// 人物座標
		int pkX, pkY;				//pk時的座標
		int rangeX1, rangeX2;		//可移動的x座標範圍
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isSensor;				//是否正在偵測
		bool isForeign;				//是不是外國女生
		int moveMode;				//1 = 還沒pk 2 = pk贏了 3 = 右上飛天 4 = 左上飛天
		int beforePKmode;			//1 =面相左邊  2=面向右邊
		int mode;					//人物狀態 1= 左邊旋轉 2 = 右邊旋轉 3 = 左邊走路 4 = 右邊走路 5 = 左邊被驚嚇 6 = 右邊被驚嚇 7 = PK模式  13=左邊笑著走 14=右邊笑著走
	};
}
#endif