#pragma once
#include "OOP_Menu.h"
#include "Laba_3.h"

class Init
{
private:
	Menu lab2;
public:

	Init()
	{
		lab2.AddMenuItem("������ 8, 8 ���i���: ", Zadacha8);
		lab2.AddMenuItem("������ 15, 8 ���i���: ", Zadacha15);
	}
	void Show_Lab()
	{
		lab2.ShowMenu();
	}
};