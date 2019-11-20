#pragma once
class Utils
{
public:
	/**
	* Không cho thay đổi kích thước console chương trình
	*
	* @note size của console: 630 x 700
	*
	* @noreturn
	**/
	static void fixConsoleWindow();

	/**
	* Di chuyển con trỏ
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*
	* @param x		hoành độ
	* @param y		tung độ
	*
	* @noreturn
	**/
	static void gotoXY(int x, int y);
};

