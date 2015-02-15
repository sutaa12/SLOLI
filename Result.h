
//=============================================================================
//
// ��ʑJ�� [Result.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef RESULT_FILE
#define RESULT_FILE

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"
#include "ResultBG.h"
#include "Polygon.h"
#include "ResultLogo.h"
#include "ModeFlag.h"
#include "score.h"
//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define STARTL ("data/TEXTURE/Start.png")
#define MOJIR_W (300)
#define MOJIR_H (40)
#define MOJIRX (350)
#define MOJIRY (500)
//*****************************************************************************
// �N���X
//*****************************************************************************
class RESULTMODE
{
public:
	RESULTMODE(void){}//�R���X�g���N�^
	~RESULTMODE(void){}//�f�X�g���N�^

HRESULT InitResult(int nScore);//���U���g������

void UnInitResult(void);//���U���g�I��
void UpdateResult(void);//���U���g�A�b�v�f�[�g
void DrawResult(void);//���U���g�`��
private:
RESLUTBGIMAGE ReslutBG;
RESULTLOGOIMAGE ResultLogo; 
ModeFlag c_Rmode;
Poly ResultButton; 
int c_nScore;
SCOREIMAGE c_Score ;
};
#endif

