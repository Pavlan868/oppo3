#include "pch.h"

#include "CppUnitTest.h"

#include <iostream>
#include <sstream>
#include <vector>

#include "ConsoleApplication12/CarInfo.h"
#include "ConsoleApplication12/reader.h"
#include "ConsoleApplication12/Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
    TEST_CLASS(CarInfoTests)
    {
    public:
        TEST_METHOD(TestPrintCarInfo)
        {
            // Create a CarInfo instance for testing
            CarInfo car;
            car.date.day = 13;
            car.date.month = 12;
            car.date.year = 2003;
            car.carNumber = "D530FY";

            // Assert that the printCarInfo method works as expected
            std::stringstream buffer;
            car.printCarInfo(buffer);


            Assert::AreEqual(std::string("Date: 13.12.2003, Car number: D530FY\n"), buffer.str());


            if (buffer.str() == "Date: 13.12.2003, Car number: D530FY\n") {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("TestPrintCarInfo: Success");
            }
            else {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("TestPrintCarInfo: Failure");
            }
      
        }

        TEST_METHOD(ValidCarNumber)
        {
            CarInfo car;

            // Проверка валидного номера
            car.carNumber = "A123BC";
            Assert::IsTrue(car.isValidCarNumber(car.carNumber));
            if (car.isValidCarNumber(car.carNumber)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Success\n");
            }

            Assert::IsTrue(car.isValidCarNumber("A123BC"));
            Assert::IsTrue(car.isValidCarNumber("D530FY"));
            Assert::IsTrue(car.isValidCarNumber("U408TY"));
            Assert::IsTrue(car.isValidCarNumber("G441RT"));
            Assert::IsTrue(car.isValidCarNumber("F862KL"));
            Assert::IsTrue(car.isValidCarNumber("A132CB"));
            Assert::IsTrue(car.isValidCarNumber("R541KL"));
            Assert::IsTrue(car.isValidCarNumber("P842OL"));
            Assert::IsTrue(car.isValidCarNumber("T011EW"));

            // TODO: добавить несколько случаев (OK)

        }

        TEST_METHOD(InvalidCarNumber)
        {
            // TODO: перенести в отдельную группу  ---> InvalidCarNumber (OK)
            // Проверка невалидных номеров
            CarInfo car;
            car.carNumber = "1234BC"; // отсутствует начальная буква
            Assert::IsFalse(car.isValidCarNumber(car.carNumber));
            //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - отсутствует начальная буква\n");
            if (car.isValidCarNumber(car.carNumber)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - отсутствует начальная буква\n");
            }


            car.carNumber = "A123B";  // слишком короткий номер
            Assert::IsFalse(car.isValidCarNumber(car.carNumber));
            //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - слишком короткий номер\n");
            if (car.isValidCarNumber(car.carNumber)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - слишком короткий номер\n");
            }


            car.carNumber = "A12BCD"; // четыре числа
            Assert::IsFalse(car.isValidCarNumber(car.carNumber));
            //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - четыре числа\n");
            if (car.isValidCarNumber(car.carNumber)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - четыре числа\n");
            }


            car.carNumber = "A12B3C"; // число вместо второй последней буквы
            Assert::IsFalse(car.isValidCarNumber(car.carNumber));
            //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - число вместо второй последней буквы\n");
            if (car.isValidCarNumber(car.carNumber)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("ValidateCarNumber: Failure - число вместо второй последней буквы\n");
            }
        }
    };

    TEST_CLASS(ReaderTests)
    {
    public:
        TEST_METHOD(TestReadCarInfo)
        {
            std::vector<CarInfo> carList;

            std::ifstream inputFile("D:\\avtomobili.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening the file." << std::endl;
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("Error opening the file.");

                exit(1);
            }
            readCarInfo(inputFile, carList);

                // Assuming you have a specific file with known data, you can check if carList is as expected.
            if (carList.size() > 0) {
                // Ensure carList is not empty
                Assert::IsTrue(true, L"Car list is not empty.");

                if (!carList.empty()) {
                    // Check the first car's carNumber
                    Assert::AreEqual("D530FY", carList[0].carNumber.c_str(), L"First car's carNumber is not as expected.");
                    //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("D530FY, First car's carNumber is not as expected.");
                    if (!carList.empty()) {
                        Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("InvalidDate1Test: Success\n");
                    }
                    else {
                        Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("InvalidDate1Test: Failure");
                    }


                }
            }
            else {
                // Output an error message if the test failed
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("TestReadCarInfo failed: Car list is empty.");
            }

        }
    };

    TEST_CLASS(DateValidityTest)
    {
    public:
        TEST_METHOD(ValidDateTest)
        {
            Assert::IsTrue(Date{ 13, 12, 2003 }.isValid());
            Assert::IsTrue(Date{ 20, 10, 1992 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 2024 }.isValid());
            Assert::IsTrue(Date{ 28, 02, 2023 }.isValid());
            Assert::IsTrue(Date{ 05, 07, 2005 }.isValid());
            // TODO: добавить несколько случаев (OK)
            //...
            Assert::IsTrue(Date{ 29, 02, 1992 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 1996 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 2000 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 2004 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 2008 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 2012 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 2016 }.isValid());
            Assert::IsTrue(Date{ 29, 02, 2020 }.isValid());

            Assert::IsTrue(Date{ 01, 02, 1998 }.isValid());
            Assert::IsTrue(Date{ 07, 07, 2007 }.isValid());

            Logger::WriteMessage("ValidDateTest: Success\n");
        }

        TEST_METHOD(DateBefore1990Test)
        {
            Date dateBefore1990;
            dateBefore1990.day = 1;
            dateBefore1990.month = 1;
            dateBefore1990.year = 1989;

            // Проверяем недопустимую дату до 1990 года
            Assert::IsTrue(Date::isDateValid(dateBefore1990));
            //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("DateBefore1990Test: Success");
            if (Date::isDateValid(dateBefore1990)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("DateBefore1990Test: Success\n");
            }
            else {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("DateBefore1990Test: Failure");
            }
        }

        TEST_METHOD(DateAfter2023Test)
        {
            Date dateAfter2023;
            dateAfter2023.day = 1;
            dateAfter2023.month = 1;
            dateAfter2023.year = 2024;

            // Проверяем недопустимую дату после 2023 года
            Assert::IsTrue(Date::isDateValid(dateAfter2023));
            //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("DateAfter2023Test:: Success");
            if (Date::isDateValid(dateAfter2023)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("DateAfter2023Test: Failure \n");
            }
            else {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("DateAfter2023Test: Success");
            }
        }

        TEST_METHOD(InvalidDate2Test)
        {
            Date invalidDate2;
            invalidDate2.day = 31;
            invalidDate2.month = 2;
            invalidDate2.year = 2023;

            // Проверяем недопустимую дату
            Assert::IsFalse(Date::isDateValid(invalidDate2));
            Assert::IsFalse(Date{ -1, 07, 2005 }.isValid());
            Assert::IsFalse(Date{ 0, 06, 2022 }.isValid());
            Assert::IsFalse(Date{ -1, 07, 2005 }.isValid());
            // TODO: добавить несколько случаев (OK)
            Assert::IsFalse(Date{ 29, 02, 2023 }.isValid());
            Assert::IsFalse(Date{ 29, 02, 20017 }.isValid());
            Assert::IsFalse(Date{ 29, 02, 2005 }.isValid());
            Assert::IsFalse(Date{ 29, 02, 2-04 }.isValid());
            Assert::IsFalse(Date{ -10, 11, 2006 }.isValid());
            Assert::IsFalse(Date{ 01, -7, 2023 }.isValid());


            //Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("InvalidDate2Test:: Success");
            if (Date::isDateValid(invalidDate2)) {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("InvalidDate2Test: Failure \n");
            }
            else {
                Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage("InvalidDate2Test: Success");
            }
        }
    };
}
