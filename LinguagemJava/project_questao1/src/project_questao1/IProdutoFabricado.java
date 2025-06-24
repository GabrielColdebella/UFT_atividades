package project_questao1;

public interface IProdutoFabricado extends IProduto{
	int getNumeroIngredientes();
	IProduto getIngrediente(int numero);
	
}
