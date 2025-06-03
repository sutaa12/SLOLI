//=============================================================================
//
// Enemy Constants [EnemyConstants.h]
// Author : NARITADA SUZUKI
//
//=============================================================================
#ifndef _ENEMY_CONSTANTS_H_
#define _ENEMY_CONSTANTS_H_

//*****************************************************************************
// Enemy Movement Constants
//*****************************************************************************
#define ENEMY_MOVEMENT_SPEED (0.5f)
#define ENEMY_SPAWN_TIMER (70)
#define ENEMY_BULLET_TIMER (120)
#define ENEMY_BOUNDARY_BUFFER (90)

//*****************************************************************************
// Enemy Type Constants
//*****************************************************************************
#define ENEMY_TYPE_BASIC (0)
#define ENEMY_TYPE_JUMPING (1)
#define ENEMY_TYPE_COUNT (2)

//*****************************************************************************
// Jumping Enemy Constants
//*****************************************************************************
#define JUMP_MIN_INTERVAL (60)
#define JUMP_MAX_INTERVAL (120)
#define JUMP_VELOCITY_Y (-3.0f)
#define GRAVITY (0.1f)

#endif
