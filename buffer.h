#ifndef BUFFER_H
#define BUFFER_H

template <class T>
class buffer {
  public:
    buffer(unsigned long long int size);
    ~buffer();
    T *get_line();
  private:
    T *line_ptr;
};

template <class T>
buffer<T>::buffer(unsigned long long int size):
  line_ptr(new T[size])
{
  // Allocate new pointer
}

template <class T>
buffer<T>::~buffer()
{
  // Delete the Pointer
  delete line_ptr;
}

template <class T>
T *buffer<T>::get_line()
{
  return line_ptr;
}

#endif /* BUFFER_H */
