#include "SClient.h"
#include "SService.h"
#include "SUsage.h"
#include "include.h"


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// 
// Перечисления для действий и типов файлов.
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
/**
*
*   @brief  enum Actiron
*
*   Это перечисление определяет возможные действия, которые может выполнить
*   программа при взаимодействии с файлами. Каждое значение в перечислении
*   соответствует определенному действию, которое может выбрать пользователь.
*
*   Значения:
*   - INPUT: Действие, указывающее на ввод данных в файл. Значение: 1
*   - READ: Действие, указывающее на чтение данных из файла. Значение: 2
*   - EXIT: Действие, указывающее на выход из программы. Значение: 3
*
*/
enum Action { AINPUT = 1, AREAD, ACREATE, ATASK, AEXIT = 0};


/**
 *
 *   @brief enum FileType
 *
 *   Это перечисление определяет типы файлов, с которыми может работать
 *   программа. Каждое значение в перечислении соответствует определенному
 *   типу файла, что упрощает обработку файлов.
 *   
 *   Значения:
 *   - CLIENT: Тип файла, представляющий данные клиента. Значение: 1
 *   - SERVICE: Тип файла, представляющий данные сервиса. Значение: 2
 *   - USAGE: Тип файла, представляющий данные использования. Значение: 3
 *   - BACK: Специальный тип(опция), указывающий на возврат в предыдущее меню или
 *     действие. Значение: 4
 *
 */
enum FileType { CLIENT = 1, SERVICE, USAGE, BACK = 0};










//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// 
// Функции для отображения меню действий с файлами.
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
/*
*
*       Статичная функция для отображения меню действий с файлами
*
*       Эта функция выводит на экран меню, позволяющее пользователю выбрать
*       действие, которое он хочет выполнить с файлами. 
* 
*       Меню включает:
*       - опции для ввода данных в файл, 
*       - чтение данных из файла, 
*       - создание файла с пользовательским именем
*       - индивидуальное задание
*       - выход из программы.
*
*/
static inline void FShowMenuAction() {
    std::cout << "\n----------System----------\n"
        << "Select action:\n"
        << "1. Input to file\n"
        << "2. Reading a File\n"
        << "3. Create a file\n"
        << "4. Check my task\n"
        << "0. Exit to programm\n"
        << "--------------------------\n";
}




/*
*
*       Статичная функция для отображения меню структур
*
*       Эта функция выводит на экран меню, позволяющее пользователю выбрать
*       тип файла, с которым он хочет работать. 
*       I
*       Меню включает опции для выбора типа файла:
*       1. Client;
*       2. Service;
*       3. Usage;
*       0. Опция возврата в предыдущее меню.
*
*/
static inline void FShowMenuFile() {
    std::cout << "\n----------System----------\n"
        << "Select File:\n"
        << "1. Client\n"
        << "2. Service\n"
        << "3. Usage\n"
        << "0. Back\n"
        << "-------------------------\n";
}


















/**
 * @brief Получает текущее время в формате строки.
 *
 * Функция использует стандартную библиотеку <chrono> для получения
 * текущего времени и форматирует его в строку вида "YYYY-MM-DD HH:MM:SS".
 *
 * @return std::string Строка, представляющая текущее время в формате "YYYY-MM-DD HH:MM:SS".
 */
std::string GetCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);
    
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}















/**
 *       @brief Функция для обработки операций с файлами
 *
 *       Функция HandleFileOperation выполняет операции ввода и чтения данных
 *       из файлов в зависимости от типа файла и действия, выбранного пользователем.
 *
 *       Параметры:
 *       @param action: действие, которое нужно выполнить (INPUT или READ).
 *       @param fileType: тип файла, с которым будет работать функция (Client, Service, Usage).
 *       @param client: ссылка на объект клиента для выполнения операций с файлом клиента.
 *       @param service: ссылка на объект сервиса для выполнения операций с файлом сервиса.
 *       @param usage: ссылка на объект использования для выполнения операций с файлом использования.
 */
void HandleFileOperation(Action action, FileType fileType, SClient& client, SService& service, SUsage& usage) {
    std::ofstream WobjectClass; // Объект для записи в файл
    std::ifstream RobjectClass; // Объект для чтения из файла
    std::ofstream reportFile("TextFilesFolder/Action.txt", std::ios::app);

    // Получаем текущее время
    std::string currentTime = GetCurrentTime();

    switch (fileType) {
    case FileType::CLIENT:
        if (action == Action::AINPUT) {
            std::cout << "Writing to Client file...\n";
            client.FWriteToFile(WobjectClass, "Client");
            std::cout << "Writing completed successfully!\n";
            reportFile << currentTime << " - Writing to Client file completed successfully.\n"; // Записываем в отчет
        } else {
            std::cout << "Reading from Client file...\n";
            client.FReadFileSymbolically(RobjectClass, "Client");
            std::cout << "Reading completed successfully!\n";
            reportFile << currentTime << " - Reading from Client file completed successfully.\n"; // Записываем в отчет
        }
        break;
    case FileType::SERVICE:
        if (action == Action::AINPUT) {
            std::cout << "Writing to Service file...\n";
            service.FWriteToFile(WobjectClass, "Service");
            std::cout << "Writing completed successfully!\n";
            reportFile << currentTime << " - Writing to Service file completed successfully.\n"; // Записываем в отчет
        } else {
            std::cout << "Reading from Service file...\n";
            service.FReadFileSymbolically(RobjectClass, "Service");
            std::cout << "Reading completed successfully!\n";
            reportFile << currentTime << " - Reading from Service file completed successfully.\n"; // Записываем в отчет
        }
        break;
    case FileType::USAGE:
        if (action == Action::AINPUT) {
            std::cout << "Writing to Usage file...\n";
            usage.FWriteToFile(WobjectClass, "Usage");
            std::cout << "Writing completed successfully!\n";
            reportFile << currentTime << " - Writing to Usage file completed successfully.\n"; // Записываем в отчет
        } else {
            std::cout << "Reading from Usage file...\n";
            usage.FReadFileSymbolically(RobjectClass, "Usage");
            std::cout << "Reading completed successfully!\n";
            reportFile << currentTime << " - Reading from Usage file completed successfully.\n"; // Записываем в отчет
        }
        break;
    case FileType::BACK:
        std::cout << "Returning to the previous menu...\n";
        break;
    default:
        std::cerr << "I$> Invalid input. You entered an invalid file type.\n";
        break;
    }

    // Закрываем файл отчета
    reportFile.close();
}





/**
 *       @brief Функция для обработки операций с файлами
 *
 *       Функция HandleFileOperation выполняет операции ввода и чтения данных
 *       из файлов в зависимости от типа файла и действия, выбранного пользователем.
 *
 *       Параметры:
 *       @param action: действие, которое нужно выполнить (INPUT или READ).
 *       @param fileType: тип файла, с которым будет работать функция (Client, Service, Usage).
 *       @param fileName: название для файла 
 *       @param client: ссылка на объект клиента для выполнения операций с файлом клиента.
 *       @param service: ссылка на объект сервиса для выполнения операций с файлом сервиса.
 *       @param usage: ссылка на объект использования для выполнения операций с файлом использования.
 */
void HandleFileOperation(Action action, FileType fileType, std::string& fileName, SClient& client, SService& service, SUsage& usage) {
    std::ofstream WobjectClass; // Объект для записи в файл
    std::ifstream RobjectClass; // Объект для чтения из файла
    std::ofstream reportFile("TextFilesFolder/Action.txt", std::ios::app);

    // Получаем текущее время
    std::string currentTime = GetCurrentTime();

    switch (fileType) {
    case FileType::CLIENT:
        if (action == Action::AINPUT) {
            std::cout << "Writing to Client file...\n";
            client.FWriteToFile(WobjectClass, fileName);
            std::cout << "Writing completed successfully!\n";
            reportFile << currentTime << " - Writing to Client file completed successfully.\n"; // Записываем в отчет
        } else {
            std::cout << "Reading from Client file...\n";
            client.FReadFileSymbolically(RobjectClass, fileName);
            std::cout << "Reading completed successfully!\n";
            reportFile << currentTime << " - Reading from Client file completed successfully.\n"; // Записываем в отчет
        }
        break;
    case FileType::SERVICE:
        if (action == Action::AINPUT) {
            std::cout << "Writing to Service file...\n";
            service.FWriteToFile(WobjectClass, fileName);
            std::cout << "Writing completed successfully!\n";
            reportFile << currentTime << " - Writing to Service file completed successfully.\n"; // Записываем в отчет
        } else {
            std::cout << "Reading from Service file...\n";
            service.FReadFileSymbolically(RobjectClass, fileName);
            std::cout << "Reading completed successfully!\n";
            reportFile << currentTime << " - Reading from Service file completed successfully.\n"; // Записываем в отчет
        }
        break;
    case FileType::USAGE:
        if (action == Action::AINPUT) {
            std::cout << "Writing to Usage file...\n";
            usage.FWriteToFile(WobjectClass, fileName);
            std::cout << "Writing completed successfully!\n";
            reportFile << currentTime << " - Writing to Usage file completed successfully.\n"; // Записываем в отчет
        } else {
            std::cout << "Reading from Usage file...\n";
            usage.FReadFileSymbolically(RobjectClass, fileName);
            std::cout << "Reading completed successfully!\n";
            reportFile << currentTime << " - Reading from Usage file completed successfully.\n"; // Записываем в отчет
        }
        break;
    case FileType::BACK:
        std::cout << "Returning to the previous menu...\n";
        break;
    default:
        std::cerr << "I$> Invalid input. You entered an invalid file type.\n";
        break;
    }

    // Закрываем файл отчета
    reportFile.close();
}



















void findClientPhoneNumber(const std::string& clientName, std::string& clientPhoneNumber) {
    std::ifstream RobjectClass("TextFilesFolder/Client.txt"); // Объект для чтения из файла
    if (!RobjectClass.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Client.txt");
    }

    std::string line;
    bool found = false;

    // Приводим имя клиента к нижнему регистру для сравнения
    std::string lowerClientName = clientName;
    std::transform(lowerClientName.begin(), lowerClientName.end(), lowerClientName.begin(), ::tolower);

    while (std::getline(RobjectClass, line)) {
        std::stringstream ss(line);
        std::string name;
        std::string phoneNumber;

        // Извлекаем имя клиента
        if (std::getline(ss, name, ',')) {
            // Убираем пробелы
            name.erase(name.find_last_not_of(" ") + 1);
            name.erase(0, name.find_first_not_of(" "));

            // Приводим имя клиента к нижнему регистру для сравнения
            std::string lowerName = name;
            std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            // Если имя совпадает
            if (lowerName == lowerClientName) {
                // Извлекаем номер телефона
                if (std::getline(ss, phoneNumber, ',')) {
                    // Убираем пробелы
                    phoneNumber.erase(phoneNumber.find_last_not_of(" ") + 1);
                    phoneNumber.erase(0, phoneNumber.find_first_not_of(" "));
                    
                    std::cout << "\n<<<<<<<<<<--Find-Info-->>>>>>>>>>\n";
                    std::cout << "Номер телефона клиента " << clientName << ": " << phoneNumber;
                    std::cout << "\n<<<<<<<<<<------------->>>>>>>>>>\n";
                    clientPhoneNumber = phoneNumber;
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found) {
        std::cout << "Клиент с именем " << clientName << " не найден." << std::endl;
    }

    RobjectClass.close(); // Закрываем файл
}





void findServiceNumberByPhone(const std::string& phoneNumber, std::string& serviceNumber) {
    std::ifstream usageFile("TextFilesFolder/Usage.txt"); // Объект для чтения из файла
    if (!usageFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Usage.txt");
    }

    std::string line;
    bool found = false;

    while (std::getline(usageFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string currentPhoneNumber = line.substr(0, commaPos);
            std::string currentServiceNumber = line.substr(commaPos + 1, line.find(',', commaPos + 1) - commaPos - 1);

            currentPhoneNumber.erase(currentPhoneNumber.find_last_not_of(" ") + 1);
            currentPhoneNumber.erase(0, currentPhoneNumber.find_first_not_of(" "));
            currentServiceNumber.erase(currentServiceNumber.find_last_not_of(" ") + 1);
            currentServiceNumber.erase(0, currentServiceNumber.find_first_not_of(" "));

            if (currentPhoneNumber == phoneNumber) {
                std::cout << "\n<<<<<<<<<<--Find-Service-->>>>>>>>>>\n";
                std::cout << "Номер услуги для телефона " << phoneNumber << ": " << currentServiceNumber;
                std::cout << "\n<<<<<<<<<<---------------->>>>>>>>>>\n";
                serviceNumber = currentServiceNumber;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "Услуга с номером телефона " << phoneNumber << " не найдена." << std::endl;
    }

    usageFile.close(); // Закрываем файл
}





void findServiceNameByCode(const std::string& serviceCode, std::string& serviceName) {
    std::ifstream serviceFile("TextFilesFolder/Service.txt"); // Объект для чтения из файла
    if (!serviceFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Service.txt");
    }

    std::string line;
    bool found = false;

    while (std::getline(serviceFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string currentServiceName = line.substr(0, commaPos);
            std::string currentServiceCode = line.substr(commaPos + 1, line.find(',', commaPos + 1) - commaPos - 1);

            currentServiceName.erase(currentServiceName.find_last_not_of(" ") + 1);
            currentServiceName.erase(0, currentServiceName.find_first_not_of(" "));
            currentServiceCode.erase(currentServiceCode.find_last_not_of(" ") + 1);
            currentServiceCode.erase(0, currentServiceCode.find_first_not_of(" "));

            if (currentServiceCode == serviceCode) {
                std::cout << "\n<<<<<<<<<<--Find-Service-Name-->>>>>>>>>>\n";
                std::cout << "Имя услуги для кода " << serviceCode << ": " << currentServiceName;
                std::cout << "\n<<<<<<<<<<--------------------->>>>>>>>>>\n";
                serviceName = currentServiceName;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "Услуга с кодом " << serviceCode << " не найдена." << std::endl;
    }

    serviceFile.close(); // Закрываем файл
}











/**
 * @brief Функция для поиска сервис-кода по имени сервиса
 * 
 * 
 */
void findServiceCodeByName(const std::string& serviceName, std::string& serviceCode) {
    std::ifstream serviceFile("TextFilesFolder/Service.txt");
    if (!serviceFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Service.txt");
    }

    std::string line;
    bool found = false;

    std::string lowerServiceName = serviceName;
    std::transform(lowerServiceName.begin(), lowerServiceName.end(), lowerServiceName.begin(), ::tolower);

    while (std::getline(serviceFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string currentServiceName = line.substr(0, commaPos);
            std::string currentServiceCode = line.substr(commaPos + 1, line.find(',', commaPos + 1) - commaPos - 1);

            currentServiceName.erase(currentServiceName.find_last_not_of(" ") + 1);
            currentServiceName.erase(0, currentServiceName.find_first_not_of(" "));
            currentServiceCode.erase(currentServiceCode.find_last_not_of(" ") + 1);
            currentServiceCode.erase(0, currentServiceCode.find_first_not_of(" "));

            std::string lowerCurrentServiceName = currentServiceName;
            std::transform(lowerCurrentServiceName.begin(), lowerCurrentServiceName.end(), lowerCurrentServiceName.begin(), ::tolower);

            if (lowerCurrentServiceName == lowerServiceName) {
                std::cout << "\n<<<<<<<<<<--Find-Service-Code-->>>>>>>>>>\n";
                std::cout << "Код услуги для " << serviceName << ": " << currentServiceCode;
                std::cout << "\n<<<<<<<<<<--------------------->>>>>>>>>>\n";
                serviceCode = currentServiceCode;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "Услуга с именем " << serviceName << " не найдена." << std::endl;
    }

    serviceFile.close();
}




void findPhoneNumberByServiceCode(const std::string& serviceCode, std::string& phoneNumber) {
    std::ifstream usageFile("TextFilesFolder/Usage.txt");
    if (!usageFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Usage.txt");
    }

    std::string line;
    bool found = false;

    // Убираем пробелы в коде услуги
    std::string trimmedServiceCode = serviceCode;
    trimmedServiceCode.erase(trimmedServiceCode.find_last_not_of(" ") + 1);
    trimmedServiceCode.erase(0, trimmedServiceCode.find_first_not_of(" "));

    while (std::getline(usageFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string currentPhoneNumber = line.substr(0, commaPos);
            std::string currentServiceCode = line.substr(commaPos + 1, line.find(',', commaPos + 1) - commaPos - 1);

            // Убираем пробелы
            currentPhoneNumber.erase(currentPhoneNumber.find_last_not_of(" ") + 1);
            currentPhoneNumber.erase(0, currentPhoneNumber.find_first_not_of(" "));
            currentServiceCode.erase(currentServiceCode.find_last_not_of(" ") + 1);
            currentServiceCode.erase(0, currentServiceCode.find_first_not_of(" "));

            if (currentServiceCode == trimmedServiceCode) {
                std::cout << "\n<<<<<<<<<<--Find-Phone-Number-->>>>>>>>>>\n";
                std::cout << "Номер телефона для кода услуги " << serviceCode << ": " << currentPhoneNumber;
                std::cout << "\n<<<<<<<<<<------------------------->>>>>>>>>>\n";
                phoneNumber = currentPhoneNumber;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "Услуга с кодом " << serviceCode << " не найдена." << std::endl;
    }

    usageFile.close();
}




void findClientNameByPhoneNumber(const std::string& phoneNumber, std::string& clientName) {
    std::ifstream RobjectClass("TextFilesFolder/Client.txt"); // Объект для чтения из файла
    if (!RobjectClass.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Client.txt");
    }

    std::string line;
    bool found = false;

    // Убираем пробелы в номере телефона
    std::string trimmedPhoneNumber = phoneNumber;
    trimmedPhoneNumber.erase(trimmedPhoneNumber.find_last_not_of(" ") + 1);
    trimmedPhoneNumber.erase(0, trimmedPhoneNumber.find_first_not_of(" "));

    while (std::getline(RobjectClass, line)) {
        std::stringstream ss(line);
        std::string name;
        std::string currentPhoneNumber;

        // Извлекаем имя клиента
        if (std::getline(ss, name, ',')) {
            // Убираем пробелы
            name.erase(name.find_last_not_of(" ") + 1);
            name.erase(0, name.find_first_not_of(" "));

            // Извлекаем номер телефона
            if (std::getline(ss, currentPhoneNumber, ',')) {
                // Убираем пробелы
                currentPhoneNumber.erase(currentPhoneNumber.find_last_not_of(" ") + 1);
                currentPhoneNumber.erase(0, currentPhoneNumber.find_first_not_of(" "));

                // Сравниваем номер телефона
                if (currentPhoneNumber == trimmedPhoneNumber) {
                    std::cout << "\n<<<<<<<<<<--Find-Info-->>>>>>>>>>\n";
                    std::cout << "Имя клиента с номером телефона " << phoneNumber << ": " << name;
                    std::cout << "\n<<<<<<<<<<------------->>>>>>>>>>\n";
                    clientName = name;
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found) {
        std::cout << "Клиент с номером телефона " << phoneNumber << " не найден." << std::endl;
    }

    RobjectClass.close(); // Закрываем файл
}






















/**
*
*       @brief: FUNCTION MAIN
*
*          "Точка входа в программу"
*
*/
int main() {
    Action userAction = AEXIT;
    FileType fileType = BACK;
    

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //
    // Создание объектов для работы с данными.
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    SClient client;
    SService service;
    SUsage usage;



    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    // 
    // Основной цикл программы, который будет выполняться до выхода.
    // 
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    while (true) {
        FShowMenuAction();
        int actionInput;
        std::cin >> actionInput;
        userAction = static_cast<Action>(actionInput);

        if (userAction == Action::AEXIT) break;

        if (userAction == Action::AINPUT || userAction == Action::AREAD) {
            FShowMenuFile();
            int fileInput;
            std::cin >> fileInput;
            fileType = static_cast<FileType>(fileInput);

            if (fileType == BACK) continue; // Возврат в главное меню

            HandleFileOperation(userAction, fileType, client, service, usage);
        } else if(userAction == Action::ACREATE) {
            std::string fileName;
            std::cout << "Input Name File: ";
            std::cin >> fileName;

            FShowMenuFile();
            int fileInput;
            std::cin >> fileInput;
            fileType = static_cast<FileType>(fileInput);

            if (fileType == BACK) continue; // Возврат в главное меню

            HandleFileOperation(userAction, fileType, fileName, client, service, usage);
        } else if (userAction == Action::ATASK) {
            std::string NameOfTfeClientYouAreLooking;
            std::string phoneNumberOfTheDesiredClient;
            std::string serviceCodeOfTheDesiredPhoneNumber;
            std::string serviceNameOfTheDesiredServiceCode;
            
            std::cout << "Input name of the clint you are looking: ";

            std::cin.ignore();
            std::getline(std::cin, NameOfTfeClientYouAreLooking);

            std::cout << "\n\n\n";

            // Берем информацию из файла клиента
            findClientPhoneNumber(NameOfTfeClientYouAreLooking, phoneNumberOfTheDesiredClient);
            findServiceNumberByPhone(phoneNumberOfTheDesiredClient, serviceCodeOfTheDesiredPhoneNumber);
            findServiceNameByCode(serviceCodeOfTheDesiredPhoneNumber, serviceNameOfTheDesiredServiceCode);
            
            

        } else { // Обработка неверного ввода
            std::cerr << "Invalid input. Expected 1, 2, or 0.\n";
        }
    }

    return EXIT_SUCCESS;
}