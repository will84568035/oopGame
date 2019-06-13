#ifndef CCOMBO_H
#define CCOMBO_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// PK模式時的連打文字class
	/////////////////////////////////////////////////////////////////////////////
	class Ccombo
	{
	public:
		Ccombo();						
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 撥放圖形動畫
		void OnShow();					// 將連打文字圖形貼到畫面
		void SetX(int x);
		
	protected:
		int Sx, Sy;					
		CAnimation comboText;
	};
}
#endif

