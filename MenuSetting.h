#pragma once
#include "menu.h"


/*
Setting:
- đối kháng
- độ dài của thanh
- độ to của board
- tốc độ ball ban đầu
- tốc độ thanh
*/

enum itemSetting {
	MODE,
	LENGTH_STICK,
	SIZE_BOARD,
	SPEED_BALL,
	SPEED_STICK,
	SAVE
};
class MenuSetting : public Menu
{
private:
	char szSetting[SAVE][3][11] = {
		{ "PVP", "PVE" },
		{ "Ngan", "Trung binh", "Dai"},
		{ "Nho", "Trung binh",	"To" },
		{ "Cham", "Trung binh", "Nhanh"},
		{ "Cham", "Trung binh", "Nhanh"},

	};
	char constNameSettings[5][1][40] = {
		{"Mode: "},
		{"Do dai cua thanh: "},
		{"Do to cua san choi: "},
		{"Toc do cua banh khi bat dau: "},
		{"Toc do cua thanh khi di chuyen: "},
	};
	vector<int>itemSetting;
	Event event;
public:
	MenuSetting();
	~MenuSetting();
	/**
	* Trả về MODE được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = PVP 1 = PVE
	**/
	int getMode();

	/**
	* Trả về LENGTH của STICK được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = ngắn 1 = trung bình 2 = dài
	**/
	int getLengthStick();

	/**
	* Trả về SIZE của BOARD được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = nhỏ 1 = trung bình 2 = to
	**/
	int getSizeBoard();

	/**
	* Trả về SPEED của BALL được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = chậm 1 = trung bình 2 = nhanh
	**/
	int getSpeedBall();

	/**
	* Trả về SPEED của STICK  được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = chậm 1 = trung bình 2 = nhanh
	**/
	int getSpeedStick();

	void resetMenuSettings(int item);

	void update();

	void changeItem(int item);

	void show();
};
