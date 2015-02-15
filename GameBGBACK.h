
//=============================================================================
//
// �J�[�Q�[�������� [GameBG0.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef GAMEBG0_FILE
#define GAMEBG0_FILE

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define BG0 (" ")
#define SCORE ("data/TEXTURE/ScoreL.png")
#define LIFEL ("data/TEXTURE/Life.png")
#define LIFE ("data/TEXTURE/LifeM.png")
#define BG0SIZE_WH (600)
#define SCOREL_W (175)
#define SOCREL_H (50)
#define LIFE_HW (40)
#define BASE_X (780)
#define BASE_Y (250)
//*****************************************************************************
// �\���̐錾
//*****************************************************************************

//*****************************************************************************
// �N���X
//*****************************************************************************
class GAMEBG0IMAGE
{
public:
void InitGameBG(void);//�|���S���������Ō��ʂ�Ԃ�
void UnInitGameBG(void);//�|���S���I������
void UpdateGameBG(void);//�|���S���A�b�v�f�[�g
void DrawGameBG(int nLife);//�|���S���`��
private:

	cBase BGBase;
	Poly BGPolygon;
	Poly BGScoreL;
	Poly BGPLifeL;
	Poly BGLife;
};


#endif

