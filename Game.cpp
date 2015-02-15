//=============================================================================
//
// 画面遷移 [Game.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "Game.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define P1 ("data/TEXTURE/P_Wait.png")
#define P2 ("data/TEXTURE/P2_Wait.png")
#define E1 ("data/TEXTURE/Enemy1.png")
#define P_E1 (20)
#define E_E1 (20)
//=============================================================================
// 初期化関数
//=============================================================================
HRESULT GameMODE::InitGame(int nPflag)//ゲーム画面初期化で結果を返す
{
	nLCnt=0;
	//敵プレイヤー初期化
	m_nPMode = nPflag;
	if(m_nPMode==CHARA2_MODE)
	{
	cPlayer1.InitPlayer(P1,PSIZE_W,PSIZE_H,PPOS_X,PPOS_Y,1.0,1.0,PLAYER_MAX);
	}else{
	cPlayer1.InitPlayer(P2,PSIZE_W,PSIZE_H,PPOS_X,PPOS_Y,1.0,1.0,PLAYER_MAX);
	}
	cBullet.InitBullet(BULLETIMG,BSIZE_W,BSIZE_H,0,0,1,1,0);
	cEnemy.InitEnemy(E1,ESIZE_W,ESIZE_H,PPOS_X,PPOS_Y,1.0,1.0,0);
	//ポリゴン初期化
	GameBG.InitGameBG();//ＢＧ初期化
	GameBG0.InitGameBG();
	GameBG2.InitGameBG2();
	GameBG3.InitGameBG3();
	GamePoseMenu.InitGamePS();
	cScore.InitScore();//スコア初期化
	c_Effect.EffectInit(BULLETIMG);//エフェクトロード
	c_nGameFlag=MAINGAME;//ゲームの流れセット
	PlaySound(SOUND_LABEL_BGM001);
	return S_OK;
}
//=============================================================================
// 終了処理関数
//=============================================================================
int GameMODE::UnInitGame(void)//ゲーム画面終了処理
{
	int nScore=cScore.GetSCore();
	cPlayer1.UninitPlayer();
	cBullet.UninitBullet();
	cEnemy.UninitEnemy();
	GameBG.UnInitGameBG();
	GameBG0.UnInitGameBG();
	GameBG2.UnInitGameBG2();
	GameBG3.UnInitGameBG3();
	GamePoseMenu.UnInitGamePS();
	cScore.UnInitScore();
	c_Effect.EffectUninit();
	c_nGameFlag=INITGAME;
	StopSound();
	return nScore;
}
//=============================================================================
// アップデート関数
//=============================================================================
void GameMODE::UpdateGame(void)//ゲーム画面アップデート
{
	//ポーズチェック
	if(cPlayer1.GetLFlag()<=0)
	{
		c_Gmode.SetFlag(MODE_RESLUT);	
	}
		if(c_nGameFlag==INITGAME)
	{
		UnInitGame();
		InitGame(m_nPMode);
	}else
	if(c_nGameFlag==GAMETITLE)
	{
		c_Gmode.SetFlag(MODE_TITLE);	
	}else
	if(c_nGameFlag==POSEGAME)//ポーズモード
	{
		c_nGameFlag=GamePoseMenu.UpdateGamePS();

	}else{//ゲームモード
		cPlayer1.SetSpeed(Speed);
		if(GetKeyboardTrigger(DIK_P))//Pでポーズ切り替え
	{
		if(c_nGameFlag==MAINGAME)
		{
		c_nGameFlag=POSEGAME;
		}
	}
				cPlayer1.SetFeed(1);
		if(GetKeyboardTrigger(DIK_F5))
		{
			cPlayer1.PlayerReset(PPOS_X,PPOS_Y);//プレイヤーリセット
		}else
		if(GetKeyboardTrigger(DIK_SPACE)==TRUE&&cPlayer1.GetLFlag()!=0)
		{
			if(m_nPMode==CHARA2_MODE)
			{
 			cBullet.SetBullet(cPlayer1.PoschkX(),cPlayer1.PoschkY(),PLAYER1_B);//弾セット
			}else{
			cBullet.SetBullet(cPlayer1.PoschkX(),cPlayer1.PoschkY(),PLAYER2_B);//弾セット
			}
		}else
		if(GetKeyboardPress(DIK_LSHIFT)==TRUE&&cPlayer1.GetLFlag()!=0)//あたり判定チェック
		{
			cPlayer1.SetSpeed(Speed*0.7f);
 			c_Effect.EffectSet(cPlayer1.PoschkX()+(PSIZE_W/2)-(PSIZE_HW/2),cPlayer1.PoschkY()+(PSIZE_H/2)-(PSIZE_HW/2),PSIZE_HW,PSIZE_HW,P_E1,1.0f,0.2f,0.2f,E_P1_B);
			cPlayer1.SetFeed(0.4);
		}


		for(int nLoopE=0;nLoopE<ENEMY_MAX;nLoopE++)//敵チェック
		{
			if(cEnemy.GetBFLag(nLoopE)!=0&&cEnemy.GetFLag(nLoopE)!=0)//敵の弾セット
			{
				cBullet.SetBullet(cEnemy.GetEnemyX(nLoopE),cEnemy.GetEnemyY(nLoopE),ENEMY1_B);
			}

		}

		for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)//弾チェック
		{
			for(int nLoop2=0;nLoop2<ENEMY_MAX;nLoop2++)//敵とチェック
			{
				if(cBullet.BulletFlagChk(nLoop)==PLAYER1_B)
				{
					c_Effect.EffectSet(cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),EFFECT_SIZE1,EFFECT_SIZE1,P_E1,0.5f,1.0f,0.0f,E_P1_B);//プレイヤー弾
					if(cEnemy.EnemyChkFlag(nLoop2)==1)
					{
					if(cHichk.HitChk(	cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),BSIZE_W,BSIZE_H,
										cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),ESIZE_W,ESIZE_H,QUATOQUA)==1)
					{
						c_Effect.EffectSet(cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),EFFECT_EXPLO,EFFECT_EXPLO,P_E1,1.0f,0.5f,0.5f,E_Ex);//爆発
						cBullet.SetBulletFlag(nLoop,0);
						cEnemy.SetEnemyFlag(nLoop2,NONE_B);
						cScore.AddScore(10);
						PlaySound(SOUND_LABEL_SE_EXPLOSION);
					}
					}
				}else
				if(cBullet.BulletFlagChk(nLoop)==PLAYER2_B)
				{
					c_Effect.EffectSet(cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),EFFECT_SIZE1,EFFECT_SIZE1,P_E1,0.5f,1.0f,0.0f,E_P2_B);//プレイヤー弾
					if(cEnemy.EnemyChkFlag(nLoop2)==1)
					{
					if(cHichk.HitChk(	cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),BSIZE_W*2,BSIZE_H*2,
										cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),ESIZE_W,ESIZE_H,QUATOQUA)==1)
					{
						c_Effect.EffectSet(cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),EFFECT_EXPLO,EFFECT_EXPLO,P_E1,1.0f,0.5f,0.5f,E_Ex);//爆発
						cEnemy.SetEnemyFlag(nLoop2,NONE_B);
						PlaySound(SOUND_LABEL_SE_EXPLOSION);
						cScore.AddScore(10);
					}
					}	
				}else//if
					if(cBullet.BulletFlagChk(nLoop)==ENEMY1_B)
					{
					c_Effect.EffectSet(cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),EFFECT_SIZE2,EFFECT_SIZE2,E_E1,0.2f,0.1f,0.2f,E_E1_B);//敵弾
						if(cHichk.HitChk(	cBullet.GetBulletX(nLoop)+(BSIZE_W/2),cBullet.GetBulletY(nLoop)+(BSIZE_H/2),BSIZE_W,BSIZE_H,
						cPlayer1.PoschkX()+(PSIZE_W/2),cPlayer1.PoschkY()+(PSIZE_H/2),PSIZE_HW/2,PSIZE_HW/2,CIRTOCIR)==1)
						{
							if(nLCnt==0)
							{
							cPlayer1.SetLFlag(cPlayer1.GetLFlag()-1);
							cBullet.SetBulletFlag(nLoop,0);
							PlaySound(SOUND_LABEL_SE_HIT000);
							nLCnt++;
							}
						}//敵の玉とプレイヤーチェック
					}
				}//for
		}//

			for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
			{
					if(cEnemy.EnemyChkFlag(nLoop)==1)
					{
				if(cHichk.HitChk(	cPlayer1.PoschkX()+(PSIZE_W/2),cPlayer1.PoschkY()+(PSIZE_H/2),PSIZE_HW/2,PSIZE_HW/2,
				cEnemy.GetEnemyX(nLoop)+(ESIZE_W/2),cEnemy.GetEnemyY(nLoop)+(ESIZE_H/2),ESIZE_W/2,ESIZE_H/2,CIRTOCIR)==1)
				{
							if(nLCnt==0)
							{
							PlaySound(SOUND_LABEL_SE_HIT000);
							cPlayer1.SetLFlag(cPlayer1.GetLFlag()-1);
							cBullet.SetBulletFlag(nLoop,0);
							nLCnt++;
							}
				}
					}
		}
if(nLCnt!=0)
{
		nLCnt++;
		if(nLCnt>=40)
		{
			nLCnt=0;
		}
}
		cPlayer1.PlayerUpdate();//プレイヤーをアップデート
		cBullet.BulletUpdate(cPlayer1.PoschkX(),cPlayer1.PoschkY());//弾アップデート
		cEnemy.EnemyUpdate();//敵アップデート
		cScore.UpdateScore();
		c_Effect.EffectUpdate();
		GameBG.UpdateGameBG();
		GameBG2.UpdateGameBG2(cPlayer1.PoschkX());
		GameBG3.UpdateGameBG3(cPlayer1.PoschkX());
		GameBG0.UpdateGameBG();
	}//ゲーム中
}
//=============================================================================
// 描画関数
//=============================================================================
void GameMODE::DrawGame(void)//ゲーム画面描画
{
		GameBG.DrawGameBG();
		GameBG3.DrawGameBG3();
		cEnemy.DrawEnemy();
		cBullet.DrawBullet();
		if(nLCnt%2==0)
		{
		cPlayer1.DrawPlayer();
		}
		c_Effect.EffectDraw();
		GameBG2.DrawGameBG2();

		GameBG0.DrawGameBG(cPlayer1.GetLFlag());
		cScore.DrawScore();
			if(c_nGameFlag==POSEGAME)//ポーズモード
			{
				GamePoseMenu.DrawGamePS();
			}

}

void GameMODE::GameReset(void)
{
	StopSound();
	nLCnt=0;
		//敵プレイヤー初期化
	cPlayer1.InitPlayer(P1,PSIZE_W,PSIZE_H,PPOS_X,PPOS_Y,1.0,1.0,1);
	cBullet.InitBullet(BULLETIMG,BSIZE_W,BSIZE_H,0,0,1,1,0);
	cEnemy.InitEnemy(E1,ESIZE_W,ESIZE_H,PPOS_X,PPOS_Y,1.0,1.0,1);
	//ポリゴン初期化
	GameBG.InitGameBG();//ＢＧ初期化
	GameBG0.InitGameBG();
	GameBG2.InitGameBG2();
	GameBG3.InitGameBG3();
	cScore.InitScore();//スコア初期化
	c_Effect.EffectInit(BULLETIMG);//エフェクトロード
	c_nGameFlag=MAINGAME;//ゲームの流れセット
}