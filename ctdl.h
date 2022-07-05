#pragma once
#include <iostream>
#include <string>
#include <cstdlib>// rand , srand
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;
//============== danh sach vat tu ==============
struct vat_tu
{
	string ma_vt;
	string ten_vt;
	string hang_vt;
	string don_vi_tinh;
	float so_luong_ton;
	bool kt;//true: da duoc lap hoa don	  -   false: chua duoc lap hoa
};
typedef struct vat_tu VAT_TU;
struct ds_vat_tu
{
	VAT_TU* ds[100];
	int sl = 0;
};
typedef struct ds_vat_tu DS_VAT_TU;
//=============== danh sach chi tiet hoa don ================
struct chi_tiet_hoa_don
{
	string ma_vt;
	float so_luong;
	int don_gia;
	float VAT;//% thue
	bool trang_thai;//1: khach mua - 0: khach tra
};
typedef struct chi_tiet_hoa_don CHI_TIET_HOA_DON;
struct ds_chi_tiet_hd
{
	CHI_TIET_HOA_DON ds[20];
	int sl = 0;
};
typedef struct ds_chi_tiet_hd DS_CHI_TIET_HD;
//=============== danh sach hoa don =============
struct hoa_don
{
	//data
	string so_hd;
	string ngay_lap_hd;
	char loai;//X: xuat - N: nhap
	//dschitiet hd
	DS_CHI_TIET_HD danh_sach_chi_tiet_hd;
	//pointer
	hoa_don* pnext;
};
typedef struct hoa_don HOA_DON;
struct ds_hoa_don
{
	HOA_DON* phead = NULL;
	int sl = 0;
};
typedef struct ds_hoa_don DS_HOA_DON;
//=============== danh sach nhan vien ================
struct nhan_vien
{	
	//data
	int ma_nv;
	string ho;
	string ten;
	string phai;
	//*dshd
	DS_HOA_DON danh_sach_hd;
	//pointer
	nhan_vien* pleft;
	nhan_vien* pright;
};
typedef struct nhan_vien* tree;
struct ds_nhan_vien
{
	tree TREE = NULL;
	int sl = 0;
};
typedef struct ds_nhan_vien DS_NHAN_VIEN;