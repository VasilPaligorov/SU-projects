#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>

class ColumnBase {
public:
    virtual ~ColumnBase() = default;
    virtual void print();
};

template<typename T>
class Column : public ColumnBase {

private:
    std::vector<T> data;

public:

    Column() = default;

    Column(const Column &other);

    Column &operator=(const Column &other);

    T &operator[](int index);

    void addElement(T element);

    void removeElement(int index);

    int getSize();

    void print() override;
};

template<typename T>
Column<T>::Column(const Column &other) {
    this->data = other.data;
}

template<typename T>
Column<T> &Column<T>::operator=(const Column &other) {
    if (this != &other) {
        this->data = other.data;
    }

    return *this;
}

template<typename T>
T &Column<T>::operator[](int index) {
    if (index < 0 || index >= this->data.size()) {
        throw std::out_of_range("Index out of range");
    }

    return this->data[index];
}

template<typename T>
void Column<T>::addElement(T element) {
    this->data.push_back(element);
}

template<typename T>
void Column<T>::removeElement(int index) {
    if (index < 0 || index >= this->data.size()) {
        throw std::out_of_range("Index out of range");
    }

    this->data.erase(this->data.begin() + index);
}

template<typename T>
int Column<T>::getSize() {
    return this->data.size();
}

template<typename T>
void Column<T>::print() {
    for (int i = 0; i < this->data.size(); ++i) {
        std::cout << this->data[i] << " ";
    }

    std::cout << std::endl;
}