#include <iostream>
#include "virus.h"
#include "paciente.h"

int main() {
  Virus *virus_zero = new Virus("VZERO", 0.8, 4);
  Paciente p1("Maria", 0.2, virus_zero);
  Paciente p2("Joao", 0.3);
  p2.contato(p1);
  Paciente p3("Carla", 0.3);
  p3.contato(p2);

  std::cout << p1.get_virus()->get_nome() << " " \
            << p1.get_virus() << "\n";
  std::cout << p2.get_virus()->get_nome() << " " \
            << p2.get_virus() << "\n";
  std::cout << p3.get_virus()->get_nome() << " " 
            << p3.get_virus() << "\n";
  
  delete virus_zero;
  return 0;
}
