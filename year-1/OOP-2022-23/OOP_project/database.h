#include "table.h"
#include <stdexcept>
#include <vector>
#include <string>

struct databaseStructure {
    std::string tableName;
    std::string path;
};

class Database {
private:
    std::string fileName;
    std::vector<databaseStructure> tables;

public:
    Database() = delete;

    Database(std::string fileName);

    Database(const Database &other);

    Database &operator=(const Database &other);

    void addTable(databaseStructure table);

    void removeTable(int index);

    int getSize();

    void print();

};