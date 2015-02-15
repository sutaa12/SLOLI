
//=============================================================================
//
// ��ʑJ�� [Game.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef GAME_FILE
#define GAME_FILE

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"
#include "sound.h"
#include "GameBG.h"
#include "GameBG2.h"
#include "GameBG3.h"
#include "GameBGBACK.h"
#include "GamePose.h"
#include "Score.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "HitChk.h"
#include "Effect.h"
#include "ModeFlag.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define Speed (20)//�v���C���[�X�s�[�h
//*****************************************************************************
//�N���X�錾
//*****************************************************************************
class GameMODE
{
public:
GameMODE(void){c_nGameFlag=INITGAME;}//�R���X�g���N�^
~GameMODE(void){}
HRESULT InitGame(int nPflag);//�Q�[����ʏ�����
int UnInitGame(void);//�Q�[����ʏI��
void UpdateGame(void);//�Q�[����ʃA�b�v�f�[�g
void DrawGame(void);//�Q�[����ʕ`��
void GameReset(void);//�Q�[���f�[�^���Z�b�g
private:
int nLCnt;
int m_nPMode;//�v���C���[���[�h
Player cPlayer1;
BULLETMANAGE cBullet;
ENEMYMANAGE cEnemy;
GAMEBGIMAGE GameBG;
GAMEBG0IMAGE GameBG0;
GAMEBG2IMAGE GameBG2;
GAMEBG3IMAGE GameBG3;

GAMEPOSEMenu GamePoseMenu;

SCOREIMAGE cScore;

HITCHK cHichk;

EFFECTMANAGE c_Effect;
ModeFlag c_Gmode;
int c_nGameFlag;
};
#endif

