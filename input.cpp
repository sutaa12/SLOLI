//=============================================================================
//
// ���͏��� [input.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
#include "input.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MAX_KEY (256)//�L�[�̍ő吔
#define START_RE (40)//���s�[�g�J�n
//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
LPDIRECTINPUT8 g_pDInput=NULL;//DirectInput�I�u�W�F�N�g�|�C���^
LPDIRECTINPUTDEVICE8 g_pDIDevkeyboard=NULL;//�f�o�C�X���͂̃|�C���^(�L�[�{�[�h�p)
BYTE g_akeyState[MAX_KEY];//�L�[�{�[�h�̏�Ԋi�[
BYTE g_keyTrigger[MAX_KEY];
BYTE g_keyRelease[MAX_KEY];
BYTE g_keyRepeat[MAX_KEY];
int g_nReCnt[MAX_KEY];//���s�[�g�̃J�E���g


//============================================================================
// �L�[�{�[�h�̏�����
//=============================================================================
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd)
{
	HRESULT hr;
	if(g_pDInput==NULL)//�{�̂��ł��ĂȂ��ꍇ
	{
		// DirectInput�I�u�W�F�N�g�̍쐬
		hr=DirectInput8Create	(hInstance,
								DIRECTINPUT_VERSION,
								IID_IDirectInput8,
								(void**)&g_pDInput,
								NULL);
		if(FAILED(hr))
		{
			//���b�Z�[�W�{�b�N�X�\��
			MessageBox(NULL,"�쐬���s","DI�쐬���s",MB_OK);
			return hr;
		}
	}
	// �f�o�C�X�I�u�W�F�N�g���쐬
	hr=g_pDInput->CreateDevice	(GUID_SysKeyboard,
								&g_pDIDevkeyboard,
								NULL);
		if(FAILED(hr))
		{
			//���b�Z�[�W�{�b�N�X�\��
			MessageBox(NULL,"�쐬���s","CD�쐬���s",MB_OK);
			return hr;
		}


	// �f�[�^�t�H�[�}�b�g��ݒ�
	hr=g_pDIDevkeyboard->SetDataFormat(&c_dfDIKeyboard);
		if(FAILED(hr))
		{
			//���b�Z�[�W�{�b�N�X�\��
			MessageBox(NULL,"�쐬���s","SDF�쐬���s",MB_OK);
			return hr;
		}


	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
		hr=g_pDIDevkeyboard->SetCooperativeLevel	(hWnd,
													(DISCL_FOREGROUND|DISCL_NONEXCLUSIVE));
		if(FAILED(hr))
		{
			//���b�Z�[�W�{�b�N�X�\��
			MessageBox(NULL,"�쐬���s","SCL�쐬���s",MB_OK);
			return hr;
		}
		
		for(int nCnt=0;nCnt<MAX_KEY;nCnt++)
		{
			g_nReCnt[nCnt]=0;
		}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)

		g_pDIDevkeyboard->Acquire();
		
	return S_OK;
}

//=============================================================================
// �L�[�{�[�h�̏I������
//=============================================================================
void UninitKeyboard(void)
{
	// DirectInput�I�u�W�F�N�g�̊J��
	if(g_pDInput!=NULL)
	{
		g_pDInput->Release();
		g_pDInput=NULL;
	}

	// �f�o�C�X�I�u�W�F�N�g�̊J��

	if(g_pDIDevkeyboard!=NULL)
	{
		g_pDIDevkeyboard->Unacquire();
		g_pDIDevkeyboard->Release();
		g_pDIDevkeyboard=NULL;
	}
}

//=============================================================================
// �L�[�{�[�h�̍X�V����
//=============================================================================
void UpdateKeyboard(void)
{
	BYTE akeyState[MAX_KEY];//�L�[�{�[�h�̊i�[���

	if(SUCCEEDED(g_pDIDevkeyboard->GetDeviceState(sizeof(akeyState),&akeyState[0])))
	{
		for(int nCnt=0;nCnt<MAX_KEY;nCnt++)
		{

			g_keyRelease[nCnt]=(akeyState[nCnt]^g_akeyState[nCnt])&g_akeyState[nCnt];//�����[�X���쐬
			
			//���s�[�g���쐬
			if(g_nReCnt[nCnt]<START_RE)//�J�n�ȉ��Ȃ�
			{
				g_keyRepeat[nCnt]=g_keyTrigger[nCnt];//�g���K�[��
							if(g_nReCnt[nCnt]>0)//�J�n�ȉ��Ȃ�
							{
								g_nReCnt[nCnt]++;
							}
			}else{//�J�n�ȏ�Ȃ�
				g_keyRepeat[nCnt]=akeyState[nCnt];//�g���K�[��
			}


			g_keyTrigger[nCnt]=(akeyState[nCnt]^g_akeyState[nCnt])&~g_akeyState[nCnt];//�g���K�[���쐬
			g_akeyState[nCnt]=akeyState[nCnt];//�L�[���X�V
		}
	}else
	{
		g_pDIDevkeyboard->Acquire();
	}
}

//=============================================================================
// �L�[�{�[�h�̃v���X��Ԃ��擾
//=============================================================================
bool GetKeyboardPress(int nKey)
{
	return(g_akeyState[nKey] & 0x80) ? TRUE : FALSE;
}

//=============================================================================
// �L�[�{�[�h�̃g���K�[��Ԃ��擾
//=============================================================================
bool GetKeyboardTrigger(int nKey)
{

	return(g_keyTrigger[nKey] & 0x80) ? TRUE : FALSE;//�g���K�[�̏��ƈ�v���邩
}

//=============================================================================
// �L�[�{�[�h�̃��s�[�g��Ԃ��擾
//=============================================================================
bool GetKeyboardRepeat(int nKey)
{
	return(g_keyRepeat[nKey] & 0x80) ? TRUE : FALSE;

}

//=============================================================================
// �L�[�{�[�h�̃����|�X��Ԃ��擾
//=============================================================================
bool GetKeyboardRelease(int nKey)
{
	return(g_keyRelease[nKey] & 0x80) ? TRUE : FALSE;
}


void RepeatSet(int nKey)
{
	g_nReCnt[nKey]++;
}
void RepaetReset(int nKey)
{g_nReCnt[nKey]=0;
}