#ifndef CLUSNAKE_H
#define CLUSNAKE_H
#include "CSchoolMap.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 男生的class
	/////////////////////////////////////////////////////////////////////////////

	class CLuSnake
	{
	public:
		CLuSnake();
		int  GetX1();														// 人物左上角 x 座標
		int  GetY1();														// 人物左上角 y 座標
		int  GetX2();														// 人物右下角 x 座標
		int  GetY2();														// 人物右下角 y 座標
		void Initialize(int nx,int ny,bool flap1,bool flap2,int Level);		// 設定人物為初始值
		void LoadBitmap();													// 載入圖形
		void OnMove(SchoolMap *m);											// 移動人物
		void OnShow(SchoolMap *m);											// 將人物圖形貼到畫面

		void SetMovingLeft(bool flag);										// 設定是否正在往左移動
		void SetMovingRight(bool flag);										// 設定是否正在往右移動
		void SetXY(int nx, int ny);											// 設定人物左上角座標
		void SetMode(int mode);												//設定人物狀態
		int GetMode();														//回傳人物狀態

		void AddEnergy();											//增加腳色愛心能量
		void SetEnergy(int energy);									//設定腳色愛心能量

		void InvincibleAddEnergy();									//無敵狀態增加腳色愛心能量
		void InvincibleComboAddEnergy();							//無敵狀態增加PK條能量

		void EnergyReduction();										//減少pk條的能量
		void ComboAddEnergy();										//增加PK條能量

		int GetEnergy();											//取得腳色愛心能量
		int GetScore();												//取得這個腳色價值的分數
		int GetHandSomeLevel();										//取得腳色帥度


		bool  IsShowFinish();										//動畫是否播完了
		void SetIsPkLose(bool flag);								//設定女主角是否pk輸了
		bool GetIsPkLose();											//得到女主角是否pk輸了
		int GetFinalScore();										//得到這個男生的結算加分
		bool GetisPlayedDingAudio();								//得到是否放過得分音效
		void SetisPlayedDingAudio(bool flag);						//設定是否放過得分音效
		
	protected:
		//魯蛇
		CAnimation RLuSnake, LLuSnake,WLLuSnake,WRLuSnake,RAtLuSnake,LAtLuSnake,RFollower,LFollower,PKAtLuSnake;
		//帥哥
		CAnimation RBoy, LBoy, WLBoy, WRBoy, RFollowBoy, LFollowBoy;
		//大帥哥
		CAnimation RCoolBoy, LCoolBoy, WLCoolBoy, WRCoolBoy, RFollowCoolBoy, LFollowCoolBoy;
		//外國大帥哥
		CAnimation RForeignBoy, LForeignBoy, WLForeignBoy, WRForeignBoy, RFollowForeignBoy, LFollowForeignBoy;


		int loveEnergy;				//愛心能量
		int score;					//價值分數
		int finalScore;				//最後結算時會得到的分數
		int x, y;					//人物左上角座標
		int handSomeLevel;			//男生的帥度
		int rangeX1, rangeX2;		//可移動的x座標範圍
		bool isMovingLeft;			//是否正在往左移動
		bool isMovingRight;			//是否正在往右移動
		bool isfollow;				//是否正在跟隨女主角
		bool isPKlose;				//女主角是否pk輸了
		bool isGetFinalScore;		//是否已經獲得結算加分
		bool isPlayedDingAudio;		//是否放過得分音效
		int mode;					//人物狀態 1= 左邊站著 2 = 右邊站著 3 = 左邊走路 4 = 右邊走路
									//5 = 左邊被射  6=右邊被射  7=左邊跟隨 8=右邊跟隨

		
	};
}
#endif