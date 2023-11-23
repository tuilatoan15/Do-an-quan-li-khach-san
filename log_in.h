#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

	//DangNhap-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
	int dangNhapAdmin(){
	    string username, password;
  
			DangNhapLai1:
			cout << "Tên đăng nhập: ";
			getline(cin, username);
			cout << "Mật khẩu: ";
			getline(cin, password);

			if(username == "admin1" && password == "12345") {
				cout << "Đăng nhập thành công với tư cách Quản lí!" << endl;
				return 1;
			}
			else {
				cout << "Vui lòng kiểm tra lại tài khoản, mật khẩu!" << endl;
				goto DangNhapLai1;
			}     
	}

	int dangNhapUser() {
        string username, password;
   
			DangNhapLai2:  
			cout << "Tên đăng nhập: ";
			getline(cin, username);
			cout << "Mật khẩu: ";
			getline(cin, password);

			if(username == "user1" && password == "12345") {
				cout << "Đăng nhập thành công với tư cách Người dùng!" << endl;
				return 1;
			}
			else {
				cout << "Vui lòng kiểm tra lại tài khoản, mật khẩu!" << endl;
				goto DangNhapLai2;
			}     
	}
