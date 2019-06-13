#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CArrow.h"


namespace game_framework {
	CArrow::CArrow()
	{
		Ux= 180;
		Dx = 200;
		Uy = 120;
		Dy = 250;
		isUpClick, isDownClick = false;
		floor = 1;
	}


	void CArrow::LoadBitmap()
	{
		arrowUP.AddBitmap(IDB_buttonUp1, RGB(0, 0, 0));
		arrowDown.AddBitmap(IDB_buttonDown1, RGB(0, 0, 0));
		arrowUP_click.AddBitmap(IDB_buttonUp2, RGB(0, 0, 0));
		arrowDown_click.AddBitmap(IDB_buttonDown2, RGB(0, 0, 0));
	}

	void CArrow::SetArrowPosition(int LR)
	{
		if (floor == 1) {
			if (LR == 1) {							//�Y�b�Y�b�Ӽh����
				Ux = 20; Dx = 30;					//�]�w�W�U�b�Y��x��m
			}
			else if (LR == 2) {						//�Y�b�Y�b�Ӽh�k��
				Ux = 4900 - arrowUP.Width();
				Dx = 4900 - arrowUP.Width();		//�]�w�W�U�b�Y��x��m
			}

		}
		else if (floor == 2) {
			if (LR == 1) {							//�Y�b�Y�b�Ӽh����
				Ux = 4920 + 20; Dx = 4920 + 30;		//�]�w�W�U�b�Y��x��m
			}
			else if (LR == 2) {						//�Y�b�Y�b�Ӽh�k��
				Ux = 9840 - 20 - arrowUP.Width();
				Dx = 9840 - 10 - arrowUP.Width();	//�]�w�W�U�b�Y��x��m
			}
		}
		else if (floor == 3) {
			if (LR == 1) {							//�Y�b�Y�b�Ӽh����
				Ux = 9840 + 20; Dx = 9840 + 30;		//�]�w�W�U�b�Y��x��m
			}
			else if (LR == 2) {						//�Y�b�Y�b�Ӽh�k��
				Ux = 14760 - 20 - arrowUP.Width();
				Dx = 14760 - 10 - arrowUP.Width();	//�]�w�W�U�b�Y��x��m
			}
		}
		else if (floor == 4) {
			if (LR == 1) {							//�Y�b�Y�b�Ӽh����
				Ux = 14760 + 20; Dx = 14760 + 30;	//�]�w�W�U�b�Y��x��m
			}
			else if (LR == 2) {						//�Y�b�Y�b�Ӽh�k��
				Ux = 19680 - 20 - arrowUP.Width();
				Dx = 19680 - 10 - arrowUP.Width();	//�]�w�W�U�b�Y��x��m
			}
		}
	}

	void CArrow::SetIsUpClick(bool flag)
	{
		isUpClick = flag;
	}

	void CArrow::SetIsDownClick(bool flag)
	{
		isDownClick = flag;
	}

	int CArrow::GetClickUpDown()
	{
		if (isUpClick == true) return 1;
		else if (isDownClick == true)return 2;
		else return 0;
	}

	void CArrow::OnShow(SchoolMap *m)
	{

		//�W�b�Y�����
		if (floor < 4) {
			if (isUpClick == false) {
				arrowUP.SetTopLeft(m->ScreenX(Ux),m->ScreenY(Uy));
				arrowUP.OnShow();
			}
			else {
				arrowUP_click.SetTopLeft(m->ScreenX(Ux), m->ScreenY(Uy));
				arrowUP_click.OnShow();
			}
		}

		//�U�b�Y�����
		if (floor > 1) {
			if (isDownClick == false) {
				arrowDown.SetTopLeft(m->ScreenX(Dx), m->ScreenY(Dy));
				arrowDown.OnShow();
			}
			else {
				arrowDown_click.SetTopLeft(m->ScreenX(Dx), m->ScreenY(Dy));
				arrowDown_click.OnShow();
			}
		}
	}
	void CArrow::SetFloor(int floorNum)
	{
		floor = floorNum;
	}
}