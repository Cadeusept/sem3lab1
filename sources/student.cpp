#include "student.hpp"

auto get_name(const json& j) -> std::string {
    if (j.is_null())
        return "";
    else
        return j.get<std::string>();
}

auto get_group(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else
        return j.get<std::size_t>();
}

auto get_avg(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else if (j.is_number_float())
        return j.get<std::double_t>();
    else
        return j.get<std::size_t>();
}

auto get_debt(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else
        return j.get<std::vector<std::string> >();
}

void from_json(const json& j, Student& s) {
    s.name = get_name(j.at("name"));
    s.group = get_group(j.at("group"));
    s.avg = get_avg(j.at("avg"));
    s.debt = get_debt(j.at("debt"));
}

std::string get_str_from_name(std::string name){
    if (!name.empty())
        return name;
    else
        return "null";
}

std::string get_str_from_group(std::any group){
    if (group.type()==typeid(std::nullptr_t))
        return "null";
    else if (group.type()==typeid(std::string))
        return std::any_cast<std::string>(group);
    else if (group.type()==typeid(std::size_t))
        return std::to_string(std::any_cast<std::size_t>(group));
    else
        throw std::invalid_argument{"Unexpected 'group' type"};
}

std::string get_str_from_avg(std::any avg){
    if (avg.type()==typeid(std::nullptr_t))
        return "null";
    else if (avg.type()==typeid(std::string))
        return std::any_cast<std::string>(avg);
    else if (avg.type()==typeid(std::double_t))
        return std::to_string(std::any_cast<std::double_t>(avg));
    else if (avg.type()==typeid(std::size_t))
        return std::to_string(std::any_cast<std::size_t>(avg));
    else
        throw std::invalid_argument{"Unexpected 'avg' type"};
}

std::string get_str_from_debt(std::any debt){
    if (debt.type()==typeid(std::nullptr_t))
        return "null";
    else if (debt.type()==typeid(std::string))
        return std::any_cast<std::string>(debt);
    else if (debt.type()==typeid(std::vector<std::string>))
        return std::to_string(std::any_cast< std::vector<std::string> >(debt).size()) +" items";
    else
        throw std::invalid_argument{"Unexpected 'debt' type"};
}

void print(const Student& student, std::ostream& os, unsigned max_name, unsigned max_group, unsigned max_avg, unsigned max_debt) {
    os << "|" << std::left <<std::setw(max_name);
    os << get_str_from_name(student.name);

    os << "|" <<std::setw(max_group);
    os << get_str_from_group(student.group);

    os << "|" <<std::setw(max_avg);
    os << get_str_from_avg(student.avg);

    os << "|" <<std::setw(max_debt);
    os << get_str_from_debt(student.debt);
    os << "|\n";
}



void print(const std::vector<Student>& students, std::ostream& os) {
    unsigned max_name=0; unsigned max_group=0; unsigned max_avg=0; unsigned max_debt=0;
    for (auto const& student : students){
        if (get_str_from_name(student.name).length()>max_name)
            max_name=get_str_from_name(student.name).length();
        if (get_str_from_group(student.group).length()>max_group)
            max_group=get_str_from_group(student.group).length();
        if (get_str_from_avg(student.avg).length()>max_avg)
            max_avg=get_str_from_avg(student.avg).length();
        if (get_str_from_debt(student.debt).length()>max_debt)
            max_debt=get_str_from_debt(student.debt).length();
    }

    std::string table_string;
    table_string+="|";
    table_string+=std::string(max_name,'-');
    table_string+="|";
    table_string+=std::string(max_group,'-');
    table_string+="|";
    table_string+=std::string(max_avg,'-');
    table_string+="|";
    table_string+=std::string(max_debt,'-');
    table_string+="|\n";

    os << table_string;
    os << "|" << std::left << std::setw(max_name) << "Name" << "|" << std::setw(max_group) << "Group" << "|"
       << std::setw(max_avg) << "Avg" << "|" << std::setw(max_debt) << "Debt" << "|\n";

    //сделать таблицу вывода
    for (auto const& student : students) {
        os << table_string;
        print(student, os, max_name, max_group, max_avg, max_debt);
    }

    os << table_string;
}

void parse_json(std::string jsonPath){
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

    print(students, std::cout);
}



