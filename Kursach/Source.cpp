#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

struct InfoStudents
{
	string fio;
	int NumberOfGroup;
	float AverageScore;
	int math;
	int phy;
	int proga;
	int english;
	int DataBase;
	InfoStudents *next;
} *first, *help, *head;

int CheckEnter(bool(*Fun)(int)); //проверка на ввод с использованием указателя на функцию 605
int Avtorisation(); //выполяем авторизацию 669
int CheckNumberGroup(); //проверка на ввод группы
void CreateSpisok(); //создаём список 766
void ShowInfoOfStudents(); //Выводим информацию о студентах 791
void CloseTheProgram(); //Хотите закрыть программу? 546
void MenuAdmin(int &choice, bool &back, bool &checkexit); //Меню админа
void MenuUser(int &choice, bool &back, bool &checkexit); //Меню пользователя
void Sort(bool(*Fun)()); //Сортировка с использованием указателя на функцию 802
void InformationOnElectives(bool(*Fun)()); //информация о участниках факультатива 882
void InfAboutAllElectives(bool(*Fun)()); //информация обо всех факультативах в общем 915
void SearchGroup(); //Поиск группа 930
void SearchAverScore(); //Поиск средний балл 973
void SearchFio(); //Поиск фамилии 1014
void TheSorting(int choice2); //Cортировка 1106
void TheSearching(int choice3); //Поиск 1124
void CountOfAccounts(string acc); //колличество аккакунтов 738
void Task(int choice); //выполнение задания 1064
void WriteToFile(); //запись в файл 1142
void AddData(); //добавление данных 1155
void EditData(); //редактирование данных 1202
void DeleteData(); //удалить данные 1302
void AddAccounts(string accounts); //добавление аккаунтов 292
void EditAccounts(string acc); //редактирование аккаунтов 357
void DeleteAccount(string acc); //удаление аккаунтов 440
float CheckFloatEnter(); //проверка на ввод дробных чисел 632
string CheckFio(); //проверка на ввод фамилии
bool isCheck0and1(int choice); //проверка на ввод 0 и 1 (555)
bool isCheck1and2(int choice); //проверка на ввод 1 и 2 (562)
bool isCheck0to2(int choice); //проверка на ввод 0-2 (569)
bool isCheck0to3(int choice); //проверка на ввод 0-3 (576)
bool isCheck0to4(int choice); //проверка на ввод 0-4 (584)
bool isCheck0to6(int choice); //проверка на ввод 0-6 (591)
bool isCheck1to8(int choice); //проверка на ввод 1-8 (598)
bool isSortOfAveregeScore(); //Сортировка по среднему баллу 525
bool isSortOfGroup(); //Сортировка по группе 532
bool isSortOfFio(); //Сортировка по фио 539
bool isInfAboutMath(); //факультатив матем 847
bool isInfAboutPhy(); //факультатив физика 854
bool isInfAboutProga(); //факультатив прога 861
bool isInfAboutEnglish(); //факультатив англ 868
bool isInfAboutDataBase(); //факультатив база даных 875

const string AccOfUsers = "D://Курсовая/User.txt";
const string FileStudents = "D://Курсовая/Students.txt";
const string AccOfAdmin = "D://Курсовая/Administrator.txt";
const int RoleAdmin = 1;
const int RoleUser = 2;
const string CheckEnd = "|";
const int studfordis = 15;

string nowlogin;

void main()
{
	bool checkexit = false;
	int YourAvtorisation;
	CreateSpisok();
	do
	{
		checkexit = false;
		YourAvtorisation = Avtorisation();
		bool back = false;
		switch (YourAvtorisation) //                         ВЫБОР АВТОРИЗАЦИИ
		{
		case 1:
			back = false;
			do
			{
				back = false;
				int choice;
				cout << "\n----------------------------------Menu of Admin----------------------------------\n\t";
				cout << "What do you want to work with:\n\t1-Accounts\n\t2-Data\n\t0-Exit to main menu\n";
				choice = CheckEnter(isCheck0to2);
				MenuAdmin(choice, back, checkexit);
			} while (back);
			break;
		case 0:
			back = false;
			do
			{
				back = false;
				int choice;
				cout << "\n----------------------------------Menu of User----------------------------------\n\t1-View data;\n\t2-Task\n\t3-Sort\n\t4-Search\n\t0-Exit to main menu\n";
				choice = CheckEnter(isCheck0to4);
				MenuUser(choice, back, checkexit);
			} while (back);
		}
	} while (checkexit);
	_getch();
}

void MenuAdmin(int &choice, bool &back, bool &checkexit)
{
	switch (choice)//                                 МЕНЮ АДМИНА
	{
	case 1:
		int choice1;
		cout << "What do you want to do?\n\t1-View\n\t2-Add\n\t3-Edit\n\t4-Delete\n\t0-Exit to menu of Admin\n";
		choice1 = CheckEnter(isCheck0to4);
		switch (choice1) //работа с учётными записями
		{
		case 1:
			int choise;
			cout << "What do you want to view:\n\t1-Admins\n\t2-Users\n";
			choise = CheckEnter(isCheck1and2);
			switch (choise) //просмотреть учётную запись админа или пользователя
			{
			case 1:
				CountOfAccounts(AccOfAdmin);
				break;
			case 2:
				CountOfAccounts(AccOfUsers);
				break;
			}
			CloseTheProgram();
			back = true;
			break;
		case 2:
			int choice;
			cout << "Which account do you want to add:\n\t1-Admins\n\t2-Users\n";
			choice = CheckEnter(isCheck1and2);
			if (choice == 1)
				AddAccounts(AccOfAdmin);
			else AddAccounts(AccOfUsers);
			CloseTheProgram();
			back = true;
			break;
		case 3:
			int choose;
			cout << "Which account do you want to edit:\n\t1-Admins\n\t2-Users\n";
			choose = CheckEnter(isCheck1and2);
			if (choose == 1)
				EditAccounts(AccOfAdmin);
			else EditAccounts(AccOfUsers);
			CloseTheProgram();
			back = true;
			break;
		case 4:
			int choose1;
			cout << "Which account do you want to delete:\n\t1-Admins\n\t2-Users\n";
			choose1 = CheckEnter(isCheck1and2);
			if (choose1 == 1)
				DeleteAccount(AccOfAdmin);
			else DeleteAccount(AccOfUsers);
			CloseTheProgram();
			back = true;
			break;
		case 0:
			back = true;
			break;
		}
		break;
	case 2:
		int choise1;
		cout << "Selected mode:\n\t1-Edit mode\n\t2-Processing mode\n";
		choise1 = CheckEnter(isCheck0to2); //работа с данными
		switch (choise1)
		{
		case 1:
			int choice1;
			cout << "What do you want to do?\n\t1-View\n\t2-Add\n\t3-Edit\n\t4-Delete\n\t0-Exit to menu of Admin\n";
			choice1 = CheckEnter(isCheck0to4);
			switch (choice1) //работа в режими редактирования
			{
			case 1:
				ShowInfoOfStudents();
				CloseTheProgram();
				back = true;
				break;
			case 2:
				AddData();
				CloseTheProgram();
				back = true;
				break;
			case 3:
				EditData();
				CloseTheProgram();
				back = true;
				break;
			case 4:
				DeleteData();
				CloseTheProgram();
				back = true;
				break;
			case 0:
				back = true;
				break;
			}
			break;
		case 2:
			bool back0 = false;
			do
			{
				back0 = false;
				int choice;
				cout << "\n\t1-Task\n\t2-Sort\n\t3-Search\n\t0-Exit to menu of Admin\n";
				choice = CheckEnter(isCheck0to3);
				switch (choice) //работа в режими обработки
				{
				case 1:
					cout << "\nSelect the discipline:\n\t1-Math;\n\t2-Physics;\n\t3-Programming;\n\t4-English;\n\t5-Data Base;\n\t6-All disciplines;\n\t0-Back\n";
					int choice;
					choice = CheckEnter(isCheck0to6);
					Task(choice);
					if (choice == 0)
						back0 = true;
					CloseTheProgram();
					back = true;
					break;
				case 2:
					cout << "\nChoose type of sort:\n\t1-Averege score;\n\t2-FIO;\n\t3-Group;\n\t0-Back\n";
					int choice2;
					choice2 = CheckEnter(isCheck0to3);
					TheSorting(choice2);
					if (choice2 == 0)
						back0 = true;
					back = true;
					break;
				case 3:
					cout << "\nChoose what you will be looking for:\n\t1-Averege score;\n\t2-FIO;\n\t3-Group;\n\t0-Back\n";
					int choice3;
					choice3 = CheckEnter(isCheck0to3);
					TheSearching(choice3);
					if (choice3 == 0)
						back0 = true;
					back = true;
					break;
				case 0:
					back = true;
					break;
				}
			} while (back0);
		}
		break;
	case 0:
		checkexit = true;
		break;
	}
}

void MenuUser(int &choice, bool &back, bool &checkexit)
{
	switch (choice) //                             МЕНЮ ПОЛЬЗОВАТЕЛЯ
	{
	case 1:
		ShowInfoOfStudents();
		CloseTheProgram();
		back = true;
		break;
	case 2:
		cout << "\nSelect the discipline:\n\t1-Math;\n\t2-Physics;\n\t3-Programming;\n\t4-English;\n\t5-Data Base;\n\t6-All disciplines;\n\t0-Exit to menu of User\n";
		int choice;
		choice = CheckEnter(isCheck0to6);
		Task(choice);
		CloseTheProgram();
		back = true;
		break;
	case 3:
		cout << "\nChoose type of sort:\n\t1-Averege score;\n\t2-FIO;\n\t3-Group;\n\t0-Exit to menu of User\n";
		int choice2;
		choice2 = CheckEnter(isCheck0to3);
		TheSorting(choice2);
		back = true;
		break;
	case 4:
		cout << "\nChoose what you will be looking for:\n\t1-Averege score;\n\t2-FIO;\n\t3-Group;\n\t0-Exit to menu of User\n";
		int choice3;
		choice3 = CheckEnter(isCheck0to3);
		TheSearching(choice3);
		CloseTheProgram();
		back = true;
		break;
	case 0: checkexit = true;
		break;
	}
}

void AddAccounts(string accounts)
{
	struct Accounts
	{
		string login;
		string password;
		Accounts *next;
	} *first, *head, *help;
	ifstream fin(accounts); //открываем файл
	head = help = first = NULL;
	do
	{
		if (first == NULL)
		{
			first = new Accounts;
			head = help = first;
			first->next = NULL;
		}
		else
		{
			head = new Accounts;
			head->next = NULL;
			help->next = head;
			help = head;
		}
		fin >> head->login;
		if (head->login != CheckEnd)
			fin >> head->password;
	} while (head->login != CheckEnd);
	fin.close();
	int check;
	string EnterLogin;
	do
	{
		head = help;
		check = 0;
		cout << "Enter login: ";
		cin >> head->login;
		EnterLogin = head->login;
		head = first;
		while (head != NULL)
		{
			if (EnterLogin == head->login)
				check++;
			head = head->next;
		}
		if (check != 1)
			cout << "Login exists! Try again!\n";
	} while (check != 1);
	head = help;
	cout << "Enter password: ";
	cin >> head->password;
	head = first;
	ofstream fout(accounts);// открывает файл для записи
	while (head != NULL)
	{
		fout << head->login << endl;
		fout << head->password << endl;
		head = head->next;
	}
	fout << CheckEnd;
}

void EditAccounts(string acc)
{
	CountOfAccounts(acc);
	struct Accounts
	{
		string login;
		string password;
		Accounts *next;
	} *first, *head, *help;
	ifstream fin(acc); //открываем файл
	head = help = first = NULL;
	do
	{
		if (first == NULL)
		{
			first = new Accounts;
			head = help = first;
			first->next = NULL;
		}
		else
		{
			head = new Accounts;
			head->next = NULL;
			help->next = head;
			help = head;
		}
		fin >> head->login;
		if (head->login != CheckEnd)
			fin >> head->password;
	} while (head->login != CheckEnd);
	fin.close();
	cout << "Enter the login of the account you want to edit: ";
	string login;
	int Yes_No;
	cin >> login;
	head = first;
	bool check1 = true;
	while (head->next != NULL)
	{
		if (login == head->login)
		{
			int check = 0;
			do
			{
				cout << "Enter a new login: ";
				cin >> head->login;
				check1 = false;
				help = first;
				check = 0;
				while (help->next != NULL)
				{
					if (help->login == head->login)
						check++;
					help = help->next;
				}
				if (check == 2)
					cout << "Login exists! Try again!\n";
			} while (check != 1);
			cout << "\nDo you want to edit the password?\n\t[1-yes; 2-no]" << endl;
			Yes_No = CheckEnter(isCheck1and2);
			if (Yes_No == 1)
			{
				cout << "Enter a new password: ";
				cin >> head->password;
			}
			cout << "Editing was done successfully!!!\n";
		}
		head = head->next;
	}
	if (check1)
		cout << "Account doesn't exist!\n";
	ofstream fout(acc);// открывает файл для записи
	head = first;
	while (head->next != NULL)
	{
		fout << head->login << endl;
		fout << head->password << endl;
		head = head->next;
	}
	fout << CheckEnd;
}

void DeleteAccount(string acc)
{
	CountOfAccounts(acc);
	struct Accounts
	{
		string login;
		string password;
		Accounts *next;
	} *first, *head, *help;
	ifstream fin(acc); //открываем файл
	head = help = first = NULL;
	do
	{
		if (first == NULL)
		{
			first = new Accounts;
			head = help = first;
			first->next = NULL;
		}
		else
		{
			head = new Accounts;
			head->next = NULL;
			help->next = head;
			help = head;
		}
		fin >> head->login;
		if (head->login != CheckEnd)
			fin >> head->password;
	} while (head->login != CheckEnd);
	fin.close();
	bool check = false;
	string login;
	do
	{
		check = false;
		cout << "Enter the login of the account you want to delete: ";
		cin >> login;
		if (login == nowlogin)
		{
			check = true;
			cout << "You can't delete yourself! Try again!\n";
		}
	} while (check);
	head = first;
	bool check1 = true;
	while (head->next != NULL)
	{
		if (login == head->login)
		{
			if (head == first)
			{
				first = first->next;
				delete (head);
				head = first;
				cout << "Removal was successful!!!";
			}
			else
			{
				Accounts *temp;
				temp = first;
				while (temp->next != head)
					temp = temp->next;
				temp->next = head->next;
				delete (head);
				cout << "Removal was successful!!!";
				check1 = false;
				head = temp;
			}
		}
		head = head->next;
	}
	if (check)
		cout << "Account doesn't exist!\n";
	ofstream fout(acc);// открывает файл для записи
	head = first;
	while (head->next != NULL)
	{
		fout << head->login << endl;
		fout << head->password << endl;
		head = head->next;
	}
	fout << CheckEnd;
}

bool isSortOfAveregeScore()
{
	if (head->next->AverageScore > head->AverageScore)
		return true;
	else return false;
}

bool isSortOfGroup()
{
	if (head->next->NumberOfGroup > head->NumberOfGroup)
		return true;
	else return false;
}

bool isSortOfFio()
{
	if (head->next->fio <= head->fio)
		return true;
	else return false;
}

void CloseTheProgram()
{
	int Yes_No;
	cout << "\nDo you want to close the program?\n\t[1-yes; 2-no]" << endl;
	Yes_No = CheckEnter(isCheck1and2);
	if (Yes_No == 1)
		exit(1);
}

bool isCheck0and1(int choice)
{
	if (choice != 0 && choice != 1)
		return true;
	else return false;
}

bool isCheck1and2(int choice)
{
	if (choice != 1 && choice != 2)
		return true;
	else return false;
}

bool isCheck0to2(int choice)
{
	if (choice < 0 || choice > 2)
		return true;
	else return false;
}

bool isCheck0to3(int choice)
{
	if (choice < 0 || choice > 3)
		return true;
	else return false;
}


bool isCheck0to4(int choice)
{
	if (choice < 0 || choice > 4)
		return true;
	else return false;
}

bool isCheck0to6(int choice)
{
	if (choice < 0 || choice > 6)
		return true;
	else return false;
}

bool isCheck1to8(int choice)
{
	if (choice < 1 || choice > 8)
		return true;
	else return false;
}

int CheckEnter(bool(*Fun)(int))
{
	char input_line[13]; //вводимая строка
	int enter_number, prov; //enter_number-вводимое число
	do
	{
		prov = 0; //проверка на корректность
		cin >> input_line;
		for (int i = 0; input_line[i] != '\0'; i++)
		{
			if (input_line[i] < '0' || input_line[i] > '9')
				prov++;
		}
		if (prov == 0)
			enter_number = atoi(input_line); //переводит массив char в int
		if (Fun(enter_number))
			prov++;
		if (prov != 0)
			cout << "Try again!" << endl;
	} while (prov != 0);
	return enter_number;
}

int CheckNumberGroup()
{
	char input_line[13]; //вводимая строка
	int prov; //enter_number-вводимое число
	do
	{
		prov = 0; //проверка на корректность
		cin >> input_line;
		for (int i = 0; input_line[i] != '\0'; i++)
		{
			if (input_line[i] < '0' || input_line[i] > '9')
				prov++;
		}
		if (prov == 0)
			head->NumberOfGroup = atoi(input_line); //переводит массив char в int
		else
			prov++;
		if (head->NumberOfGroup / 100000 > 9 || head->NumberOfGroup / 100000 < 1)
			prov++;
		if (prov != 0)
			cout << "Try again!\n";
	} while (prov != 0);
	return head->NumberOfGroup;
}

float CheckFloatEnter()
{
	char InPut[13];
	float enter_number;
	int prov;
	do
	{
		prov = 0;
		int check = 0;
		cin >> InPut;
		for (int i = 0; InPut[i] != '\0'; i++)
		{
			if ((InPut[i] < '0' || InPut[i] > '9') && InPut[i] != '.')
				prov++;
			else if (InPut[i] == '.')
				check++;
		}
		if (prov == 0 && (check == 0 || check == 1))
			enter_number = atof(InPut);
		else
			prov++;
		if (enter_number > 10 || enter_number < 0)
			prov++;
		if (prov != 0)
			cout << "Try again!\n";
	} while (prov != 0);
	return enter_number;
}

int Avtorisation()
{
	string login, pass;
	int role;
	cout << "Welcome!\n";
	bool CheckAvt = true;
	do
	{
		cout << "Enter login: ";
		cin >> login;
		nowlogin = login;
		cout << "Enter password: ";
		cin >> pass;
		cout << "Choose role:\n\t1 - ADMIN\n\t2 - USER\n";
		role = CheckEnter(isCheck1and2);
		if (role == RoleAdmin)
		{
			ifstream fin(AccOfAdmin); //открываем файл
			string loginadm, passadm;
			int check = 0;
			do
			{
				fin >> loginadm;
				fin >> passadm;
				if (login == loginadm && pass == passadm)
					check++;
			} while (loginadm != CheckEnd);
			fin.close();
			if (check)
			{
				cout << "You are Admin";
				CheckAvt = false;
				return 1;
			}
			else
				cout << "Please, try again!\n";
		}
		else if (role == RoleUser)
		{
			int check = 0;
			ifstream fin(AccOfUsers); //открываем файл
			string loginuser, passuser;
			do
			{
				fin >> loginuser;
				fin >> passuser;
				if (login == loginuser && pass == passuser)
					check++;
			} while (loginuser != CheckEnd);
			fin.close();
			if (check)
			{
				cout << "You are User";
				CheckAvt = false;
				return 0;
			}
			else
				cout << "Please, try again!\n";
		}
	} while (CheckAvt);
}

void CountOfAccounts(string acc)
{
	ifstream fin(acc);
	string ReadLine;
	int NumberOfString = 0; //количество строк в файле
	do
	{
		fin >> ReadLine; //считывание строк
		if (ReadLine != CheckEnd)
			cout << ReadLine << endl;
		NumberOfString++;
	} while (ReadLine != CheckEnd);
	NumberOfString--;
	int KolvoOfAccounts = NumberOfString / 2; //количество аккаунтов в файле
	fin.close();
	cout << "Number of Accounts: " << KolvoOfAccounts << endl;
}

void CreateSpisok()
{
	ifstream fin(FileStudents);
	string ReadLine;
	int NumberOfString = 0; //количество строк в файле
	do
	{
		fin >> ReadLine; //считывание строк
		NumberOfString++;
	} while (ReadLine != CheckEnd);
	NumberOfString--;
	int KolvoOfStudents = NumberOfString / 8; //количество студентов в файле
	fin.close();
	ifstream fin2(FileStudents);
	head = new InfoStudents;
	first = head;
	while (KolvoOfStudents != 0) //заполняем список
	{
		help = new InfoStudents;
		head->next = help;
		fin2 >> head->fio;
		fin2 >> head->NumberOfGroup;
		fin2 >> head->AverageScore;
		fin2 >> head->math;
		fin2 >> head->phy;
		fin2 >> head->proga;
		fin2 >> head->english;
		fin2 >> head->DataBase;
		head = help;
		head->fio = head->fio;
		head->next = NULL;
		KolvoOfStudents--;
	}
	fin2.close();
}

void ShowInfoOfStudents()
{
	head = first;
	cout << "FIO\t\t" << "Number of group  " << "Aver. score   " << "Math  " << "Physics  " << "Proga  " << "English  " << "DataBase" << endl;
	while (head->next != NULL)
	{
		cout << head->fio << "\t   " << head->NumberOfGroup << "\t     " << head->AverageScore << "\t" << head->math << "\t" << head->phy << "\t" << head->proga << "\t" << head->english << "\t " << head->DataBase << endl;
		head = head->next;
	}
}

void Sort(bool(*Fun)())
{
	int check;
	do
	{
		check = 0;
		head = first;
		while (head->next->next != NULL)
		{
			if (Fun())
			{
				float temp;
				string tempo;
				temp = head->AverageScore;
				head->AverageScore = head->next->AverageScore;
				head->next->AverageScore = temp;
				tempo = head->fio;
				head->fio = head->next->fio;
				head->next->fio = tempo;
				temp = head->NumberOfGroup;
				head->NumberOfGroup = head->next->NumberOfGroup;
				head->next->NumberOfGroup = temp;
				temp = head->math;
				head->math = head->next->math;
				head->next->math = temp;
				temp = head->phy;
				head->phy = head->next->phy;
				head->next->phy = temp;
				temp = head->proga;
				head->proga = head->next->proga;
				head->next->proga = temp;
				temp = head->english;
				head->english = head->next->english;
				head->next->english = temp;
				temp = head->DataBase;
				head->DataBase = head->next->DataBase;
				head->next->DataBase = temp;
				check++;
			}
			head = head->next;
		}
	} while (check != 0);
	cout << "Sorting was successful!!!" << endl;
}

bool isInfAboutMath()
{
	if (head->math == 1)
		return true;
	else return false;
}

bool isInfAboutPhy()
{
	if (head->phy == 1)
		return true;
	else return false;
}

bool isInfAboutProga()
{
	if (head->proga == 1)
		return true;
	else return false;
}

bool isInfAboutEnglish()
{
	if (head->english == 1)
		return true;
	else return false;
}

bool isInfAboutDataBase()
{
	if (head->DataBase == 1)
		return true;
	else return false;
}

void InformationOnElectives(bool(*Fun)())
{
	int kolvo = 0;
	head = first;
	cout << "Students who would like to go to the electorate:\n";
	while (head->next != NULL)
	{
		if (Fun())
		{
			cout << head->fio << endl;
			kolvo++;
		}
		head = head->next;
	}
	cout << kolvo << endl;
	if (kolvo > 15)
	{
		kolvo = 0;
		head = first;
		cout << "15 students with the highest rating:\n";
		while (studfordis > kolvo)
		{
			if (Fun())
			{
				cout << head->fio << endl;
				kolvo++;
			}
			head = head->next;
		}
	}
	head = help;
}

void InfAboutAllElectives(bool(*Fun)())
{
	int kolvo = 0;
	head = first;
	while (head->next != NULL)
	{
		if (Fun())
			kolvo++;
		head = head->next;
	}
	cout << kolvo << endl;
}

void SearchGroup()
{
	head = first;
	int element;
	char enter[13];
	int prov = 0, checkTA = 0;
	cout << "Enter number of group: ";
	do
	{
		prov = 0;
		checkTA = 0;
		cin >> enter;
		if (enter[6] != '\0' || enter[0] == '0')
		{
			cout << "Try again.\n";
			prov++;
			checkTA++;
		}
		int i = 0;
		while (enter[i] != '\0')
		{
			if (enter[i] < '0' || enter[i] > '9')
				prov++;
			i++;
		}
		if (checkTA == 0 && (prov != 0 || i != 6))
		{
			cout << "Try again.\n";
			prov++;
		}
		if (prov == 0)
			element = atoi(enter);
	} while (enter[6] != '\0' || prov != 0);
	prov = 0; // проверка
	head = first;
	while (head != NULL)
	{
		if (head->NumberOfGroup == element)
			prov++;
		head = head->next;
	}
	if (prov == 0)
		cout << "Group doesn't exist!";
	else
	{
		head = first;
		cout << "FIO\t\t" << "Number of group  " << "Aver. score   " << "Math  " << "Physics  " << "Proga  " << "English  " << "DataBase" << endl;
		while (head->next != NULL)
		{
			if (element == head->NumberOfGroup)
				cout << head->fio << "\t   " << head->NumberOfGroup << "\t     " << head->AverageScore << "\t" << head->math << "\t" << head->phy << "\t" << head->proga << "\t" << head->english << "\t " << head->DataBase << endl;
			head = head->next;
		}
	}
}

void SearchAverScore()
{
	head = first;
	float part1;
	cout << "Enter the beginning of the interval: ";
	part1 = CheckFloatEnter();
	cout << "Enter the ending of the interval: ";
	float part2;
	part2 = CheckFloatEnter();
	if (part1 > part2)
	{
		float temp = part1;
		part1 = part2;
		part2 = temp;
	}
	int proverka = 0;
	while (head->next != NULL)
	{
		if (head->AverageScore >= part1 && head->AverageScore <= part2)
			proverka++;
		head = head->next;
	}
	if (proverka == 0)
		cout << "Average score dosn't exist!";
	else
	{
		head = first;
		cout << "FIO\t\t" << "Number of group  " << "Aver. score   " << "Math  " << "Physics  " << "Proga  " << "English  " << "DataBase" << endl;
		while (head->next != NULL)
		{
			if (head->AverageScore >= part1 && head->AverageScore <= part2)
				cout << head->fio << "\t   " << head->NumberOfGroup << "\t     " << head->AverageScore << "\t" << head->math << "\t" << head->phy << "\t" << head->proga << "\t" << head->english << "\t " << head->DataBase << endl;
			head = head->next;
		}
	}
}

void SearchFio()
{
	head = first;
	string letter;
	cout << "Enter FIO: ";
	cin >> letter;
	int length = letter.length();
	head = first;
	int prov = 0;
	while (head->next != NULL)
	{
		int i = 0, check = 0;
		int len;
		len = head->fio.length();
		while (i != length && i < len)
		{
			if (letter[i] != head->fio[i])
				check++;
			i++;
		}
		if (check == 0)
		{
			prov++;
			break;
		}
		head = head->next;
	}
	if (prov == 0)
		cout << "Student doesn't exist!\n";
	else
	{
		head = first;
		cout << "FIO\t\t" << "Number of group  " << "Aver. score   " << "Math  " << "Physics  " << "Proga  " << "English  " << "DataBase" << endl;
		while (head->next != NULL)
		{
			int len;
			len = head->fio.length();
			int i = 0, check = 0;
			while (i != length && i < len)
			{
				if (letter[i] != head->fio[i])
					check++;
				i++;
			}
			if (check == 0)
				cout << head->fio << "\t   " << head->NumberOfGroup << "\t     " << head->AverageScore << "\t" << head->math << "\t" << head->phy << "\t" << head->proga << "\t" << head->english << "\t " << head->DataBase << endl;
			head = head->next;
		}
	}
}

void Task(int choice)
{
	switch (choice) //     ЗАДАНИЕ
	{
	case 1:
		Sort(isSortOfAveregeScore);
		InformationOnElectives(isInfAboutMath);
		break;
	case 2:
		Sort(isSortOfAveregeScore);
		InformationOnElectives(isInfAboutPhy);
		break;
	case 3:
		Sort(isSortOfAveregeScore);
		InformationOnElectives(isInfAboutProga);
		break;
	case 4:
		Sort(isSortOfAveregeScore);
		InformationOnElectives(isInfAboutEnglish);
		break;
	case 5:
		Sort(isSortOfAveregeScore);
		InformationOnElectives(isInfAboutDataBase);
		break;
	case 6:
		Sort(isSortOfAveregeScore);
		cout << "Students who would like to go to math: ";
		InfAboutAllElectives(isInfAboutMath);
		cout << "Students who would like to go to physics: ";
		InfAboutAllElectives(isInfAboutPhy);
		cout << "Students who would like to go to programming: ";
		InfAboutAllElectives(isInfAboutProga);
		cout << "Students who would like to go to English: ";
		InfAboutAllElectives(isInfAboutEnglish);
		cout << "Students who would like to go to Data base: ";
		InfAboutAllElectives(isInfAboutDataBase);
		break;
	case 0:
		break;
	}
}

void TheSorting(int choice2)
{
	switch (choice2) //ВЫБОР СОРТИРОВКИ
	{
	case 1:
		Sort(isSortOfAveregeScore);
		break;
	case 2:
		Sort(isSortOfFio);
		break;
	case 3:
		Sort(isSortOfGroup);
		break;
	case 0:
		break;
	}
}

void TheSearching(int choice3)
{
	switch (choice3) //ВЫБОР ПОИСКА
	{
	case 1:
		SearchAverScore();
		break;
	case 2:
		SearchFio();
		break;
	case 3:
		SearchGroup();
		break;
	case 0:
		break;
	}
}

void WriteToFile()
{
	ofstream fout(FileStudents);// открывает файл для записи
	head = first;
	while (head->next != NULL)
	{
		fout << head->fio << endl << head->NumberOfGroup << endl << head->AverageScore << endl << head->math << endl << head->phy << endl << head->proga << endl << head->english << endl << head->DataBase << endl;
		head = head->next;
	}
	fout << CheckEnd;
	fout.close();
}

string CheckFio()
{
	string line;
	while (true)
	{
		int prov = 0, check = 0;
		int k = 0;
		cin >> line;
		int length = line.length();
		for (int i = 0; i < length; i++)
		{
			if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') || (line[i] == '.'))
			{
				cout << "";
				if (line[i] == '.')
					check++;
			}
			else prov++;
		}
		if (((length >= 6 && prov == 0) && check == 3) && (((line[length - 1] == '.') && (line[length - 3] == '.')) && (line[length - 5] == '.')))
			break;
		else cout << "Error!\n";
	} 
	return line;
}


void AddData()
{
	help = new InfoStudents;
	head->next = help;
	cout << "Enter FIO: ";
	head->fio = CheckFio();
	cout << "Enter group: ";
	head->NumberOfGroup = CheckNumberGroup();
	cout << "Enter average score: ";
	head->AverageScore = CheckFloatEnter();
	cout << "Does a student want to attend an elective course in mathematics?:\n\t[1 - yes; 0 - no]" << endl;
	head->math = CheckEnter(isCheck0and1);
	cout << "Does a student want to attend an elective course in physics?:\n\t[1 - yes; 0 - no]" << endl;
	head->phy = CheckEnter(isCheck0and1);
	cout << "Does a student want to attend an elective course in programming?:\n\t[1 - yes; 0 - no]" << endl;
	head->proga = CheckEnter(isCheck0and1);
	cout << "Does a student want to attend an elective course in English?:\n\t[1 - yes; 0 - no]" << endl;
	head->english = CheckEnter(isCheck0and1);
	cout << "Does a student want to attend an elective course in Data Base?:\n\t[1 - yes; 0 - no]" << endl;
	head->DataBase = CheckEnter(isCheck0and1);
	head = head->next;
	head->next = NULL;
	WriteToFile();
	cout << "The addition was successful!!!";
}

void EditData()
{
	head = first;
	string letter;
	cout << "Enter FIO: ";
	cin >> letter;
	int prov = 0;
	int c = 0;
	while (head->next != NULL)
	{
		if (letter == head->fio)
			c++;
		head = head->next;
	}
	if (c != 0)
		prov++;
	if (prov == 0)
		cout << "Student doesn't exist!\n";
	else
	{
		head = first;
		while (letter != head->fio)
		{
			head = head->next;
		}
		cout << endl << "FIO\t\t" << "Number of group  " << "Aver. score   " << "Math  " << "Physics  " << "Proga  " << "English  " << "DataBase" << endl;
		cout << head->fio << "\t   " << head->NumberOfGroup << "\t     " << head->AverageScore << "\t" << head->math << "\t" << head->phy << "\t" << head->proga << "\t" << head->english << "\t " << head->DataBase << endl << endl;
		int choice;
		cout << "What do you want to edit?\n\t1-FIO\n\t2-Number of group\n\t3-Average score\n\t4-Math\n\t5-Physics\n\t6-Programming\n\t7-English\n\t8-DataBase\n";
		choice = CheckEnter(isCheck1to8);
		switch (choice)
		{
		case 1:
			cout << head->fio << endl << "Please, enter new FIO: ";
			head->fio = CheckFio();
			break;
		case 2:
			cout << head->NumberOfGroup << endl << "Please, enter new Number of group: ";
			CheckNumberGroup();
			break;
		case 3:
			cout << head->AverageScore << endl << "Please, enter new Average score: ";
			head->AverageScore = CheckFloatEnter();
			break;
		case 4:
			cout << head->math << endl << "Please, enter new Math: ";
			head->math = CheckEnter(isCheck0and1);
			break;
		case 5:
			cout << head->phy << endl << "Please, enter new Physics: ";
			head->phy = CheckEnter(isCheck0and1);
			break;
		case 6:
			cout << head->proga << endl << "Please, enter new Programming: ";
			head->proga = CheckEnter(isCheck0and1);
			break;
		case 7:
			cout << head->english << endl << "Please, enter new English: ";
			head->english = CheckEnter(isCheck0and1);
			break;
		case 8:
			cout << head->DataBase << endl << "Please, enter new DataBase: ";
			head->DataBase = CheckEnter(isCheck0and1);
			break;
		}
		while (head->next != NULL)
		{
			head = head->next;
		}
		cout << "Editing was done successfully!!!";
	}
	WriteToFile();
}

void DeleteData()
{
	head = first;
	string letter;
	cout << "Enter FIO: ";
	cin >> letter;
	bool check = true;
	while (head->next != NULL)
	{
		if (letter == head->fio)
		{
			if (head == first)
			{
				first = first->next;
				check = false;
				delete (head);
				head = first;
			}
			else
			{
				InfoStudents *temp, *help;
				help = head->next;
				temp = first;
				while (temp->next != head)
					temp = temp->next;
				temp->next = help;
				check = false;
				delete (head);
				head = help;
			}
		}
		else
			head = head->next;
	}
	if (check)
		cout << "Student doesn't exist!\n";
	else 
		cout << "Removal was successful!!!\n";
	WriteToFile();
}