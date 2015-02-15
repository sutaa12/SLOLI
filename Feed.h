//=============================================================================
//
// �t�F�[�h�Ǘ� [feed.h]
// Author : NARITADA SUZUKI
//
#ifndef FEED_
#define FEED_
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include"Base.h"
//*****************************************************************************
#define FEEDIN (1)//�t�F�[�h�t���O
#define FEEDOUT (2)
#define CHARA1 ("data/TEXTURE/SLECT_C1.png")
#define CHARA2 ("data/TEXTURE/SLECT_C2.png")
#define C_X (300)
#define Chara_WH (600)
//=============================================================================
//�N���X��`
//=============================================================================
class FEED
{
public:
	FEED(void);
	void FeedSet(int FeedFlag);//�t�F�[�h�X�^�[�g
	void FeedUpdate();//�t���O�`�F�b�N
	float FeedChk();//�t�F�[�h�l�Ԃ�

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
