#ifndef PKBACKGROUND_H
#define PKBACKGROUND_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// PK模式的背景class
	/////////////////////////////////////////////////////////////////////////////

	class PKbackground
	{
	public:
		PKbackground();
		void LoadBitmap();								// 載入pk背景圖片
		void OnMove();									// 播放pk背景圖片
		void OnShow(SchoolMap *m);						// 印出載入pk背景圖片
		void Setfloor(int floor);						//設定現在的樓層

	protected:
		CAnimation background;
		int x, y;					// 背景左上角座標
		int floor;					//樓層
	};
}
#endif
