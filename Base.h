//=============================================================================
//
// 座標ベース管理 [base.h]
// Author : NARITADA SUZUKI
//
#ifndef FILE_BASE
#define FILE_BASE
//=============================================================================
//インクルード
//*****************************************************************************
#include "main.h"
//*****************************************************************************
//=============================================================================
//クラス定義
//=============================================================================
class cBase
{
public:
	//コンストラクタ
	cBase(float fPosX,float fPosY,float fTexX,float fTexY,int nWitdh,int Height,int nFlag);
	cBase();
	//初期化
	void InitBase(float fPosX,float fPosY,float fTexX,float fTexY,int nWitdh,int Height,int nFlag);
	//座標を返す,
	float chkPosX(void);
	float chkPosY(void);

	float chkTexX(void);
	float chkTexY(void);

	//フェード値を返す
	float GetFeed(void);

	//フェード値変更
	void SetFeed(float fFeedO);

	//座標変更
	void ChangePos(float fPosX,float fPosY);
	void ChangeTex(float fTexX,float fTexY);

	//サイズを返す
	int chkWitdth(void);
	int chkHeight(void);

	//サイズ変更
	void ChangeSize(int nWitdh,int nHeight);
	
	//カウント変更チェック

	void SetCnt(int nCount);
	int GetCnt(void);

	//フラグを返す
	int chkFlag(void);
	int GetBlag(void){return c_nBFlag;}

	//フラグ変更
	void ChangeFlag(int nFlag);
	void SetBFlag(int nBFlag){c_nBFlag=nBFlag;};//弾フラグ
	
	void SetMoveX(float fMovex){	c_fMovex=fMovex;}
	void SetMoveY(float fMovey){	c_fMovey=fMovey;}

	float GetMoveX(void){return c_fMovex;}
	float GetMoveY(void){return c_fMovey;}

	void SetCol(float fR,float fG,float fB){c_fRed=fR;c_fGre=fG;c_fBlu=fB;}
	float GetColR(void){return c_fRed;}
	float GetColG(void){return c_fGre;}
	float GetColB(void){return c_fBlu;}

private:
	//座標
	float c_fPosX;
	float c_fPosY;
	float c_foldPosX;
	float c_foldPosY;
	float c_fMovex;
	float c_fMovey;
	//テクスチャ座標
	float c_fTexX;
	float c_fTexY;
	//画像サイズ
	int c_nWitdh;
	int c_nHeight;
	
	//フェード値
	float c_fFeed;
	//RGB
	float c_fRed;
	float c_fGre;
	float c_fBlu;
	//時間
	int c_nCnt;

	//フラグ
	int c_nLFlag;
	int c_nBFlag;
};

#endif