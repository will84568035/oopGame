#ifndef CGAMEINITOPTION_H
#define CGAMEINITOPTION_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �X�l�e�����ﶵ��class
	/////////////////////////////////////////////////////////////////////////////

	class CGameInitOption
	{
	public:
		CGameInitOption();
		void LoadBitmap();						// ���J�ϧ�
		void OnShow();							// �N�ɿﶵ��e��
		void OnMove();							//����Ϥ��ʵe

		void SetIsStartClick(bool flag);		//�]�w�O�_�I��"�}�l�C��"
		bool GetIsStartClick();					//��O�_�I��"�}�l�C��"

		void SetIsAboutClick(bool flag);		//�]�w�O�_�I��"����ڭ�"
		bool GetIsAboutClick();					//��O�_�I��"����ڭ�"

		void SetIsLeaveClick(bool flag);		//�]�w�O�_�I��"���}�C��"
		bool GetIsLeaveClick();					//�o��O�_�I��"���}�C��"

		void SetEnterMode(int mode);			//�]�w�{�b�n��ܭ��ت��ﶵ�s��

	protected:
		CAnimation optionStart, optionAbout, optionLeave;						//���s�s��mode0 :
		CAnimation optionStart_click, optionAbout_click, optionLeave_click;		//�C���}�l�B����ڭ̡B�����C��
		CAnimation optionDirectStart_click;										//���s�s��mode1: �����}�l
		CAnimation optionReturn_click;											//���s�s��mode2: ��^
		bool isStartClick, isAboutClick, isLeaveClick;							//���s�O�_�Q�I��
		int enterMode;											//�i�J����ӿﶵ 0=�٨S�� 1=�}�l�C�� 2=����ڭ�
	};
}
#endif
