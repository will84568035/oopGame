#ifndef CINVINCIBLELINE_H
#define CINVINCIBLELINE_H
#include <time.h>
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 無敵模式時間條的class
	/////////////////////////////////////////////////////////////////////////////

	class CInvincibleLine
	{
	public:
		CInvincibleLine();
		void LoadBitmap();				// 載入圖形
		void OnShow();		            // 將無敵條貼到畫面
		int GetX2();					//回傳圖片的
		void InvincibleLineReSet();		//無敵條重設

		void StartCountTime();			//無敵開始計時的時間
		void SetisStartCount(bool flag);//設定無敵開始計時的時間
		bool GetisStartCount();			//得到無敵開始計時的時間
		void CountTime();				//讀取無敵開始後得過了多少時間
		
		bool GetIsTimeOut();			//回傳無敵是否時間到

	protected:
		int Sx, Sy;
		CAnimation InvincibleLine[40];	//無敵條圖片
		CAnimation InvincibleBorder;
		CAnimation Flower1;
		CAnimation Flower2;

		clock_t StartTime, EndTime;		//計時用的時間點
		double LastTime;				//計時時間差
		bool isStartCount;				//使否開始計時
		bool IsTimeOut;					//無敵是否時間到
	};
}
#endif