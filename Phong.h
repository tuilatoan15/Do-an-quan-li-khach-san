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

	//Phong--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// Ham kiem tra phong ton tai
	bool kiemTraPhongTonTai(string maPhong) {
		Node* hienTai = danhSachPhong.getDau();
		while (hienTai != nullptr) {
			if (hienTai->data.maPhong == maPhong) {
				// Phong ton tai trong danh sach
				return true;
			}
			hienTai = hienTai->next;
		}
		// Phong khong ton tai trong danh sach
		return false;
	}

	void themPhong() {
		// Tao mot nut moi cho phong moi
		Node* nutMoi = new Node;
		nutMoi->next = nullptr;

		do {
			// Nhap thong tin phong
			cout << "Nhap ma phong: ";
			getline(cin, nutMoi->data.maPhong);
			if (isCode(nutMoi->data.maPhong) == false) {
				cout << "Ma phong khong hop le!\n(Ma phong hop le: VD: PH001)\nVui long nhap ma phong khac!\n" << endl;
			} 

			if (kiemTraPhongTonTai(nutMoi->data.maPhong) == true) {
				cout << "Ma phong nay da ton tai!\nVui long nhap ma phong khac!" << endl;
			}			
		}
		while ((isCode(nutMoi->data.maPhong) == false) || (kiemTraPhongTonTai(nutMoi->data.maPhong) == true));

		do {
			cout << "Nhap loai phong (1: VIP, 0: Thuong): ";
			cin >> nutMoi->data.loaiPhong;
			if (isLoaiPhong(nutMoi->data.loaiPhong) == false) {
				cout << "Loai phong khong hop le!\nVui long nhap loai phong khac!\n" << endl;
			}
		}
		while (isLoaiPhong(nutMoi->data.loaiPhong) == false);

		do {
			cout << "Nhap gia phong (VND): ";
			cin >> nutMoi->data.giaPhong;			
			if (isTaiKhoan(nutMoi->data.giaPhong) == false) {
				cout << "Gia phong khong hop le!\n(Gia phong hop le: VD: 100 000(tro len))\nVui long nhap 1 gia phong khac!\n" << endl;
			}
		}
		while (isTaiKhoan(nutMoi->data.giaPhong) == false);

		do {
			cout << "Nhap trang thai phong (1: Trong, 0: Da dat): ";
			cin >> nutMoi->data.trangThai;	
			if (isTrangThai(nutMoi->data.trangThai) == false) {
				cout << "Trang thai khong hop le!\nVui long nhap lai trang thai khac!\n" << endl;
			}	
		}
		while (isTrangThai(nutMoi->data.trangThai) == false);


		// Them nut moi vao danh sach lien ket
		if (danhSachPhong.getDau() == nullptr) {
			// Neu danh sach rong, dat nut moi lam ca dau va cuoi
			danhSachPhong.setDau(nutMoi);
			danhSachPhong.setCuoi(nutMoi);
		} else {
			// Nguoc lai, them nut moi vao cuoi danh sach va cap nhat cuoi
			danhSachPhong.getCuoi()->next = nutMoi;
			danhSachPhong.setCuoi(nutMoi);
		}

		cout << "Phong da duoc them thanh cong!" << endl;
	}

	// Ham sua thong tin cua mot phong
	void suaPhong() {
		string maPhongCanSua;
		cout << "Nhap ma phong can sua: ";
		getline(cin, maPhongCanSua);

		// Tim phong trong danh sach
		Node* hienTai = danhSachPhong.getDau();
		while (hienTai != nullptr) {
			if (hienTai->data.maPhong == maPhongCanSua) {
				// Hien thi thong tin cu cua phong
				cout << "Thong tin cu cua phong:" << endl;
				cout << "+---------------+---------------+---------------+---------------+" << endl;
				cout << "|   Ma phong    |  Loai phong   |   Gia phong   |  Trang thai   |" << endl;
				cout << "+---------------+---------------+---------------+---------------+" << endl;
				inThongTin1Phong(hienTai->data);
				cout << "+---------------+---------------+---------------+---------------+" << endl;

				// Nhap thong tin moi
				do {
					cout << "Nhap loai phong moi (1: VIP, 0: Thuong): ";
					cin >> hienTai->data.loaiPhong;	
					if (isLoaiPhong(hienTai->data.loaiPhong) == false) {
					cout << "Loai phong khong hop le!\nVui long nhap loai phong khac!\n" << endl;
					}			
				}
				while (isLoaiPhong(hienTai->data.loaiPhong) == false);

				do {
					cout << "Nhap gia phong moi: ";
					cin >> hienTai->data.giaPhong;		
					if (isTaiKhoan(hienTai->data.giaPhong) == false) {
					cout << "Gia phong khong hop le!\n(Gia phong hop le: VD: 100 000(tro len))\nVui long nhap 1 gia phong khac!\n" << endl;
					}		
				}
				while (isTaiKhoan(hienTai->data.giaPhong) == false);
				
				do {
					cout << "Nhap trang thai phong moi (1: Trong, 0: Da dat): ";
					cin >> hienTai->data.trangThai;		
					if (isTrangThai(hienTai->data.trangThai) == false) {
					cout << "Trang thai khong hop le!\nVui long nhap lai trang thai khac!\n" << endl;
					}			
				}
				while (isTrangThai(hienTai->data.trangThai) == false);

				cout << "Thong tin phong da duoc cap nhat!" << endl;
				return;
			}
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay phong co ma " << maPhongCanSua << " trong danh sach." << endl;
	}

	// Ham xoa mot phong khoi danh sach
	void xoaPhong() {
		string maPhongCanXoa;
		cout << "Nhap ma phong can xoa: ";
		getline(cin, maPhongCanXoa);

		// Tim phong trong danh sach
		Node* hienTai = danhSachPhong.getDau();
		Node* truocNo = nullptr;

		while (hienTai != nullptr) {
			if (hienTai->data.maPhong == maPhongCanXoa) {
				// Neu phong can xoa la phong dau danh sach
				if (hienTai == danhSachPhong.getDau()) {
					danhSachPhong.setDau(hienTai->next);
				}

				// Neu phong can xoa la phong cuoi danh sach
				if (hienTai == danhSachPhong.getCuoi()) {
					danhSachPhong.setCuoi(truocNo);
					if (truocNo != nullptr) {
						truocNo->next = nullptr;
					}
				}

				// Neu phong can xoa o giua danh sach
				if (truocNo != nullptr && hienTai->next != nullptr) {
					truocNo->next = hienTai->next;
				}

				// Giai phong bo nho cua nut can xoa
				delete hienTai;

				cout << "Phong da duoc xoa thanh cong!" << endl;
				return;
			}

			truocNo = hienTai;
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay phong co ma " << maPhongCanXoa << " trong danh sach." << endl;
	}

	// Ham in thong tin cua mot phong
	void inThongTin1Phong(Phong phong) {
		cout << "|" << setw(15) << left << phong.maPhong << "|"
			<< setw(15) << (phong.loaiPhong ? "VIP" : "Thuong") << "|"
			<< setw(15) << phong.giaPhong << "|"
			<< setw(15) << (phong.trangThai ? "Trong" : "Da dat") << "|"
			<< endl;
	}

	// Ham in danh sach cac phong
	void DanhSachPhong::inDanhSachPhong() {
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		cout << "+---------------+---------------+---------------+---------------+" << endl;
		cout << "|   Ma phong    |  Loai phong   |   Gia phong   |  Trang thai   |" << endl;
		cout << "+---------------+---------------+---------------+---------------+" << endl;

		Node* hienTai = danhSachPhong.dau;
		while (hienTai != nullptr) {
			inThongTin1Phong(hienTai->data);
			hienTai = hienTai->next;
		}

		cout << "+---------------+---------------+---------------+---------------+" << endl;
	}

	// Ham tim kiem phong theo ma phong
	void DanhSachPhong::timKiemPhongTheoMaPhong() {
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		string maPhongCanTim;
		cout << "Nhap ma phong can tim: ";
		getline(cin, maPhongCanTim);

		Node* hienTai = danhSachPhong.dau;
		while (hienTai != nullptr) {
			if (hienTai->data.maPhong == maPhongCanTim) {
				cout << "+---------------+---------------+---------------+---------------+" << endl;
				cout << "|   Ma phong    |  Loai phong   |   Gia phong   |  Trang thai   |" << endl;
				cout << "+---------------+---------------+---------------+---------------+" << endl;
				inThongTin1Phong(hienTai->data);
				cout << "+---------------+---------------+---------------+---------------+" << endl;
				return;
			}
			hienTai = hienTai->next;
		}

		cout << "Khong tim thay phong co ma " << maPhongCanTim << " trong danh sach." << endl;
	}

	// Ham tim kiem phong theo trang thai
	void DanhSachPhong::timKiemPhongTheoTrangThai() {
		// Kiểm tra danh sách phòng có rỗng hay không
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		bool trangThaiCanTim;
		cout << "Nhap trang thai phong can tim (1: Trong, 0: Da dat): ";
		cin >> trangThaiCanTim;

		cout << "+---------------+---------------+---------------+---------------+" << endl;
		cout << "|   Ma phong    |  Loai phong   |   Gia phong   |  Trang thai   |" << endl;
		cout << "+---------------+---------------+---------------+---------------+" << endl;

		Node* hienTai = danhSachPhong.dau;
		bool coPhong = false;  // Biến cờ để kiểm tra xem có phòng nào thỏa mãn hay không

		while (hienTai != nullptr) {
			if (hienTai->data.trangThai == trangThaiCanTim) {
				inThongTin1Phong(hienTai->data);
				coPhong = true;  // Đặt cờ thành true khi có ít nhất một phòng thỏa mãn
			}
			hienTai = hienTai->next;
		}

		if (!coPhong) {
			cout << "|       Khong co phong nao thoa man trang thai tim kiem.        |" << endl;
		}

		cout << "+---------------+---------------+---------------+---------------+" << endl;
	}

	// Ham sap xep danh sach phong theo ma phong
	void DanhSachPhong::sapXepPhongTheoMaPhong() {
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		cout << "Danh sach phong sau khi duoc sap xep: " << endl;
		// Ap dung thuat toan Bubble Sort de sap xep danh sach phong theo ma phong
		Node* i = danhSachPhong.dau;
		while (i != nullptr) {
			Node* j = danhSachPhong.dau;
			while (j->next != nullptr) {
				// So sanh ma phong va hoan doi neu can
				if (j->data.maPhong > j->next->data.maPhong) {
					swap(j->data, j->next->data);
				}
				j = j->next;
			}
			i = i->next;
		}

		// In danh sach phong da duoc sap xep
		inDanhSachPhong();
	}

	// Ham sap xep danh sach phong theo trang thai
	void DanhSachPhong::sapXepPhongTheoTrangThai() {
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		cout << "Danh sach phong sau khi duoc sap xep: " << endl;
		// Ap dung thuat toan Bubble Sort de sap xep danh sach phong theo trang thai
		Node* i = danhSachPhong.dau;
		while (i != nullptr) {
			Node* j = danhSachPhong.dau;
			while (j->next != nullptr) {
				// So sanh trang thai va hoan doi neu can
				if (j->data.trangThai > j->next->data.trangThai) {
					swap(j->data, j->next->data);
				}
				j = j->next;
			}
			i = i->next;
		}

		// In danh sach phong da duoc sap xep
		inDanhSachPhong();
	}