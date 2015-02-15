//=============================================================================
//
// ���W�x�[�X�Ǘ� [base.h]
// Author : NARITADA SUZUKI
//
#ifndef FILE_BASE
#define FILE_BASE
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include "main.h"
//*****************************************************************************
//=============================================================================
//�N���X��`
//=============================================================================
class cBase
{
public:
	//�R���X�g���N�^
	cBase(float fPosX,float fPosY,float fTexX,float fTexY,int nWitdh,int Height,int nFlag);
	cBase();
	//������
	void InitBase(float fPosX,float fPosY,float fTexX,float fTexY,int nWitdh,int Height,int nFlag);
	//���W��Ԃ�,
	float chkPosX(void);
	float chkPosY(void);

	float chkTexX(void);
	float chkTexY(void);

	//�t�F�[�h�l��Ԃ�
	float GetFeed(void);

	//�t�F�[�h�l�ύX
	void SetFeed(float fFeedO);

	//���W�ύX
	void ChangePos(float fPosX,float fPosY);
	void ChangeTex(float fTexX,float fTexY);

	//�T�C�Y��Ԃ�
	int chkWitdth(void);
	int chkHeight(void);

	//�T�C�Y�ύX
	void ChangeSize(int nWitdh,int nHeight);
	
	//�J�E���g�ύX�`�F�b�N

	void SetCnt(int nCount);
	int GetCnt(void);

	//�t���O��Ԃ�
	int chkFlag(void);
	int GetBlag(void){return c_nBFlag;}

	//�t���O�ύX
	void ChangeFlag(int nFlag);
	void SetBFlag(int nBFlag){c_nBFlag=nBFlag;};//�e�t���O
	
	void SetMoveX(float fMovex){	c_fMovex=fMovex;}
	void SetMoveY(float fMovey){	c_fMovey=fMovey;}

	float GetMoveX(void){return c_fMovex;}
	float GetMoveY(void){return c_fMovey;}

	void SetCol(float fR,float fG,float fB){c_fRed=fR;c_fGre=fG;c_fBlu=fB;}
	float GetColR(void){return c_fRed;}
	float GetColG(void){return c_fGre;}
	float GetColB(void){return c_fBlu;}

private:
	//���W
	float c_fPosX;
	float c_fPosY;
	float c_foldPosX;
	float c_foldPosY;
	float c_fMovex;
	float c_fMovey;
	//�e�N�X�`�����W
	float c_fTexX;
	float c_fTexY;
	//�摜�T�C�Y
	int c_nWitdh;
	int c_nHeight;
	
	//�t�F�[�h�l
	float c_fFeed;
	//RGB
	float c_fRed;
	float c_fGre;
	float c_fBlu;
	//����
	int c_nCnt;

	//�t���O
	int c_nLFlag;
	int c_nBFlag;
};

#endif