#ifndef _npe_SDL_joystick_h_
#define _npe_SDL_joystick_h_

typedef struct SDL_Joystick SDL_Joystick;

int SDL_NumJoysticks(void);
SDL_Joystick *SDL_JoystickOpen(int n);
void SDL_JoystickClose(SDL_Joystick*);
int SDL_JoystickNumAxes(SDL_Joystick*);
int SDL_JoystickNumButtons(SDL_Joystick*);
int SDL_JoystickNumHats(SDL_Joystick*);
int SDL_JoystickNumBalls(SDL_Joystick*);
int SDL_JoystickEventState(int);
void SDL_JoystickUpdate(void);
Uint8 SDL_JoystickGetHat(SDL_Joystick*,int);
Sint16 SDL_JoystickGetAxis(SDL_Joystick*,int);
Uint8 SDL_JoystickGetButton(SDL_Joystick*,int);
char* SDL_JoystickName(SDL_Joystick*);

#endif
