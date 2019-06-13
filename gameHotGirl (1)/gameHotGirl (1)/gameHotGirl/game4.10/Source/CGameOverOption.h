#ifndef CGAMEOVEROPTION_H
#define CGAMEOVEROPTION_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �������ﶵclass
	/////////////////////////////////////////////////////////////////////////////

	class CGameOverOption
	{
	public:
		CGameOverOption();
		void LoadBitmap();						// ���J�ϧ�
		void OnShow();							// �N�ɿﶵ��e��
		void OnMove();							//����Ϥ��ʵe

		void SetIsBackClick(bool flag);			//�]�w�O�_�I��"���s�}�l"
		bool GetIsBackClick();					//��O�_�I��"���s�}�l"

		void SetIsLeaveClick(bool flag);		//�]�w�O�_�I��"���}�C��"
		bool GetIsLeaveClick();					//�o��O�_�I��"���}�C��"
		
	protected:
		CAnimation optionBack, optionLeave, optionBack_click, optionLeave_click;
		bool isBackClick, isLeaveClick;			//���s�O�_�Q�I��
	};
}
#endif
