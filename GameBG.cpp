//=============================================================================
//
// カーゲームα [GameBG.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "GameBG.h"

//*****************************************************************************
// グローバル変数:
//*****************************************************************************
//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//=============================================================================
// 初期化関数
//=============================================================================
void GAMEBGIMAGE::InitGameBG(void)//ポリゴン初期化で結果を返す
{
	this->BGBase.InitBase(-BG_X,0,0,0,BGSIZE_WH,BGSIZE_WH,0);
	this->BGPolygon.InitPolygon(BG1,BGSIZE_WH,BGSIZE_WH,BGBase.chkPosX(),BGBase.chkPosX(),1);
}
//=============================================================================
// 終了処理関数
//=============================================================================
void GAMEBGIMAGE::UnInitGameBG(void)//ポリゴン終了処理
{

	this->BGPolygon.UninitPolygon();

}
//=============================================================================
// アップデート関数
//=============================================================================
void GAMEBGIMAGE::UpdateGameBG(void)//ポリゴンアップデート
{
	this->BGBase.ChangeTex(this->BGBase.chkTexX(),this->BGBase.chkTexY()-BG_SPEED);
	this->BGPolygon.SetTexUV(this->BGBase.chkTexX(),this->BGBase.chkTexY(),this->BGBase.chkTexX()+1,1);
	this->BGPolygon.UpdatePolygon(this->BGBase.chkWitdth(),this->BGBase.chkHeight(),this->BGBase.chkPosX(),this->BGBase.chkPosY(),0);
}
//=============================================================================
// 描画関数
//=============================================================================
void GAMEBGIMAGE::DrawGameBG(void)//ポリゴン描画
{
	//ポリゴン表示
	this->BGPolygon.DrawPolygon(0);
}