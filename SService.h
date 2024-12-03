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
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
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







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_NameService(const std::string& VARIABLE_strNameService);
	void FSETSTRING_TimeUnit(const std::string& VARIABLE_strTimeUnit);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode);
	void FSETSTRING_TypeTime(const std::string& VARIABLE_strTypeTime);








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string		FGETSTRING_NameService()		const;
	std::string		FGETSTRING_TimeUnit()			const;
	std::string		FGETSTRING_PathFile()			const;
	std::uint64_t	FGETUINT64T_ServiceCode()		const;
	std::string		FGETSTRING_TypeTime()			const;








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FWriteToFile(std::ofstream& objectClass, const std::string& nameFile);









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FReadFileSymbolically(std::ifstream& objectClass, const std::string& nameFile);









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
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