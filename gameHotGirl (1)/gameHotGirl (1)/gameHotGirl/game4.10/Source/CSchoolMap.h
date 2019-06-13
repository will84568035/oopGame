#ifndef CSCHOOLMAP_H
#define CSCHOOLMAP_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �D�a��class
	/////////////////////////////////////////////////////////////////////////////
	class SchoolMap {
	public:
		SchoolMap();
		void LoadBitmap();						//���J�����Ϥ�
		void OnShow();							//�L�X�����Ϥ�
		int ScreenX(int);						//�o���ഫ�᪺�ù�x�I�y��
		int ScreenY(int);						//�o���ഫ�᪺�ù�y�I�y��
		void SetSx(int);						//�]�w�ù�x�y��
		int getSx();							//�o��ù�x�y��
		
	protected:
		CMovingBitmap	LStair1, RStair1,classrooom;	//�a�ϤW���Ϥ�����
		CMovingBitmap	LStair2, RStair2;
		CMovingBitmap	LStair3, RStair3;
		CMovingBitmap	LStair4, RStair4;
		CMovingBitmap	ROOF1, ROOF2;
		CMovingBitmap	key;							//���O���Ϥ�
		
		

		
		int map[28];			//�a�Ϯy�к�
		int Sx, Sy;				//�ù�x,y�y��
		const int Sw, Cw,h;		//�Ϫ��e��

	};


}
#endif 