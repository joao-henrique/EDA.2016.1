#define D 5 //árvore de ordem 5
 
typedef struct BTPage{
	//armazena numero de chaves na pagina
	short int totalChaves;
 
	//vetor de chaves
	int chaves[D-1];
 
	//Ponteiros das paginas filhas, -1 aponta para NULL
	struct BTPage filha[D];	
}Page;

Busca(k, ponteiroRaiz) {
	se(ponteiroRaiz == -1) {
		return (chave nao encontrada)
	}
	senao
	{
		carrega em memoria primaria pagina apontado por ponteiroRaiz
		procura k na pagina carregada
		se(k foi encontrada)
		{
			return (chave encontrada)
		}
		senao
		{
			ponteiro = ponteiro para a próxima página da possível ocorrência de k
			return (Busca (k, ponteiro))
		}
	}
}

Inserçao(ponteiroRaiz, key, chavePromovida) {
	se(ponteiroRaiz == -1)//se ponteiroRaiz nao aponta para nenhuma pagina
	{
		chavePromovida = key
		return(flag que indica que houve promoção de chave)
	}
	senao
	{
		carregue a página P apontada por ponteiroRaiz em memoria primária
		busque por key nessa página P
		posicao = página no qual key poderia estar 
	}
 
	se(key foi encontrada)
	{
		//chave ja esta na arvore, retorne uma flag de erro
		return(flag de erro)
	}
 
	flagRetorno = Inserçao(posicao, key, chavePromovida)//procedimento recursivo
 
	se(flagRetorno indica que nao houve promoçao de chave ou que ocorreu um erro)
	{
		return(conteudo de flagRetorno)
	}
	senao se(há espaço na página P para chavePromovida)
	{
		insere chavePromovida na página P
		escreve página P em arquivo
		return(flag que indica que nao houve promocao de chave)
	}
	senao //nao ha espaço em P para key
	{
		realize operação de split em P
		escreva em arquivo  a nova página e a página P
		return(flag que indica que houve promoçao de chave)
	}	
}

REMOÇÃO
Busque a chave k
Busque a menor chave M na página folha da sub-árvore à direita de k
Se a chave k não está numa folha
{	
 Substitua k por M
}
Apague a chave k ou M da página folha
Se a página folha não sofrer underflow
{
	 fim do algoritmo
}
Se a página folha sofrer underflow, verifique as páginas irmãs da página folha
{
   Se uma das páginas tiver um número maior do que o mínimo redistribua as chaves
   Senão concatene as páginas com uma de suas irmãs e a chave pai separadora
}
Se ocorrer concatenação de páginas aplique o trecho das linhas 8 até 17 para a página pai da folha

void emOrdem (tpaginaB raiz) {
	if(raiz==NULL)
		return;
	for(int i=0;i<raiz.n,i++)
		emOrdem(raiz->pont[i]);
		printf("%i",raiz->chv[i]);
	}
	emOrdem(raiz->pont[raiz.n]);
}
