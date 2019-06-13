#ifndef CGAMERLUE_H
#define CGAMERLUE_H

enum AUDIO_ID4 {				// �w�q�U�ح��Ī��s��
	AUDIO_Book = 30,				//½�ѭ���
};

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �W�h����1~6����class
	/////////////////////////////////////////////////////////////////////////////

	class CGameRlue
	{
	public:
		CGameRlue();
		void LoadBitmap();						// ���J�ϧ�
		void OnShow();							// �N�W�h�L��e��
		void OnMove();							//����Ϥ��ʵe
		void GoNextPage();						//����U�@�i�W�h��
		void GoLastPage();						//����W�@�i�W�h��

	protected:
		CAnimation rlue[6];						//���i�W�h�ʵe
		int page;								//�ĴX�i�W�h�� 1~6
	};
}
#endif

