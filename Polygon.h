//=============================================================================
//
// �|���S���Ǘ� [polygon.h]
// Author : NARITADA SUZUKI
//
#ifndef _POLYGON_
#define _POLYGON_ 
//=============================================================================
// �C���N���[�h
//*****************************************************************************
#include "main.h"
//*****************************************************************************
// �N���X
//*****************************************************************************
class Poly
{
public:
	Poly();//�R���X�g���N�^
	~Poly();//�f�X�g���N�^
	
	HRESULT InitPolygon(char *cTexPass,int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM);//�|���S��������
	
	void UninitPolygon();//�|���S���I��
	void UpdatePolygon(int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM);//�A�b�v�f�[�g
	void UpdatePolygonROTE(float nPosX1,float nPosY1,float nPosX2,float nPosY2,float nPosX3,float nPosY3,float nPosX4,float nPosY4,int nNUM);//�A�b�v�f�[�g(��])
	void PolygonFeed();//�|���S���̃t�F�[�h����
	void DrawPolygon(int nNum);//�`��
	void PolygonFeedIN();
	void PolygonFeedOUT();
	float Feedchk();
	void SetFeed(float ffeed);
	void SetColor(float fRed,float fGre,float fBlu);

	void SetTexUV(float fTexU,float fTexV,float fTexPU,float fTexPV);//�e�N�X�`����UV�Z�b�g

private:
	LPDIRECT3DTEXTURE9 c_pD3DTexPolygon;//�e�N�X�`���i�[�ϐ�
	LPDIRECT3DVERTEXBUFFER9 c_pD3DVtxBuffPolygon;//���_�o�b�t�@

	int c_nPolyNum;//�\�����鐔
	
	int c_nWidth;//����
	int c_nHeight;//����

	int c_noldWidth;//����
	int c_noldHeight;//����
	
	int c_nPosX;//���WX
	int c_nPosY;//���WY

	int c_noldPosX;//���WX
	int c_noldPosY;//���WY

	float c_fTexU;//�e�N�X�`�����W
	float c_fTexV;
	float c_fTexPatternU;//�e�N�X�`���p�^�[��
	float c_fTexPatternV;//�e�N�X�`���p�^�[��

	float c_fFeedSpeed;//�t�F�[�h�̂͂₳
	float c_fFeed;//�t�F�[�h�l

	float c_fColR;//�Ԃ̒l
	float c_fColG;//�΂̒l
	float c_fColB;//���F�̒l

};

#endif