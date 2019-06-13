#ifndef CTEACHER_H
#define CTEACHER_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 老師的class
	/////////////////////////////////////////////////////////////////////////////

	class CTeacher
	{
	public:
		CTeacher();
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
		void SetisTouch(bool flag);									//設定是否碰到人
		bool GetisTouch();											//回傳是碰到人
		
	protected:
		CAnimation WLTeacher;
		CAnimation	WRTeacher;
		CAnimation shadow;
		bool isTouch;				//是否碰到人
		int x, y;					// 人物左上角座標
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		int mode;					//人物狀態 1= 左邊走路 2 = 右邊走路
	};
}
#endif