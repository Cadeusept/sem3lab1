#include <nlohmann/json.hpp>
#include <student.hpp>
#include <fstream>
#include <iostream>


void print(const Student& student, std::ostream& os) {
    //сделать для остальных атрибутов student проверку
    if (student.debt.type() == typeid(std::nullptr_t)) {
        os << "null";
    } else if (student.debt.type() == typeid(std::string)) {
        os << std::any_cast<std::string>(student.debt);
    } else {
        os
          << std::any_cast<std::vector<std::string> >(student.debt).size()
          << " items";
    }
}

void print(const std::vector<Student>& students, std::ostream& os) {

    //елать таблицу вывода
    for (auto const& student : students) {
        print(student, os);
    }
}

int main() {
    std::string jsonPath = "~/Рабочий стол/students.json";


    std::ifstream file{jsonPath};
    if (!file) {
        throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    std::vector<Student> students;
    for (auto const& item : data.at("items")) {
        Student student;
        from_json(item, student);
        students.push_back(student);
    }
    //нужно проверки сделатб
    print(students, std::cout);

}


