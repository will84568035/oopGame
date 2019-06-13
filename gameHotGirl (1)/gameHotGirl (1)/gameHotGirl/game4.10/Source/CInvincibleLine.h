#ifndef CINVINCIBLELINE_H
#define CINVINCIBLELINE_H
#include <time.h>
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �L�ļҦ��ɶ�����class
	/////////////////////////////////////////////////////////////////////////////

	class CInvincibleLine
	{
	public:
		CInvincibleLine();
		void LoadBitmap();				// ���J�ϧ�
		void OnShow();		            // �N�L�ı��K��e��
		int GetX2();					//�^�ǹϤ���
		void InvincibleLineReSet();		//�L�ı����]

		void StartCountTime();			//�L�Ķ}�l�p�ɪ��ɶ�
		void SetisStartCount(bool flag);//�]�w�L�Ķ}�l�p�ɪ��ɶ�
		bool GetisStartCount();			//�o��L�Ķ}�l�p�ɪ��ɶ�
		void CountTime();				//Ū���L�Ķ}�l��o�L�F�h�֮ɶ�
		
		bool GetIsTimeOut();			//�^�ǵL�ĬO�_�ɶ���

	protected:
		int Sx, Sy;
		CAnimation InvincibleLine[40];	//�L�ı��Ϥ�
		CAnimation InvincibleBorder;
		CAnimation Flower1;
		CAnimation Flower2;

		clock_t StartTime, EndTime;		//�p�ɥΪ��ɶ��I
		double LastTime;				//�p�ɮɶ��t
		bool isStartCount;				//�ϧ_�}�l�p��
		bool IsTimeOut;					//�L�ĬO�_�ɶ���
	};
}
#endif