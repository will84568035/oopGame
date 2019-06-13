#ifndef CGAMEINITOPTION_H
#define CGAMEINITOPTION_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 出始畫面的選項集class
	/////////////////////////////////////////////////////////////////////////////

	class CGameInitOption
	{
	public:
		CGameInitOption();
		void LoadBitmap();						// 載入圖形
		void OnShow();							// 將時選項到畫面
		void OnMove();							//播放圖片動畫

		void SetIsStartClick(bool flag);		//設定是否點擊"開始遊戲"
		bool GetIsStartClick();					//到是否點擊"開始遊戲"

		void SetIsAboutClick(bool flag);		//設定是否點擊"關於我們"
		bool GetIsAboutClick();					//到是否點擊"關於我們"

		void SetIsLeaveClick(bool flag);		//設定是否點擊"離開遊戲"
		bool GetIsLeaveClick();					//得到是否點擊"離開遊戲"

		void SetEnterMode(int mode);			//設定現在要顯示哪種的選項群組

	protected:
		CAnimation optionStart, optionAbout, optionLeave;						//按鈕群組mode0 :
		CAnimation optionStart_click, optionAbout_click, optionLeave_click;		//遊戲開始、關於我們、結束遊戲
		CAnimation optionDirectStart_click;										//按鈕群組mode1: 直接開始
		CAnimation optionReturn_click;											//按鈕群組mode2: 返回
		bool isStartClick, isAboutClick, isLeaveClick;							//按鈕是否被點選
		int enterMode;											//進入到哪個選項 0=還沒選 1=開始遊戲 2=關於我們
	};
}
#endif
