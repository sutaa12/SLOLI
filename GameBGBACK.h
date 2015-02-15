
//=============================================================================
//
// カーゲームα処理 [GameBG0.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef GAMEBG0_FILE
#define GAMEBG0_FILE

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define BG0 (" ")
#define SCORE ("data/TEXTURE/ScoreL.png")
#define LIFEL ("data/TEXTURE/Life.png")
#define LIFE ("data/TEXTURE/LifeM.png")
#define BG0SIZE_WH (600)
#define SCOREL_W (175)
#define SOCREL_H (50)
#define LIFE_HW (40)
#define BASE_X (780)
#define BASE_Y (250)
//*****************************************************************************
// 構造体宣言
//*****************************************************************************

//*****************************************************************************
// クラス
//*****************************************************************************
class GAMEBG0IMAGE
{
public:
void InitGameBG(void);//ポリゴン初期化で結果を返す
void UnInitGameBG(void);//ポリゴン終了処理
void UpdateGameBG(void);//ポリゴンアップデート
void DrawGameBG(int nLife);//ポリゴン描画
private:

	cBase BGBase;
	Poly BGPolygon;
	Poly BGScoreL;
	Poly BGPLifeL;
	Poly BGLife;
};


#endif

