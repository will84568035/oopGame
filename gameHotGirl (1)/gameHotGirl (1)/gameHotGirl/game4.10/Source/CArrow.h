#ifndef CARROW_H
#define CARROW_H
#include "CSchoolMap.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 加絙繷class
	/////////////////////////////////////////////////////////////////////////////

	class CArrow
	{
	public:
		CArrow();
		void LoadBitmap();						// 更瓜
		void OnShow(SchoolMap *m);		        // 盢絙繷禟礶
		void SetFloor(int floorNum);			// 砞﹚à瞷加糷
		void SetArrowPosition(int LR);			//砞﹚絙繷瓜竚
		void SetIsUpClick(bool flag);			//砞﹚琌翴阑加
		void SetIsDownClick(bool flag);			//砞﹚琌翴阑加
		int GetClickUpDown();					//眔瞷琌匡拒加临琌加
		

	protected:
		CAnimation arrowUP, arrowDown, arrowUP_click, arrowDown_click;
		int Ux, Uy, Dx, Dy;				//加秙x,y畒夹
		bool isUpClick, isDownClick;	//琌砆翴阑
		int floor;						//à瞷┮加糷
	};
}
#endif