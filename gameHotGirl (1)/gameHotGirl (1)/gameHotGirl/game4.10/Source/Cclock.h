#ifndef CCLOCK_H
#define CCLOCK_H
#include <time.h>
#include "CHotGirl.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// ������class
	/////////////////////////////////////////////////////////////////////////////

	class Cclock
	{
	public:
		Cclock();
		void LoadBitmap();							// ���J�ϧ�
		void OnShow();								// �N�����K��e��
		void ClockReSet();							//�������]��l��
		void CountTime();							//Ū���C���}�l��o�L�F�h�֮ɶ�

		void StartCountTime();						//�}�l�C���p�ɪ��ɶ�
		void SetisStartCount(bool flag);			//�]�w�O�_�}�l�p�ɹC�����ɶ�
		bool GetisStartCount();						//�o��O�_�}�l�p�ɹC�����ɶ�
	
		void SetIsPlayTimeUpAudio(bool isPlay);		//�O�_�������n����
		bool GetIsAudioTimeUp();					//�o�����n���֬O�_��

		void StartPlayGameOverAudio();				//�����C�����ѭ��Ī�����_�l�ɶ��I
		bool GetIsGameOverAudioTimeUp();			//�o��C����F�����֬O�_����

		bool GetIsTimeOut();						//�^�ǬO�_�ɶ���
		void DemoSetIsTimeOut(bool flag);			//�]�w�O�_�ɶ���
	protected:
		int Sx, Sy;									//�����y��
		CAnimation clocks[13];						//�����Ϥ�
		clock_t StartTime, EndTime;								//�C���}�l�B�����ɶ��I
		clock_t AudioStartTime, AudioEndTime;					//�����}�l�B��������ɶ��I
		clock_t GameOverAudioStartTime, GameOverAudioEndTime;	//�C����F���Ķ}�l�B�������񪺮ɶ��I
		double LastTime, AudioLastTime, GameOverAudioLastTime;	//�U�خɶ��I����h�[

		bool isStartCount;							//�C���O�_�}�l�p��
		bool IsTimeOut;								//�C���ɶ��O�_����

		bool isPlayTimeUpAudio;						//�O�_����ɶ��쭵��
		bool isAudioTimeUp;							//�ɶ��쭵�լO�_����

		bool isPlayedGameOverAudio;					//�O�_����C����쭵��
		bool isGameOverAudioTimeUp;					//�C���魵�ĬO�_����
	};
}
#endif