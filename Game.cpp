//=============================================================================
//
// ��ʑJ�� [Game.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "Game.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define P1 ("data/TEXTURE/P_Wait.png")
#define P2 ("data/TEXTURE/P2_Wait.png")
#define E1 ("data/TEXTURE/Enemy1.png")
#define P_E1 (20)
#define E_E1 (20)
//=============================================================================
// �������֐�
//=============================================================================
HRESULT GameMODE::InitGame(int nPflag)//�Q�[����ʏ������Ō��ʂ�Ԃ�
{
	nLCnt=0;
	//�G�v���C���[������
	m_nPMode = nPflag;
	if(m_nPMode==CHARA2_MODE)
	{
	cPlayer1.InitPlayer(P1,PSIZE_W,PSIZE_H,PPOS_X,PPOS_Y,1.0,1.0,PLAYER_MAX);
	}else{
	cPlayer1.InitPlayer(P2,PSIZE_W,PSIZE_H,PPOS_X,PPOS_Y,1.0,1.0,PLAYER_MAX);
	}
	cBullet.InitBullet(BULLETIMG,BSIZE_W,BSIZE_H,0,0,1,1,0);
	cEnemy.InitEnemy(E1,ESIZE_W,ESIZE_H,PPOS_X,PPOS_Y,1.0,1.0,0);
	//�|���S��������
	GameBG.InitGameBG();//�a�f������
	GameBG0.InitGameBG();
	GameBG2.InitGameBG2();
	GameBG3.InitGameBG3();
	GamePoseMenu.InitGamePS();
	cScore.InitScore();//�X�R�A������
	c_Effect.EffectInit(BULLETIMG);//�G�t�F�N�g���[�h
	c_nGameFlag=MAINGAME;//�Q�[���̗���Z�b�g
	PlaySound(SOUND_LABEL_BGM001);
	return S_OK;
}
//=============================================================================
// �I�������֐�
//=============================================================================
int GameMODE::UnInitGame(void)//�Q�[����ʏI������
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
// �A�b�v�f�[�g�֐�
//=============================================================================
void GameMODE::UpdateGame(void)//�Q�[����ʃA�b�v�f�[�g
{
	//�|�[�Y�`�F�b�N
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
	if(c_nGameFlag==POSEGAME)//�|�[�Y���[�h
	{
		c_nGameFlag=GamePoseMenu.UpdateGamePS();

	}else{//�Q�[�����[�h
		cPlayer1.SetSpeed(Speed);
		if(GetKeyboardTrigger(DIK_P))//P�Ń|�[�Y�؂�ւ�
	{
		if(c_nGameFlag==MAINGAME)
		{
		c_nGameFlag=POSEGAME;
		}
	}
				cPlayer1.SetFeed(1);
		if(GetKeyboardTrigger(DIK_F5))
		{
			cPlayer1.PlayerReset(PPOS_X,PPOS_Y);//�v���C���[���Z�b�g
		}else
		if(GetKeyboardTrigger(DIK_SPACE)==TRUE&&cPlayer1.GetLFlag()!=0)
		{
			if(m_nPMode==CHARA2_MODE)
			{
 			cBullet.SetBullet(cPlayer1.PoschkX(),cPlayer1.PoschkY(),PLAYER1_B);//�e�Z�b�g
			}else{
			cBullet.SetBullet(cPlayer1.PoschkX(),cPlayer1.PoschkY(),PLAYER2_B);//�e�Z�b�g
			}
		}else
		if(GetKeyboardPress(DIK_LSHIFT)==TRUE&&cPlayer1.GetLFlag()!=0)//�����蔻��`�F�b�N
		{
			cPlayer1.SetSpeed(Speed*0.7f);
 			c_Effect.EffectSet(cPlayer1.PoschkX()+(PSIZE_W/2)-(PSIZE_HW/2),cPlayer1.PoschkY()+(PSIZE_H/2)-(PSIZE_HW/2),PSIZE_HW,PSIZE_HW,P_E1,1.0f,0.2f,0.2f,E_P1_B);
			cPlayer1.SetFeed(0.4);
		}


		for(int nLoopE=0;nLoopE<ENEMY_MAX;nLoopE++)//�G�`�F�b�N
		{
			if(cEnemy.GetBFLag(nLoopE)!=0&&cEnemy.GetFLag(nLoopE)!=0)//�G�̒e�Z�b�g
			{
				cBullet.SetBullet(cEnemy.GetEnemyX(nLoopE),cEnemy.GetEnemyY(nLoopE),ENEMY1_B);
			}

		}

		for(int nLoop=0;nLoop<BULLET_MAX;nLoop++)//�e�`�F�b�N
		{
			for(int nLoop2=0;nLoop2<ENEMY_MAX;nLoop2++)//�G�ƃ`�F�b�N
			{
				if(cBullet.BulletFlagChk(nLoop)==PLAYER1_B)
				{
					c_Effect.EffectSet(cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),EFFECT_SIZE1,EFFECT_SIZE1,P_E1,0.5f,1.0f,0.0f,E_P1_B);//�v���C���[�e
					if(cEnemy.EnemyChkFlag(nLoop2)==1)
					{
					if(cHichk.HitChk(	cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),BSIZE_W,BSIZE_H,
										cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),ESIZE_W,ESIZE_H,QUATOQUA)==1)
					{
						c_Effect.EffectSet(cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),EFFECT_EXPLO,EFFECT_EXPLO,P_E1,1.0f,0.5f,0.5f,E_Ex);//����
						cBullet.SetBulletFlag(nLoop,0);
						cEnemy.SetEnemyFlag(nLoop2,NONE_B);
						cScore.AddScore(10);
						PlaySound(SOUND_LABEL_SE_EXPLOSION);
					}
					}
				}else
				if(cBullet.BulletFlagChk(nLoop)==PLAYER2_B)
				{
					c_Effect.EffectSet(cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),EFFECT_SIZE1,EFFECT_SIZE1,P_E1,0.5f,1.0f,0.0f,E_P2_B);//�v���C���[�e
					if(cEnemy.EnemyChkFlag(nLoop2)==1)
					{
					if(cHichk.HitChk(	cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),BSIZE_W*2,BSIZE_H*2,
										cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),ESIZE_W,ESIZE_H,QUATOQUA)==1)
					{
						c_Effect.EffectSet(cEnemy.GetEnemyX(nLoop2),cEnemy.GetEnemyY(nLoop2),EFFECT_EXPLO,EFFECT_EXPLO,P_E1,1.0f,0.5f,0.5f,E_Ex);//����
						cEnemy.SetEnemyFlag(nLoop2,NONE_B);
						PlaySound(SOUND_LABEL_SE_EXPLOSION);
						cScore.AddScore(10);
					}
					}	
				}else//if
					if(cBullet.BulletFlagChk(nLoop)==ENEMY1_B)
					{
					c_Effect.EffectSet(cBullet.GetBulletX(nLoop),cBullet.GetBulletY(nLoop),EFFECT_SIZE2,EFFECT_SIZE2,E_E1,0.2f,0.1f,0.2f,E_E1_B);//�G�e
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
						}//�G�̋ʂƃv���C���[�`�F�b�N
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
		cPlayer1.PlayerUpdate();//�v���C���[���A�b�v�f�[�g
		cBullet.BulletUpdate(cPlayer1.PoschkX(),cPlayer1.PoschkY());//�e�A�b�v�f�[�g
		cEnemy.EnemyUpdate();//�G�A�b�v�f�[�g
		cScore.UpdateScore();
		c_Effect.EffectUpdate();
		GameBG.UpdateGameBG();
		GameBG2.UpdateGameBG2(cPlayer1.PoschkX());
		GameBG3.UpdateGameBG3(cPlayer1.PoschkX());
		GameBG0.UpdateGameBG();
	}//�Q�[����
}
//=============================================================================
// �`��֐�
//=============================================================================
void GameMODE::DrawGame(void)//�Q�[����ʕ`��
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
			if(c_nGameFlag==POSEGAME)//�|�[�Y���[�h
			{
				GamePoseMenu.DrawGamePS();
			}

}

void GameMODE::GameReset(void)
{
	StopSound();
	nLCnt=0;
		//�G�v���C���[������
	cPlayer1.InitPlayer(P1,PSIZE_W,PSIZE_H,PPOS_X,PPOS_Y,1.0,1.0,1);
	cBullet.InitBullet(BULLETIMG,BSIZE_W,BSIZE_H,0,0,1,1,0);
	cEnemy.InitEnemy(E1,ESIZE_W,ESIZE_H,PPOS_X,PPOS_Y,1.0,1.0,1);
	//�|���S��������
	GameBG.InitGameBG();//�a�f������
	GameBG0.InitGameBG();
	GameBG2.InitGameBG2();
	GameBG3.InitGameBG3();
	cScore.InitScore();//�X�R�A������
	c_Effect.EffectInit(BULLETIMG);//�G�t�F�N�g���[�h
	c_nGameFlag=MAINGAME;//�Q�[���̗���Z�b�g
}