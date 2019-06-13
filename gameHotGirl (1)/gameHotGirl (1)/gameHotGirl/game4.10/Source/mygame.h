/*
 * mygame.h: ���ɮ��x�C��������class��interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/


#include "CHotGirl.h"
#include "CSchoolMap.h"
#include "CLuSnake.h"
#include "CScore.h"
#include "CSmallLove.h"
#include "CBitch.h"
#include "PKbackground.h"
#include "CTeacher.h"
#include "Cclock.h"
#include "CInvincibleLine.h"
#include "CArrow.h"
#include "CAllMusic.h"
#include "CGameOverMap.h"
#include "CEnding.h"
#include "CGameOverOption.h"
#include "CGameInitOption.h"
#include "CGameRlue.h"

static int total_score;					//�C���`��

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	//�D�y�{����
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID1 {					// �w�q�U�ح��Ī��s��
		AUDIO_BACKGROUND = 1,			// �I������1 �����f
		AUDIO_BACKGROUND2 = 2,			// �I������2 ���x�f
		AUDIO_BACKGROUND3 = 3,			// �I������3 �ӦZ�Ϫ��ӦZ
		AUDIO_BACKGROUND4 = 4,			// �I������4 ���W���Q


		AUDIO_REBACKGROUND = 5,			// RE�I������1 �����f
		AUDIO_REBACKGROUND2 = 6,		// RE�I������2 ���x�f
		AUDIO_REBACKGROUND3 = 7,		// RE�I������3 �ӦZ�Ϫ��ӦZ
		AUDIO_REBACKGROUND4 = 8,		// RE�I������4 ���W���Q

		AUDIO_FIRSTMUSIC=22,			//�}������
		
	};

	

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyDown(UINT, UINT, UINT);				//�Y���U��L
	protected:
		void OnMove();									//����Ϥ��ʵe
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int enterMode;									//�i�J����ӿﶵ 0=�٨S�� 1=�}�l�C�� 2=����ڭ�
		CMovingBitmap initialBackground;				// �_�l�e�����ʭ�
		CMovingBitmap aboutBackground;					// ����ڭ̪����ʭ�
		CGameInitOption	option;							//�}�l�ﶵ
		CGameRlue	rule;								//�C���W�h
		CAllMusic allMusic;								//���q��
		bool isPlayedFirstTimeMusic;					//�O�_���L�}������
		
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);				//���U��L������
		void OnKeyUp(UINT, UINT, UINT);					//��}��L������
		void CloseAllAudio();							//�����Ҧ��C������
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap	gamebackground;					//�ЫǭI��
		CMovingBitmap	SecretKey;						//�K�޶��Ϥ�
		CTeacher		teacher;						//�Ѯv
		CHotGirl		hotgirl;						//�k�D��
		vector<CLuSnake*> lusnakes;						//�|�D�}�C
		CLuSnake		lusnake[27];					//�|�D��
		CScore			eightBit_score[8];				//�K�����
		CSmallLove		ten_love[10];					//���W���R��
		CBitch			bitchies[17];					//�k�ͼĤH��
		PKbackground    pk_background;					//PK���I����
		SchoolMap		schoolmap;						//�I��
		CMovingBitmap	blackbroad;						//�ªO
		Cclock			clock;							//����
		CArrow			arrow;							//�ӱ�b�Y
		CAllMusic		allMusic;						//����������
		CInvincibleLine InvincibleLine;					//�L�Įɶ���
		bool isShowSecretKey;							//�K�ެO�_�n�q�X
		int				picX, picY;
		int				whichBackgroungMusic;	
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
		void OnKeyDown(UINT, UINT, UINT);

	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CEnding ending;									//��������
		CGameOverOption	option;							//�����ﶵ
		CScore eightBit_score[8];						//�K�����
		CAllMusic allMusic;								//���q��
	};

}