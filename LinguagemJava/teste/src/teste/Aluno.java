package teste;

public class Aluno extends Pessoa{
	private String login;
	private int totAssistido;
	
	public Aluno(String nome, int idade, String sexo) {
		super(nome, idade, sexo);
	}

	public String getLogin() {
		return login;
	}

	public void setLogin(String login) {
		this.login = login;
	}

	public int getTotAssistido() {
		return totAssistido;
	}

	public void setTotAssistido(int totAssistido) {
		this.totAssistido = totAssistido;		
	}

	
}
