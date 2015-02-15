//=============================================================================
//
// ���[�h�Ǘ� [ModeManage.h]
// Author : NARITADA SUZUKI
//========================================================
#ifndef MODE_FILE
#define MODE_FILE
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include "main.h"
#include "Game.h"
#include "Title.h"
#include "Result.h"
#include "Feed.h"
#include "ModeFlag.h"
//*****************************************************************************

//=============================================================================
//�N���X��`
//=============================================================================
class cModeManage
{
public:
	cModeManage(){}//�R���X�g���N�^
	~cModeManage(){}//�f�X�g���N�^
	void ModeInit();//������
	void ModeUpdate();//�A�b�v�f�[�g
	void ModeDraw();//�`��
	void ModeUninit();//�I��
	void MODNumInit();
	void MODNumUninit();
	int GetModeFlag(){return c_ModeFlag;}
	void SetModeFlag(int nFlag){c_ModeFlag=nFlag;};
	void GameFlagSet(int nFlag){c_ModeFlag = nFlag;}
private:
	ModeFlag c_MFlag;
	int c_nPmode;
	int c_ModeFlag;//�t���O
	int c_ModeOldFlag;
	FEED c_ScreenFeed;
	GameMODE Gamemode;
	TITLEMODE Titlemode;
	RESULTMODE Reslutmode;
	int c_Score;//�X�R�A
};

#endif MODE_END
