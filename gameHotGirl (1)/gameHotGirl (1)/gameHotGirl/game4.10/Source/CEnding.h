#ifndef CENDIND_H
#define CENDIND_H

enum AUDIO_ID2 {				// �w�q�U�ح��Ī��s��
	AUDIO_ENDING1 = 20,				//�骺��������
	AUDIO_ENDING23 = 21,			//����23����
	AUDIO_ENDING4 = 24,				//����4����
	AUDIO_ENDING5 = 25,				//����5����
	AUDIO_ENDING6 = 29,				//����6����
};
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ����������class
	/////////////////////////////////////////////////////////////////////////////
	class CEnding {
	public:
		CEnding();
		void LoadBitmap();					//���J�����Ϥ�
		void LoadAudio();					//���J���ص�������
		void OnShow();						//�L�X�����Ϥ�
		void OnMove();						//���񵲧��ʵe
		void SetEnding(int total_score);	//�̷ӱo�쪺�`���]�w��������
		void StopAllAudio();				//�����Ҧ�����
		int GetEnding();					//�o��{�b����������
		
	protected:
		int ending;							//��������1~6
		CAnimation endingAnimation[6];		//�����ʵe
		CMovingBitmap	tip;				//�p���ܹ�
	};
}
#endif 