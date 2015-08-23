#include <gtk/gtk.h>
#include <gtk-3.0/gtk/gtktypes.h>

/*Objetos Globais*/
GtkEntry *xInputText;
GtkEntry *yInputText;
GtkWidget *pointsList;

/*Atributos Globais*/
float zoom = 1;
float move = 10;
int direction = 0;

/*Imprime uma string para teste*/
static void impressao_teste(GtkWidget* widget, gpointer data)
{
    g_print("TESTE.\n");
}

/*Fecha o programa*/
static void fechar_janela(GtkWidget* widget, gpointer data)
{
    gtk_widget_destroy((GtkWidget*) data);
}

/*Nao sei o que eh*/
static void add_to_list(GtkWidget* widget, gpointer data) {
    printf("BOSTA");
    printf("X: %s", gtk_entry_get_text(xInputText));
    printf("Y: %s", gtk_entry_get_text(yInputText));
}

/*Nao sei o que eh*/
static void remove_from_list(GtkWidget* widget, gpointer data) {
    gtk_widget_destroy((GtkWidget*) data);
}

/*Nao sei o que eh*/
static void open_poligon_window(GtkWidget* widget, gpointer data) {

    GtkBuilder *builder;
    GError *error = NULL;
    GtkWidget *window;
    builder = gtk_builder_new();
    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if (!gtk_builder_add_from_file(builder, "interface_principal.glade", &error)) {
        g_warning("%s", error->message);
        g_free(error);
    }
    /* Get main window pointer from UI */
    window = GTK_WIDGET(gtk_builder_get_object(builder, "janela_principal"));
    xInputText = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    yInputText = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));


    GtkWidget *btnCancel = GTK_WIDGET(gtk_builder_get_object(builder, "btnCancel"));
    g_signal_connect(btnCancel, "clicked", G_CALLBACK(fechar_janela), window);


    /* Connect signals */
    gtk_builder_connect_signals(builder, NULL);

    /* Destroy builder, since we don't need it anymore */
    g_object_unref(G_OBJECT(builder));

    /* Show window. All other widgets are automatically shown by GtkBuilder */

    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_widget_show_all(window);

    /* Start main loop */
    gtk_main();

}

/*void draw_line(cairo_t *cr, Ponto* ponto1, Ponto* ponto2) {
    cairo_move_to(cr, ponto1->x, ponto1->y);
    cairo_line_to(cr, ponto2->x, ponto2->y);
    cairo_stroke(cr);
}*/

/*void draw_poligono(cairo_t *cr, Poligono* pol) {

    Elemento<Ponto>* pontoAnterior = pol->pontoInicial();
    Elemento<Ponto>* proximoPonto = pontoAnterior->getProximo();

    if (proximoPonto == NULL) {
        cairo_arc(cr, pontoAnterior->getInfo().x, pontoAnterior->getInfo().y, 1, 0, 2 * G_PI);
        cairo_stroke(cr);
    } else {
        do {
            draw_line(cr, pontoAnterior->getInfoPointer(), proximoPonto->getInfoPointer());
            pontoAnterior = proximoPonto;
            proximoPonto = proximoPonto->getProximo();

        } while (proximoPonto != NULL);

        proximoPonto = pol->pontoInicial();
        draw_line(cr, pontoAnterior->getInfoPointer(), proximoPonto->getInfoPointer());
    }

}*/

/*bool draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 1);
    cairo_scale(cr, zoom, zoom);

    Elemento<Poligono>* element = objects->getHead();
    while (element != NULL) {
        Poligono* poligono = element->getInfoPointer();
        if(direction != 0){
            switch (direction){
                case 1:
                    poligono->moveRight(move); break;
                case 2:
                    poligono->moveLeft(move); break;
                case 3:
                    poligono->moveTop(move); break;
                case 4:
                    poligono->moveDown(move); break;
            }
        }
        draw_poligono(cr, poligono);
        element = element->getProximo();
    }
    direction = 0;
    return FALSE;
}*/


void zoom_mais(GtkWidget *widget, gpointer data) {
    zoom *= 1.05;
    gtk_widget_queue_draw((GtkWidget*) data);
}

void zoom_menos(GtkWidget *widget, gpointer data) {
    zoom *= 0.95;
    gtk_widget_queue_draw((GtkWidget*) data);
}

void move_direita(GtkWidget *w, gpointer data)
{
    direction = 1;
    gtk_widget_queue_draw((GtkWidget*) data);

}

void move_esquerda(GtkWidget *w, gpointer data)
{
    direction = 2;
    gtk_widget_queue_draw((GtkWidget*) data);
}

void move_subir(GtkWidget *w, gpointer data)
{
    direction = 3;
    gtk_widget_queue_draw((GtkWidget*) data);
}

void move_descer(GtkWidget *w, gpointer data)
{
    direction = 4;
    gtk_widget_queue_draw((GtkWidget*) data);
}

int main(int argc, char **argv) 
{
    /*Instanciando objetos*/
    GtkBuilder *builder = gtk_builder_new();//Builder representa o .glade criado
    GtkWidget *window;//Janela na qual serao colocados os itens a serem mostrados
    GError *error = NULL;

    /* Inicializa GTK+ */
    gtk_init(&argc, &argv);

    /* Le um arquivo de interface (.glade). Se ocorrer erro, reporta e sai do programa.*/
    if (!gtk_builder_add_from_file(builder, "interface_principal.glade", &error))
    {
        g_warning("%s", error->message);
        g_free(error);
        return (1);
    }

    /* Pega o ponteiro da janela principal da interface*/
    window = GTK_WIDGET(gtk_builder_get_object(builder, "janela_principal"));

    /*Pega o ponteiro de todos os itens na janela principal e os conecta na window*/
    GtkWidget *botaoSubir = GTK_WIDGET(gtk_builder_get_object(builder, "botao_subir"));
    g_signal_connect_swapped(botaoSubir, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    GtkWidget *botaoDescer = GTK_WIDGET(gtk_builder_get_object(builder, "botao_descer"));
    g_signal_connect(botaoDescer, "clicked", G_CALLBACK(impressao_teste), window);

    GtkWidget *botaoEsquerda = GTK_WIDGET(gtk_builder_get_object(builder, "botao_esquerda"));
    g_signal_connect(botaoEsquerda, "clicked", G_CALLBACK(impressao_teste), window);
    
    GtkWidget *botaoDireita = GTK_WIDGET(gtk_builder_get_object(builder, "botao_direita"));
    g_signal_connect(botaoDireita, "clicked", G_CALLBACK(impressao_teste), window);
    
    GtkWidget *zoomMais = GTK_WIDGET(gtk_builder_get_object(builder, "zoom_mais"));
    g_signal_connect(zoomMais, "clicked", G_CALLBACK(impressao_teste), window);
    
    GtkWidget *zoomMenos = GTK_WIDGET(gtk_builder_get_object(builder, "zoom_menos"));
    g_signal_connect(zoomMenos, "clicked", G_CALLBACK(impressao_teste), window);

    GtkWidget *areaDeDesenho = GTK_WIDGET(gtk_builder_get_object(builder, "area_desenho"));
    g_signal_connect(G_OBJECT(areaDeDesenho), "draw", G_CALLBACK(impressao_teste), NULL);

    /* Destruindo o builder */
    g_object_unref(G_OBJECT(builder));
    /* Mostra a janela */
    gtk_widget_show_all(window);
    /* Comeca main loop */
    gtk_main();

    return ( 0);
}
