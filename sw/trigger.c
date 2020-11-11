/*
 * =====================================================================================
 *
 *       Filename:  trigger.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/30/20 14:25:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yair Gadelov (yg), yair.gadelov@gmail.com
 *        Company:  Israel
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include "trigger.h"


#define DEV_NAME  "/dev/uio0"

static int fd;

int trigger_init(void)
{

	fd=open(DEV_NAME,O_RDONLY);
	if (fd<0) {
		return -1;
	}

	return 0;
}



//https://yurovsky.github.io/2014/10/10/linux-uio-gpio-interrupt.html

int trigger_poll(void)
{
	int info = 1,nb; /* unmask */

	struct pollfd fds = {
            .fd = fd,
            .events = POLLIN,
        };

        int ret = poll(&fds, 1, -1);

	if (ret >= 1) {
            nb = read(fd, &info, sizeof(info));
            if (0 && nb == (ssize_t)sizeof(info)) {
                /* Do something in response to the interrupt. */
                printf("Interrupt #%u!\n", info);
            }
        } else {
	    info = -1;
          //  close(fd);
        }


	return info;

}
