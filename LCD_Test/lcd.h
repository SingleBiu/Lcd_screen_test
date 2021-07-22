/*
 * @Author: SingleBiu
 * @Date: 2021-07-22 16:55:19
 * @LastEditors: SingleBiu
 * @LastEditTime: 2021-07-22 17:17:55
 * @Description: LCD函数头文件
 */
#if !defined(__SCREEN_H__)
#define __SCREEN_H__

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

// LCD屏幕的宽度
#define WIDTH 1024
// LCD屏幕的高度
#define HEIGHT 600

// 常见颜色
#define RED       0xff0000
#define GREEN     0x00ff00
#define BLUE      0x0000ff
#define YELLOW    0xffff00
#define BLACK     0x000000
#define WHITE     0xffffff

// 帧缓冲设备文件描述符
#define LCD_FILE "/dev/fb0"

// 帧缓冲首地址
static int *plcd = NULL;
// LCD_FILE的文件描述符
static int lcd_fd;


typedef unsigned int uint;
typedef unsigned char uchar;

void lcd_init();
void lcd_draw_point(uint x, uint y, int color);
void lcd_draw_rect(uint x0, uint y0, uint w, uint h, int color);

#endif // __SCREEN_H__
