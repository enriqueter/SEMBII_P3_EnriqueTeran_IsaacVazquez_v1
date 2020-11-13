/*
 * Mouse&Keyboard.h
 *
 *  Created on: 11,2, 2020
 *      Author: Enrique Teran
 */

#include "Mouse&Keyboard.h"

#define KEYBOARD_DELAY 2000000U
#define MOUSE_DELAY 10000U


typedef enum {S0,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14,S15}state_t;

static void realese_Key (uint8_t* keybuffer);

static state_t state_g = S0;

static int8_t PointerX = 0U;
static int8_t PointerY = 0U;

static void delay(uint32_t max)
{
	uint32_t delay_counter = 0;
	while (max > delay_counter)
		delay_counter++;
}


Boolean_t Cuadrado(uint8_t* MouseOrKeybuffer)
{
	static Boolean_t flag = FALSE;
	switch (state_g)
	{
		case S0:
			/* Move right */
			MouseOrKeybuffer[0] = 1U;
			MouseOrKeybuffer[2] = 2U;
			MouseOrKeybuffer[3] = 0U;

			PointerX++;
			if (PointerX > 99U) {
				state_g++;
			}
			break;

		case S1:
			/* Move down */
			MouseOrKeybuffer[0] = 1U;
			MouseOrKeybuffer[2] = 0U;
			MouseOrKeybuffer[3] = 2U;
			PointerY++;
			if (PointerY > 99U) {
				state_g++;
			}
			break;
		case S2:
			/* Move left */
			MouseOrKeybuffer[0] = 1U;
			MouseOrKeybuffer[2] = (uint8_t) (-2);
			MouseOrKeybuffer[3] = 0U;
			PointerX--;
			if (PointerX < 2U) {
				state_g++;
			}
			break;
		case S3:
			/* Move up */
			MouseOrKeybuffer[0] = 1U;
			MouseOrKeybuffer[2] = 0U;
			MouseOrKeybuffer[3] = (uint8_t) (-2);
			PointerY--;
			if (PointerY < 2U) {
				state_g = S0;
				flag = TRUE;
				delay(MOUSE_DELAY);
			}
			break;
		default:
			break;
		}
	return flag;
}

Boolean_t Paint(uint8_t* MouseOrKeybuffer)
{
	static Boolean_t flag = FALSE;
	switch (state_g)
	{
	case S0:
		/* WINDOWS + R*/
		MouseOrKeybuffer[1] = MODIFERKEYS_LEFT_GUI;
		MouseOrKeybuffer[3] = KEY_R;
		delay(KEYBOARD_DELAY);
		break;
	case S1:
		/* write M*/
		MouseOrKeybuffer[3] = KEY_M;
		delay(KEYBOARD_DELAY);
		break;
	case S2:
		/* write S*/
		MouseOrKeybuffer[3] = KEY_S;
		delay(KEYBOARD_DELAY);
		break;
	case S3:
		/* write P*/
		MouseOrKeybuffer[3] = KEY_P;
		delay(KEYBOARD_DELAY);
		break;
	case S4:
		/* write A*/
		MouseOrKeybuffer[3] = KEY_A;
		delay(KEYBOARD_DELAY);
		break;
	case S5:
		/* write I*/
		MouseOrKeybuffer[3] = KEY_I;
		delay(KEYBOARD_DELAY);
		break;
	case S6:
		/* write N*/
		MouseOrKeybuffer[3] = KEY_N;
		delay(KEYBOARD_DELAY);
		break;
	case S7:
		/* write T*/
		MouseOrKeybuffer[3] = KEY_T;
		delay(KEYBOARD_DELAY);
		break;
	case S8:
		/* ENTER*/
		MouseOrKeybuffer[3] = KEY_ENTER;
		delay(KEYBOARD_DELAY);
		break;
	default:
		realese_Key(MouseOrKeybuffer);
		delay(10*KEYBOARD_DELAY);
		break;
	}

	if (state_g == S9)
	{

		state_g = S0;
		delay(KEYBOARD_DELAY);
		flag = TRUE;

	}
	else
	{
		delay(KEYBOARD_DELAY);
		state_g++;
	}
	return flag;

}

Boolean_t draw(uint8_t* MouseOrKeybuffer)
{
	static Boolean_t flag = FALSE;

	switch (state_g) {
	case S0:
		/* Move right */
			MouseOrKeybuffer[1] = 1U;
			MouseOrKeybuffer[2] = 3U;
			MouseOrKeybuffer[3] = 0U;
			PointerY++;
			if (PointerY > 99U) {
				state_g++;
			}
		break;

	case S1:
		/* Move down */
		MouseOrKeybuffer[1] = 1U;
		MouseOrKeybuffer[2] = 0U;
		MouseOrKeybuffer[3] = 6U;
		PointerY--;
		if (PointerY < 2U) {
			state_g++;
		}
		break;
	case S2:
		/* CLICK */
		MouseOrKeybuffer[1] = 1U;
		MouseOrKeybuffer[2] = 0U;
		MouseOrKeybuffer[3] = 0U;
		PointerY--;
		if (PointerY < 2U) {
			state_g++;

		}
		break;
	case S3:
		MouseOrKeybuffer[1] = 0U;
		MouseOrKeybuffer[2] = 0U;
		MouseOrKeybuffer[3] = 0U;
		state_g = S0;
		flag = TRUE;
		delay(MOUSE_DELAY);
	break;
	default:

		break;
	}

	return flag;
}

Boolean_t Notepad(uint8_t* MouseOrKeybuffer)
{
	static Boolean_t flag = FALSE;
	static direction_t direction = LEFT;
	switch (state_g) {
	case S0:
		/* WINDOWS + R*/
		MouseOrKeybuffer[1] = MODIFERKEYS_LEFT_GUI;
		MouseOrKeybuffer[3] = KEY_R;
		delay(KEYBOARD_DELAY);

		break;
	case S1:
		/* write N*/
		MouseOrKeybuffer[3] = KEY_N;
		delay(KEYBOARD_DELAY);
		break;
	case S2:
		/* write O*/
		MouseOrKeybuffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case S3:
		/* write T*/
		MouseOrKeybuffer[3] = KEY_T;
		delay(KEYBOARD_DELAY);
		break;
	case S4:
		/* write E*/
		MouseOrKeybuffer[3] = KEY_E;
		delay(KEYBOARD_DELAY);
		break;
	case S5:
		/* write P*/
		MouseOrKeybuffer[3] = KEY_P;
		delay(KEYBOARD_DELAY);
		break;
	case S6:
		/* write A*/
		MouseOrKeybuffer[3] = KEY_A;
		delay(KEYBOARD_DELAY);
		break;
	case S7:
		/* write D*/
		MouseOrKeybuffer[3] = KEY_D;
		delay(KEYBOARD_DELAY);
		break;
	case S8:
		/* ENTER*/
		MouseOrKeybuffer[3] = KEY_ENTER;
		delay(KEYBOARD_DELAY);
		break;
	case S9:
			realese_Key(MouseOrKeybuffer);
			delay(KEYBOARD_DELAY);
		break;
	case S10:
		//notepad 1
		if (LEFT == direction)
		{
			/* CTRL + <- */
			MouseOrKeybuffer[1] = MODIFERKEYS_LEFT_GUI;
			MouseOrKeybuffer[3] = KEY_LEFTARROW;
			delay(KEYBOARD_DELAY);
			break;
		}
		else
		{ //notepad 2
			/* CTRL + ->*/
			MouseOrKeybuffer[1] = MODIFERKEYS_LEFT_GUI;
			MouseOrKeybuffer[3] = KEY_RIGHTARROW;
			delay(KEYBOARD_DELAY);
			break;
		}
	default:
		break;
	}

	if (state_g == S10 && direction == LEFT)
	{
		direction = RIGHT;
		state_g = S0;
		delay(KEYBOARD_DELAY);
	}
	else if (state_g == S10 && direction == RIGHT)
	{
		state_g = S0;
		delay(KEYBOARD_DELAY);
		direction = LEFT;
		flag = TRUE;
	}
	else
	{
		state_g++;
	}
	return flag;
}

Boolean_t move(uint8_t* MouseOrKeybuffer, direction_t direction)
{
	static Boolean_t flag = FALSE;

	if(RIGHT == direction)
	{
		flag = FALSE;
		switch (state_g)
		{
			case S0:
				/* Move right */
				MouseOrKeybuffer[1] = 0U;
				MouseOrKeybuffer[2] = (uint8_t) (-4);
				MouseOrKeybuffer[3] = 0U;
				PointerX--;
				if (PointerX < 2U) {
					state_g++;
				}
				break;

			case S1:
				/* click */
				MouseOrKeybuffer[1] = 1U;
				MouseOrKeybuffer[2] = 0U;
				MouseOrKeybuffer[3] = 0U;
				state_g++;
				delay(MOUSE_DELAY);
				break;
			case S2:
				/* unclick */
				MouseOrKeybuffer[1] = 0U;
				MouseOrKeybuffer[2] = 0U;
				MouseOrKeybuffer[3] = 0U;
				state_g++;
				delay(MOUSE_DELAY);
				break;
			case S3:
				/* unclick */
				MouseOrKeybuffer[1] = 0U;
				MouseOrKeybuffer[2] = 0U;
				MouseOrKeybuffer[3] = 0U;
				state_g = S0;
				flag = TRUE;
				break;
			default:
				break;
		}
	}
	else
	{
		switch (state_g)
		{
			case S0:
				/* Move left */
				MouseOrKeybuffer[1] = 0U;
				MouseOrKeybuffer[2] = 4U;
				MouseOrKeybuffer[3] = 0U;

				PointerX++;
				if (PointerX > 200U) {
					state_g++;
				}

				break;

			case S1:
				/* click */
				MouseOrKeybuffer[1] = 1U;
				MouseOrKeybuffer[2] = 0U;
				MouseOrKeybuffer[3] = 0U;
				state_g++;
				delay(MOUSE_DELAY);
				break;
			case S2:
				/* unclick */
				MouseOrKeybuffer[1] = 0U;
				MouseOrKeybuffer[2] = 0U;
				MouseOrKeybuffer[3] = 0U;
				delay(MOUSE_DELAY);
				state_g++;
				break;
			case S3:
				/* unclick */
				MouseOrKeybuffer[1] = 0U;
				MouseOrKeybuffer[2] = 0U;
				MouseOrKeybuffer[3] = 0U;
				state_g = S0;
				flag = TRUE;
				break;
			default:
				break;
		}
	}

		return flag;

}

Boolean_t write(uint8_t* MouseOrKeybuffer)
{
	static Boolean_t flag = FALSE;

	switch (state_g)
	{
	case S0:
		/*  write H*/
		MouseOrKeybuffer[3] = KEY_H;
		delay(KEYBOARD_DELAY);
		break;
	case S1:
		/*  write A*/
		MouseOrKeybuffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case S2:
		/*  write I*/
		MouseOrKeybuffer[3] = KEY_L;
		delay(KEYBOARD_DELAY);
		break;
	case S3:
		/*  write L*/
		MouseOrKeybuffer[3] = KEY_A;
		delay(KEYBOARD_DELAY);
		break;
	case S4:
		/*  SPACEBAR */
		MouseOrKeybuffer[3] = KEY_SPACEBAR;
		delay(KEYBOARD_DELAY);
		break;
	case S5:
		/*  write P*/
		MouseOrKeybuffer[3] = KEY_M;
		delay(KEYBOARD_DELAY);
		break;
	case S6:
		/*  write I*/
		MouseOrKeybuffer[3] = KEY_U;
		delay(KEYBOARD_DELAY);
		break;
	case S7:
		/*  write Z*/
		MouseOrKeybuffer[3] = KEY_N;
		delay(KEYBOARD_DELAY);
		break;
	case S8:
		/*  write A*/
		MouseOrKeybuffer[3] = KEY_D;
		delay(KEYBOARD_DELAY);
		break;
	case S9:
		/*  write N*/
		MouseOrKeybuffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case S10:
		/*  write O*/
		MouseOrKeybuffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case S11:
			realese_Key(MouseOrKeybuffer);
		break;
	default:
		break;
	}

	if (state_g == S12) {
		state_g = S0;
		realese_Key(MouseOrKeybuffer);
		flag = TRUE;
		delay(10 * KEYBOARD_DELAY);
	} else {
		state_g++;
	}

	return flag;
}

Boolean_t copy(uint8_t* MouseOrKeybuffer)
{
	static Boolean_t flag = FALSE;

	switch (state_g) {
	case S0:
		/* CRTL */
		MouseOrKeybuffer[1] = MODIFERKEYS_LEFT_CTRL;
		/* DependS on the language of the computer, it could be KEY_A or KEY_E*/
		MouseOrKeybuffer[3] = KEY_E;
		delay(KEYBOARD_DELAY);
		break;
	case S2:
		delay(10 * KEYBOARD_DELAY);
		break;
	case S3:
		/*  CTRL + C*/
		MouseOrKeybuffer[1] = MODIFERKEYS_LEFT_CTRL;
		MouseOrKeybuffer[3] = KEY_C;
		delay(KEYBOARD_DELAY);
		break;
	case S4:
		realese_Key(MouseOrKeybuffer);
		flag = TRUE;
		delay(KEYBOARD_DELAY);
	break;
	default:
	break;
	}

	if (state_g == S4)
	{
		state_g = S0;
	}
	else
	{
		state_g++;
	}

	return flag;
}

Boolean_t paste(uint8_t* MouseOrKeybuffer)
{
	static Boolean_t flag = FALSE;

	switch (state_g)
	{
		case S0:
			MouseOrKeybuffer[1] = MODIFERKEYS_LEFT_CTRL;
			MouseOrKeybuffer[3] = KEY_V;
			delay(KEYBOARD_DELAY);

			break;
		case S2:
			realese_Key(MouseOrKeybuffer);
			flag = TRUE;
			break;
		default:
			break;
	}

	if (state_g == S2) {
		state_g = S0;
	} else {
		state_g++;
	}

	return flag;
}


static void realese_Key (uint8_t* keybuffer)
{
	keybuffer[1] = 0U;
	keybuffer[3] = 0U;
	keybuffer[4] = 0U;
	keybuffer[5] = 0U;
}
