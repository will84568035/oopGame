#ifndef CENDIND_H
#define CENDIND_H

enum AUDIO_ID2 {				// 定義各種音效的編號
	AUDIO_ENDING1 = 20,				//輸的結局音效
	AUDIO_ENDING23 = 21,			//結局23音效
	AUDIO_ENDING4 = 24,				//結局4音效
	AUDIO_ENDING5 = 25,				//結局5音效
	AUDIO_ENDING6 = 29,				//結局6音效
};
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 結局種類的class
	/////////////////////////////////////////////////////////////////////////////
	class CEnding {
	public:
		CEnding();
		void LoadBitmap();					//載入結局圖片
		void LoadAudio();					//載入六種結局音效
		void OnShow();						//印出結局圖片
		void OnMove();						//播放結局動畫
		void SetEnding(int total_score);	//依照得到的總分設定結局種類
		void StopAllAudio();				//關閉所有音效
		int GetEnding();					//得到現在的結局種類
		
	protected:
		int ending;							//結局種類1~6
		CAnimation endingAnimation[6];		//結局動畫
		CMovingBitmap	tip;				//小提示圖
	};
}
#endif 