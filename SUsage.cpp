#include "SUsage.h"





/**
 * @brief Устанавливает номер телефона клиента
 * 
 * @param VARIABLE_strClientPhoneNumber номер телефона
 */
void SUsage::FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber) 	{this->strClientPhoneNumber = VARIABLE_strClientPhoneNumber; }



/**
 * @brief Устанавливает дату / время использования услуги
 * 
 * @param VARIABLE_strUsageDateTime дата / время использования услуги
 */
void SUsage::FSETSTRING_UsageDateTime(const std::string& VARIABLE_strUsageDateTime) 			{this->strUsageDateTime = VARIABLE_strUsageDateTime; }



/**
 * @brief Устанавливает продолжительность
 * 
 * @param VARIABLE_strDuration продолжительность
 */
void SUsage::FSETSTRING_Duration(const std::string& VARIABLE_strDuration) 						{this->strDuration = VARIABLE_strDuration; }




/**
 * @brief Устанавливает путь к файлу
 * 
 * @param VARIABLE_strPathFile путь к файлу
 */
void SUsage::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile) 						{this->strPathFile = VARIABLE_strPathFile; }



/**
 * @brief Устанавливает код сервиса
 * 
 * @param VARIABLE_strServiceCode код сервиса
 */
void SUsage::FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_strServiceCode) 				{this->uint64tServiceCode = VARIABLE_strServiceCode; }







/**
 * @brief Получает номер телефона клиента.
 *
 * Эта функция возвращает номер телефона клиента, хранящийся в объекте.
 *
 * @return Строка, представляющая номер телефона клиента.
 */
std::string SUsage::FGETSTRING_ClientPhoneNumber()	const { return this->strClientPhoneNumber; }




/**
 * @brief Получает дату и время использования услуги.
 *
 * Эта функция возвращает дату и время использования услуги, хранящиеся в объекте.
 *
 * @return Строка, представляющая дату и время использования услуги.
 */
std::string SUsage::FGETSTRING_UsageDateTime()		const { return this->strUsageDateTime; }




/**
 * @brief Получает продолжительность использования услуги.
 *
 * Эта функция возвращает продолжительность использования услуги, хранящуюся в объекте.
 *
 * @return Строка, представляющая продолжительность использования услуги.
 */
std::string SUsage::FGETSTRING_Duration()			const { return this->strDuration; }




/**
 * @brief Получает путь к файлу.
 *
 * Эта функция возвращает путь к файлу, хранящийся в объекте.
 *
 * @return Строка, представляющая путь к файлу.
 */

std::string SUsage::FGETSTRING_PathFile()			const { return this->strPathFile; }




/**
 * @brief Получает код услуги.
 *
 * Эта функция возвращает код услуги, хранящийся в объекте.
 *
 * @return Код услуги в формате uint64_t.
 */
std::uint64_t SUsage::FGETUINT64T_ServiceCode()		const { return this->uint64tServiceCode; }








/**
 * @brief Записывает данные об использовании услуги в файл.
 *
 * Эта функция запрашивает у пользователя ввод номера телефона клиента, кода услуги, 
 * продолжительности использования и даты/времени использования, а затем записывает 
 * эти данные в указанный файл. Если файл не может быть открыт или данные не могут 
 * быть записаны, выбрасывается исключение.
 *
 * @param objectClass Ссылка на объект ofstream для записи в файл.
 * @param nameFile Имя файла (без расширения), в который будут записаны данные.
 *
 * @throws std::runtime_error Если не удаётся открыть файл или записать в него данные.
 */
void SUsage::FWriteToFile(std::ofstream& objectClass, const std::string& nameFile)
{
	strPathFile += nameFile + ".txt";

	this->strNameFile = nameFile;
	
	objectClass.open(this->strPathFile, std::ofstream::app);
	if (!objectClass.is_open())
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}



	std::cin.ignore();
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strClientPhoneNumber);		std::cout << "\n-------------------" << std::endl;	
	std::cout << "~$ Enter service code: ";								std::cin >> this->uint64tServiceCode;			       	std::cin.ignore(); 						std::cout << "\n-------------------" << std::endl;	
	std::cout << "~$ Enter duration: ";									std::getline(std::cin, this->strDuration);				std::cout << "\n-------------------" << std::endl;	
	std::cout << "~$ Enter usage date time: ";							std::getline(std::cin, this->strUsageDateTime);			std::cout << "\n-------------------" << std::endl;



	objectClass << '\n' << this->strClientPhoneNumber << ", "
		<< this->uint64tServiceCode << ", "
		<< this->strDuration << ", "
		<< this->strUsageDateTime << '\n';

	if (objectClass.fail())
	{
		throw std::runtime_error("Failed to write to file: " + strPathFile);
	}

	objectClass.close();

	this->strPathFile = "TextFilesFolder/";
}




/**
 * @brief Символьное чтение файла и вывод его содержимого на экран.
 *
 * Эта функция открывает указанный файл, читает его символ за символом и выводит 
 * его содержимое на экран. Если файл не может быть открыт, выбрасывается исключение.
 *
 * @param objectClass Ссылка на объект ifstream для чтения из файла.
 * @param nameFile Имя файла (без расширения), который будет прочитан.
 *
 * @throws std::runtime_error Если не удаётся открыть файл.
 */
void SUsage::FReadFileSymbolically(std::ifstream& objectClass, const std::string& nameFile)
{
	strPathFile += nameFile + ".txt";

	this->strNameFile = nameFile;
	
	objectClass.open(this->strPathFile);
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