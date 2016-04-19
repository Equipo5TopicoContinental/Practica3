/*
 * Player_Fsm.c
 *
 *  Created on: Apr 19, 2016
 *      Author: Adrian
 */

#include "Player_Fsm.h"
#include "Player.h"

T_BOOL PlayPause, Stop, VolUp, VolDown, Fwd, Rwd;

void Player_Fsm(void);

void PlayPauseReq(void){
	PlayPause = TRUE;
	Player_Fsm();
}
void StopReq(void){
	Stop = TRUE;
	Player_Fsm();
}
void VolUpReq(void){
	VolUp = TRUE;
	Player_Fsm();
}
void VolDownReq(void){
	VolDown = TRUE;
	Player_Fsm();
}
void FwdReq(void){
	Fwd = TRUE;
	Player_Fsm();
}
void RwdReq(void){
	Rwd = TRUE;
	Player_Fsm();
}


void Player_Fsm(void){
	static E_PLAYER_STATE state;
	switch(state){
	case PLAY:
		if(TRUE==PlayPause){
			Player_Pause();
			state = PAUSE;
		}else if(TRUE==Stop){
			Player_Stop();
			state = STOP;
		}else if(TRUE==VolUp){
			Player_VolUp();
			state = PLAY;
		}else if(TRUE == VolDown){
			Player_VolDown();
			state = PLAY;
		}else if(TRUE == Fwd){
			Player_Fwd();
			state = PLAY;
		}else if(TRUE == Rwd){
			if (MAX_RWD_TIME > PlayerState.TrackTime){
				Player_Rwd();
			}else{
				Player_ResetTrack();
			}			
			state = PLAY;
		}else{}
		break;
	case PAUSE:
		if(TRUE == PlayPause){
			Player_Play();
			state = PLAY;
		}else if(TRUE == Stop){
			Player_Stop();
			state = STOP;
		}else if(TRUE==VolUp){
			Player_VolUp();
			state = PAUSE;
		}else if(TRUE == VolDown){
			Player_VolDown();
			state = PAUSE;
		}else if(TRUE == Fwd){
			Player_Fwd();
			state = PAUSE;
		}else if(TRUE == Rwd){
			if (MAX_RWD_TIME > PlayerState.TrackTime){
				Player_Rwd();
			}else{
				Player_ResetTrack();
			}			
			state = PAUSE;
		}else{}
		break;
	case STOP:
		if(TRUE == PlayPause){
			Player_Play();
			state = PLAY;
		}else if(TRUE == Stop){
			Player_ResetPlaylist();
			state = STOP;
		}else if(TRUE==VolUp){
			Player_VolUp();
			state = STOP;
		}else if(TRUE == VolDown){
			Player_VolDown();
			state = STOP;
		}else if(TRUE == Fwd){
			Player_Fwd();
			state = STOP;
		}else if(TRUE == Rwd){
			Player_Rwd();			
			state = STOP;
		}else{}
		break;
	default:
		Player_Init();
		break;
	}
}
