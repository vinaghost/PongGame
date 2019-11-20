#include "Utils.h"

#include <Windows.h>
#include <mmsystem.h>
#include <cstdio>

void Utils::fixConsoleWindow() {
	/*Thay đổi tên chương trình console*/
	SetConsoleTitle(TEXT("Pong"));

	/* Khoá phóng to và co giãn cửa sổ console */

	// lấy id console 
	HWND consoleWindow = GetConsoleWindow();
	// lấy giá trị cấu hình cửa sổ
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	//tắt nút phóng to và co giãn console
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	// Đặt lại giá trị cấu hình của cửa sổ
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	/*https://stackoverflow.com/questions/21238806/how-to-set-output-console-width-in-visual-studio*/
	/* Cấu hình kích thước  */
	MoveWindow(consoleWindow, 0, 0, 630, 700, TRUE);

	/*http://www.cplusplus.com/forum/beginner/95699/*/
	/* Cấu hình vị trí cửa sổ trên màn hình */
	SetWindowPos(consoleWindow, 0, 300, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	//lấy con trỏ giữ màn hình
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	/*https://cboard.cprogramming.com/cplusplus-programming/97959-[ask]-how-remove-scrollbar.html*/
	/*Xoá thanh trượt*/
	CONSOLE_SCREEN_BUFFER_INFO info;

	//Lấy cấu hình buffer của màn hình
	GetConsoleScreenBufferInfo(handle, &info);
	//Cấu hình lại sao cho buffer của màn hình giống với kích thước của màn hình
	COORD new_size = {
		(short int)(info.srWindow.Right - info.srWindow.Left + 1),
		(short int)(info.srWindow.Bottom - info.srWindow.Top + 1),
	};
	//Đặt lại theo cấu hình mới
	SetConsoleScreenBufferSize(handle, new_size);


	/*https://stackoverflow.com/questions/33975912/how-to-set-console-font-to-raster-font-programmatically*/
	/* Cấu hình font của cửa sổ để hiện phần tên game ổn định */
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//Font chạy ổn định nhất: Lucida Console
	wcscpy_s(cfi.FaceName, L"Lucida Console");

	SetCurrentConsoleFontEx(handle, FALSE, &cfi);

}

void Utils::gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	// Di chuyển con trỏ tới vị trí coord 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}