#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>
#include "prototype.h"

using namespace std;

	//KhachHang--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		// Ham kiem tra khach hang ton tai
	bool kiemTraKhachHangTonTai(string maKhach) {
		NodeKH* hienTai = danhSachKhachHang.getDauKH();
		while (hienTai != nullptr) {
			if (hienTai->data.maKhach == maKhach) {
				// Khach hang ton tai trong danh sach
				return true;
			}
			hienTai = hienTai->next;
		}
		// Khach hang khong ton tai trong danh sach
		return false;
	}
		
	void themKhachHang() {
		NodeKH* nutMoi = new NodeKH;
		nutMoi->next = nullptr;

		do {
			cout << "Nhap ma khach hang: ";
			getline(cin, nutMoi->data.maKhach);

			if (isCode(nutMoi->data.maKhach) == false) {
				cout << "Ma khach hang khong hop le!\n(Ma khach hang hop le: VD: KH001)\nVui long nhap lai ma khach hang khac!\n" << endl;
			}

			if (kiemTraKhachHangTonTai(nutMoi->data.maKhach) == true) {
				cout << "Ma khach hang nay da ton tai!\nVui long nhap lai ma khach hang khac!" << endl;
			}
		}

		while ((isCode(nutMoi->data.maKhach) == false) || (kiemTraKhachHangTonTai(nutMoi->data.maKhach) == true));

		do {
			cout << "Nhap ten khach hang: ";
			getline(cin, nutMoi->data.tenKhach);
			if (isName(nutMoi->data.tenKhach) == false) {
				cout << "Ten khach hang khong hop le!\n(Ten hop le: VD: Nguyen Huu Toan)\nVui long nhap lai ten khach hang khac!\n" << endl;
			}		
		}
		while (isName(nutMoi->data.tenKhach) == false);

		do {
			cout << "Nhap tuoi: ";
			cin >> nutMoi->data.tuoi;
			cin.ignore();
			if (isAge(nutMoi->data.tuoi) == false) {
				cout << "Tuoi khong hop le!\nVui long nhap lai tuoi khac!\n" << endl;
			}
		}
		while (isAge(nutMoi->data.tuoi) == false);

		do {
			cout << "Nhap so dien thoai: ";
			getline(cin, nutMoi->data.soDT);
			if (isSDT(nutMoi->data.soDT) == false) {
				cout << "So dien thoai khong hop le!\nVui long nhap lai so dien thoai khac!\n" << endl;
			}
		}
		while (isSDT(nutMoi->data.soDT) == false);

		do {
			cout << "Nhap CCCD: ";
			getline(cin, nutMoi->data.CCCD);	
			if (isCCCD(nutMoi->data.CCCD) == false) {
				cout << "CCCD khong hop le!\nVui long nhap lai so CCCD khac!\n" << endl;
			}	
		}
		while (isCCCD(nutMoi->data.CCCD) == false);

		do {
			cout << "Nhap dia chi: ";
			getline(cin, nutMoi->data.diaChi);		
			if (isName(nutMoi->data.diaChi) == false) {
				cout << "Dia chi khong hop le!\n(Dia chi hop le: VD: Binh Dinh, Tp Ho Chi Minh)\nVui long nhap lai 1 dia chi khac!\n" << endl;
			}
		}
		while (isName(nutMoi->data.diaChi) == false);

		do {
			cout << "Nhap so du tai khoan (VND): ";
			cin >> nutMoi->data.taiKhoan;	
			if (isTaiKhoan(nutMoi->data.taiKhoan) == false) {
				cout << "So du tai khoan khong hop le!\n(So du tai khoan hop le: VD: 100 000(tro len))\nVui long nhap lai 1 so du tai khoan khac!\n" << endl;
			}	
		}
		while (isTaiKhoan(nutMoi->data.taiKhoan) == false);

		if (danhSachKhachHang.getDauKH() == nullptr) {
			danhSachKhachHang.setDauKH(nutMoi);
			danhSachKhachHang.setCuoiKH(nutMoi);
		} else {
			danhSachKhachHang.getCuoiKH()->next = nutMoi;
			danhSachKhachHang.setCuoiKH(nutMoi);
		}

		cout << "Khach hang da duoc them thanh cong!" << endl;
	}

	void suaKhachHang() {
		if (danhSachKhachHang.getDauKH() == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string maKhachCanSua;
		cout << "Nhap ma khach hang can sua: ";
		getline(cin, maKhachCanSua);

		NodeKH* hienTai = danhSachKhachHang.getDauKH();
		while (hienTai != nullptr) {
			if (hienTai->data.maKhach == maKhachCanSua) {
				cout << "Thong tin cu cua khach hang:" << endl;
				cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
				cout << "|   Ma khach    |     Ten khach      | Tuoi | So dien thoai |       CCCD         |      Dia chi       |   Tai khoan   |" << endl;
				cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
				inThongTin1KhachHang(hienTai->data);
				cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;


				do {
					cout << "Nhap ten khach hang: ";
					getline(cin, hienTai->data.tenKhach);
					if (isName(hienTai->data.tenKhach) == false) {
						cout << "Ten khach hang khong hop le!\n(Ten hop le: VD: Nguyen Huu Toan)\nVui long nhap lai ten khach hang khac!\n" << endl;
					}		
				}
				while (isName(hienTai->data.tenKhach) == false);

				do {
					cout << "Nhap tuoi moi: ";
					cin >> hienTai->data.tuoi;
					if (isAge(hienTai->data.tuoi) == false) {
						cout << "Tuoi khong hop le!\nVui long nhap tuoi khac!\n" << endl;
					}
				}
				while (isAge(hienTai->data.tuoi) == false);

				do {
					cout << "Nhap so dien thoai moi: ";
					cin.ignore();
					getline(cin, hienTai->data.soDT);
					if (isSDT(hienTai->data.soDT) == false) {
					cout << "So dien thoai khong hop le!\nVui long nhap lai so dien thoai khac!\n" << endl;
					}
				}
				while (isSDT(hienTai->data.soDT) == false);

				do {
					cout << "Nhap CCCD moi: ";
					getline(cin, hienTai->data.CCCD);		
					if (isCCCD(hienTai->data.CCCD) == false) {
					cout << "CCCD khong hop le!\nVui long nhap lai so CCCD khac!\n" << endl;
					}		
				}
				while (isCCCD(hienTai->data.CCCD) == false);

				do {
					cout << "Nhap dia chi moi: ";
					getline(cin, hienTai->data.diaChi);
					if (isName(hienTai->data.diaChi) == false) {
					cout << "Dia chi khong hop le!\n(Dia chi hop le: VD: Binh Dinh, Tp Ho Chi Minh)\nVui long nhap lai 1 dia chi khac!\n" << endl;
					}
				}
				while (isName(hienTai->data.diaChi) == false);

				do {
					cout << "Nhap tai khoan moi: ";
					cin >> hienTai->data.taiKhoan;
					if (isTaiKhoan(hienTai->data.taiKhoan) == false) {
					cout << "So du tai khoan khong hop le!\n(So du tai khoan hop le: VD: 100 000(tro len))\nVui long nhap lai 1 so du tai khoan khac!\n" << endl;
					}
				}
				while (isTaiKhoan(hienTai->data.taiKhoan) == false);

				cout << "Thong tin khach hang da duoc cap nhat!" << endl;
				return;
			}
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay khach hang co ma " << maKhachCanSua << " trong danh sach." << endl;
	}

	void xoaKhachHang() {
		if (danhSachKhachHang.getDauKH() == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string maKhachCanXoa;
		cout << "Nhap ma khach hang can xoa: ";
		getline(cin, maKhachCanXoa);

		NodeKH* hienTai = danhSachKhachHang.getDauKH();
		NodeKH* truocNo = nullptr;

		while (hienTai != nullptr) {
			if (hienTai->data.maKhach == maKhachCanXoa) {
				if (hienTai == danhSachKhachHang.getDauKH()) {
					danhSachKhachHang.setDauKH(hienTai->next);
				}

				if (hienTai == danhSachKhachHang.getCuoiKH()) {
					danhSachKhachHang.setCuoiKH(truocNo);
					if (truocNo != nullptr) {
						truocNo->next = nullptr;
					}
				}

				if (truocNo != nullptr && hienTai->next != nullptr) {
					truocNo->next = hienTai->next;
				}

				delete hienTai;

				cout << "Khach hang da duoc xoa thanh cong!" << endl;
				return;
			}

			truocNo = hienTai;
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay khach hang co ma " << maKhachCanXoa << " trong danh sach." << endl;
	}

	void inThongTin1KhachHang(KhachHang kh) {
		cout << "|" << setw(15) << left << kh.maKhach << "|"
			<< setw(20) << kh.tenKhach << "|"
			<< setw(6) << kh.tuoi << "|"
			<< setw(15) << kh.soDT << "|"
			<< setw(20) << kh.CCCD << "|"
			<< setw(20) << kh.diaChi << "|"
			<< setw(15) << kh.taiKhoan << "|"
			<< endl;
	}

	void DanhSachKhachHang::inDSKhachHang() {
		if (danhSachKhachHang.getDauKH() == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
		cout << "|   Ma khach    |     Ten khach      | Tuoi | So dien thoai |       CCCD         |      Dia chi       |   Tai khoan   |" << endl;
		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;

		NodeKH* hienTai = danhSachKhachHang.getDauKH();
		while (hienTai != nullptr) {
			inThongTin1KhachHang(hienTai->data);
			hienTai = hienTai->next;
		}

		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
	}

	void DanhSachKhachHang::timKiemKHTheoMaKhach() {
		if (danhSachKhachHang.getDauKH() == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string maKhachCanTim;
		cout << "Nhap ma khach hang can tim: ";
		getline(cin, maKhachCanTim);

		NodeKH* hienTai = danhSachKhachHang.getDauKH();
		while (hienTai != nullptr) {
			if (hienTai->data.maKhach == maKhachCanTim) {
				cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
				cout << "|   Ma khach    |     Ten khach      | Tuoi | So dien thoai |       CCCD         |      Dia chi       |   Tai khoan   |" << endl;
				cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
				inThongTin1KhachHang(hienTai->data);
				cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
				return;
			}
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay khach hang co ma " << maKhachCanTim << " trong danh sach." << endl;
	}

	void DanhSachKhachHang::timKiemKHTheoTen() {
		// Kiểm tra danh sách khách hàng có rỗng hay không
		if (danhSachKhachHang.getDauKH() == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string tenKhachCanTim;
		cout << "Nhap ten khach hang can tim: ";
		getline(cin, tenKhachCanTim);

		NodeKH* hienTai = danhSachKhachHang.getDauKH();
		bool coKhachHang = false;  // Biến cờ để kiểm tra xem có khách hàng nào thỏa mãn hay không

		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
		cout << "|   Ma khach    |     Ten khach      | Tuoi | So dien thoai |       CCCD         |      Dia chi       |   Tai khoan   |" << endl;
		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;

		while (hienTai != nullptr) {
			if (hienTai->data.tenKhach == tenKhachCanTim) {
				inThongTin1KhachHang(hienTai->data);
				coKhachHang = true;  // Đặt cờ thành true khi có ít nhất một khách hàng thỏa mãn
			}
			hienTai = hienTai->next;
		}

		if (!coKhachHang) {
			cout << "|                       Khong tim thay khach hang co ten " << setw(20) << tenKhachCanTim << " trong danh sach.                       |" << endl;
		}

		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
	}

	void DanhSachKhachHang::sapXepKHTangDanTheoTen() {
		if (danhSachKhachHang.getDauKH() == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		cout << "Danh sach khach hang sau khi duoc sap xep tang dan theo ten: " << endl;
		NodeKH* i = danhSachKhachHang.getDauKH();
		while (i != nullptr) {
			NodeKH* j = danhSachKhachHang.getDauKH();
			while (j->next != nullptr) {
				if (j->data.tenKhach > j->next->data.tenKhach) {
					swap(j->data, j->next->data);
				}
				j = j->next;
			}
			i = i->next;
		}

		inDSKhachHang();
	}

	void DanhSachKhachHang::sapXepKHGiamDanTheoTen() {
		if (danhSachKhachHang.getDauKH() == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		cout << "Danh sach khach hang sau khi duoc sap xep giam dan theo ten: " << endl;
		NodeKH* i = danhSachKhachHang.getDauKH();
		while (i != nullptr) {
			NodeKH* j = danhSachKhachHang.getDauKH();
			while (j->next != nullptr) {
				if (j->data.tenKhach < j->next->data.tenKhach) {
					swap(j->data, j->next->data);
				}
				j = j->next;
			}
			i = i->next;
		}

		inDSKhachHang();
	}