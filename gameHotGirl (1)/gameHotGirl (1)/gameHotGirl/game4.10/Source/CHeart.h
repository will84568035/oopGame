#ifndef CHEART_H
#define CHEART_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 愛心的class
	/////////////////////////////////////////////////////////////////////////////

	class CHeart
	{
	public:
		CHeart(int x, int y,int energy,int score, int small_energy);	//愛心能量、愛心的價值分數,小愛心的分數
		int  GetX1();									// 愛心左上角 x 座標
		int  GetX2();									// 愛心右下角 x 座標
		void LoadBitmap();								// 載入圖形
		void OnMove(SchoolMap *m, int Uy, int Dy);		// 撥放愛心動畫
		void OnShow(SchoolMap *m);						// 將愛心圖形貼到畫面

		void SetHeartLoveEnergy(int luSnakeLoveEnergy);//設定愛心的能量值
		bool IsEnergyFull();						   //愛心能量是否集滿
		void SetIsPKfull(bool flag);				   //設定是否pk集滿
		int GetScore();								   //得到這顆愛心的價值分數
		int GetSmallEnergy();						   //得到小愛心的能量

		bool IsFinish();								//愛心是否掉落結束
	protected:
		CAnimation heart[14];				//愛心圖片
		int heartEnergy;					//普通愛心能量
		int smallEnergy;					//小愛心能量
		int Sx, Sy,Score;					//愛心位置,累計分數
		bool isEnergyFull;					//愛心能量是否滿
		bool isPKfull;						//被pk完的愛心
		
		int velocity;						//愛心掉落加速度
		bool rising;						//愛心是否上升
		bool isFinish;						//愛心是否掉落結束
	};
}
#endif
