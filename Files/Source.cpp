#include <iostream>
#include <fstream>

void copyFile(const char* in, const char* out)
{
	std::ofstream fout;
	std::ifstream fin;
	fout.open(out);
	if (!fout.is_open())
		throw "Failed to open out file";
	fin.open(in);
	if (!fin.is_open())
		throw "Failed to open in file";

	char c = fin.get();
	while (!fin.eof())
	{
		fout << c;
		c = fin.get();
	}

	fout.close();
	fin.close();
}

int main()
{
	std::ofstream fout;
	std::ifstream fin;
	//������� ���� � ������ ����������� � �����
	//fout.open("out.txt",std::ios::app);
	fout.open("out.txt");
	if (!fout.is_open())
	{
		std::cout << "Output file error" << std::endl;
		system("pause");
		return 0;
	}

	//����-����� �������� ���������� std::cout � std::cin
	//fout << "Hello file!" << std::endl;
	//fout << 22 << ' ' << 3.1415 << "=pi" << true << std::endl;

	fin.open("test.txt");
	if (!fin.is_open())
	{
		std::cout << "Input file error" << std::endl;
		system("pause");
		return 0;
	}

	char str[64];
	//��������� ����� �� ������� �������/�������� �� ����� �������
	//fin >> x;

	//������� ���� 64 �������, ���� ������, ���� ���������
	//�� ������� �� ����� �������
	fin.get(str, 64);
	std::cout << str << std::endl;
	//��� ���� ������ �������� �� ������,
	//��� ��� ������ ������� ���� ������ -- ���� ��� ��� ������ ��������
	fin.get();
	//������ ����� ���������� ������
	fin.get(str, 64);
	std::cout << str << std::endl;

	//getline ������ �� �� �����, ������ ������� ������� �� ����� ������
	//fin.getline(str, 64);
	//std::cout << str << std::endl;
	//��� ��� ���� ����� ���� ����� ������ ������ �� �����
	//fin.getline(str, 64);
	//std::cout << str << std::endl;

	fin.close();
	fout.close();

	try 
	{
		copyFile("in.txt", "out.txt");
	}
	catch(const char* errorMsg)
	{
		std::cout << errorMsg << std::endl;
	}

	system("pause");
	return 0;
}