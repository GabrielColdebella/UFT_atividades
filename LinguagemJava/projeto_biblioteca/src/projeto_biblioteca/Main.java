package projeto_biblioteca;
import java.util.Scanner;
import java.time.LocalDate;
//import java.io.InputStream;
//import java.util.ArrayList;
//import java.util.stream.Stream;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Biblioteca bltc = new Biblioteca();
		int opcao = 0, opcao1 = 0, opcao2, opcao3, usuario;
		
		Autor[] exAutor = new Autor[3];
		Livro[] exLivro = new Livro[3];
		
		exAutor[0] = new Autor("autor1", LocalDate.of(2005, 03, 19));
		exAutor[1] = new Autor("autor2", LocalDate.of(2006, 10, 10));
		exAutor[2] = new Autor("autor3", LocalDate.of(1300, 02, 04));
		
		for (int i = 0; i < exAutor.length; i++) {
			bltc.adicionarAutor(exAutor[i]);
			for (int j = 0; j < exAutor.length; j++) {				
				exLivro[i] = new Livro(exAutor[i], ("livro " + i + j));
				bltc.adicionarLivro(exLivro[i]);
			}
		}
		
		bltc.adicionarEmprestimo(exLivro[1], "usuario1");
		
		while(opcao1 != 2) {
			
			do {
				System.out.println("\nQuem é você?");
				System.out.println("0. Funcionário\n1. Usuário\n2. Sair\nOpção:");
				usuario = sc.nextInt();
			} while (usuario < 0 || usuario >= 2);
			
			// parte do funcionario (administra os livros)
			if(usuario == 0) {
				do {
					System.out.println("\nO que deseja fazer?");
					System.out.println("0. 	Sair"
							+ "\n1.	Registrar autor(es)"
							+ "\n2. 	Remover autor"
							+ "\n3. 	Registrar livro(s)"
							+ "\n4. 	Remover livro"
							+ "\n5. 	Registrar emprestimo(s)"
							+ "\n6. 	Remover emprestimo"
							+ "\n7. 	Mostrar todos os livros"
							+ "\n8. 	Mostrar todos os livros disponíveis"
							+ "\n9. 	Mostrar todos os autores"
							+ "\n10. 	Mostrar todos os emprestimos"
							+ "\n11. 	Encontrar livro por id"
							+ "\nOpção:");
					opcao = sc.nextInt();
					
					switch (opcao) {
						
						//Registrar autor(es)
						case 1:
							System.out.println("\nQuantos autores deseja registrar?");
							opcao2 = sc.nextInt();
							
							if(opcao2 > 0) {							
								Autor[] aut = new Autor[opcao2];
								
								for (int i = 0; i < opcao2; i++) {
									System.out.println("\nDigite respectivamente o nome, ano de nascimento, mês e dia.");
									aut[i] = new Autor(sc.next(), LocalDate.of(sc.nextInt(), sc.nextInt(), sc.nextInt()));
									bltc.adicionarAutor(aut[i]);
								}
							}
							break;
						
						//Remover autor
						case 2:
							System.out.println("\nQual autor deseja remover?");
							opcao2 = sc.nextInt();
							
							bltc.removerAutor(opcao2);
							break;
							
						//Registrar livro(s)
						case 3:
							System.out.println("\nQuantos livros deseja registrar?");
							opcao2 = sc.nextInt();
							
							if(opcao2 > 0) {							
								Livro[] lv = new Livro[opcao2];
								
								for (int i = 0; i < opcao2; i++) {
									System.out.println("\nDigite respectivamente o id do autor e o titulo");
									System.out.println("digite 0 para mostrar todos os autores");
									opcao3 = sc.nextInt();
									
									if(opcao3 == 0) { 
										bltc.listarAutoresFormatado();
										System.out.println("\nid do autor:");
										opcao3 = sc.nextInt();
									}
									
									sc.nextLine();
									String titulo = sc.nextLine();
									lv[i] = new Livro(bltc.encontrarAutorPorId(opcao3), titulo);
									bltc.adicionarLivro(lv[i]);
								}
							}
							break;
							
						//Remover livro
						case 4:
							System.out.println("\nQual livro deseja remover?");
							opcao2 = sc.nextInt();
							
							bltc.removerLivro(opcao2);
							break;
							
						// Registrar emprestimo(s)
						case 5:
							System.out.println("\nQuantos emprestimos deseja registrar?");
							opcao2 = sc.nextInt();
							
							if(opcao2 > 0) {							
								for (int i = 0; i < opcao2; i++) {
									System.out.println("\nDigite respectivamente o id do livro e o nome de usuário");
									System.out.println("digite 0 para mostrar todos os livros");
									opcao3 = sc.nextInt();
									
									if(opcao3 == 0) { 
										bltc.listarLivroDisponivel();
										System.out.println("\nid do livro:");
										opcao3 = sc.nextInt();
									}
									
									sc.nextLine();
									String nomeUsuario = sc.nextLine();
									bltc.adicionarEmprestimo(bltc.encontrarLivroPorId(opcao3), nomeUsuario);
								}
							}
							break;
							
						// Remover emprestimo
						case 6:
							System.out.println("\nQual emprestimo deseja remover?");
							opcao2 = sc.nextInt();
							
							bltc.removerEmprestimo(opcao2);
							break;
							
						//Mostrar todos os livros
						case 7:
							bltc.listarLivrosFormatado();
							break;
							
						//Mostrar todos os livros disponíveis
						case 8:
							bltc.listarLivroDisponivel();
							break;
							
						//Mostrar todos os autores
						case 9:
							bltc.listarAutoresFormatado();
							break;
							
						//Mostrar todos os emprestimos
						case 10:
							bltc.listarEmprestimosFormatado();
							break;
							
						//Encontrar livro por id
						case 11:
							System.out.println("\nQual livro deseja buscar?");
							opcao2 = sc.nextInt();
							
							bltc.encontrarLivroPorIdFormatado(opcao2);
							break;
							
						default:
							break;
					}
				} while (opcao != 0);
			}
			
			// parte do usuário (só pega ou devolve livros)
			do {
				if(usuario == 1) {			
					do {
						System.out.println("\nOlá! Deseja pegar um livro?");
						System.out.println("0. Não\n1. Sim\n2. Apenas olhar o catalogo\nOpção:");
						opcao = sc.nextInt();
					} while (opcao < 0 || opcao > 2);
				
					if(opcao == 1 || opcao == 2) {
						System.out.println("\nLista de livros:");
						bltc.listarLivrosFormatado();
						
						if(opcao == 1) {
							System.out.println("\nQuantos emprestimos deseja registrar?");
							opcao2 = sc.nextInt();
							
							if(opcao2 > 0) {							
								for (int i = 0; i < opcao2; i++) {
									System.out.println("\nDigite respectivamente o id do livro e o nome de usuário");
									System.out.println("digite 0 para mostrar todos os livros");
									opcao3 = sc.nextInt();
									
									if(opcao3 == 0) { 
										bltc.listarLivroDisponivel();
										System.out.println("\nid do livro:");
										opcao3 = sc.nextInt();
									}
									
									sc.nextLine();
									String nomeUsuario = sc.nextLine();
									bltc.adicionarEmprestimo(bltc.encontrarLivroPorId(opcao3), nomeUsuario);
								}
							}
						}
					}
				}
			} while (opcao != 0);
		}
		sc.close();
		System.out.println("Até mais!");
	}
}
