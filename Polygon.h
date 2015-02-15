//=============================================================================
//
// ポリゴン管理 [polygon.h]
// Author : NARITADA SUZUKI
//
#ifndef _POLYGON_
#define _POLYGON_ 
//=============================================================================
// インクルード
//*****************************************************************************
#include "main.h"
//*****************************************************************************
// クラス
//*****************************************************************************
class Poly
{
public:
	Poly();//コンストラクタ
	~Poly();//デストラクタ
	
	HRESULT InitPolygon(char *cTexPass,int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM);//ポリゴン初期化
	
	void UninitPolygon();//ポリゴン終了
	void UpdatePolygon(int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM);//アップデート
	void UpdatePolygonROTE(float nPosX1,float nPosY1,float nPosX2,float nPosY2,float nPosX3,float nPosY3,float nPosX4,float nPosY4,int nNUM);//アップデート(回転)
	void PolygonFeed();//ポリゴンのフェード処理
	void DrawPolygon(int nNum);//描画
	void PolygonFeedIN();
	void PolygonFeedOUT();
	float Feedchk();
	void SetFeed(float ffeed);
	void SetColor(float fRed,float fGre,float fBlu);

	void SetTexUV(float fTexU,float fTexV,float fTexPU,float fTexPV);//テクスチャのUVセット

private:
	LPDIRECT3DTEXTURE9 c_pD3DTexPolygon;//テクスチャ格納変数
	LPDIRECT3DVERTEXBUFFER9 c_pD3DVtxBuffPolygon;//頂点バッファ

	int c_nPolyNum;//表示する数
	
	int c_nWidth;//横幅
	int c_nHeight;//高さ

	int c_noldWidth;//横幅
	int c_noldHeight;//高さ
	
	int c_nPosX;//座標X
	int c_nPosY;//座標Y

	int c_noldPosX;//座標X
	int c_noldPosY;//座標Y

	float c_fTexU;//テクスチャ座標
	float c_fTexV;
	float c_fTexPatternU;//テクスチャパターン
	float c_fTexPatternV;//テクスチャパターン

	float c_fFeedSpeed;//フェードのはやさ
	float c_fFeed;//フェード値

	float c_fColR;//赤の値
	float c_fColG;//緑の値
	float c_fColB;//黄色の値

};

#endif