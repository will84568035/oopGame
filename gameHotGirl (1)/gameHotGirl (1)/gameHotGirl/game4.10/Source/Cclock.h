#ifndef CCLOCK_H
#define CCLOCK_H
#include <time.h>
#include "CHotGirl.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 時鐘的class
	/////////////////////////////////////////////////////////////////////////////

	class Cclock
	{
	public:
		Cclock();
		void LoadBitmap();							// 載入圖形
		void OnShow();								// 將時鐘貼到畫面
		void ClockReSet();							//時鐘重設初始值
		void CountTime();							//讀取遊戲開始後得過了多少時間

		void StartCountTime();						//開始遊戲計時的時間
		void SetisStartCount(bool flag);			//設定是否開始計時遊戲的時間
		bool GetisStartCount();						//得到是否開始計時遊戲的時間
	
		void SetIsPlayTimeUpAudio(bool isPlay);		//是否播放鐘聲音樂
		bool GetIsAudioTimeUp();					//得到鐘聲音樂是否放完

		void StartPlayGameOverAudio();				//紀錄遊戲失敗音效的播放起始時間點
		bool GetIsGameOverAudioTimeUp();			//得到遊戲輸了的音樂是否播完

		bool GetIsTimeOut();						//回傳是否時間到
		void DemoSetIsTimeOut(bool flag);			//設定是否時間到
	protected:
		int Sx, Sy;									//時鐘座標
		CAnimation clocks[13];						//時鐘圖片
		clock_t StartTime, EndTime;								//遊戲開始、結束時間點
		clock_t AudioStartTime, AudioEndTime;					//時鐘開始、結束撥放時間點
		clock_t GameOverAudioStartTime, GameOverAudioEndTime;	//遊戲輸了音效開始、結束撥放的時間點
		double LastTime, AudioLastTime, GameOverAudioLastTime;	//各種時間點持續多久

		bool isStartCount;							//遊戲是否開始計時
		bool IsTimeOut;								//遊戲時間是否結束

		bool isPlayTimeUpAudio;						//是否播放時間到音校
		bool isAudioTimeUp;							//時間到音校是否播完

		bool isPlayedGameOverAudio;					//是否播放遊戲輸到音校
		bool isGameOverAudioTimeUp;					//遊戲輸音效是否播完
	};
}
#endif