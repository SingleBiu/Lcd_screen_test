/*
 * @Author: SingleBiu
 * @Date: 2021-07-22 17:11:17
 * @LastEditors: SingleBiu
 * @LastEditTime: 2021-07-22 17:17:45
 * @Description: LCD函数文件
 */
#include"srceen.h"

/**
 * @description: LCD屏幕初始化
 * @param {*}
 * @return {*}
 */
void lcd_init()
{
    // 打开LCD文件
    lcd_fd = open(LCD_FILE, O_RDWR);
	if (-1 == fd)
	{
		perror("open LCD error");
		return ;
	}

    // 使plcd指向帧缓冲区的首地址
    plcd = mmap(NULL, WIDTH*HEIGHT*4, 
	           PROT_READ | PROT_WRITE,
			   MAP_SHARED,
			   fd,
			   0);
}

/**
 * @description: 在LCD屏幕上画一个color颜色的点
 * @param {uint} x 屏幕的x坐标
 * @param {uint} y 屏幕的y坐标
 * @param {int} color 要填充的颜色
 * @return {*}
 */
void lcd_draw_point(uint x, uint y, int color)
{
	if (x >= WIDTH || y >= HEIGHT)
		return ;
	*(plcd + y*WIDTH + x) = color;
}

/**
 * @description: 在LCD的任意位置 显示一个任意大小的任意颜色的矩形
 * @param {uint} x0 矩形起始的x坐标
 * @param {uint} y0 矩形起始的y坐标
 * @param {uint} w  矩形的宽
 * @param {uint} h  矩形的高
 * @param {int} color  要填充的颜色
 * @return {*}
 */
void lcd_draw_rect(uint x0, uint y0, uint w, uint h, int color)
{
	int x, y;
	for (y = y0; y < y0 + h && y < HEIGHT; y++)
	{
		for (x = x0; x < x0 + w && x < WIDTH; x++)
			lcd_draw_point(x, y, color);
	}
}

/**
 * @description: 检测LCD屏幕有无坏点
 * @param {*}
 * @return {*}
 */
void lcd_color_check()
{
    while(1)
    {
        lcd_draw_rect(0,0,WIDTH,HEIGHT,BLACK);
        sleep(3);
        lcd_draw_rect(0,0,WIDTH,HEIGHT,RED);
        sleep(3);
        lcd_draw_rect(0,0,WIDTH,HEIGHT,GREEN);
        sleep(3);
        lcd_draw_rect(0,0,WIDTH,HEIGHT,BLUE);
        sleep(3);
        lcd_draw_rect(0,0,WIDTH,HEIGHT,YELLOW);
        sleep(3);
        lcd_draw_rect(0,0,WIDTH,HEIGHT,WHITE);
        sleep(3);
    }
}