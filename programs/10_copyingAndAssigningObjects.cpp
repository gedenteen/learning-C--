#include <iostream>
using namespace std;

struct IntArray {
    IntArray(int size)
    {
        size_ = size;
        data_ = new int[size];
        for (int i = 0; i < size; i++) {
            data_[i] = rand() % size;
        }
    }

    /* Copy constructor that allocating memory and copying data from input object.
     * If delete this constructor, then error occurs.
     */
    IntArray(IntArray const& a)
        : size_(a.size_), data_(new int[size_])
    {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = a.data_[i];
    }
    ~IntArray()
    {
        delete[] data_;
    }

    /* Assignment operator that allocating memory and copying data from input object.
     * If delete this operator, then error occurs.
     */
    IntArray& operator =(IntArray const& a)
    {
        if (this != &a) {
            delete[] data_;
            size_ = a.size_;
            data_ = new int[size_];
            for (size_t i = 0; i != size_; ++i)
                data_[i] = a.data_[i];
        }
        return *this;
    }

    void outputData()
    {
        for (int i = 0; i < size_; i++) {
            cout << data_[i] << " ";
        }
        cout << "\n";
    }

private:
    size_t size_;
    int* data_;
};
int main() {
    IntArray a1(10);
    a1.outputData();

    IntArray a2(20);
    a2.outputData();

    IntArray a3 = a1; // copying
    a3.outputData();

    a2 = a1; // assigment
    a2.outputData();

    return 0;
}
