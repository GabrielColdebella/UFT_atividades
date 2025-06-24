package project_questao1;

public class Main {
	public static void main(String[] args) {
		ProdutosComprados pc = new ProdutosComprados();
		pc.setNome("teste11111");
		
		ProdutosComprados pc2 = new ProdutosComprados();
		pc2.setNome("222222222teste");
		
		System.out.println(pc.getNome());
		System.out.println(pc2.getNome());
	}

}
