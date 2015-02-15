//=============================================================================
//
// 弾管理 [Bullet.cpp]
// Author : NARITADA SUZUKI
//
#ifndef BULLET_
#define BULLET_
//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include "Effect.h"
#include"Base.h"
//*****************************************************************************
//弾のモード
typedef enum
{
	NONE_B,
	PLAYER1_B,
	PLAYER2_B,
	ENEMY1_B,
	ENEMY2_B,
	MAX_B
}B_MODE;
//マクロ定義
#define BSIZE_W (6)
#define BSIZE_H (6)
#define BSIZE_WH (20)
#define BULLET_MAX (100)
#define BULLET_SPEED (6)
#define BULLET_EFFECTTIME (10)
#define BULLETIMG ("data/TEXTURE/effect000.jpg")
//=============================================================================
//クラス定義
//=============================================================================
class BULLETMANAGE
{
public:
	void BulletUpdate(float fPosX,float fPosY);//キー判定

	void InitBullet(char *cTexPass,int nPwidth,int nPheight,int nBPosX,int nBPosY,float fTexX,float fTexY,int nFlag);
	void DrawBullet();
	void UninitBullet();

	float GetBulletX(int nNum){return BulletBase[nNum].chkPosX();}
	float GetBulletY(int nNum){return BulletBase[nNum].chkPosY();}
	void SetBulletFlag(int nNum,int nFlag){BulletBase[nNum].ChangeFlag(nFlag);}


	void SetBullet(float fPosX,float fPosY,int nMode);
	int BulletFlagChk(int nNum);
	void AnimSet();//アニメーションセット

private:
	cBase BulletBase[BULLET_MAX];
	Poly BulletPolygon;
};


#endif