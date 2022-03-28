#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <openssl/md5.h>

static GtkWidget *lbltitulo,*lblpass;
static GtkWidget *name, *pass, *user;
static GtkWidget *result,*result2;
static int Pasa;

char *str2md5(const char *str, int length) {
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}

void generate_html(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.html",Name);
    char buffer2[32];
    snprintf(buffer2, sizeof(buffer2), "%s",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp," <!DOCTYPE html>\n<html lang='en'>\n<meta charset='UTF-8'>\n<title>%s</title>\n<meta name='viewport' content='width=device-width,initial-scale=1'>\n<link rel='stylesheet' href=''>\n<style>\n</style>\n<script src=''></script>\n<body>\n</body>\n</html>",buffer2);
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}
void generate_java(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.java",Name);
    char buffer2[32];
    snprintf(buffer2, sizeof(buffer2), "%s",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp," public class %s {\n/**\t\n* @param args the command line arguments\n*/\t\npublic static void main(String[] args) {\n\tSystem.out.println(\"\"); // Display the string.\n\t}\n}",buffer2);
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}
void generate_c(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.c",Name);
    char buffer2[32];
    snprintf(buffer2, sizeof(buffer2), "%s",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp,"#include <stdio.h>\nint main(int argc, char **argv) {\n\tprintf(\"%s\");\n\treturn 0;\n}",buffer2);
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}
void generate_python(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.py",Name);
    char buffer2[32];
    snprintf(buffer2, sizeof(buffer2), "%s",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp,"print(\"%s\")",buffer2);
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}
void generate_css(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.css",Name);
    char buffer2[32];
    snprintf(buffer2, sizeof(buffer2), "%s",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp,"*{\n\tbackground: rgb(2,0,36);\n\tfont-family:monospace;\n\tfont-size: 20px;\n\tmargin:0;\n\tcolor:white;\n}");
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}
void generate_php(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.php",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp,"<?php\n/*Tu codigo aqui*/\n?>");
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}
void generate_latex(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.tex",Name);
    char buffer2[32];
    snprintf(buffer2, sizeof(buffer2), "%s",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp,"\\title{%s}\n\\author{}\n\\date{\today}\n\\documentclass[12pt]{article}\n\\begin{document}\n\\maketitle\n\\begin{abstract}\n\\end{abstract}\n\\section{Introduction}\n\\paragraph{Outline}\n\\section{Previous work}\\label{previous work}\n\\section{Results}\\label{results}\n\\section{Conclusions}\\label{conclusions}\n\\bibliographystyle{abbrv}\n\\bibliography{main}\n\\end{document}",buffer2);
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}
void generate_ruby(GtkWidget *html, gpointer data){
    char *Name = (char *)gtk_entry_get_text(GTK_ENTRY(name));
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%s.rb",Name);
    char buffer2[32];
    snprintf(buffer2, sizeof(buffer2), "%s",Name);
    FILE *fp;
    fp = fopen ( buffer, "w" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
    fprintf(fp,"class HelloWorld\n\tdef initialize(name)\n\t\t@name = name.capitalize\n\tend\n\tdef sayHi\n\t\tputs \"Hello #{@name}!\"\n\tend\nend\n\nhello = HelloWorld.new(\"%s\")\nhello.sayHi",buffer2);
	fclose ( fp );
    gtk_label_set_text(GTK_LABEL(result), buffer);
}

/*
Script de compilacion 
gcc `pkg-config gtk+-3.0 --cflags` GeneradorArchivos.c -o GeneradorArchivos `pkg-config gtk+-3.0 --libs`
*/
void MenuInicial(){
    GtkWidget *window, *grid;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET(window), 800, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    GtkWidget *html, *java, *python, *c, *php, *css, *latex, *ruby;
    lbltitulo=gtk_label_new("Inserta el nombre del archivo");
    gtk_grid_attach(GTK_GRID(grid),lbltitulo,0,1, 1, 1);

    name = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), name, 0,2, 1, 1);

    html = gtk_button_new_with_label("Archivo HTML");
    g_signal_connect(html, "clicked", G_CALLBACK(generate_html), NULL);
    gtk_grid_attach(GTK_GRID(grid), html, 0, 3, 1, 1);

    java = gtk_button_new_with_label("Archivo Java");
    g_signal_connect(java, "clicked", G_CALLBACK(generate_java), NULL);
    gtk_grid_attach(GTK_GRID(grid), java, 1, 3, 1, 1);

    python = gtk_button_new_with_label("Archivo Python");
    g_signal_connect(python, "clicked", G_CALLBACK(generate_python), NULL);
    gtk_grid_attach(GTK_GRID(grid), python, 2, 3, 1, 1);

    c = gtk_button_new_with_label("Archivo C");
    g_signal_connect(c, "clicked", G_CALLBACK(generate_c), NULL);
    gtk_grid_attach(GTK_GRID(grid), c, 3, 3, 1, 1);

    php = gtk_button_new_with_label("Archivo PHP");
    g_signal_connect(php, "clicked", G_CALLBACK(generate_php), NULL);
    gtk_grid_attach(GTK_GRID(grid), php, 0, 4, 1, 1);

    css = gtk_button_new_with_label("Archivo CSS");
    g_signal_connect(css, "clicked", G_CALLBACK(generate_css), NULL);
    gtk_grid_attach(GTK_GRID(grid), css, 1, 4, 1, 1);

    latex = gtk_button_new_with_label("Archivo LATEX");
    g_signal_connect(latex, "clicked", G_CALLBACK(generate_latex), NULL);
    gtk_grid_attach(GTK_GRID(grid), latex, 2, 4, 1, 1);

    ruby = gtk_button_new_with_label("Archivo RUBY");
    g_signal_connect(ruby, "clicked", G_CALLBACK(generate_ruby), NULL);
    gtk_grid_attach(GTK_GRID(grid), ruby, 3, 4, 1, 1);

    result = gtk_label_new("result:");
    gtk_grid_attach(GTK_GRID(grid), result, 0, 5, 1, 1);

    gtk_widget_show_all(window);
    gtk_main();
}
void Submit_action(GtkWidget *Submit, gpointer data){
char *US = (char *)gtk_entry_get_text(GTK_ENTRY(user));
char *PAS = (char *)gtk_entry_get_text(GTK_ENTRY(pass));
/*US=admin PAS=password*/
if(strcmp(str2md5(US,strlen(US)),"21232f297a57a5a743894a0e4a801fc3")==0 && strcmp(str2md5(PAS,strlen(PAS)),"5f4dcc3b5aa765d61d8327deb882cf99")==0){
    Pasa=1;
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "Usuario Correcto");
    gtk_label_set_text(GTK_LABEL(result2), buffer);
    MenuInicial(); 
    
}
else{
    Pasa=0;
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "Error Contraseña o Usuario Incorrecto");
    gtk_label_set_text(GTK_LABEL(result2), buffer);
}
}
void InicioSesion(){
    GtkWidget *window, *grid;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET(window), 800, 600);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    GtkWidget *Submit;

    lbltitulo=gtk_label_new("Usuario");
    gtk_grid_attach(GTK_GRID(grid),lbltitulo,0,1, 1, 1);

    user = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), user, 1,1, 1, 1);

    lblpass=gtk_label_new("Contraseña");
    gtk_grid_attach(GTK_GRID(grid),lblpass,0,2, 1, 1);

    pass = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(pass),FALSE);
    gtk_grid_attach(GTK_GRID(grid), pass, 1,2, 1, 1);

    Submit = gtk_button_new_with_label("Enviar");
    g_signal_connect(Submit, "clicked", G_CALLBACK(Submit_action), NULL);
    gtk_grid_attach(GTK_GRID(grid), Submit, 0, 3, 1, 1);

    result2 = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), result2 ,3, 5, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();
}



int main(int argc, char **argv) {
    Pasa=0;
    gtk_init(&argc, &argv);
    InicioSesion();
    return 0;
}
