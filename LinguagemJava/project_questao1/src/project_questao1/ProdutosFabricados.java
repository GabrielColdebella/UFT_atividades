package project_questao1;

public abstract class ProdutosFabricados implements IProdutoFabricado{
	private String[][] ingredienteNome;
	private float[][] ingredienteCusto;
	
	private String[] nome;
	private float[] custo;

	
	
	public int getNumeroIngredientes() {
		return this.ingredienteCusto.length;
	}

	public String getNome(int indiceProduto) {
		return this.nome[indiceProduto];
	}
	public void setNome(String nome, int indiceProduto) {
		this.nome[indiceProduto] = nome;
	}
	
	public float getCusto(int indiceProduto) {
		float soma = (float) 0;
		for (int i = 0; i < this.ingredienteCusto.length; i++) {
			soma = soma + this.ingredienteCusto[indiceProduto][i];
		}
		return soma;
	}
	
	// get e set do ingrediente
	public void setIngredienteCusto(int indiceProduto, int indiceIngrediente, float novoCusto) {
		this.ingredienteCusto[indiceProduto][indiceIngrediente] = novoCusto;
	}
	
	public float getIngredienteCusto(int indiceProduto, int indiceIngrediente) {
		return this.ingredienteCusto[indiceProduto][indiceIngrediente];
	}
	
	public void setIngredienteNome(int indiceProduto, int indiceIngrediente, String novoNome) {
		this.ingredienteNome[indiceProduto][indiceIngrediente] = novoNome;
	}
	
	public String getIngredienteNome(int indiceProduto, int indiceIngrediente) {
		return this.ingredienteNome[indiceProduto][indiceIngrediente];
	}
}
