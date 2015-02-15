//=============================================================================
//
// モードフラグ管理 [ModeFlag.h]
// Author : NARITADA SUZUKI
//===============================================

#ifndef MODE_FLAG
#define MODE_FLAG

#include "main.h"

class ModeFlag
{
public:
	void SetFlag(int nMFlag){GameModeFlag = nMFlag;}
	int GetFlag(void){return GameModeFlag;}
private:
	static int GameModeFlag;
};

#endif