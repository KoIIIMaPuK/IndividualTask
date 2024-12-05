#pragma once
#include "include.h"


/*
*
*
*/
struct SService
{
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//	PUBLIC
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] Constructors:
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SService
	(
		const std::string& VARIABLE_strNameService,
		const std::string& VARIABLE_strTimeUnit,
		const std::string& VARIABLE_strPathFile,
		const std::string& VARIABLE_strNameFiles,
		const std::uint64_t& VARIABLE_uint64tServiceCode,
		const std::string& VARIABLE_strTypeTime
	) : strNameService(VARIABLE_strNameService),
		strTimeUnit(VARIABLE_strTimeUnit),
		strPathFile(VARIABLE_strPathFile),
		strNameFile(VARIABLE_strNameFiles),
		uint64tServiceCode(VARIABLE_uint64tServiceCode),
		strTypeTime(VARIABLE_strTypeTime)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] Constructors: 
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SService()
		: strNameService("Undefined"),
		strTimeUnit("Undefined"),
		strPathFile("TextFilesFolder/"),
		strNameFile("UndefinedService.txt"),
		uint64tServiceCode(0),
		strTypeTime("sec")
	{}







	/**
	 * @brief Устанавливает имя сервиса.
	 *
	 * @param VARIABLE_strNameService Имя сервиса.
	 */
	void FSETSTRING_NameService(const std::string& VARIABLE_strNameService);



	/**
	 * @brief Устанавливает единицу времени.
	 *
	 * @param VARIABLE_strTimeUnit Единица времени.
	 */
	void FSETSTRING_TimeUnit(const std::string& VARIABLE_strTimeUnit);



	/**
	 * @brief Устанавливает путь к файлу.
	 *
	 * @param VARIABLE_strPathFile Путь к файлу.
	 */
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);



	/**
	 * @brief Устанавливает код сервиса.
	 *
	 * @param VARIABLE_uint64tServiceCode Код сервиса.
	 */
	void FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode);



	/**
	 * @brief Устанавливает тариф.
	 *
	 * @param VARIABLE_doubleTariff Тариф.
	 */
	void FSETSTRING_TypeTime(const std::string& VARIABLE_strTypeTime);








	/**
	 * @brief Получает имя сервиса.
	 *
	 * @return Имя сервиса.
	 */
	std::string		FGETSTRING_NameService()		const;



	/**
	 * @brief Получает единицу времени.
	 *
	 * @return Единица времени.
	 */
	std::string		FGETSTRING_TimeUnit()			const;



	/**
	 * @brief Получает путь к файлу.
	 *
	 * @return Путь к файлу.
	 */
	std::string		FGETSTRING_PathFile()			const;



	/**
	 * @brief Получает код сервиса.
	 *
	 * @return Код сервиса.
	 */
	std::uint64_t	FGETUINT64T_ServiceCode()		const;



	/**
	 * @brief Получает тариф.
	 *
	 * @return Тариф.
	 */
	std::string		FGETSTRING_TypeTime()			const;








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// PUBLIC
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	/**
	 * @brief Записывает данные в файл.
	 *
	 * Открывает файл для записи и запрашивает у пользователя данные для записи.
	 *
	 * @param objectClass Объект класса ofstream для записи в файл.
	 * 
	 * @throws std::runtime_error Если не удалось открыть файл или записать в него.
	 */
	void FWriteToFile(std::ofstream& objectClass, const std::string& nameFile);









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
	void FReadFileSymbolically(std::ifstream& objectClass, const std::string& nameFile);









//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// PROTECTED
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
protected:
	std::string strNameService;
	std::string strTimeUnit;
	std::string strPathFile;
	std::string strNameFile;
	std::uint64_t uint64tServiceCode;
	std::string strTypeTime;
};