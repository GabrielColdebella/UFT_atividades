package projeto_biblioteca;
import java.util.ArrayList;
import java.util.List;

public class Biblioteca {
	private List<Livro> livros = new ArrayList<>();
	private List<Autor> autores = new ArrayList<>();
	private List<Emprestimo> emprestimos = new ArrayList<>();

	public void adicionarAutor(Autor autor) {
		autores.add(autor);
	}
	
	public void removerAutor(int id) {
		autores.removeIf(autor -> autor.getId() == id);
	}
	
	public List<Autor> listarAutores() {
		return autores;
	}
	
	public void listarAutoresFormatado() {
		for(Autor autor : autores) {
			System.out.println("ID:"+autor.getId()+" - "+autor.getNome()+" - "+autor.getDataNascimento());
		}
	}
	
	public Autor encontrarAutorPorId(int id) {
	    for (Autor autor : autores) {
	        if (autor.getId() == id) {
	            return autor;
	        }
	    }
	    return null;
	}
	
	public void adicionarLivro(Livro... livroTemp) {
		for(Livro livro : livroTemp) {			
			livros.add(livro);
		}
	}
	
	public void removerLivro(int id) {
		livros.removeIf(livro -> livro.getId() == id);
	}
	
    public List<Livro> listarLivros() {
        return livros;
    }
    
    public void listarLivrosFormatado() {
		for(Livro livro : livros) {
			System.out.println("ID:"+livro.getId()+" - "+livro.getTitulo()+" - Disponivel:"+livro.getDisponivel()+" - "+livro.getAutor());
		}
    }

	public void listarLivroDisponivel() {
		for(Livro livro : livros) {
			if(livro.getDisponivel()) {
				System.out.println("ID:"+livro.getId()+" - "+livro.getTitulo()+" - "+livro.getAutor());
			};
		}
	}
	
	public Livro encontrarLivroPorId(int id) {
	    for (Livro livro : livros) {
	        if (livro.getId() == id) {
	            return livro;
	        }
	    }
	    return null;
	}
	
	public void encontrarLivroPorIdFormatado(int id) {
		for(Livro livro : livros) {
			if(livro.getId() == id) {
				System.out.println(livro.getId());
				System.out.println(livro.getTitulo());
				System.out.println(livro.getAutor());
				System.out.println(livro.getDisponivel());
			};
		}
	}
	
	public void adicionarEmprestimo(Livro livro, String nomeUsuario) {
		if(livro.getDisponivel()) {
			Emprestimo emp = new Emprestimo(livro, nomeUsuario);
			emprestimos.add(emp);
		} else {
			System.out.println("O livro em questão já foi emprestado");
		}
	}
	
	public void removerEmprestimo(int id) {
        for (Emprestimo emprestimo : emprestimos) {
            if (emprestimo.getId() == id) {
                emprestimo.devolver();
                break;
            }
        }
		emprestimos.removeIf(emprestimo -> emprestimo.getId() == id);
	}
	
	public List<Emprestimo> listarEmprestimos() {
		return emprestimos;
	}
	
	public void listarEmprestimosFormatado() {
		for(Emprestimo emprestimo : emprestimos) {
			System.out.println("ID:"+emprestimo.getId()+" - "+emprestimo.getNomeUsuario()+" - "+emprestimo.getTitulo());
		}
	}
}
