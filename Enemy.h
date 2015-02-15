//=============================================================================
//
// �v���C���[�Ǘ� [Enemy.cpp]
// Author : NARITADA SUZUKI
//
#ifndef ENEMY_
#define ENEMY_
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
#include"Base.h"
#include "Bullet.h"

//*****************************************************************************
//�}�N����`
#define ESIZE_W (50)
#define ESIZE_H (25)

#define ENEMY_MAX (10)
//=============================================================================
//�N���X��`
//=============================================================================
class ENEMYMANAGE
{
public:
	void EnemyUpdate();//�G�̂����ՂŁ[��
	int EnemyChkFlag(int nNum);//�t���O�`�F�b�N
	
	void InitEnemy(char *cTexPass,int nEwidth,int nEheight,int nEPosX,int nEPosY,float fTexX,float fTexY,int nFlag);
	void DrawEnemy();
	void UninitEnemy();
	void EnemyMove();//�G�̓���

	float GetEnemyX(int nNum){return EnemyBase[nNum].chkPosX();}
	float GetEnemyY(int nNum){return EnemyBase[nNum].chkPosY();}
	void SetEnemyFlag(int nNum,int nFlag){EnemyBase[nNum].ChangeFlag(nFlag);EnemyBase[nNum].SetCnt(0);}
	
	void SetEnemy(int nNum);

	int GetFLag(int nNum){return EnemyBase[nNum].chkFlag();}
	int GetBFLag(int nNum){return EnemyBase[nNum].GetBlag();}
	void AnimSet();//�A�j���[�V�����Z�b�g

private:
	cBase EnemyBase[ENEMY_MAX];
	Poly EnemyPolygon;
	
	float c_fLength;
	float c_fAngle;
	D3DXVECTOR3 c_pos[ENEMY_MAX];//�|���S���̈ʒu
	D3DXVECTOR3 c_rot;//��]��

	int c_nPTexPattern;//�e�N�X�`���p�^�[��
	int c_nPTexMove;//�e�N�X�`���p�^�[���̈ړ���
	
};

#endif
