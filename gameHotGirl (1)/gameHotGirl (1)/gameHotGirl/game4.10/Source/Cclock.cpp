#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Cclock.h"


namespace game_framework {

	Cclock::Cclock()
	{
		Sx = 450;							//時鐘初始值
		Sy = 0;
		isStartCount = false;
		IsTimeOut = false;
		isPlayTimeUpAudio = false;
		isAudioTimeUp = false;
		isPlayedGameOverAudio = false;
		isGameOverAudioTimeUp = false;
	}
	

	
	void Cclock::LoadBitmap()
	{
		clocks[0].AddBitmap(IDB_CLOCK0, RGB(0, 0, 0));
		clocks[1].AddBitmap(IDB_CLOCK1, RGB(0, 0, 0));
		clocks[2].AddBitmap(IDB_CLOCK2, RGB(0, 0, 0));
		clocks[3].AddBitmap(IDB_CLOCK3, RGB(0, 0, 0));
		clocks[4].AddBitmap(IDB_CLOCK4, RGB(0, 0, 0));
		clocks[5].AddBitmap(IDB_CLOCK5, RGB(0, 0, 0));
		clocks[6].AddBitmap(IDB_CLOCK6, RGB(0, 0, 0));
		clocks[7].AddBitmap(IDB_CLOCK7, RGB(0, 0, 0));
		clocks[8].AddBitmap(IDB_CLOCK8, RGB(0, 0, 0));
		clocks[9].AddBitmap(IDB_CLOCK9, RGB(0, 0, 0));
		clocks[10].AddBitmap(IDB_CLOCK10, RGB(0, 0, 0));
		clocks[11].AddBitmap(IDB_CLOCK11, RGB(0, 0, 0));
		clocks[12].AddBitmap(IDB_CLOCK12, RGB(0, 0, 0));
	}


	void Cclock::OnShow()
	{
		LastTime = difftime(EndTime, StartTime);
		

		if (LastTime <= 7500) {								//依照時間過多久顯示時鐘圖片
			clocks[0].SetTopLeft(Sx, Sy);
			clocks[0].OnShow();
		}
		else if (LastTime <= 15000) {
			clocks[1].SetTopLeft(Sx, Sy);
			clocks[1].OnShow();
		}
		else if (LastTime <= 22500) {
			clocks[2].SetTopLeft(Sx, Sy);
			clocks[2].OnShow();
		}
		else if (LastTime <= 30000) {
			clocks[3].SetTopLeft(Sx, Sy);
			clocks[3].OnShow();
		}
		else if (LastTime <= 37500) {
			clocks[4].SetTopLeft(Sx, Sy);
			clocks[4].OnShow();
		}
		else if (LastTime <= 45000) {
			clocks[5].SetTopLeft(Sx, Sy);
			clocks[5].OnShow();
		}
		else if (LastTime <= 52500) {
			clocks[6].SetTopLeft(Sx, Sy);
			clocks[6].OnShow();
		}
		else if (LastTime <= 60000) {
			clocks[7].SetTopLeft(Sx, Sy);
			clocks[7].OnShow();
		}
		else if (LastTime <= 67500) {
			clocks[8].SetTopLeft(Sx, Sy);
			clocks[8].OnShow();
		}
		else if (LastTime <= 75000) {
			clocks[9].SetTopLeft(Sx, Sy);
			clocks[9].OnShow();
		}
		else if (LastTime <= 82500) {
			clocks[10].SetTopLeft(Sx, Sy);
			clocks[10].OnShow();
		}
		else if (LastTime < 90000) {
			clocks[11].SetTopLeft(Sx, Sy);
			clocks[11].OnShow();
		}
		else if (LastTime >= 90000) {
			clocks[12].SetTopLeft(Sx, Sy);
			clocks[12].OnShow();
			IsTimeOut = true;
			isStartCount = false;
		}

		if (IsTimeOut == true) {									//遊戲時間是否結束
			if (isPlayTimeUpAudio == false) {						//若還沒播過時間到音效
				isPlayTimeUpAudio = true;
				CAudio::Instance()->Play(AUDIO_TIMEUP, false);		//播放時間到的鐘聲
				AudioStartTime = clock();							//取得時鐘撥放開始時間
			}

			AudioLastTime = difftime(AudioEndTime, AudioStartTime);	//紀錄音效撥了多久

			if (AudioLastTime >= 22000) {							//若音樂放完了
				isAudioTimeUp = true;								//音樂時間到=true
				CAudio::Instance()->Stop(AUDIO_TIMEUP);				//關閉時間到的鐘聲
			}
		}
		AudioEndTime = clock();										//取得時鐘撥放多久時間

		if (isPlayedGameOverAudio == true) {						//若遊戲失敗的音效開始計時
			GameOverAudioEndTime = clock();							//紀錄已經撥放多久
			GameOverAudioLastTime= difftime(GameOverAudioEndTime, GameOverAudioStartTime);
			if (GameOverAudioLastTime >= 12000) {					//若音樂放完了
				isGameOverAudioTimeUp = true;
				CAudio::Instance()->Stop(AUDIO_GAMEOVER);			//關閉遊戲失敗的音效
			}
		}
	}


	void Cclock::ClockReSet()				//時鐘值重設
	{
		isStartCount = false;
		IsTimeOut = false;
		isPlayTimeUpAudio = false;
		isAudioTimeUp = false;
		isPlayedGameOverAudio = false;
		isGameOverAudioTimeUp = false;
	}


	void Cclock::CountTime()
	{
		EndTime = clock();
	}

	void Cclock::StartCountTime()
	{
		if (isStartCount == false) {
			StartTime = clock();
			SetisStartCount(true);
		}
	}

	void Cclock::SetisStartCount(bool flag)
	{
		isStartCount = flag;
	}

	bool Cclock::GetisStartCount()
	{
		return isStartCount;
	}

	bool Cclock::GetIsTimeOut()
	{	
		return IsTimeOut;
	}

	void Cclock::DemoSetIsTimeOut(bool flag)
	{
		IsTimeOut = true;
	}


	void Cclock::SetIsPlayTimeUpAudio(bool isPlay)
	{
		isPlayTimeUpAudio = isPlay;
	}

	bool Cclock::GetIsAudioTimeUp()
	{
		return isAudioTimeUp;
	}

	void Cclock::StartPlayGameOverAudio()
	{
		if (isPlayedGameOverAudio == false) {
			isPlayedGameOverAudio = true;
			GameOverAudioStartTime = clock();
		}
	}

	bool Cclock::GetIsGameOverAudioTimeUp()
	{
		return isGameOverAudioTimeUp;
	}

}