package project_iphone;

public class AparelhoTelefonico {
	private String modelo;
	private String numero;
	
	public void ligar(String n) {
        this.numero = n;
        System.out.println("Ligando para:" + this.numero);
	};
	
	public void atenderChamada() {
		System.out.println("Chamada atendida.");
	};
	
	public void recusarChamada() {
		System.out.println("Chamada recusada.");
	};
	
	public void iniciarCorreioVoz() {
		System.out.println("Iniciando correio de voz...");
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getNumero() {
		return numero;
	}

	public void setNumero(String numero) {
		this.numero = numero;
	};
}

