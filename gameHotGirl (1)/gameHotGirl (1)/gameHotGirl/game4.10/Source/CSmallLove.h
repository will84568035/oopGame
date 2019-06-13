#ifndef CSMALLLOVE_H
#define CSMALLLOVE_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ���W���p�R�ߪ�class
	/////////////////////////////////////////////////////////////////////////////

	class CSmallLove
	{
	public:
		void Initialize(int x, int y);	//�줸���ƪ���l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					//����ϧΰʵe
		void OnShow();					// �N�ϧζK��e��
		void SetMode(int mode);			//�]�w�Ϥ����˦�
		void SetDanger(bool flag);		//�]�w�O�_�M�I

	protected:
		int Sx, Sy;						
		int mode;						//�R�߶����{��
		bool isDanger;					//�O�_���M�I
		CAnimation love[10];			//�R�߹Ϥ�
		CAnimation dangerLove[10];		//�M�I���R�߹Ϥ�
	};
}
#endif