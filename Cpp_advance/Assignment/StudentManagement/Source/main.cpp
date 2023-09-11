/*
 * File Name: main.cpp
 * Author: Phat Bui Gia
 * Date: 08/09/2023
 * Description: This is the main source file for a student management system using vectors. 
 * It contains the main function that drives the program and provides a menu for user interaction.
 */

#include "StudentManagement.h"

extern vector<SinhVien> dataBaseSV;

int main()
{
	HienThi menu;
	bool exitProgram = false;

	while (!exitProgram)
	{
		cout << "/*******************************************/" << endl;
		menu.giaoDien();
		int luaChon;
	luaChon:
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			menu.themSV();
			break;
		case 2:
			menu.capNhatSV();
			break;
		case 3:
			menu.xoaSV();
			break;
		case 4:
			menu.timKiemSV();
			break;
		case 5:
			menu.sapXepSVTheoDiemTB();
			break;
		case 6:
			menu.sapXepSVTheoTen();
			break;
		case 7:
			menu.danhSachSV();
			break;
		case 8:
			exitProgram = true;
			break;
		default:
			cout << "Lua chon khong hop le." << endl;
			goto luaChon;
		}
	}
	return 0;
}