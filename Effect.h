//=============================================================================
//
// �t�F�[�h�Ǘ� [Efect.h]
// Author : NARITADA SUZUKI
//
#ifndef EFFECT_
#define EFFECT_
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
#define EFFECT_MAX (8000)//
#define EFFECT_SIZE1 (10)
#define EFFECT_SIZE2 (15)
#define EFFECT_EXPLO (10)
enum EFFECT_MODE
{
	E_NONE,E_P1_B,E_P2_B,E_E1_B,E_Ex
};
//=============================================================================
//�N���X��`
//=============================================================================
class EFFECTMANAGE
{
public:
	EFFECTMANAGE();//�R���X�g���N�^
	void EffectInit(char *cTexPass);//������
	void EffectSet(float fPosX,float fPosy,float fSizeW,float fSizeH,float fLimit,float nR,float nG,float nB,int nEflag);//�Z�b�g
	void EffectUpdate();
	void EffectDraw();//�\��
	void EffectReset();//���Z�b�g
	void EffectUninit();//�J��
	void EffectSetCol(float nR,float nG,float nB); 
private:

	cBase c_EffectBase[EFFECT_MAX];
	Poly c_EffectPoly;
};

#endif
