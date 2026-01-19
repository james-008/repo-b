/*
 * Sin-Yaw Wang <swang24@scu.edu>


namespace csen79
{

  // assignment
  Bag &Bag::operator=(const Bag &rhs)
  {
    std::cout << "assign" << std::endl;
    memcpy(this->data, rhs.data, DATASIZE);
    return *this;
  }

  // move constructor
  Bag::Bag(Bag &&rhs)
  {
    std::cout << "move constructor; calling assignment" << std::endl;
    this->operator=(rhs);
  }

  // copy constructor
  Bag::Bag(const Bag &rhs)
  {
    std::cout << "copy; calling assignment" << std::endl;
    this->operator=(rhs);
  }

  // move
  Bag &Bag::operator=(Bag &&rhs)
  {
    std::cout << "move; calling assign" << std::endl;
    return this->operator=(rhs);
  }

  // simple asssess functions
  // replace them with appropriate ones for assignments
  const Bag::Data &Bag::getData(const int i) const
  {
    if (i < 0 || i >= DATASIZE)
      throw std::out_of_range(std::string("index out of range"));
    return data[i];
  };
  void Bag::setData(const int i, const Data &d)
  {
    if (i < 0 || i >= DATASIZE)
      throw std::out_of_range(std::string("index out of range"));
    data[i] = (Data)d;
  }
  void Bag::push(const Data &value)
  {
    if (size == DATASIZE)
      throw std::overflow_error("Queue overflow");
    data[tail] = value;
    tail = (tail + 1) % DATASIZE;
    size++;
  };
  Bag::Data Bag::pop()
  {
    if (size == 0)
      throw std::underflow_error("Queue underflow");
    Data value = data[head];
    head = (head + 1) % DATASIZE;
    size--;
    return value;
  };
  void Bag::print() const
  {
    if (size == 0)
    {
      std::cout << "[Empty]" << std::endl;
      return;
    }
    std::cout << "Queue: ";
    for (size_t i = 0; i < size; i++)
      std::cout << data[(head + i) % DATASIZE] << " ";
    std::cout << std::endl;
  };
}
