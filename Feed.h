//=============================================================================
//
// フェード管理 [feed.h]
// Author : NARITADA SUZUKI
//
#ifndef FEED_
#define FEED_
//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
#define FEEDIN (1)//フェードフラグ
#define FEEDOUT (2)
#define CHARA1 ("data/TEXTURE/SLECT_C1.png")
#define CHARA2 ("data/TEXTURE/SLECT_C2.png")
#define C_X (300)
#define Chara_WH (600)
//=============================================================================
//クラス定義
//=============================================================================
class FEED
{
public:
	FEED(void);
	void FeedSet(int FeedFlag);//フェードスタート
	void FeedUpdate();//フラグチェック
	float FeedChk();//フェード値返す

	void InitFeed(char *cTexPass,int nPwidth,int nPheight,int nPPosX,int nPPosY,float fTexX,float fTexY,int nFlag);
	void DrawFeed();
	void UninitFeed();

private:
	cBase FeedBase;
	Poly FeedPolygon;
	Poly Feedchara1;
	Poly Feedchara2;
};

#endif
