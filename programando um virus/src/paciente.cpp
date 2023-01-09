#include "paciente.h"

Paciente::Paciente(std::string nome, double resistencia) {
  _nome = nome;
  _resistencia = resistencia;
  _infectado = false;
  _virus = nullptr;
}

Paciente::Paciente(std::string  nome, double resistencia, Virus *virus) {
  _nome = nome;
  _resistencia = resistencia;
  _infectado = true;
  _virus = virus;
}

bool Paciente::is_infectado(){
    return _infectado;
}
Virus *Paciente::get_virus(){
    return _virus;
}
std::string Paciente::get_nome(){
    return _nome;
}

void Paciente::contato(Paciente &p2) {
  if (p2.is_infectado() && !this->is_infectado()) {
    if (p2.get_virus()->get_forca() > _resistencia) {
        _infectado = true;
        _virus = p2.transmitir();
    }
  }
}

Virus *Paciente::transmitir(){
    return _virus->reproduzir();
}
