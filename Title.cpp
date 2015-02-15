//=============================================================================
//
// 画面遷移 [Title.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include"sound.h"
#include "Title.h"
#include "ModeManage.h"
//*****************************************************************************
// グローバル変数:
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//=============================================================================
// 初期化関数
//=============================================================================
HRESULT TITLEMODE::InitTitle(void)//タイトル初期化で結果を返す
{
	PlaySound(SOUND_LABEL_BGM000);
	TitleBg.InitTitleBG();
	TitleLogo.InitTitleLogo();
	SelectMoji.InitPolygon(MOJIL,MOJIL_W,MOJIL_H,MOJIX,MOJIY,1);
	TitleButton.InitPolygon(STARTL,MOJI_W,MOJI_H,MOJIX,MOJIY,1);
	SelectBG.InitPolygon(SELECTBG,BG_WH,BG_WH,0,0,1);
	SelectLogo.InitPolygon(SELECT_LOGO,SLOGO_W,SLOGO_H,SLOGO_X,SLOGO_Y,1);
	SelectChara1.InitPolygon(CHARA1,CHARA_WH,CHARA_WH,0,0,1);
	SelectChara2.InitPolygon(CHARA2,CHARA_WH,CHARA_WH,CHARA2_X,0,1);
	SelectMoji.SetFeed(0);
	SelectBG.SetFeed(0);
	SelectLogo.SetFeed(0);
	SelectChara1.SetFeed(0);
	SelectChara2.SetFeed(0);
	TitleButton.SetFeed(0.1);
	SelectBG.SetColor(1,1,1);
	SelectChara1.SetColor(1,1,1);
	SelectChara2.SetColor(1,1,1);
	m_SlectSet=NONE_S;
	return S_OK;
}
//=============================================================================
// 終了処理関数
//=============================================================================
void TITLEMODE::UnInitTitle(void)//タイトル終了処理
{
	SelectMoji.UninitPolygon();
	TitleButton.UninitPolygon();
	SelectBG.UninitPolygon();
	SelectLogo.UninitPolygon();
	SelectChara1.UninitPolygon();
	SelectChara2.UninitPolygon();
	StopSound();
	TitleBg.UnInitTitleBG();
	TitleLogo.UnInitTitleLogo();
		m_SlectSet=NONE_S;
}
//=============================================================================
// アップデート関数
//=============================================================================
int TITLEMODE::UpdateTitle(void)//タイトルアップデート
{
	if(GetKeyboardTrigger(DIK_RETURN)&&	m_SlectSet==NONE_S)//Pでポーズ切り替え
	{
	PlaySound(SOUND_LAVEL_SE_BUTTON);
	SelectBG.SetFeed(0.1);
	SelectLogo.SetFeed(0.1);
	SelectChara1.SetFeed(0.1);
	SelectChara2.SetFeed(0.1);
	SelectMoji.SetFeed(0.1);
	m_SlectSet=MAIN_S;
	}

		if(GetKeyboardTrigger(DIK_RETURN))
	{
	if(m_SlectSet==CHARA1_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
		c_TFlag.SetFlag(MODE_GAME);
		return CHARA1_MODE;
	}else
	if(m_SlectSet==CHARA2_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
		c_TFlag.SetFlag(MODE_GAME);
		return CHARA2_MODE;

	}
	}

	if(TitleButton.Feedchk()<=0)
	{
		TitleButton.PolygonFeedIN();
	}else
	if(TitleButton.Feedchk()>=1)
	{
		TitleButton.PolygonFeedOUT();
	}
	UpdateSelect();
	TitleBg.UpdateTitleBG();
	TitleLogo.UpdateTitleLogo();
	TitleButton.PolygonFeed();
}
//=============================================================================
// 描画関数
//=============================================================================
void TITLEMODE::DrawTitle(void)//タイトル描画
{
	TitleBg.DrawTitleBG();
	TitleLogo.DrawTitleLogo();
	TitleButton.DrawPolygon(0);
	DrawSlect();
	
}
void TITLEMODE::UpdateSelect(void)//セレクト画面
{
	if(	m_SlectSet!=NONE_S&&SelectBG.Feedchk()>=1)
	{
	if(GetKeyboardTrigger(DIK_RIGHT)&&m_SlectSet!=CHARA2_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
	SelectBG.SetColor(0.5,0.5,0.5);
	SelectChara1.SetColor(0.5,0.5,0.5);
	SelectChara2.SetColor(1,1,1);
	m_SlectSet=CHARA2_S;
	}else
	if(GetKeyboardTrigger(DIK_LEFT)&&	m_SlectSet!=CHARA1_S)
	{
		PlaySound(SOUND_LAVEL_SE_BUTTON);
	SelectBG.SetColor(0.5,0.5,0.5);
	SelectChara2.SetColor(0.5,0.5,0.5);
	SelectChara1.SetColor(1,1,1);
	m_SlectSet=CHARA1_S;
	}

	}
	SelectMoji.PolygonFeed();
	SelectBG.PolygonFeed();
	SelectLogo.PolygonFeed();
	SelectChara1.PolygonFeed();
	SelectChara2.PolygonFeed();
}
void TITLEMODE::DrawSlect(void)//タイトル描画
{
	SelectBG.DrawPolygon(0);
	SelectLogo.DrawPolygon(0);
	SelectChara1.DrawPolygon(0);
	SelectChara2.DrawPolygon(0);
	SelectMoji.DrawPolygon(0);
}
