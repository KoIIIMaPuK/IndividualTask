#include "SClient.h"
#include "SService.h"
#include "SUsage.h"
#include "include.h"

#include <iostream>
#include <fstream>


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
enum FileType { CLIENT = 1, SERVICE, USAGE, BACK };












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
    std::ofstream reportFile("TextFilesFolder/Action.txt", std::ios::app); // Открываем файл отчета в режиме добавления

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
            client.FReadFileSymbolically(RobjectClass);
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
            service.FReadFileSymbolically(RobjectClass);
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
            usage.FReadFileSymbolically(RobjectClass);
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
    std::ofstream reportFile("TextFilesFolder/Action.txt", std::ios::app); // Открываем файл отчета в режиме добавления

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
            client.FReadFileSymbolically(RobjectClass);
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
            service.FReadFileSymbolically(RobjectClass);
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
            usage.FReadFileSymbolically(RobjectClass);
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
            std::cout << "Input Path-to-Name/Name File: ";
            std::cin >> fileName;

            FShowMenuFile();
            int fileInput;
            std::cin >> fileInput;
            fileType = static_cast<FileType>(fileInput);

            if (fileType == BACK) continue; // Возврат в главное меню

            HandleFileOperation(userAction, fileType, fileName, client, service, usage);
        } else if (userAction == Action::ATASK) {
            std::cout << "Error: not found";
        } else { // Обработка неверного ввода
            std::cerr << "Invalid input. Expected 1, 2, or 0.\n";
        }
    }

    return EXIT_SUCCESS;
}