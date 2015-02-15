//=============================================================================
//
// �|���S���Ǘ� [polygon.cpp]
// Author : NARITADA SUZUKI
//
//=============================================================================
//�C���N���[�h
//*****************************************************************************
#include"main.h"
#include"Polygon.h"
//�}�N����`
#define FeedSpeed (0.08)

//*****************************************************************************
//���C���֐�
//*****************************************************************************
	Poly::Poly()//�R���X�g���N�^
	{
		//�l������
		this->c_pD3DTexPolygon=NULL;
		this->c_pD3DVtxBuffPolygon=NULL;
		this->c_nHeight=0;
		this->c_nWidth=0;

		this->c_nPosX=0;
		this->c_nPosY=0;

		this->c_fTexU=0;
		this->c_fTexV=0;
		this->c_fTexPatternU=1;
		this->c_fTexPatternV=1;

		this->c_fFeed=1;

		this->c_fColR=1;
		this->c_fColG=1;
		this->c_fColB=1;
		this->c_nPolyNum=0;//�|���S���̐�

		this->c_fFeedSpeed=FeedSpeed;
	}
//*****************************************************************************
	Poly::~Poly()//�f�X�g���N�^
	{
					if(c_pD3DTexPolygon!=NULL)
	{
		c_pD3DTexPolygon->Release();//������
		c_pD3DTexPolygon=NULL;
	}
			if(c_pD3DVtxBuffPolygon!=NULL)//��łȂ��Ȃ�
			{
				c_pD3DVtxBuffPolygon->Release();
				c_pD3DVtxBuffPolygon=NULL;//�A�h���X�����
			}

	}
//*****************************************************************************
	HRESULT Poly::InitPolygon(char *cTexPass,int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM)//�|���S��������
	{
		this->c_nPolyNum=nNUM;
			if(FAILED(	GetDevice()->CreateVertexBuffer(	//���_�o�b�t�@�쐬
				sizeof(VERTEX_2D)*4*c_nPolyNum,
				D3DUSAGE_WRITEONLY,
				FVF_VERTEX_2D,
				D3DPOOL_MANAGED,
				&c_pD3DVtxBuffPolygon,
				NULL)))
			{
		return E_FAIL;//�ǂݍ��߂Ȃ�������G���[
			}

//���W�Ɖ摜�T�C�Y������
	this->c_nWidth=nPwidth;
	this->c_nHeight=nPheight;
	this->c_nPosX=nPPosX;
	this->c_nPosY=nPPosY;
//�Â����W���p��
	this->c_noldWidth=nPwidth;
	this->c_noldHeight=nPheight;
	this->c_noldPosX=nPPosX;
	this->c_noldPosY=nPPosY;


	VERTEX_2D *c_pvtxPolygon;//���_������ϐ�

	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//���_�̈ʒu�����b�N
	for(int nLoop=0;nLoop<c_nPolyNum;nLoop++)
	{
				//���_���̏�����
	c_pvtxPolygon[0].vtx = D3DXVECTOR3(c_nPosX,c_nPosY,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[1].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[2].vtx = D3DXVECTOR3(c_nPosX,c_nPosY+c_nHeight,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[3].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY+c_nHeight,0.0f);//���_�̍��W�i�[

	c_pvtxPolygon[0].rhw = 1.0f;//�Œ�
	c_pvtxPolygon[1].rhw = 1.0f;//�Œ�
	c_pvtxPolygon[2].rhw = 1.0f;//�Œ�
	c_pvtxPolygon[3].rhw = 1.0f;//�Œ�

	c_pvtxPolygon[0].diffurse = D3DCOLOR_RGBA(255,255,255,255); //�F�ݒ�
	c_pvtxPolygon[1].diffurse = D3DCOLOR_RGBA(255,255,255,255); //�F�ݒ�
	c_pvtxPolygon[2].diffurse = D3DCOLOR_RGBA(255,255,255,255); //�F�ݒ�
	c_pvtxPolygon[3].diffurse = D3DCOLOR_RGBA(255,255,255,255); //�F�ݒ�

	c_pvtxPolygon[0].tex = D3DXVECTOR2(0.0f,0.0f);
	c_pvtxPolygon[1].tex = D3DXVECTOR2(1.0f,0.0f);
	c_pvtxPolygon[2].tex = D3DXVECTOR2(0.0f,1.0f);
	c_pvtxPolygon[3].tex = D3DXVECTOR2(1.0f,1.0f);
	c_pvtxPolygon+=4;
	}
	c_pD3DVtxBuffPolygon->Unlock();//���b�N�̉�����Y�ꂸ��

	//�e�N�X�`���̓ǂݍ���

	D3DXCreateTextureFromFile(GetDevice(),
								cTexPass,
								&c_pD3DTexPolygon);
	return S_OK;

	}
//*****************************************************************************
	void Poly::UninitPolygon()//�|���S���I��
	{
			if(c_pD3DTexPolygon!=NULL)
	{
		c_pD3DTexPolygon->Release();//������
		c_pD3DTexPolygon=NULL;
	}
			if(c_pD3DVtxBuffPolygon!=NULL)//��łȂ��Ȃ�
			{
				c_pD3DVtxBuffPolygon->Release();
				c_pD3DVtxBuffPolygon=NULL;//�A�h���X�����
			}
	}
//*****************************************************************************
	void Poly::UpdatePolygon(int nPwidth,int nPheight,int nPPosX,int nPPosY,int nNUM)//�A�b�v�f�[�g
	{

//���W�Ɖ摜�T�C�Y������
	this->c_nWidth=nPwidth;
	this->c_nHeight=nPheight;
	this->c_nPosX=nPPosX;
	this->c_nPosY=nPPosY;

	VERTEX_2D *c_pvtxPolygon;//���_������ϐ�
	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//���_�̈ʒu�����b�N
	c_pvtxPolygon=c_pvtxPolygon+(nNUM*4);
//���_���̍X�V
	c_pvtxPolygon[0].vtx = D3DXVECTOR3(c_nPosX,c_nPosY,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[1].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[2].vtx = D3DXVECTOR3(c_nPosX,c_nPosY+c_nHeight,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[3].vtx = D3DXVECTOR3(c_nPosX+c_nWidth,c_nPosY+c_nHeight,0.0f);//���_�̍��W�i�[
//�e�N�X�`���̍X�V
	c_pvtxPolygon[0].tex = D3DXVECTOR2(c_fTexU,c_fTexV);
	c_pvtxPolygon[1].tex = D3DXVECTOR2(c_fTexU+(c_fTexPatternU),c_fTexV);
	c_pvtxPolygon[2].tex = D3DXVECTOR2(c_fTexU,c_fTexV+(c_fTexPatternV));
	c_pvtxPolygon[3].tex = D3DXVECTOR2(c_fTexU+(c_fTexPatternU),c_fTexV+(c_fTexPatternV));

	c_pvtxPolygon[0].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�
	c_pvtxPolygon[1].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�
	c_pvtxPolygon[2].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�
	c_pvtxPolygon[3].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�

	c_pD3DVtxBuffPolygon->Unlock();//���b�N�̉�����Y�ꂸ��
	}
//*****************************************************************************
	void Poly::DrawPolygon(int nNum)//�`��
	{
			//�|���S���\��

	GetDevice()->SetStreamSource(0,c_pD3DVtxBuffPolygon,0,sizeof(VERTEX_2D));//�|���S���Z�b�g(2���ڂ�BG)

	GetDevice()->SetFVF(FVF_VERTEX_2D); //���_�t�H�[�}�b�g�̐ݒ�

	GetDevice()->SetTexture(0,c_pD3DTexPolygon);//�e�N�X�`���Z�b�g

	GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//�|���S���̐ݒ�
									nNum*4,
									2);//��
	}
//*****************************************************************************
void Poly::PolygonFeedIN()
{
	if(c_fFeedSpeed<=0)//�O�ȉ��Ȃ�
	{
	c_fFeedSpeed*=-1;
	}
	c_fFeed+=c_fFeedSpeed;
}

void Poly::PolygonFeedOUT()
{
		if(c_fFeedSpeed>=0)//�O�ȉ��Ȃ�
	{
	c_fFeedSpeed*=-1;
	}
	c_fFeed+=c_fFeedSpeed;
}

void Poly::PolygonFeed()
{
	if(c_fFeed>0&&c_fFeed<=1)//�t�F�[�h���O�ȏ�Ȃ�
	{
	c_fFeed+=c_fFeedSpeed;//�t�F�[�h���Z
	}
		VERTEX_2D *c_pvtxPolygon;//���_������ϐ�
	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//���_�̈ʒu�����b�N
				//���_���̏�����
	c_pvtxPolygon[0].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�
	c_pvtxPolygon[1].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�
	c_pvtxPolygon[2].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�
	c_pvtxPolygon[3].diffurse = D3DXCOLOR(c_fColR,c_fColG,c_fColB,c_fFeed); //�F�ݒ�
	
	c_pD3DVtxBuffPolygon->Unlock();//���b�N�̉�����Y�ꂸ��
}
float Poly::Feedchk()
{
	return c_fFeed;
}

void Poly::SetTexUV(float fTexU,float fTexV,float fTexPU,float fTexPV)//�`��
{
	//�e�N�X�`�����W�Z�b�g
	c_fTexU=fTexU;
	c_fTexV=fTexV;
	//�p�^�[���Z�b�g
	c_fTexPatternU=fTexPU;
	c_fTexPatternV=fTexPV;
}

void Poly::UpdatePolygonROTE(float nPosX1,float nPosY1,float nPosX2,float nPosY2,float nPosX3,float nPosY3,float nPosX4,float nPosY4,int nNUM)
{
		VERTEX_2D *c_pvtxPolygon;//���_������ϐ�
	c_pD3DVtxBuffPolygon->Lock(0,0,(void**)&c_pvtxPolygon,0);//���_�̈ʒu�����b�N
	c_pvtxPolygon=c_pvtxPolygon+(nNUM*4);
//���_���̍X�V
	c_pvtxPolygon[0].vtx = D3DXVECTOR3(nPosX1,nPosY1,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[1].vtx = D3DXVECTOR3(nPosX2,nPosY2,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[2].vtx = D3DXVECTOR3(nPosX3,nPosY3,0.0f);//���_�̍��W�i�[
	c_pvtxPolygon[3].vtx = D3DXVECTOR3(nPosX4,nPosY4,0.0f);//���_�̍��W�i�[

	c_pD3DVtxBuffPolygon->Unlock();//���b�N�̉�����Y�ꂸ��
}

void Poly::SetFeed(float ffeed)
{
	this->c_fFeed=ffeed;
}

void Poly::SetColor(float fRed,float fGre,float fBlu)
{
	this->c_fColR=fRed;
	this->c_fColG=fGre;
	this->c_fColB=fBlu;

}