#pragma once
#include"ctdl.h"
void chuan_hoa_chu(string& a)
{ // xoa khoang trong o truoc
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}

	// xoa khoang trong o giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	//Viet hoa chu dau`
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i <= a.length();i++)
		if (a[i] == ' ')
		{
			if (a[i+1] >= 97 && a[i] <= 122)
			{
				a[i+1] -= 32;
			}
		}
}
//===================
nhan_vien* khoi_tao_node_nhan_vien()
{
	nhan_vien* p = new nhan_vien;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}
////===============
void them_1_nv(tree& t, nhan_vien* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->ma_nv > t->ma_nv)
		{
			them_1_nv(t->pright, p);
		}
		else if (p->ma_nv < t->ma_nv)
		{
			them_1_nv(t->pleft, p);
		}
	}
}