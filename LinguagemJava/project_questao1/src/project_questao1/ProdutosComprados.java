package project_questao1;

public class ProdutosComprados implements IProduto{

	private String nome;
	private float custo;

	
	public float getCusto() {
		return custo;
	}
	public void setCusto(Float custo) {
		this.custo = custo;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
}
