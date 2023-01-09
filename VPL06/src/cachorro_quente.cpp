// TODO implemente essa classe de acordo com o hpp correspondente
#include "cachorro_quente.hpp"

/**
 * @brief Construtor padrao que inicializa todas as variaveis da classe.
 * Note que o valor unitario (membro da classe mãe) deve ser calculado
 * através do método calcPreco.
 *
 * @param num_salsichas número de salsichas
 * @param complementos coleção de complementos
 * @param prensado se o cachorro quente deve ser prensado
 * @param qtd Quantidade do item.
 */
CachorroQuente::CachorroQuente(int num_salsichas, std::vector<std::string> &complementos, bool prensado, int qtd)
{
    _num_salsichas = num_salsichas;
    _complementos = complementos;
    _prensado = prensado;
    _quantidade = qtd;
}

int CachorroQuente::getNumSalsichas()
{
    return _num_salsichas;
}

std::vector<std::string> CachorroQuente::getComplementos()
{
    return _complementos;
}
int CachorroQuente::numAdicionais()
{
    return _complementos.size();
}

bool CachorroQuente::getPrensado()
{
    return _prensado;
}

/**
 * @brief Calcula o valor do cachorro quente de acordo com as regras:
 * 5 reais preço base + 1.50 real por salsicha
 * + 1 real por complemento + 0.50 centavos se for prensar
 *
 * @return float preço do cachorro quente em reais
 */
float CachorroQuente::calcPreco()
{
    return 5.0 + (1.50 * (getNumSalsichas()) + (1.0 * (numAdicionais())) + (0.5 * getPrensado()));
}
/**
 * @brief Retorna a descricao detalhada da comida japonesa.
 * Ex: 4X cachorro-quente com 2 salsichas, milho, queijo ralado.
 *
 * @return std::string Descricao da comida japonesa.
 */
std::string descricao();