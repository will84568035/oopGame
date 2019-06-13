#ifndef CGAMEOVERMAP_H
#define CGAMEOVERMAP_H
namespace game_framework {

	class CGameOverMap {
	public:
		CGameOverMap();
		void LoadBitmap();
		void OnShow();
		int ScreenX(int);
		int ScreenY(int);
		void SetSx(int);
		int getSx();
	protected:
		CMovingBitmap	LStair1, RStair1, classrooom;
		CMovingBitmap	LStair2, RStair2;
		CMovingBitmap	LStair3, RStair3;
		CMovingBitmap	LStair4, RStair4;
		CMovingBitmap	ROOF1, ROOF2;


		int map[28];
		int Sx, Sy;
		const int Sw, Cw, h;
	};


}
#endif 
