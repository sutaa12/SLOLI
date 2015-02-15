//=============================================================================
//
// �J�[�Q�[���� [Score.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include <math.h>
#include "Score.h"

//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//=============================================================================
// �������֐�
//=============================================================================
void SCOREIMAGE::InitScore(void)//�|���S���������Ō��ʂ�Ԃ�
{
	for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScoreBase[nLoop].InitBase(SCORE_X+(nLoop*SCORE_W),SCORE_Y,0,0,SCORE_W,SCORE_H,0);	
	}
	this->c_ScorePolygon.InitPolygon(SCORE1,SCORE_W,SCORE_H,SCORE_X,SCORE_Y,SCORE_MAX);
}
//=============================================================================
// �I�������֐�
//=============================================================================
void SCOREIMAGE::UnInitScore(void)//�|���S���I������
{
		for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScorePolygon.UninitPolygon();
	}
		c_nScoreNum=0;
}
//=============================================================================
// �A�b�v�f�[�g�֐�
//=============================================================================
void SCOREIMAGE::UpdateScore(void)//�|���S���A�b�v�f�[�g
{
	int nNumberold=c_nScoreNum;//�����p��
	for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		int nNumber;//��������
		//��ԑ傫�����Ŋ���P�O�ƑO�̌��̐�
		nNumber=nNumberold/(int)pow((float)10,(float)SCORE_MAX-nLoop-1);
	
		this->c_ScoreBase[nLoop].ChangeTex(0.0f+(nNumber/10.0f),0.0f);

		this->c_ScorePolygon.SetTexUV(this->c_ScoreBase[nLoop].chkTexX(),this->c_ScoreBase[nLoop].chkTexY(),
																0.1f,1.0f);
		this->c_ScorePolygon.UpdatePolygon(SCORE_W,SCORE_H,c_ScoreBase[nLoop].chkPosX(),c_ScoreBase[nLoop].chkPosY(),nLoop);
	
		nNumberold-=nNumber*(int)pow((float)10,(float)SCORE_MAX-nLoop-1);//�O�̌��폜
	}
}
//=============================================================================
// �`��֐�
//=============================================================================
void SCOREIMAGE::DrawScore(void)//�|���S���`��
{
		for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScorePolygon.DrawPolygon(nLoop);
	}
}

void SCOREIMAGE::AddScore(int nValue)
{

	c_nScoreNum+=nValue;//�X�R�A���Z
	if(c_nScoreNum>(int)pow((float)10,(float)SCORE_MAX))
	{
		c_nScoreNum=(int)pow((float)10,(float)SCORE_MAX)-1;
	}else
		if(c_nScoreNum<0)
		{
			c_nScoreNum=0;
		}


}
void  SCOREIMAGE::SetScoreXY(float fX,float fY)
{
		for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScoreBase[nLoop].InitBase(fX+(nLoop*SCORE_W),fY,0,0,SCORE_W,SCORE_H,0);	
	}
}