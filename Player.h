//=============================================================================
//
// プレイヤー管理 [Player.cpp]
// Author : NARITADA SUZUKI
//
#ifndef PLAYER_
#define PLAYER_
//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
//マクロ定義
#define PSIZE_W (23)
#define PSIZE_H (36)
#define PSIZE_HW (15)
#define PLAYER_MAX (3)

#define PPOS_X (300)
#define PPOS_Y (500)
//=============================================================================
//クラス定義
//=============================================================================
class Player
{
public:
	Player(void);
	void PlayerUpdate();//キー判定
	void PlayerReset(float nPPosX,float nPPosY);//フラグチェック
	
	void InitPlayer(char *cTexPass,int nPwidth,int nPheight,float nPPosX,float nPPosY,float fTexX,float fTexY,int nFlag);
	void DrawPlayer();
	void UninitPlayer();
	void SetFeed(float fFeed){PlayerPolygon.SetFeed(fFeed);}

	float PoschkX();
	float PoschkY();
	void SetSpeed(float fSpeed){c_fSpeed =fSpeed; }

	void SetLFlag(int nFlag){PlayerBase.ChangeFlag(nFlag);}
	int GetLFlag(void){return PlayerBase.chkFlag();}

	void AnimSet();//アニメーションセット

private:
	cBase PlayerBase;
	Poly PlayerPolygon;
	float c_fPPosX; //座標
	float c_fPPosY;
	float c_fSpeed;
	float c_fPMoveX;//移動量
	float c_fPMoveY;
	
	int c_nPTexPattern;//テクスチャパターン
	int c_nPTexMove;//テクスチャパターンの移動量

	
};

#endif
