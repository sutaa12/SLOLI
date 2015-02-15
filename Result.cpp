//=============================================================================
//
// ��ʑJ�� [Result.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "Result.h"
#include "sound.h"
//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
#define RSC_X (320)
#define RSC_Y (370)
//=============================================================================
// �������֐�
//=============================================================================
HRESULT RESULTMODE::InitResult(int nScore)//���U���g�������Ō��ʂ�Ԃ�
{
	c_nScore=nScore;
	ResultButton.InitPolygon(STARTL,MOJIR_W,MOJIR_H,MOJIRX,MOJIRY,1);
	ReslutBG.InitResultBG();
	ResultLogo.InitResultLogo();
	ResultButton.SetFeed(0.1);
	c_Score.InitScore();
	c_Score.SetScoreXY(RSC_X,RSC_Y);
	c_Score.AddScore(c_nScore);
	PlaySound(SOUND_LABEL_BGM002);
	return S_OK;
}
//=============================================================================
// �I�������֐�
//=============================================================================
void RESULTMODE::UnInitResult(void)//���U���g�I������
{
	StopSound();
	ResultButton.UninitPolygon();
	ReslutBG.UnInitResultBG();
	ResultLogo.UnInitResultLogo();
	c_Score.UnInitScore();

}
//=============================================================================
// �A�b�v�f�[�g�֐�
//=============================================================================
void RESULTMODE::UpdateResult(void)//���U���g�A�b�v�f�[�g
{
	if(GetKeyboardTrigger(DIK_RETURN))//P�Ń|�[�Y�؂�ւ�
	{
	c_Rmode.SetFlag(MODE_TITLE);
	}
		if(ResultButton.Feedchk()<=0)
	{
		ResultButton.PolygonFeedIN();
	}else
	if(ResultButton.Feedchk()>=1)
	{
		ResultButton.PolygonFeedOUT();
	}

	ReslutBG.UpdateResultBG();
	ResultLogo.UpdateResultLogo();
	c_Score.UpdateScore();
	ResultButton.PolygonFeed();
}
//=============================================================================
// �`��֐�
//=============================================================================
void RESULTMODE::DrawResult(void)//���U���g�`��
{
	ReslutBG.DrawResultBG();
	ResultLogo.DrawResultLogo();
	ResultButton.DrawPolygon(0);
	c_Score.DrawScore();
}