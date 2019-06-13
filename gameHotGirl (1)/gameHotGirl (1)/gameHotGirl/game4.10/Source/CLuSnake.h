#ifndef CLUSNAKE_H
#define CLUSNAKE_H
#include "CSchoolMap.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �k�ͪ�class
	/////////////////////////////////////////////////////////////////////////////

	class CLuSnake
	{
	public:
		CLuSnake();
		int  GetX1();														// �H�����W�� x �y��
		int  GetY1();														// �H�����W�� y �y��
		int  GetX2();														// �H���k�U�� x �y��
		int  GetY2();														// �H���k�U�� y �y��
		void Initialize(int nx,int ny,bool flap1,bool flap2,int Level);		// �]�w�H������l��
		void LoadBitmap();													// ���J�ϧ�
		void OnMove(SchoolMap *m);											// ���ʤH��
		void OnShow(SchoolMap *m);											// �N�H���ϧζK��e��

		void SetMovingLeft(bool flag);										// �]�w�O�_���b��������
		void SetMovingRight(bool flag);										// �]�w�O�_���b���k����
		void SetXY(int nx, int ny);											// �]�w�H�����W���y��
		void SetMode(int mode);												//�]�w�H�����A
		int GetMode();														//�^�ǤH�����A

		void AddEnergy();											//�W�[�}��R�߯�q
		void SetEnergy(int energy);									//�]�w�}��R�߯�q

		void InvincibleAddEnergy();									//�L�Ī��A�W�[�}��R�߯�q
		void InvincibleComboAddEnergy();							//�L�Ī��A�W�[PK����q

		void EnergyReduction();										//���pk������q
		void ComboAddEnergy();										//�W�[PK����q

		int GetEnergy();											//���o�}��R�߯�q
		int GetScore();												//���o�o�Ӹ}����Ȫ�����
		int GetHandSomeLevel();										//���o�}��ӫ�


		bool  IsShowFinish();										//�ʵe�O�_�����F
		void SetIsPkLose(bool flag);								//�]�w�k�D���O�_pk��F
		bool GetIsPkLose();											//�o��k�D���O�_pk��F
		int GetFinalScore();										//�o��o�Өk�ͪ�����[��
		bool GetisPlayedDingAudio();								//�o��O�_��L�o������
		void SetisPlayedDingAudio(bool flag);						//�]�w�O�_��L�o������
		
	protected:
		//�|�D
		CAnimation RLuSnake, LLuSnake,WLLuSnake,WRLuSnake,RAtLuSnake,LAtLuSnake,RFollower,LFollower,PKAtLuSnake;
		//�ӭ�
		CAnimation RBoy, LBoy, WLBoy, WRBoy, RFollowBoy, LFollowBoy;
		//�j�ӭ�
		CAnimation RCoolBoy, LCoolBoy, WLCoolBoy, WRCoolBoy, RFollowCoolBoy, LFollowCoolBoy;
		//�~��j�ӭ�
		CAnimation RForeignBoy, LForeignBoy, WLForeignBoy, WRForeignBoy, RFollowForeignBoy, LFollowForeignBoy;


		int loveEnergy;				//�R�߯�q
		int score;					//���Ȥ���
		int finalScore;				//�̫ᵲ��ɷ|�o�쪺����
		int x, y;					//�H�����W���y��
		int handSomeLevel;			//�k�ͪ��ӫ�
		int rangeX1, rangeX2;		//�i���ʪ�x�y�нd��
		bool isMovingLeft;			//�O�_���b��������
		bool isMovingRight;			//�O�_���b���k����
		bool isfollow;				//�O�_���b���H�k�D��
		bool isPKlose;				//�k�D���O�_pk��F
		bool isGetFinalScore;		//�O�_�w�g��o����[��
		bool isPlayedDingAudio;		//�O�_��L�o������
		int mode;					//�H�����A 1= ���䯸�� 2 = �k�䯸�� 3 = ���䨫�� 4 = �k�䨫��
									//5 = ����Q�g  6=�k��Q�g  7=������H 8=�k����H

		
	};
}
#endif