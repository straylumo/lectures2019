#include <iostream>

int main() 
{
	//Обычная переменная типа double
	double x = 12345.6;
	std::cout << "         x = " << x << std::endl;
	std::cout << " sizeof(x) = " << sizeof(x) << std::endl;

	//Указатель на переменную типа double
	double* px;
	//Получаем адрес переменной x и записываем в указатель px
	px = &x;
	//Значение указателя = адрес 
	std::cout << "        px = " << px << std::endl;
	//Размер указателя: 4 байта на x32 системах,
	//8 байт на x64 системах
	std::cout << "sizeof(px) = " << sizeof(px) << std::endl;
	//Разыменование указателя: получаем значение по адресу
	//(ВАЖНО: тут * -- это оператор, а не модификатор типа!)
	std::cout << "       *px = " << *px << std::endl;

	//В указатель можно записать адрес другой переменной
	double y = 4.56;
	px = &y;
	std::cout << "         y = " << y << std::endl;
	std::cout << "        px = " << px << std::endl;
	//Теперь при разыменовании мы получаем значение переменной y
	std::cout << "       *px = " << *px << std::endl;
	//Через указатель можно также и менять значение переменной
	*px = 1.23;
	std::cout << "         y = " << y << std::endl;

	//Указателья на константу: можно считывать значение по адресу,
	//но нельзя менять. Исходная переменная необязательно константна
	const double* cpx = &x;
	//Ошибка: нельзя менять значение по адресу указателя на константу
	//*cpx = 2;

	//Константный указатель: можно считывать и менять значение по адресу,
	//но сам адрес уже нельзя менять
	double* const pcx = &x;
	//Ошибка: адрес уже задан
	//pcx = &y;

	//Константный указатель на константу
	//Вообще ничего нельзя, только читать значение по адресу :)
	const double* const cpcx = &x;

	//Переменная-массив на самом деле является указателем
	//на первый элемент. Фактически, то же самое, что и
	//int* const arr;
	int arr[3] = { 1,2,3 };
	//Поскольку это указатель, то можно пробежаться по массиву
	//при помощи арифметики указателей
	//На самом деле обращение по индексу массива -- это синоним
	//для смещения указателя: a[i] == *(a+i)
	for (int i = 0; i < 3; ++i)
		std::cout << *(arr + i) << ' ';
	std::cout << std::endl;

	//А поскольку это синонимы, то такой цикл тоже валиден :)
	for (int i = 0; i < 3; ++i)
		std::cout << i[arr] << ' ';
	std::cout << std::endl;

	//Наконец, можно создавать указатели на указатели
	//Такая переменная хранит в себе адрес другого указателя
	double** ppx = &px;
	//Так устроены двумерные массивы: это просто массив указателей
	//на первые элементы одномерных строчек

	system("pause");
	return 0;
}