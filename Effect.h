//=============================================================================
//
// フェード管理 [Efect.h]
// Author : NARITADA SUZUKI
//
#ifndef EFFECT_
#define EFFECT_
//=============================================================================
//インクルード
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
//クラス定義
//=============================================================================
class EFFECTMANAGE
{
public:
	EFFECTMANAGE();//コンストラクタ
	void EffectInit(char *cTexPass);//初期化
	void EffectSet(float fPosX,float fPosy,float fSizeW,float fSizeH,float fLimit,float nR,float nG,float nB,int nEflag);//セット
	void EffectUpdate();
	void EffectDraw();//表示
	void EffectReset();//リセット
	void EffectUninit();//開放
	void EffectSetCol(float nR,float nG,float nB); 
private:

	cBase c_EffectBase[EFFECT_MAX];
	Poly c_EffectPoly;
};

#endif
