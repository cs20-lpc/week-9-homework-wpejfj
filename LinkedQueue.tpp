template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
  head = nullptr;
  last = nullptr;
  this->length = 0;

}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
  if (isEmpty())
    throw std::string("error: empty queue");
  return last->value;

}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
  while (head != nullptr) {
    Node *tmp = head;
    head = head->next;
    delete tmp;
  }
  last = nullptr;
  this->length = 0;

}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
  Node *curr = copyObj.head;
  while (curr != nullptr) {
    enqueue(curr->value);
    curr = curr->next;
  }
  
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
  if (isEmpty())
    throw std::string("error: empty queue");
  Node *tmp = head;
  head = head->next;
  if (head == nullptr)
    last = nullptr;
  delete tmp;
  this->length--;

}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
  Node *newNode = new Node(elem);
  if (isEmpty()) {
    head = newNode;
    last = newNode;
  }
  else {
    last->next = newNode;
    last = newNode;
  }
  this->length++;
  
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
  if (isEmpty())
    throw std::string("error: empty queue");
  return head->value;

}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
