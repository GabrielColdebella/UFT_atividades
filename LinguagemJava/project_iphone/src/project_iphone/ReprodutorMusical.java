package project_iphone;

public class ReprodutorMusical {
    private String musicaAtual;

    public void tocar() {
        System.out.println("Tocando: " + musicaAtual);
    }

    public void pausar() {
        System.out.println("Música pausada.");
    }
    
    public void voltar() {
        System.out.println("Tocando música anterior.");
    }
    
    public void avancar() {
        System.out.println("Tocando música seguinte.");
    }

    public void selecionarMusica(String musica) {
        this.musicaAtual = musica;
        System.out.println("Música selecionada: " + musicaAtual);
    }
}