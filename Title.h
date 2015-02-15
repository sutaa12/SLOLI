
//=============================================================================
//
// ��ʑJ�� [Title.h]
// Author : NARITADA SUZUKI
//
//=============================================================================


#ifndef TITLE_FILE
#define TITLE_FILE

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"
#include "Polygon.h"
#include "TitleBG.h"
#include "TitleLogo.h"
#include "ModeFlag.h"
//*****************************************************************************
// �}�N����`
#define MOJIL ("data/TEXTURE/Message.png")
#define MOJIL_W (180)
#define MOJIL_H (150)
#define STARTL ("data/TEXTURE/Start.png")
#define MOJI_W (300)
#define MOJI_H (40)
#define MOJIX (350)
#define MOJIY (250)
#define SELECTBG ("data/TEXTURE/SlectBG.png")
#define BG_WH (1000)
#define SELECT_LOGO ("data/TEXTURE/SLECTMOJI.png")
#define SLOGO_W (551)
#define SLOGO_H (83)
#define SLOGO_X (200)
#define SLOGO_Y (50)
#define CHARA1 ("data/TEXTURE/SLECT_C1.png")
#define CHARA2 ("data/TEXTURE/SLECT_C2.png")
#define CHARA_WH (800)
#define CHARA2_X (100)
enum 
{
	NONE_S,MAIN_S,CHARA1_S,CHARA2_S
};
//*****************************************************************************
class TITLEMODE
{
public:
	TITLEMODE(){}//�R���X�g���N�^
	~TITLEMODE(){}//�f�X�g���N�^
HRESULT InitTitle(void);//�^�C�g��������
void UnInitTitle(void);//�^�C�g���I��
int UpdateTitle(void);//�^�C�g���A�b�v�f�[�g
void DrawTitle(void);//�^�C�g���`��
void UpdateSelect(void);//�Z���N�g���
void DrawSlect(void);
private:
TITLEBGIMAGE TitleBg;
TITLELOGOIMAGE TitleLogo;
Poly TitleButton;
Poly SelectBG;

Poly SelectMoji;
Poly SelectLogo;
Poly SelectChara1;
Poly SelectChara2;
int m_SlectSet;
ModeFlag c_TFlag; 
};
#endif

