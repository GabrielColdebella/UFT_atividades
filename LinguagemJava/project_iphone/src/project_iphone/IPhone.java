package project_iphone;

public class IPhone{
	private String tamanho;
	private String cor;
	private String versao;
	
    private ReprodutorMusical reprodutor;
    private AparelhoTelefonico telefone;
    private NavegadorInternet navegador;
	
    public IPhone(String tamanho, String cor, String versao) {
        this.tamanho = tamanho;
        this.cor = cor;
        this.versao = versao;
        
        this.setReprodutor(new ReprodutorMusical());
        this.setTelefone(new AparelhoTelefonico());
        this.setNavegador(new NavegadorInternet());
    }
	
	public void ligar() {
		 System.out.println("iPhone ligado.");
	};
	
	public void desligar() {
		System.out.println("iPhone desligado.");
	}
	
	public String getTamanho() {
		return tamanho;
	}
	public void setTamanho(String tamanho) {
		this.tamanho = tamanho;
	}
	
	public String getCor() {
		return cor;
	}
	public void setCor(String cor) {
		this.cor = cor;
	}
	
	public String getVersao() {
		return versao;
	}
	public void setVersao(String versao) {
		this.versao = versao;
	}

	public ReprodutorMusical getReprodutor() {
		return reprodutor;
	}

	public void setReprodutor(ReprodutorMusical reprodutor) {
		this.reprodutor = reprodutor;
	}

	public AparelhoTelefonico getTelefone() {
		return telefone;
	}

	public void setTelefone(AparelhoTelefonico telefone) {
		this.telefone = telefone;
	}

	public NavegadorInternet getNavegador() {
		return navegador;
	}

	public void setNavegador(NavegadorInternet navegador) {
		this.navegador = navegador;
	};
}
