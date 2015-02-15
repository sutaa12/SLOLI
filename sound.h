//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : NARITADA SUZUKI
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

// �T�E���h�t�@�C��
typedef enum
{
	SOUND_LABEL_BGM000 = 0,		// BGM0
	SOUND_LABEL_BGM001,			// BGM1
	SOUND_LABEL_BGM002,			// BGM2
	SOUND_LABEL_SE_SHOT,		// �e���ˉ�
	SOUND_LABEL_SE_SHOT2,		// �e���ˉ�
	SOUND_LABEL_SE_LASER,		// ���[�U�[���ˉ�
	SOUND_LABEL_SE_EXPLOSION,	// ������
	SOUND_LABEL_SE_HIT000,		// �Փˉ�0
	SOUND_LABEL_SE_HIT001,		// �Փˉ�1
	SOUND_LABEL_SE_DEFEND,		// �h�䉹
	SOUND_LABEL_SE_LOCKON,		// ���b�N�I����
	SOUND_LAVEL_SE_BUTTON,
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);

#endif
