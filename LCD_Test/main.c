/*
 * @Author: SingleBiu
 * @Date: 2021-07-22 14:48:40
 * @LastEditors: SingleBiu
 * @LastEditTime: 2021-07-22 19:05:00
 * @Description: 一个简单的测试LCD屏幕的程序
 */
#include"lcd.h"

int main(int argc, char const *argv[])
{
    // 初始化LCD屏幕
    lcd_init();

    // 检查LCD屏幕有无坏点
    lcd_color_check();
    
    // 关闭LCD屏幕
    close(lcd_fd);

    return 0;
}
