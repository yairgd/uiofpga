/*
 * =====================================================================================
 *
 *       Filename:  gpio_hal.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/20 16:07:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yair Gadelov (yg), yair.gadelov@gmail.com
 *        Company:  Israel
 *
 * =====================================================================================
 */
#ifndef GPIO_HAL
#define GPIO_HAL value
int gpio_hal_init() ;
void set_clk() ;
void reset_clk() ;
void set_rst() ;
void reset_rst() ;
void disable_timer() ;
void enable_timer() ;
int get_data() ;
int get_clk() ;
int get_clk() ;

#endif

