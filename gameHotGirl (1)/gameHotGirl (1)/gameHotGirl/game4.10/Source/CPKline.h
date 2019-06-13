#ifndef CPKLINE_H
#define CPKLINE_H
#include "CSchoolMap.h"
#include "Ccombo.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// PK�ɳs������class
	/////////////////////////////////////////////////////////////////////////////

	class CPKline
	{
	public:
		CPKline(int x, int y, int energy);			//�y�СB�s����������
		void SetLineEnergy(int luSnakeLoveEnergy);	//�]�w�s����������
		void LoadBitmap();							// ���J�ϧ�
		void OnMove();								//����ϧΰʵe
		void OnShow(SchoolMap *m);					// �N�ϧζK��e��
		bool IsEnergyFull();						//�^�ǷR�߯�q�O�_����
		int getEnergy();							//�^�ǳs����������
		bool IsFinish();							//�^�ǬO�_�s����
	protected:
		int Sx, Sy;					//�R�ߦ�m,�֭p����
		int lineEnergy;				//�s����������
		bool isLineFull;			//�R�߯�q�O�_��
		CAnimation pkLine[25];		//�s��������
		bool isFinish;				//�O�_�s����
		Ccombo comboText;			//�s����r

	};
}
#endif
