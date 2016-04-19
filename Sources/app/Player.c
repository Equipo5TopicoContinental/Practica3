/*
 * Player.c
 *
 *  Created on: Apr 19, 2016
 *      Author: Adrian
 */

#include "Player.h"
#include "stdtypedef.h"
#include "RGB_LEDs.h"

COLOR tracks[3][MAX_TRACK_TIME] = {
    { LED_RED, LED_GREEN, LED_GREEN, LED_RED, LED_CYAN, LED_RED, LED_GREEN, LED_GREEN, LED_RED, LED_CYAN, LED_RED, LED_GREEN, LED_GREEN, LED_RED, LED_CYAN, LED_RED, LED_GREEN, LED_GREEN, LED_RED, LED_CYAN, LED_RED, LED_GREEN, LED_GREEN, LED_RED, LED_CYAN, LED_RED, LED_GREEN, LED_GREEN, LED_RED, LED_CYAN},
    { LED_BLUE, LED_BLUE, LED_CYAN, LED_MAGENTA, LED_MAGENTA, LED_BLUE, LED_BLUE, LED_CYAN, LED_MAGENTA, LED_MAGENTA, LED_BLUE, LED_BLUE, LED_CYAN, LED_MAGENTA, LED_MAGENTA, LED_BLUE, LED_BLUE, LED_CYAN, LED_MAGENTA, LED_MAGENTA, LED_BLUE, LED_BLUE, LED_CYAN, LED_MAGENTA, LED_MAGENTA, LED_BLUE, LED_BLUE, LED_CYAN, LED_MAGENTA, LED_MAGENTA },
    { LED_BLUE, LED_CYAN, LED_CYAN, LED_RED, LED_MAGENTA, LED_BLUE, LED_CYAN, LED_CYAN, LED_RED, LED_MAGENTA, LED_BLUE, LED_CYAN, LED_CYAN, LED_RED, LED_MAGENTA, LED_BLUE, LED_CYAN, LED_CYAN, LED_RED, LED_MAGENTA, LED_BLUE, LED_CYAN, LED_CYAN, LED_RED, LED_MAGENTA, LED_BLUE, LED_CYAN, LED_CYAN, LED_RED, LED_MAGENTA },
    
};


void Player_Play(void){
	PlayerState.State = PLAY;
}
void Player_Pause(void){
	PlayerState.State = PAUSE;
}
void Player_Stop(void){
	PlayerState.State = STOP;
	PlayerState.Ticks = 0;
	PlayerState.TrackTime = 0;
}
void Player_VolUp(void){
	if(PlayerState.Volume < MAX_VOL)
	{
		PlayerState.Volume++;
	}else{}

}
void Player_VolDown(void){
	if(PlayerState.Volume > MIN_VOL){
		PlayerState.Volume--;
	}else{}
}
void Player_Fwd(void){
	PlayerState.Track++;
	PlayerState.Track %= NUM_TRACKS;
	PlayerState.Ticks = 0;
	PlayerState.TrackTime = 0;
}
void Player_Rwd(void){
	PlayerState.Track--;
	PlayerState.Track %= NUM_TRACKS;
	PlayerState.Ticks = 0;
	PlayerState.TrackTime = 0;
}
void Player_ResetTrack(void){
	PlayerState.Ticks = 0;
	PlayerState.TrackTime = 0;
}
void Player_Init(void){
	PlayerState.Track=0;
	PlayerState.Ticks = 0;
	PlayerState.TrackTime = 0;
	PlayerState.Volume = 5;
	PlayerState.State = STOP;
}
void Player_ResetPlaylist(void){
	PlayerState.Track=0;
}
void Player_Update(void){
	COLOR c;
	if(PlayerState.State == PLAY){
		PlayerState.Ticks += ticks_per_call;
		PlayerState.TrackTime = PlayerState.Ticks / TICS_PER_SEC;
		if(PlayerState.TrackTime>= MAX_TRACK_TIME){
			Player_Fwd();
		}
		//Show color
		c = tracks[PlayerState.Track][PlayerState.TrackTime % MAX_TRACK_TIME];
		set_color(c);
		
	}else if(PlayerState.State == STOP){
		//LEdsOFF
		leds_off();
	}else if(PlayerState.State == PAUSE){
		//Show color
		
	}else{
		
	}


}
