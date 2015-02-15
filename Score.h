
//=============================================================================
//
// �J�[�Q�[�������� [score.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef score_FILE
#define score_FILE

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"
#include "Polygon.h"
#include "Base.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define SCORE_X (750)	//�X�R�A���_�̍��W
#define SCORE_Y (300)	//���_�̍��W

#define SCORE_W (30)		//�X�R�A�T�C�Y
#define SCORE_H (60) 

#define SCORE_MAX (5)	//�X�R�A�̍ő�l

#define SCORE1 ("data/TEXTURE/number000.png")
//*****************************************************************************
// �\���̐錾
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

class SCOREIMAGE
{
public:
void InitScore(void);//�|���S���������Ō��ʂ�Ԃ�
void UnInitScore(void);//�|���S���I������
void UpdateScore(void);//�|���S���A�b�v�f�[�g
void DrawScore(void);//�|���S���`��
void SetScoreXY(float fX,float fY);
int GetSCore(void){return c_nScoreNum;}
void AddScore(int nNum);
private:
	cBase c_ScoreBase[SCORE_MAX];
	Poly c_ScorePolygon;
	int c_nScoreNum;
};
#endif
//AKR
