//=============================================================================
//
// ポリゴン管理 [polygon.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
//マクロ定義
#define FeedSpeed (0.08)

//*****************************************************************************
//メイン関数
//*****************************************************************************
	Poly::Poly()//コンストラクタ
	{
		//値初期化
		this->c_pD3DTexPolygon=NULL;
		this->c_pD3DVtxBuffPolygon=NULL;
		this->c_nHeight=0;
		this->c_nWidth=0;

		this->c_nPosX=0;
		this->c_nPosY=0;

		this->c_fTexU=0;
		this->c_fTexV=0;
		this->c_fTexPatternU=1;
		this->c_fTexPatternV=1;

		this->c_fFeed=1;

		this->c_fColR=1;
		this->c_fColG=1;
		this->c_fColB=1;
		this->c_nPolyNum=0;//ポリゴンの数

		this->c_fFeedSpeed=FeedSpeed;
	}
//*****************************************************************************
	Poly::~Poly()//デストラクタ
	{
					if(c_pD3DTexPolygon!=NULL)
	{
		c_pD3DTexPolygon->Release();//初期化
		c_pD3DTexPolygon=NULL;
	}
			if(c_pD3DVtxBuffPolygon!=NULL)//空でないなら
			{
				c_pD3DVtxBuffPolygon->Release();
				c_pD3DVtxBuffPolygon=NULL;//アドレスを空に
			}

	}
//*****************************************************************************
	HRESULT Poly::InitPolygon(char *cTexPass,int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM)//ポリゴン初期化
	{
		this->c_nPolyNum=nNUM;
			if(FAILED(	GetDevice()->CreateVertexBuffer(	//頂点バッファ作成
				sizeof(VERTEX_2D)*4*c_nPolyNum,
				D3DUSAGE_WRITEONLY,
				FVF_VERTEX_2D,
				D3DPOOL_MANAGED,
				&c_pD3DVtxBuffPolygon,
				NULL)))
			{
		return E_FAIL;//読み込めなかったらエラー
			}

//座標と画像サイズ初期化
	this->c_nWidth=nPwidth;
	this->c_nHeight=nPheight;
	this->c_nPosX=nPPosX;
	this->c_nPosY=nPPosY;
//古い座標も用意
	this->c_noldWidth=nPwidth;
	this->c_noldHeight=nPheight;
	this->c_noldPosX=nPPosX;
	this->c_noldPosY=nPPosY;


	VERTEX_2D *c_pvtxPolygon;//頂点を入れる変数

	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//頂点の位置をロック
	for(int nLoop=0;nLoop<c_nPolyNum;nLoop++)
	{
				//頂点情報の初期化
	c_pvtxPolygon[0].vtx = D3DXVECTOR3(c_nPosX,c_nPosY,0.0f);//頂点の座標格納
	c_pvtxPolygon[1].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY,0.0f);//頂点の座標格納
	c_pvtxPolygon[2].vtx = D3DXVECTOR3(c_nPosX,c_nPosY+c_nHeight,0.0f);//頂点の座標格納
	c_pvtxPolygon[3].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY+c_nHeight,0.0f);//頂点の座標格納

	c_pvtxPolygon[0].rhw = 1.0f;//固定
	c_pvtxPolygon[1].rhw = 1.0f;//固定
	c_pvtxPolygon[2].rhw = 1.0f;//固定
	c_pvtxPolygon[3].rhw = 1.0f;//固定

	c_pvtxPolygon[0].diffurse = D3DCOLOR_RGBA(255,255,255,255); //色設定
	c_pvtxPolygon[1].diffurse = D3DCOLOR_RGBA(255,255,255,255); //色設定
	c_pvtxPolygon[2].diffurse = D3DCOLOR_RGBA(255,255,255,255); //色設定
	c_pvtxPolygon[3].diffurse = D3DCOLOR_RGBA(255,255,255,255); //色設定

	c_pvtxPolygon[0].tex = D3DXVECTOR2(0.0f,0.0f);
	c_pvtxPolygon[1].tex = D3DXVECTOR2(1.0f,0.0f);
	c_pvtxPolygon[2].tex = D3DXVECTOR2(0.0f,1.0f);
	c_pvtxPolygon[3].tex = D3DXVECTOR2(1.0f,1.0f);
	c_pvtxPolygon+=4;
	}
	c_pD3DVtxBuffPolygon->Unlock();//ロックの解除を忘れずに

	//テクスチャの読み込み

	D3DXCreateTextureFromFile(GetDevice(),
								cTexPass,
								&c_pD3DTexPolygon);
	return S_OK;

	}
//*****************************************************************************
	void Poly::UninitPolygon()//ポリゴン終了
	{
			if(c_pD3DTexPolygon!=NULL)
	{
		c_pD3DTexPolygon->Release();//初期化
		c_pD3DTexPolygon=NULL;
	}
			if(c_pD3DVtxBuffPolygon!=NULL)//空でないなら
			{
				c_pD3DVtxBuffPolygon->Release();
				c_pD3DVtxBuffPolygon=NULL;//アドレスを空に
			}
	}
//*****************************************************************************
	void Poly::UpdatePolygon(int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM)//アップデート
	{

//座標と画像サイズ初期化
	this->c_nWidth=nPwidth;
	this->c_nHeight=nPheight;
	this->c_nPosX=nPPosX;
	this->c_nPosY=nPPosY;

	VERTEX_2D *c_pvtxPolygon;//頂点を入れる変数
	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//頂点の位置をロック
	c_pvtxPolygon=c_pvtxPolygon+(nNUM*4);
//頂点情報の更新
	c_pvtxPolygon[0].vtx = D3DXVECTOR3(c_nPosX,c_nPosY,0.0f);//頂点の座標格納
	c_pvtxPolygon[1].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY,0.0f);//頂点の座標格納
	c_pvtxPolygon[2].vtx = D3DXVECTOR3(c_nPosX,c_nPosY+c_nHeight,0.0f);//頂点の座標格納
	c_pvtxPolygon[3].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY+c_nHeight,0.0f);//頂点の座標格納
//テクスチャの更新
	c_pvtxPolygon[0].tex = D3DXVECTOR2(c_fTexU,c_fTexV);
	c_pvtxPolygon[1].tex = D3DXVECTOR2(c_fTexU+(c_fTexPatternU),c_fTexV);
	c_pvtxPolygon[2].tex = D3DXVECTOR2(c_fTexU,c_fTexV+(c_fTexPatternV));
	c_pvtxPolygon[3].tex = D3DXVECTOR2(c_fTexU+(c_fTexPatternU),c_fTexV+(c_fTexPatternV));

	c_pvtxPolygon[0].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定
	c_pvtxPolygon[1].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定
	c_pvtxPolygon[2].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定
	c_pvtxPolygon[3].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定

	c_pD3DVtxBuffPolygon->Unlock();//ロックの解除を忘れずに
	}
//*****************************************************************************
	void Poly::DrawPolygon(int nNum)//描画
	{
			//ポリゴン表示

	GetDevice()->SetStreamSource(0,c_pD3DVtxBuffPolygon,0,sizeof(VERTEX_2D));//ポリゴンセット(2枚目のBG)

	GetDevice()->SetFVF(FVF_VERTEX_2D); //頂点フォーマットの設定

	GetDevice()->SetTexture(0,c_pD3DTexPolygon);//テクスチャセット

	GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//ポリゴンの設定
									nNum*4,
									2);//個数
	}
//*****************************************************************************
void Poly::PolygonFeedIN()
{
	if(c_fFeedSpeed<=0)//０以下なら
	{
	c_fFeedSpeed*=-1;
	}
	c_fFeed+=c_fFeedSpeed;
}

void Poly::PolygonFeedOUT()
{
		if(c_fFeedSpeed>=0)//０以下なら
	{
	c_fFeedSpeed*=-1;
	}
	c_fFeed+=c_fFeedSpeed;
}

void Poly::PolygonFeed()
{
	if(c_fFeed>0&&c_fFeed<=1)//フェードが０以上なら
	{
	c_fFeed+=c_fFeedSpeed;//フェード加算
	}
		VERTEX_2D *c_pvtxPolygon;//頂点を入れる変数
	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//頂点の位置をロック
				//頂点情報の初期化
	c_pvtxPolygon[0].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定
	c_pvtxPolygon[1].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定
	c_pvtxPolygon[2].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定
	c_pvtxPolygon[3].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //色設定
	
	c_pD3DVtxBuffPolygon->Unlock();//ロックの解除を忘れずに
}
float Poly::Feedchk()
{
	return c_fFeed;
}

void Poly::SetTexUV(float fTexU,float fTexV,float fTexPU,float fTexPV)//描画
{
	//テクスチャ座標セット
	c_fTexU=fTexU;
	c_fTexV=fTexV;
	//パターンセット
	c_fTexPatternU=fTexPU;
	c_fTexPatternV=fTexPV;
}

void Poly::UpdatePolygonROTE(float nPosX1,float nPosY1,float nPosX2,float nPosY2,float nPosX3,float nPosY3,float nPosX4,float nPosY4,int nNUM)
{
		VERTEX_2D *c_pvtxPolygon;//頂点を入れる変数
	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//頂点の位置をロック
	c_pvtxPolygon=c_pvtxPolygon+(nNUM*4);
//頂点情報の更新
	c_pvtxPolygon[0].vtx = D3DXVECTOR3(nPosX1,nPosY1,0.0f);//頂点の座標格納
	c_pvtxPolygon[1].vtx = D3DXVECTOR3(nPosX2,nPosY2,0.0f);//頂点の座標格納
	c_pvtxPolygon[2].vtx = D3DXVECTOR3(nPosX3,nPosY3,0.0f);//頂点の座標格納
	c_pvtxPolygon[3].vtx = D3DXVECTOR3(nPosX4,nPosY4,0.0f);//頂点の座標格納

	c_pD3DVtxBuffPolygon->Unlock();//ロックの解除を忘れずに
}

void Poly::SetFeed(float ffeed)
{
	this->c_fFeed=ffeed;
}

void Poly::SetColor(float fRed,float fGre,float fBlu)
{
	this->c_fColR=fRed;
	this->c_fColG=fGre;
	this->c_fColB=fBlu;

}