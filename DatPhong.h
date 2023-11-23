#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>
#include "prototype.h"
#include "KhachHang.h"

using namespace std;

	//DatPhong------------------------------------------------------------------------------------------------------------------------------------------
	void hienThiPhongConTrong() {
		if (danhSachPhong.getDau() == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		cout << "+---------------+---------------+---------------+---------------+" << endl;
		cout << "|   Ma phong    |  Loai phong   |   Gia phong   |  Trang thai   |" << endl;
		cout << "+---------------+---------------+---------------+---------------+" << endl;

		Node* hienTai = danhSachPhong.getDau();
		while (hienTai != nullptr) {
			if (hienTai->data.trangThai) {  // Phong con trong (trang thai = true)
				inThongTin1Phong(hienTai->data);
			}
			hienTai = hienTai->next;
		}

		cout << "+---------------+---------------+---------------+---------------+" << endl;
	}

	void truTienKhachHang(string maKhach, int soTienCanTru, DanhSachKhachHang& danhSachKhachHang) {
		NodeKH* hienTai = danhSachKhachHang.getDauKH();

		while (hienTai != nullptr) {
			if (hienTai->data.maKhach == maKhach) {
				if (hienTai->data.taiKhoan >= soTienCanTru) {
					hienTai->data.taiKhoan -= soTienCanTru;
					cout << "Da tru " << soTienCanTru << " VND tu tai khoan cua khach hang " << maKhach << " (Ten khach: " <<hienTai->data.tenKhach << ")" << endl;
				} else {
					cout << "Tai khoan khong du de thanh toan!" << endl;
				}
				return;
			}
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay khach hang co ma " << maKhach << " trong danh sach." << endl;
	}

	// Ham dat phong theo Ma phong
	void datPhongTheoMaPhong(DanhSachPhong& danhSachPhong, DanhSachKhachHang& danhSachKhachHang) {
		if (danhSachPhong.getDau() == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		string maPhongDat;
		cout << "Nhap ma phong muon dat: ";
		getline(cin, maPhongDat);

		Node* hienTai = danhSachPhong.getDau();
		while (hienTai != nullptr) {
			if (hienTai->data.maPhong == maPhongDat) {
				if (hienTai->data.trangThai == 0) {
					cout << "Phong co ma " << maPhongDat << " hien dang trong trang thai da dat." << endl;
					return;
				}

				cout << "+---------------+---------------+---------------+---------------+" << endl;
				cout << "|   Ma phong    |  Loai phong   |   Gia phong   |  Trang thai   |" << endl;
				cout << "+---------------+---------------+---------------+---------------+" << endl;
				inThongTin1Phong(hienTai->data);
				cout << "+---------------+---------------+---------------+---------------+" << endl;

				char luaChon;
				cout << "Ban co muon dat phong nay khong? (1: Yes, 0: No): ";
				cin >> luaChon;

				if (luaChon) {
					// Nhap ma khach muon dat
					string maKhachDat;
					cout << "Nhap ma khach muon dat: ";
					cin.ignore(); // Clear the newline character in the buffer
					getline(cin, maKhachDat);

					if (kiemTraKhachHangTonTai(maKhachDat)) {
					// Tru tien tu tai khoan khach hang
					truTienKhachHang(maKhachDat, hienTai->data.giaPhong, danhSachKhachHang);
					cout << "Tru tien khach hang thanh cong!" << endl;

					// Cap nhat trang thai phong
					hienTai->data.trangThai = 0;
					cout << "Dat phong thanh cong!" << endl;
					}
					else {
						cout << "Dat phong khong thanh cong!" << endl;
					}
				}
				else {
					cout << "Huy dat phong!" << endl;
				}

				return;
			}
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay phong co ma " << maPhongDat << " trong danh sach." << endl;
	}
	// Ham tra phong theo ma phong
	void traPhongTheoMaPhong() {
		if (danhSachPhong.getDau() == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		string maPhongTra;
		cout << "Nhap ma phong muon tra: ";
		getline(cin, maPhongTra);

		Node* hienTai = danhSachPhong.getDau();
		while (hienTai != nullptr) {
			if (hienTai->data.maPhong == maPhongTra) {
				if (hienTai->data.trangThai == 0) {
					// Phong da dat, thuc hien tra phong
					hienTai->data.trangThai = 1;
					cout << "Tra phong thanh cong!" << endl;
				} else {
					cout << "Phong co ma " << maPhongTra << " hien dang trong trang thai chua dat." << endl;
				}
				return;
			}
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay phong co ma " << maPhongTra << " trong danh sach." << endl;
	}
