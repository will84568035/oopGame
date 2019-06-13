#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CInvincibleLine.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CInvincibleLine::CInvincibleLine()
	{
		Sx = 60;
		Sy = 42;
		isStartCount = false;
		IsTimeOut = false;
	}


	int CInvincibleLine::GetX2()
	{
		return Sx + InvincibleLine[0].Width();
	}




	void CInvincibleLine::LoadBitmap()
	{
		InvincibleLine[0].AddBitmap(IDB_INVICINBLE0, RGB(0, 0, 0));
		InvincibleLine[1].AddBitmap(IDB_INVICINBLE1, RGB(0, 0, 0));
		InvincibleLine[2].AddBitmap(IDB_INVICINBLE2, RGB(0, 0, 0));
		InvincibleLine[3].AddBitmap(IDB_INVICINBLE3, RGB(0, 0, 0));
		InvincibleLine[4].AddBitmap(IDB_INVICINBLE4, RGB(0, 0, 0));
		InvincibleLine[5].AddBitmap(IDB_INVICINBLE5, RGB(0, 0, 0));
		InvincibleLine[6].AddBitmap(IDB_INVICINBLE6, RGB(0, 0, 0));
		InvincibleLine[7].AddBitmap(IDB_INVICINBLE7, RGB(0, 0, 0));
		InvincibleLine[8].AddBitmap(IDB_INVICINBLE8, RGB(0, 0, 0));
		InvincibleLine[9].AddBitmap(IDB_INVICINBLE9, RGB(0, 0, 0));

		InvincibleLine[10].AddBitmap(IDB_INVICINBLE10, RGB(0, 0, 0));
		InvincibleLine[11].AddBitmap(IDB_INVICINBLE11, RGB(0, 0, 0));
		InvincibleLine[12].AddBitmap(IDB_INVICINBLE12, RGB(0, 0, 0));
		InvincibleLine[13].AddBitmap(IDB_INVICINBLE13, RGB(0, 0, 0));
		InvincibleLine[14].AddBitmap(IDB_INVICINBLE14, RGB(0, 0, 0));
		InvincibleLine[15].AddBitmap(IDB_INVICINBLE15, RGB(0, 0, 0));
		InvincibleLine[16].AddBitmap(IDB_INVICINBLE16, RGB(0, 0, 0));
		InvincibleLine[17].AddBitmap(IDB_INVICINBLE17, RGB(0, 0, 0));
		InvincibleLine[18].AddBitmap(IDB_INVICINBLE18, RGB(0, 0, 0));
		InvincibleLine[19].AddBitmap(IDB_INVICINBLE19, RGB(0, 0, 0));

		InvincibleLine[20].AddBitmap(IDB_INVICINBLE20, RGB(0, 0, 0));
		InvincibleLine[21].AddBitmap(IDB_INVICINBLE21, RGB(0, 0, 0));
		InvincibleLine[22].AddBitmap(IDB_INVICINBLE22, RGB(0, 0, 0));
		InvincibleLine[23].AddBitmap(IDB_INVICINBLE23, RGB(0, 0, 0));
		InvincibleLine[24].AddBitmap(IDB_INVICINBLE24, RGB(0, 0, 0));
		InvincibleLine[25].AddBitmap(IDB_INVICINBLE25, RGB(0, 0, 0));
		InvincibleLine[26].AddBitmap(IDB_INVICINBLE26, RGB(0, 0, 0));
		InvincibleLine[27].AddBitmap(IDB_INVICINBLE27, RGB(0, 0, 0));
		InvincibleLine[28].AddBitmap(IDB_INVICINBLE28, RGB(0, 0, 0));
		InvincibleLine[29].AddBitmap(IDB_INVICINBLE29, RGB(0, 0, 0));

		InvincibleLine[30].AddBitmap(IDB_INVICINBLE30, RGB(0, 0, 0));
		InvincibleLine[31].AddBitmap(IDB_INVICINBLE31, RGB(0, 0, 0));
		InvincibleLine[32].AddBitmap(IDB_INVICINBLE32, RGB(0, 0, 0));
		InvincibleLine[33].AddBitmap(IDB_INVICINBLE33, RGB(0, 0, 0));
		InvincibleLine[34].AddBitmap(IDB_INVICINBLE34, RGB(0, 0, 0));
		InvincibleLine[35].AddBitmap(IDB_INVICINBLE35, RGB(0, 0, 0));
		InvincibleLine[36].AddBitmap(IDB_INVICINBLE36, RGB(0, 0, 0));
		InvincibleLine[37].AddBitmap(IDB_INVICINBLE37, RGB(0, 0, 0));
		InvincibleLine[38].AddBitmap(IDB_INVICINBLE38, RGB(0, 0, 0));
		InvincibleLine[39].AddBitmap(IDB_INVICINBLE39, RGB(0, 0, 0));

		Flower1.AddBitmap(IDB_FLOWER1, RGB(0, 0, 0));
		Flower2.AddBitmap(IDB_FLOWER2, RGB(0, 0, 0));
		InvincibleBorder.AddBitmap(IDB_INVICINBLEBORDER, RGB(0, 0, 0));

	}


	void CInvincibleLine::OnShow()
	{
		LastTime = difftime(EndTime, StartTime);
		if (LastTime <= 500) {
			InvincibleLine[0].SetTopLeft(Sx, Sy);
			InvincibleLine[0].OnShow();
		}
		else if (LastTime <= 1000) {
			InvincibleLine[1].SetTopLeft(Sx, Sy);
			InvincibleLine[1].OnShow();
		}
		else if (LastTime <= 1500) {
			InvincibleLine[2].SetTopLeft(Sx, Sy);
			InvincibleLine[2].OnShow();
		}
		else if (LastTime <= 2000) {
			InvincibleLine[3].SetTopLeft(Sx, Sy);
			InvincibleLine[3].OnShow();
		}
		else if (LastTime <= 2500) {
			InvincibleLine[4].SetTopLeft(Sx, Sy);
			InvincibleLine[4].OnShow();
		}
		else if (LastTime <= 3000) {
			InvincibleLine[5].SetTopLeft(Sx, Sy);
			InvincibleLine[5].OnShow();
		}
		else if (LastTime <= 3500) {
			InvincibleLine[6].SetTopLeft(Sx, Sy);
			InvincibleLine[6].OnShow();
		}
		else if (LastTime <= 4000) {
			InvincibleLine[7].SetTopLeft(Sx, Sy);
			InvincibleLine[7].OnShow();
		}
		else if (LastTime <= 4500) {
			InvincibleLine[8].SetTopLeft(Sx, Sy);
			InvincibleLine[8].OnShow();
		}
		else if (LastTime <= 5000) {
			InvincibleLine[9].SetTopLeft(Sx, Sy);
			InvincibleLine[9].OnShow();
		}
		else if (LastTime <= 5500) {
			InvincibleLine[10].SetTopLeft(Sx, Sy);
			InvincibleLine[10].OnShow();
		}
		else if (LastTime <= 6000) {
			InvincibleLine[11].SetTopLeft(Sx, Sy);
			InvincibleLine[11].OnShow();
		}
		else if (LastTime <= 6500) {
			InvincibleLine[12].SetTopLeft(Sx, Sy);
			InvincibleLine[12].OnShow();
		}
		else if (LastTime <= 7000) {
			InvincibleLine[13].SetTopLeft(Sx, Sy);
			InvincibleLine[13].OnShow();
		}
		else if (LastTime <= 7500) {
			InvincibleLine[14].SetTopLeft(Sx, Sy);
			InvincibleLine[14].OnShow();
		}
		else if (LastTime <= 8000) {
			InvincibleLine[15].SetTopLeft(Sx, Sy);
			InvincibleLine[15].OnShow();
		}
		else if (LastTime <= 8500) {
			InvincibleLine[16].SetTopLeft(Sx, Sy);
			InvincibleLine[16].OnShow();
		}
		else if (LastTime <= 9000) {
			InvincibleLine[17].SetTopLeft(Sx, Sy);
			InvincibleLine[17].OnShow();
		}
		else if (LastTime <= 9500) {
			InvincibleLine[18].SetTopLeft(Sx, Sy);
			InvincibleLine[18].OnShow();
		}
		else if (LastTime <= 10000) {
			InvincibleLine[19].SetTopLeft(Sx, Sy);
			InvincibleLine[19].OnShow();
		}
		else if (LastTime <= 10500) {
			InvincibleLine[20].SetTopLeft(Sx, Sy);
			InvincibleLine[20].OnShow();
		}
		else if (LastTime <= 11000) {
			InvincibleLine[21].SetTopLeft(Sx, Sy);
			InvincibleLine[21].OnShow();
		}
		else if (LastTime <= 11500) {
			InvincibleLine[22].SetTopLeft(Sx, Sy);
			InvincibleLine[22].OnShow();
		}
		else if (LastTime <= 12000) {
			InvincibleLine[23].SetTopLeft(Sx, Sy);
			InvincibleLine[23].OnShow();
		}
		else if (LastTime <= 12500) {
			InvincibleLine[24].SetTopLeft(Sx, Sy);
			InvincibleLine[24].OnShow();
		}
		else if (LastTime <= 13000) {
			InvincibleLine[25].SetTopLeft(Sx, Sy);
			InvincibleLine[25].OnShow();
		}
		else if (LastTime <= 13500) {
			InvincibleLine[26].SetTopLeft(Sx, Sy);
			InvincibleLine[26].OnShow();
		}
		else if (LastTime <= 14000) {
			InvincibleLine[27].SetTopLeft(Sx, Sy);
			InvincibleLine[27].OnShow();
		}
		else if (LastTime <= 14500) {
			InvincibleLine[28].SetTopLeft(Sx, Sy);
			InvincibleLine[28].OnShow();
		}
		else if (LastTime <= 15000) {
			InvincibleLine[29].SetTopLeft(Sx, Sy);
			InvincibleLine[29].OnShow();
		}
		else if (LastTime <= 15500) {
			InvincibleLine[30].SetTopLeft(Sx, Sy);
			InvincibleLine[30].OnShow();
		}
		else if (LastTime <= 16000) {
			InvincibleLine[31].SetTopLeft(Sx, Sy);
			InvincibleLine[31].OnShow();
		}
		else if (LastTime <= 16500) {
			InvincibleLine[32].SetTopLeft(Sx, Sy);
			InvincibleLine[32].OnShow();
		}
		else if (LastTime <= 17000) {
			InvincibleLine[33].SetTopLeft(Sx, Sy);
			InvincibleLine[33].OnShow();
		}
		else if (LastTime <= 17500) {
			InvincibleLine[34].SetTopLeft(Sx, Sy);
			InvincibleLine[34].OnShow();
		}
		else if (LastTime <= 18000) {
			InvincibleLine[35].SetTopLeft(Sx, Sy);
			InvincibleLine[35].OnShow();
		}
		else if (LastTime <= 18500) {
			InvincibleLine[36].SetTopLeft(Sx, Sy);
			InvincibleLine[36].OnShow();
		}
		else if (LastTime <= 19000) {
			InvincibleLine[37].SetTopLeft(Sx, Sy);
			InvincibleLine[37].OnShow();
		}
		else if (LastTime <= 19500) {
			InvincibleLine[38].SetTopLeft(Sx, Sy);
			InvincibleLine[38].OnShow();
		}
		else if (LastTime >= 20000) {
			InvincibleLine[39].SetTopLeft(Sx, Sy);
			InvincibleLine[39].OnShow();
			IsTimeOut = true;
			isStartCount = false;
		}

		Flower1.SetTopLeft(Sx - 50,Sy);
		Flower1.OnShow();
		Flower2.SetTopLeft(GetX2() + 10, Sy);
		Flower2.OnShow();
		InvincibleBorder.SetTopLeft(Sx, Sy);
		InvincibleBorder.OnShow();

	}

	void CInvincibleLine::CountTime()
	{
		EndTime = clock();
	}

	void CInvincibleLine::StartCountTime()
	{
		if (isStartCount == false) {
			StartTime = clock();
			SetisStartCount(true);
		}
	}

	void CInvincibleLine::SetisStartCount(bool flag)
	{
		isStartCount = flag;
	}

	bool CInvincibleLine::GetisStartCount()
	{
		return isStartCount;
	}

	bool CInvincibleLine::GetIsTimeOut()
	{
		return IsTimeOut;
	}

	void CInvincibleLine::InvincibleLineReSet()
	{
		isStartCount = false;
		IsTimeOut = false;
	}

}

