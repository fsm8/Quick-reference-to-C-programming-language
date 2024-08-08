
#include <stdio.h>
//#include <conio.h>
//#include <string.h>
//#include <time.h>
//#include <stdlib.h>
//#include <inttypes.h>
//#include <Windows.h>
//#include "lib.h"
//#include <math.h>

/*
#define ONE printf("DEBUG\n")
#define TWO ONE; ONE
#define FOUR TWO; TWO

FOUR;


#define SWAP(a, b) (a^=b, b^=a, a^=b)

int a = 1, b = 2;
printf("%d %d \n", a, b);
SWAP(a, b);
printf("%d %d", a, b);

*/


int main() 
{

//uint32_t val = (val >> 16) | (val << 16);
//printf("%u \n", val);
//float fval = *(float*) &val;
//printf("%f \n", fval);

//while (1){}


    //return 0;
}

void un (void)
{
	printf("hello world\n");
}

/*

///// Компиляция

gcc main.c -E -o main.i // результат работы препроцессора
gcc main.i -S -o main.s // ассемблерный код
gcc main.s -c -o main.o // объектный код
gcc main.o    -o main.exe // исполняемый файл

gcc main.c // компиляция, создастся исполняемый файл a.exe
.\a.exe // запуск исполняемого файла


///// Библиотеки

//подключение статической библиотеки
gcc -c lib.c
ar -r libmy1.a lib.o
gcc main.c -L .\ -lmy1
.\a.exe

//подключение динамической библиотеки
gcc -c -fPIC lib.c
gcc -shared -o libmy2.dll lib.o
gcc main.c -L .\ -lmy2
.\a.exe


///// Инициализировать что-то где-то, помимо функции, нельзя!

int i;
i = 5; // warning
i = 6; // error
// main
printf("%d ", i);


///// typeof. фишка gcc. в msvs не работает

int a = 10;
typeof(a) b = 20; // b теперь того же типа, что и a (int)
printf("%d\n", b); // Выведет: 20


///// Платформонезависимая запись в переменную FFFFFFFF

unsigned int z;
z = ~0;
printf("%x ", z); // ffffffff


///// Используя переменную «a», запишем объявления для:

int a;             // Целое
int *a;            // Указатель на целое
int **a;           // Указатель на указатель на целое
int a[10];         // Массив из десяти целых
int *a[10];        // Массив из десяти указателей на целые
int (*a)[10];      // Указатель на массив из десяти целых
int (*a)(int);     // Указатель на функцию, которая берет целый аргумент и возвращает целое
int (*a[10])(int); // Массив из десяти указателей на функции, которые берут целый аргумент и возвращают целое


///// Перегрузка функций. C11. _Generic

//#define foo(X) _Generic((X), int: foo_int, char: foo_char, float: foo_float, default: foo_int)(X)

#define foo(X)          \
    _Generic((X),       \
    int: foo_int,       \
    char: foo_char,     \
    float: foo_float,   \
    default: foo_int    \
)(X)
int foo_int(int a) 
{
	//return a + 1;
	printf("%d\n", a);
}
float foo_float(float a) 
{
	//return a + 1.0;
	printf("%f\n", a);
}
char foo_char(char a) 
{
	//return a + 1;
	printf("%c\n", a);
}
///// main
foo(5.0f);
foo(5);
foo('a'); // не работает!!! выводит число заместо символа а
foo((char)'a'); // а так работает!!!


///// Выравнивание. pack (package) работает только на struct и union. Фишка gсc для совместимости с msvisual. В gnu c также есть: char ch __attribute__ (packed);

#pragma pack(push, 1) // Установим размер выравнивания в 1 байт. прагма пак
struct Foo
{
    char ch;
    short id;
    short opt;
    int value;
};
#pragma pack(pop) // Установим предыдущую настройку выравнивания

printf("%d %d %d \n", sizeof(char), sizeof(short), sizeof(int)); // 1 2 4
printf("%d ", sizeof(struct Foo)); // 12 без pack, 9 - с pack.


#pragma pack(push, 1)
struct Foo
{
    char ch;
	char id;
    unsigned int value;
};
#pragma pack(pop)
union 
{
	struct Foo fff;
	uint8_t ss[8];
}un;
un.fff.ch = 1;
un.fff.id = 2;
un.fff.value = 3;

printf("%d \n", sizeof(struct Foo));
printf("%d %d %d %d %d %d %d %d \n", un.ss[0],un.ss[1],un.ss[2],un.ss[3],un.ss[4],un.ss[5],un.ss[6],un.ss[7]); 


///// Строки

char  arr1[] = "HELLO";
char  arr4[10];
char* arr3 = "HELLO";
char* arr2[] = {"HELLO", "WORLD"}; // {"HELLO", "WORLD", NULL}; // чтобы найти конец массива указателей при их переборе в цикле
char* arr5[2];

strcpy(arr4, "HELLO");
arr1[0] = 'h';
*(arr1+1) = 'e';
arr5[0] = "wow";
arr5[1] = "cvb";

printf("%s ", arr1); // heLLO
printf("%s ", arr2[1]); // WORLD . поменять нельзя - константа
printf("%s ", arr3); // HELLO
printf("%s ", arr4); // HELLO
printf("%s ", arr5[0]); // wow

printf("%c ", arr2[0][3]); // L
printf("%c ", arr3[0]); // H
printf("%c ", *arr1); // h
printf("%c ", *(arr5[0])); // w
printf("%c ", *(*(arr5+0)+1)); // o
printf("%c ", *(*(arr5+1)+2)); // b


char string[4] = {0,};
*(string+0) = '1';
*(string+1) = '5';
*(string+2) = '9';
printf("%s", string);


char* arr[] = {"HELLO"};
printf("%zd %zd ", sizeof(arr[0]), sizeof(*arr));  // 4 4
printf("%p %p %p %p\n", &arr, &arr[0], arr+1, arr); 	  // 0061FF1C 0061FF1C 0061FF20 0061FF1C

char arr2[] = {"HELLO"};
printf("%zd %zd ", sizeof(arr2[0]), sizeof(arr2)); // 1 6
printf("%p %p %p %p", &arr2, &arr2[0], arr2+1, &arr2[1]); // 0061FF16 0061FF16 0061FF17 0061FF17

// Так, в ОЗУ STM32 лежит только адрес во flash, где находится строка, а адрес в ОЗУ пишется с flash


///// Массивы

int arr1[10] = {0, };
printf("%d ", arr1[1]);
arr1[0] = 7;
printf("%d ", arr1[0]);
*(arr1 + 1) = 5;
printf("%d ", arr1[1]);
arr[1] = '5';

int arr[5] = {'f', };
arr[4] = '\0';
printf("%s ", arr); // f
printf("%d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4] ); // 102 0 0 0 0

int arr2[10][10] = {0, };
arr2[1][1] = 5;
arr2[1][0] = 55;
printf("%d ", arr2[1][1]); // 5
printf("%d ", *arr2[1]); // 55
printf("%d ", *(*(arr2+1)+1)); // 5

int arr[5][5] = {{1, 2}, {3, 4}};
*arr[1] = 5;
printf("%d ", arr[1][0]);

int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
printf("%d ", **arr); // 1
printf("%d ", arr[1][0]); // 4
printf("%d ", *arr[1]); // 4
printf("%d ", *(*(arr+1)+0)); // 4

int matr[3][2];
int* pm = matr; // будем обращаться к массиву как к одной цепочке элементов
*(pm+3) = 123;
pm[3] = 123; // или так
printf("%d", matr[1][1]); // 123

int matr[3][2];
int (*pm)[2] = matr;
*(*(pm+1)+1) = 123;
pm[1][1] = 123;
printf("%d", matr[1][1]); // 123


///// Передача массива в функцию

// одномерного
void func (int a[], int* a1, int size)
{
	printf("%d ", a[0]); // 2
	printf("%d ", *(a+1)); // 3
	printf("%d ", *(a1+1)); // 2
	printf("%d \n", a1[0]); // 1
}
// многомерного
void func2 (int (*b)[3], int c[][3], int* d) // int b[строк][3 столбца]
{
	printf("%d ", b[0][0]); // 1
	printf("%d ", c[0][0]); // 5
	printf("%d ", *(d+0)); // 5
	//printf("%d ", d[0][0]); // нельзя!
}

int a[5] = {1, 2, 3, 4, 5};
int b[2][3] = {{1, 2}, {3, 4}};
int c[2][3] = {{5, 6}, {7, 8}};
int* d = c;

func(a+1, a, 5);
func2(b, c, d);


///// scanf

char a[11] = {0};
scanf("%9s", &a);
scanf("%[^\n]", &a);
printf("%s", a);

int a, b;
scanf("%d%d", &a, &b);
printf("%d %d", a, b);

char c;
scanf("%c", &c);
printf("%c ", c);

char c, d;
scanf("%c %c", &c, &d);
printf("%c %c", c, d);

float a;
scanf("%f", &a);
printf("%f", a);

int a;
scanf("%4d", &a);
printf("%d", a);

char f;
while(scanf("%c", &f) != EOF && f != '.')
{ printf("%c ", f); }

int f;
while(scanf("%d", &f) == 1)
{ printf("%d ", f); }

int a;
while (scanf("%d", &a) == 1 && a != 9)
{ printf("%d ", a); }


///// Структуры


// Поля структур нельзя инициализировать в глобальной области, типа: struct rect{int x;}; struct st a; a.x = 5;
// Можно только так в глобальной области: struct rect{int x; int y;} a = {-7, 5};
// Или так можно в глобальной области: struct rect{int x;}; struct rect a = {-7, 5, 12, 8};

struct st
{
	int a;
	char b[5];
	char* c;
	int d[5];
};
struct st str = {.a = 1, .b = "fo", .c = "hello", .d[0] = 7};
strcpy(str.b, "Ho");
str.c = "HELLOWWW";
printf("%d %s %s %d", str.a, str.b, str.c, str.d[0]);
struct st str2;
strcpy(str2.c, "Hollo");
printf("%d %s %s %d", str2.a, str2.b, str2.c, str2.d[0]); // 4199136  Hollo 6422280
str2 = (struct st){1, 2}; // тоже можно, хотя и странно

struct s
{
	int a:4;
	int b:4; 
	char* c;
	int d[5];
	char* e[];
};
struct s str = {.b = 7};
str.a = 5;
struct s* str2;
str2 = &str;
str2->b = 6;
(*str2).b = 4;
str.c = "hi";
str.d[0] = 2;
str.e[0] = "hellow";
printf("%d %d %s %d %s ", str.a, str.b, str.c, str.d[0], str.e[0]);

struct s
{
	int a:4;
	int b:4;
} ;
//st = {1, 2};
struct s st;
st.a = 1;
st.b = 2;
printf("%d %d ", st.a, st.b);
struct s str = {3, 4};
printf("%d %d ", str.a, str.b);
struct s str2 = {5, 6};
printf("%d %d ", str2.a, str2.b);

struct s
{
	unsigned char a: 1;
	unsigned char b: 1;
} st = {.a = 1, .b = 1};
printf("%u %u ", st.a, st.b);
printf("%zu ", sizeof(st));

// Из Linux 0.01

struct tty_struct {
	struct termios termios;
	int pgrp;
	int stopped;
	void (*write)(struct tty_struct * tty);
	struct tty_queue read_q;
	struct tty_queue write_q;
	struct tty_queue secondary;
	};

struct tty_struct tty_table[] = {
	{
		{0, OPOST | ONLCR, 0, ICANON | ECHO | ECHOCTL | ECHOKE, 0, INIT_C_CC},
		0,
		0,
		con_write,
		{0,0,0,0,""},
		{0,0,0,0,""},
		{0,0,0,0,""}
	},{
		{0, OPOST | ONLRET, B2400 | CS8, 0, 0, INIT_C_CC},
		0,
		0,
		rs_write,
		{0x3f8,0,0,0,""},
		{0x3f8,0,0,0,""},
		{0,0,0,0,""}
	},{
		{0, OPOST | ONLRET, B2400 | CS8, 0, 0, INIT_C_CC},
		0,
		0,
		rs_write,
		{0x2f8,0,0,0,""},
		{0x2f8,0,0,0,""},
		{0,0,0,0,""}
	}
};

init(tty_table[1].read_q.data);

void con_write(struct tty_struct * tty);

struct tty_queue * table_list[]={
	&tty_table[0].read_q, &tty_table[0].write_q,
	&tty_table[1].read_q, &tty_table[1].write_q,
	&tty_table[2].read_q, &tty_table[2].write_q
	};

void con_write(struct tty_struct * tty)
{
	int nr;
	char c;

	nr = CHARS(tty->write_q);
	while (nr--) {
		GETCH(tty->write_q,c);
		switch(state) {
			case 0:
				if (c>31 && c<127) {
					if (x>=columns) {
						x -= columns;
						pos -= columns<<1;
						lf();
					}
					__asm__("movb _attr,%%ah\n\t"
						"movw %%ax,%1\n\t"
						::"a" (c),"m" (*(short *)pos)
						:"ax");
					pos += 2;
					x++;
				} else if (c==27)
					state=1;
				else if (c==10 || c==11 || c==12)
					lf();
				else if (c==13)
					cr();
				else if (c==ERASE_CHAR(tty))
					del();
				else if (c==8) {
					if (x) {
						x--;
						pos -= 2;
					}
				} else if (c==9) {
					c=8-(x&7);
					x += c;
					pos += c<<1;
					if (x>columns) {
						x -= columns;
						pos -= columns<<1;
						lf();
					}
					c=9;
				}
				break;
			case 1:
				state=0;
				if (c=='[')
					state=2;
				else if (c=='E')
					gotoxy(0,y+1);
				else if (c=='M')
					ri();
				else if (c=='D')
					lf();
				else if (c=='Z')
					respond(tty);
				else if (x=='7')
					save_cur();
				else if (x=='8')
					restore_cur();
				break;
			case 2:
				for(npar=0;npar<NPAR;npar++)
					par[npar]=0;
				npar=0;
				state=3;
				if (ques=(c=='?'))
					break;
			case 3:
				if (c==';' && npar<NPAR-1) {
					npar++;
					break;
				} else if (c>='0' && c<='9') {
					par[npar]=10*par[npar]+c-'0';
					break;
				} else state=4;
			case 4:
				state=0;
				switch(c) {
					case 'G': case '`':
						if (par[0]) par[0]--;
						gotoxy(par[0],y);
						break;
					case 'A':
						if (!par[0]) par[0]++;
						gotoxy(x,y-par[0]);
						break;
					case 'B': case 'e':
						if (!par[0]) par[0]++;
						gotoxy(x,y+par[0]);
						break;
					case 'C': case 'a':
						if (!par[0]) par[0]++;
						gotoxy(x+par[0],y);
						break;
					case 'D':
						if (!par[0]) par[0]++;
						gotoxy(x-par[0],y);
						break;
					case 'E':
						if (!par[0]) par[0]++;
						gotoxy(0,y+par[0]);
						break;
					case 'F':
						if (!par[0]) par[0]++;
						gotoxy(0,y-par[0]);
						break;
					case 'd':
						if (par[0]) par[0]--;
						gotoxy(x,par[0]);
						break;
					case 'H': case 'f':
						if (par[0]) par[0]--;
						if (par[1]) par[1]--;
						gotoxy(par[1],par[0]);
						break;
					case 'J':
						csi_J(par[0]);
						break;
					case 'K':
						csi_K(par[0]);
						break;
					case 'L':
						csi_L(par[0]);
						break;
					case 'M':
						csi_M(par[0]);
						break;
					case 'P':
						csi_P(par[0]);
						break;
					case '@':
						csi_at(par[0]);
						break;
					case 'm':
						csi_m();
						break;
					case 'r':
						if (par[0]) par[0]--;
						if (!par[1]) par[1]=lines;
						if (par[0] < par[1] &&
						    par[1] <= lines) {
							top=par[0];
							bottom=par[1];
						}
						break;
					case 's':
						save_cur();
						break;
					case 'u':
						restore_cur();
						break;
				}
		}
	}
	set_cursor();
}


///// union

union un
{
	int a;
	char arr[10];
} un1;
un1.a = 0x123456;
printf("%x ", un1.a);
printf("%x ", un1.arr[0]);
printf("%x ", *(un1.arr+1));
union un* un2 = &un1;
(*un2).a = 0x7890;
printf("%x ", (*un2).arr[0]);
printf("%x ", *((*un2).arr+1));
printf("%x ", *(un2->arr+1));

union u
{
	int a;
	char b[4];
} un = {.a = 0x12345678}, un2;
un2 = un;
un2.a = 0x87654321;
printf("%x %x %x %x \n", un.b[0], un.b[1], un.b[2], un.b[3]);


struct p
{
	uint8_t age; // 33
	char first_name[1]; // 'y'
	char second_name[5]; // "Yes"
	char *last_name; // "Yeska"
};
union
{
	struct p person;
	uint8_t array[8];
} uPerson_1;

uPerson_1.person.age = 33;
uPerson_1.person.first_name[0] = 'y';
strcpy(uPerson_1.person.second_name, "Yes");
uPerson_1.person.last_name = "Yeska";

uint32_t u_data = uPerson_1.array[0];
printf("%d ", u_data); // 33
printf("%c ", uPerson_1.array[1]); // y
printf("%c ", uPerson_1.array[2]); // Y
printf("%c ", uPerson_1.array[6]); // "Yes" прописан в 5 символах. Мусор
printf("%s ", uPerson_1.person.second_name); // Yes
printf("%s ", uPerson_1.person.last_name); // Yeska


union
{
	uint8_t array[8];
	struct
	{
		uint8_t age;
		char first_name[1];
		char second_name[5];
		char *last_name;
	} prs;
} uPerson_2;


///// Структуры: функции, приведение типов

struct s
{
	int a;
	int b;
};

void func1 (struct s str)
{
	printf("%d ", str.a);
}

void func2 (struct s* str)
{
	printf("%d ", *((int*)str+1));
}

void func3 (int* c)
{
	printf("%d ", *(c+1));
}

void func4 (int d)
{
	printf("%d ", d);
}

void func5 (int e)
{
	printf("%d ", e);
}

void func6 (char* str)
{
	printf("%s ", str);
}


struct s str = {.a = 11, .b = 22};
struct s* str2 = &str;
struct s str6 = {.a = "hello", .b = "world"};

int* c = (void*)&str;
int d = str.a;
int e = *((int*)str2+1);

func1(str);
func2(&str);
func3(c);
func4(d);
func5(e);
func6(str6.b); // без &str6.b


struct rect
{
	char a:2;
	char b:3;
};
struct rect str;
str = (struct rect){1, 2}; // странно, но работает


///// Неявное приведение типов

unsigned int x = 50;
int y = -500; // 2^32 - 500
int z = y/x;
printf("%d ", z); // 85899335 неверно!

int x = 50;
int y = -500;
int z = y/x;
printf("%d ", z); // -10 верно!


void foo1(void)
{
   unsigned int a = 6;
   int b = -20;
   (a+b > 6) ? printf(">6 ") : printf("<=6 ");
}
void foo2(void)
{
   unsigned int a = 6;
   int b = -20;
   int z;
   z = a + b;
   printf("%d ", z);
}
void foo3(void)
{
   int a = 6;
   int b = -20;
   (a+b > 6) ? printf(">6 ") : printf("<=6 ");
}

foo1(); // >6 не верно
foo2(); // -14
foo3(); // <=6 верно


///// Приведение типов. Указатели

uint8_t a = 250;
int8_t b = *( (int8_t *) &a); // так нельзя
printf("%d %u \n", b, b);

uint16_t a = 0xABCD;
uint16_t b = *( (uint8_t *) &a);
printf("%x \n", b); // ab

int a = 5;
printf("%d ", a); // 5
printf("%p ", &a);
printf("%d ", *(&a)); // 5

int a = 5;
int* b;
b = (unsigned int*)&a; // ??? зачем?
*b = 7;
printf("%d ",  a);
printf("%p ", &b);
printf("%p ",  b);
printf("%p ", &a);
printf("%d ", *b);

int a = 49;
char* b = (char*)&a;
printf("%c ", *b);


В языке Cи оператор приведения типа используется для явного указания компилятору о необходимости приведения типа. 
В данном случае, когда мы приводим указатель на int к указателю на char, мы должны использовать оператор приведения типа (char *), 
чтобы явно указать, что мы хотим интерпретировать указатель на int как указатель на char.
Без оператора приведения типа компилятор может выдать предупреждение или ошибку, поскольку приведение указателей разных типов 
может привести к непредсказуемым результатам:

int a = 256;
char* b = (char*)&a;
printf("%d %d %d %d ", *(b+0), *(b+1), *(b+2), *(b+3)); // 0 1 0 0

int x = 128;
printf("%f \n", (float)x);

float y1; 
y1 = 27/5.0;
printf("%f \n", y1);

int a[5] = {127, 55};
char *b = (char*)a+1;
printf("%d %d %d %d %d %d \n", *b, *(b+1), *(b+2), *(b+3), *(b+4), *(b+5));
int f = 125;
char* g = (char*)&f;
void* e = a;
printf("%d %d %d \n", *((char*)e), *((char*)(e+1)), *((char*)(e+2)));


struct s { int a; int b; } st = {8, 9};
char* h = (void*) &st;
struct s * str;
str = &st;

char i = *((char*) str);
char ii = *((char*) str+4); // str уже адрес
char iii = *((char*) &st+4); // st не адрес, нужен &
char iiii = *((char*)&st);
//char i = *(str); // так нельзя!!!
//int* c = (void*)&str; // для примера, когда структура без указателя
//int d = str.a; // тоже

printf("%d ", h[0]); // 8
printf("%d ", i); // 8
printf("%d ", ii); // 9
printf("%d ", iii); // 9
printf("%d ", iiii); // 8


///// Находим знак вещественного числа

float x = -15.526;
printf("%d \n", sizeof(float));
printf("%d \n", sizeof(int));
printf("%f \n", x);

unsigned int* a = &x; // warning. нужно (unsigned int*)&x
printf("%x \n", *a); // - 11000001011110000110101001111111 
					//  + 01000001011110000110101001111111
unsigned int b = *a;
b = b >> 31;
printf("%x ", b); // 1 -
				  // 0 +
unsigned int c = *(unsigned int *)&x;
c >>= 31;
printf("%x \n", c);

printf("%x \n", *((uint32_t *)&x) >> 31); // 1


///// Передача float побайтово

float original = 15.625;

printf("%f \n", original); 
printf("%d \n", sizeof(float));

uint32_t float2int = *((uint32_t*) &original);

uint8_t parted_float[4] = {0, };
parted_float[0] = *((uint8_t*) &float2int+0);
parted_float[1] = *((uint8_t*) &float2int+1);
parted_float[2] = *((uint8_t*) &float2int+2);
parted_float[3] = *((uint8_t*) &float2int+3);
printf("%d %d %d %d \n", parted_float[0], parted_float[1], parted_float[2], parted_float[3]);

uint32_t int2float = *((uint32_t*) parted_float);
float originalAfterTransfer = *((float*) &int2float);
printf("%f \n", originalAfterTransfer);


///// Передача функции в функцию по указателю

void aaa (char* x)
{
	printf("%s ", x);
}
void print (void (* c) (char* y))
{
	c("hello world");
}
print(aaa);


void aaa (int x)
{
	printf("%d ", x);
}
void print (void (* c)(int y), int z)
{
	c(z);
}
print(aaa, 15);


int func (int n)
{
	printf("%d ", n);
	return n + 1;
}
int (* fp) (int);
fp = func;
fp(5);


void (* application) (void);
uint32_t address = *((uint32_t *) 0x08000000);
application = ( void (*) (void) ) address;
application();


void (* const tr[3][4]) (void) = {[0][0] = sos, [0][1] = pop}; // designated initializers . назначенные инициализаторы
tr[0][0] ();


///// TYPEDEF (стр. 569, 610 Праты)


void nnn (int x)
{
	printf("%d ", x);
}

typedef void (* newtype) (int);

void print (newtype pf) // void print (void (*pf) (int))
{
	pf(10);
}

print(nnn); // 10


// Вместо структуры по имени st можно применять тип Student (или, в других источниках, student_t, или STUDENT_t)
typedef struct st
{
	int a;
	char b;
} Student;

Student s;
s.a = 555;
printf("s.a=%d \n", s.a);

struct st d;
d.a = 55;
printf("d.a=%d \n", d.a);
printf("s.a=%d \n", s.a);

//typedef struct st { int a; } student = {0, 222}; // так нельзя!!!


// При использовании typedef для именования типа структуры дескриптор (как выше, например, st) можно не указывать
typedef struct
{
	int a;
	char b;
} Student;

Student s;
s.a = 555;
printf("s.a=%d \n", s.a);

Student d;
d.a = 55;
printf("d.a=%d \n", d.a);

// Дескриптор st необходим, если шаблон структуры используется более одного раза: struct st{};
// Иначе, можно так: struct {} str;

typedef enum
{
	GPIO_PIN_RESET = 0;
	GPIO_PIN_SET;
} GPIO_PinState;
GPIO_PinState pnst;
pnst = GPIO_PIN_RESET;


///// enum

// Ключевое слово enum позволяет создать новый тип. Константы enum имеют тип int (или как решит компилятор)
enum {one = 1, two, three = 50};
char arr[one];
printf("%d %d\n", one, two); // 1 2 50

// Первое обьявление устанавливает spectr как имя дескриптора, которое позволяет использовать enum spectr в качестве имени типа
// Второе обьявление делает color переменной этого типа
enum spectr {red, blue = 100, yellow};
enum spectr colour;
colour = blue; // 100
printf("%d \n", colour); // 100
if (colour == blue)
{
	printf("%d \n", colour+1); // 101
}

const char* colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};
enum spectrum {red, orange, yellow, green, blue, violet};
enum spectrum color;
char choice[] = "violet";
for(color = red; color <= violet; color++)
{
	if(strcmp(choice, colors[color]) == 0)
	{
		printf("%d \n", color); // 5
		break;
	}
}
switch(color)
{
	case violet: printf("switch = %d \n", color); break; // 5
}


///// Возвращение указателя из функции

int a = 5;
int* foo5 (void)
{
	return &a;
}
printf("%p ", &a);
printf("%p ", foo5());


///// Списки

struct list
{
	int value;
	struct list* next;
} *head;
struct list* p = NULL;
head = malloc(sizeof (struct list));
head->value = 100;
head->next = malloc(sizeof (struct list));
head->next->value = 200;
head->next->next = NULL;
for(p = head; p != NULL; p = p->next)
{
	printf("%d ", p->value);
}
for(head; head != NULL; head = head->next)
{
	printf("%d ", head->value);
}
free(head->next);
free(head);


struct s
{
	int a;
	int b;
	struct s* next;
};
struct s* insert_up(struct s* head, int value)
{
	struct s* new = calloc(1, sizeof(struct s));
	new->a = value;
	new->next = head;
	return new;
}
struct s* insert_end (struct s* head, int value)
{
	struct s* new = calloc(1, sizeof(struct s));
	new->a = value;
	if(head == NULL)
	{
		return new;
	}
	else{
	struct s* p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = new;
	return head;
	}
}
struct s* head = NULL;
head = insert_up(head, 100);
head = insert_end(&head, 100);


///// Двоичные деревья

typedef struct tree
{
	datatype key; // или int key
	struct tree * left;
	struct tree * right;
	struct tree * parent; / необязательное поле
} tree;

tree * tr = NULL;

void preorder (tree* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->key);
	if (root->left)
	{
		preorder(root->left);
	}
	if (root->right)
	{
		preorder(root->right);
	}
}

tr = calloc(1, sizeof(tree));
tr->key = 1;
tr->right = calloc(1, sizeof(tree));
tr->right->key = 5;

tr->left = calloc(1, sizeof(tree));
tr->left->key = 2;

tr->left->left = calloc(1, sizeof(tree));
tr->left->left->key = 3;

tr->left->right = calloc(1, sizeof(tree));
tr->left->right->key = 4;

preorder(tr); // 1 2 3 4 5


///// UTF-8

SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
char str1[] = "Привет";
printf("%s \n", str1);
printf("%4x %x %x %x %x %x %x %x\n", str1[0],\
str1[1],str1[2],str1[3],str1[4],str1[5],str1[6],str1[7]);
printf("%lu", sizeof(str1)); // 13
printf("\n");
char str2[] = "Hello";
printf("%s \n", str2);
printf("%x %x %x %x %x %x\n", str2[0],str2[1],str2[2],str2[3],str2[4],str2[5]); // ffffffd0 ffffff9f ffffffd1 ffffff80 ffffffd0 ffffffb8 ffffffd0 ffffffb2 // D0 9F	П D1 80	р
printf("%lu", sizeof(str2)); // 6


///// Перенос строки

printf("very long string \
we can remove on next string!");

const char signMessage[] = {"I AM PREDATOR,  UNSEEN COMBATANT. \
CREATED BY THE UNITED STATES DEPART"};
printf("%s", signMessage);


///// Time

struct timespec ts;
timespec_get(&ts, TIME_UTC);
char buff[100];
strftime(buff, sizeof(buff), "%D %T", gmtime(&ts.tv_sec));
printf("%s.%ld", buff, ts.tv_nsec);


///// Fizzbuzz

for (int i = 0; i < 100; i++)
{
	if (!(i % 3) && !(i % 5) && i != 0)
	{
		printf("%s \n", "FizzBuzz"); continue;
	}
	else if(!(i % 3) && i != 0)
	{
		printf("%s \n", "Fizz");
	}
	else if (!(i % 5) && i != 0)
	{
		printf("%s \n", "Buzz");
	}
	else
	{
		printf("%d \n", i);
	}
}


for (int i = 1; i <= 100; i++)
{
	//char three = !(i % 3);
	//char five = !(i % 5);
	//char three_five = three << 1 | five;
	char three_five = !(i % 5) | (!(i % 3) << 1);
	
	switch (three_five)
	{
		case 0: printf("%d \n", i); break;
		case 1: printf("%s \n", "Buzz"); break; // 5
		case 2: printf("%s \n", "Fizz"); break; // 3
		case 3: printf("%s \n", "FizzBuzz"); break; // 3 и 5
		default: break;
	}
}


#define THREE_DIV 3
#define FIVE_DIV  5
uint8_t of_three = 0;
uint8_t of_five = 0;
for (int i = 1; i <= 100; ++i) 
{     
    of_three = i % THREE_DIV;
    of_five = i % FIVE_DIV;
	
    if (of_three == 0 && of_five == 0)
        printf("FizzBuzz\n");
    else if (of_three == 0)
        printf("Fizz\n");
    else if (of_five == 0)
        printf("Buzz\n");
    else
        printf("%d\n", i);
}


///// 

int16_t a = -1;
printf("%d ", a);
printf("%x ", a);
printf("%u ", a);


///// C++

// h
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};

// cpp
Morse::Morse(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Morse::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250); 
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

// main
Morse morse(13);
morse.dot(); morse.dash();

*/
