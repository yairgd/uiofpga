/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/20 15:49:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yair Gadelov (yg), yair.gadelov@gmail.com
 *        Company:  Israel
 *
 * =====================================================================================
 */
/*
out vector 0x41200000
----------------------
W11 - clk out - out[0]
W12 - rst out - out[1]

in vector 0x41210000
--------------------
V10 - data in - in[0]


*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

static	int fd;
static void *out_ptr;
static void *in_ptr;
static void *ctl_ptr;

void set_clk() {
	unsigned value = *((unsigned *)(out_ptr));
	value|=0x1;
	*((unsigned *)(out_ptr )) = value;
}
void reset_clk() {
	unsigned value = *((unsigned *)(out_ptr ));
	value&=(~0x1);
	*((unsigned *)(out_ptr )) = value;
}

void set_rst() {
	unsigned value = *((unsigned *)(out_ptr));
	value|=0x2;
	*((unsigned *)(out_ptr )) = value;}
void reset_rst() {
	unsigned value = *((unsigned *)(out_ptr ));
	value&=(~0x2);
	*((unsigned *)(out_ptr )) = value;
}

void enable_timer() {
	unsigned value = *((unsigned *)(out_ptr));
	value|=0x1;
	*((unsigned *)(ctl_ptr )) = value;

}
void disable_timer() {
	unsigned value = *((unsigned *)(out_ptr ));
	value&=(~0x1);
	*((unsigned *)(ctl_ptr )) = value;

}

int get_data() {
	return  *((unsigned *)(in_ptr )) & 0x1;
}

int get_clk() {
	return  *((unsigned *)(out_ptr )) & 0x1;
}




int gpio_hal_init() {
	void *ptr;

	fd = open ("/dev/mem", O_RDWR);
	if (fd < 1) {
		perror("cannot open /dev/mem");
		return -1;
	}

	/* get output ptr */
	unsigned gpio_addr=1092616192, page_offset;
	unsigned page_size=sysconf(_SC_PAGESIZE);
	/* mmap the device into memory */
	unsigned page_addr = (gpio_addr & (~(page_size-1)));
	page_offset = gpio_addr - page_addr;
	ptr = mmap(NULL, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, page_addr);	
	out_ptr = ((unsigned *)(ptr + page_offset));



	/* get input ptr */
	 gpio_addr=1092681728, page_offset;
	 page_size=sysconf(_SC_PAGESIZE);
	/* mmap the device into memory */
	 page_addr = (gpio_addr & (~(page_size-1)));
	page_offset = gpio_addr - page_addr;
	ptr = mmap(NULL, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, page_addr);	
	in_ptr = ((unsigned *)(ptr + page_offset));



	/* get output contorl ptr */
	 gpio_addr=1092747264, page_offset;
	 page_size=sysconf(_SC_PAGESIZE);
	/* mmap the device into memory */
	 page_addr = (gpio_addr & (~(page_size-1)));
	page_offset = gpio_addr - page_addr;
	ptr = mmap(NULL, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, page_addr);	
	ctl_ptr = ((unsigned *)(ptr + page_offset));





	

	/* enable interrupt */
	

}


#ifdef GPIO_HAL_TEST
int main() {
	gpio_hal_init();
	set_clk();
	reset_clk();

	return 0;
}
#endif
	



