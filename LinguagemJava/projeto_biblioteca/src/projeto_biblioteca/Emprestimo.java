package projeto_biblioteca;
import java.time.LocalDate;

public class Emprestimo{
	private int id;
	private static int contadorId = 1;
	private Livro livro;
	private String nomeUsuario;
	private LocalDate dataEmprestimo;
	private LocalDate dataDevolucao;
	
	public Emprestimo(Livro livroEmp, String nomeUsuario) {
		super();
		this.id = contadorId++;
		this.livro = livroEmp;
		this.nomeUsuario = nomeUsuario;
		this.dataEmprestimo = LocalDate.now();
		this.livro.setDisponivel(false);
	}
	
	public void devolver() {
        this.dataDevolucao = LocalDate.now();
        this.livro.setDisponivel(true);
	}

	@Override
	public String toString() {
		return "Emprestimo [id=" + id + ", livro=" + livro + ", nomeUsuario=" + nomeUsuario + ", dataEmprestimo="
				+ dataEmprestimo + ", dataDevolucao=" + dataDevolucao + "]";
	}
	

	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public static int getContadorId() {
		return contadorId;
	}
	public static void setContadorId(int contadorId) {
		Emprestimo.contadorId = contadorId;
	}
	public String getTitulo() {
		return livro.getTitulo();
	}
	public Livro getLivro() {
		return livro;
	}
	public void setLivro(Livro livro) {
		this.livro = livro;
	}
	public String getNomeUsuario() {
		return nomeUsuario;
	}
	public void setNomeUsuario(String nomeUsuario) {
		this.nomeUsuario = nomeUsuario;
	}
	public LocalDate getDataEmprestimo() {
		return dataEmprestimo;
	}
	public void setDataEmprestimo(LocalDate dataEmprestimo) {
		this.dataEmprestimo = dataEmprestimo;
	}
	public LocalDate getDataDevolucao() {
		return dataDevolucao;
	}
	public void setDataDevolucao(LocalDate dataDevolucao) {
		this.dataDevolucao = dataDevolucao;
	}
	

	
}
