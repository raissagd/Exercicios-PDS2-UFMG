#ifndef PDS2_PACIENTE_H
#define PDS2_PACIENTE_H

#include <string>
#include "virus.h"

class Paciente {
private:
  std::string _nome;
  double _resistencia;
  bool _infectado;
  Virus *_virus; // PONTEIRO
public:
  Paciente(std::string nome, double resistencia); // SOBRECARGA
  Paciente(std::string nome, double resistencia, Virus *virus);
  bool is_infectado();
  Virus *get_virus();
  std::string get_nome();
  void contato(Paciente &contato);
  Virus *transmitir();
  void curar();
};
#endif
