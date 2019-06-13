#ifndef CPKLINE_H
#define CPKLINE_H
#include "CSchoolMap.h"
#include "Ccombo.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// PK時連打條的class
	/////////////////////////////////////////////////////////////////////////////

	class CPKline
	{
	public:
		CPKline(int x, int y, int energy);			//座標、連打條的分數
		void SetLineEnergy(int luSnakeLoveEnergy);	//設定連打條的分數
		void LoadBitmap();							// 載入圖形
		void OnMove();								//播放圖形動畫
		void OnShow(SchoolMap *m);					// 將圖形貼到畫面
		bool IsEnergyFull();						//回傳愛心能量是否集滿
		int getEnergy();							//回傳連打條的分數
		bool IsFinish();							//回傳是否連打完
	protected:
		int Sx, Sy;					//愛心位置,累計分數
		int lineEnergy;				//連打條的分數
		bool isLineFull;			//愛心能量是否滿
		CAnimation pkLine[25];		//連打條的圖
		bool isFinish;				//是否連打完
		Ccombo comboText;			//連打文字

	};
}
#endif
