#ifndef CHOTGIRL_H
#define CHOTGIRL_H
#include "CSchoolMap.h"
#include "CLuSnake.h"
#include "GirlBullet.h"
#include "CHeart.h"
#include "CBitch.h"
#include "CPKline.h"
#include "CTeacher.h"

namespace game_framework {

	enum HOTGIRL_AUDIO {					// 定義各種音效的編號
		AUDIO_PK = 9,						//PK贏、輸、撞到老師
		AUDIO_LIGHTING = 10,				//進入PK模式的打雷音效
		AUDIO_HEART = 11,					//碰到愛心的音效
		AUDIO_LASER = 12,					//射擊雷射音效
		AUDIO_SCREAM = 13,					//魯蛇慘叫聲
		AUDIO_TOKYO = 14,					//無敵模式音樂
		AUDIO_TRANSFORM = 15,				//變身小音效
		AUDIO_TIMEUP = 16,					//時間到鐘聲
		AUDIO_FINALCOUNTSCORE=17,			//分數結算音效
		AUDIO_GAMEOVER = 18,				//遊戲失敗音效
		AUDIO_Alien=19,						//男生結算叫聲
		AUDIO_DANGER = 23,					//危險警告音樂
		AUDIO_TEACHERYELL1=26,				//老師罵人，走路要看路阿!
		AUDIO_TEACHERYELL2 = 27,			//老師罵人，談戀愛很屌是阿!
		AUDIO_HEY=28						//男生嘿嘿音效
	};
	/////////////////////////////////////////////////////////////////////////////
	// 女主角class
	/////////////////////////////////////////////////////////////////////////////

	class CHotGirl
	{
	public:
		CHotGirl();
		int  GetX1();										// 人物左上角 x 座標
		int  GetY1();										// 人物左上角 y 座標
		int  GetX2();										// 人物右下角 x 座標
		int  GetY2();										// 人物右下角 y 座標
		void Initialize(SchoolMap *m);						// 設定人物為初始值
		void LoadBitmap();									// 載入圖形
		void OnMove(SchoolMap *m);							// 移動人物
		void OnShow(SchoolMap *m,CTeacher *teacher);		// 將人物圖形貼到畫面


		void SetMovingLeft(bool flag);						// 設定是否正在往左移動
		void SetMovingRight(bool flag);						// 設定是否正在往右移動
		void SetXY(int nx, int ny);							// 設定人物左上角座標
		void SetMode(int mode);								//設定人物狀態
		int GetMode();										//得到人物狀態


		void LockSnake(CLuSnake *lusnake, SchoolMap *m);	//鎖定男生
		void UnLockSnake(CLuSnake *lusnake, SchoolMap *m);	//解鎖男生
		bool IsLocked();									//女主角是否鎖定人
		
		void LoadingBullet(SchoolMap *m);					//裝填子彈
		void SetShotting(bool flag);						//設定是否射擊
		bool IsShotting();									//回傳是否射擊
		void ShowBullet(SchoolMap *m);						//發射子彈動畫
		bool IsBulletEmpty();								//得到子彈是否沒了


		void AttackLusnake(bool start);						//女主角攻擊魯蛇
		void BitchSensor(CBitch *bitch, SchoolMap *m);		//女生敵人判斷是否再偵測範圍裡	
		void TrunAttackMode(CBitch *bitch, SchoolMap *m);	//改變女主角、敵人的攻擊模式(改成pk)
		void AddFollower(SchoolMap *m);						//女主角增加跟隨者
			

		bool IsPK();										//回傳現在是否在PK模式
		void SetIsPK(bool ispk);							//設定現在是否在PK模式
		void StartPK(SchoolMap * m);						//開始PK
		void ShowPKLine(SchoolMap *m);						//印出PK條
		void ComboPK(SchoolMap *m);							//PK條連打
		void ShowPKPeople(SchoolMap *m);					//把PK模式會有的人改成PK型態
		void InterruptPK();									//時間到中斷pk
		
		bool IsHeartEmpty();								//愛心是否是空的
		void MoveHearts(SchoolMap *m);						//愛心掉落的物理反應
		int GetEnergyScore();								//得到左上角愛心的分數
		void SetEnergyScore(int score);						//設定左上角愛心的分數
		int GetBitScore(int bit_number);					//回傳某位得到的分數
		int GetTotalScore();								//回傳得到的總分
		
		bool GetIsInvincible();								//回傳現在是不是無敵狀態
		void SetIsInvincible(bool flag);					//設定現在是不是無敵狀態
		bool GetIsHaveInvincible();							//得到是否曾經進入過無敵模式
		void SetisPlayInvincibleAUDIO(bool flag);			//設定是否曾經進入過無敵模式
		

		int GetFloor();										//得到現在在第幾樓
		void UpFloor(SchoolMap *m);							//上樓
		void DownFloor(SchoolMap *m);						//下樓

		
		void LoadAudio();									//載入所有相關因項
		void ResetShow();									//圖片動畫重置
		bool GetIsPlayedDangerMusic();						//回傳是否放過危險警告音樂
		void SetIsPlayedDangerMusic(bool flag);				//設定是否放過危險警告音樂

		
		void IsTouchTeacher(CTeacher *teacher);				//是否有碰到老師
		void IsLayDown();									//判斷是否跌到	
		bool GetIsLayDown();								//回傳是否跌到	


		bool GetIsTouchStair();								//得到是否碰到樓梯
		int GetTouchStairLR();								//判斷是否碰到樓梯


		bool FinalCountScore(SchoolMap *m);					//最後結算分數,true為分數結算為,false則還沒
		void GameOverReact();								//處理遊戲失敗的反應跟音效

		void DemoAddEnergy();								//外掛:增加愛心能量
		void DemoMinusEnergy();								//外掛:減少愛心能量
		
	protected:
		//所有模式的女主角的圖
		CAnimation RhotGirl,LhotGirl,WLhotGirl,WRhotGirl,ULhotGirl,URhotGirl,DLhotGirl, DRhotGirl;
		CAnimation PKGirl, LlayDownGirl,RlayDownGirl, LFrightenedGirl, RFrightenedGirl,LLaughGirl,RLaughGirl;
		CAnimation FinalLlayDownGirl, FinalRlayDownGirl;


		CLuSnake *AttackedBoy;			//目前被攻擊的男生
		CPKline *PKline;				//PK條
		CHeart *heart;					//目前掉落的愛心
		CBitch *PKbitch;				//目前再跟你PK的女生敵人
		vector<GirlBullet *> bullets;	//子彈的vector
		vector<CLuSnake *>	follower;	//被俘虜的男生們
		vector<CBitch *> PKbitchies;	//pk模式的婊子們
		vector<CHeart *> hearts;		//所有掉落的愛心

		bool isMovingLeft;				// 是否正在往左移動
		bool isMovingRight;				// 是否正在往右移動
		bool isLocked;					//是否鎖定撸蛇
		bool isShotting;				//是否正在射擊
		bool isLayDown;					//是否跌倒
		bool isPK;						//是否進入PK模式
		bool isInvincible;				//是否進入無敵模式
		bool isHaveInvincible;			//是否曾經進入過無敵模式
		bool isPlayInvincibleAUDIO;		//是否播過無敵模式音樂
		bool isTouchStair;				//是否碰到樓梯
		bool isTimeUpInterruptPK;		//時間到是否有打斷過pk了
		bool isPlayCountScoreAudio;		//是否播放結算分數音樂
		bool isPlayedGameOverAudio;		//是否播過遊戲失敗的音效
		bool isPlayedDangerMusic;		//是否播過危險警告音效


		int x, y;						// 人物左上角座標
		int Bx, By;						//男生座標
		int floorNum;					//所在樓層
		int floor_start, floor_end;		//分類每個樓層的起始跟結束座標
		int TouchStairLR;				//碰到左邊還是右邊的樓梯,1=左邊 2=右邊
		int PKcount;					//用來設計pk難度的counter
		int total_score;				//右上角的數字分數
		int energy_score;				//左上角的愛心分數
		int mode;						//人物狀態 1= 左邊站著   2 = 右邊站著  3 = 左邊走路  4 = 右邊走路 
												 //5 = 左邊抬頭  6 = 右邊抬頭  7 = 左邊低頭  8 = 右邊低頭  9 = PK模式 11 = 面向左邊跌倒 12 = 面向右邊跌倒
										         //13=左邊被嚇到 14=右邊被嚇到 15=左邊笑著走 16=右邊笑著走 17=最後面向左邊跌倒  18=最後面向右邊跌倒


		int newNumber;
		int currentMode;
		int tempMode;
	};
}
#endif