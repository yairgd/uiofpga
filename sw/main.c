/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/01/20 11:29:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yair Gadelov (yg), yair.gadelov@gmail.com
 *        Company:  Israel
 *
 * =====================================================================================
 */
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "gpio_hal.h"
#include "trigger.h"

void intHandler(int dummy) {
	disable_timer();

	exit (1);

}
int nsleep(long miliseconds)
{
	struct timespec req, rem;

	if(miliseconds > 999)
	{   
		req.tv_sec = (int)(miliseconds / 1000);                            /* Must be Non-Negative */
		req.tv_nsec = (miliseconds - ((long)req.tv_sec * 1000)) * 1000000; /* Must be in range of 0 to 999999999 */
	}   
	else
	{   
		req.tv_sec = 0;                         /* Must be Non-Negative */
		req.tv_nsec = miliseconds * 1000000;    /* Must be in range of 0 to 999999999 */
	}   

	return nanosleep(&req , &rem);
}
int main() 
{
	struct timeval t1,t2;
	int count=0;
	gpio_hal_init();
	set_clk();
	reset_clk();
	trigger_init();
	count=0;
	signal(SIGINT, intHandler);
	double d[1000];

	enable_timer();
	for (int i=0;i<1000;i++) {
		// measure the time passed between tick to tick
		memcpy (&t1,&t2,sizeof ( struct timeval));
		int prev_count = count;
		count = trigger_poll();	

		gettimeofday(&t2, NULL);
		double diff = t2.tv_sec*1e6 + t2.tv_usec -  t1.tv_sec*1e6 - t1.tv_usec;
		d[i] =diff;


	}
	disable_timer();

	for (int i=0;i<1000;i++)
		printf ("%f\n",d[i]);


	return 0;
}



