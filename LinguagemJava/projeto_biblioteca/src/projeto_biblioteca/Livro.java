package projeto_biblioteca;
import java.time.LocalDate;

public class Livro {
	private int id;
	private static int contadorId = 1;
	private Autor autor;
	private String titulo;
	private Boolean disponivel;
	private LocalDate dataCadastro;
	private LocalDate dataAtualizacao;
	
	public Livro(Autor autor, String titulo) {
		this.id = contadorId++;
		this.autor = autor;
		this.titulo = titulo;
		this.disponivel = true;
		this.dataCadastro = LocalDate.now();
		this.dataAtualizacao = LocalDate.now();
	}	
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
		this.dataAtualizacao = LocalDate.now();
	}
	public Boolean getDisponivel() {
		return disponivel;
	}
	public void setDisponivel(Boolean disponivel) {
		this.disponivel = disponivel;
		this.dataAtualizacao = LocalDate.now();
	}
	public LocalDate getDataCadastro() {
		return dataCadastro;
	}
	public void setDataCadastro(LocalDate dataCadastro) {
		this.dataCadastro = dataCadastro;
		this.dataAtualizacao = LocalDate.now();
	}
	public LocalDate getDataAtualizacao() {
		return dataAtualizacao;
	}
	public void setDataAtualizacao(LocalDate dataAtualizacao) {
		this.dataAtualizacao = dataAtualizacao;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
		this.dataAtualizacao = LocalDate.now();
	}
	public Autor getAutor() {
		return autor;
	}
	public void setAutor(Autor autor) {
		this.autor = autor;
		this.dataAtualizacao = LocalDate.now();
	}

	@Override
	public String toString() {
		return "Livro [id=" + id + ", autor=" + autor + ", titulo=" + titulo + ", disponivel=" + disponivel
				+ ", dataCadastro=" + dataCadastro + ", dataAtualizacao=" + dataAtualizacao + "]";
	}

	
}
