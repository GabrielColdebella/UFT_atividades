package project_iphone;

public class NavegadorInternet {
    private String[] abas;
    private String paginaAtual;

    public void exibirPagina(String url) {
        this.paginaAtual = url;
        System.out.println("Exibindo pagina:" + paginaAtual);
    }

    public void adicionarNovaAba(String url) {
        System.out.println("Nova aba adicionada: " + url);
    }

    public void atualizarPagina() {
        if (paginaAtual != null) {
            System.out.println("Atualizando página: " + paginaAtual);
        } else {
            System.out.println("Nenhuma página para atualizar.");
        }
    }

	public String[] getAbas() {
		return abas;
	}

	public void setAbas(String[] abas) {
		this.abas = abas;
	}
}