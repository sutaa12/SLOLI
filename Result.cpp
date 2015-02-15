//=============================================================================
//
// 画面遷移 [Result.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "Result.h"
#include "sound.h"
//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
#define RSC_X (320)
#define RSC_Y (370)
//=============================================================================
// 初期化関数
//=============================================================================
HRESULT RESULTMODE::InitResult(int nScore)//リザルト初期化で結果を返す
{
	c_nScore=nScore;
	ResultButton.InitPolygon(STARTL,MOJIR_W,MOJIR_H,MOJIRX,MOJIRY,1);
	ReslutBG.InitResultBG();
	ResultLogo.InitResultLogo();
	ResultButton.SetFeed(0.1);
	c_Score.InitScore();
	c_Score.SetScoreXY(RSC_X,RSC_Y);
	c_Score.AddScore(c_nScore);
	PlaySound(SOUND_LABEL_BGM002);
	return S_OK;
}
//=============================================================================
// 終了処理関数
//=============================================================================
void RESULTMODE::UnInitResult(void)//リザルト終了処理
{
	StopSound();
	ResultButton.UninitPolygon();
	ReslutBG.UnInitResultBG();
	ResultLogo.UnInitResultLogo();
	c_Score.UnInitScore();

}
//=============================================================================
// アップデート関数
//=============================================================================
void RESULTMODE::UpdateResult(void)//リザルトアップデート
{
	if(GetKeyboardTrigger(DIK_RETURN))//Pでポーズ切り替え
	{
	c_Rmode.SetFlag(MODE_TITLE);
	}
		if(ResultButton.Feedchk()<=0)
	{
		ResultButton.PolygonFeedIN();
	}else
	if(ResultButton.Feedchk()>=1)
	{
		ResultButton.PolygonFeedOUT();
	}

	ReslutBG.UpdateResultBG();
	ResultLogo.UpdateResultLogo();
	c_Score.UpdateScore();
	ResultButton.PolygonFeed();
}
//=============================================================================
// 描画関数
//=============================================================================
void RESULTMODE::DrawResult(void)//リザルト描画
{
	ReslutBG.DrawResultBG();
	ResultLogo.DrawResultLogo();
	ResultButton.DrawPolygon(0);
	c_Score.DrawScore();
}