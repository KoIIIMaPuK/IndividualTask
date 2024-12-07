#include "SClient.h"

/**
 * @brief Устанавливает имя клиента
 * 
 * @param VARIABLE_strClientFullName Имя клиента
 */
void SClient::FSETSTRING_ClientFullName(const std::string& VARIABLE_strClientFullName)                  { this->strClientFullName = VARIABLE_strClientFullName; }



/**
 * @brief Устанавливает номер телефона клиента
 * 
 * @param VARIABLE_strClientPhoneNumber номер телефона клиента
 */
void SClient::FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber)            { this->strClientPhoneNumber = VARIABLE_strClientPhoneNumber; }



/**
 * @brief Устанавливает дату заключения договора
 * 
 * @param VARIABLE_strDateConclusionContract дата заключения договора
 */
void SClient::FSETSTRING_DateConclusionContract(const std::string& VARIABLE_strDateConclusionContract)  { this->strDateConclusionContract = VARIABLE_strDateConclusionContract; }



/**
 * @brief Устанавливает дату истечения срока действия договора
 * 
 * @param VARIABLE_strDateExpirationContract дата истечения срока действия договора
 */
void SClient::FSETSTRING_DateExpirationContract(const std::string& VARIABLE_strDateExpirationContract)  { this->strDataExpirationContract = VARIABLE_strDateExpirationContract; }



/**
 * @brief Устанавливает путь к файлу
 * 
 * @param VARIABLE_strPathFile путь к файлу
 */
void SClient::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile)                              { this->strPathFile = VARIABLE_strPathFile; }



/**
 * @brief Устанавливает сумму долга
 * 
 * @param VARIABLE_doubleDebtAmount сумма долга
 */
void SClient::FSETDOUBLE_DebtAmount(const double& VARIABLE_doubleDebtAmount)                            { this->doubleDebtAmount = VARIABLE_doubleDebtAmount; }



/**
 * @brief Устанавливает допустимый кредит
 * 
 * @param VARIABLE_doubleCreditAllowable допустимый кредит
 */
void SClient::FSETDOUBLE_CreditAllowable(const double& VARIABLE_doubleCreditAllowable)                  { this->doubleCreditAllowable = VARIABLE_doubleCreditAllowable; }












/**
 * @brief получает имя клиента
 * 
 * @return имя клиента
 */
std::string SClient::FGETSTRING_ClientFullName()			const { return this->strClientFullName; }



/**
 * @brief получает номер телефона клиента
 * 
 * @return номер телефона клиента
 */
std::string SClient::FGETSTRING_ClientPhoneNumber()			const { return this->strClientPhoneNumber; }



/**
 * @brief получает дату заключения договора
 * 
 * @return ддата заключения договора
 */
std::string SClient::FGETSTRING_DateConclusionContract()	const { return this->strDateConclusionContract; }



/**
 * @brief получает дату истечения срокаа действия договора
 * 
 * @return дата истечения срока действия договора
 */
std::string SClient::FGETSTRING_DataExpirationContract()	const { return this->strDataExpirationContract; }



/**
 * @brief получает путь к файлу
 * 
 * @return путь к файлу
 */
std::string SClient::FGETSTRING_PathFile()					const { return this->strPathFile; }


/**
 * @brief получает сумму долга
 * 
 * @return сумма долга
 */
double SClient::FGETDOUBLE_DebtAmount()						const { return this->doubleDebtAmount; }



/**
 * @brief получает допустимый кредит
 * 
 * @return допустимый кредит
 */
double SClient::FGETDOUBLE_CreditAllowable()				const { return this->doubleCreditAllowable; }











/**
 * @brief Записывает данные в файл.
 *
 * Эта функция открывает файл, путь к которому хранится в переменной `strPathFile`.
 * Если файл не может быть открыт, выбрасывается исключение `std::runtime_error`.
 * Содержимое файла считывается символ за символом и выводится на экран.
 *
 * @param objectClass Объект класса ofstream для записи в файл.
 * 
 * @throws std::runtime_error Если не удалось открыть файл или записать в него.
 */
void SClient::FWriteToFile(std::ofstream& objectClass, const std::string& nameFile)
{
	this->strPathFile += nameFile + ".txt";

	this->strNameFile = nameFile;
	
	objectClass.open(this->strPathFile, std::ofstream::app);
	if (!objectClass.is_open())
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}


	// Ввод данных
	std::cin.ignore();
	std::cout << "~$ Enter full name: ";								std::getline(std::cin, this->strClientFullName);			std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strClientPhoneNumber);			std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter the date of conclusion of the contract: ";	std::getline(std::cin, this->strDateConclusionContract);	std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter the end date of the contract: ";				std::getline(std::cin, this->strDataExpirationContract);	std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter the amount of debt: ";						std::cin >> this->doubleDebtAmount;							std::cin.ignore();					std::cout << "\n-------------------" << std::endl;
	std::cout << "~$ Enter acceptable credit: ";						std::cin >> this->doubleCreditAllowable;					std::cin.ignore();					std::cout << "\n-------------------" << std::endl;

	// Запись в файл
	objectClass << '\n' << this->strClientFullName << ", "
		<< this->strClientPhoneNumber << ", "
		<< this->strDateConclusionContract << ", "
		<< this->strDataExpirationContract << ", "
		<< this->doubleDebtAmount << ", "
		<< this->doubleCreditAllowable << '\n';


	if (objectClass.fail())
	{
		throw std::runtime_error("Failed to write to file: " + strPathFile);
	}

	objectClass.close();

	this->strPathFile = "TextFilesFolder/";
}












/**
 * @brief Читает содержимое файла и выводит его на стандартный вывод.
 *
 * Эта функция открывает файл, путь к которому хранится в переменной `strPathFile`.
 * Если файл не может быть открыт, выбрасывается исключение `std::runtime_error`.
 * Содержимое файла считывается символ за символом и выводится на экран.
 *
 * @param objectClass Ссылка на объект ifstream, который будет использоваться для открытия файла.
 *
 * @throws std::runtime_error Если файл не может быть открыт.
 */
void SClient::FReadFileSymbolically(std::ifstream& objectClass, const std::string& nameFile)
{
	this->strPathFile += nameFile + ".txt";

	this->strNameFile = nameFile;

	objectClass.open(this->strPathFile);
	std::cout << this->strPathFile;
	if (!objectClass.is_open()) 
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}


	std::cout << std::endl << "----------File-contents----------" << std::endl;	
	char charGetSymbolFromFile;													
	while (objectClass.get(charGetSymbolFromFile))								
	{
		std::cout << charGetSymbolFromFile;										
	}
	std::cout << std::endl << "---------------------------------" << std::endl;	

	objectClass.close();

	this->strPathFile = "TextFilesFolder/";
}