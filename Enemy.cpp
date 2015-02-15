//=============================================================================
//
// 敵管理 [ENEMY.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Enemy.h"
#include"Base.h"
#include"Polygon.h"
#include "input.h"

//=============================================================================
//マクロ定義
//*****************************************************************************
void ENEMYMANAGE::InitEnemy(char *cTexPass,int nPwidth,int nPheight,int nEPosX,int nEPosY,float fTexX,float fTexY,int nFlag)
{
	for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
	nEPosX=rand()%(SCREEN_WIDTH/2);
	nEPosY=rand()%(SCREEN_HEIGHT/2);
	
	this->EnemyBase[nLoop].InitBase(nEPosX,nEPosY,fTexX,fTexY,nPwidth,nPheight,nFlag);
	
	c_fLength=sqrtf((ESIZE_W/2.0f*ESIZE_W/2.0f)+(ESIZE_H/2.0f*ESIZE_H/2.0f));
	c_fAngle=atan2(ESIZE_W/2.0f,ESIZE_H/2.0f);

	c_pos[nLoop].x=EnemyBase[nLoop].chkPosX()+(ESIZE_W/2.0f);
	c_pos[nLoop].y=EnemyBase[nLoop].chkPosY()+(ESIZE_H/2.0f);//中心座標
	c_rot.z=(D3DX_PI/180)*90;//角度
	}
	this->EnemyPolygon.InitPolygon(cTexPass,nPwidth,nPheight,nEPosX,nEPosY,ENEMY_MAX);

}

void ENEMYMANAGE::EnemyUpdate()
{

		for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
			if(EnemyBase[nLoop].chkFlag()==0)
		{
			SetEnemy(nLoop);
		}
		if(EnemyBase[nLoop].chkFlag()==1)
		{
		this->EnemyBase[nLoop].SetBFlag(0);

		this->EnemyBase[nLoop].SetCnt(this->EnemyBase[nLoop].GetCnt()+1);
		this->EnemyBase[nLoop].SetCnt(this->EnemyBase[nLoop].GetCnt()%120+1);

		this->EnemyBase[nLoop].SetBFlag(this->EnemyBase[nLoop].GetCnt()/120);

	c_pos[nLoop].x=EnemyBase[nLoop].chkPosX()+(ESIZE_W/2.0f);
	c_pos[nLoop].y=EnemyBase[nLoop].chkPosY()+(ESIZE_H/2.0f);//中心座標

			this->EnemyPolygon.UpdatePolygonROTE(	c_pos[nLoop].x + sinf( - c_fAngle - c_rot.z) * c_fLength,c_pos[nLoop].y - cosf( - c_fAngle - c_rot.z) * c_fLength,
																					c_pos[nLoop].x - sinf( - c_fAngle + c_rot.z) * c_fLength,c_pos[nLoop].y -  cosf( - c_fAngle + c_rot.z) * c_fLength,
																					c_pos[nLoop].x - sinf(c_fAngle - c_rot.z) * c_fLength,c_pos[nLoop].y + cosf(c_fAngle - c_rot.z) * c_fLength,
																					c_pos[nLoop].x + sinf(c_fAngle + c_rot.z) * c_fLength,c_pos[nLoop].y + cosf(c_fAngle + c_rot.z) * c_fLength ,nLoop);
			}
	}

		EnemyMove();
}
void ENEMYMANAGE::EnemyMove(void)
{
			for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
		this->EnemyBase[nLoop].ChangePos(EnemyBase[nLoop].chkPosX()+EnemyBase[nLoop].GetMoveX(),EnemyBase[nLoop].chkPosY()+EnemyBase[nLoop].GetMoveY());
	if((EnemyBase[nLoop].chkPosX()<-ESIZE_W||EnemyBase[nLoop].chkPosX()>SCREEN_WIDTH+ESIZE_W||EnemyBase[nLoop].chkPosY()>SCREEN_HEIGHT+ESIZE_H)&&this->EnemyBase[nLoop].GetCnt()>90)
	{
		EnemyBase[nLoop].ChangeFlag(0);
	}
	}
}
int ENEMYMANAGE::EnemyChkFlag(int nNum)
{
	return EnemyBase[nNum].chkFlag();
}

void ENEMYMANAGE::DrawEnemy()
{
		for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
		if(EnemyBase[nLoop].chkFlag()==1)
		{
		this->EnemyPolygon.DrawPolygon(nLoop);
		}
	}
}
void ENEMYMANAGE::UninitEnemy()
{
	for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
		this->EnemyPolygon.UninitPolygon();
	}
}

void ENEMYMANAGE::AnimSet()
{
		for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
	//this->EnemyPolygon[nLoop].SetTexUV((1.0f/WAIT_ANIM*((c_nPTexPattern/100)%WAIT_ANIM)),0,1.0/WAIT_ANIM,1.f);
	}
}

void ENEMYMANAGE::SetEnemy(int nNum)
{
			EnemyBase[nNum].SetCnt(EnemyBase[nNum].GetCnt()+1);

			if(EnemyBase[nNum].GetCnt()>70)
			{
			int nMode;
			nMode = rand()%4;
				EnemyBase[nNum].ChangeFlag(1);
				EnemyBase[nNum].SetCnt(0);
				switch(nMode)
				{
				case 0://右から
				EnemyBase[nNum].ChangePos(SCREEN_WIDTH+ESIZE_W,rand()%(SCREEN_HEIGHT/2));
				EnemyBase[nNum].SetMoveX(-0.5f);
				EnemyBase[nNum].SetMoveY(0.0f);
				break;

				case 1://左から
				EnemyBase[nNum].ChangePos(-ESIZE_W,rand()%(SCREEN_HEIGHT/2));
				EnemyBase[nNum].SetMoveX(0.5f);
				EnemyBase[nNum].SetMoveY(0.0f);
				break;
				case 2://上から
				EnemyBase[nNum].ChangePos(rand()%(GAME_MAX_W),-ESIZE_H);
				EnemyBase[nNum].SetMoveX(0.5f);
				EnemyBase[nNum].SetMoveY(0.5f);
				break;
				case 3://左へ
				EnemyBase[nNum].ChangePos(rand()%(GAME_MAX_W),-ESIZE_H);
				EnemyBase[nNum].SetMoveX(-0.5f);
				EnemyBase[nNum].SetMoveY(0.5f);
				break;
				}
			}
}