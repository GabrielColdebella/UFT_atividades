package teste;

public class Visualizacao {
	private Aluno espectador;
	private Video filme;
	
	public Visualizacao(Aluno espectador, Video filme) {
		super();
		this.espectador = espectador;
		this.filme = filme;
	}

	public Aluno getEspectador() {
		return espectador;
	}

	public void setEspectador(Aluno espectador) {
		this.espectador = espectador;
	}

	public Video getFilme() {
		return filme;
	}

	public void setFilme(Video filme) {
		this.filme = filme;
	}

	@Override
	public String toString() {
		return "Visualizacao [espectador=" + espectador + ", filme=" + filme + "]";
	}
	
	
}
