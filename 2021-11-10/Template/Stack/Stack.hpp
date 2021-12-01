#pragma once

#include <iostream>
using namespace std;

template<typename T> class Stack {
  template<typename U> friend ostream& operator<<(ostream&, const Stack<U>&);
  template<typename U> friend istream& operator>>(istream&, Stack<U>&);

public:
  Stack();
  Stack(const Stack<T>&);
  ~Stack();
  Stack<T>& operator=(const Stack<T>&);
  Stack<T>& Push(const T&);
  Stack<T>& Pop();
  T         Top() const;
  bool      IsEmpty() const { return top == -1; }

private:
  T*  vec;
  int size;
  int top;
};

template<typename T> Stack<T>::Stack() {
  size = 100;
  vec  = new T[size];
  top  = -1;
}

template<typename T> Stack<T>::Stack(const Stack<T>& s) {
  top  = s.top;
  size = s.size;
  vec  = new T[size];
  for (int i = 0; i <= top; i++) {
    vec[i] = s.vec[i];
  }
}

template<typename T> Stack<T>::~Stack() { delete[] vec; }

template<typename T> Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
  if (s.top >= size) {
    delete[] vec;
    size = s.size;
    vec  = new int[size];
  }

  top = s.top;

  for (int i = 0; i <= top; i++) {
    vec[i] = s.vec[i];
  }
  return *this;
}

template<typename T> Stack<T>& Stack<T>::Push(const T& val) {
  if (top == size - 1) {
    T* aux_vec = new T[size * 2];
    for (int i = 0; i < size; i++) {
      aux_vec[i] = vec[i];
    }
    delete[] vec;
    vec = aux_vec;
    size *= 2;
  }

  top++;
  vec[top] = val;

  return *this;
}

template<typename T> Stack<T>& Stack<T>::Pop() {
  if (top == -1) {
    throw logic_error("Stack is empty");
  }

  top--;
  return *this;
}

template<typename T> T Stack<T>::Top() const {
  if (top == -1) {
    throw logic_error("Stack is empty");
  }

  return vec[top];
}

template<typename U> ostream& operator<<(ostream& os, const Stack<U>& s) {
  for (int i = 0; i <= s.top; i++) {
    os << s.vec[i] << " ";
  }
  return os;
}

template<typename U> istream& operator>>(istream& is, Stack<U>& s) {
  int val;
  while (is >> val) {
    s.Push(val);
  }
  return is;
}
