#include "column.h"
#include <stdexcept>
#include <vector>

class Table {
private:
    std::string tableName;
    std::vector<ColumnBase> columns;

public:
    Table(const std::string& tableFile, const std::string& tableName);

    Table(const Table &other);

    Table &operator=(const Table &other);

    template<typename T>
    void addColumn(Column<T> column);

    void removeColumn(int index);

    int getSize();

    void print();
};
