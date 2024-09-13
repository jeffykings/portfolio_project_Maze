#include "main.h"

/**
 * toggle_rain - Toggles the rain effect on or off.
 *
 * @is_raining: Pointer to the rain state variable.
 */
void toggle_rain(int *is_raining)
{
	*is_raining = !(*is_raining);
}
