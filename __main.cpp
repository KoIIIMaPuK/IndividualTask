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




/**
 * @brief Находит номер телефона клиента по его имени.
 *
 * Эта функция ищет номер телефона клиента в файле "Client.txt" по указанному имени клиента. 
 * Если клиент с таким именем найден, его номер телефона будет сохранён в переданном параметре.
 *
 * @param clientName Имя клиента, по которому производится поиск номера телефона.
 * @param clientPhoneNumber Ссылка на строку, в которую будет записан номер телефона клиента, если он найден.
 *
 * @throws std::runtime_error Если не удаётся открыть файл "Client.txt".
 *
 * @note Функция игнорирует регистр при сравнении имен клиентов. 
 *       Если клиент с указанным именем не найден, функция выводит сообщение об этом.
 *       В случае успешного поиска, номер телефона будет выведен на экран и сохранён в параметре clientPhoneNumber.
 */
void findClientPhoneNumber(const std::string& clientName, std::string& clientPhoneNumber) {
    std::ifstream RobjectClass("TextFilesFolder/Client.txt"); // Объект для чтения из файла
    if (!RobjectClass.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Client.txt");
    }

    std::string line;
    bool found = false;

    std::string lowerClientName = clientName;
    std::transform(lowerClientName.begin(), lowerClientName.end(), lowerClientName.begin(), ::tolower);

    while (std::getline(RobjectClass, line)) {
        std::stringstream ss(line);
        std::string name;
        std::string phoneNumber;

        if (std::getline(ss, name, ',')) {
            name.erase(name.find_last_not_of(" ") + 1);
            name.erase(0, name.find_first_not_of(" "));

            std::string lowerName = name;
            std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

            if (lowerName == lowerClientName) {
                if (std::getline(ss, phoneNumber, ',')) {
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

    RobjectClass.close();
}




/**
 * @brief Находит номер услуги по номеру телефона.
 *
 * Эта функция ищет номер услуги в файле "Usage.txt" по указанному номеру телефона. 
 * Если услуга с таким номером телефона найдена, её номер будет сохранён в переданном параметре.
 *
 * @param phoneNumber Номер телефона, по которому производится поиск номера услуги.
 * @param serviceNumber Ссылка на строку, в которую будет записан номер услуги, если он найден.
 *
 * @throws std::runtime_error Если не удаётся открыть файл "Usage.txt".
 *
 * @note Если услуга с указанным номером телефона не найдена, функция выводит сообщение об этом.
 *       В случае успешного поиска, номер услуги будет выведен на экран и сохранён в параметре serviceNumber.
 */
void findServiceNumberByPhone(const std::string& phoneNumber, std::string& serviceNumber) {
    std::ifstream usageFile("TextFilesFolder/Usage.txt");
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




/**
 * @brief Находит имя услуги по её коду.
 *
 * Эта функция ищет имя услуги в файле "Service.txt" по указанному коду услуги. 
 * Если услуга с таким кодом найдена, её имя будет сохранено в переданном параметре.
 *
 * @param serviceCode Код услуги, по которому производится поиск имени услуги.
 * @param serviceName Ссылка на строку, в которую будет записано имя услуги, если оно найдено.
 *
 * @throws std::runtime_error Если не удаётся открыть файл "Service.txt".
 *
 * @note Если услуга с указанным кодом не найдена, функция выводит сообщение об этом.
 *       В случае успешного поиска, имя услуги будет выведено на экран и сохранено в параметре serviceName.
 */
void findServiceNameByCode(const std::string& serviceCode, std::string& serviceName) {
    std::ifstream serviceFile("TextFilesFolder/Service.txt");
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

    serviceFile.close();
}











/**
 * @brief Находит код услуги по её названию.
 *
 * Эта функция ищет код услуги в файле "Service.txt" по указанному названию услуги. 
 * Если услуга с таким названием найдена, её код будет сохранён в переданном параметре.
 *
 * @param serviceName Название услуги, по которому производится поиск кода услуги.
 * @param serviceCode Ссылка на строку, в которую будет записан код услуги, если он найден.
 *
 * @throws std::runtime_error Если не удаётся открыть файл "Service.txt".
 *
 * @note Поиск осуществляется без учёта регистра. Если услуга с указанным именем не найдена, 
 *       функция выводит сообщение об этом. В случае успешного поиска, код услуги будет выведен на экран 
 *       и сохранён в параметре serviceCode.
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




/**
 * @brief Находит номер телефона по коду услуги.
 *
 * Эта функция ищет номер телефона в файле "Usage.txt" по указанному коду услуги. 
 * Если код услуги найден, соответствующий номер телефона будет сохранён в переданном параметре.
 *
 * @param serviceCode Код услуги, по которому производится поиск номера телефона.
 * @param phoneNumber Ссылка на строку, в которую будет записан номер телефона, если он найден.
 *
 * @throws std::runtime_error Если не удаётся открыть файл "Usage.txt".
 *
 * @note Если услуга с указанным кодом не найдена, функция выводит сообщение об этом.
 *       В случае успешного поиска, номер телефона будет выведен на экран и сохранён в параметре phoneNumber.
 */
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




/**
 * @brief Находит имя клиента по номеру телефона.
 *
 * Эта функция ищет клиента в файле "Client.txt" по указанному номеру телефона. 
 * Если клиент с таким номером найден, его имя будет сохранено в переданном параметре.
 *
 * @param phoneNumber Номер телефона, по которому производится поиск клиента.
 * @param clientName Ссылка на строку, в которую будет записано имя клиента, если он найден.
 *
 * @throws std::runtime_error Если не удаётся открыть файл "Client.txt".
 *
 * @note Если клиент с указанным номером телефона не найден, функция выводит сообщение об этом.
 *       В случае успешного поиска, имя клиента будет выведено на экран и сохранено в параметре clientName.
 */
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
 * @brief Находит имена клиентов, которые использовали определённую услугу.
 *
 * Эта функция ищет клиентов, которые пользовались услугой с заданным именем. 
 * Читает данные из трёх файлов: 
 * - "Service.txt" для получения кода услуги по её имени,
 * - "Usage.txt" для нахождения записей об использовании услуги,
 * - "Client.txt" для получения имён клиентов по их телефонным номерам.
 *
 * @param serviceName Название услуги, по которой производится поиск клиентов.
 * @param clientNames Вектор, в который будут добавлены имена клиентов, использовавших услугу.
 *
 * @throws std::runtime_error Если не удаётся открыть один из файлов ("Service.txt", "Usage.txt" или "Client.txt").
 *
 * @note Если услуга с указанным именем не найдена, функция выводит сообщение об этом и завершает выполнение.
 *       Если клиенты, использовавшие услугу, не найдены, вектор clientNames останется пустым.
 */
void findClientsByServiceName(const std::string& serviceName, std::vector<std::string>& clientNames) {
    std::ifstream serviceFile("TextFilesFolder/Service.txt");
    if (!serviceFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Service.txt");
    }

    std::string line;
    std::string serviceCode;
    bool serviceFound = false;

    // Шаг 1: Найти код услуги по названию услуги
    while (std::getline(serviceFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string currentServiceName = line.substr(0, commaPos);
            currentServiceName.erase(currentServiceName.find_last_not_of(" ") + 1);
            currentServiceName.erase(0, currentServiceName.find_first_not_of(" "));

            if (currentServiceName == serviceName) {
                serviceCode = line.substr(commaPos + 1, line.find(',', commaPos + 1) - commaPos - 1);
                serviceCode.erase(serviceCode.find_last_not_of(" ") + 1);
                serviceCode.erase(0, serviceCode.find_first_not_of(" "));
                serviceFound = true;
                break;
            }
        }
    }

    serviceFile.close(); // Закрываем файл

    if (!serviceFound) {
        std::cout << "Услуга с названием " << serviceName << " не найдена." << std::endl;
        return;
    }

    std::ifstream usageFile("TextFilesFolder/Usage.txt");
    if (!usageFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Usage.txt");
    }

    while (std::getline(usageFile, line)) {
        std::stringstream ss(line);
        std::string currentPhoneNumber;
        std::string currentServiceCode;

        if (std::getline(ss, currentPhoneNumber, ',')) {
            // Убираем пробелы
            currentPhoneNumber.erase(currentPhoneNumber.find_last_not_of(" ") + 1);
            currentPhoneNumber.erase(0, currentPhoneNumber.find_first_not_of(" "));
            
            if (std::getline(ss, currentServiceCode, ',')) {
                currentServiceCode.erase(currentServiceCode.find_last_not_of(" ") + 1);
                currentServiceCode.erase(0, currentServiceCode.find_first_not_of(" "));
                
                if (currentServiceCode == serviceCode) {
                    // Найти имя клиента по номеру телефона
                    std::ifstream clientFile("TextFilesFolder/Client.txt");
                    if (!clientFile.is_open()) {
                        throw std::runtime_error("Failed to open file: TextFilesFolder/Client.txt");
                    }

                    std::string clientLine;
                    while (std::getline(clientFile, clientLine)) {
                        std::stringstream clientSS(clientLine);
                        std::string name;
                        std::string phone;

                        if (std::getline(clientSS, name, ',')) {
                            name.erase(name.find_last_not_of(" ") + 1);
                            name.erase(0, name.find_first_not_of(" "));
                            
                            if (std::getline(clientSS, phone, ',')) {
                                phone.erase(phone.find_last_not_of(" ") + 1);
                                phone.erase(0, phone.find_first_not_of(" "));
                                
                                if (phone == currentPhoneNumber) {
                                    clientNames.push_back(name);
                                    break; 
                                }
                            }
                        }
                    }

                    clientFile.close();
                }
            }
        }
    }

    usageFile.close();
}




/**
 * @brief Находит имена клиентов, которые использовали определённую услугу в заданном диапазоне дат.
 *
 * Эта функция ищет клиентов, которые пользовались услугой с заданным именем в указанный диапазон дат. 
 * Читает данные из трёх файлов: 
 * - "Service.txt" для получения кода услуги по её имени,
 * - "Usage.txt" для нахождения записей об использовании услуги в указанный период,
 * - "Client.txt" для получения имён клиентов по их телефонным номерам.
 *
 * @param serviceName Название услуги, по которой производится поиск клиентов.
 * @param startDate Дата начала диапазона, в котором необходимо искать использование услуги.
 * @param endDate Дата окончания диапазона, в котором необходимо искать использование услуги.
 * @param clientNames Вектор, в который будут добавлены имена клиентов, использовавших услугу в указанный период.
 *
 * @throws std::runtime_error Если не удаётся открыть один из файлов ("Service.txt", "Usage.txt" или "Client.txt").
 *
 * @note Если услуга с указанным именем не найдена, функция выводит сообщение об этом и завершает выполнение.
 *       Если клиенты, использовавшие услугу в заданный период, не найдены, вектор clientNames останется пустым.
 */
void findClientsByServiceNameAndDateRange(const std::string& serviceName, const std::tm& startDate, const std::tm& endDate, std::vector<std::string>& clientNames) {
    std::ifstream serviceFile("TextFilesFolder/Service.txt");
    if (!serviceFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Service.txt");
    }

    std::string line;
    std::string serviceCode;
    bool serviceFound = false;

    while (std::getline(serviceFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string currentServiceName = line.substr(0, commaPos);
            currentServiceName.erase(currentServiceName.find_last_not_of(" ") + 1);
            currentServiceName.erase(0, currentServiceName.find_first_not_of(" "));

            if (currentServiceName == serviceName) {
                serviceCode = line.substr(commaPos + 1, line.find(',', commaPos + 1) - commaPos - 1);
                serviceCode.erase(serviceCode.find_last_not_of(" ") + 1);
                serviceCode.erase(0, serviceCode.find_first_not_of(" "));
                serviceFound = true;
                break;
            }
        }
    }

    serviceFile.close();

    if (!serviceFound) {
        std::cout << "Услуга с названием " << serviceName << " не найдена." << std::endl;
        return;
    }

    std::ifstream usageFile("TextFilesFolder/Usage.txt");
    if (!usageFile.is_open()) {
        throw std::runtime_error("Failed to open file: TextFilesFolder/Usage.txt");
    }

    while (std::getline(usageFile, line)) {
        std::stringstream ss(line);
        std::string currentPhoneNumber;
        std::string currentServiceCode;
        std::string startDateStr, endDateStr;

        if (std::getline(ss, currentPhoneNumber, ',')) {
            currentPhoneNumber.erase(currentPhoneNumber.find_last_not_of(" ") + 1);
            currentPhoneNumber.erase(0, currentPhoneNumber.find_first_not_of(" "));
            
            if (std::getline(ss, currentServiceCode, ',') &&
                std::getline(ss, startDateStr, ',') &&
                std::getline(ss, endDateStr, ',')) {
                
                currentServiceCode.erase(currentServiceCode.find_last_not_of(" ") + 1);
                currentServiceCode.erase(0, currentServiceCode.find_first_not_of(" "));
                
                std::tm startUsageDate = {};
                std::istringstream startSS(startDateStr);
                startSS >> std::get_time(&startUsageDate, "%d.%m.%Y");

                std::tm endUsageDate = {};
                std::istringstream endSS(endDateStr);
                endSS >> std::get_time(&endUsageDate, "%d.%m.%Y");
                
                if (currentServiceCode == serviceCode) {
                    if ((std::difftime(std::mktime(&startUsageDate), std::mktime(const_cast<std::tm*>(&startDate))) >= 0 && 
                         std::difftime(std::mktime(const_cast<std::tm*>(&endDate)), std::mktime(&startUsageDate)) >= 0) ||
                        (std::difftime(std::mktime(&endUsageDate), std::mktime(const_cast<std::tm*>(&startDate))) >= 0 && 
                         std::difftime(std::mktime(const_cast<std::tm*>(&endDate)), std::mktime(&endUsageDate)) >= 0)) {
                        
                        std::ifstream clientFile("TextFilesFolder/Client.txt");
                        if (!clientFile.is_open()) {
                            throw std::runtime_error("Failed to open file: TextFilesFolder/Client.txt");
                        }

                        std::string clientLine;
                        while (std::getline(clientFile, clientLine)) {
                            std::stringstream clientSS(clientLine);
                            std::string name;
                            std::string phone;

                            if (std::getline(clientSS, name, ',')) {
                                name.erase(name.find_last_not_of(" ") + 1);
                                name.erase(0, name.find_first_not_of(" "));
                                
                                    if (std::getline(clientSS, phone, ',')) {
                                    phone.erase(phone.find_last_not_of(" ") + 1);
                                    phone.erase(0, phone.find_first_not_of(" "));
                                    
                                    if (phone == currentPhoneNumber) {
                                        clientNames.push_back(name);
                                        break;
                                    }
                                }
                            }
                        }
                        clientFile.close();
                    }
                }
            }
        }
    }

    usageFile.close();
}




/**
 * @brief Парсит файл параметров для извлечения названий услуг и дат.
 *
 * Эта функция читает файл с указанным именем и извлекает названия услуг и даты начала и окончания.
 * Названия услуг сохраняются в векторе, а даты сохраняются в структуре std::tm.
 *
 * @param filename Имя файла, который будет прочитан.
 * @param serviceNames Вектор, в который будут добавлены названия услуг.
 * @param startDate Структура std::tm, в которую будет записана дата начала.
 * @param endDate Структура std::tm, в которую будет записана дата окончания.
 *
 * @throws std::runtime_error Если не удаётся открыть файл с указанным именем.
 *
 * @note Файл должен содержать секции "[Service]" и "[Date]", после которых следуют названия услуг и даты в формате "дд.мм.гггг".
 *       Если в секции "[Date]" указано только одно значение, оно будет интерпретировано как дата начала, а второе значение — как дата окончания.
 */
void parseParamFile(const std::string& filename, std::vector<std::string>& serviceNames, std::tm& startDate, std::tm& endDate) {
    std::ifstream paramFile(filename);
    if (!paramFile.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    bool readingService = false;
    bool readingDate = false;

    while (std::getline(paramFile, line)) {
        line.erase(line.find_last_not_of(" \n\r\t") + 1);
        line.erase(0, line.find_first_not_of(" \n\r\t"));

        if (line.empty()) {
            continue;
        }

        if (line == "[Service]") {
            readingService = true;
            readingDate = false;
            continue;
        } else if (line == "[Date]") {
            readingService = false;
            readingDate = true;
            continue;
        }

        if (readingService) {
            serviceNames.push_back(line);
        } else if (readingDate) {
            if (startDate.tm_year == 0) {
                std::istringstream startSS(line);
                startSS >> std::get_time(&startDate, "%d.%m.%Y");
            } else {
                std::istringstream endSS(line);
                endSS >> std::get_time(&endDate, "%d.%m.%Y");
            }
        }
    }

    paramFile.close();
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
    // Создание объектов для работы с данными
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    SClient client;
    SService service;
    SUsage usage;



    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    // 
    // Основной цикл программы
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
/*
            std::string NameOfTfeClientYouAreLooking;
            std::string phoneNumberOfTheDesiredClient;
            std::string serviceCodeOfTheDesiredPhoneNumber;
            std::string serviceNameOfTheDesiredServiceCode;

            std::vector<std::string> clientNames;
            
            findClientsByServiceName("SMS", clientNames);

/
            std::cout << "Input name of the clint you are looking: ";

            std::cin.ignore();
            std::getline(std::cin, NameOfTfeClientYouAreLooking);

            std::cout << "\n\n\n";

            // Берем информацию из файла клиента
            findClientPhoneNumber(NameOfTfeClientYouAreLooking, phoneNumberOfTheDesiredClient);
            findServiceNumberByPhone(phoneNumberOfTheDesiredClient, serviceCodeOfTheDesiredPhoneNumber);
            findServiceNameByCode(serviceCodeOfTheDesiredPhoneNumber, serviceNameOfTheDesiredServiceCode);
            
            

            for (const auto& name : clientNames) 
            {
                std::cout << name << std::endl;
            }
*/
            try {
                std::string currentTime = GetCurrentTime();
                std::vector<std::string> serviceNames;
                std::tm startDate = {};
                std::tm endDate = {};

                std::ofstream actionFile("TextFilesFolder/Action.txt", std::ios::app);

                parseParamFile("TextFilesFolder/Param.ini", serviceNames, startDate, endDate);

                std::vector<std::string> clientNames;

                for (const auto& serviceName : serviceNames) {
                    findClientsByServiceNameAndDateRange(serviceName, startDate, endDate, clientNames);
                }



                // Выводим имена клиентов
                std::cout << "Clients who used the services during the specified period:" << std::endl;
                for (const auto& name : clientNames) {
                    std::cout << name << std::endl;
                }



                // Запись в файл Report.txt
                std::ofstream reportFile("TextFilesFolder/Report.txt");
                if (!reportFile.is_open()) {
                    throw std::runtime_error("Failed to open file: Report.txt");
                }

                reportFile << "Clients who used the services during the specified period:\n";
                for (const auto& name : clientNames) {
                    reportFile << name << "\n";
                }

                reportFile.close();
                std::cout << "The report is written to a file Report.txt." << std::endl;
                actionFile << currentTime << " - The report is written to a file Report.txt.\n"; // Записываем в отчет

            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }

        } else { // Обработка неверного ввода
            std::cerr << "Invalid input. Expected 1, 2, 3, 4 or 0.\n";
        }
    }

    return EXIT_SUCCESS;
}