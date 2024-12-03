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







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// 
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
std::string SUsage::FGETSTRING_ClientPhoneNumber()	const { return this->strClientPhoneNumber; }
std::string SUsage::FGETSTRING_UsageDateTime()		const { return this->strUsageDateTime; }
std::string SUsage::FGETSTRING_Duration()			const { return this->strDuration; }
std::string SUsage::FGETSTRING_PathFile()			const { return this->strPathFile; }
std::uint64_t SUsage::FGETUINT64T_ServiceCode()		const { return this->uint64tServiceCode; }








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
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



	objectClass << this->strClientPhoneNumber << ", "
		<< this->uint64tServiceCode << ", "
		<< this->strDuration << ", "
		<< this->strUsageDateTime << '\n';

	if (objectClass.fail())
	{
		throw std::runtime_error("Failed to write to file: " + strPathFile);
	}



	objectClass.close();
}








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
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
}