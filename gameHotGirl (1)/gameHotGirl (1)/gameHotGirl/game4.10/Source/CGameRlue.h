#ifndef CGAMERLUE_H
#define CGAMERLUE_H

enum AUDIO_ID4 {				// 定義各種音效的編號
	AUDIO_Book = 30,				//翻書音效
};

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 規則說明1~6頁的class
	/////////////////////////////////////////////////////////////////////////////

	class CGameRlue
	{
	public:
		CGameRlue();
		void LoadBitmap();						// 載入圖形
		void OnShow();							// 將規則印到畫面
		void OnMove();							//播放圖片動畫
		void GoNextPage();						//換到下一張規則圖
		void GoLastPage();						//換到上一張規則圖

	protected:
		CAnimation rlue[6];						//六張規則動畫
		int page;								//第幾張規則圖 1~6
	};
}
#endif

