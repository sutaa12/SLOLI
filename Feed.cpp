//=============================================================================
//
// プレイヤー管理 [Feed.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Feed.h"
#include"Base.h"
#include"Polygon.h"
//=============================================================================
//マクロ定義
//*****************************************************************************
#define OFF (0)
#define ON (1)
enum KEYINPUT
{
	NONE,
	LEFT,
	RIGHT
};
#define Speed (1.0)
//*****************************************************************************
FEED::FEED(void)
{

}

void FEED::FeedSet(int FeedFlag)
{
	if(FeedFlag==FEEDIN)
	{
	this->FeedPolygon.PolygonFeedIN();
	this->Feedchara1.PolygonFeedIN();
	this->Feedchara2.PolygonFeedIN();

	}else
		if(FeedFlag==FEEDOUT)
		{
			this->FeedPolygon.PolygonFeedOUT();
			this->Feedchara1.PolygonFeedOUT();
			this->Feedchara2.PolygonFeedOUT();
		}
}

void FEED::FeedUpdate()
{
	this->FeedPolygon.PolygonFeed();
	this->Feedchara1.PolygonFeed();
	this->Feedchara2.PolygonFeed();

}

void FEED::InitFeed(char *cTexPass,int nPwidth,int nPheight,int nPPosX,int nPPosY,float fTexX,float fTexY,int nFlag)
{
	this->FeedPolygon.SetFeed(0);
	this->Feedchara1.SetFeed(0);
	this->Feedchara2.SetFeed(0);
	
	this->FeedBase.InitBase(nPPosX,nPPosY,fTexX,fTexY,nPwidth,nPheight,nFlag);
	this->FeedPolygon.InitPolygon(cTexPass,nPwidth,nPheight,nPPosX,nPPosY,1);
	this->Feedchara1.InitPolygon(CHARA1,Chara_WH,Chara_WH,nPPosX,nPPosY,1);
	this->Feedchara2.InitPolygon(CHARA2,Chara_WH,Chara_WH,C_X,nPPosY,1);

}

void FEED::DrawFeed()
{
	this->FeedPolygon.DrawPolygon(0);
	this->Feedchara1.DrawPolygon(0);
	this->Feedchara2.DrawPolygon(0);
}
void FEED::UninitFeed()
{
	this->FeedPolygon.UninitPolygon();
	this->Feedchara1.UninitPolygon();
	this->Feedchara2.UninitPolygon();
}

float FEED::FeedChk()
{
	return this->FeedPolygon.Feedchk();
}

