//=============================================================================
//
// �����蔻��Ǘ� [HitChk.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"HitChk.h"
//=============================================================================
//�}�N����`
//=============================================================================
//����
//=============================================================================
int HITCHK::HitChk(float nPosX1,float nPosY1,int nSizeW1,int nSizeH1,float nPosX2,float nPosY2,int nSizeW2,int nSizeH2,int nNum)//�~���m�̓����蔻��
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