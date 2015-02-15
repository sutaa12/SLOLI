//=============================================================================
//
// �J�[�Q�[���� [GameBG0.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "GameBGBACK.h"

//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************
//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//=============================================================================
// �������֐�
//=============================================================================
void GAMEBG0IMAGE::InitGameBG(void)//�|���S���������Ō��ʂ�Ԃ�
{
	
	this->BGBase.InitBase(GAME_MAX_W,0,0,0,BG0SIZE_WH,BG0SIZE_WH,0);
	this->BGPolygon.InitPolygon(BG0,BG0SIZE_WH,BG0SIZE_WH,BGBase.chkPosX(),BGBase.chkPosY(),1);
	this->BGPolygon.SetColor(0.0f,0.0f,0.0f);
	float PosY=BASE_Y;
	this->BGScoreL.InitPolygon(SCORE,SCOREL_W,SOCREL_H,BASE_X,PosY,1);
	PosY+=SOCREL_H*2;
	this->BGPLifeL.InitPolygon(LIFEL,SCOREL_W,SOCREL_H,BASE_X,PosY,1);
	PosY+=SOCREL_H;

	this->BGLife.InitPolygon(LIFE,LIFE_HW,LIFE_HW,BASE_X,PosY,3);
}
//=============================================================================
// �I�������֐�
//=============================================================================
void GAMEBG0IMAGE::UnInitGameBG(void)//�|���S���I������
{

	this->BGPolygon.UninitPolygon();

}
//=============================================================================
// �A�b�v�f�[�g�֐�
//=============================================================================
void GAMEBG0IMAGE::UpdateGameBG(void)//�|���S���A�b�v�f�[�g
{

	for(int nLoop=0;nLoop<3;nLoop++)
	{
		this->BGLife.UpdatePolygon(LIFE_HW,LIFE_HW,BASE_X+(LIFE_HW*nLoop),400,nLoop);
	}
	this->BGPolygon.PolygonFeed();
}
//=============================================================================
// �`��֐�
//=============================================================================
void GAMEBG0IMAGE::DrawGameBG(int nLife)//�|���S���`��
{
	//�|���S���\��
	this->BGPolygon.DrawPolygon(0);
	this->BGScoreL.DrawPolygon(0);
	this->BGPLifeL.DrawPolygon(0);

	for(int nLoop=0;nLoop<nLife;nLoop++)
	{
	this->BGLife.DrawPolygon(nLoop);
	}


	

}