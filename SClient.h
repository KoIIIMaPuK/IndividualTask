#pragma once
#include "include.h"

struct SClient
{
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// [0] Публичная часть структуры
// 
// 	   * Базовая часть структуры
// 
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] Конструктор структуры
	// 
	//		* Сами задаем значения
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SClient
	(
		const std::string&		VARIABLE_strClientFullName,				// Ссылка на переменную <ФИО клиента>
		const std::string&		VARIABLE_strClientPhoneNumber,				// Ссылка на переменную <Номер телефона клиента>
		const std::string&		VARIABLE_strDateConclusionContract,			// Ссылка на переменную <Дату заключения договора>
		const std::string&		VARIABLE_strDataExpirationContract,			// Ссылка на переменную <Дату окончания договора>
		const std::string&		VARIABLE_strPathFile,					// Ссылка на переменную <Путь к файлу>
		const double			VARIABLE_doubleDebtAmount,				// Ссылка на переменную <Размер задолжности>
		const double			VARIABLE_doubleCreditАllowable				// Ссылка на переменную <Допустимый кредит>
	) : strClientFullName(VARIABLE_strClientFullName),
		strClientPhoneNumber(VARIABLE_strClientPhoneNumber),
		strDateConclusionContract(VARIABLE_strDateConclusionContract),
		strDataExpirationContract(VARIABLE_strDataExpirationContract),
		strPathFile(VARIABLE_strPathFile),
		doubleDebtAmount(VARIABLE_doubleDebtAmount),
		doubleCreditАllowable(VARIABLE_doubleCreditАllowable)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] Конструктор структуры
	// 
	//		* Здесь используем дефолтные
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SClient()
		: strClientFullName("Undefined"),
			strClientPhoneNumber("Undefined"),
			strDateConclusionContract("Undefined"),
			strDataExpirationContract("Undefined"),
			strPathFile("Undefined.txt"),
			doubleDebtAmount(0.0),
			doubleCreditАllowable(0.0)
	{}







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Сеттеры
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_ClientFullName(const std::string& VARIABLE_strClientFullName);
	void FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber);
	void FSETSTRING_DateConclusionContract(const std::string& VARIABLE_strDateConclusionContract);
	void FSETSTRING_DataExpirationContract(const std::string& VARIABLE_strDataExpirationContract);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETDOUBLE_DebtAmount(double VARIABLE_doubleDebtAmount);
	void FSETDOUBLE_CreditАllowable(double VARIABLE_doubleCreditАllowable);








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Геттеры
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string FGETSTRING_ClientFullName()			const;
	std::string FGETSTRING_ClientPhoneNumber()		const;
	std::string FGETSTRING_DateConclusionContract()		const;
	std::string FGETSTRING_DataExpirationContract()		const;
	std::string FGETSTRING_PathFile()			const;
	double FGETDOUBLE_DebtAmount()				const;
	double FGETDOUBLE_CreditАllowable()			const;








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// [1] Публичная часть структуры
// 
//		* Предназначана для прочих функций
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Запись в файл
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FWriteToFile(std::ofstream& objectClass);









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Чтение из файла
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FReadSymbolFromFile(std::ifstream& objectClass);


	






//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// [0] Насследуемая часть структуры
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
protected:
	std::string		strClientFullName;				// ФИО клиента
	std::string		strClientPhoneNumber;				// Номер телефона клиента
	std::string		strDateConclusionContract;			// Дата заключения договора
	std::string		strDataExpirationContract;			// Дата окончание договора
	std::string		strPathFile;					// Путь к файлу
	double			doubleDebtAmount;				// Размер задолжности
	double			doubleCreditАllowable;				// Допустимый кредит
};
