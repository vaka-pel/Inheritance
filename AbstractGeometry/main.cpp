#include<iostream>
#include<Windows.h>
using namespace std;
namespace GEOMETRY
{
	enum Color
	{
		Red = 0x000000FF,
		Green = 0x0000FF00,
		Blue = 0x00FF0000,
		Yellow = 0x0000FFFF,
		Orange = 0x0000A5FF,
		White = 0x00FFFFFF
	};
#define SHAPE_TAKE_PARAMETERS   int start_x, int start_y, int Line_width, Color color
#define SHAPE_GIVE_PARAMETERS    start_x, start_y, Line_width, color


	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int Line_width;
	public:
		static const int MIN_START_X = 100;
		static const int MIN_START_Y = 100;
		static const int MAX_START_X = 1000;
		static const int MAX_START_Y = 600;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 16;
		static const int MIN_SIZE = 32;
		static const int MAX_SIZE = 768;

		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			//тело конструктора
			set_start_x(start_x);
			set_start_y(start_y);
			set_Line_width(Line_width);
		}
		void set_start_x(int start_x)
		{
			this->start_x = 
				start_x < MIN_START_X ? MIN_START_X :
				start_x > MAX_START_X ? MAX_START_X :
				start_x;
		}
		void set_start_y(int start_y)
		{
			this->start_y = 
				start_y < MIN_START_Y ? MIN_START_Y :
				start_y > MAX_START_Y ? MAX_START_Y :
				start_y;
		}
		void set_Line_width(int Line_width)
		{
			this->Line_width =
				Line_width < MIN_LINE_WIDTH ? MIN_LINE_WIDTH :
				Line_width > MAX_LINE_WIDTH ? MAX_LINE_WIDTH :
				Line_width;
		}
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		int get_Line_width()const
		{
			return Line_width;
		}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "ѕлощадь фигуры: " << get_area() << endl;
			cout << "ѕериметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	/*class Square :public Shape
	{
		double side;
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			this->side = side;
		}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return 4 * side;
		}
		void draw()const override
		{
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			cout << endl;
		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "ƒлинна стороны квадрата: " << get_side() << endl;
			Shape::info();
		}
	};*/
	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		void set_width(double width)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return (width + height) * 2;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); //получаем окно консоли
			HDC hdc = GetDC(hwnd);// получаем контекст устроиства дл€ окна консоли
			// DC это то на чем мы будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, color); // карандаш рисует контур
			HBRUSH hBrush = CreateSolidBrush(color); // кисть рисует заливку
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			// можно рисовать
			::Rectangle(hdc, start_x, start_y,start_x+width, start_y+height);
			// hdc, hPen, hBrush занимают ресурсы и ресурсы нужно освобождать
			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);

		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "—тороны: " << width << "x" << height << endl;
			Shape::info();
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(int side, SHAPE_TAKE_PARAMETERS) : Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
	};

}
void main()
{
	setlocale(LC_ALL, "");
	//cout << hex << Color::SomeColor << endl;

	//Shape shape;
	//Square square;
	GEOMETRY::Square square(5, 100, 100, 1, GEOMETRY::Color::Red);
	/*cout << "ƒлинна стороны квадрата: " << square.get_side() << endl;
	cout << " ѕлощадь квадрата: " << square.get_area() << endl;
	cout << "ѕериметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
	cout << "\n---------------------------------------\n" << endl;*/
	square.info();

	GEOMETRY::Rectangle rect(150, 100, 550, 100, 2, GEOMETRY::Color::Orange);
	rect.info();
	while (true)
	{
		square.draw();
		rect.draw();
	}
}