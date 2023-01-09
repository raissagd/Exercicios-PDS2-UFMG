#ifndef PDS2_VIRUS_H
#define PDS2_VIRUS_H

#include <string>

class Virus {
private:
  std::string _nome;
  double _forca;

  Virus **_filhos;
  int _numero_filhos;
  int _capacidade_reproducao;
public:
  Virus(std::string nome, double forca, int capacidade_reproducao);
  ~Virus();
  
  Virus *reproduzir();

  std::string get_nome();
  double get_forca();
  
};
#endif
