#ifndef CTEACHER_H
#define CTEACHER_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �Ѯv��class
	/////////////////////////////////////////////////////////////////////////////

	class CTeacher
	{
	public:
		CTeacher();
		int  GetX1();												// �H�����W�� x �y��
		int  GetY1();												// �H�����W�� y �y��
		int  GetX2();												// �H���k�U�� x �y��
		int  GetY2();												// �H���k�U�� y �y��
		void Initialize(int nx, int ny, bool flap1, bool flap2);	// �]�w�H������l��
		void LoadBitmap();											// ���J�ϧ�
		void OnMove(SchoolMap *m);									// ���ʤH��
		void OnShow(SchoolMap *m);									// �N�H���ϧζK��e��
		void SetMovingLeft(bool flag);								// �]�w�O�_���b��������
		void SetMovingRight(bool flag);								// �]�w�O�_���b���k����
		void SetXY(int nx, int ny);									// �]�w�H�����W���y��
		void SetMode(int mode);										//�]�w�H�����A
		void SetisTouch(bool flag);									//�]�w�O�_�I��H
		bool GetisTouch();											//�^�ǬO�I��H
		
	protected:
		CAnimation WLTeacher;
		CAnimation	WRTeacher;
		CAnimation shadow;
		bool isTouch;				//�O�_�I��H
		int x, y;					// �H�����W���y��
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		int mode;					//�H�����A 1= ���䨫�� 2 = �k�䨫��
	};
}
#endif