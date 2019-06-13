#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CTeacher.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CTeacher::CTeacher()
	{
		Initialize(0, 0, false, false);
	}

	int CTeacher::GetX1()
	{
		return x;
	}

	int CTeacher::GetY1()
	{
		return y;
	}

	int CTeacher::GetX2()
	{
		return x + WLTeacher.Width();
	}

	int CTeacher::GetY2()
	{
		return y + WLTeacher.Height();
	}

	void CTeacher::Initialize(int nx, int ny, bool flap1, bool flap2)
	{
		SetXY(nx, ny);
		isMovingRight = flap1;
		isMovingLeft = flap2;
		isTouch = false;
		mode = 1;
	}

	void CTeacher::LoadBitmap()
	{
		//���J�Ϥ��i�hlist�̭�
		WLTeacher.AddBitmap(IDB_LTEACHER0, RGB(255, 255, 255));
		WLTeacher.AddBitmap(IDB_LTEACHER1, RGB(255, 255, 255));
		WLTeacher.AddBitmap(IDB_LTEACHER2, RGB(255, 255, 255));
		WLTeacher.AddBitmap(IDB_LTEACHER3, RGB(255, 255, 255));

		WRTeacher.AddBitmap(IDB_RTEACHER0, RGB(255, 255, 255));
		WRTeacher.AddBitmap(IDB_RTEACHER1, RGB(255, 255, 255));
		WRTeacher.AddBitmap(IDB_RTEACHER2, RGB(255, 255, 255));
		WRTeacher.AddBitmap(IDB_RTEACHER3, RGB(255, 255, 255));


		shadow.AddBitmap(IDB_SHADOW, RGB(255, 255, 255));
	}

	void CTeacher::OnMove(SchoolMap *m)
	{
		const int STEP_SIZE = 3; //���ʳt�׵���!�����
		WRTeacher.OnMove();
		WLTeacher.OnMove();

		if (isMovingLeft)
		{

			if (GetX1() > 0) {  //�H������
				x -= STEP_SIZE;
			}
			else
			{
				isMovingLeft = false;
				isMovingRight = true;
				this->mode = 2;
			}
		}
		else if (isMovingRight)
		{
			if (GetX2() < 4500) {	//�H������
				x += STEP_SIZE;
			}
			else
			{
				isMovingRight = false;
				isMovingLeft = true;
				this->mode = 1;
			}
		}
	}

	void CTeacher::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CTeacher::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CTeacher::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}


	void CTeacher::OnShow(SchoolMap *m)
	{
		if (this->mode == 1)				//1= ���䨫��
		{
			WLTeacher.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			shadow.SetTopLeft(m->ScreenX(x) - 25, m->ScreenY(y) + 135);
			shadow.OnShow();
			WLTeacher.OnShow();
		}
		else if (this->mode == 2)			// 2 = �k�䨫��
		{
			WRTeacher.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
			shadow.SetTopLeft(m->ScreenX(x) - 25, m->ScreenY(y) + 135);
			shadow.OnShow();
			WRTeacher.OnShow();
		}
	}

	void CTeacher::SetMode(int mode)
	{
		this->mode = mode;
	}

	void CTeacher::SetisTouch(bool flag)
	{
		isTouch = flag;
	}

	bool CTeacher::GetisTouch()
	{
		return isTouch;
	}


}