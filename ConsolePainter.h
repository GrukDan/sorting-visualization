#pragma once

#include "Main.h"

class ConsolePainter {
private:
	HWND hwnd;
	HDC hdc;
	HPEN p1, p2;
	HBRUSH b1, b2;
	char Title[1024];
	int width;//width of the column
	int height;//height of the column
public:
	ConsolePainter(int width,int height):
		width(width),
		height(height){
		GetConsoleTitle(Title, 1024);
		hwnd = FindWindow(NULL, Title); 
		hdc = GetDC(hwnd);   
		p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); 
		b1, b2 = CreateSolidBrush(RGB(0, 255, 0)); 
	}
	~ConsolePainter() {
		ReleaseDC(hwnd, hdc);    // ����������� �������� ���������
		DeleteObject(p2);       // ������� ��������� ����
		DeleteObject(b2);       // ������� ��������� �����
	}
	template<typename T>  void draw(T* arr,int size);
};



template<typename T>
inline void ConsolePainter::draw(T * arr, int size)
{
	clear_screen();

	p1 = (HPEN)SelectObject(hdc, p2);  // ������� ������� ���� � �������� ���������
	b1 = (HBRUSH)SelectObject(hdc, b2);    // ������� ����� � �������� ���������

	for (int i = 0; i < size; i++) {
		Rectangle(hdc, i*width, height, i * width + width, arr[i] + height);
	}

	SelectObject(hdc, p1);   // ���������� ������ ����
	SelectObject(hdc, b1);   // ���������� ������ �����
}
