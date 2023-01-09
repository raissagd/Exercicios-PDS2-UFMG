#include "virus.h"

Virus::Virus(std::string nome, double forca, int capacidade_reproducao) {
  _nome = nome;
  _forca = forca;
  _capacidade_reproducao = capacidade_reproducao;
  _numero_filhos = 0;
  // vetor de tamanho capacidade_reproducao para os filhos (no heap)
  _filhos = new Virus*[capacidade_reproducao]();
}

Virus::~Virus() {
  if (_filhos != nullptr) {
    for (int i = 0; i < _numero_filhos; i++)
        if (_filhos[i] != nullptr)
         delete _filhos[i];
    delete[] _filhos;
  }
}

Virus *Virus::reproduzir() {
  if (this->_numero_filhos == this->_capacidade_reproducao) {
    return nullptr;
  }
  // Aloca uma um novo filho.
  std::string nome = _nome + "_C" + std::to_string(_numero_filhos+1);
  Virus *novo_virus = new Virus(nome, _forca, _capacidade_reproducao);
  _filhos[_numero_filhos] = novo_virus;  // Guarda copia em um vetor
  _numero_filhos += 1;                   // Aumenta o número de filhos
  return _filhos[_numero_filhos - 1];    // Retorna ponteiro para copia
}


std::string Virus::get_nome() {
  return _nome;
}

double Virus::get_forca() {
  return _forca;
}
