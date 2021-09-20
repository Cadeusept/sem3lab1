#include <nlohmann/json.hpp>
#include "student.hpp"
#include <fstream>
#include <iostream>


void print(const Student& student, std::ostream& os) {
    //сделать для остальных атрибутов student проверку
    if (student.group.type()==typeid(std::string)){
        os << std::any_cast<std::string>(student.group);
//    } else if (student.group.type()==typeid(std::nullptr_t)) {
//        os << "null";
    } else {
        os << std::any_cast<std::string>(student.group) << "group";
    }

//    if (student.avg.type()!=typeid(std::nullptr_t)){
//        os << std::any_cast<std::string>(student.avg);
//    } else os << "no data";

    if (student.debt.type() == typeid(std::nullptr_t)) {
        os << "null";
    } else if (student.debt.type() == typeid(std::string)) {
        os << std::any_cast<std::string>(student.debt);
    } else {
        os
          << std::any_cast< std::vector<std::string> >(student.debt).size()
          << " items";
    }
}

void print(const std::vector<Student>& students, std::ostream& os) {
    unsigned long max_name=0; unsigned long max_group=0; unsigned long max_avg=0; unsigned long max_debt=0;
    for (auto const& student : students){
        if (student.name.length()>max_name) max_name=student.name.length();
        if (std::any_cast<std::string>(student.group).length()>max_group) max_group=std::any_cast<std::string>(student.group).length();
        if (std::any_cast<std::string>(student.avg).length()>max_avg) max_avg=std::any_cast<std::string>(student.avg).length();
        if ((student.debt.type() == typeid(std::string) && std::any_cast<std::string>(student.debt).length()>max_debt) ||
                (student.debt.type() != typeid(std::string) && (student.debt.type() != typeid(std::nullptr_t) && std::any_cast< std::vector<std::string> >(student.debt).size()>max_debt)))
            max_debt=std::any_cast< std::vector<std::string> >(student.debt).size();
    }

    //сделать таблицу вывода
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


