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

struct DanhSachKhachHang {
    NodeKH* dauKH;
    NodeKH* cuoiKH;
};

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
struct DanhSachPhong {
    Node* dau;
    Node* cuoi;
};

struct DatPhong {
    string maKhach;
    string maPhong; 
};

//protype--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
	void inDanhSachPhong();
	void timKiemPhongTheoMaPhong();
	void timKiemPhongTheoTrangThai();
	void sapXepPhongTheoMaPhong();
	void sapXepPhongTheoTrangThai();
	//Khach
	void themKhachHang();
	void suaKhachHang();
	void xoaKhachHang();
	void inThongTin1KhachHang(KhachHang kh);
	void inDSKhachHang();
	void timKiemKHTheoMaKhach();
	void timKiemKHTheoTen();
	void sapXepKHTangDanTheoTen();
	void sapXepKHGiamDanTheoTen();
	//DatPhong
	void inDanhSachPhong();
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
	
//Khai bao toan cuc
DanhSachPhong danhSachPhong;
DanhSachKhachHang danhSachKhachHang;
int SLPhong = 0, SLKhach = 0, SLDatPhong = 0;

// Viet ham
	//Cac ham kiem tra dieu kien
	// Kiểm tra tên
	bool isName(string name) {
		// Kiểm tra xem độ dài của tên có vượt quá 20 ký tự không
		if (name.length() > 20) {
			return false;
		}

		// Kiểm tra xem ký tự đầu tiên của mỗi từ có phải là chữ hoa không
		for (size_t i = 0; i < name.length(); ++i) {
			if (i == 0 || name[i - 1] == ' ') {
				if (!isupper(name[i])) {
					return false;
				}
			} else {
				if (!isalpha(name[i])) {
					return false;
				}
			}
		}

		// Nếu tất cả các điều kiện đều đúng, trả về true
		return true;
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
		return age >= 0 && age <= 100;
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

	//Phong--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// Ham kiem tra phong ton tai
	bool kiemTraPhongTonTai(string maPhong) {
		Node* hienTai = danhSachPhong.dau;
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
		if (danhSachPhong.dau == nullptr) {
			// Neu danh sach rong, dat nut moi lam ca dau va cuoi
			danhSachPhong.dau = nutMoi;
			danhSachPhong.cuoi = nutMoi;
		} else {
			// Nguoc lai, them nut moi vao cuoi danh sach va cap nhat cuoi
			danhSachPhong.cuoi->next = nutMoi;
			danhSachPhong.cuoi = nutMoi;
		}

		cout << "Phong da duoc them thanh cong!" << endl;
	}

	// Ham sua thong tin cua mot phong
	void suaPhong() {
		string maPhongCanSua;
		cout << "Nhap ma phong can sua: ";
		getline(cin, maPhongCanSua);

		// Tim phong trong danh sach
		Node* hienTai = danhSachPhong.dau;
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
		Node* hienTai = danhSachPhong.dau;
		Node* truocNo = nullptr;

		while (hienTai != nullptr) {
			if (hienTai->data.maPhong == maPhongCanXoa) {
				// Neu phong can xoa la phong dau danh sach
				if (hienTai == danhSachPhong.dau) {
					danhSachPhong.dau = hienTai->next;
				}

				// Neu phong can xoa la phong cuoi danh sach
				if (hienTai == danhSachPhong.cuoi) {
					danhSachPhong.cuoi = truocNo;
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
	void inDanhSachPhong() {
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
	void timKiemPhongTheoMaPhong() {
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
	void timKiemPhongTheoTrangThai() {
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
	void sapXepPhongTheoMaPhong() {
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
	void sapXepPhongTheoTrangThai() {
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

	//KhachHang--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		// Ham kiem tra khach hang ton tai
	bool kiemTraKhachHangTonTai(string maKhach) {
		NodeKH* hienTai = danhSachKhachHang.dauKH;
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

		if (danhSachKhachHang.dauKH == nullptr) {
			danhSachKhachHang.dauKH = nutMoi;
			danhSachKhachHang.cuoiKH = nutMoi;
		} else {
			danhSachKhachHang.cuoiKH->next = nutMoi;
			danhSachKhachHang.cuoiKH = nutMoi;
		}

		cout << "Khach hang da duoc them thanh cong!" << endl;
	}

	void suaKhachHang() {
		if (danhSachKhachHang.dauKH == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string maKhachCanSua;
		cout << "Nhap ma khach hang can sua: ";
		getline(cin, maKhachCanSua);

		NodeKH* hienTai = danhSachKhachHang.dauKH;
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
		if (danhSachKhachHang.dauKH == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string maKhachCanXoa;
		cout << "Nhap ma khach hang can xoa: ";
		getline(cin, maKhachCanXoa);

		NodeKH* hienTai = danhSachKhachHang.dauKH;
		NodeKH* truocNo = nullptr;

		while (hienTai != nullptr) {
			if (hienTai->data.maKhach == maKhachCanXoa) {
				if (hienTai == danhSachKhachHang.dauKH) {
					danhSachKhachHang.dauKH = hienTai->next;
				}

				if (hienTai == danhSachKhachHang.cuoiKH) {
					danhSachKhachHang.cuoiKH = truocNo;
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

	void inDSKhachHang() {
		if (danhSachKhachHang.dauKH == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
		cout << "|   Ma khach    |     Ten khach      | Tuoi | So dien thoai |       CCCD         |      Dia chi       |   Tai khoan   |" << endl;
		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;

		NodeKH* hienTai = danhSachKhachHang.dauKH;
		while (hienTai != nullptr) {
			inThongTin1KhachHang(hienTai->data);
			hienTai = hienTai->next;
		}

		cout << "+---------------+--------------------+------+---------------+--------------------+--------------------+---------------+" << endl;
	}

	void timKiemKHTheoMaKhach() {
		if (danhSachKhachHang.dauKH == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string maKhachCanTim;
		cout << "Nhap ma khach hang can tim: ";
		getline(cin, maKhachCanTim);

		NodeKH* hienTai = danhSachKhachHang.dauKH;
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

	void timKiemKHTheoTen() {
		// Kiểm tra danh sách khách hàng có rỗng hay không
		if (danhSachKhachHang.dauKH == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		string tenKhachCanTim;
		cout << "Nhap ten khach hang can tim: ";
		getline(cin, tenKhachCanTim);

		NodeKH* hienTai = danhSachKhachHang.dauKH;
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

	void sapXepKHTangDanTheoTen() {
		if (danhSachKhachHang.dauKH == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		cout << "Danh sach khach hang sau khi duoc sap xep tang dan theo ten: " << endl;
		NodeKH* i = danhSachKhachHang.dauKH;
		while (i != nullptr) {
			NodeKH* j = danhSachKhachHang.dauKH;
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

	void sapXepKHGiamDanTheoTen() {
		if (danhSachKhachHang.dauKH == nullptr) {
			cout << "Danh sach khach hang rong." << endl;
			return;
		}

		cout << "Danh sach khach hang sau khi duoc sap xep giam dan theo ten: " << endl;
		NodeKH* i = danhSachKhachHang.dauKH;
		while (i != nullptr) {
			NodeKH* j = danhSachKhachHang.dauKH;
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
	//DatPhong------------------------------------------------------------------------------------------------------------------------------------------
	void hienThiPhongConTrong() {
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		cout << "+---------------+---------------+---------------+---------------+" << endl;
		cout << "|   Ma phong    |  Loai phong   |   Gia phong   |  Trang thai   |" << endl;
		cout << "+---------------+---------------+---------------+---------------+" << endl;

		Node* hienTai = danhSachPhong.dau;
		while (hienTai != nullptr) {
			if (hienTai->data.trangThai) {  // Phong con trong (trang thai = true)
				inThongTin1Phong(hienTai->data);
			}
			hienTai = hienTai->next;
		}

		cout << "+---------------+---------------+---------------+---------------+" << endl;
	}

	void truTienKhachHang(string maKhach, int soTienCanTru, DanhSachKhachHang& danhSachKhachHang) {
		NodeKH* hienTai = danhSachKhachHang.dauKH;

		while (hienTai != nullptr) {
			if (hienTai->data.maKhach == maKhach) {
				if (hienTai->data.taiKhoan >= soTienCanTru) {
					hienTai->data.taiKhoan -= soTienCanTru;
					cout << "Da tru " << soTienCanTru << " VND tu tai khoan cua khach hang " << maKhach << endl;
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
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		string maPhongDat;
		cout << "Nhap ma phong muon dat: ";
		getline(cin, maPhongDat);

		Node* hienTai = danhSachPhong.dau;
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
					// Cap nhat trang thai phong
					hienTai->data.trangThai = 0;
					cout << "Dat phong thanh cong!" << endl;

					// Nhap ma khach muon dat
					string maKhachDat;
					cout << "Nhap ma khach muon dat: ";
					cin.ignore(); // Clear the newline character in the buffer
					getline(cin, maKhachDat);

					// Tru tien tu tai khoan khach hang
					truTienKhachHang(maKhachDat, hienTai->data.giaPhong, danhSachKhachHang);
					cout << "Tru tien khach hang thanh cong!" << endl;
				} else {
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
		if (danhSachPhong.dau == nullptr) {
			cout << "Danh sach phong rong." << endl;
			return;
		}

		string maPhongTra;
		cout << "Nhap ma phong muon tra: ";
		getline(cin, maPhongTra);

		Node* hienTai = danhSachPhong.dau;
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

	// doc ghi file-------------------------------------------------------------------------------------------------------------------------------
	// Ghi phòng vào file
	void ghiVaoFilePhong(const DanhSachPhong& danhSachPhong) {
		const string tenFile = "DanhSachPhong.txt";
		ofstream outFile(tenFile);

		if (outFile.is_open()) {
			Node* currentPhong = danhSachPhong.dau;
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
								if (danhSachPhong.dau == nullptr) {
									danhSachPhong.dau = newNode;
									danhSachPhong.cuoi = newNode;
								} else {
									danhSachPhong.cuoi->next = newNode;
									danhSachPhong.cuoi = newNode;
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
			NodeKH* currentKhachHang = danhSachKhachHang.dauKH;
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
											if (danhSachKhachHang.dauKH == nullptr) {
												danhSachKhachHang.dauKH = newNode;
												danhSachKhachHang.cuoiKH = newNode;
											} else {
												danhSachKhachHang.cuoiKH->next = newNode;
												danhSachKhachHang.cuoiKH = newNode;
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
					inDanhSachPhong();
					system("pause");
					break;
				case 5:
					timKiemPhongTheoMaPhong();
					system("pause");
					break;
				case 6:
					timKiemPhongTheoTrangThai();
					system("pause");
					break;
				case 7:
					sapXepPhongTheoMaPhong();
					system("pause");
					break;
				case 8:
					sapXepPhongTheoTrangThai();
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
					inDSKhachHang();
					system("pause");
					break;
				case 5:
					timKiemKHTheoMaKhach();
					system("pause");
					break;
				case 6:
					timKiemKHTheoTen();
					system("pause");
					break;
				case 7:
					sapXepKHTangDanTheoTen();
					system("pause");
					break;
				case 8:
					sapXepKHGiamDanTheoTen();
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
					inDanhSachPhong();
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
			cout << "| 4. Doc Danh sach phong tu File         |" << endl;
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

int main() {
	menuDangNhap();
	return 0;
}