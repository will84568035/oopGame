#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPKline.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CPKline::CPKline(int x, int y, int energy)
	{
		Sx = x;
		Sy = y;
		lineEnergy = energy;
		isLineFull = false;
		isFinish = false;
	}

	

	void CPKline::SetLineEnergy(int luSnakeLoveEnergy)
	{
		lineEnergy = luSnakeLoveEnergy;
		if (lineEnergy >= 120)isLineFull = true;
	}

	void CPKline::LoadBitmap()
	{
		//載入圖片進去list裡面
		pkLine[0].AddBitmap(IDB_PKLINE0);
		pkLine[1].AddBitmap(IDB_PKLINE1);
		pkLine[2].AddBitmap(IDB_PKLINE2);
		pkLine[3].AddBitmap(IDB_PKLINE3);
		pkLine[4].AddBitmap(IDB_PKLINE4);
		pkLine[5].AddBitmap(IDB_PKLINE5);
		pkLine[6].AddBitmap(IDB_PKLINE6);
		pkLine[7].AddBitmap(IDB_PKLINE7);
		pkLine[8].AddBitmap(IDB_PKLINE8);
		pkLine[9].AddBitmap(IDB_PKLINE9);
		pkLine[10].AddBitmap(IDB_PKLINE10);
		pkLine[11].AddBitmap(IDB_PKLINE11);
		pkLine[12].AddBitmap(IDB_PKLINE12);
		pkLine[13].AddBitmap(IDB_PKLINE13);
		pkLine[14].AddBitmap(IDB_PKLINE14);
		pkLine[15].AddBitmap(IDB_PKLINE15);
		pkLine[16].AddBitmap(IDB_PKLINE16);
		pkLine[17].AddBitmap(IDB_PKLINE17);
		pkLine[18].AddBitmap(IDB_PKLINE18);
		pkLine[19].AddBitmap(IDB_PKLINE19);
		pkLine[20].AddBitmap(IDB_PKLINE20);
		pkLine[21].AddBitmap(IDB_PKLINE21);
		pkLine[22].AddBitmap(IDB_PKLINE22);
		pkLine[23].AddBitmap(IDB_PKLINE23);
		pkLine[24].AddBitmap(IDB_PKLINE24);

		comboText.LoadBitmap();
		
	}

	void CPKline::OnMove()
	{
		comboText.OnMove();
	}


	void CPKline::OnShow(SchoolMap *m)
	{		
		if (lineEnergy == 0) {
			pkLine[0].SetTopLeft(Sx, Sy);
			pkLine[0].OnShow();

			comboText.SetX(331);
			comboText.OnShow();
		}
		else if (lineEnergy <= 5) {
			pkLine[1].SetTopLeft(Sx, Sy);
			pkLine[1].OnShow();

			comboText.SetX(347);
			comboText.OnShow();
		}
		else if (lineEnergy <= 10) {
			pkLine[2].SetTopLeft(Sx, Sy);
			pkLine[2].OnShow();

			comboText.SetX(363);
			comboText.OnShow();
		}
		else if (lineEnergy <= 15) {
			pkLine[3].SetTopLeft(Sx, Sy);
			pkLine[3].OnShow();

			comboText.SetX(379);
			comboText.OnShow();
		}
		else if (lineEnergy <= 20) {
			pkLine[4].SetTopLeft(Sx, Sy);
			pkLine[4].OnShow();

			comboText.SetX(395);
			comboText.OnShow();
		}
		else if (lineEnergy <= 25) {
			pkLine[5].SetTopLeft(Sx, Sy);
			pkLine[5].OnShow();

			comboText.SetX(411);
			comboText.OnShow();
		}
		else if (lineEnergy <= 30) {
			pkLine[6].SetTopLeft(Sx, Sy);
   			pkLine[6].OnShow();

			comboText.SetX(427);
			comboText.OnShow();
		}
		else if (lineEnergy <= 35) {
			pkLine[7].SetTopLeft(Sx, Sy);
			pkLine[7].OnShow();

			comboText.SetX(443);
			comboText.OnShow();
		}
		else if (lineEnergy <= 40) {
			pkLine[8].SetTopLeft(Sx, Sy);
			pkLine[8].OnShow();

			comboText.SetX(459);
			comboText.OnShow();
		}
		else if (lineEnergy <= 45) {
			pkLine[9].SetTopLeft(Sx, Sy);
			pkLine[9].OnShow();

			comboText.SetX(475);
			comboText.OnShow();
		}
		else if (lineEnergy <= 50) {
			pkLine[10].SetTopLeft(Sx, Sy);
			pkLine[10].OnShow();

			comboText.SetX(491);
			comboText.OnShow();
		}
		else if (lineEnergy <= 55) {
			pkLine[11].SetTopLeft(Sx, Sy);
			pkLine[11].OnShow();

			comboText.SetX(507);
			comboText.OnShow();
		}
		else if (lineEnergy < 60) {
			pkLine[12].SetTopLeft(Sx, Sy);
			pkLine[12].OnShow();

			comboText.SetX(523);
			comboText.OnShow();
		}
		else if (lineEnergy < 65) {
			pkLine[13].SetTopLeft(Sx, Sy);
			pkLine[13].OnShow();

			comboText.SetX(539);
			comboText.OnShow();
		}
		else if (lineEnergy < 70) {
			pkLine[14].SetTopLeft(Sx, Sy);
			pkLine[14].OnShow();

			comboText.SetX(555);
			comboText.OnShow();
		}
		else if (lineEnergy < 75) {
			pkLine[15].SetTopLeft(Sx, Sy);
			pkLine[15].OnShow();

			comboText.SetX(571);
			comboText.OnShow();
		}
		else if (lineEnergy < 80) {
			pkLine[16].SetTopLeft(Sx, Sy);
			pkLine[16].OnShow();

			comboText.SetX(587);
			comboText.OnShow();
		}
		else if (lineEnergy < 85) {
			pkLine[17].SetTopLeft(Sx, Sy);
			pkLine[17].OnShow();

			comboText.SetX(603);
			comboText.OnShow();
		}
		else if (lineEnergy < 90) {
			pkLine[18].SetTopLeft(Sx, Sy);
			pkLine[18].OnShow();

			comboText.SetX(619);
			comboText.OnShow();
		}else if (lineEnergy < 95) {
			pkLine[19].SetTopLeft(Sx, Sy);
			pkLine[19].OnShow();

			comboText.SetX(635);
			comboText.OnShow();
		}
		else if (lineEnergy < 100) {
			pkLine[20].SetTopLeft(Sx, Sy);
			pkLine[20].OnShow();
			comboText.SetX(651);
			comboText.OnShow();
		}
		else if (lineEnergy < 105) {
			pkLine[21].SetTopLeft(Sx, Sy);
			pkLine[21].OnShow();
			comboText.SetX(667);
			comboText.OnShow();
		}
		else if (lineEnergy <110) {
			pkLine[22].SetTopLeft(Sx, Sy);
			pkLine[22].OnShow();

			comboText.SetX(683);
			comboText.OnShow();
		}
		else if (lineEnergy < 115) {
			pkLine[23].SetTopLeft(Sx, Sy);
			pkLine[23].OnShow();

			comboText.SetX(699);
			comboText.OnShow();
		}
		else if (IsEnergyFull())
		{
			pkLine[24].SetTopLeft(Sx, Sy);
			pkLine[24].OnShow();
			comboText.SetX(719);
			comboText.OnShow();
		}

       }

	bool CPKline::IsEnergyFull() {
		return isLineFull;
	}

	bool CPKline::IsFinish() {
		return isFinish;
	}

	int CPKline::getEnergy() {
		return lineEnergy;
	}

}