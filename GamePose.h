
//=============================================================================
//
// カーゲームα処理 [GamePose.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef GAMEPS_FILE
#define GAMEPS_FILE

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define PS1 ("data/TEXTURE/Pose.png")
#define POSEL ("data/TEXTURE/PoseLogo.png")
#define RETURN ("data/TEXTURE/RetrunB.png")
#define TITLE ("data/TEXTURE/TitleB.png")
#define RETRY ("data/TEXTURE/RetryB.png")
#define MESSAGE ("data/TEXTURE/Message.png")

#define Base_Y (50)
#define LOGO_X (150)
#define B_X (200)
#define Message_X (200)

#define Moji_MAX (5)

#define L_W (400)
#define B_W (210)
#define B_H (40)
#define M_W (180)
#define M_H (150)
enum PO_MODE
{
	M_RETURN,M_RETRY,M_TITLE,M_PMAX
};
//*****************************************************************************
// 構造体宣言
//*****************************************************************************

//*****************************************************************************
// クラス
//*****************************************************************************
class GAMEPOSEMenu
{
public:
void InitGamePS(void);//ポリゴン初期化で結果を返す
void UnInitGamePS(void);//ポリゴン終了処理
int UpdateGamePS(void);//ポリゴンアップデート
void DrawGamePS(void);//ポリゴン描画
private:

	cBase BGBase;
	Poly BGPolygon;
	Poly m_PoseLogo;
	Poly m_Return;
	Poly m_Rery;
	Poly m_Title;
	Poly m_Message;	
	int nFlag;
};


#endif

