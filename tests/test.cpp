//Copyright 2021 Matthew abobus1488822@yandex,ru

#include <gtest/gtest.h>
#include <student.hpp>

TEST(Exceptions, Wrong_file_path){
    EXPECT_THROW(parse_json(FILE_DIR"test_file1.json"),std::runtime_error);
}

TEST(Exceptions, Empty_file_path){
    EXPECT_THROW(parse_json(FILE_DIR""),std::runtime_error);
}

TEST(Exceptions, Wrong_number_of_items){
    EXPECT_THROW(parse_json(FILE_DIR"test_file2.json"),std::runtime_error);
}

TEST(Exceptions, Unexpected_group_type){
    EXPECT_THROW(get_str_from_group(3.14),std::invalid_argument);
}

TEST(Exceptions, Unexpected_avg_type){
    EXPECT_THROW(get_str_from_avg("ABOBA"),std::invalid_argument);
}

TEST(Exceptions, Unexpected_debt_type){
    EXPECT_THROW(get_str_from_debt(3.14),std::invalid_argument);
}

TEST(Equality, EqualityTest1){
    std::ifstream file{FILE_DIR"test_file3.json"};
    json data;
    file>>data;

    std::vector<Student> students=get_vector_from_json(data);
    std::stringstream parsed;
    print(students,parsed);

    EXPECT_EQ(parsed.str(),
              "|---------------|---------|--------|-------|\n"
              "|Name           |Group    |Avg     |Debt   |\n"
              "|---------------|---------|--------|-------|\n"
              "|Abobus Amogusov|1        |4.25    |3 items|\n"
              "|---------------|---------|--------|-------|\n"
              "|Valentin Dyadka|Antihype |5       |Kremlin|\n"
              "|---------------|---------|--------|-------|\n"
              "|Andrei Zamai   |President|5.000000|null   |\n"
              "|---------------|---------|--------|-------|\n"
              "|Dirty Monk     |Beast    |1.000000|2 items|\n"
              "|---------------|---------|--------|-------|\n");
}