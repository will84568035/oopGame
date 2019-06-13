#ifndef CALLMUSIC_H
#define CALLMUSIC_H
#include "CHotGirl.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 音量鍵的class
	/////////////////////////////////////////////////////////////////////////////

	class CAllMusic
	{
	public:
		CAllMusic();
		void LoadBitmap();				// 載入音量鍵圖形
		void OnShow();		            // 將音量鍵貼到畫面
		bool GetisCloseMusic();			//取得是否關閉全部音樂
		void SetisCloseMusic();			//設定是否關閉全部音樂
		void SetEnterMode(int mode);	//設定是哪個階段

	protected:
		int Sx, Sy;										//個別分數位置
		CAnimation AllMusicPlay, AllMusicClose;			//音量鍵圖片
		CAnimation LittleMusicPlay, LittleMusicClose;	//小音量鍵圖片
		bool isCloseMusic;								//全部音樂是否被關掉
		int enterMode;									//進入到哪個階段 1=起始畫面 2=規則 3=關於我們 4=遊戲中 5=結束
	};
}
#endif