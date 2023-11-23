#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>
#include "Phong.h"

using namespace std;

	//Menu----------------------------------------------------------------------------------------------------------------------------------------
	void menuPhong() {
		while(true) {
			system("cls");
			cout << "+----------------------------------------+" << endl;
			cout << "|           MENU QUẢN LÝ PHÒNG           |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 1. Thêm thông tin phòng                |" << endl;
			cout << "| 2. Sửa thông tin phòng                 |" << endl;
			cout << "| 3. Xóa thông tin phòng                 |" << endl;
			cout << "| 4. In danh sách phòng                  |" << endl;
			cout << "| 5. Tìm kiếm phòng theo Mã phòng        |" << endl;
			cout << "| 6. Tìm kiếm phòng theo trạng thái      |" << endl;
			cout << "| 7. Sắp xếp phòng theo Mã phòng         |" << endl;
			cout << "| 8. Sắp xếp phòng theo trạng thái       |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 0. Quay lại                            |" << endl;
			cout << "+----------------------------------------+" << endl << endl;

			int chon;
			cout << "Nhap lua chon: ";
			cin >> chon;
			cin.ignore();

			switch(chon) {
				case 1:
					themPhong();
					system("pause");
					break;
				case 2:
					suaPhong();
					system("pause");
					break;
				case 3:
					xoaPhong();
					system("pause");
					break;
				case 4:
					danhSachPhong.inDanhSachPhong();
					system("pause");
					break;
				case 5:
					danhSachPhong.timKiemPhongTheoMaPhong();
					system("pause");
					break;
				case 6:
					danhSachPhong.timKiemPhongTheoTrangThai();
					system("pause");
					break;
				case 7:
					danhSachPhong.sapXepPhongTheoMaPhong();
					system("pause");
					break;
				case 8:
					danhSachPhong.sapXepPhongTheoTrangThai();
					system("pause");
					break;
				case 0:
					return;
				default:
					cout << "Lua chon ko hop le!\nVui long nhap lua chon khac!" << endl;
					system("pause");
			}
		}
	}

	void menuKhach() {
		while(true) {
			system("cls");
			cout << "+----------------------------------------+" << endl;
			cout << "|        MENU QUAN LY KHACH HANG         |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 1. Thêm thông tin khách hàng           |" << endl;
			cout << "| 2. Sửa thông tin khách hàng            |" << endl;
			cout << "| 3. Xóa thông tin khách hàng            |" << endl;
			cout << "| 4. In danh sách khách hàng             |" << endl;
			cout << "| 5. Tìm kiếm khách hàng theo Mã khách   |" << endl;
			cout << "| 6. Tìm kiếm khách hàng theo Tên        |" << endl;
			cout << "| 7. Sắp xếp khách hàng tăng dần theo Tên|" << endl;
			cout << "| 8. Sắp xếp khách hàng giảm dần theo Tên|" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 0. Quay lại                            |" << endl;
			cout << "+----------------------------------------+" << endl << endl;

			int chon;
			cout << "Nhap lua chon: ";
			cin >> chon;
			cin.ignore();

			switch(chon) {
				case 1:
					themKhachHang();
					system("pause");
					break;
				case 2:
					suaKhachHang();
					system("pause");
					break;
				case 3:
					xoaKhachHang();
					system("pause");
					break;
				case 4:
					danhSachKhachHang.inDSKhachHang();
					system("pause");
					break;
				case 5:
					danhSachKhachHang.timKiemKHTheoMaKhach();
					system("pause");
					break;
				case 6:
					danhSachKhachHang.timKiemKHTheoTen();
					system("pause");
					break;
				case 7:
					danhSachKhachHang.sapXepKHTangDanTheoTen();
					system("pause");
					break;
				case 8:
					danhSachKhachHang.sapXepKHGiamDanTheoTen();
					system("pause");
					break;
				case 0:
					return;
				default:
					cout << "Lua chon ko hop le!\nVui long nhap lua chon khac!" << endl;
					system("pause");
			}
		}
	}

	void menuDatPhong() {
		while(true) {
			system("cls");
			cout << "+----------------------------------------+" << endl;
			cout << "|           MENU DAT PHONG               |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 1. In danh sách phòng                  |" << endl;
			cout << "| 2. Hiển thị phòng còn trống            |" << endl;
			cout << "| 3. Đặt phòng theo Mã phòng             |" << endl;
			cout << "| 4. Trả phòng theo Mã phòng             |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 0. Quay lại                            |" << endl;
			cout << "+----------------------------------------+" << endl << endl;

			int chon;
			cout << "Nhap lua chon: ";
			cin >> chon;
			cin.ignore();

			switch(chon) {
				case 1:
					danhSachPhong.inDanhSachPhong();
					system("pause");	
					break;
				case 2:
					hienThiPhongConTrong();
					system("pause");	
					break;
				case 3:
					datPhongTheoMaPhong(danhSachPhong, danhSachKhachHang);
					system("pause");	
					break;
				case 4:
					traPhongTheoMaPhong();
					system("pause");	
					break;
				case 0:
					return;
				default:
					cout << "Lua chon ko hop le!\nVui long nhap lua chon khac!" << endl;
					system("pause");					
			}
		}
	}
	
	void menuAdmin() {
		while(true) {
			system("cls");
			cout << "+----------------------------------------+" << endl;
			cout << "|               MENU ADMIN               |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 1. Quản lí phòng                       |" << endl;
			cout << "| 2. Quản lí khách hàng                  |" << endl;
			cout << "| 3. Doc/Ghi du lieu vao File            |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 0. Quay lại                            |" << endl;
			cout << "+----------------------------------------+" << endl << endl;

			int chon;
			cout << "Nhap lua chon: ";
			cin >> chon;
			cin.ignore();

			switch(chon) {
				case 1:
					system("pause");
					menuPhong();
					break;
				case 2:
					system("pause");
					menuKhach();
					break;
				case 3:
					system("pause");
					menuDocGhiFile();
					break;
				case 0:
					return;
				default:
					cout << "Lua chon ko hop le!\nVui long nhap lua chon khac!" << endl;
					system("pause");
			}
		}
	}

	void menuUser() {
		menuDatPhong();
	}

	void menuDangNhap() {
		while(true) {
			system("cls");
			cout << "  CHƯƠNG TRÌNH QUẢN LÍ KHÁCH SẠN - UTC2  " << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "|               MENU CHÍNH               |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 1. Đăng nhập với tư cách Admin         |" << endl;
			cout << "| 2. Đăng nhập với tư cách Người dùng    |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 0. Thoát chương trình                  |" << endl;
			cout << "+----------------------------------------+" << endl << endl;

			int chon;
			cout << "Nhap lua chon: ";
			cin >> chon;
			cin.ignore();

			switch(chon) {
				case 1:
					dangNhapAdmin();
					system("pause");
					menuAdmin();
					break;
				case 2:
					dangNhapUser();
					system("pause");
					menuUser();
					break;
				case 0:
					return;
				default:
					cout << "Lua chon ko hop le!\nVui long nhap lua chon khac!" << endl;
					system("pause");
			}
		}
	}

	void menuDocGhiFile() {
		while(true) {
			system("cls");
			cout << "+----------------------------------------+" << endl;
			cout << "|            MENU DOC/GHI FILE           |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 1. Ghi Danh sach phong vao File Phong  |" << endl;
			cout << "| 2. Doc Danh sach phong tu File         |" << endl;
			cout << "| 3. Ghi Danh sach Khach hang vao File   |" << endl;
			cout << "| 4. Doc Danh sach Khach hang tu File    |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| 0. Quay lại                            |" << endl;
			cout << "+----------------------------------------+" << endl << endl;

			int chon;
			cout << "Nhap lua chon: ";
			cin >> chon;
			cin.ignore();

			switch(chon) {
				case 1: 
					ghiVaoFilePhong(danhSachPhong);
					system("pause");
					break;
				case 2:
					docTuFilePhong(danhSachPhong);
					system("pause");
					break;
				case 3:
					ghiVaoFileKhachHang(danhSachKhachHang);
					system("pause");
					break;
				case 4:
					docTuFileKhachHang(danhSachKhachHang);
					system("pause");
					break;
				case 0:
					return;
				default:
					cout << "Lua chon ko hop le!\nVui long nhap lua chon khac!" << endl;
					system("pause");					
			}
		}
	}
