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

	// doc ghi file-------------------------------------------------------------------------------------------------------------------------------
	// Ghi phòng vào file
	void ghiVaoFilePhong(const DanhSachPhong& danhSachPhong) {
		const string tenFile = "DanhSachPhong.txt";
		ofstream outFile(tenFile);

		if (outFile.is_open()) {
			Node* currentPhong = danhSachPhong.getDau();
			while (currentPhong != nullptr) {
				outFile << "Ma phong: " << currentPhong->data.maPhong << endl;
				outFile << "Loai phong: " << (currentPhong->data.loaiPhong ? "VIP" : "Thuong") << endl;
				outFile << "Gia phong: " << currentPhong->data.giaPhong << endl;
				outFile << "Trang thai: " << (currentPhong->data.trangThai ? "Da dat" : "Chua dat") << endl;
				outFile << endl;

				currentPhong = currentPhong->next;
			}

			outFile.close();
			cout << "Danh sach phong da duoc ghi vao file." << endl;
		} else {
			cerr << "Khong the mo file de ghi." << endl;
		}
	}

	// Đọc phòng từ file
	void docTuFilePhong(DanhSachPhong& danhSachPhong) {
		const string tenFile = "DanhSachPhong.txt";
		ifstream inFile(tenFile);

		if (inFile.is_open()) {
			string line;
			bool loi = false;

			while (getline(inFile, line)) {
				if (line == "") continue;

				Phong phong;
				if (line.find("Ma phong:") != string::npos) {
					phong.maPhong = line.substr(line.find(":") + 2);
					getline(inFile, line);
					if (line.find("Loai phong:") != string::npos) {
						phong.loaiPhong = (line.substr(line.find(":") + 2) == "VIP");
						getline(inFile, line);
						if (line.find("Gia phong:") != string::npos) {
							try {
								phong.giaPhong = stoi(line.substr(line.find(":") + 2));
							} catch (const exception& e) {
								cerr << "Loi: " << e.what() << endl;
								loi = true;
								break;
							}
							getline(inFile, line);
							if (line.find("Trang thai:") != string::npos) {
								phong.trangThai = (line.substr(line.find(":") + 2) == "Da dat");

								// Thêm phòng vào danh sách
								Node* newNode = new Node{phong, nullptr};
								if (danhSachPhong.getDau() == nullptr) {
									danhSachPhong.setDau(newNode);
									danhSachPhong.setCuoi(newNode);
								} else {
									danhSachPhong.getCuoi()->next = newNode;
									danhSachPhong.setCuoi(newNode);
								}
							} else {
								cerr << "Loi: Du lieu trang thai phong khong hop le." << endl;
								loi = true;
								break;
							}
						} else {
							cerr << "Loi: Du lieu gia phong khong hop le." << endl;
							loi = true;
							break;
						}
					} else {
						cerr << "Loi: Du lieu loai phong khong hop le." << endl;
						loi = true;
						break;
					}
				} else {
					cerr << "Loi: Du lieu ma phong khong hop le." << endl;
					loi = true;
					break;
				}
			}

			inFile.close();

			if (!loi) {
				cout << "Danh sach phong da duoc doc tu file." << endl;
			}
		} else {
			cerr << "Khong the mo file de doc." << endl;
		}
	}

	// Ghi khách hàng vào file
	void ghiVaoFileKhachHang(const DanhSachKhachHang& danhSachKhachHang) {
		const string tenFile = "DanhSachKhachHang.txt";
		ofstream outFile(tenFile);

		if (outFile.is_open()) {
			NodeKH* currentKhachHang = danhSachKhachHang.getDauKH();
			while (currentKhachHang != nullptr) {
				outFile << "Ma khach: " << currentKhachHang->data.maKhach << endl;
				outFile << "Ten khach: " << currentKhachHang->data.tenKhach << endl;
				outFile << "Tuoi: " << currentKhachHang->data.tuoi << endl;
				outFile << "So dien thoai: " << currentKhachHang->data.soDT << endl;
				outFile << "CCCD: " << currentKhachHang->data.CCCD << endl;
				outFile << "Dia chi: " << currentKhachHang->data.diaChi << endl;
				outFile << "Tai khoan: " << currentKhachHang->data.taiKhoan << endl;
				outFile << endl;

				currentKhachHang = currentKhachHang->next;
			}

			outFile.close();
			cout << "Danh sach khach hang da duoc ghi vao file." << endl;
		} else {
			cerr << "Khong the mo file de ghi." << endl;
		}
	}

	// Đọc khách hàng từ file
	void docTuFileKhachHang(DanhSachKhachHang& danhSachKhachHang) {
		const string tenFile = "DanhSachKhachHang.txt";
		ifstream inFile(tenFile);

		if (inFile.is_open()) {
			string line;
			bool loi = false;

			while (getline(inFile, line)) {
				if (line == "") continue;

				KhachHang khachHang;
				if (line.find("Ma khach:") != string::npos) {
					khachHang.maKhach = line.substr(line.find(":") + 2);
					getline(inFile, line);
					if (line.find("Ten khach:") != string::npos) {
						khachHang.tenKhach = line.substr(line.find(":") + 2);
						getline(inFile, line);
						if (line.find("Tuoi:") != string::npos) {
							try {
								khachHang.tuoi = stoi(line.substr(line.find(":") + 2));
							} catch (const exception& e) {
								cerr << "Loi: " << e.what() << endl;
								loi = true;
								break;
							}
							getline(inFile, line);
							if (line.find("So dien thoai:") != string::npos) {
								khachHang.soDT = line.substr(line.find(":") + 2);
								getline(inFile, line);
								if (line.find("CCCD:") != string::npos) {
									khachHang.CCCD = line.substr(line.find(":") + 2);
									getline(inFile, line);
									if (line.find("Dia chi:") != string::npos) {
										khachHang.diaChi = line.substr(line.find(":") + 2);
										getline(inFile, line);
										if (line.find("Tai khoan:") != string::npos) {
											try {
												khachHang.taiKhoan = stoi(line.substr(line.find(":") + 2));
											} catch (const exception& e) {
												cerr << "Loi: " << e.what() << endl;
												loi = true;
												break;
											}

											// Thêm khách hàng vào danh sách
											NodeKH* newNode = new NodeKH{khachHang, nullptr};
											if (danhSachKhachHang.getDauKH() == nullptr) {
												danhSachKhachHang.setDauKH(newNode);
												danhSachKhachHang.setCuoiKH(newNode);
											} else {
												danhSachKhachHang.getCuoiKH()->next = newNode;
												danhSachKhachHang.setCuoiKH(newNode);
											}
										} else {
											cerr << "Loi: Du lieu tai khoan khong hop le." << endl;
											loi = true;
											break;
										}
									} else {
										cerr << "Loi: Du lieu dia chi khong hop le." << endl;
										loi = true;
										break;
									}
								} else {
									cerr << "Loi: Du lieu CCCD khong hop le." << endl;
									loi = true;
									break;
								}
							} else {
								cerr << "Loi: Du lieu so dien thoai khong hop le." << endl;
								loi = true;
								break;
							}
						} else {
							cerr << "Loi: Du lieu tuoi khong hop le." << endl;
							loi = true;
							break;
						}
					} else {
						cerr << "Loi: Du lieu ten khach khong hop le." << endl;
						loi = true;
						break;
					}
				} else {
					cerr << "Loi: Du lieu ma khach khong hop le." << endl;
					loi = true;
					break;
				}
			}

			inFile.close();

			if (!loi) {
				cout << "Danh sach khach hang da duoc doc tu file." << endl;
			}
		} else {
			cerr << "Khong the mo file de doc." << endl;
		}
	}