//=============================================================================
//
// �J�[�Q�[���� [GameBG0.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "GamePose.h"

//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************
//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//=============================================================================
// �������֐�
//=============================================================================
void GAMEPOSEMenu::InitGamePS(void)//�|���S���������Ō��ʂ�Ԃ�
{
	nFlag = M_RETURN;
	float BaseY = Base_Y;
	this->BGBase.InitBase(0,0,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
	this->BGPolygon.InitPolygon(PS1,SCREEN_WIDTH,SCREEN_HEIGHT,BGBase.chkPosX(),BGBase.chkPosY(),1);
	this->BGPolygon.SetFeed(0.9f);

	this->m_PoseLogo.InitPolygon(POSEL,L_W,B_H,LOGO_X,BaseY,1);
	BaseY+=Base_Y+B_H;
	this->m_Return.InitPolygon(RETURN,B_W,B_H,B_X,BaseY,1);
	BaseY+=B_H;
	this->m_Rery.InitPolygon(RETRY,B_W,B_H,B_X,BaseY,1);
	BaseY+=B_H;
	this->m_Title.InitPolygon(TITLE,B_W,B_H,B_X,BaseY,1);
	BaseY+=B_H;
	this->m_Message.InitPolygon(MESSAGE,M_W,M_H,B_X,BaseY,1);

}
//=============================================================================
// �I�������֐�
//=============================================================================
void GAMEPOSEMenu::UnInitGamePS(void)//�|���S���I������
{

	this->BGPolygon.UninitPolygon();

}
//=============================================================================
// �A�b�v�f�[�g�֐�
//=============================================================================
int GAMEPOSEMenu::UpdateGamePS(void)//�|���S���A�b�v�f�[�g
{
	this->BGPolygon.UpdatePolygon(SCREEN_WIDTH,SCREEN_HEIGHT,BGBase.chkPosX(),BGBase.chkPosY(),0);
	this->BGBase.SetCnt(BGBase.GetCnt()+1);
	this->BGBase.SetCnt(BGBase.GetCnt()%60);
	
	if(GetKeyboardRepeat(DIK_UP))
	{
		nFlag=(nFlag+(M_PMAX-1))%M_PMAX;
	}else
	if(GetKeyboardRepeat(DIK_DOWN))
	{
		nFlag=(nFlag+1)%M_PMAX;
	}
	if(GetKeyboardTrigger(DIK_RETURN))
	{
		switch(nFlag)
		{
		case M_RETURN:
			return MAINGAME;
			break;
		case M_RETRY:
			return INITGAME;
			break;
		case M_TITLE:
			return GAMETITLE;
			break;
		}
	}
return POSEGAME;
}
//=============================================================================
// �`��֐�
//=============================================================================
void GAMEPOSEMenu::DrawGamePS(void)//�|���S���`��
{
	//�|���S���\��
	this->BGPolygon.DrawPolygon(0);
	this->m_PoseLogo.DrawPolygon(0);
	if(nFlag!=M_RETURN||BGBase.GetCnt()%2==0)
	{
	this->m_Return.DrawPolygon(0);
	}
	if(nFlag!=M_RETRY||BGBase.GetCnt()%2==0)
	{
	this->m_Rery.DrawPolygon(0);
	}
	if(nFlag!=M_TITLE||BGBase.GetCnt()%2==0)
	{
	this->m_Title.DrawPolygon(0);
	}
	this->m_Message.DrawPolygon(0);

}