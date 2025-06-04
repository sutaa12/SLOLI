//=============================================================================
//
// 敵管理 [ENEMY.cpp]
// Author : NARITADA SUZUKI
//

//=============================================================================
//インクルード
//*****************************************************************************
#include"main.h"
#include"Enemy.h"
#include"EnemyConstants.h"
#include"Base.h"
#include"Polygon.h"
#include "input.h"

//=============================================================================
//マクロ定義
//*****************************************************************************
void ENEMYMANAGE::InitEnemy(char *cTexPass,int nPwidth,int nPheight,int nEPosX,int nEPosY,float fTexX,float fTexY,int nFlag)
{
	for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
	nEPosX=rand()%(SCREEN_WIDTH/2);
	nEPosY=rand()%(SCREEN_HEIGHT/2);
	
	this->EnemyBase[nLoop].InitBase(nEPosX,nEPosY,fTexX,fTexY,nPwidth,nPheight,nFlag);
	this->enemies[nLoop] = nullptr;
	
	c_fLength=sqrtf((ESIZE_W/2.0f*ESIZE_W/2.0f)+(ESIZE_H/2.0f*ESIZE_H/2.0f));
	c_fAngle=atan2(ESIZE_W/2.0f,ESIZE_H/2.0f);

	c_pos[nLoop].x=EnemyBase[nLoop].chkPosX()+(ESIZE_W/2.0f);
	c_pos[nLoop].y=EnemyBase[nLoop].chkPosY()+(ESIZE_H/2.0f);//中心座標
	c_rot.z=(D3DX_PI/180)*90;//角度
	}
	this->EnemyPolygon.InitPolygon(cTexPass,nPwidth,nPheight,nEPosX,nEPosY,ENEMY_MAX);

}

void ENEMYMANAGE::EnemyUpdate()
{

		for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
			if(EnemyBase[nLoop].chkFlag()==0)
		{
			SetEnemy(nLoop);
		}
		if(EnemyBase[nLoop].chkFlag()==1)
		{
		this->EnemyBase[nLoop].SetBFlag(0);

		this->EnemyBase[nLoop].SetCnt(this->EnemyBase[nLoop].GetCnt()+1);
		this->EnemyBase[nLoop].SetCnt(this->EnemyBase[nLoop].GetCnt()%ENEMY_BULLET_TIMER+1);

		this->EnemyBase[nLoop].SetBFlag(this->EnemyBase[nLoop].GetCnt()/ENEMY_BULLET_TIMER);

		if(enemies[nLoop])
		{
			enemies[nLoop]->Update();
		}

	c_pos[nLoop].x=EnemyBase[nLoop].chkPosX()+(ESIZE_W/2.0f);
	c_pos[nLoop].y=EnemyBase[nLoop].chkPosY()+(ESIZE_H/2.0f);//中心座標

			this->EnemyPolygon.UpdatePolygonROTE(	c_pos[nLoop].x + sinf( - c_fAngle - c_rot.z) * c_fLength,c_pos[nLoop].y - cosf( - c_fAngle - c_rot.z) * c_fLength,
																					c_pos[nLoop].x - sinf( - c_fAngle + c_rot.z) * c_fLength,c_pos[nLoop].y -  cosf( - c_fAngle + c_rot.z) * c_fLength,
																					c_pos[nLoop].x - sinf(c_fAngle - c_rot.z) * c_fLength,c_pos[nLoop].y + cosf(c_fAngle - c_rot.z) * c_fLength,
																					c_pos[nLoop].x + sinf(c_fAngle + c_rot.z) * c_fLength,c_pos[nLoop].y + cosf(c_fAngle + c_rot.z) * c_fLength ,nLoop);
			}
	}

		EnemyMove();
}
void ENEMYMANAGE::EnemyMove(void)
{
			for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
		if(EnemyBase[nLoop].chkFlag()==1 && enemies[nLoop])
		{
			enemies[nLoop]->Move();
		}
		
	if((EnemyBase[nLoop].chkPosX()<-ESIZE_W||EnemyBase[nLoop].chkPosX()>SCREEN_WIDTH+ESIZE_W||EnemyBase[nLoop].chkPosY()>SCREEN_HEIGHT+ESIZE_H)&&this->EnemyBase[nLoop].GetCnt()>ENEMY_BOUNDARY_BUFFER)
	{
		EnemyBase[nLoop].ChangeFlag(0);
		CleanupEnemyInstance(nLoop);
	}
	}
}
int ENEMYMANAGE::EnemyChkFlag(int nNum)
{
	return EnemyBase[nNum].chkFlag();
}

void ENEMYMANAGE::DrawEnemy()
{
		for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
		if(EnemyBase[nLoop].chkFlag()==1)
		{
		this->EnemyPolygon.DrawPolygon(nLoop);
		}
	}
}
void ENEMYMANAGE::UninitEnemy()
{
	for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
		CleanupEnemyInstance(nLoop);
		this->EnemyPolygon.UninitPolygon();
	}
}

void ENEMYMANAGE::AnimSet()
{
		for(int nLoop=0;nLoop<ENEMY_MAX;nLoop++)
	{
	//this->EnemyPolygon[nLoop].SetTexUV((1.0f/WAIT_ANIM*((c_nPTexPattern/100)%WAIT_ANIM)),0,1.0/WAIT_ANIM,1.f);
	}
}

void ENEMYMANAGE::SetEnemy(int nNum)
{
			EnemyBase[nNum].SetCnt(EnemyBase[nNum].GetCnt()+1);

			if(EnemyBase[nNum].GetCnt()>ENEMY_SPAWN_TIMER)
			{
			int enemyType = rand() % ENEMY_TYPE_COUNT;
			CreateEnemyInstance(nNum, enemyType);
			
			EnemyBase[nNum].ChangeFlag(1);
			EnemyBase[nNum].SetCnt(0);
			
			if(enemies[nNum])
			{
				enemies[nNum]->SetMovementPattern();
			}
			}
}

//=============================================================================
//=============================================================================
void BasicEnemy::Update()
{
	Move();
}

void BasicEnemy::Move()
{
	enemyBase->ChangePos(enemyBase->chkPosX() + enemyBase->GetMoveX(), 
						 enemyBase->chkPosY() + enemyBase->GetMoveY());
}

void BasicEnemy::SetMovementPattern()
{
	int nMode = rand() % 4;
	switch(nMode)
	{
		case 0://右から
		enemyBase->ChangePos(SCREEN_WIDTH+ESIZE_W, rand()%(SCREEN_HEIGHT/2));
		enemyBase->SetMoveX(-ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(0.0f);
		break;

		case 1://左から
		enemyBase->ChangePos(-ESIZE_W, rand()%(SCREEN_HEIGHT/2));
		enemyBase->SetMoveX(ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(0.0f);
		break;
		
		case 2://上から
		enemyBase->ChangePos(rand()%(GAME_MAX_W), -ESIZE_H);
		enemyBase->SetMoveX(ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(ENEMY_MOVEMENT_SPEED);
		break;
		
		case 3://左へ
		enemyBase->ChangePos(rand()%(GAME_MAX_W), -ESIZE_H);
		enemyBase->SetMoveX(-ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(ENEMY_MOVEMENT_SPEED);
		break;
	}
}

//=============================================================================
//=============================================================================
JumpingEnemy::JumpingEnemy(cBase* base, int idx) : Enemy(base, idx)
{
	jumpTimer = 0;
	nextJumpTime = JUMP_MIN_INTERVAL + rand() % (JUMP_MAX_INTERVAL - JUMP_MIN_INTERVAL);
	jumpVelocityY = 0.0f;
	isJumping = false;
}

void JumpingEnemy::Update()
{
	Move();
	UpdateJumpPhysics();
}

void JumpingEnemy::Move()
{
	enemyBase->ChangePos(enemyBase->chkPosX() + enemyBase->GetMoveX(), 
						 enemyBase->chkPosY() + enemyBase->GetMoveY() + jumpVelocityY);
}

void JumpingEnemy::SetMovementPattern()
{
	int nMode = rand() % 4;
	switch(nMode)
	{
		case 0://右から
		enemyBase->ChangePos(SCREEN_WIDTH+ESIZE_W, rand()%(SCREEN_HEIGHT/2));
		enemyBase->SetMoveX(-ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(0.0f);
		break;

		case 1://左から
		enemyBase->ChangePos(-ESIZE_W, rand()%(SCREEN_HEIGHT/2));
		enemyBase->SetMoveX(ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(0.0f);
		break;
		
		case 2://上から
		enemyBase->ChangePos(rand()%(GAME_MAX_W), -ESIZE_H);
		enemyBase->SetMoveX(ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(ENEMY_MOVEMENT_SPEED);
		break;
		
		case 3://左へ
		enemyBase->ChangePos(rand()%(GAME_MAX_W), -ESIZE_H);
		enemyBase->SetMoveX(-ENEMY_MOVEMENT_SPEED);
		enemyBase->SetMoveY(ENEMY_MOVEMENT_SPEED);
		break;
	}
}

void JumpingEnemy::InitiateJump()
{
	if (!isJumping)
	{
		jumpVelocityY = JUMP_VELOCITY_Y;
		isJumping = true;
		nextJumpTime = JUMP_MIN_INTERVAL + rand() % (JUMP_MAX_INTERVAL - JUMP_MIN_INTERVAL);
		jumpTimer = 0;
	}
}

void JumpingEnemy::UpdateJumpPhysics()
{
	jumpTimer++;
	
	if (!isJumping && jumpTimer >= nextJumpTime)
	{
		InitiateJump();
	}
	
	if (isJumping)
	{
		jumpVelocityY += GRAVITY;
		if (jumpVelocityY >= 0.0f)
		{
			jumpVelocityY = 0.0f;
			isJumping = false;
		}
	}
}

//=============================================================================
//=============================================================================
void ENEMYMANAGE::CreateEnemyInstance(int nNum, int enemyType)
{
	CleanupEnemyInstance(nNum);
	
	switch(enemyType)
	{
		case ENEMY_TYPE_BASIC:
			enemies[nNum] = new BasicEnemy(&EnemyBase[nNum], nNum);
			break;
		case ENEMY_TYPE_JUMPING:
			enemies[nNum] = new JumpingEnemy(&EnemyBase[nNum], nNum);
			break;
		default:
			enemies[nNum] = new BasicEnemy(&EnemyBase[nNum], nNum);
			break;
	}
}

void ENEMYMANAGE::CleanupEnemyInstance(int nNum)
{
	if (enemies[nNum])
	{
		delete enemies[nNum];
		enemies[nNum] = nullptr;
	}
}
