#ifndef CCOMBO_H
#define CCOMBO_H
#include "CSchoolMap.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// PK�Ҧ��ɪ��s����rclass
	/////////////////////////////////////////////////////////////////////////////
	class Ccombo
	{
	public:
		Ccombo();						
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ����ϧΰʵe
		void OnShow();					// �N�s����r�ϧζK��e��
		void SetX(int x);
		
	protected:
		int Sx, Sy;					
		CAnimation comboText;
	};
}
#endif

