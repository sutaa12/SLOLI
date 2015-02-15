//=============================================================================
//
// カーゲーム完成 [main.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルード
//*****************************************************************************
#include <time.h>
#include "main.h"
#include "ModeManage.h"
#include"sound.h"
//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define CLASS_NAME		"AppClass"			// ウインドウのクラス名
#define WINDOW_NAME		"テクスチャアニメーション"		// ウインドウのキャプション名


//*****************************************************************************
// 構造体定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);//ウィンドウプロシージャコールパック
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);//ウィンドウ初期化
void Uninit(void);//初期化
void Update(void);//アップデート
void Draw(void);//描画
void DrawFPS(void);
//アクセサ関数

//*****************************************************************************
// グローバル変数:
//*****************************************************************************
LPDIRECT3D9			g_pD3D = NULL;			// Direct3Dオブジェクト
LPDIRECT3DDEVICE9	g_pD3DDevice = NULL;	// Deviceオブジェクト(描画に必要)
cModeManage c_Mode;

#ifdef _DEBUG
int						g_nCountFPS = 0;			// FPSカウンタ
LPD3DXFONT				g_pD3DXFont=NULL;			//FPSのフォント
#endif

//=============================================================================
// メイン関数
//=============================================================================

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);	// 無くても良いけど、警告が出る（未使用宣言）
	UNREFERENCED_PARAMETER(lpCmdLine);		// 無くても良いけど、警告が出る（未使用宣言）

	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;

	WNDCLASSEX	wcex = {
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		NULL
	};
	HWND hWnd;
	MSG msg;
	
	// ウィンドウクラスの登録
	RegisterClassEx(&wcex);

	// ウィンドウの作成
	hWnd = CreateWindowEx(0,
						CLASS_NAME,
						WINDOW_NAME,
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						SCREEN_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,
						SCREEN_HEIGHT + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),
						NULL,
						NULL,
						hInstance,
						NULL);

	// 初期化処理(ウィンドウを作成してから行う)
		if(FAILED(Init(hInstance,hWnd,TRUE)))
	{
		return E_FAIL;
	}

	// フレームカウント初期化
	timeBeginPeriod(1);					// 分解能を設定
	dwExecLastTime = 
	dwFPSLastTime = timeGetTime();		// システム時刻をミリ秒単位で取得
	dwCurrentTime =
	dwFrameCount = 0;

	// ウインドウの表示(初期化処理の後に行う)
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	
	// メッセージループ
	while(1)
	{
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
			{// PostQuitMessage()が呼ばれたらループ終了
				break;
			}
			else
			{
				// メッセージの翻訳と送出
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
        }
		else
		{
			dwCurrentTime = timeGetTime();		// システム時刻を取得

			if((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5秒ごとに実行
			{
#ifdef _DEBUG
				g_nCountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);		// FPSを測定
#endif
			    
				dwFPSLastTime = dwCurrentTime;		// FPSを測定した時刻を保存
				dwFrameCount = 0;					// カウントをクリア
			}

			if((dwCurrentTime - dwExecLastTime) >= (1000 / 60))		// 1/60秒ごとに実行
			{
				dwExecLastTime = dwCurrentTime;		// 処理した時刻を保存

				// 更新処理
				Update();
				
				// 描画処理
				Draw();


				dwFrameCount++;			// カウントを加算
			}
		}
	}

	// ウィンドウクラスの登録を解除
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	// 終了処理
	Uninit();

	timeEndPeriod(1);				// 分解能を戻す

	return (int)msg.wParam;
}

//=============================================================================
// プロシージャ
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	D3DPRESENT_PARAMETERS d3dpp;
    D3DDISPLAYMODE d3ddm;

	// Direct3Dオブジェクトの作成
	g_pD3D = Direct3DCreate9( D3D_SDK_VERSION );
	if( g_pD3D == NULL )
	{
		return E_FAIL;
	}

	// 現在のディスプレイモードを取得
    if(FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	// デバイスのプレゼンテーションパラメータの設定
	ZeroMemory( &d3dpp, sizeof(d3dpp) );						// ワークをゼロクリア
	d3dpp.BackBufferCount			= 1;
	d3dpp.BackBufferWidth			= SCREEN_WIDTH;				// ゲーム画面サイズ(幅)
	d3dpp.BackBufferHeight			= SCREEN_HEIGHT;			// ゲーム画面サイズ(高さ)
	d3dpp.BackBufferFormat			= D3DFMT_UNKNOWN;			// バックバッファのフォーマットは現在設定されているものを使う
	d3dpp.SwapEffect				= D3DSWAPEFFECT_DISCARD;	// 映像信号に同期してフリップする
	d3dpp.Windowed					= bWindow;					// ウィンドウモード
	d3dpp.EnableAutoDepthStencil	= TRUE;						// デプスバッファ（Ｚバッファ）とステンシルバッファを作成
	d3dpp.AutoDepthStencilFormat	= D3DFMT_D16;				// デプスバッファとして16bitを使う

	if(bWindow)
	{// ウィンドウモード
		d3dpp.BackBufferFormat           = D3DFMT_UNKNOWN;					// バックバッファ
		d3dpp.FullScreen_RefreshRateInHz = 0;								// リフレッシュレート
		d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;	// インターバル
	}
	else
	{// フルスクリーンモード
		d3dpp.BackBufferFormat           = D3DFMT_R5G6B5;					// バックバッファ
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;			// リフレッシュレート
		d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_DEFAULT;		// インターバル
	}

	// デバイスの生成
	// ディスプレイアダプタを表すためのデバイスを作成
	// 描画と頂点処理をハードウェアで行なう
	if(FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, 
									D3DDEVTYPE_HAL, 
									hWnd, 
									D3DCREATE_HARDWARE_VERTEXPROCESSING, 
									&d3dpp, &g_pD3DDevice)))
	{
		// 上記の設定が失敗したら
		// 描画をハードウェアで行い、頂点処理はCPUで行なう
		if(FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, 
										D3DDEVTYPE_HAL, 
										hWnd, 
										D3DCREATE_SOFTWARE_VERTEXPROCESSING, 
										&d3dpp, &g_pD3DDevice)))
		{
			// 上記の設定が失敗したら
			// 描画と頂点処理をCPUで行なう
			if(FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, 
											D3DDEVTYPE_REF,
											hWnd, 
											D3DCREATE_SOFTWARE_VERTEXPROCESSING, 
											&d3dpp, &g_pD3DDevice)))
			{
				// 初期化失敗
				return E_FAIL;
			}
		}
	}
	InitKeyboard(hInstance,hWnd);
#ifdef _DEBUG
	//フォント生成
	D3DXCreateFont(g_pD3DDevice,18,0,0,0,FALSE,SHIFTJIS_CHARSET,OUT_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Terminal",&g_pD3DXFont);
#endif
		//(レンダーステートパラメータの設定)
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_CCW);//裏面のポリゴンを描画しない
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE,TRUE);//Zバッファ利用
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,TRUE);//アルファプレンドする
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);//アルファブレンドの設定
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
		//(サンプラステートの設定)
	g_pD3DDevice->SetSamplerState(0,D3DSAMP_ADDRESSU,D3DTADDRESS_WRAP);
	g_pD3DDevice->SetSamplerState(0,D3DSAMP_ADDRESSV,D3DTADDRESS_WRAP);
	g_pD3DDevice->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);
		//(テクスチャステージステートの設定)
	g_pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG2,D3DTA_CURRENT);
	InitSound(hWnd);
	
	srand((unsigned int)time(NULL));//乱数準備
	c_Mode.ModeInit();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void Uninit(void)
{
#ifdef _DEBUG
	if(g_pD3DXFont!=NULL)
	{
		g_pD3DXFont->Release();
		g_pD3DXFont=NULL;
	}
#endif
		if(g_pD3D!=NULL)
	{
		g_pD3D->Release();//初期化
		g_pD3D=NULL;
	}
		if(g_pD3DDevice!=NULL)
	{
		g_pD3DDevice->Release();//初期化
		g_pD3DDevice=NULL;
	}
		c_Mode.ModeUninit();
		UninitKeyboard();
	UninitSound();


		//その他オブジェクトの解放も行う

}
//=============================================================================
// 更新処理
//=============================================================================
void Update(void)
{
			UpdateKeyboard();
			c_Mode.ModeUpdate();
}

//=============================================================================
// 描画処理
//=============================================================================
void Draw(void)
{
		g_pD3DDevice->Clear(0,NULL,(D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0,0,0,0),		//背景色指定
						1.0f,0);	//画面のクリア
	if(SUCCEEDED(g_pD3DDevice->BeginScene()))
	{

		//さまざまなオブジェクトの描画を行う
		c_Mode.ModeDraw();

		
#ifdef _DEBUG
		DrawFPS();
#endif
		g_pD3DDevice->EndScene();//描画終了
	}
	g_pD3DDevice->Present(NULL,NULL,NULL,NULL);

}

//=============================================================================
// デバイスの取得
//=============================================================================
LPDIRECT3DDEVICE9 GetDevice(void)
{
	return g_pD3DDevice;
}

#ifdef _DEBUG
//=============================================================================
// FPS表示処理
//=============================================================================
void DrawFPS(void)
{
	RECT rect={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
	char aStr[256];
	wsprintf(&aStr[0],"FPS:%d\n",g_nCountFPS);
	g_pD3DXFont->DrawText(NULL,&aStr[0],-1,&rect,DT_LEFT,D3DCOLOR_RGBA(255,255,255,255));
}
#endif

