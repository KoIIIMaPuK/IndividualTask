#pragma once
#include "include.h"


/*
*
*
*
*
*
*/
struct SUsage
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
	SUsage
	(
		const std::string& VARIABLE_strClientPhoneNumber,
		const std::string& VARIABLE_strUsageDateTime,
		const std::string& VARIABLE_strDuration,
		const std::string& VARIABLE_strPathFile,
		const std::string& VARIABLE_strNameFiles,
		const std::uint64_t& VARIABLE_uint64tServiceCode
	) : strClientPhoneNumber(VARIABLE_strClientPhoneNumber),
		strUsageDateTime(VARIABLE_strUsageDateTime),
		strDuration(VARIABLE_strDuration),
		strPathFile(VARIABLE_strPathFile),
		strNameFile(VARIABLE_strNameFiles),
		uint64tServiceCode(VARIABLE_uint64tServiceCode)
	{}







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// 
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SUsage()
		: strClientPhoneNumber("Undefined"),
		strUsageDateTime("Undefined"),
		strDuration("Undefined"),
		strPathFile("TextFilesFolder/"),
		strNameFile("UndefinedUsage.txt"),
		uint64tServiceCode(0)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber);
	void FSETSTRING_UsageDateTime(const std::string& VARIABLE_strUsageDateTime);
	void FSETSTRING_Duration(const std::string& VARIABLE_strDuration);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode);








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	//
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string FGETSTRING_ClientPhoneNumber()		const;
	std::string FGETSTRING_UsageDateTime()			const;
	std::string FGETSTRING_Duration()				const;
	std::string FGETSTRING_PathFile()				const;
	std::uint64_t FGETUINT64T_ServiceCode()			const;








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
	std::string strClientPhoneNumber;
	std::string strUsageDateTime;
	std::string strDuration;
	std::string strPathFile;
	std::string strNameFile;
	std::uint64_t uint64tServiceCode;
};
