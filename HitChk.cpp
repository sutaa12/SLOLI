//=============================================================================
//
// 当たり判定管理 [HitChk.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//インクルード
//*****************************************************************************
#include"HitChk.h"
//=============================================================================
//マクロ定義
//=============================================================================
//処理
//=============================================================================
int HITCHK::HitChk(float nPosX1,float nPosY1,int nSizeW1,int nSizeH1,float nPosX2,float nPosY2,int nSizeW2,int nSizeH2,int nNum)//円同士の当たり判定
{
	switch(nNum)
	{
	case CIRTOCIR:
		if(((nPosX1-nPosX2)*(nPosX1-nPosX2)) + ((nPosY2-nPosY1)*(nPosY2-nPosY1)) <= ((nSizeW1/2)+(nSizeW2/2))*((nSizeW1/2)+(nSizeW2/2)))
		{
			return 1;
		}
		break;
	case CIRTOQUA:
		if(0)
		{
			return 1;
		}
		break;
	case QUATOQUA:
		if(nPosX1+nSizeW1>=nPosX2&&nPosY1+nSizeH1>=nPosY2&&nPosX2+nSizeW2>=nPosX1&&nPosY2+nSizeH2>=nPosY1)
		{
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}