#ifndef CALLMUSIC_H
#define CALLMUSIC_H
#include "CHotGirl.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ���q�䪺class
	/////////////////////////////////////////////////////////////////////////////

	class CAllMusic
	{
	public:
		CAllMusic();
		void LoadBitmap();				// ���J���q��ϧ�
		void OnShow();		            // �N���q��K��e��
		bool GetisCloseMusic();			//���o�O�_������������
		void SetisCloseMusic();			//�]�w�O�_������������
		void SetEnterMode(int mode);	//�]�w�O���Ӷ��q

	protected:
		int Sx, Sy;										//�ӧO���Ʀ�m
		CAnimation AllMusicPlay, AllMusicClose;			//���q��Ϥ�
		CAnimation LittleMusicPlay, LittleMusicClose;	//�p���q��Ϥ�
		bool isCloseMusic;								//�������֬O�_�Q����
		int enterMode;									//�i�J����Ӷ��q 1=�_�l�e�� 2=�W�h 3=����ڭ� 4=�C���� 5=����
	};
}
#endif