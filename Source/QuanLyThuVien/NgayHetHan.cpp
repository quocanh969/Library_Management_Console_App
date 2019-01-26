#include<stdio.h>
#include"library.h"
int k = 0;//bien k kiem tra tinh tre han;
int NgayTrongThang(int thang, int nam)
{
	//xuat ra trong thang co bao nhieu ngay
	switch (thang)
	{
	case 1:case 3:case 5:case 7:case 8: case 10: case 12: return 31;
	case 4:case 6: case 9: case 11: return 30;
	case 2:
		{
			if (nam % 4 == 0)return 29;
			else return 28;
		}
	
	}
}
int KiemTraTinhDungSaiCuaNgay(int ngay, int thang, int nam)
{//ham kiem tra la ban da nhap ngay dung chua, neu chua thi se yeu cau nhap lai, tat nhien la doi voi nhung nguoi nhap ngay bang chu thi se bao loi
	if (ngay <= 0 || ngay > NgayTrongThang(thang, nam))return 0;
	if (thang < 1 || thang>12)return 0;
	if (nam <= 0)return 0;
	return 1;
}
void XuatNgayHetHan(int ngay, int thang,int nam)
{//ham xuat ra ngay het han cua the thu vien ke sau khi nguoi dung lap
	printf("==> ngay het han la: %d/%d/%d", ngay, thang, nam+4);
}
void XuatNgayTraDuKien(int ngay, int thang, int nam)
{//ham xuat ra ngay tra du kien khi nguoi dung bat dau muon sach
	int ngay1, thang1, nam1;
	if (7 + ngay >= NgayTrongThang(thang , nam))
	{
		ngay1 = 7 + ngay - NgayTrongThang(thang, nam) ;
		thang1 = thang + 1;
		nam1 = nam;
		if (thang1 > 12)
		{
			thang1 = thang1 - 12;
			nam1 = nam + 1;
		}
	}
	else
	{
		ngay1 =  7+ ngay;
		thang1 = thang;
		nam1 = nam;
	}
	printf("==> ngay tre han la: %d/%d/%d", ngay1, thang1, nam1);
}
int KiemTraNgayTreHan(int ngaymuon, int thangmuon, int nammuon,int ngaytra,int thagntra,int namtra)
{//ham kiem tra xem nguoi dung tra sach co dung thoi han chua, neu chua thi se phai dong phat
	int ngay;
	if (ngaytra - ngaymuon < 0)
	{
		ngay = ngaytra + NgayTrongThang(thangmuon, nammuon) - ngaymuon;
	}
	else ngay = ngaytra - ngaymuon;
	if (ngay > 7)
	{
		printf("\nban can phai dong tien phat vi tra sach tre han\nso tien can phai dong la: %d", (ngay - 7) * 5000);
		return 1;
	}
	else
	{
		printf("\nban da tra sach dung han");
		return 0;
	}
}