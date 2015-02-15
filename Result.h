
//=============================================================================
//
// 画面遷移 [Result.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef RESULT_FILE
#define RESULT_FILE

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "main.h"
#include "ResultBG.h"
#include "Polygon.h"
#include "ResultLogo.h"
#include "ModeFlag.h"
#include "score.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define STARTL ("data/TEXTURE/Start.png")
#define MOJIR_W (300)
#define MOJIR_H (40)
#define MOJIRX (350)
#define MOJIRY (500)
//*****************************************************************************
// クラス
//*****************************************************************************
class RESULTMODE
{
public:
	RESULTMODE(void){}//コンストラクタ
	~RESULTMODE(void){}//デストラクタ

HRESULT InitResult(int nScore);//リザルト初期化

void UnInitResult(void);//リザルト終了
void UpdateResult(void);//リザルトアップデート
void DrawResult(void);//リザルト描画
private:
RESLUTBGIMAGE ReslutBG;
RESULTLOGOIMAGE ResultLogo; 
ModeFlag c_Rmode;
Poly ResultButton; 
int c_nScore;
SCOREIMAGE c_Score ;
};
#endif

