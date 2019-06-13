#ifndef CSCHOOLMAP_H
#define CSCHOOLMAP_H
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 主地圖class
	/////////////////////////////////////////////////////////////////////////////
	class SchoolMap {
	public:
		SchoolMap();
		void LoadBitmap();						//載入結局圖片
		void OnShow();							//印出結局圖片
		int ScreenX(int);						//得到轉換後的螢幕x點座標
		int ScreenY(int);						//得到轉換後的螢幕y點座標
		void SetSx(int);						//設定螢幕x座標
		int getSx();							//得到螢幕x座標
		
	protected:
		CMovingBitmap	LStair1, RStair1,classrooom;	//地圖上的圖片類型
		CMovingBitmap	LStair2, RStair2;
		CMovingBitmap	LStair3, RStair3;
		CMovingBitmap	LStair4, RStair4;
		CMovingBitmap	ROOF1, ROOF2;
		CMovingBitmap	key;							//指令集圖片
		
		

		
		int map[28];			//地圖座標網
		int Sx, Sy;				//螢幕x,y座標
		const int Sw, Cw,h;		//圖的寬高

	};


}
#endif 