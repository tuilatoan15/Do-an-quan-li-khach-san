#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

struct KhachHang {
	string maKhach;
    string tenKhach;
    int tuoi;
    string soDT;
    string CCCD;
    string diaChi;
    int taiKhoan;
};

struct NodeKH {
    KhachHang data;
    NodeKH* next;
};

class DanhSachKhachHang {
private:
    NodeKH* dauKH;
    NodeKH* cuoiKH;

public:
    DanhSachKhachHang();
    ~DanhSachKhachHang();

    NodeKH* getDauKH() const;
    void setDauKH(NodeKH* newDauKH);

    NodeKH* getCuoiKH() const;
    void setCuoiKH(NodeKH* newCuoiKH);

	void inDSKhachHang();
	void timKiemKHTheoMaKhach();
	void timKiemKHTheoTen();
	void sapXepKHTangDanTheoTen();
	void sapXepKHGiamDanTheoTen();
};

	DanhSachKhachHang::DanhSachKhachHang() : dauKH(nullptr), cuoiKH(nullptr) {}

	DanhSachKhachHang::~DanhSachKhachHang() {
		while (dauKH != nullptr) {
			NodeKH* temp = dauKH;
			dauKH = dauKH->next;
			delete temp;
		}
	}

	NodeKH* DanhSachKhachHang::getDauKH() const {
		return dauKH;
	}

	void DanhSachKhachHang::setDauKH(NodeKH* newDauKH) {
		dauKH = newDauKH;
	}

	NodeKH* DanhSachKhachHang::getCuoiKH() const {
		return cuoiKH;
	}

	void DanhSachKhachHang::setCuoiKH(NodeKH* newCuoiKH) {
		cuoiKH = newCuoiKH;
	}

struct Phong {
	string maPhong;
    bool loaiPhong; // V.I.P hoac Thuong
    int giaPhong;
    bool trangThai;
};

// Dinh nghia mot nut cho danh sach lien ket
struct Node {
    Phong data;
    Node* next;
};

// Dinh nghia danh sach lien ket de luu tru cac phong
class DanhSachPhong {
private:
    Node* dau;
    Node* cuoi;
public:
    DanhSachPhong() : dau(nullptr), cuoi(nullptr) {}

    ~DanhSachPhong() {
        while (dau != nullptr) {
            Node* temp = dau;
            dau = dau->next;
            delete temp;
        }
    }

    Node* getDau() const {
        return dau;
    }

    void setDau(Node* newDau) {
        dau = newDau;
    }

    Node* getCuoi() const {
        return cuoi;
    }

    void setCuoi(Node* newCuoi) {
        cuoi = newCuoi;
    }

    void inDanhSachPhong();
	void timKiemPhongTheoMaPhong();
	void timKiemPhongTheoTrangThai();
	void sapXepPhongTheoMaPhong();
	void sapXepPhongTheoTrangThai();
};

struct DatPhong {
    string maKhach;
    string maPhong; 
};