//=============================================================================
//
// �e�Ǘ� [BULLET.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"sound.h"
#include"main.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Base.h"
#include"Polygon.h"
#include"Player.h"
#include "input.h"
//=============================================================================
//�}�N����`
//*****************************************************************************
void BULLETMANAGE::InitBullet(char *cTexPass,int nPwidth,int nPheight,int nBPosX,int nBPosY,float fTexX,float fTexY,int nFlag)
{
	for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)
	{
	this->BulletBase[nLoop].InitBase(nBPosX,nBPosY,fTexX,fTexY,nPwidth,nPheight,nFlag);
	}
	this->BulletPolygon.InitPolygon(cTexPass,nPwidth,nPheight,nBPosX,nBPosY,BULLET_MAX);

}

void BULLETMANAGE::BulletUpdate(float fPosX,float fPosY)//�e�̐i�s
{
		for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)
	{
		if(BulletBase[nLoop].chkFlag()!=0)
		{
			if(BulletBase[nLoop].chkFlag()==PLAYER1_B||BulletBase[nLoop].chkFlag()==PLAYER2_B)//�v���C��[�Ȃ�
			{
				if(this->BulletBase[nLoop].chkPosY()<0)//�v���C���[�̒e�i�s
				{
					this->BulletBase[nLoop].ChangeFlag(NONE_B);
				}//
					this->BulletBase[nLoop].ChangePos(BulletBase[nLoop].chkPosX(),BulletBase[nLoop].chkPosY()-BULLET_SPEED);
					this->BulletPolygon.UpdatePolygon(BulletBase[nLoop].chkWitdth(),BulletBase[nLoop].chkHeight(),
					BulletBase[nLoop].chkPosX(),BulletBase[nLoop].chkPosY(),nLoop);
			}else//

			if(BulletBase[nLoop].chkFlag()==ENEMY1_B||BulletBase[nLoop].chkFlag()==ENEMY2_B)//�G�Ȃ�
			{
				if(this->BulletBase[nLoop].chkPosY()>SCREEN_HEIGHT)//�G�̒e�i�s
				{
					this->BulletBase[nLoop].ChangeFlag(0);
				}//
				this->BulletBase[nLoop].ChangePos(BulletBase[nLoop].chkPosX(),BulletBase[nLoop].chkPosY()+BULLET_SPEED);
				this->BulletPolygon.UpdatePolygon(BulletBase[nLoop].chkWitdth(),BulletBase[nLoop].chkHeight(),
				BulletBase[nLoop].chkPosX(),BulletBase[nLoop].chkPosY(),nLoop);
			}//
		}
	}//
		//update end
}

void BULLETMANAGE::SetBullet(float fPosX,float fPosY,int nMODE)
{
	

			if(nMODE==PLAYER2_B)
		{
			for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)
			{
			if(this->BulletBase[nLoop].chkFlag()==PLAYER2_B)
			{
			return;
			}
			}
		}

		for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)
	{
		if(this->BulletBase[nLoop].chkFlag()==0)
		{
			this->BulletBase[nLoop].ChangeFlag(nMODE);//�t���O���I����
			if(nMODE==PLAYER1_B)
			{
			this->BulletBase[nLoop].ChangePos(fPosX+PSIZE_W/2,fPosY-1);
			PlaySound(SOUND_LABEL_SE_SHOT);
			}else
			if(nMODE==PLAYER2_B)
			{
			this->BulletBase[nLoop].ChangePos(fPosX+PSIZE_W/2,fPosY-1);
			PlaySound(SOUND_LABEL_SE_SHOT);
			}else
			if(nMODE==ENEMY1_B)
			{
			this->BulletBase[nLoop].ChangePos(fPosX+20,fPosY+ESIZE_H);
			PlaySound(SOUND_LABEL_SE_SHOT2);
			}
			break;
		}
	}
}

int BULLETMANAGE::BulletFlagChk(int nNum)
{		
	return this->BulletBase[nNum].chkFlag();
}

void BULLETMANAGE::DrawBullet()
{
		for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)
	{
		if(this->BulletBase[nLoop].chkFlag()!=0)
		{
		this->BulletPolygon.DrawPolygon(nLoop);
		}
	}

}
void BULLETMANAGE::UninitBullet()
{
	for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)
	{
		this->BulletPolygon.UninitPolygon();
	}
}

void BULLETMANAGE::AnimSet()
{
		for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)
	{
	//this->BulletPolygon[nLoop].SetTexUV((1.0f/WAIT_ANIM*((c_nPTexPattern/100)%WAIT_ANIM)),0,1.0/WAIT_ANIM,1.f);
	}
}