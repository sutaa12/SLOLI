//=============================================================================
//
// �v���C���[�Ǘ� [Player.cpp]
// Author : NARITADA SUZUKI
//
#ifndef PLAYER_
#define PLAYER_
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
//�}�N����`
#define PSIZE_W (23)
#define PSIZE_H (36)
#define PSIZE_HW (15)
#define PLAYER_MAX (3)

#define PPOS_X (300)
#define PPOS_Y (500)
//=============================================================================
//�N���X��`
//=============================================================================
class Player
{
public:
	Player(void);
	void PlayerUpdate();//�L�[����
	void PlayerReset(float nPPosX,float nPPosY);//�t���O�`�F�b�N
	
	void InitPlayer(char *cTexPass,int nPwidth,int nPheight,float nPPosX,float nPPosY,float fTexX,float fTexY,int nFlag);
	void DrawPlayer();
	void UninitPlayer();
	void SetFeed(float fFeed){PlayerPolygon.SetFeed(fFeed);}

	float PoschkX();
	float PoschkY();
	void SetSpeed(float fSpeed){c_fSpeed =fSpeed; }

	void SetLFlag(int nFlag){PlayerBase.ChangeFlag(nFlag);}
	int GetLFlag(void){return PlayerBase.chkFlag();}

	void AnimSet();//�A�j���[�V�����Z�b�g

private:
	cBase PlayerBase;
	Poly PlayerPolygon;
	float c_fPPosX; //���W
	float c_fPPosY;
	float c_fSpeed;
	float c_fPMoveX;//�ړ���
	float c_fPMoveY;
	
	int c_nPTexPattern;//�e�N�X�`���p�^�[��
	int c_nPTexMove;//�e�N�X�`���p�^�[���̈ړ���

	
};

#endif
