#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"library.h"
void main()
{
	//ham nhap thong tin
	//The doc gia
	
	//The sach

	//ham chay chuong trinh
	int a,n,x,y,m,tmp=0,tnq=0;//bien tmp la so doc gia, bien tnq la so quyen sach(bao gom nhieu sach cung mot tua de)
flag:
	GanGiaTriTamp(tnq);//sau moi lan thay doi so doc gia va so sach thi t gan lai lan nua bien tamp va bien DG trong source PhieuMuonTraSach
	GanGiaTri(tmp,tnq);
	flag30:
	system("cls");
	MenuChinh();
	scanf("%d", &a);
	if (a < 1 || a>6)
	{
		printf("khong ton tai lenh do");
		system("cls");
		goto flag;
	}
	switch (a)
	{
	case 1://Quan ly doc gia
	{
	flag6:;
		system("cls");
		Menu1();
		scanf("%d%*c", &x);//%*c bo qua ki tu \n trong scanf de su dung gets_s
		if (x==1)//Xem danh sach doc gia
			{
			if (tmp == 0)
			{
				system("cls");//neu nhu thu vien chua co danh sach doc gia thi se yeu cau nguoi dung nhap vao
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			else
			{
				system("cls");
				XemDanhSachTatCaDocGia(tmp);
			}
				_getch();
				goto flag6;
			}
		else if (x==2)//Them doc gia
			{
			system("cls");
				tmp = ThemDocGia();
				goto flag6;
			}
		else if (x == 3)//Sua thong tin doc gia
			{
			if (tmp == 0)
			{
				system("cls");
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			else
			{
				system("cls");//o moi doc gia thi thu vien se danh dau so thu tu cua doc gia, nen xem qua de nguoi dung co the biet so thu tu cua doc gia can tim
				printf("\nban nen xem thong danh sach tat ca doc gia,\n sau do chon so thu tu cua doc gia ma minh dinh sua\nnhap 1 de quay lai xem thong tin, neu ban nho roi thi nhap mot so bat ki");
				scanf("%d", &n);if (n == 1)goto flag6;
			flag3:;
				printf("\nnhap so thu tu cua doc gia ma ban muon sua thong tin: ");scanf("%d", &m);
				if (m<0 || m>tmp)
				{
					printf("\nkhong ton tai doc gia thu %d trong danh sach", m);
					printf("\nban hay nhap lai lua chon cua minh");
					_getch();
					goto flag3;
				}
				system("cls");
			flag4:;
				MenuChonThongTin();
				scanf("%d%*c", &n);//n la lua chon phan thong tin can sua
				if (n < 0 || n>8)
				{
					printf("\nkhong ton tai lua chon %d trong menu chon thong tin can sua", n);
					printf("\nban hay nhap lai lua chon cua minh");
					_getch();
					goto flag4;
				}
				if (n == 9)goto flag6;
				system("cls");
				SuaThongTin(n, m);
			}
			_getch();
			goto flag6;
			}
		else if (x == 4)//Xoa thong tin doc gia
			{
			if (tmp == 0)
			{
				system("cls");
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			else
			{
				system("cls");//Xoa het tat ca thong tin cua doc gia duoc chon
				printf("\nban nen xem thong danh sach tat ca doc gia,\n sau do chon so thu tu cua doc gia ma minh dinh sua\nnhap 1 de quay lai, nhap mot phim bat ky neu ban da biet so thu tu cua doc gia: ");
				scanf("%d", &n);if (n == 1)goto flag6;
			flag5:;
				printf("\nnhap so thu tu cua doc gia ma ban muon xoa thong tin: ");scanf("%d", &m);
				if (m<0 || m>tmp)
				{
					printf("\nkhong ton tai doc gia thu %d trong danh sach", m);
					printf("\nban hay nhap lai lua chon cua minh");
					_getch();
					goto flag5;
				}
				_getch();
				system("cls");
					tmp=XoaThongTin(m);
			}
				_getch();
				goto flag6;
			}
		else if (x == 5)//Tim kiem doc gia theo CMND
			{
			if (tmp == 0)
			{
				system("cls");
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			else
			{
				system("cls");
				TimDocGiaTheoCMND();
			}
				_getch();
				goto flag6;
			}
		else if (x == 6)//Tim kiem doc gia theo ten
				//ban co the nhap ten gan dung hoac khong can nhap het ho ten van tim duoc doc gia, hoac co the tim duoc nhieu doc gia
			{
			if (tmp == 0)
			{
				system("cls");
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			else
			{
				system("cls");
				char TenTim[20];
				printf("\nnhap ten can tim: ");
				gets_s(TenTim);
				TimDocGiaTheoTen(TenTim);
			}
				_getch();
				goto flag6;
			}
		else if (x == 7)goto flag;
		else
			{
			system("cls");
				printf("\nkhong ton tai lua chon do");
				goto flag;
			}
		}
		case 2:
		{
		flag7:;
			system("cls");
			Menu2();
			scanf("%d%*c", &y);
			if (y == 1)
			{
				if (tnq == 0)
				{
					system("cls");//neu thu vien chua co danh sach sach thi se yeu cau nguoi dung nhap vao
					printf("\nhien van chua co sach trong danh sach, vui long them sach");
					goto flag7;
				}
				else
				{
					system("cls");
					int i;
					XemDanhSachTatCaSach(tnq);
				}
				_getch();
				goto flag7;
			}
			else if (y == 2)
			{
				system("cls");
				tnq = ThemSach();
				goto flag7;
			}
			else if (y == 3)
			{
				system("cls");
				if (tnq == 0)
				{
					system("cls");
					printf("\nhien van chua co sach trong danh sach, vui long them sach");
					goto flag7;
				}
				else
				{
					system("cls");
					printf("\nban nen xem thong danh sach sach,\n sau do chon so thu tu cua sach ma minh dinh sua\nnhap 1 de quay lai, neu ban da nho thi an mot so bat ki");
					scanf("%d", &n);if (n == 1)goto flag7;
				flag11:;
					printf("\nnhap so thu tu cua sach ma ban muon sua thong tin: ");scanf("%d", &m);
					if (m<0 || m>tnq)
					{
						printf("\nkhong ton tai sach thu %d trong danh sach", m);
						printf("\nban hay nhap lai lua chon cua minh");
						_getch();
						goto flag11;
					}
					_getch();
					system("cls");
				flag12:;
					MenuChonThongTinSach();
					scanf("%d%*c", &n);//n la lua chon thong tin can sua
					system("cls");
					if (n < 0 || n>8)
					{
						printf("\nkhong ton tai lua chon %d trong menu chon thong tin can sua", n);
						printf("\nban hay nhap lai lua chon cua minh");
						_getch();
						goto flag12;
						system("cls");
					}
					if (n == 0)goto flag7;
					SuaThongTinSach(n, m);
				}
				_getch();
				goto flag7;
			}
			else if (y == 4)
			{
				if (tnq == 0)
				{
					system("cls");
					printf("\nhien van chua co sach trong danh sach, vui long them sach");
					goto flag7;
				}
				else
				{
					system("cls");
					printf("\nban nen xem thong danh sach tat ca sach,\n sau do chon so thu tu cua sach ma minh dinh sua\nnhap 1 de quay lai, neu ban da nho thi an mot so bat ki");
					scanf("%d", &n);if (n == 1)goto flag7;
				flag19:;
					printf("\nnhap so thu tu cua sach ma ban muon sua thong tin: ");scanf("%d", &m);
					if (m<0 || m>tnq)
					{
						printf("\nkhong ton tai sach thu %d trong danh sach", m);
						printf("\nban hay nhap lai lua chon cua minh");
						_getch();
						goto flag19;
					}
					system("cls");
					tnq=XoaSach(m);
				}
				_getch();
				goto flag7;
			}
			else if (y == 5)
			{
				if (tnq == 0)
				{
					system("cls");
					printf("\nhien van chua co sach trong danh sach, vui long them sach");
					goto flag7;
				}
				else
				{
					system("cls");
					TimKiemSachTheoISBN();
				}
				_getch();
				goto flag7;
			}
			else if (y == 6)
				{
				if (tnq == 0)
				{	
					system("cls");
					printf("\nhien van chua co sach trong danh sach, vui long them sach");
					goto flag7;
				}
				else
				{
					system("cls");
					char TenTim[20];
					printf("\nnhap ten can tim: ");
					gets_s(TenTim);
					TimKiemSachTheoTen(TenTim);
					//neu ban khong nho ro ten hay nho chut chut thi cu thu nhap vao o tim kiem, vi thu vien duoc ho tro cong cu tim kiem nhung ten co lien quan
				}
					_getch();
					goto flag7;
				}
			else if (y == 7)goto flag;
			else
			{
				system("cls");
				printf("\nkhong ton tai lua chon do");
				goto flag;
			}
		}
		case 3:
		{
			if (tmp == 0)
			{
				system("cls");
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			if (tnq == 0)
			{
				system("cls");
				printf("\nhien van chua co sach trong danh sach, vui long them sach");
				goto flag7;
			}
			system("cls");
			printf("\nNGUOI DUNG SAU KHI MUON SACH THI PHAI TRA HET SACH ROI MOI DUOC MUON QUYEN KHAC");
			_getch();
			int o;
			o=PhieuMuonSach(tmp, tnq);//o la bien kiem tra xem doc gia da tra het sach chua
			if (o == 0) goto flag;
			system("cls");
			DanhSachISBNMuon(tmp, tnq);
			_getch();
			goto flag30;
		}
		case 4:
		{
			if (tmp == 0)
			{
				system("cls");
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			if (tnq == 0)
			{
				system("cls");
				printf("\nhien van chua co sach trong danh sach, vui long them sach");
				goto flag7;
			}
			system("cls");
			//printf("\nmoi lan chi tra duoc mot quyen sach de nham dam bao tinh minh bach va ky luong trong khau kiem soat,\nmong ban thong cam");
			PhieuTraSach(tmp,tnq);
			_getch();
			goto flag30;
		}
		case 5:
		{
			if (tmp == 0)
			{
				system("cls");
				printf("\nhien van chua co doc gia trong danh sach, vui long them doc gia");
				_getch();
				goto flag6;
			}
			if (tnq == 0)
			{
				system("cls");
				printf("\nhien van chua co sach trong danh sach, vui long them sach");
				goto flag7;
			}
		flag31:;
			system("cls");
			MenuThongKe();
			scanf("%d%*c", &n);
			system("cls");
			if (n == 1)
			{
				printf("\nco tat ca %d quyen sach trong thu vien", SoSachCoTrongThuVien());
				_getch();
				goto flag31;
			}
			else if (n == 2)
			{
				SachTheoTheLoai();
				_getch();
				goto flag31;
			}
			else if (n == 3)
			{
				printf("\nco tat ca %d doc gia tham gia", tmp);
				_getch();
				goto flag31;
			}
			else if (n == 4)
			{
				DocGiaTheoGioiTinh();
				_getch();
				goto flag31;
			}
			else if (n == 5)
			{
				printf("\nco tat ca %d sach dang duoc muon", SachDuocMuon(tmp, tnq));
				_getch();
				goto flag31;
			}
			else if (n == 6)
			{
				NguoiTreHan(tmp);
				_getch();
				goto flag31;
			}
			else if (n == 7)
			{
				goto flag30;
			}
			else
			{
				printf("\nkhong ton tai len do, vui long nhap lai");
				_getch();
				goto flag31;
			}
		}
		case 6:
		{
			goto end;
		}
}
end:;
}