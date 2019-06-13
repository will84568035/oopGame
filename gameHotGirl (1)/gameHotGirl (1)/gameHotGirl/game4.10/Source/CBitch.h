#ifndef CBITCH_H
#define CBITCH_H
#include "CSchoolMap.h"
#include "CLuSnake.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �k�ͼĤH��class
	/////////////////////////////////////////////////////////////////////////////

	class CBitch
	{
	public:
		CBitch();
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
		int GetMode();												//�^�ǲ{�b���H�����A
		void SetSensor(bool flag);									//�]�w�O�_�b����
		bool GetSensor();											//�^�ǬO�_�b����


		void SetShowCount();										//�]�w�ʵe����t��
		bool IsShowFinish();										//�^�ǬO�_���񧹹Ϥ� mode = 5 or mode = 6

		void AttackBoy(CLuSnake *AttackBoy);						//�����ؼШk��
		
		void SetMoveMode(int mode);									//�]�w���ʼҦ�

		void SetBeforePKmode(int mode);								//�]�wpk�e�����A
		int GetBeforePKmode();										//�o��pk�e�����A
		void SetPKPosition(int x, int y);							//�]�wpk�ɪ��y��

		void SetIsForeign(bool flag);								//�]�w�L�O���O�~��k��
		bool GetIsForeign();										//���o�L�O���O�~��k��

	protected:
		CAnimation RStBitch;
		CAnimation	RWBitch;
		CAnimation LStBitch;
		CAnimation	LWBitch;
		CAnimation LFrightenedBitch;
		CAnimation RFrightenedBitch;
		CAnimation PKBitch;
		CAnimation WLWBitch;
		CAnimation WRWBitch;
		
		
		int x, y;					// �H���y��
		int pkX, pkY;				//pk�ɪ��y��
		int rangeX1, rangeX2;		//�i���ʪ�x�y�нd��
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isSensor;				//�O�_���b����
		bool isForeign;				//�O���O�~��k��
		int moveMode;				//1 = �٨Spk 2 = pkĹ�F 3 = �k�W���� 4 = ���W����
		int beforePKmode;			//1 =���ۥ���  2=���V�k��
		int mode;					//�H�����A 1= ������� 2 = �k����� 3 = ���䨫�� 4 = �k�䨫�� 5 = ����Q���~ 6 = �k��Q���~ 7 = PK�Ҧ�  13=���䯺�ۨ� 14=�k�䯺�ۨ�
	};
}
#endif