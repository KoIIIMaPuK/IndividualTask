#include "SService.h"






/**
 * @brief Устанавливает имя сервиса.
 *
 * @param VARIABLE_strNameService Имя сервиса.
 */
void SService::FSETSTRING_NameService(const std::string& VARIABLE_strNameService) 			{this->strNameService = VARIABLE_strNameService;}



/**
 * @brief Устанавливает единицу времени.
 *
 * @param VARIABLE_strTimeUnit Единица времени.
 */
void SService::FSETSTRING_TimeUnit(const std::string& VARIABLE_strTimeUnit) 				{this->strTimeUnit = VARIABLE_strTimeUnit;}




/**
 * @brief Устанавливает путь к файлу.
 *
 * @param VARIABLE_strPathFile Путь к файлу.
 */
void SService::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile) 				{this->strPathFile = VARIABLE_strPathFile;}





/**
 * @brief Устанавливает код сервиса.
 *
 * @param VARIABLE_uint64tServiceCode Код сервиса.
 */
void SService::FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode) 	{this->uint64tServiceCode = VARIABLE_uint64tServiceCode;}





/**
 * @brief Устанавливает тариф.
 *
 * @param VARIABLE_doubleTariff Тариф.
 */
void SService::FSETDOUBLE_Tariff(double VARIABLE_doubleTariff) 								{this->doubleTariff = VARIABLE_doubleTariff;}
















/**
 * @brief Получает имя сервиса.
 *
 * @return Имя сервиса.
 */
std::string SService::FGETSTRING_NameService() 		const {return this->strNameService;}





/**
 * @brief Получает единицу времени.
 *
 * @return Единица времени.
 */
std::string SService::FGETSTRING_TimeUnit() 		const {return this->strTimeUnit;}





/**
 * @brief Получает путь к файлу.
 *
 * @return Путь к файлу.
 */
std::string SService::FGETSTRING_PathFile() 		const {return this->strPathFile;}





/**
 * @brief Получает код сервиса.
 *
 * @return Код сервиса.
 */
std::uint64_t SService::FGETUINT64T_ServiceCode() 	const {return this->uint64tServiceCode;}





/**
 * @brief Получает тариф.
 *
 * @return Тариф.
 */
double SService::FGETDOUBLE_Tariff() 				const {return this->doubleTariff;}





















/**
* @brief Записывает данные в файл.
*
* Открывает файл для записи и запрашивает у пользователя данные для записи.
*
* @param objectClass Объект класса ofstream для записи в файл.
* @throws std::runtime_error Если не удалось открыть файл или записать в него.
*/
void SService::FWriteToFile(std::ofstream& objectClass, const std::string& nameFile)
{
	strPathFile += nameFile;

	this->strNameFile = nameFile;

	objectClass.open(this->strPathFile, std::ofstream::app);
	if (!objectClass.is_open())
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}



	std::cin.ignore();
	std::cout << "~$ Enter full name: ";								std::getline(std::cin, this->strNameService);		std::cout << "\n-------------------" << std::endl; 
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strTimeUnit);			std::cout << "\n-------------------" << std::endl; 
	std::cout << "~$ Enter the amount of debt ";						std::cin >> this->uint64tServiceCode;				std::cin.ignore();						std::cout << "\n-------------------" << std::endl;
	std::cout << "~$ Enter acceptable credit ";							std::cin >> this->doubleTariff;						std::cin.ignore();						std::cout << "\n-------------------" << std::endl;




	objectClass << this->strNameService << ", "
		<< this->strTimeUnit << ", "
		<< this->uint64tServiceCode << ", "
		<< this->doubleTariff << '\n';
	



	if (objectClass.fail())
	{
		throw std::runtime_error("Failed to write to file: " + strPathFile);
	}

	objectClass.close();
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
void SService::FReadFileSymbolically(std::ifstream& objectClass)
{
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