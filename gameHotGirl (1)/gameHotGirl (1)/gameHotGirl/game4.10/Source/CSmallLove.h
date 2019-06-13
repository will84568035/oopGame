#ifndef CSMALLLOVE_H
#define CSMALLLOVE_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 左上角小愛心的class
	/////////////////////////////////////////////////////////////////////////////

	class CSmallLove
	{
	public:
		void Initialize(int x, int y);	//位元分數的初始化
		void LoadBitmap();				// 載入圖形
		void OnMove();					//撥放圖形動畫
		void OnShow();					// 將圖形貼到畫面
		void SetMode(int mode);			//設定圖片的樣式
		void SetDanger(bool flag);		//設定是否危險

	protected:
		int Sx, Sy;						
		int mode;						//愛心集滿程度
		bool isDanger;					//是否有危險
		CAnimation love[10];			//愛心圖片
		CAnimation dangerLove[10];		//危險的愛心圖片
	};
}
#endif