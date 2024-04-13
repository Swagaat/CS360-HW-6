#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class dateType {
public:
    dateType(int m = 1, int d = 1, int y = 1900);
    void setDate(int m, int d, int y);
    bool isLeapYear() const;
    void printDate() const;

private:
    int month;
    int day;
    int year;
};

dateType::dateType(int m, int d, int y) {
    setDate(m, d, y);
}

void dateType::setDate(int m, int d, int y) {
    if (m >= 1 && m <= 12) {
        month = m;
    } else {
        std::cout << "Invalid month.\n";
        month = 1;
    }

    if (d >= 1 && d <= 31) {
        day = d;
    } else {
        std::cout << "Invalid day.\n";
        day = 1;
    }

    if (y >= 1900 && y <= 2100) {
        year = y;
    } else {
        std::cout << "Invalid year.\n";
        year = 1900;
    }
}

bool dateType::isLeapYear() const {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void dateType::printDate() const {
    std::cout << month << "/" << day << "/" << year;
}

class addressType {
public:
    addressType(std::string street = "", std::string city = "", std::string state = "", std::string zip = "");
    void setAddress(std::string street, std::string city, std::string state, std::string zip);
    void printAddress() const;

private:
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;
};

addressType::addressType(std::string street, std::string city, std::string state, std::string zip) {
    setAddress(street, city, state, zip);
}

void addressType::setAddress(std::string street, std::string city, std::string state, std::string zip) {
    streetAddress = street;
    this->city = city;
    this->state = state;
    zipCode = zip;
}

void addressType::printAddress() const {
    std::cout << streetAddress << ", " << city << ", " << state << " " << zipCode << std::endl;
}

class personType {
public:
    void print() const;
    void setName(std::string first, std::string last);
    std::string getFirstName() const;
    std::string getLastName() const;
    personType(std::string first = "", std::string last = "");

private:
    std::string firstName;
    std::string lastName;
};

void personType::print() const {
    std::cout << firstName << " " << lastName;
}

void personType::setName(std::string first, std::string last) {
    firstName = first;
    lastName = last;
}

std::string personType::getFirstName() const {
    return firstName;
}

std::string personType::getLastName() const {
    return lastName;
}

personType::personType(std::string first, std::string last) {
    firstName = first;
    lastName = last;
}

class extPersonType : public personType {
public:
    extPersonType(std::string first = "", std::string last = "");
    void setInfo(std::string first, std::string last, std::string phone, dateType dob, std::string relation);
    void printInfo() const;

private:
    std::string phoneNumber;
    dateType dateOfBirth;
    std::string relationship;
};

extPersonType::extPersonType(std::string first, std::string last) : personType(first, last) {}

void extPersonType::setInfo(std::string first, std::string last, std::string phone, dateType dob, std::string relation) {
    setName(first, last);
    phoneNumber = phone;
    dateOfBirth = dob;
    relationship = relation;
}

void extPersonType::printInfo() const {
    print();
    std::cout << ", Phone: " << phoneNumber << ", DOB: ";
    dateOfBirth.printDate();
    std::cout << ", Relation: " << relationship << std::endl;
}

class addressBookType {
public:
    void loadFromFile(std::string filename);
    void sortByLastName();
    void searchByLastName(std::string lastName);
    void printPersonInfo(std::string lastName);
    void printBirthdaysInMonth(int month);
    void printBetweenLastNames(std::string start, std::string end);
    void printByRelationship(std::string relation);

private:
    std::vector<extPersonType> addressBook;
};

void addressBookType::loadFromFile(std::string filename) {
}

void addressBookType::sortByLastName() {
    std::sort(addressBook.begin(), addressBook.end(), [](const extPersonType& a, const extPersonType& b) {
        return a.getLastName() < b.getLastName();
    });
}

void addressBookType::searchByLastName(std::string lastName) {
    auto it = std::find_if(addressBook.begin(), addressBook.end(), [&](const extPersonType& person) {
        return person.getLastName() == lastName;
    });
    if (it != addressBook.end()) {
        it->printInfo();
    } else {
        std::cout << "Person not found.\n";
    }
}
int main() {
    // Test the classes here
    dateType date1(2, 29, 2020);
    date1.printDate();
  std::cout << std::endl;
  dateType newDate(2, 29, 2020);
  newDate.printDate();
  std::cout << " is a leap year: " << newDate.isLeapYear() << std::endl;

  addressType newAddress("123 Main St", "City", "State", "12345");
  newAddress.printAddress();

  extPersonType newPerson("Jane", "Doe");
  newPerson.setInfo("Jane", "Doe", "123-456-7890", newDate, "Family");
  newPerson.printInfo();

    return 0;
}
