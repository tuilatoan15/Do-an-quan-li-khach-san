#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

	//Cac ham kiem tra dieu kien
	// Kiểm tra tên
	bool isName(string name) {
		if (name.length() < 5 || name.length() > 20 || isspace(name.front()) || isspace(name.back()))
			return false;

		bool isFirstChar = true; // Đánh dấu ký tự đầu tiên của từ
		for (size_t i = 0; i < name.length(); ++i) {
			if (!isalpha(name[i]) && name[i] != ' ')
				return false;

			if (isalpha(name[i])) {
				if (isFirstChar && !isupper(name[i]))
					return false; // Ký tự đầu tiên của từ không phải là in hoa

				isFirstChar = false; // Đánh dấu là đã đi qua ký tự đầu tiên
			}
		return true;
		}
	}

	// Kiểm tra mã
	bool isCode(string code) {
		if (code.length() != 5) {
			return false;
		}

		if (!isupper(code[0]) || !isupper(code[1])) {
			return false;
		}

		for (char c : code.substr(2)) {
			if (!isdigit(c)) {
				return false;
			}
		}

		return true;
	}

	// Kiểm tra tuổi
	bool isAge(int age) {
		return age >= 18 && age <= 100;
	}

	// Kiểm tra số điện thoại
	bool isSDT(string sdt) {
		if (sdt.length() != 10 || sdt[0] != '0') {
			return false;
		}

		for (char c : sdt.substr(1)) {
			if (!isdigit(c)) {
				return false;
			}
		}

		return true;
	}

	// Kiểm tra CCCD
	bool isCCCD(string cccd) {
		return cccd.length() == 12 && isdigit(cccd[0]);
	}

	// Kiểm tra tài khoản
	bool isTaiKhoan(int taiKhoan) {
		return taiKhoan > 100000;
	}

	bool isLoaiPhong(int loaiPhong) {
		return loaiPhong == 0 || loaiPhong == 1;
	}

	// Kiểm tra trạng thái phòng (0 hoặc 1)
	bool isTrangThai(int trangThai) {
		return trangThai == 0 || trangThai == 1;
	}