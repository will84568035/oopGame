#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CSmallLove.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	void CSmallLove::Initialize(int x, int y) {
		Sx = x;
		Sy = y;
		mode = 0;
		isDanger = false;
	}

	


	void CSmallLove::OnMove()
	{
		for (int i = 0; i < 9; i++)
		{
			dangerLove[i].OnMove();
		}
	}

	void CSmallLove::LoadBitmap()
	{
		love[0].AddBitmap(IDB_SLOVE0, RGB(0, 0, 0));
		love[1].AddBitmap(IDB_SLOVE1, RGB(0, 0, 0));
		love[2].AddBitmap(IDB_SLOVE2, RGB(0, 0, 0));
		love[3].AddBitmap(IDB_SLOVE3, RGB(0, 0, 0));
		love[4].AddBitmap(IDB_SLOVE4, RGB(0, 0, 0));
		love[5].AddBitmap(IDB_SLOVE5, RGB(0, 0, 0));
		love[6].AddBitmap(IDB_SLOVE6, RGB(0, 0, 0));
		love[7].AddBitmap(IDB_SLOVE7, RGB(0, 0, 0));
		love[8].AddBitmap(IDB_SLOVE8, RGB(0, 0, 0));


		dangerLove[0].AddBitmap(IDB_SLOVE0, RGB(0, 0, 0));
		dangerLove[0].AddBitmap(IDB_SLOVE01, RGB(0, 0, 0));
		dangerLove[1].AddBitmap(IDB_SLOVE1, RGB(0, 0, 0));
		dangerLove[1].AddBitmap(IDB_SLOVE11, RGB(0, 0, 0));
		dangerLove[2].AddBitmap(IDB_SLOVE2, RGB(0, 0, 0));
		dangerLove[2].AddBitmap(IDB_SLOVE21, RGB(0, 0, 0));
		dangerLove[3].AddBitmap(IDB_SLOVE3, RGB(0, 0, 0));
		dangerLove[3].AddBitmap(IDB_SLOVE31, RGB(0, 0, 0));
		dangerLove[4].AddBitmap(IDB_SLOVE4, RGB(0, 0, 0));
		dangerLove[4].AddBitmap(IDB_SLOVE41, RGB(0, 0, 0));
		dangerLove[5].AddBitmap(IDB_SLOVE5, RGB(0, 0, 0));
		dangerLove[5].AddBitmap(IDB_SLOVE51, RGB(0, 0, 0));
		dangerLove[6].AddBitmap(IDB_SLOVE6, RGB(0, 0, 0));
		dangerLove[6].AddBitmap(IDB_SLOVE61, RGB(0, 0, 0));
		dangerLove[7].AddBitmap(IDB_SLOVE7, RGB(0, 0, 0));
		dangerLove[7].AddBitmap(IDB_SLOVE71, RGB(0, 0, 0));
		dangerLove[8].AddBitmap(IDB_SLOVE8, RGB(0, 0, 0));
		dangerLove[8].AddBitmap(IDB_SLOVE81, RGB(0, 0, 0));
		for (int i = 0; i < 9; i++)
		{
			dangerLove[i].SetDelayCount(5);
		}

	}


	void CSmallLove::OnShow()
	{
		if (isDanger==true)
		{
			if (this->mode == 0)
			{
				dangerLove[0].SetTopLeft(Sx, Sy);
				dangerLove[0].OnShow();
			}
			else if (this->mode == 1)
			{
				dangerLove[1].SetTopLeft(Sx, Sy);
				dangerLove[1].OnShow();
			}
			else if (this->mode == 2)
			{
				dangerLove[2].SetTopLeft(Sx, Sy);
				dangerLove[2].OnShow();
			}
			else if (this->mode == 3)
			{
				dangerLove[3].SetTopLeft(Sx, Sy);
				dangerLove[3].OnShow();
			}
			else if (this->mode == 4) {
				dangerLove[4].SetTopLeft(Sx, Sy);
				dangerLove[4].OnShow();
			}
			else if (this->mode == 5) {
				dangerLove[5].SetTopLeft(Sx, Sy);
				dangerLove[5].OnShow();
			}
			else if (this->mode == 6) {
				dangerLove[6].SetTopLeft(Sx, Sy);
				dangerLove[6].OnShow();
			}
			else if (this->mode == 7) {
				dangerLove[7].SetTopLeft(Sx, Sy);
				dangerLove[7].OnShow();
			}
			else if (this->mode == 8) {
				dangerLove[8].SetTopLeft(Sx, Sy);
				dangerLove[8].OnShow();
			}
		}
		else
		{
			if (this->mode == 0)
			{
				love[0].SetTopLeft(Sx, Sy);
				love[0].OnShow();
			}
			else if (this->mode == 1)
			{
				love[1].SetTopLeft(Sx, Sy);
				love[1].OnShow();
			}
			else if (this->mode == 2)
			{
				love[2].SetTopLeft(Sx, Sy);
				love[2].OnShow();
			}
			else if (this->mode == 3)
			{
				love[3].SetTopLeft(Sx, Sy);
				love[3].OnShow();
			}
			else if (this->mode == 4) {
				love[4].SetTopLeft(Sx, Sy);
				love[4].OnShow();
			}
			else if (this->mode == 5) {
				love[5].SetTopLeft(Sx, Sy);
				love[5].OnShow();
			}
			else if (this->mode == 6) {
				love[6].SetTopLeft(Sx, Sy);
				love[6].OnShow();
			}
			else if (this->mode == 7) {
				love[7].SetTopLeft(Sx, Sy);
				love[7].OnShow();
			}
			else if (this->mode == 8) {
				love[8].SetTopLeft(Sx, Sy);
				love[8].OnShow();
			}
		}
	}

	void CSmallLove::SetMode(int mode)
	{
		this->mode = mode;
	}

	void CSmallLove::SetDanger(bool flag)
	{
		isDanger = flag;
	}

}