#pragma once
#include"ctdl.h"
#include <iostream>
#include <string>
#include <cstdlib>// rand , srand
#include <ctime>
#include <conio.h>
#include <fstream>
#include "chucnangphu.h"
#include "doc_ghi_file.h"
using namespace std;
void xuat_ds_vat_tu(DS_VAT_TU ds_vt);
void hieu_chinh_vt(DS_VAT_TU ds_vt);
void xoa(DS_VAT_TU& ds_vt);
int kt_trung(string a, DS_VAT_TU ds_vt);
int kt_ma_vt(string a, DS_VAT_TU ds_vt);
int kt_ma_vt(string a, DS_VAT_TU ds_vt) // kiểm tra coi mã trùng hay không
{
	for (int i = 0; i < ds_vt.sl; i++)
	{
		//kt ma vt a ton tai
		if (ds_vt.ds[i]->ma_vt == a)
		{
			//check chưa lập hóa đơn
			if (ds_vt.ds[i]->kt == false)
			{
				return i;
			}
		}
	}
	return -1;
}
void them_vat_tu(DS_VAT_TU& ds_vt);
string tao_ma_vt(DS_VAT_TU ds_vt);
void xuat_ds_vat_tu(DS_VAT_TU ds_vt)
{
	for (int i = 0; i < ds_vt.sl; i++)
	{
		cout << "\t\t============= VAT TU " << i + 1 << " =============" << endl;
		cout << "Ma vat tu: " << ds_vt.ds[i]->ma_vt << endl;
		cout << "Ten vat tu: " << ds_vt.ds[i]->ten_vt << endl;
		cout << "hang~ dong ho : " << ds_vt.ds[i]->hang_vt << endl;
		cout << "Don vi tinh: " << ds_vt.ds[i]->don_vi_tinh << endl;
		cout << "So luong ton: " << ds_vt.ds[i]->so_luong_ton << endl;
	}
}
//===============================
// nhan_vien* khoi_tao_node_nhan_vien();

void nhap_nhan_vien(DS_NHAN_VIEN& ds_nv);

// void them_1_nv(tree& t, nhan_vien* p);

int tao_ma_nv(tree t);

bool kt_ma_nv_trung(tree t, int ma);

void chuyen_cay_sang_mang(tree t, nhan_vien* ds[], int& nds);
void hoan_vi_2_nv(nhan_vien* a, nhan_vien* b);
void sap_xep_ds_nv(nhan_vien* ds[], int& nds);
void in_ds_nhan_vien(nhan_vien* ds[], int& nds);
void giai_phong_ds_nhan_vien(nhan_vien* ds[], int& nds);
//=======XOA NHAN VIEN ==
void xoa_nhan_vien(DS_NHAN_VIEN& ds_nv);
void xoa_1_nv(tree& t, int ma);
//=====HIEU CHINH
void hieu_chinh_nv(DS_NHAN_VIEN &ds_nv);
void hieu_chinh_1_nv(tree t, int ma);
//=======XUAT HOA DON ===
void lap_hoa_don(ds_nhan_vien &ds_nv);
void them_1_hd(HOA_DON &phead,HOA_DON *p);
HOA_DON *khoi_tao_node_hd();
nhan_vien *kt_ma_nv(tree t, int ma);
bool kt_trung_ma_hd(HOA_DON *phead, string ma);
void menu()
{
	DS_VAT_TU ds_vt;
	ds_nhan_vien ds_nv;
	bool kt = true;
	doc_file_ds_vat_tu(ds_vt);
	doc_file_ds_nhan_vien(ds_nv);
	while (kt == true)
	{
		system("cls");
		cout << "======================================PROJECT CUOI KY CAU TRUC GIAI THUAT - VA DU LIEU=================================\n";
		cout << "\t\t\t\t\t\t QUAN LY CUA HANG BAN DONG HO \n";
		cout << "===============================MENU===============================================MEMBERS=============================\n";
		cout << "||\t\t1.Them hang.                                   ||\t 1.Vo Tran Viet Anh  19119073" << endl;
		cout << "||\t\t2.Xuat danh sach                               ||\t 2.Tran Anh Dung     19119080" << endl;
		cout << "||\t\t3.Xoa                                          ||\t 3.Nguyen Hoang Minh 191190" << endl;
		cout << "||\t\t4.Chinh sua                                    || " << endl;
		cout << "||\t\t5.Nhap nhan vien                               ||" << endl;
		cout << "||\t\t6.Xuat danh sach nhan vien sap sep theo ho ten ||"<< endl;
		cout << "||\t\t7.Xoa nhan vien.                               ||" << endl;
		cout << "||\t\t8.Hieu chinh nhan vien                         ||" << endl;
		cout << "||\t\t9.Xuat hoa don                                 ||" << endl;
		cout << "||\t\t0. Thoat                                       ||" << endl;
		cout << "=======================================================================================================================\n";
		int luachon;
		cout << "nhap lua chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			if (ds_vt.sl == 100)
			{
				cout << "them ko thanh cong." << endl;
				system("pause");
			}
			else {
				them_vat_tu(ds_vt);
				cout << "===> them thanh cong! <===" << endl;
			}
		}
		case 2:
		{
			xuat_ds_vat_tu(ds_vt);
			system("pause");
			break;
		}
		case 3:
		{
			if (ds_vt.sl == 0)
			{
				cout << "Unsuccesfully!" << endl;
				system("pause");
			}
			else {
				xoa(ds_vt);
				break;
			}
		}
		case 4:
		{
			if (ds_vt.sl == 0)
			{
				cout << "Empty!" << endl;
				system("pause");
			}
			else {
				hieu_chinh_vt(ds_vt);
				break;
			}
		}
		case 5:
		{
			nhap_nhan_vien(ds_nv);
			break;
		}
		case 6:
		{
			nhan_vien* ds[100];
			int nds = 0;
			chuyen_cay_sang_mang(ds_nv.TREE, ds, nds);
			sap_xep_ds_nv(ds, nds);
			in_ds_nhan_vien(ds, nds);
			giai_phong_ds_nhan_vien(ds, nds);
			system("pause");
			break;
		}
		case 7: 
		{
			xoa_nhan_vien(ds_nv);
			break;
		}
		case 8 :
		{
			hieu_chinh_nv(ds_nv);
			break;
		}
		case 9:
		{
			lap_hoa_don(ds_nv);
			break;
		}
		case 0:
		{
			kt = false;
			break;

		}
		}

	}
}
void xoa(DS_VAT_TU& ds_vt)
{
	cout << "Neu vat tu da duoc lap hoa don thi khong the xoa." << endl;
	string a;
	cout << "Nhap ma hang: "; cin >> a;
	//chuan_hoa_chu(a);
	//=======================
	int vt = kt_ma_vt(a, ds_vt);
	//======== xoa ========
	//dời
	if (vt < 0)
	{
		cout << "Vat tu khong ton tai hoac da duoc lap hoa don." << endl;
		system("pause");
	}
	else
	{
		for (int i = vt; i < ds_vt.sl - 1; i++)
		{
			ds_vt.ds[i]->ma_vt = ds_vt.ds[i + 1]->ma_vt;
			ds_vt.ds[i]->ten_vt = ds_vt.ds[i + 1]->ten_vt;
			ds_vt.ds[i]->don_vi_tinh = ds_vt.ds[i + 1]->don_vi_tinh;
			ds_vt.ds[i]->so_luong_ton = ds_vt.ds[i + 1]->so_luong_ton;
			ds_vt.ds[i]->kt = ds_vt.ds[i + 1]->kt;
		}
		//giảm sl
		VAT_TU* tam = ds_vt.ds[ds_vt.sl - 1];
		ds_vt.sl--;
		cout << "Da xoa thanh cong !" << endl;
		system("pause");
	}
}

void hieu_chinh_vt(DS_VAT_TU ds_vt)
{
	string a;
	cout << "Nhap ma vat tu can hieu chinh: "; cin >> a;
	//========= kiem tra ma vt =============
	int vt = kt_ma_vt(a, ds_vt);
	if (vt < 0)
	{
		cout << "Ma khong ton tai!" << endl;
		system("pause");
	}
	else
	{
		//======== hieu chinh ==========
		cout << "Nhap ten vat tu: ";
		cin.ignore();
		getline(cin, ds_vt.ds[vt]->ten_vt);
		cout << "Nhap don vi tinh: ";
		getline(cin, ds_vt.ds[vt]->don_vi_tinh);
		cout << "So luong ton: ";
		cin>> ds_vt.ds[vt]->so_luong_ton;
		chuan_hoa_chu(ds_vt.ds[vt]->ten_vt);
		chuan_hoa_chu(ds_vt.ds[vt]->don_vi_tinh);
		cout << "===================" << endl;
		cout << "Da thay doi thong tin vat tu !" << endl;
		system("pause");
	}
}
void them_vat_tu(DS_VAT_TU& ds_vt)
{
	VAT_TU* p = new VAT_TU;
	p->ma_vt = tao_ma_vt(ds_vt);
	cin.ignore();
	cout << "Name's Watch: " ;
	getline(cin, p->ten_vt);
	cout << "Brandname's Watch: ";
	getline(cin, p->hang_vt);
	cout << "nhap don vi: " ;
	getline(cin, p->don_vi_tinh);
	cout << "SO LUONG TON KHO: ";
	cin >> p->so_luong_ton;
	//========chuan hoa chu
	chuan_hoa_chu(p->ten_vt);
	chuan_hoa_chu(p->ma_vt);
	chuan_hoa_chu(p->don_vi_tinh);
	ds_vt.ds[ds_vt.sl] = p;
	ds_vt.sl++;
}
string tao_ma_vt(DS_VAT_TU ds_vt)
{
	string a = "VA0000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung(a, ds_vt) >= 0);
	return a;
}
int kt_trung(string a, DS_VAT_TU ds_vt)
{
	for (int i = 0; i < ds_vt.sl; i++)
	{
		if (ds_vt.ds[i]->ma_vt == a)
		{
			return i;
		}
		return -1;
	}
	return -1;
}
//=================== nhap nhan vien ============

void nhap_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	nhan_vien* p = khoi_tao_node_nhan_vien();
	cin.ignore();
	cout << "Nhap ho: "; getline(cin, p->ho);
	cout << "Nhap ten: "; getline(cin, p->ten);
	cout << "Nhap phai: "; getline(cin, p->phai);
	p->ma_nv = tao_ma_nv(ds_nv.TREE);
	them_1_nv(ds_nv.TREE, p);
	ds_nv.sl++;
}
int tao_ma_nv(tree t)
{
	int ma;//100-999
	do
	{
		ma = rand() % (999 - 100 + 1) + 100;
	} while (kt_ma_nv_trung(t, ma) == true);
	return ma;
}
bool kt_ma_nv_trung(tree t, int ma)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (t->ma_nv == ma)
		{
			return 1;
		}
		else if (t->ma_nv < ma)
		{
			kt_ma_nv_trung(t->pright, ma);
		}
		else
		{
			kt_ma_nv_trung(t->pleft, ma);
		}
	}
}
//=========== xu ly nhan vien ===============
// nhan_vien* khoi_tao_node_nhan_vien()
// {
// 	nhan_vien* p = new nhan_vien;
// 	p->pleft = NULL;
// 	p->pright = NULL;
// 	return p;
// }
// void them_1_nv(tree& t, nhan_vien* p)
// {
// 	if (t == NULL)
// 	{
// 		t = p;
// 	}
// 	else
// 	{
// 		if (p->ma_nv > t->ma_nv)
// 		{
// 			them_1_nv(t->pright, p);
// 		}
// 		else if (p->ma_nv < t->ma_nv)
// 		{
// 			them_1_nv(t->pleft, p);
// 		}
// 	}
// }
//================ in danh sach nhan vien ===================
//---- chuyen cay sang mang ---------
void chuyen_cay_sang_mang(tree t, nhan_vien* ds[], int& nds)
{
	if (t != NULL)
	{
		//data
		ds[nds] = new nhan_vien;
		ds[nds]->ma_nv = t->ma_nv;
		ds[nds]->ho = t->ho;
		ds[nds]->ten = t->ten;
		ds[nds]->phai = t->phai;
		nds++;
		chuyen_cay_sang_mang(t->pleft, ds, nds);
		chuyen_cay_sang_mang(t->pright, ds, nds);
	}
}
//------ sap xep danh sach nhan vien -------
void hoan_vi_2_nv(nhan_vien* a, nhan_vien* b)
{
	nhan_vien* tam = new nhan_vien;
	tam->ma_nv = a->ma_nv;
	tam->ho = a->ho;
	tam->ten = a->ten;
	tam->phai = a->phai;
	tam->danh_sach_hd = a->danh_sach_hd;
	//---------
	a->ma_nv = b->ma_nv;
	a->ho = b->ho;
	a->ten = b->ten;
	a->phai = b->phai;
	a->danh_sach_hd = b->danh_sach_hd;
	//-----------
	b->ma_nv = tam->ma_nv;
	b->ho = tam->ho;
	b->ten = tam->ten;
	b->phai = tam->phai;
	b->danh_sach_hd = tam->danh_sach_hd;
	delete tam;
}
void sap_xep_ds_nv(nhan_vien* ds[], int& nds)
{
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (ds[i]->ten > ds[j]->ten)
			{
				hoan_vi_2_nv(ds[i], ds[j]);
			}
			else if (ds[i]->ten == ds[j]->ten)
			{
				if (ds[i]->ho > ds[j]->ho)
				{
					hoan_vi_2_nv(ds[i], ds[j]);
				}
			}
		}
	}
}
//--- in danh sach nhan vien ra -------------
void in_ds_nhan_vien(nhan_vien* ds[], int& nds)
{
	if (nds == 0)
	{
		cout << "danh sach nhan vien rong" << endl;
	}
	else {
		for (int i = 0; i < nds; i++)
		{
			cout << "\t\t======== nhan vien " << i+1 << " ========" << endl;
			cout << "\t\tMa nhan vien: " << ds[i]->ma_nv << endl;
			chuan_hoa_chu(ds[i]->ho);
			chuan_hoa_chu(ds[i]->ten);
			cout << "\t\tHo ten:" << ds[i]->ho << " " << ds[i]->ten << endl;
			chuan_hoa_chu(ds[i]->phai);
			cout << "\t\tGioi tinh: " << ds[i]->phai << endl;
		}
	}
}
//------------ giai phong ------------
void giai_phong_ds_nhan_vien(nhan_vien* ds[], int& nds)
{
	for (int i = 0; i < nds; i++)
	{
		delete ds[i];
	}
}
//================= xoa nhan vien ===============
void xoa_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	int a;
	cout << "Nhap ma nhan vien: "; cin >> a;
	bool kt = kt_ma_nv_trung(ds_nv.TREE, a);
	if (kt == true)
	{
		//xoa
		xoa_1_nv(ds_nv.TREE, a);
		ds_nv.sl--;
		cout << "Xoa Thanh Cong!" << endl;
	}
	else
	{
		cout << "Ma nhan vien khong ton tai!" << endl;
	}
	system("pause");
}
void node_the_mang(tree& t, nhan_vien*& x);
void xoa_1_nv(tree& t, int ma)
{
	if (t != NULL)
	{
		if (t->ma_nv == ma)
		{
			nhan_vien* x = t;//x se luu node can giai phong
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if (t->pright == NULL)
			{
				t = t->pleft;
			}
			else if (t->pleft != NULL && t->pright != NULL)
			{
				//tim node the mang: trai cung cay con phai
				node_the_mang(t->pright, x);
			}
			delete x;
		}
		else if (t->ma_nv < ma)
		{
			xoa_1_nv(t->pright, ma);
		}
		else if (t->ma_nv > ma)
		{
			xoa_1_nv(t->pleft, ma);
		}
	}
}
void node_the_mang(tree& t, nhan_vien*& x)
{
	if (t->pleft != NULL)
	{
		node_the_mang(t->pleft, x);
	}
	else//trai cung
	{
		hoan_vi_2_nv(t, x);
		x = t;//x se luu vi tri node nay de ty nua giai phong
		t = t->pright;
	}
}
//===== hieuchinh nhan vien
// //============= hieu chinh nhan vien ==========
void hieu_chinh_nv(DS_NHAN_VIEN& ds_nv)
{
	int a;
	cout << "Nhap ma nhan vien can hieu chinh: "; cin >> a;
	bool kt = kt_ma_nv_trung(ds_nv.TREE, a);
	if (kt == true)
	{
		hieu_chinh_1_nv(ds_nv.TREE, a);
		cout << "Da hieu chinh thong tin nhan vien" << endl;
	}
	else
	{
		cout << "Ma khong ton tai." << endl;
	}
	system("pause");
}
void hieu_chinh_1_nv(tree t, int ma)
{
	if (t != NULL)
	{
		if (t->ma_nv == ma)
		{
			cin.ignore();
			cout << "Nhap ho: "; getline(cin, t->ho);
			cout << "Nhap ten: "; getline(cin, t->ten);
			cout << "Nhap phai: "; getline(cin, t->phai);
			chuan_hoa_chu(t->ho);
			chuan_hoa_chu(t->ten);
			chuan_hoa_chu(t->phai);
		}
		else if (t->ma_nv > ma)
		{
			hieu_chinh_1_nv(t->pleft, ma);
		}
		else if (t->ma_nv < ma)
		{
			hieu_chinh_1_nv(t->pright, ma);
		}
	}
}
//================ lap hoa don ==============
string tao_ma_hd(DS_HOA_DON ds_hd);
void them_1_hd(HOA_DON *&phead, HOA_DON *p);
//==lap hoa don ==============
string tao_ma_hd(DS_HOA_DON ds_hd);
void them_1_hd(HOA_DON*& phead, HOA_DON* p);
void nhap_vt_hd(DS_SAN_PHAM& ds_vt)
{
	string a;
	cout << "Nhap ma san pham: "; cin >> a;
	int VT = kt_ma_vt(a, ds_vt);
	if (VT < 0)
	{
		cout << "san pham khong ton tai." << endl;
		system("pause");
	}
	else
	{
		for (int i = VT; i <= VT; i++)
		{
			san_pham* p = new san_pham;
			for (int i = 0; i < ds_vt.sl; i++)
			{
				//kt ma vt a ton tai
				if (ds_vt.ds[i]->ma_vt == a)
				{
					//check chưa lập hóa đơn
					if (ds_vt.ds[i]->kt == false)
					{
						p = ds_vt.ds[i];
						break;
					}
				}
			}
			cout << "SO LUONG muon mua: ";
			cin >> p->so_luong_mua;
			if (p->so_luong_ton < 1 || p->so_luong_mua < 1 || p->so_luong_mua > p->so_luong_ton)
				cout << "Khong du hang`!" << endl;
			return;
			p->so_luong_ton -= p->so_luong_mua;

		}

		system("pause");
	}
}
void lap_hoa_don(DS_NHAN_VIEN& ds_nv, DS_SAN_PHAM& ds_vt)
{
	ds_chi_tiet_hd ds_hd;
	string b;
	int a;
	cout << "Nhap ma nhan vien lap hoa don: "; cin >> a;
	nhan_vien* tam = kt_ma_nv(ds_nv.TREE, a);
	if (tam == NULL)
	{
		cout << "Ma nhan vien khong ton tai!" << endl;
	}
	else
	{
		//xu ly lap hoa don

		HOA_DON* p = khoi_tao_node_hd();
		bool nhap;
		bool ktw = true;
		while (ktw == true)
		{
			system("cls");
			cout << "1. Hoa Don nhap" << endl;
			cout << "2. Hoa don xuat" << endl;
			cout << "Nhap loai hoa don: "; int x;
			cin >> x;
			switch (x)
			{
			case 1:
			{
				cout << "Loai hoa don: Nhap" << endl;
				nhap = true;
				p->loai = 'N';
				ktw = false;
				break;
			}
			case 2:
			{
				cout << "Loai hoa don: Xuat" << endl;
				nhap = false;
				p->loai = 'X';
				ktw = false;
				break;
			}
			}
		}
		//=====

		//======================
		p->so_hd = tao_ma_hd(tam->danh_sach_hd);
		cout << "Ma hoa don: " << p->so_hd << endl;
		cin.ignore();
		cout << "Nhap ngay lap hoa don: "; getline(cin, p->ngay_lap_hd);
		//--------- them hd vao ds hoa don --------
		them_1_hd(tam->danh_sach_hd.phead, p);
		nhap_vt_hd(ds_vt);
		system("pause");
	}
}
void them_1_hd(HOA_DON *&phead, HOA_DON *p)
{
	if (phead == NULL)
	{
		phead = p;
	}
	else
	{
		for (HOA_DON *k = phead;k != NULL;k = k->pnext)
		{
			if (k->pnext == NULL)
			{
				k->pnext = p;
				break;
			}
		}
	}
}
HOA_DON *khoi_tao_node_hd()
{
	HOA_DON *p = new HOA_DON;
	p->pnext = NULL;
	return p;
}
nhan_vien *kt_ma_nv(tree t,int ma)
{
	if (t != NULL)
	{
		if (t->ma_nv == ma)
		{
			return t;
		}
		else if (t->ma_nv < ma)
		{
			kt_ma_nv(t->pright, ma);
		}
		else if (t->ma_nv > ma)
		{
			kt_ma_nv(t->pleft, ma);
		}
	}
	else
	{
		return NULL;
	}
}
bool kt_trung_ma_hd(HOA_DON *phead,string ma)
{
	for (HOA_DON *k = phead;k != NULL;k = k->pnext)
	{
		if (k->so_hd == ma)
		{
			return true;
		}
	}
	return false;
}
string tao_ma_hd(DS_HOA_DON ds_hd)
{
	string a = "HD0000";
	do
	{
		for (int i = 2;i < a.length();i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung_ma_hd(ds_hd.phead,a)==true);
	return a;
}