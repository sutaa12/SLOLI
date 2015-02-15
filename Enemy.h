//=============================================================================
//
// プレイヤー管理 [Enemy.cpp]
// Author : NARITADA SUZUKI
//
#ifndef ENEMY_
#define ENEMY_
//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include"Base.h"
#include "Bullet.h"

//*****************************************************************************
//マクロ定義
#define ESIZE_W (50)
#define ESIZE_H (25)

#define ENEMY_MAX (10)
//=============================================================================
//クラス定義
//=============================================================================
class ENEMYMANAGE
{
public:
	void EnemyUpdate();//敵のあっぷでーと
	int EnemyChkFlag(int nNum);//フラグチェック
	
	void InitEnemy(char *cTexPass,int nEwidth,int nEheight,int nEPosX,int nEPosY,float fTexX,float fTexY,int nFlag);
	void DrawEnemy();
	void UninitEnemy();
	void EnemyMove();//敵の動き

	float GetEnemyX(int nNum){return EnemyBase[nNum].chkPosX();}
	float GetEnemyY(int nNum){return EnemyBase[nNum].chkPosY();}
	void SetEnemyFlag(int nNum,int nFlag){EnemyBase[nNum].ChangeFlag(nFlag);EnemyBase[nNum].SetCnt(0);}
	
	void SetEnemy(int nNum);

	int GetFLag(int nNum){return EnemyBase[nNum].chkFlag();}
	int GetBFLag(int nNum){return EnemyBase[nNum].GetBlag();}
	void AnimSet();//アニメーションセット

private:
	cBase EnemyBase[ENEMY_MAX];
	Poly EnemyPolygon;
	
	float c_fLength;
	float c_fAngle;
	D3DXVECTOR3 c_pos[ENEMY_MAX];//ポリゴンの位置
	D3DXVECTOR3 c_rot;//回転量

	int c_nPTexPattern;//テクスチャパターン
	int c_nPTexMove;//テクスチャパターンの移動量
	
};

#endif
