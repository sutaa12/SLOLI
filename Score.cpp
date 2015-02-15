//=============================================================================
//
// カーゲームα [Score.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include <math.h>
#include "Score.h"

//*****************************************************************************
// グローバル変数:
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//=============================================================================
// 初期化関数
//=============================================================================
void SCOREIMAGE::InitScore(void)//ポリゴン初期化で結果を返す
{
	for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScoreBase[nLoop].InitBase(SCORE_X+(nLoop*SCORE_W),SCORE_Y,0,0,SCORE_W,SCORE_H,0);	
	}
	this->c_ScorePolygon.InitPolygon(SCORE1,SCORE_W,SCORE_H,SCORE_X,SCORE_Y,SCORE_MAX);
}
//=============================================================================
// 終了処理関数
//=============================================================================
void SCOREIMAGE::UnInitScore(void)//ポリゴン終了処理
{
		for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScorePolygon.UninitPolygon();
	}
		c_nScoreNum=0;
}
//=============================================================================
// アップデート関数
//=============================================================================
void SCOREIMAGE::UpdateScore(void)//ポリゴンアップデート
{
	int nNumberold=c_nScoreNum;//桁引継ぎ
	for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		int nNumber;//桁さがし
		//一番大きい桁で割り１０と前の桁の数
		nNumber=nNumberold/(int)pow((float)10,(float)SCORE_MAX-nLoop-1);
	
		this->c_ScoreBase[nLoop].ChangeTex(0.0f+(nNumber/10.0f),0.0f);

		this->c_ScorePolygon.SetTexUV(this->c_ScoreBase[nLoop].chkTexX(),this->c_ScoreBase[nLoop].chkTexY(),
																0.1f,1.0f);
		this->c_ScorePolygon.UpdatePolygon(SCORE_W,SCORE_H,c_ScoreBase[nLoop].chkPosX(),c_ScoreBase[nLoop].chkPosY(),nLoop);
	
		nNumberold-=nNumber*(int)pow((float)10,(float)SCORE_MAX-nLoop-1);//前の桁削除
	}
}
//=============================================================================
// 描画関数
//=============================================================================
void SCOREIMAGE::DrawScore(void)//ポリゴン描画
{
		for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScorePolygon.DrawPolygon(nLoop);
	}
}

void SCOREIMAGE::AddScore(int nValue)
{

	c_nScoreNum+=nValue;//スコア加算
	if(c_nScoreNum>(int)pow((float)10,(float)SCORE_MAX))
	{
		c_nScoreNum=(int)pow((float)10,(float)SCORE_MAX)-1;
	}else
		if(c_nScoreNum<0)
		{
			c_nScoreNum=0;
		}


}
void  SCOREIMAGE::SetScoreXY(float fX,float fY)
{
		for(int nLoop=0;nLoop<SCORE_MAX;nLoop++)
	{
		this->c_ScoreBase[nLoop].InitBase(fX+(nLoop*SCORE_W),fY,0,0,SCORE_W,SCORE_H,0);	
	}
}