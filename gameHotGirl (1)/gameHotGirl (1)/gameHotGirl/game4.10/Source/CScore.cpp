#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CScore.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	void CScore::Initialize(int x, int y) {
		Sx = x;
		Sy = y;
		mode = 0;
	}


	void CScore::LoadBitmap()
	{
		number[0].AddBitmap(IDB_NUMBER0,RGB(0,0,0));
		number[1].AddBitmap(IDB_NUMBER1, RGB(0, 0, 0));
		number[2].AddBitmap(IDB_NUMBER2, RGB(0, 0, 0));
		number[3].AddBitmap(IDB_NUMBER3, RGB(0, 0, 0));
		number[4].AddBitmap(IDB_NUMBER4, RGB(0, 0, 0));
		number[5].AddBitmap(IDB_NUMBER5, RGB(0, 0, 0));
		number[6].AddBitmap(IDB_NUMBER6, RGB(0, 0, 0));
		number[7].AddBitmap(IDB_NUMBER7, RGB(0, 0, 0));
		number[8].AddBitmap(IDB_NUMBER8, RGB(0, 0, 0));
		number[9].AddBitmap(IDB_NUMBER9, RGB(0, 0, 0));
	}


	void CScore::OnShow()
	{
		if (this->mode == 0)				
		{
			number[0].SetTopLeft(Sx,Sy);
			number[0].OnShow();
		}
		else if (this->mode == 1)			
		{
			number[1].SetTopLeft(Sx, Sy);
			number[1].OnShow();
		}
		else if (this->mode == 2)			
		{
			number[2].SetTopLeft(Sx, Sy);
			number[2].OnShow();
		}
		else if (this->mode == 3)			
		{
			number[3].SetTopLeft(Sx, Sy);
			number[3].OnShow();
		}
		else if (this->mode == 4) {			
			number[4].SetTopLeft(Sx, Sy);
			number[4].OnShow();
		}
		else if (this->mode == 5) {			
			number[5].SetTopLeft(Sx, Sy);
			number[5].OnShow();
		}
		else if (this->mode == 6) {			
			number[6].SetTopLeft(Sx, Sy);
			number[6].OnShow();
		}
		else if (this->mode == 7) {			
			number[7].SetTopLeft(Sx, Sy);
			number[7].OnShow();
		}
		else if (this->mode == 8) {			
			number[8].SetTopLeft(Sx, Sy);
			number[8].OnShow();
		}
		else if (this->mode == 9) {			
			number[9].SetTopLeft(Sx, Sy);
			number[9].OnShow();
		}
	}

	void CScore::SetMode(int mode)
	{
		this->mode = mode;
	}

}