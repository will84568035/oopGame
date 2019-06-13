#ifndef CSCORE_H
#define CSCORE_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// じだ计class
	/////////////////////////////////////////////////////////////////////////////

	class CScore
	{
	public:
		void Initialize(int x,int y);	//じだ计﹍て
		void LoadBitmap();				// 更瓜
		void OnShow();					// 盢じだ计瓜禟礶
		void SetMode(int mode);			//砞﹚じだ计家Α(计)
		
	protected:		
		int Sx, Sy;						//だ计竚
		int mode;						//计家Α(0~9)
		CAnimation number[10];			//计瓜
	};
}
#endif