#ifndef CHEART_H
#define CHEART_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �R�ߪ�class
	/////////////////////////////////////////////////////////////////////////////

	class CHeart
	{
	public:
		CHeart(int x, int y,int energy,int score, int small_energy);	//�R�߯�q�B�R�ߪ����Ȥ���,�p�R�ߪ�����
		int  GetX1();									// �R�ߥ��W�� x �y��
		int  GetX2();									// �R�ߥk�U�� x �y��
		void LoadBitmap();								// ���J�ϧ�
		void OnMove(SchoolMap *m, int Uy, int Dy);		// ����R�߰ʵe
		void OnShow(SchoolMap *m);						// �N�R�߹ϧζK��e��

		void SetHeartLoveEnergy(int luSnakeLoveEnergy);//�]�w�R�ߪ���q��
		bool IsEnergyFull();						   //�R�߯�q�O�_����
		void SetIsPKfull(bool flag);				   //�]�w�O�_pk����
		int GetScore();								   //�o��o���R�ߪ����Ȥ���
		int GetSmallEnergy();						   //�o��p�R�ߪ���q

		bool IsFinish();								//�R�߬O�_��������
	protected:
		CAnimation heart[14];				//�R�߹Ϥ�
		int heartEnergy;					//���q�R�߯�q
		int smallEnergy;					//�p�R�߯�q
		int Sx, Sy,Score;					//�R�ߦ�m,�֭p����
		bool isEnergyFull;					//�R�߯�q�O�_��
		bool isPKfull;						//�Qpk�����R��
		
		int velocity;						//�R�߱����[�t��
		bool rising;						//�R�߬O�_�W��
		bool isFinish;						//�R�߬O�_��������
	};
}
#endif
