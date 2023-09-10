/*
 * File Name: StudentClass_Vector.h
 * Author: Phat Bui Gia
 * Date: 08/09/2023
 * Description: This header file contains the declaration of the Student class 
 * and related functions for a student management system using vectors.
 */

#ifndef __STUDENT_CLASS_VECTOR_H
#define __STUDENT_CLASS_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum
{
	GIOI,
	KHA,
	TB,
	YEU
} HocLuc;

string enumHocLuc(HocLuc h);

typedef enum
{
	NAM,
	NU
} GioiTinh;

string enumGioiTinh(GioiTinh g);

class SinhVien
{
private:
	static double idCounter;
	double id;
	string name;
	double age;
	string gioiTinh;
	double diemToan;
	double diemLy;
	double diemHoa;
	double diemTB;
	string hocLuc;

public:
	void setID();
	void setName();
	void setAge();
	void setGioiTinh();
	void setDiemToan();
	void setDiemLy();
	void setDiemHoa();
	void setDiemTB();
	void setHocLuc();

	double getID();
	string getName();
	double getAge();
	string getGioiTinh();
	double getDiemToan();
	double getDiemLy();
	double getDiemHoa();
	double getDiemTB();
	string getHocLuc();
};

class HienThi
{
private:
public:
	void giaoDien();
	void themSV();
	void capNhatSV();
	void xoaSV();
	void timKiemSV();
	void sapXepSVTheoDiemTB();
	void sapXepSVTheoTen();
	void danhSachSV();
};

void tieuDeThongTinSV();
void hienThiThongTinSV(SinhVien sv);

#endif
