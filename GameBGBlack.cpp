//=============================================================================
//
// カーゲームα [GameBG0.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "GameBGBACK.h"

//*****************************************************************************
// グローバル変数:
//*****************************************************************************
//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//=============================================================================
// 初期化関数
//=============================================================================
void GAMEBG0IMAGE::InitGameBG(void)//ポリゴン初期化で結果を返す
{
	
	this->BGBase.InitBase(GAME_MAX_W,0,0,0,BG0SIZE_WH,BG0SIZE_WH,0);
	this->BGPolygon.InitPolygon(BG0,BG0SIZE_WH,BG0SIZE_WH,BGBase.chkPosX(),BGBase.chkPosY(),1);
	this->BGPolygon.SetColor(0.0f,0.0f,0.0f);
	float PosY=BASE_Y;
	this->BGScoreL.InitPolygon(SCORE,SCOREL_W,SOCREL_H,BASE_X,PosY,1);
	PosY+=SOCREL_H*2;
	this->BGPLifeL.InitPolygon(LIFEL,SCOREL_W,SOCREL_H,BASE_X,PosY,1);
	PosY+=SOCREL_H;

	this->BGLife.InitPolygon(LIFE,LIFE_HW,LIFE_HW,BASE_X,PosY,3);
}
//=============================================================================
// 終了処理関数
//=============================================================================
void GAMEBG0IMAGE::UnInitGameBG(void)//ポリゴン終了処理
{

	this->BGPolygon.UninitPolygon();

}
//=============================================================================
// アップデート関数
//=============================================================================
void GAMEBG0IMAGE::UpdateGameBG(void)//ポリゴンアップデート
{

	for(int nLoop=0;nLoop<3;nLoop++)
	{
		this->BGLife.UpdatePolygon(LIFE_HW,LIFE_HW,BASE_X+(LIFE_HW*nLoop),400,nLoop);
	}
	this->BGPolygon.PolygonFeed();
}
//=============================================================================
// 描画関数
//=============================================================================
void GAMEBG0IMAGE::DrawGameBG(int nLife)//ポリゴン描画
{
	//ポリゴン表示
	this->BGPolygon.DrawPolygon(0);
	this->BGScoreL.DrawPolygon(0);
	this->BGPLifeL.DrawPolygon(0);

	for(int nLoop=0;nLoop<nLife;nLoop++)
	{
	this->BGLife.DrawPolygon(nLoop);
	}


	

}