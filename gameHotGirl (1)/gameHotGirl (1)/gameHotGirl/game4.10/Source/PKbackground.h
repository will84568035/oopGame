#ifndef PKBACKGROUND_H
#define PKBACKGROUND_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// PK�Ҧ����I��class
	/////////////////////////////////////////////////////////////////////////////

	class PKbackground
	{
	public:
		PKbackground();
		void LoadBitmap();								// ���Jpk�I���Ϥ�
		void OnMove();									// ����pk�I���Ϥ�
		void OnShow(SchoolMap *m);						// �L�X���Jpk�I���Ϥ�
		void Setfloor(int floor);						//�]�w�{�b���Ӽh

	protected:
		CAnimation background;
		int x, y;					// �I�����W���y��
		int floor;					//�Ӽh
	};
}
#endif
