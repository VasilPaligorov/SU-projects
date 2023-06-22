#include "table.h"
#include <stdexcept>
#include <fstream>


Table::Table(const std::string &tableFile, const std::string &tableName)
        : tableName(tableName) {
//    std::ifstream file(tableFile);
//    if (!file.is_open()) {
//        throw std::invalid_argument("File not found!");
//    }
//    std::string name;
//    int numberOfColumns;
//    file >> name >> numberOfColumns;
//    if (numberOfColumns < 0) {
//        throw std::invalid_argument("Invalid number of columns!");
//    }
//
//    for (int i = 0; i < numberOfColumns; ++i) {
//        std::string type;
//        file >> type;
//        if (type == "int") {
//            Column<int> column;
//            int numberOfElements;
//            file >> numberOfElements;
//            for (int j = 0; j < numberOfElements; ++j) {
//                int element;
//                file >> element;
//                column.addElement(element);
//            }
//            std::dynamic_pointer_cast<ColumnBase>(std::make_shared<Column<int>>(column));
//            this->columns.push_back(column);
//        } else if (type == "double") {
            Column<double> column;
//            int numberOfElements;
//            file >> numberOfElements;
//            for (int j = 0; j < numberOfElements; ++j) {
//                double element;
//                file >> element;
//                column.addElement(element);
//            }
//            this->columns.push_back(column);
//        } else if (type == "string") {
//            Column<std::string> column;
//            int numberOfElements;
//            file >> numberOfElements;
//            for (int j = 0; j < numberOfElements; ++j) {
//                std::string element;
//                file >> element;
//                column.addElement(element);
//            }
//            this->columns.push_back(column);
//        } else {
//            throw std::invalid_argument("Invalid type!");
//        }
//    }
//
//    file.close();

            this->columns.push_back(column);
            this->columns.push_back(column);
            this->columns.push_back(column);

}

Table::Table(const Table &other) {
    this->tableName = other.tableName;
    this->columns = other.columns;
}

Table &Table::operator=(const Table &other) {
    if (this != &other) {
        this->tableName = other.tableName;
        this->columns = other.columns;
    }

    return *this;
}

void Table::removeColumn(int index) {
    if (index < 0 || index >= this->columns.size()) {
        throw std::out_of_range("Index out of range!");
    }

    this->columns.erase(this->columns.begin() + index);
}

int Table::getSize() {
    return this->columns.size();
}

void Table::print() {
    std::cout << this->tableName << std::endl;
    for (int i = 0; i < this->columns.size(); ++i) {
        std::cout << i << " ; ";
        this->columns[i].print();
    }
}

