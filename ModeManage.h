//=============================================================================
//
// モード管理 [ModeManage.h]
// Author : NARITADA SUZUKI
//========================================================
#ifndef MODE_FILE
#define MODE_FILE
//=============================================================================
//インクルード
//*****************************************************************************
#include "main.h"
#include "Game.h"
#include "Title.h"
#include "Result.h"
#include "Feed.h"
#include "ModeFlag.h"
//*****************************************************************************

//=============================================================================
//クラス定義
//=============================================================================
class cModeManage
{
public:
	cModeManage(){}//コンストラクタ
	~cModeManage(){}//デストラクタ
	void ModeInit();//初期化
	void ModeUpdate();//アップデート
	void ModeDraw();//描画
	void ModeUninit();//終了
	void MODNumInit();
	void MODNumUninit();
	int GetModeFlag(){return c_ModeFlag;}
	void SetModeFlag(int nFlag){c_ModeFlag=nFlag;};
	void GameFlagSet(int nFlag){c_ModeFlag = nFlag;}
private:
	ModeFlag c_MFlag;
	int c_nPmode;
	int c_ModeFlag;//フラグ
	int c_ModeOldFlag;
	FEED c_ScreenFeed;
	GameMODE Gamemode;
	TITLEMODE Titlemode;
	RESULTMODE Reslutmode;
	int c_Score;//スコア
};

#endif MODE_END
