#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CHeart.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CHeart::CHeart(int x, int y, int energy, int score, int small_energy)
	{
		Sx = x;								//設定愛心初始值
		Sy = y;
		smallEnergy = small_energy;
		heartEnergy = energy;
		Score = score;
		velocity = 20;
		if (energy > 120)
		{
			isEnergyFull = true;
		}

		isEnergyFull = false;
		rising = true;
		isFinish = false;
		isPKfull = false;

	}

	int CHeart::GetX1()
	{
		return Sx;
	}


	int CHeart::GetX2()
	{
		return Sx + heart[0].Width();
	}


	void CHeart::SetHeartLoveEnergy(int luSnakeLoveEnergy)
	{
		heartEnergy = luSnakeLoveEnergy;				//得到這個魯蛇的愛心能量
		if (heartEnergy >= 120)isEnergyFull = true;
	}

	void CHeart::LoadBitmap()
	{
		//載入圖片進去list裡面
		heart[0].AddBitmap(IDB_HEART1, RGB(0, 0, 0));
		heart[1].AddBitmap(IDB_HEART2, RGB(0, 0, 0));
		heart[2].AddBitmap(IDB_HEART3, RGB(0, 0, 0));
		heart[3].AddBitmap(IDB_HEART4, RGB(0, 0, 0));
		heart[4].AddBitmap(IDB_HEART5, RGB(0, 0, 0));
		heart[5].AddBitmap(IDB_HEART6, RGB(0, 0, 0));
		heart[6].AddBitmap(IDB_HEART7, RGB(0, 0, 0));
		heart[7].AddBitmap(IDB_HEART8, RGB(0, 0, 0));
		heart[8].AddBitmap(IDB_HEART9, RGB(0, 0, 0));
		heart[9].AddBitmap(IDB_HEART10, RGB(0, 0, 0));
		heart[10].AddBitmap(IDB_HEART11, RGB(0, 0, 0));
		heart[11].AddBitmap(IDB_HEART12, RGB(0, 0, 0));
		heart[12].AddBitmap(IDB_HEART13, RGB(0, 0, 0));
		heart[13].AddBitmap(IDB_BIGHEART, RGB(0, 0, 0));
	}
	
	void CHeart::OnMove(SchoolMap *m,int Uy,int Dy)
	{
		heart[12].OnMove();	//執行物件的動畫

		if (rising) {					// 上升狀態
			if (Sy > Uy) {
				Sy -= velocity;			// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
				velocity= velocity-2;	// 受重力影響，下次的上升速度降低
			}
			else {
				rising = false;			// 當速度 <= 0，上升終止，下次改為下降
				velocity = 2;			// 下降的初速(velocity)為1
			}
		}else {							// 下降狀態
			if (Sy < Dy) {				// 當y座標還沒碰到地板
				Sy += velocity;			// y軸下降(移動velocity個點，velocity的單位為 點/次)
				velocity= velocity+2;	// 受重力影響，下次的下降速度增加
			}else {
				Sy = Dy ;				// 當y座標低於地板，更正為地板上
				isFinish = true;
			}
		}
	}

	void CHeart::OnShow(SchoolMap *m)
	{	
		if (isPKfull == false) {
			if (heartEnergy <= 10) {
				heart[0].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[0].OnShow();
			}
			else if (heartEnergy <= 20) {
				heart[1].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[1].OnShow();
			}
			else if (heartEnergy <= 30) {
				heart[2].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[2].OnShow();
			}
			else if (heartEnergy <= 40) {
				heart[3].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[3].OnShow();
			}
			else if (heartEnergy <= 50) {
				heart[4].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[4].OnShow();
			}
			else if (heartEnergy <= 60) {
				heart[5].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[5].OnShow();
			}
			else if (heartEnergy <= 70) {
				heart[6].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[6].OnShow();
			}
			else if (heartEnergy <= 80) {
				heart[7].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[7].OnShow();
			}
			else if (heartEnergy <= 90) {
				heart[8].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[8].OnShow();
			}
			else if (heartEnergy <= 100) {
				heart[9].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[9].OnShow();
			}
			else if (heartEnergy <= 110) {
				heart[10].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[10].OnShow();
			}
			else if (heartEnergy < 120) {
				heart[11].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[11].OnShow();
			}
			else if (IsEnergyFull())
			{
				heart[12].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
				heart[12].OnShow();
			}
		}else{
			heart[13].SetTopLeft(m->ScreenX(Sx), m->ScreenY(Sy));
			heart[13].OnShow();
		}
	}

	bool CHeart::IsEnergyFull() {
		return isEnergyFull;
	}

	bool CHeart::IsFinish() {
		return isFinish;
	}
	int CHeart::GetScore()
	{
		return Score;
	}
	int CHeart::GetSmallEnergy() {
		return smallEnergy;
	}
	void CHeart::SetIsPKfull(bool flag)
	{
		isPKfull = flag;
	}
}