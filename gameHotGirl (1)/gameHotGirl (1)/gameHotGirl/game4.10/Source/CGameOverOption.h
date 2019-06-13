#ifndef CGAMEOVEROPTION_H
#define CGAMEOVEROPTION_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 結局的選項class
	/////////////////////////////////////////////////////////////////////////////

	class CGameOverOption
	{
	public:
		CGameOverOption();
		void LoadBitmap();						// 載入圖形
		void OnShow();							// 將時選項到畫面
		void OnMove();							//播放圖片動畫

		void SetIsBackClick(bool flag);			//設定是否點擊"重新開始"
		bool GetIsBackClick();					//到是否點擊"重新開始"

		void SetIsLeaveClick(bool flag);		//設定是否點擊"離開遊戲"
		bool GetIsLeaveClick();					//得到是否點擊"離開遊戲"
		
	protected:
		CAnimation optionBack, optionLeave, optionBack_click, optionLeave_click;
		bool isBackClick, isLeaveClick;			//按鈕是否被點選
	};
}
#endif
