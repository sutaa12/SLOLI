
//=============================================================================
//
// 画面遷移 [Game.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef GAME_FILE
#define GAME_FILE

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "main.h"
#include "sound.h"
#include "GameBG.h"
#include "GameBG2.h"
#include "GameBG3.h"
#include "GameBGBACK.h"
#include "GamePose.h"
#include "Score.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "HitChk.h"
#include "Effect.h"
#include "ModeFlag.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define Speed (20)//プレイヤースピード
//*****************************************************************************
//クラス宣言
//*****************************************************************************
class GameMODE
{
public:
GameMODE(void){c_nGameFlag=INITGAME;}//コンストラクタ
~GameMODE(void){}
HRESULT InitGame(int nPflag);//ゲーム画面初期化
int UnInitGame(void);//ゲーム画面終了
void UpdateGame(void);//ゲーム画面アップデート
void DrawGame(void);//ゲーム画面描画
void GameReset(void);//ゲームデータリセット
private:
int nLCnt;
int m_nPMode;//プレイヤーモード
Player cPlayer1;
BULLETMANAGE cBullet;
ENEMYMANAGE cEnemy;
GAMEBGIMAGE GameBG;
GAMEBG0IMAGE GameBG0;
GAMEBG2IMAGE GameBG2;
GAMEBG3IMAGE GameBG3;

GAMEPOSEMenu GamePoseMenu;

SCOREIMAGE cScore;

HITCHK cHichk;

EFFECTMANAGE c_Effect;
ModeFlag c_Gmode;
int c_nGameFlag;
};
#endif

