#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>
#include "lib_struct_and_class.h"

using namespace std;

//Khai bao toan cuc--------------------------------------------------------------------------------------------------------------------------------
DanhSachPhong danhSachPhong;
DanhSachKhachHang danhSachKhachHang;
int SLPhong = 0, SLKhach = 0, SLDatPhong = 0;
double doanhThu = 0;

//prototype----------------------------------------------------------------------------------------------------------------------------------------
	//Cac ham dieu kien
	bool isName(string name);
	bool isCode(string code);
	bool isAge(int age);
	bool isSDT(string sdt);
	bool isCCCD(string cccd);
	bool isTaiKhoan(int taiKhoan);
	bool isLoaiPhong(int loaiPhong);
	bool isTrangThai(int trangThai);

	//DangNhap
	int dangNhapAdmin();
	int dangNhapUser();
	//Phong
	void themPhong();
	void suaPhong();
	void xoaPhong();
	void inThongTin1Phong(Phong phong);
	//Khach
	void themKhachHang();
	void suaKhachHang();
	void xoaKhachHang();
	void inThongTin1KhachHang(KhachHang kh);
	//DatPhong
	void hienThiPhongConTrong();
	void datPhongTheoMaPhong(DanhSachPhong& danhSachPhong, DanhSachKhachHang& danhSachKhachHang);
	void traPhongTheoMaPhong();
	//Doc/Ghi File
	void ghiVaoFilePhong(const DanhSachPhong& danhSachPhong);
	void ghiVaoFileKhachHang(const DanhSachKhachHang& danhSachKhachHang);
	void docTuFilePhong(DanhSachPhong& danhSachPhong);
	void docTuFileKhachHang(DanhSachKhachHang& danhSachKhachHang);
	//Menu
	void menuDangNhap();
	void menuAdmin();
	void menuUser();
	void menuPhong();
	void menuKhach();
	void menuDatPhong();
	void menuDocGhiFile();