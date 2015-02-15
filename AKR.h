
//=============================================================================
//
// �J�[�Q�[�������� [AKR.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef AKR_FILE
#define AKR_FILE

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define X1 (0)	//���_1�̍��W
#define X2 (200)	//���_2�̍��W

#define Y1 (300)	//���_1�̍��W
#define Y2 (600)	//���_2�̍��W

#define AKRX1 (0)	//���_1�̍��W
#define AKRX2 (180)	//���_2�̍��W

#define AKRY1 (0)	//���_1�̍��W
#define AKRY2 (360)	//���_2�̍��W

#define AKR_SIZE_MIN (10) //�Ίp���̍ŏ��l
#define AKR_SIZE_MAX (800)//�Ίp���̍ő�l 

#define Y_SPEED (30)	//�c�̉����x
#define X_SPEED (30)	//���̉����x



#define AKR_MAX (1) //�搶�̃}�b�N�X

#define AKR1 ("data/TEXTURE/akira000.png")
#define AKR2 ("../data/TEXTURE/akira000.png")
//*****************************************************************************
// �\���̐錾
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitPolygonAKR(void);//�|���S���������Ō��ʂ�Ԃ�
void UnInitPolygonAKR(void);//�|���S���I������
void UpdatePolygonAKR(void);//�|���S���A�b�v�f�[�g
void DrawPolygonAKR(void);//�|���S���`��
void UpdateROTATE();

#endif
//AKR