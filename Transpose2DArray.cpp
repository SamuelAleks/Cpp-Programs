#include <iostream>

template <class T>
class Array2D
{
private:
    unsigned int LENGTH; // Number of elements in array
    unsigned int nrows;
    unsigned int ncols;
    T *array;

public:
    Array2D(const int row, const int col)
    {
        std::cout << "Constructor called with rows: " << row << ", cols: " << col << std::endl;
        this->LENGTH = row * col;
        this->nrows = row;
        this->ncols = col;
        this->array = new T[this->LENGTH];
    }

    Array2D(const Array2D<T> &x)
    {
        std::cout << "Copy constructor called" << std::endl;
        if (this != &x)
        {
            this->LENGTH = x.LENGTH;
            this->nrows = x.nrows;
            this->ncols = x.ncols;
            this->array = new T[this->LENGTH];
            for (int i = 0; i < this->LENGTH; ++i)
            {
                this->array[i] = x.array[i];
            }
        }
    }

    ~Array2D()
    {
        std::cout << "Destructor called" << std::endl;
        delete[] array;
    }

    unsigned int len() { return LENGTH; }
    unsigned int rows() { return nrows; }
    unsigned int cols() { return ncols; }

    // 2D Indexing Function into 1D Data Storage Structure
    inline T &operator()(const int y, const int x) const
    {
        return array[y * ncols + x];
    }
};

void transpose_swap(Array2D<int> &data, int i, int j)
{
    std::cout << "Swapping elements at (" << i << ", " << j << ") and (" << j << ", " << i << ")" << std::endl;
    int tmp = data(i, j);
    data(i, j) = data(j, i);
    data(j, i) = tmp;
}

void transpose(Array2D<int> &data)
{
    std::cout << "Transposing matrix" << std::endl;
    for (int i = 0; i < data.rows(); ++i)
    {
        for (int j = i + 1; j < data.cols(); ++j)
        {
            transpose_swap(data, i, j);
        }
    }
}

void use_transpose(Array2D<int> A)
{
    std::cout << "Using transposed matrix" << std::endl;
    // Do something with the transposed matrix A
    // For demonstration, let's just print the first few elements
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::cout << A(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows, cols;
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> cols;

    Array2D<int> A(rows, cols);

    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < A.rows(); ++i)
    {
        for (int j = 0; j < A.cols(); ++j)
        {
            std::cin >> A(i, j); // read in A(i,j) from the input
        }
    }

    transpose(A);
    use_transpose(A);

    return 0;
}
