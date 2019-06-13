#ifndef CARROW_H
#define CARROW_H
#include "CSchoolMap.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �W�U�ӽb�Y��class
	/////////////////////////////////////////////////////////////////////////////

	class CArrow
	{
	public:
		CArrow();
		void LoadBitmap();						// ���J�ϧ�
		void OnShow(SchoolMap *m);		        // �N�b�Y�K��e��
		void SetFloor(int floorNum);			// �]�w�k�D���{�b���Ӽh
		void SetArrowPosition(int LR);			//�]�w�b�Y�ϧΪ���m
		void SetIsUpClick(bool flag);			//�]�w�O�_�I���W�Ӫ���
		void SetIsDownClick(bool flag);			//�]�w�O�_�I���U�Ӫ���
		int GetClickUpDown();					//�o��{�b�O��ܤW���٬O�U��
		

	protected:
		CAnimation arrowUP, arrowDown, arrowUP_click, arrowDown_click;
		int Ux, Uy, Dx, Dy;				//�W�U�ӫ��s��x,y�y��
		bool isUpClick, isDownClick;	//�W�U�O�_�Q�I��
		int floor;						//�k�D���{�b�Ҧb���Ӽh
	};
}
#endif