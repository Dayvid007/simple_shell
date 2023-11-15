#include "secondheader.h"

/**
 * gt_signedinnt - Handle the crtl + c call in prompt
 * @sigma: Signal handler
 */
void gt_signedinnt(int sigma)
{
	(void)sigma;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
