#ifndef CSCORE_H
#define CSCORE_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �줸���ƪ�class
	/////////////////////////////////////////////////////////////////////////////

	class CScore
	{
	public:
		void Initialize(int x,int y);	//�줸���ƪ���l��
		void LoadBitmap();				// ���J�ϧ�
		void OnShow();					// �N�줸���ƹϧζK��e��
		void SetMode(int mode);			//�]�w�줸���ƪ��Ҧ�(���@�ӼƦr)
		
	protected:		
		int Sx, Sy;						//�ӧO���Ʀ�m
		int mode;						//��ƼҦ�(0~9)
		CAnimation number[10];			//�Ʀr�Ϥ�
	};
}
#endif