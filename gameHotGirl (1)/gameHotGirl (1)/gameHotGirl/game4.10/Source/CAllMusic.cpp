#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CAllMusic.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CAllMusic::CAllMusic()
	{
		Sx = 910;
		Sy = 7;
		enterMode = 4;
		isCloseMusic = false;
	}

	

	void CAllMusic::LoadBitmap()
	{
		AllMusicPlay.AddBitmap(IDB_soundOn, RGB(0, 0, 0));
		AllMusicClose.AddBitmap(IDB_soundOff, RGB(0, 0, 0));
		LittleMusicPlay.AddBitmap(IDB_radioOpen, RGB(255, 255, 255));
		LittleMusicClose.AddBitmap(IDB_radioClose, RGB(255, 255, 255));
	}


	void CAllMusic::OnShow()
	{	
		if (enterMode == 1) {									//起始畫面
			if (isCloseMusic == false) {
				LittleMusicPlay.SetTopLeft(110, 375);
				LittleMusicPlay.OnShow();
			}
			else {
				LittleMusicClose.SetTopLeft(110,375);
				LittleMusicClose.OnShow();
			}
		}
		else if (enterMode == 2) {								//規則說明
			if (isCloseMusic == false) {
				LittleMusicPlay.SetTopLeft(650, 460);
				LittleMusicPlay.OnShow();
			}
			else {
				LittleMusicClose.SetTopLeft(650, 460);
				LittleMusicClose.OnShow();
			}
		}else if (enterMode == 3) {								//關於我們
			if (isCloseMusic == false) {
				LittleMusicPlay.SetTopLeft(800, 460);
				LittleMusicPlay.OnShow();
			}
			else {
				LittleMusicClose.SetTopLeft(800, 460);
				LittleMusicClose.OnShow();
			}
		}else if (enterMode == 4) {								//遊戲中
			if (isCloseMusic == false) {
				AllMusicPlay.SetTopLeft(910, 7);
				AllMusicPlay.OnShow();
			}
			else {
				AllMusicClose.SetTopLeft(910, 7);
				AllMusicClose.OnShow();
			}
		}else if (enterMode == 5) {								//結局
			if (isCloseMusic == false) {
				LittleMusicPlay.SetTopLeft(760, 400);
				LittleMusicPlay.OnShow();
			}
			else {
				LittleMusicClose.SetTopLeft(760, 400);
				LittleMusicClose.OnShow();
			}
		}

	}
	bool CAllMusic::GetisCloseMusic()
	{
		return isCloseMusic;
	}
	void CAllMusic::SetisCloseMusic()
	{
		if (isCloseMusic == true) {			//音量鍵切換
			isCloseMusic = false;
		}
		else if(isCloseMusic==false){
			isCloseMusic = true;
		}
	}
	
	void CAllMusic::SetEnterMode(int mode)
	{
		enterMode = mode;
	}
}