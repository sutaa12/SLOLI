//=============================================================================
//
// ��ʑJ�� [Title.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include"sound.h"
#include "Title.h"
#include "ModeManage.h"
//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//=============================================================================
// �������֐�
//=============================================================================
HRESULT TITLEMODE::InitTitle(void)//�^�C�g���������Ō��ʂ�Ԃ�
{
	PlaySound(SOUND_LABEL_BGM000);
	TitleBg.InitTitleBG();
	TitleLogo.InitTitleLogo();
	SelectMoji.InitPolygon(MOJIL,MOJIL_W,MOJIL_H,MOJIX,MOJIY,1);
	TitleButton.InitPolygon(STARTL,MOJI_W,MOJI_H,MOJIX,MOJIY,1);
	SelectBG.InitPolygon(SELECTBG,BG_WH,BG_WH,0,0,1);
	SelectLogo.InitPolygon(SELECT_LOGO,SLOGO_W,SLOGO_H,SLOGO_X,SLOGO_Y,1);
	SelectChara1.InitPolygon(CHARA1,CHARA_WH,CHARA_WH,0,0,1);
	SelectChara2.InitPolygon(CHARA2,CHARA_WH,CHARA_WH,CHARA2_X,0,1);
	SelectMoji.SetFeed(0);
	SelectBG.SetFeed(0);
	SelectLogo.SetFeed(0);
	SelectChara1.SetFeed(0);
	SelectChara2.SetFeed(0);
	TitleButton.SetFeed(0.1);
	SelectBG.SetColor(1,1,1);
	SelectChara1.SetColor(1,1,1);
	SelectChara2.SetColor(1,1,1);
	m_SlectSet=NONE_S;
	return S_OK;
}
//=============================================================================
// �I�������֐�
//=============================================================================
void TITLEMODE::UnInitTitle(void)//�^�C�g���I������
{
	SelectMoji.UninitPolygon();
	TitleButton.UninitPolygon();
	SelectBG.UninitPolygon();
	SelectLogo.UninitPolygon();
	SelectChara1.UninitPolygon();
	SelectChara2.UninitPolygon();
	StopSound();
	TitleBg.UnInitTitleBG();
	TitleLogo.UnInitTitleLogo();
		m_SlectSet=NONE_S;
}
//=============================================================================
// �A�b�v�f�[�g�֐�
//=============================================================================
int TITLEMODE::UpdateTitle(void)//�^�C�g���A�b�v�f�[�g
{
	if(GetKeyboardTrigger(DIK_RETURN)&&	m_SlectSet==NONE_S)//P�Ń|�[�Y�؂�ւ�
	{
	PlaySound(SOUND_LAVEL_SE_BUTTON);
	SelectBG.SetFeed(0.1);
	SelectLogo.SetFeed(0.1);
	SelectChara1.SetFeed(0.1);
	SelectChara2.SetFeed(0.1);
	SelectMoji.SetFeed(0.1);
	m_SlectSet=MAIN_S;
	}

		if(GetKeyboardTrigger(DIK_RETURN))
	{
	if(m_SlectSet==CHARA1_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
		c_TFlag.SetFlag(MODE_GAME);
		return CHARA1_MODE;
	}else
	if(m_SlectSet==CHARA2_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
		c_TFlag.SetFlag(MODE_GAME);
		return CHARA2_MODE;

	}
	}

	if(TitleButton.Feedchk()<=0)
	{
		TitleButton.PolygonFeedIN();
	}else
	if(TitleButton.Feedchk()>=1)
	{
		TitleButton.PolygonFeedOUT();
	}
	UpdateSelect();
	TitleBg.UpdateTitleBG();
	TitleLogo.UpdateTitleLogo();
	TitleButton.PolygonFeed();
}
//=============================================================================
// �`��֐�
//=============================================================================
void TITLEMODE::DrawTitle(void)//�^�C�g���`��
{
	TitleBg.DrawTitleBG();
	TitleLogo.DrawTitleLogo();
	TitleButton.DrawPolygon(0);
	DrawSlect();
	
}
void TITLEMODE::UpdateSelect(void)//�Z���N�g���
{
	if(	m_SlectSet!=NONE_S&&SelectBG.Feedchk()>=1)
	{
	if(GetKeyboardTrigger(DIK_RIGHT)&&m_SlectSet!=CHARA2_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
	SelectBG.SetColor(0.5,0.5,0.5);
	SelectChara1.SetColor(0.5,0.5,0.5);
	SelectChara2.SetColor(1,1,1);
	m_SlectSet=CHARA2_S;
	}else
	if(GetKeyboardTrigger(DIK_LEFT)&&	m_SlectSet!=CHARA1_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
	SelectBG.SetColor(0.5,0.5,0.5);
	SelectChara2.SetColor(0.5,0.5,0.5);
	SelectChara1.SetColor(1,1,1);
	m_SlectSet=CHARA1_S;
	}

	}
	SelectMoji.PolygonFeed();
	SelectBG.PolygonFeed();
	SelectLogo.PolygonFeed();
	SelectChara1.PolygonFeed();
	SelectChara2.PolygonFeed();
}
void TITLEMODE::DrawSlect(void)//�^�C�g���`��
{
	SelectBG.DrawPolygon(0);
	SelectLogo.DrawPolygon(0);
	SelectChara1.DrawPolygon(0);
	SelectChara2.DrawPolygon(0);
	SelectMoji.DrawPolygon(0);
}
