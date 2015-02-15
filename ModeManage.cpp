//=============================================================================
//
// モード管理 [ModeManage.cpp]
// Author : NARITADA SUZUKI
//=============================================================================
//インクルード
//*****************************************************************************
#include "main.h"
#include "ModeManage.h"
//*****************************************************************************
void cModeManage::ModeInit()//初期化
{
	c_Score=0;
	c_ModeFlag = MODE_TITLE;
	c_MFlag.SetFlag(MODE_TITLE);
	c_ModeOldFlag=c_ModeFlag;//初期の値
	c_nPmode=0;

		c_ScreenFeed.InitFeed("",SCREEN_WIDTH,SCREEN_HEIGHT,0,0,1,1,0);//フェード初期化
	switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.InitTitle();
		break;
	case MODE_GAME:
		Gamemode.InitGame(c_nPmode);
		break;
	case MODE_RESLUT:
		Reslutmode.InitResult(c_Score);
		break;
	}
}
void cModeManage::ModeUpdate()//アップデート
{
	c_ModeFlag=c_MFlag.GetFlag();
	c_ScreenFeed.FeedUpdate();//フェードアップデート
	if(c_ModeFlag==c_ModeOldFlag)//フラグが合わない場合
	{
		switch(c_ModeFlag)
		{
		case MODE_TITLE:
		c_nPmode=Titlemode.UpdateTitle();
			break;
		case MODE_GAME:
			Gamemode.UpdateGame();
			break;
		case MODE_RESLUT:
			Reslutmode.UpdateResult();
			break;
		}
	}	
		if(c_ScreenFeed.FeedChk()==0)//始まり
		{
		if(c_ModeFlag!=c_ModeOldFlag)//フラグが合わない場合
		{
			c_ScreenFeed.FeedSet(FEEDIN);
		}
		}

		if(c_ScreenFeed.FeedChk()>=1)//フェードチェック折り返しなら
		{
			c_ScreenFeed.FeedSet(FEEDOUT);//フェードアウト
		MODNumUninit();//終了
		c_ModeOldFlag=c_ModeFlag;
		MODNumInit();
		}

}
void cModeManage::ModeDraw()//描画
{
		switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.DrawTitle();
		break;
	case MODE_GAME:
		Gamemode.DrawGame();
		break;
	case MODE_RESLUT:
		Reslutmode.DrawResult();
		break;
	}

	c_ScreenFeed.DrawFeed();
}
void cModeManage::ModeUninit()//終了
{
			c_ScreenFeed.UninitFeed();
		switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.UnInitTitle();
		break;
	case MODE_GAME:
		c_Score = Gamemode.UnInitGame();
		break;
	case MODE_RESLUT:
		Reslutmode.UnInitResult();
		break;
	}

}

//=============================================================================
//モード初期化処理
//=============================================================================
void cModeManage::MODNumInit(void)
{
		switch(c_ModeFlag)
	{
	case MODE_TITLE:
		Titlemode.InitTitle();
		break;
	case MODE_GAME:
		Gamemode.InitGame(c_nPmode);
		break;
	case MODE_RESLUT:
		Reslutmode.InitResult(c_Score);
		break;
	}
}
//=============================================================================
//モード終了処理
//=============================================================================
void cModeManage::MODNumUninit(void)
{
	switch(c_ModeOldFlag)
	{
	case MODE_TITLE:
		Titlemode.UnInitTitle();
		break;
	case MODE_GAME:
		c_Score = Gamemode.UnInitGame();
		break;
	case MODE_RESLUT:
		Reslutmode.UnInitResult();
		break;
	}
}
