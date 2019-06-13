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
		Sx = x;								//�]�w�R�ߪ�l��
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
		heartEnergy = luSnakeLoveEnergy;				//�o��o�Ӿ|�D���R�߯�q
		if (heartEnergy >= 120)isEnergyFull = true;
	}

	void CHeart::LoadBitmap()
	{
		//���J�Ϥ��i�hlist�̭�
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
		heart[12].OnMove();	//���檫�󪺰ʵe

		if (rising) {					// �W�ɪ��A
			if (Sy > Uy) {
				Sy -= velocity;			// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity= velocity-2;	// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				rising = false;			// ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 2;			// �U������t(velocity)��1
			}
		}else {							// �U�����A
			if (Sy < Dy) {				// ��y�y���٨S�I��a�O
				Sy += velocity;			// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity= velocity+2;	// �����O�v�T�A�U�����U���t�׼W�[
			}else {
				Sy = Dy ;				// ��y�y�ЧC��a�O�A�󥿬��a�O�W
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