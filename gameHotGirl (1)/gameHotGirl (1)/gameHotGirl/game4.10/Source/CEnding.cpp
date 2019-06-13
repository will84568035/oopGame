#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEnding.h"

namespace game_framework {

	CEnding::CEnding(){
		ending = 1;
	}

	void CEnding::LoadBitmap()
	{
		endingAnimation[0].AddBitmap(IDB_sadEnd1);		//結局一:自己哭著走
		endingAnimation[0].AddBitmap(IDB_sadEnd2);
		endingAnimation[0].AddBitmap(IDB_sadEnd3);
		endingAnimation[0].AddBitmap(IDB_sadEnd4);
		endingAnimation[0].AddBitmap(IDB_sadEnd5);
		endingAnimation[0].AddBitmap(IDB_sadEnd6);
		endingAnimation[0].AddBitmap(IDB_sadEnd7);
		endingAnimation[0].AddBitmap(IDB_sadEnd8);
		endingAnimation[0].AddBitmap(IDB_sadEnd9);
		endingAnimation[0].AddBitmap(IDB_sadEnd10);
		endingAnimation[0].AddBitmap(IDB_sadEnd11);
		endingAnimation[0].AddBitmap(IDB_sadEnd12);
		endingAnimation[0].AddBitmap(IDB_sadEnd13);
		endingAnimation[0].AddBitmap(IDB_sadEnd14);
		endingAnimation[0].AddBitmap(IDB_sadEnd15);
		endingAnimation[0].AddBitmap(IDB_sadEnd16);
		endingAnimation[0].AddBitmap(IDB_sadEnd17);
		endingAnimation[0].AddBitmap(IDB_sadEnd18);
		endingAnimation[0].AddBitmap(IDB_sadEnd19);
		endingAnimation[0].AddBitmap(IDB_sadEnd20);
		endingAnimation[0].AddBitmap(IDB_sadEnd21);
		endingAnimation[0].AddBitmap(IDB_sadEnd22);
		endingAnimation[0].AddBitmap(IDB_sadEnd23);
		endingAnimation[0].AddBitmap(IDB_sadEnd24);
		endingAnimation[0].AddBitmap(IDB_sadEnd25);
		endingAnimation[0].AddBitmap(IDB_sadEnd26);
		endingAnimation[0].AddBitmap(IDB_sadEnd27);
		endingAnimation[0].SetDelayCount(6);

		
		endingAnimation[1].AddBitmap(IDB_4wEnd1);				//結局二:魯蛇圍著走
		endingAnimation[1].AddBitmap(IDB_4wEnd2);
		endingAnimation[1].AddBitmap(IDB_4wEnd3);
		endingAnimation[1].AddBitmap(IDB_4wEnd4);
		endingAnimation[1].AddBitmap(IDB_4wEnd5);
		endingAnimation[1].AddBitmap(IDB_4wEnd6);
		endingAnimation[1].AddBitmap(IDB_4wEnd7);
		endingAnimation[1].AddBitmap(IDB_4wEnd8);
		endingAnimation[1].AddBitmap(IDB_4wEnd9);
		endingAnimation[1].AddBitmap(IDB_4wEnd10);
		endingAnimation[1].AddBitmap(IDB_4wEnd11);
		endingAnimation[1].AddBitmap(IDB_4wEnd12);
		endingAnimation[1].AddBitmap(IDB_4wEnd13);
		endingAnimation[1].AddBitmap(IDB_4wEnd14);
		endingAnimation[1].AddBitmap(IDB_4wEnd15);
		endingAnimation[1].AddBitmap(IDB_4wEnd16);
		endingAnimation[1].AddBitmap(IDB_4wEnd17);
		endingAnimation[1].AddBitmap(IDB_4wEnd18);
		endingAnimation[1].AddBitmap(IDB_4wEnd19);
		endingAnimation[1].AddBitmap(IDB_4wEnd20);
		endingAnimation[1].AddBitmap(IDB_4wEnd21);
		endingAnimation[1].AddBitmap(IDB_4wEnd22);
		endingAnimation[1].AddBitmap(IDB_4wEnd23);
		endingAnimation[1].SetDelayCount(7);

		endingAnimation[2].AddBitmap(IDB_75wEnd1);			//結局三:藍髮帥哥牽著走
		endingAnimation[2].AddBitmap(IDB_75wEnd2);
		endingAnimation[2].AddBitmap(IDB_75wEnd3);
		endingAnimation[2].AddBitmap(IDB_75wEnd4);
		endingAnimation[2].AddBitmap(IDB_75wEnd5);
		endingAnimation[2].AddBitmap(IDB_75wEnd6);
		endingAnimation[2].AddBitmap(IDB_75wEnd7);
		endingAnimation[2].AddBitmap(IDB_75wEnd8);
		endingAnimation[2].AddBitmap(IDB_75wEnd9);
		endingAnimation[2].AddBitmap(IDB_75wEnd10);
		endingAnimation[2].AddBitmap(IDB_75wEnd11);
		endingAnimation[2].AddBitmap(IDB_75wEnd12);
		endingAnimation[2].AddBitmap(IDB_75wEnd13);
		endingAnimation[2].AddBitmap(IDB_75wEnd14);
		endingAnimation[2].AddBitmap(IDB_75wEnd15);
		endingAnimation[2].AddBitmap(IDB_75wEnd16);
		endingAnimation[2].AddBitmap(IDB_75wEnd17);
		endingAnimation[2].AddBitmap(IDB_75wEnd18);
		endingAnimation[2].AddBitmap(IDB_75wEnd19);
		endingAnimation[2].AddBitmap(IDB_75wEnd20);
		endingAnimation[2].AddBitmap(IDB_75wEnd21);
		endingAnimation[2].AddBitmap(IDB_75wEnd22);
		endingAnimation[2].AddBitmap(IDB_75wEnd23);
		endingAnimation[2].AddBitmap(IDB_75wEnd24);
		endingAnimation[2].SetDelayCount(7);


		endingAnimation[3].AddBitmap(IDB_10wEnd1);			//結局四:橘髮帥哥牽著走
		endingAnimation[3].AddBitmap(IDB_10wEnd2);
		endingAnimation[3].AddBitmap(IDB_10wEnd3);
		endingAnimation[3].AddBitmap(IDB_10wEnd4);
		endingAnimation[3].AddBitmap(IDB_10wEnd5);
		endingAnimation[3].AddBitmap(IDB_10wEnd6);
		endingAnimation[3].AddBitmap(IDB_10wEnd7);
		endingAnimation[3].AddBitmap(IDB_10wEnd8);
		endingAnimation[3].AddBitmap(IDB_10wEnd9);
		endingAnimation[3].AddBitmap(IDB_10wEnd10);
		endingAnimation[3].AddBitmap(IDB_10wEnd11);
		endingAnimation[3].AddBitmap(IDB_10wEnd12);
		endingAnimation[3].AddBitmap(IDB_10wEnd13);
		endingAnimation[3].AddBitmap(IDB_10wEnd14);
		endingAnimation[3].AddBitmap(IDB_10wEnd15);
		endingAnimation[3].AddBitmap(IDB_10wEnd16);
		endingAnimation[3].AddBitmap(IDB_10wEnd17);
		endingAnimation[3].AddBitmap(IDB_10wEnd18);
		endingAnimation[3].AddBitmap(IDB_10wEnd19);
		endingAnimation[3].AddBitmap(IDB_10wEnd20);
		endingAnimation[3].AddBitmap(IDB_10wEnd21);
		endingAnimation[3].AddBitmap(IDB_10wEnd22);
		endingAnimation[3].AddBitmap(IDB_10wEnd23);
		endingAnimation[3].AddBitmap(IDB_10wEnd24);
		endingAnimation[3].AddBitmap(IDB_10wEnd25);
		endingAnimation[3].AddBitmap(IDB_10wEnd26);
		endingAnimation[3].AddBitmap(IDB_10wEnd27);
		endingAnimation[3].AddBitmap(IDB_10wEnd28);
		endingAnimation[3].AddBitmap(IDB_10wEnd29);
		endingAnimation[3].AddBitmap(IDB_10wEnd30);
		endingAnimation[3].AddBitmap(IDB_10wEnd31);
		endingAnimation[3].AddBitmap(IDB_10wEnd32);
		endingAnimation[3].AddBitmap(IDB_10wEnd33);
		endingAnimation[3].AddBitmap(IDB_10wEnd34);
		endingAnimation[3].SetDelayCount(7);

		endingAnimation[4].AddBitmap(IDB_15wEnd1);			//結局五:藍髮橘髮帥哥牽著走
		endingAnimation[4].AddBitmap(IDB_15wEnd2);
		endingAnimation[4].AddBitmap(IDB_15wEnd3);
		endingAnimation[4].AddBitmap(IDB_15wEnd4);
		endingAnimation[4].AddBitmap(IDB_15wEnd5);
		endingAnimation[4].AddBitmap(IDB_15wEnd6);
		endingAnimation[4].AddBitmap(IDB_15wEnd7);
		endingAnimation[4].AddBitmap(IDB_15wEnd8);
		endingAnimation[4].AddBitmap(IDB_15wEnd9);
		endingAnimation[4].AddBitmap(IDB_15wEnd10);
		endingAnimation[4].AddBitmap(IDB_15wEnd11);
		endingAnimation[4].AddBitmap(IDB_15wEnd12);
		endingAnimation[4].AddBitmap(IDB_15wEnd13);
		endingAnimation[4].AddBitmap(IDB_15wEnd14);
		endingAnimation[4].AddBitmap(IDB_15wEnd15);
		endingAnimation[4].AddBitmap(IDB_15wEnd16);
		endingAnimation[4].AddBitmap(IDB_15wEnd17);
		endingAnimation[4].AddBitmap(IDB_15wEnd18);
		endingAnimation[4].AddBitmap(IDB_15wEnd19);
		endingAnimation[4].AddBitmap(IDB_15wEnd20);
		endingAnimation[4].AddBitmap(IDB_15wEnd21);
		endingAnimation[4].AddBitmap(IDB_15wEnd22);
		endingAnimation[4].AddBitmap(IDB_15wEnd23);
		endingAnimation[4].AddBitmap(IDB_15wEnd24);
		endingAnimation[4].AddBitmap(IDB_15wEnd25);
		endingAnimation[4].AddBitmap(IDB_15wEnd26);
		endingAnimation[4].AddBitmap(IDB_15wEnd27);
		endingAnimation[4].AddBitmap(IDB_15wEnd28);
		endingAnimation[4].AddBitmap(IDB_15wEnd29);
		endingAnimation[4].AddBitmap(IDB_15wEnd30);
		endingAnimation[4].AddBitmap(IDB_15wEnd31);
		endingAnimation[4].AddBitmap(IDB_15wEnd32);
		endingAnimation[4].SetDelayCount(7);

		
		endingAnimation[5].AddBitmap(IDB_FinalEnd1);
		endingAnimation[5].AddBitmap(IDB_FinalEnd2);
		endingAnimation[5].AddBitmap(IDB_FinalEnd3);
		endingAnimation[5].AddBitmap(IDB_FinalEnd4);
		endingAnimation[5].AddBitmap(IDB_FinalEnd5);
		endingAnimation[5].AddBitmap(IDB_FinalEnd6);
		endingAnimation[5].AddBitmap(IDB_FinalEnd7);
		endingAnimation[5].AddBitmap(IDB_FinalEnd8);
		endingAnimation[5].AddBitmap(IDB_FinalEnd9);
		endingAnimation[5].AddBitmap(IDB_FinalEnd10);
		endingAnimation[5].AddBitmap(IDB_FinalEnd11);
		endingAnimation[5].AddBitmap(IDB_FinalEnd12);
		endingAnimation[5].AddBitmap(IDB_FinalEnd13);
		endingAnimation[5].AddBitmap(IDB_FinalEnd14);
		endingAnimation[5].AddBitmap(IDB_FinalEnd15);
		endingAnimation[5].AddBitmap(IDB_FinalEnd16);
		endingAnimation[5].AddBitmap(IDB_FinalEnd17);
		endingAnimation[5].AddBitmap(IDB_FinalEnd18);
		endingAnimation[5].AddBitmap(IDB_FinalEnd19);
		endingAnimation[5].AddBitmap(IDB_FinalEnd20);
		endingAnimation[5].AddBitmap(IDB_FinalEnd21);
		endingAnimation[5].AddBitmap(IDB_FinalEnd22);
		endingAnimation[5].AddBitmap(IDB_FinalEnd23);
		endingAnimation[5].AddBitmap(IDB_FinalEnd24);
		endingAnimation[5].AddBitmap(IDB_FinalEnd25);
		endingAnimation[5].AddBitmap(IDB_FinalEnd26);
		endingAnimation[5].AddBitmap(IDB_FinalEnd27);
		endingAnimation[5].AddBitmap(IDB_FinalEnd28);
		endingAnimation[5].AddBitmap(IDB_FinalEnd29);
		endingAnimation[5].AddBitmap(IDB_FinalEnd30);
		endingAnimation[5].SetDelayCount(7);

		tip.LoadBitmap(IDB_tip);		//載入小提示圖
	}

	void CEnding::LoadAudio()
	{
		CAudio::Instance()->Load(AUDIO_ENDING1, "sounds\\ending1.mp3");		// 載入結局音樂1
		CAudio::Instance()->Load(AUDIO_ENDING23, "sounds\\ending23.mp3");	// 載入結局音樂23
		CAudio::Instance()->Load(AUDIO_ENDING4, "sounds\\ending4.mp3");		// 載入結局音樂4
		CAudio::Instance()->Load(AUDIO_ENDING5, "sounds\\ending5.mp3");		// 載入結局音樂5
		CAudio::Instance()->Load(AUDIO_ENDING6, "sounds\\ending6.mp3");		// 載入結局音樂5
	}

	void CEnding::OnShow()
	{
		switch (ending) {
			case 1:
				endingAnimation[0].SetTopLeft(0,0);
				endingAnimation[0].OnShow();
				break;
			case 2:
				endingAnimation[1].SetTopLeft(0, 0);
				endingAnimation[1].OnShow();
				break;
			case 3:
				endingAnimation[2].SetTopLeft(0, 0);
				endingAnimation[2].OnShow();
				break;
			case 4:
				endingAnimation[3].SetTopLeft(0, 0);
				endingAnimation[3].OnShow();
				break;
			case 5:
				endingAnimation[4].SetTopLeft(0, 0);
				endingAnimation[4].OnShow();
				break;
			case 6:
				endingAnimation[5].SetTopLeft(0, 0);
				endingAnimation[5].OnShow();
				break;
			default:
				ASSERT(0);
		}

		tip.SetTopLeft(0, 512);		//印出小提示圖
		tip.ShowBitmap();
	}

	void CEnding::OnMove()
	{
		endingAnimation[0].OnMove();
		endingAnimation[1].OnMove();
		endingAnimation[2].OnMove();
		endingAnimation[3].OnMove();
		endingAnimation[4].OnMove();
		endingAnimation[5].OnMove();
	}

	void CEnding::SetEnding(int total_score)
	{
		if (total_score <= 320) {					//依照得到的分數設定最後的結局
			ending = 1;
			CAudio::Instance()->Play(AUDIO_ENDING1,true);		// 載入結局音樂1
		}
		else if (total_score < 40000) {
			ending = 2;
			CAudio::Instance()->Play(AUDIO_ENDING23, true);		// 載入結局音樂23
		}
		else if (total_score < 75000) {
			ending = 3;
			CAudio::Instance()->Play(AUDIO_ENDING23, true);		// 載入結局音樂23
		}
		else if (total_score < 100000) {
			ending = 4;
			CAudio::Instance()->Play(AUDIO_ENDING4, true);		// 載入結局音4
		}
		else if (total_score < 150000) {
			ending = 5;
			CAudio::Instance()->Play(AUDIO_ENDING5, true);		// 載入結局音5
		}
		else {
			ending = 6;
			CAudio::Instance()->Play(AUDIO_ENDING6, true);		// 載入結局音6
		}
	}
	void CEnding::StopAllAudio()
	{
		CAudio::Instance()->Stop(AUDIO_ENDING1);	//關閉所有結局音效
		CAudio::Instance()->Stop(AUDIO_ENDING23);
		CAudio::Instance()->Stop(AUDIO_ENDING4);
		CAudio::Instance()->Stop(AUDIO_ENDING5);
		CAudio::Instance()->Stop(AUDIO_ENDING6);
	}
	int CEnding::GetEnding()
	{
		return ending;
	}
}
