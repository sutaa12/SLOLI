
//=============================================================================
//
// カーゲームα処理 [TitleLogo.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef TITLELOGO_FILE
#define TITLELOGO_FILE

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "main.h"
#include "Polygon.h"
#include "Base.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TITLE_X (320)
#define TITLE_Y (50)
#define TITLE_W (350)
#define TITLE_H (100)

#define TLOGO1 ("data/TEXTURE/TitleLogo.png")
#define TLOGO2 ("../data/TEXTURE/TitleLogo.png")
//*****************************************************************************
// 構造体宣言
//*****************************************************************************

//*****************************************************************************
//クラス宣言
//*****************************************************************************
class TITLELOGOIMAGE
{
public:
void InitTitleLogo(void);//ポリゴン初期化で結果を返す
void UnInitTitleLogo(void);//ポリゴン終了処理
void UpdateTitleLogo(void);//ポリゴンアップデート
void DrawTitleLogo(void);//ポリゴン描画
private:
	cBase c_LogoBase;
	Poly c_LogoPolygon;

};

#endif

