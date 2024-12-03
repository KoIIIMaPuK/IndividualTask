#pragma once
#include "include.h"


struct SClient
{
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// 
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SClient
	(
		const std::string& VARIABLE_strClientFullName,					
		const std::string& VARIABLE_strClientPhoneNumber,				
		const std::string& VARIABLE_strDateConclusionContract,			
		const std::string& VARIABLE_strDataExpirationContract,			
		const std::string& VARIABLE_strPathFile,
		const std::string& VARIABLE_strNameFiles,						
		const double& VARIABLE_doubleDebtAmount,						
		const double& VARIABLE_doubleCreditAllowable					
	) : strClientFullName(VARIABLE_strClientFullName),
		strClientPhoneNumber(VARIABLE_strClientPhoneNumber),
		strDateConclusionContract(VARIABLE_strDateConclusionContract),
		strDataExpirationContract(VARIABLE_strDataExpirationContract),
		strPathFile(VARIABLE_strPathFile),
		strNameFile(VARIABLE_strNameFiles),
		doubleDebtAmount(VARIABLE_doubleDebtAmount),
		doubleCreditAllowable(VARIABLE_doubleCreditAllowable)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// 
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SClient()
		: strClientFullName("Undefined"),
		strClientPhoneNumber("Undefined"),
		strDateConclusionContract("Undefined"),
		strDataExpirationContract("Undefined"),
		strPathFile("TextFilesFolder/"),
		strNameFile("UndefinedClient.txt"),
		doubleDebtAmount(0.0),
		doubleCreditAllowable(0.0)
	{}









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// 
	// 
	// 
	// 
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_ClientFullName(const std::string& VARIABLE_strClientFullName);
	void FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber);
	void FSETSTRING_DateConclusionContract(const std::string& VARIABLE_strDateConclusionContract);
	void FSETSTRING_DateExpirationContract(const std::string& VARIABLE_strDateExpirationContract);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETDOUBLE_DebtAmount(const double& VARIABLE_doubleDebtAmount);
	void FSETDOUBLE_CreditAllowable(const double& VARIABLE_doubleCreditAllowable);







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// 
	// 
	//  
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string FGETSTRING_ClientFullName()				const;
	std::string FGETSTRING_ClientPhoneNumber()			const;
	std::string FGETSTRING_DateConclusionContract()		const;
	std::string FGETSTRING_DataExpirationContract()		const;
	std::string FGETSTRING_PathFile()					const;
	double FGETDOUBLE_DebtAmount()						const;
	double FGETDOUBLE_CreditAllowable()					const;








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
	// 	   
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
protected:
	std::string		strClientFullName;					
	std::string		strClientPhoneNumber;				
	std::string		strDateConclusionContract;			
	std::string		strDataExpirationContract;			
	std::string		strPathFile;
	std::string 	strNameFile;					
	double			doubleDebtAmount;					
	double			doubleCreditAllowable;				
};