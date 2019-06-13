#ifndef GIRLBULLET_H
#define GIRLBULLET_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 子彈的class
	/////////////////////////////////////////////////////////////////////////////

	class GirlBullet
	{
	public:
		GirlBullet(int Gx , int Gy , int Bx ,int By);
		int  GetX1();					// 子彈左上角 x 座標
		int  GetY1();					// 子彈左上角 y 座標
		int  GetX2();					// 子彈右下角 x 座標
		int  GetY2();					// 子彈右下角 y 座標
		void LoadBitmap();				// 載入圖形
		void OnMove(SchoolMap *m);		// 移動子彈
		void OnShow(SchoolMap *m);		// 將子彈圖形貼到畫面
		void SetMode();					//設定子彈軌道方向
		bool IsFinished();				//子彈是否到打到人	
	protected:
		int Sx, Sy;					//子彈開始座標 
		int Ex, Ey;					//子彈結束座標
		int x, y;					//子彈位置
		CAnimation bullet;			//子彈圖片
		int STEP_X, STEP_Y;			//子彈x,y移動單位
		int mode;					//1:右上,2:右下,3:左下,4:左上
		bool isFinished;			//是否碰到目標
		};
}
#endif