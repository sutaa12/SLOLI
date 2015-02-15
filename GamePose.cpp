//=============================================================================
//
// カーゲームα [GameBG0.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "GamePose.h"

//*****************************************************************************
// グローバル変数:
//*****************************************************************************
//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//=============================================================================
// 初期化関数
//=============================================================================
void GAMEPOSEMenu::InitGamePS(void)//ポリゴン初期化で結果を返す
{
	nFlag = M_RETURN;
	float BaseY = Base_Y;
	this->BGBase.InitBase(0,0,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
	this->BGPolygon.InitPolygon(PS1,SCREEN_WIDTH,SCREEN_HEIGHT,BGBase.chkPosX(),BGBase.chkPosY(),1);
	this->BGPolygon.SetFeed(0.9f);

	this->m_PoseLogo.InitPolygon(POSEL,L_W,B_H,LOGO_X,BaseY,1);
	BaseY+=Base_Y+B_H;
	this->m_Return.InitPolygon(RETURN,B_W,B_H,B_X,BaseY,1);
	BaseY+=B_H;
	this->m_Rery.InitPolygon(RETRY,B_W,B_H,B_X,BaseY,1);
	BaseY+=B_H;
	this->m_Title.InitPolygon(TITLE,B_W,B_H,B_X,BaseY,1);
	BaseY+=B_H;
	this->m_Message.InitPolygon(MESSAGE,M_W,M_H,B_X,BaseY,1);

}
//=============================================================================
// 終了処理関数
//=============================================================================
void GAMEPOSEMenu::UnInitGamePS(void)//ポリゴン終了処理
{

	this->BGPolygon.UninitPolygon();

}
//=============================================================================
// アップデート関数
//=============================================================================
int GAMEPOSEMenu::UpdateGamePS(void)//ポリゴンアップデート
{
	this->BGPolygon.UpdatePolygon(SCREEN_WIDTH,SCREEN_HEIGHT,BGBase.chkPosX(),BGBase.chkPosY(),0);
	this->BGBase.SetCnt(BGBase.GetCnt()+1);
	this->BGBase.SetCnt(BGBase.GetCnt()%60);
	
	if(GetKeyboardRepeat(DIK_UP))
	{
		nFlag=(nFlag+(M_PMAX-1))%M_PMAX;
	}else
	if(GetKeyboardRepeat(DIK_DOWN))
	{
		nFlag=(nFlag+1)%M_PMAX;
	}
	if(GetKeyboardTrigger(DIK_RETURN))
	{
		switch(nFlag)
		{
		case M_RETURN:
			return MAINGAME;
			break;
		case M_RETRY:
			return INITGAME;
			break;
		case M_TITLE:
			return GAMETITLE;
			break;
		}
	}
return POSEGAME;
}
//=============================================================================
// 描画関数
//=============================================================================
void GAMEPOSEMenu::DrawGamePS(void)//ポリゴン描画
{
	//ポリゴン表示
	this->BGPolygon.DrawPolygon(0);
	this->m_PoseLogo.DrawPolygon(0);
	if(nFlag!=M_RETURN||BGBase.GetCnt()%2==0)
	{
	this->m_Return.DrawPolygon(0);
	}
	if(nFlag!=M_RETRY||BGBase.GetCnt()%2==0)
	{
	this->m_Rery.DrawPolygon(0);
	}
	if(nFlag!=M_TITLE||BGBase.GetCnt()%2==0)
	{
	this->m_Title.DrawPolygon(0);
	}
	this->m_Message.DrawPolygon(0);

}