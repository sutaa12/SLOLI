//=============================================================================
//
// ���[�h�Ǘ� [ModeManage.cpp]
// Author : NARITADA SUZUKI
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include "main.h"
#include "ModeManage.h"
//*****************************************************************************
void cModeManage::ModeInit()//������
{
	c_Score=0;
	c_ModeFlag = MODE_TITLE;
	c_MFlag.SetFlag(MODE_TITLE);
	c_ModeOldFlag=c_ModeFlag;//�����̒l
	c_nPmode=0;

		c_ScreenFeed.InitFeed("",SCREEN_WIDTH,SCREEN_HEIGHT,0,0,1,1,0);//�t�F�[�h������
	switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.InitTitle();
		break;
	case MODE_GAME:
		Gamemode.InitGame(c_nPmode);
		break;
	case MODE_RESLUT:
		Reslutmode.InitResult(c_Score);
		break;
	}
}
void cModeManage::ModeUpdate()//�A�b�v�f�[�g
{
	c_ModeFlag=c_MFlag.GetFlag();
	c_ScreenFeed.FeedUpdate();//�t�F�[�h�A�b�v�f�[�g
	if(c_ModeFlag==c_ModeOldFlag)//�t���O������Ȃ��ꍇ
	{
		switch(c_ModeFlag)
		{
		case MODE_TITLE:
		c_nPmode=Titlemode.UpdateTitle();
			break;
		case MODE_GAME:
			Gamemode.UpdateGame();
			break;
		case MODE_RESLUT:
			Reslutmode.UpdateResult();
			break;
		}
	}	
		if(c_ScreenFeed.FeedChk()==0)//�n�܂�
		{
		if(c_ModeFlag!=c_ModeOldFlag)//�t���O������Ȃ��ꍇ
		{
			c_ScreenFeed.FeedSet(FEEDIN);
		}
		}

		if(c_ScreenFeed.FeedChk()>=1)//�t�F�[�h�`�F�b�N�܂�Ԃ��Ȃ�
		{
			c_ScreenFeed.FeedSet(FEEDOUT);//�t�F�[�h�A�E�g
		MODNumUninit();//�I��
		c_ModeOldFlag=c_ModeFlag;
		MODNumInit();
		}

}
void cModeManage::ModeDraw()//�`��
{
		switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.DrawTitle();
		break;
	case MODE_GAME:
		Gamemode.DrawGame();
		break;
	case MODE_RESLUT:
		Reslutmode.DrawResult();
		break;
	}

	c_ScreenFeed.DrawFeed();
}
void cModeManage::ModeUninit()//�I��
{
			c_ScreenFeed.UninitFeed();
		switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.UnInitTitle();
		break;
	case MODE_GAME:
		c_Score = Gamemode.UnInitGame();
		break;
	case MODE_RESLUT:
		Reslutmode.UnInitResult();
		break;
	}

}

//=============================================================================
//���[�h����������
//=============================================================================
void cModeManage::MODNumInit(void)
{
		switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.InitTitle();
		break;
	case MODE_GAME:
		Gamemode.InitGame(c_nPmode);
		break;
	case MODE_RESLUT:
		Reslutmode.InitResult(c_Score);
		break;
	}
}
//=============================================================================
//���[�h�I������
//=============================================================================
void cModeManage::MODNumUninit(void)
{
	switch(c_ModeOldFlag)
	{
	case MODE_TITLE:
		Titlemode.UnInitTitle();
		break;
	case MODE_GAME:
		c_Score = Gamemode.UnInitGame();
		break;
	case MODE_RESLUT:
		Reslutmode.UnInitResult();
		break;
	}
}
