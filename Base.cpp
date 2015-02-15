//=============================================================================
//
// �x�[�X�Ǘ� [Base.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"main.h"
#include"Base.h"
//*****************************************************************************
 cBase::cBase(float fPosX,float fPosY,float fTexX,float fTexY,int nWitdh,int nHeight,int nFlag)
 {
	 	//�Â��l�o�b�N�A�b�v
	c_foldPosX = c_fPosX;
	c_foldPosY = c_fPosX;
	//�ύX
	c_fPosX = fPosX;
	c_fPosY = fPosY;
	c_nLFlag = nFlag;
	//�ύX
	c_nWitdh = nWitdh;
	c_nHeight = nHeight;
	//�ύX
	c_fTexX = fTexX;
	c_fTexY = fTexY;
	c_nCnt = 0;
	c_nBFlag = 0;
	c_fMovex = 0;
	c_fMovey = 0;
 }

 cBase::cBase()
 {
 }

  void cBase::InitBase(float fPosX,float fPosY,float fTexX,float fTexY,int nWitdh,int nHeight,int nFlag)
 {
	 	//�Â��l�o�b�N�A�b�v
	c_foldPosX = c_fPosX;
	c_foldPosY = c_fPosX;
	//�ύX
	c_fPosX = fPosX;
	c_fPosY = fPosY;
	c_nLFlag = nFlag;
	//�ύX
	c_nWitdh = nWitdh;
	c_nHeight = nHeight;
	//�ύX
	c_fTexX = fTexX;
	c_fTexY = fTexY;
	c_nCnt = 0;
	c_nBFlag = 0;
 }

void cBase::ChangeFlag(int nFlag)
{
	c_nLFlag = nFlag;
}

void cBase::ChangePos(float fPosX,float fPosY)
{
	//�Â��l�o�b�N�A�b�v
	c_foldPosX = c_fPosX;
	c_foldPosY = c_fPosX;
	//�ύX
	c_fPosX = fPosX;
	c_fPosY = fPosY;

}

void cBase::ChangeTex(float fTexX,float fTexY)
{
	//�ύX
	c_fTexX = fTexX;
	c_fTexY = fTexY;
}

void cBase::ChangeSize(int nWitdh,int nHeight)
{
	//�ύX
	c_nWitdh = nWitdh;
	c_nHeight = nHeight;
}

void cBase::SetCnt(int nCount)
{
	c_nCnt=nCount;
}

int cBase::GetCnt(void)
{
	return c_nCnt;
}

int cBase::chkFlag(void)
{
	return c_nLFlag;
}

float cBase::chkPosX(void)
{
	return c_fPosX;
}
float cBase::chkPosY(void)
{
	return c_fPosY;
}

float cBase::chkTexX(void)
{
	return c_fTexX;
}
float cBase::chkTexY(void)
{
	return c_fTexY;
}

int cBase::chkWitdth(void)
{
	return c_nWitdh;
}

int cBase::chkHeight(void)
{
	return c_nHeight;
}
	//�t�F�[�h�l��Ԃ�
float cBase::GetFeed(void)
{
	return c_fFeed;
}
	//�t�F�[�h�l�ύX
void cBase::SetFeed(float fFeedO)
{
	if(fFeedO>1)
	{
		c_fFeed=1;
	}else
		if(fFeedO<0)
		{
			c_fFeed=0;
		}
	c_fFeed=fFeedO;
}