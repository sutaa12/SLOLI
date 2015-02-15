//=============================================================================
//
// �v���C���[�Ǘ� [Feed.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"main.h"
#include"Effect.h"
//=============================================================================
//�}�N����`
//*****************************************************************************
EFFECTMANAGE::EFFECTMANAGE()//�R���X�g���N�^
{
	for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
		this->c_EffectBase[nLoop].InitBase(0,0,0,0,0,0,0);
	}
}
void EFFECTMANAGE::EffectInit(char *cTexPass)//������
{
		for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
		this->c_EffectBase[nLoop].InitBase(0,0,0,0,0,0,0);
	}
		
		this->c_EffectPoly.InitPolygon(cTexPass,0,0,0,0,EFFECT_MAX);
}

void EFFECTMANAGE::EffectUpdate(void)//�A�b�v�f�[�g
{
			for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
		if(this->c_EffectBase[nLoop].GetFeed()> 0 && c_EffectBase[nLoop].chkFlag() != E_NONE)
		{
			switch(c_EffectBase[nLoop].chkFlag())
			{
			case E_P1_B://�v���C���[�e

			//�t�F�[�h�J��
			this->c_EffectBase[nLoop].SetFeed(c_EffectBase[nLoop].GetFeed()-(1.0f/this->c_EffectBase[nLoop].GetCnt()));
			this->c_EffectPoly.SetFeed(c_EffectBase[nLoop].GetFeed());
			this->c_EffectPoly.SetColor(c_EffectBase[nLoop].GetColR(),c_EffectBase[nLoop].GetColG(),c_EffectBase[nLoop].GetColB());
			//�|���S���ɒl�����
			this->c_EffectPoly.UpdatePolygon(c_EffectBase[nLoop].chkWitdth(),c_EffectBase[nLoop].chkHeight(),
													this->c_EffectBase[nLoop].chkPosX()-c_EffectBase[nLoop].chkWitdth()/2,this->c_EffectBase[nLoop].chkPosY(),nLoop);
			if(this->c_EffectBase[nLoop].GetFeed()  <= 0)
		{
			this->c_EffectBase[nLoop].SetCnt(0);
			this->c_EffectBase[nLoop].ChangeFlag(E_NONE);
			this->c_EffectPoly.SetFeed(1.0f);
		}
			break;
			case E_P2_B://�v���C���Q�e
						//�傫���ύX
			this->c_EffectBase[nLoop].ChangeSize(c_EffectBase[nLoop].chkWitdth()-(this->c_EffectBase[nLoop].GetCnt()),c_EffectBase[nLoop].chkHeight()-(this->c_EffectBase[nLoop].GetCnt()));
			//�ꏊ�ύX
			this->c_EffectBase[nLoop].ChangePos(this->c_EffectBase[nLoop].chkPosX()-(1.0f/this->c_EffectBase[nLoop].GetCnt()),this->c_EffectBase[nLoop].chkPosY());

			//�t�F�[�h�J��
			this->c_EffectBase[nLoop].SetFeed(c_EffectBase[nLoop].GetFeed()-(1.0f/this->c_EffectBase[nLoop].GetCnt()));
			this->c_EffectPoly.SetFeed(c_EffectBase[nLoop].GetFeed());
			this->c_EffectPoly.SetColor(c_EffectBase[nLoop].GetColR(),c_EffectBase[nLoop].GetColG(),c_EffectBase[nLoop].GetColB());
			//�|���S���ɒl�����
			this->c_EffectPoly.UpdatePolygon(c_EffectBase[nLoop].chkWitdth(),c_EffectBase[nLoop].chkHeight(),
													this->c_EffectBase[nLoop].chkPosX()-c_EffectBase[nLoop].chkWitdth()/2,this->c_EffectBase[nLoop].chkPosY(),nLoop);
			if(this->c_EffectBase[nLoop].GetFeed()  <= 0)
		{
			this->c_EffectBase[nLoop].SetCnt(0);
			this->c_EffectBase[nLoop].ChangeFlag(E_NONE);
			this->c_EffectPoly.SetFeed(1.0f);
		}

				break;
			case E_E1_B://�G�e

			//�t�F�[�h�J��
			this->c_EffectBase[nLoop].SetFeed(c_EffectBase[nLoop].GetFeed()-(1.0f/this->c_EffectBase[nLoop].GetCnt()));
			this->c_EffectPoly.SetFeed(c_EffectBase[nLoop].GetFeed());
			this->c_EffectPoly.SetColor(c_EffectBase[nLoop].GetColR(),c_EffectBase[nLoop].GetColG(),c_EffectBase[nLoop].GetColB());
			//�|���S���ɒl�����
			this->c_EffectPoly.UpdatePolygon(c_EffectBase[nLoop].chkWitdth(),c_EffectBase[nLoop].chkHeight(),
													this->c_EffectBase[nLoop].chkPosX()-c_EffectBase[nLoop].chkWitdth()/2,this->c_EffectBase[nLoop].chkPosY(),nLoop);
			if(this->c_EffectBase[nLoop].GetFeed()  <= 0)
		{
			this->c_EffectBase[nLoop].SetCnt(0);
			this->c_EffectBase[nLoop].ChangeFlag(E_NONE);
			this->c_EffectPoly.SetFeed(1.0f);
		}
			break;

			case E_Ex://����
			this->c_EffectBase[nLoop].ChangeSize(c_EffectBase[nLoop].chkWitdth()+this->c_EffectBase[nLoop].GetCnt(),c_EffectBase[nLoop].chkHeight()+this->c_EffectBase[nLoop].GetCnt());
			//�ꏊ�ύX
			this->c_EffectBase[nLoop].ChangePos(this->c_EffectBase[nLoop].chkPosX(),this->c_EffectBase[nLoop].chkPosY());
			
			if(this->c_EffectBase[nLoop].GetFeed()  > 1)//�t�F�[�h���P�𒴂�����
			{
				this->c_EffectBase[nLoop].SetMoveX(c_EffectBase[nLoop].GetMoveX()*-1);
			}
			
			//�t�F�[�h�J��
			this->c_EffectBase[nLoop].SetFeed(c_EffectBase[nLoop].GetFeed()+c_EffectBase[nLoop].GetMoveX());
			this->c_EffectPoly.SetFeed(c_EffectBase[nLoop].GetFeed());
			this->c_EffectPoly.SetColor(c_EffectBase[nLoop].GetColR(),c_EffectBase[nLoop].GetColG(),c_EffectBase[nLoop].GetColB());
			//�|���S���ɒl�����
			this->c_EffectPoly.UpdatePolygon(c_EffectBase[nLoop].chkWitdth(),c_EffectBase[nLoop].chkHeight(),
													this->c_EffectBase[nLoop].chkPosX()-c_EffectBase[nLoop].chkWitdth()/2,this->c_EffectBase[nLoop].chkPosY(),nLoop);
		if(this->c_EffectBase[nLoop].GetFeed()  <= 0)
		{
			this->c_EffectBase[nLoop].SetCnt(0);
			this->c_EffectBase[nLoop].ChangeFlag(E_NONE);
			this->c_EffectPoly.SetFeed(1.0f);
		}
				break;

			}
		}
	}
}

void EFFECTMANAGE::EffectSet(float fPosX,float fPosY,float fSizeW,float fSizeH,float fLimit,float nR,float nG,float nB,int nEflag)//�Z�b�g
{
		for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
		if(c_EffectBase[nLoop].GetCnt()==0)
		{
		this->c_EffectBase[nLoop].ChangePos(fPosX+fSizeW/2,fPosY+fSizeH/2);
		if(nEflag==E_P2_B)
		{
					this->c_EffectBase[nLoop].ChangeSize(fSizeW*15,fSizeH*15);
		}else{
		this->c_EffectBase[nLoop].ChangeSize(fSizeW,fSizeH);
		}
		this->c_EffectBase[nLoop].ChangeFlag(nEflag);
		this->c_EffectBase[nLoop].SetCnt(fLimit);
		c_EffectBase[nLoop].SetCol(nR,nG,nB);
		this->c_EffectBase[nLoop].SetMoveX((1.0f/this->c_EffectBase[nLoop].GetCnt()));
		if(nEflag != E_Ex)
		{
		c_EffectBase[nLoop].SetFeed(0.5);
		}else{
		c_EffectBase[nLoop].SetFeed(0.01);
		}
		break;

		}
	}
}

void EFFECTMANAGE::EffectDraw()//�\��
{
		for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
		if(c_EffectBase[nLoop].chkFlag()!=0)
		{ 
			GetDevice()->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
			this->c_EffectPoly.DrawPolygon(nLoop);			
			GetDevice()->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
		}
	}
}
void EFFECTMANAGE::EffectReset()//���Z�b�g
{
		for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
	}
}
void EFFECTMANAGE::EffectUninit()//�J��
{
		for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
		this->c_EffectPoly.UninitPolygon();
	}
}
void EFFECTMANAGE::EffectSetCol(float nR,float nG,float nB)
{
		for(int nLoop = 0;nLoop<EFFECT_MAX;nLoop++)
	{
		this->c_EffectBase[nLoop].SetCol(nR,nG,nB);
	}
}