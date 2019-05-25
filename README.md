# TP-PDS-II
Trabalho Final do curso de programação e desenvolvimento de software II - DCC UFMG

O objetivo do programa Máquina de Busca é proporcionar um ambiente de busca de palavras entre um conjunto de arquivos de texto previamente selecionados.
A Máquina de Busca permite que o usuário digite uma palavra qualquer e obtenha uma lista com os nomes dos arquivos que contêm esta palavra.
Para o desenvolvimento do programa, foram criadas duas classes: Conjunto_Indice e Conjunto. Ambas foram implementadas como listas duplamente
encadeadas circulares com sentinela e ordenadas.
Conjunto_Indice é a classe utilizada na função principal. Nela, são inseridas as palavras, e cada palavra possui um subconjunto com os arquivos que as contêm.
A classe Conjunto é utilizada para salvar os arquivos correspondentes a cadapalavra.

