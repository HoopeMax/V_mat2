#include <iostream>
#include <cmath>

//Нелинейное уровнение по 12 варианту(1), под пунтком а
double Fun(double);
//Производная первого порядка 
double FunDif1(double);
//Производная второго порядка 
double FunDif2(double);
//Метод Ньютона
int MetNewton(double, double);
//Метод Дихотомии
void MetDihot(double, double, double);
//Метод Хорд
int MetHord(double, double, double);
//Ввод а, b и дельты
void Input(double*, double*, double*, double*);

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, delta, X0;

	Input(&a, &b, &delta, &X0);
	MetDihot(a, b, delta);
	MetHord(a, b, delta);
	MetNewton(delta, X0);

	return 0;
}

double Fun(double X)
{
	return pow(X, 3) + 2.7 * X - 9.4;
}
double FunDif1(double X)
{
	return 3 * pow(X, 2) + 2.7;
}
double FunDif2(double X)
{
	return 6 * X;
}

int MetNewton(double del, double X0)
{
	double Fx, F1, F2, Newton, X1;

	std::cout << std::endl << "Метод Ньютона " << std::endl;

	Fx = Fun(X0);
	F1 = FunDif1(X0);
	F2 = FunDif2(X0);
	if (abs(Fx * F2) / pow(F1, 2) >= 1)
	{
		std::cout << "ОШИБКА!!!" << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}
	else
	{
		X1 = X0 - (Fx / (FunDif1(X0)));
		while (abs(X1 - X0) > del)
		{
			X0 = X1;
			Fx = Fun(X0);
			X1 = X0 - (Fx / (FunDif1(X0)));
		}
	}
	Newton = X1;
	std::cout << "Результат по решению методом Ньютона = " << Newton << std::endl;
}

int MetHord(double a, double b, double del)
{
	std::cout << std::endl << "Метод Хорд " << std::endl;

	double Fa, Fb, Fc, c = 0, Horda;
	double dx;
	Fa = Fun(a);
	Fb = Fun(b);
	if (Fa * Fb > 0)
	{
		std::cout << "ОШИБКА!!!" << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}
	else
		while (abs(b - a) > del)
		{
			c = a - ((b - a) / (Fun(b) - Fun(a))) * Fun(a);
			Fc = Fun(c);
			if (Fa * Fc < 0)
			{
				a = c;
				Fa = Fc;
			}
			else
			{
				b = c;
				Fb = Fc;
			}
		}
	dx = (b - a) / 2;
	Horda = c;
	std::cout << "Результат по решению методом Хорд = " << Horda << std::endl;
	std::cout << "F(c) = " << Fun(c) << std::endl;
	std::cout << "dx = " << dx << std::endl;
}

void MetDihot(double a, double b, double del)
{
	std::cout << std::endl << "Метод Дихотомии " << std::endl;

	double c, dx, Dihot;
	while (abs(b - a) > del)
	{
		c = (a + b) / 2;
		if (Fun(a) * Fun(c) < 0)
		{
			b = c;
		}
		else a = c;
	}
	c = (a + b) / 2;
	dx = (b - a) / 2;
	Dihot = c;
	std::cout << "Результат по решению методом Дихотомии = " << Dihot << std::endl;
	std::cout << "F(c) = " << Fun(c) << std::endl;
	std::cout << "dx = " << dx << std::endl;
}

void Input(double* a, double* b, double* delta, double* X0)
{
	std::cout << "а = ";
	std::cin >> *a;
	std::cout << "b = ";
	std::cin >> *b;
	std::cout << "delta(точность) = ";
	std::cin >> *delta;
	std::cout << "X0(нулевое приближение) = ";
	std::cin >> *X0;
}