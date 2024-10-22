#include "SClient.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Сеттеры
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SClient::FSETSTRING_ClientFullName(const std::string& VARIABLE_strClientFullName)			{ this->strClientFullName = VARIABLE_strClientFullName; }
void SClient::FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber)		{ this->strClientPhoneNumber = VARIABLE_strClientPhoneNumber; }
void SClient::FSETSTRING_DateConclusionContract(const std::string& VARIABLE_strDateConclusionContract)	{ this->strDateConclusionContract = VARIABLE_strDateConclusionContract; }
void SClient::FSETSTRING_DataExpirationContract(const std::string& VARIABLE_strDataExpirationContract)	{ this->strDataExpirationContract = VARIABLE_strDataExpirationContract; }
void SClient::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile)				{ this->strPathFile = VARIABLE_strPathFile; }
void SClient::FSETDOUBLE_DebtAmount(double VARIABLE_doubleDebtAmount)					{ this->doubleDebtAmount = VARIABLE_doubleDebtAmount; }
void SClient::FSETDOUBLE_CreditАllowable(double VARIABLE_doubleCreditАllowable)				{ this->doubleCreditАllowable = VARIABLE_doubleCreditАllowable; }








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Геттеры
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
std::string SClient::FGETSTRING_ClientFullName()		const	{ return this->strClientFullName; }
std::string SClient::FGETSTRING_ClientPhoneNumber()		const	{ return this->strClientPhoneNumber; }
std::string SClient::FGETSTRING_DateConclusionContract()	const	{ return this->strDateConclusionContract; }
std::string SClient::FGETSTRING_DataExpirationContract()	const	{ return this->strDataExpirationContract; }
std::string SClient::FGETSTRING_PathFile()			const	{ return this->strPathFile; }
double SClient::FGETDOUBLE_DebtAmount()				const	{ return this->doubleDebtAmount; }
double SClient::FGETDOUBLE_CreditАllowable()			const	{ return this->doubleCreditАllowable; }








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Запись в файл
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SClient::FWriteToFile(std::ofstream& objectClass)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Открываем файл и проверяем возможные ошибки.
	// В случае неудачи бросем исключение.
	// 
	// Примечание [0]: Поменять на <try catch>
	//
	objectClass.open(this->strPathFile, std::ofstream::app);
	if (!objectClass.is_open()) // Проверяем
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////
	



	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Производим инициализацию переменных
	// 
	SetConsoleCP(1251);	// Меняем кодировку консоли для правильной записи кириллици в файл
	std::cout << "~$ Enter full name: ";						std::getline(std::cin, this->strClientFullName);		std::cout << "-------------------" << std::endl; // Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter phone number: ";						std::getline(std::cin, this->strClientPhoneNumber);		std::cout << "-------------------" << std::endl; // Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter the date of conclusion of the contract: ";		std::getline(std::cin, this->strDateConclusionContract);	std::cout << "-------------------" << std::endl; // Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter the end date of the contract: ";				std::getline(std::cin, this->strDataExpirationContract);	std::cout << "-------------------" << std::endl; // Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter the amount of debt ";					std::cin >> this->doubleDebtAmount;				std::cout << "-------------------" << std::endl;
	std::cout << "~$ Enter acceptable credit ";					std::cin >> this->doubleCreditАllowable;			std::cout << "-------------------" << std::endl;
	SetConsoleCP(866);	// Возвращаем исходную
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Запись в файл
	//
	objectClass << this->strClientFullName				<< ", "
				<< this->strClientPhoneNumber		<< ", "
				<< this->strDateConclusionContract	<< ", "
				<< this->strDataExpirationContract	<< ", "
				<< this->doubleDebtAmount		<< ", "
				<< this->doubleCreditАllowable		<< '\n';
	//
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Проверка на ошибки записи
	// 
	// Примечание [0]: Поменять на <try catch>
	//
	if (objectClass.fail())
	{
		throw std::runtime_error("Failed to write to file: " + strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////
}








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Чтение из файла
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

void SClient::FReadSymbolFromFile(std::ifstream& objectClass)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Открытие с проверкой файла для чтения
	//
	objectClass.open(this->strPathFile);
	if (!objectClass.is_open()) // Проверяем
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Читаем открытый файл
	//
	char charGetSymbolFromFile; // Переменная, для посимвольной записи из файла
	while (objectClass.get(charGetSymbolFromFile))	// Получаем символы
 	{
		std::cout << charGetSymbolFromFile;	// Выводим на экран
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////
}
