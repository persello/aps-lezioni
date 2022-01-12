#pragma once
#include <string>
#include <vector>

class Persona {
public:
  Persona(std::string n) : nome(n) {}
  std::string Nome() const { return nome; }

private:
  std::string nome;
};