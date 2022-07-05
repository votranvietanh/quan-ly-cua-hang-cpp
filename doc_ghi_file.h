#pragma once
#include "ctdl.h"
#include "chucnangphu.h"
//================== doc file ds vat tu ==============
void doc_file_ds_vat_tu(DS_VAT_TU& ds_vt)
{
	ifstream filein;
	filein.open("bandongho.txt",  ios_base::in);
	while (filein.eof() != true)
	{
		ds_vt.ds[ds_vt.sl] = new VAT_TU;
		getline(filein, ds_vt.ds[ds_vt.sl]->ma_vt, ',');
		getline(filein, ds_vt.ds[ds_vt.sl]->ten_vt, ',');
		getline(filein, ds_vt.ds[ds_vt.sl]->don_vi_tinh, ',');
		filein >> ds_vt.ds[ds_vt.sl]->so_luong_ton;
		filein.ignore();
		filein >> ds_vt.ds[ds_vt.sl]->kt;
		filein.ignore();
		ds_vt.sl++;
	}
	filein.close();
}
//====
void doc_file_ds_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	ifstream filein;
	filein.open("DSNV.txt",  ios_base::in);
	while (filein.eof() != true)
	{
		nhan_vien *x= khoi_tao_node_nhan_vien();
		filein >> x->ma_nv;
		filein.ignore();
		getline(filein, x->ho, ',');
		getline(filein, x->ten, ',');
		getline(filein, x->phai, '\n');
		them_1_nv(ds_nv.TREE,x);
		ds_nv.sl++;
	}
	filein.close();
}