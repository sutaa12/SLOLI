//=============================================================================
//
// プレイヤー管理 [Player.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Game.h"
#include"Player.h"
#include"Base.h"
#include"Polygon.h"
#include "input.h"
//=============================================================================
//マクロ定義
//*****************************************************************************
#define OFF (0)
#define ON (1)
#define WAIT_ANIM (3)
#define WAIT_SET (20)
#define AnimSpeed (16)



enum KEYINPUT
{
	NONE,
	LEFT,
	RIGHT
};
#define MoveDown (0.6f)

//*****************************************************************************
Player::Player()
{
}

void Player::PlayerUpdate()
{
	AnimSet();
	//キー判定
		if(GetKeyboardPress(DIK_RIGHT) == TRUE&&PlayerBase.chkPosX()+PSIZE_W<GAME_MAX_W)
		{
			PlayerBase.SetMoveX((c_fSpeed-PlayerBase.GetMoveX())*MoveDown);
		}else
		if(GetKeyboardPress(DIK_LEFT) == TRUE&&PlayerBase.chkPosX()>0)
		{
			PlayerBase.SetMoveX(((-c_fSpeed-PlayerBase.GetMoveX())*MoveDown));
		}

		if(GetKeyboardPress(DIK_DOWN) == TRUE&&PlayerBase.chkPosY()+PSIZE_H<SCREEN_HEIGHT)
		{
			PlayerBase.SetMoveY((c_fSpeed-PlayerBase.GetMoveY())*MoveDown);
		}else
		if(GetKeyboardPress(DIK_UP) == TRUE&&PlayerBase.chkPosY()>0)
		{
		PlayerBase.SetMoveY(((-c_fSpeed-PlayerBase.GetMoveY())*MoveDown));
		}

		this->PlayerBase.SetMoveX(PlayerBase.GetMoveX()*MoveDown);
		this->PlayerBase.SetMoveY(PlayerBase.GetMoveY()*MoveDown);
		PlayerBase.ChangePos(PlayerBase.chkPosX()+PlayerBase.GetMoveX(),PlayerBase.chkPosY()+PlayerBase.GetMoveY());
		if(c_fPPosX<0)
			{
				PlayerBase.ChangePos(0,PlayerBase.chkPosY());
			}
				if(c_fPPosY<0)
			{
				PlayerBase.ChangePos(PlayerBase.chkPosX(),0);
			}
			this->PlayerPolygon.UpdatePolygon(PlayerBase.chkWitdth(),PlayerBase.chkHeight(),
											PlayerBase.chkPosX(),PlayerBase.chkPosY(),0);
}

void Player::PlayerReset(float nPPosX,float nPPosY)
{
	c_fSpeed=Speed;
	PlayerBase.ChangePos(nPPosX,nPPosY);
	this->PlayerBase.SetMoveX(0);
	this->PlayerBase.SetMoveY(0);
	SetLFlag(PLAYER_MAX);
}

void Player::InitPlayer(char *cTexPass,int nPwidth,int nPheight,float nPPosX,float nPPosY,float fTexX,float fTexY,int nFlag)
{
	c_fSpeed=Speed;
	c_nPTexPattern=WAIT_SET;
	c_nPTexMove=AnimSpeed;
	this->PlayerBase.InitBase(nPPosX,nPPosY,fTexX,fTexY,nPwidth,nPheight,nFlag);
	this->PlayerBase.SetMoveX(0);
	this->PlayerBase.SetMoveY(0);
	this->PlayerPolygon.InitPolygon(cTexPass,nPwidth,nPheight,nPPosX,nPPosY,1);
}

void Player::DrawPlayer()
{
	if(GetLFlag()!=0)
	{
	this->PlayerPolygon.DrawPolygon(0);
	}
}
void Player::UninitPlayer()
{
	this->PlayerPolygon.UninitPolygon();
}

void Player::AnimSet()
{
	
	c_nPTexPattern+=c_nPTexMove;		
	if(c_nPTexPattern>(WAIT_ANIM*90)||c_nPTexPattern<=WAIT_SET)
	{
		c_nPTexMove*=-1;
	}
	this->PlayerPolygon.SetTexUV((1.0f/WAIT_ANIM*((c_nPTexPattern/100)%WAIT_ANIM)),0,1.0/WAIT_ANIM,1.f);
}

float Player::PoschkX()
{
	return this->PlayerBase.chkPosX();
}

float Player::PoschkY()
{
	return this->PlayerBase.chkPosY();
}