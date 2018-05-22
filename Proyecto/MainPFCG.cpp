//Semestre 2018-2 Computación gráfica Proyecto Final
//****************************************************************//
//****************************************************************//
//******			Proyecto Final					         *****//
//******			Alumno (s):								 *****//
//******													******//
//******			Angeles Avalos José Enrique				******//
//******			Monterrosas Ramirez Jorge				******//
//******			Landeros Diego							******//
//******			Hugo Delgadillo Cortez					******//
//****************************************************************//
//****************************************************************//
//****************************************************************//
//****************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture cielo; //Cielo
CTexture ventana; //Ventanas
CTexture pasto;
CTexture Textcasa;//Paredes blancas
CTexture Textcasa2;//Ladrillo negro
CTexture Textcasa3;//Castillos parte de abajo
CTexture cedro;//madera cedro
CTexture madera_oscura;
CTexture puertabarra;
CTexture plastico_blanco;
CTexture madera_ropero;
CTexture trooper;
CTexture plasticonegro;
CTexture pielnegra;
CTexture metalrefri;
CTexture frenterefri;
CTexture colcha;
CTexture almohada;
CTexture maderaburo;
CTexture puertaburo;
CTexture puertacomoda;
CTexture maderavieja;
CTexture azulejo;
CTexture fondotv;
CTexture lavad;
CTexture azulejocasa;

//Se utilizarán para definir cada figura que el programador cree//
CFiguras f_enrique;
CFiguras f_jorge;
CFiguras f_hugo;
CFiguras f_ventilador;
//CFiguras f_diego;
//CFiguras fig2;


////Figuras de 3D Studio
//CModel kit;   //DEclarar modelo 
//CModel llanta;
//
//float rot;
////Animación del coche
//float movKit = 0.0;
//bool g_fanimacion = false;
//bool g_fanimacion2 = false;
bool giro_ventilador = false;
float rotVentilador = 0.0;
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    

	/*TEXTURAS*/
    
	cielo.LoadTGA("Exterior/cielo.tga");
	cielo.BuildGLTexture();
	cielo.ReleaseImage();

	trooper.LoadTGA("Casa/trooper.tga");
	trooper.BuildGLTexture();
	trooper.ReleaseImage();

	maderaburo.LoadTGA("Casa/buro.tga");
	maderaburo.BuildGLTexture();
	maderaburo.ReleaseImage();

	fondotv.LoadTGA("Casa/fondo.tga");
	fondotv.BuildGLTexture();
	fondotv.ReleaseImage();

	lavad.LoadTGA("Casa/lavad.tga");
	lavad.BuildGLTexture();
	lavad.ReleaseImage();

	azulejo.LoadTGA("Casa/azulejo.tga");
	azulejo.BuildGLTexture();
	azulejo.ReleaseImage();

	azulejocasa.LoadTGA("Casa/azulejo_casa.tga");
	azulejocasa.BuildGLTexture();
	azulejocasa.ReleaseImage();

	puertaburo.LoadTGA("Casa/puertaburo.tga");
	puertaburo.BuildGLTexture();
	puertaburo.ReleaseImage();

	puertacomoda.LoadTGA("Casa/puertacomoda.tga");
	puertacomoda.BuildGLTexture();
	puertacomoda.ReleaseImage();

	maderavieja.LoadTGA("Casa/maderavieja.tga");
	maderavieja.BuildGLTexture();
	maderavieja.ReleaseImage();

	colcha.LoadTGA("Casa/colcha.tga");
	colcha.BuildGLTexture();
	colcha.ReleaseImage();

	almohada.LoadTGA("Casa/almohada.tga");
	almohada.BuildGLTexture();
	almohada.ReleaseImage();

	plasticonegro.LoadTGA("Casa/plasticonegro.tga");
	plasticonegro.BuildGLTexture();
	plasticonegro.ReleaseImage();

	metalrefri.LoadTGA("Casa/metalrefri.tga");
	metalrefri.BuildGLTexture();
	metalrefri.ReleaseImage();

	frenterefri.LoadTGA("Casa/frenterefri.tga");
	frenterefri.BuildGLTexture();
	frenterefri.ReleaseImage();

	ventana.LoadTGA("Exterior/Vidrio2.tga");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();

	pasto.LoadTGA("Exterior/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	pielnegra.LoadTGA("Casa/pielblanca.tga");
	pielnegra.BuildGLTexture();
	pielnegra.ReleaseImage();

	Textcasa.LoadTGA("Casa/Textcasa.tga");
	Textcasa.BuildGLTexture();
	Textcasa.ReleaseImage();

	Textcasa2.LoadTGA("Casa/Ladrilloblack.tga");
	Textcasa2.BuildGLTexture();
	Textcasa2.ReleaseImage();

	Textcasa3.LoadTGA("Casa/Castillo.tga");
	Textcasa3.BuildGLTexture();
	Textcasa3.ReleaseImage();

	cedro.LoadTGA("Casa/cedro.tga");
	cedro.BuildGLTexture();
	cedro.ReleaseImage();

	madera_oscura.LoadTGA("Casa/madera_oscura.tga");
	madera_oscura.BuildGLTexture();
	madera_oscura.ReleaseImage();

	puertabarra.LoadTGA("Casa/puertabarra.tga");
	puertabarra.BuildGLTexture();
	puertabarra.ReleaseImage();

	plastico_blanco.LoadTGA("Casa/ventilador_metal.tga");
	plastico_blanco.BuildGLTexture();
	plastico_blanco.ReleaseImage();

	madera_ropero.LoadTGA("Casa/madera_ropero.tga");
	madera_ropero.BuildGLTexture();
	madera_ropero.ReleaseImage();

	////Carga de Figuras
	//kit._3dsLoad("kitt.3ds");	
	////kit.VertexNormals();
	//llanta._3dsLoad("k_rueda.3ds");

	//objCamera.Position_Camera(0, 2.5f, 3, 0, 10.0f, 0, 1, 1, 0);
	objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1 , 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}
void mesa(void) {
	glPushMatrix();
	glScalef(2, 0.1, 6);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-.7, -1, 2.7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-.7, -1, -2.7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(.7, -1, 2.7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(.7, -1, -2.7);
	glScalef(.2, 2, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();


}

void mesita(void) {
	glPushMatrix();
	glScalef(2, 0.1, 2);
	f_hugo.esfera(1,10,10, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-.7, -.5, 0.7);
	glScalef(.2, 1, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-.7, -.5, -0.7);
	glScalef(.2, 1, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(.7, -.5, 0.7);
	glScalef(.2, 1, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(.7, -.5, -0.7);
	glScalef(.2, 1, .2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();


}

void silla(void) {//inicia silla

	glPushMatrix();//respaldo
	glScalef(0.7, 1.5, 0.2);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();//asiento
	glTranslatef(0, -0.6, -0.4);
	glScalef(0.7, 0.2, 1);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();//pata1
	glTranslatef(0.3, -1.2, -0.85);
	glScalef(0.1, 1, 0.1);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();//pata2
	glTranslatef(-0.3, -1.2, -0.85);
	glScalef(0.1, 1, 0.1);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();//pata3
	glTranslatef(0.3, -1.2, 0.05);
	glScalef(0.1, 1, 0.1);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();//4
	glTranslatef(-0.3, -1.2, 0.05);
	glScalef(0.1, 1, 0.1);
	f_hugo.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

}//termina silla

void barracocina(void) {
	glPushMatrix();
	glScalef(8, 0.1, 2);
	f_jorge.prisma2(madera_oscura.GLindex, madera_oscura.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-1,0);
	glScalef(8, 2, 2);
	f_jorge.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5,-1,-1.5);
	glRotatef(90, 0, 1, 0);
	glScalef(5, 2, 2);
	f_jorge.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5,0,-1.5);
	glRotatef(90, 0, 1, 0);
	glScalef(5, 0.1, 2);
	f_jorge.prisma2(madera_oscura.GLindex, madera_oscura.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,-1.3,-3.3);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1.2, 0.2);
	f_jorge.prisma2(puertabarra.GLindex, puertabarra.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,-1.3,-1.3);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1.2, 0.2);
	f_jorge.prisma2(puertabarra.GLindex, puertabarra.GLindex);
	glPopMatrix();
}

void ventilador(void) {

	glPushMatrix();//centro
		glRotatef(rotVentilador,0.0,1.0,0.0);
		glPushMatrix();
			glScalef(0.5, 0.2, 0.5);
			f_ventilador.esfera(1, 10, 10 , plastico_blanco.GLindex);
		glPopMatrix();
	
		glPushMatrix();//1
			glScalef(1.5, 0.1, 0.3);
			glTranslatef(0.8,0,0);
			f_ventilador.prisma2(plastico_blanco.GLindex, plastico_blanco.GLindex);
		glPopMatrix();

		glPushMatrix();//2
			glScalef(1.5, 0.1, 0.3);
			glTranslatef(-0.8,0,0);
			f_ventilador.prisma2(plastico_blanco.GLindex, plastico_blanco.GLindex);
		glPopMatrix();

		glPushMatrix();//3
			glRotatef(90,0,1,0);
			glScalef(1.5, 0.1, 0.3);
			glTranslatef(0.8,0,0);
			f_ventilador.prisma2(plastico_blanco.GLindex, plastico_blanco.GLindex);
		glPopMatrix();

		glPushMatrix();//4
			glRotatef(90,0,1,0);
			glScalef(1.5, 0.1, 0.3);
			glTranslatef(-0.8,0,0);
			f_ventilador.prisma2(plastico_blanco.GLindex, plastico_blanco.GLindex);
		glPopMatrix();

		glPushMatrix();//barra
			glScalef(0.3, 1, 0.3);
			f_ventilador.cilindro(0.2, 1, 10, plastico_blanco.GLindex);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();//barra
			glScalef(0.3, 1, 0.3);
			glTranslatef(0,1,0);
			f_ventilador.cilindro(0.8, 0.2, 10, plastico_blanco.GLindex);
		glPopMatrix();
	
}

void barra(void) {
	glPushMatrix();
	glScalef(8, 0.1, 2);
	f_jorge.prisma2(madera_oscura.GLindex, madera_oscura.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-1,0);
	glScalef(8, 2, 2);
	f_jorge.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5,-1,-1.5);
	glRotatef(90, 0, 1, 0);
	glScalef(5, 2, 2);
	f_jorge.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5,0,-1.5);
	glRotatef(90, 0, 1, 0);
	glScalef(5, 0.1, 2);
	f_jorge.prisma2(madera_oscura.GLindex, madera_oscura.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,-1.3,-3.3);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1.2, 0.2);
	f_jorge.prisma2(puertabarra.GLindex, puertabarra.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,-1.3,-1.3);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1.2, 0.2);
	f_jorge.prisma2(puertabarra.GLindex, puertabarra.GLindex);
	glPopMatrix();
}

void ropero(void) {
	glPushMatrix();
	glScalef(9, 7, 2);
	f_jorge.prisma2(madera_ropero.GLindex, madera_ropero.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-1);
	glScalef(9, 7, 0.2);
	f_jorge.prisma2(puertabarra.GLindex, puertabarra.GLindex);
	glPopMatrix();
}

void comoda(void) {
	glPushMatrix();
	glScalef(9, 5, 2);
	f_jorge.prisma2(maderavieja.GLindex, maderavieja.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-1);
	glScalef(9, 5, 0.2);
	f_jorge.prisma2(puertacomoda.GLindex, puertacomoda.GLindex);
	glPopMatrix();
}

void pared(void) {
	glPushMatrix();
	glScalef(23, 20, 1);
	f_jorge.prisma2(Textcasa.GLindex, Textcasa.GLindex);
	glPopMatrix();

}

void piso(void) {
	glPushMatrix();
	glScalef(10, 0.5, 10);
	f_jorge.prisma(1,1,1,azulejocasa.GLindex, azulejocasa.GLindex, azulejocasa.GLindex, azulejocasa.GLindex, azulejocasa.GLindex, azulejocasa.GLindex);
	glPopMatrix();

}

void buro(void) {
	glPushMatrix();
	glScalef(1.9, 2.4, 1);
	f_jorge.prisma2(maderaburo.GLindex, maderaburo.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-0.5);
	glScalef(1.9, 2.4, 0.2);
	f_jorge.prisma2(puertaburo.GLindex, puertaburo.GLindex);
	glPopMatrix();
}

void refri(void) {
	glPushMatrix();
	glScalef(3, 5, 2);
	f_jorge.prisma2(metalrefri.GLindex, metalrefri.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,1);
	glRotatef(-90,0,0,1);
	glScalef(5, 3, 0.1);
	f_jorge.prisma2(frenterefri.GLindex, frenterefri.GLindex);
	glPopMatrix();
}

void lavabo(void) {
	glPushMatrix();
	glScalef(3, 0.1, 2);
	f_jorge.prisma2(azulejo.GLindex, azulejo.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1,1);
	glScalef(3, 2, 0.1);
	f_jorge.prisma2(azulejo.GLindex, azulejo.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1.6,1);
	glScalef(3, 0.8, 0.5);
	f_jorge.prisma2(azulejo.GLindex, azulejo.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,2,1);
	glScalef(0.3, 1.2, 0.3);
	f_jorge.prisma2(metalrefri.GLindex, metalrefri.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,2.4,0.3);
	glScalef(0.3, 0.3, 1.2);
	f_jorge.prisma2(metalrefri.GLindex, metalrefri.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1,-1);
	glScalef(3, 2, 0.1);
	f_jorge.prisma2(azulejo.GLindex, azulejo.GLindex);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(0,1,1.5);
	glScalef(2, 2, 0.1);
	f_jorge.prisma2(azulejo.GLindex, azulejo.GLindex);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90,0,1,0);
	glTranslatef(0,1,1.5);
	glScalef(2, 2, 0.1);
	f_jorge.prisma2(azulejo.GLindex, azulejo.GLindex);
	glPopMatrix();
}

void regadera(void) {
	glPushMatrix();
	glTranslatef(0,10,0.7);
	glScalef(0.3,0.3,1.5);
	f_jorge.prisma2(metalrefri.GLindex, metalrefri.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,10,0);
	glScalef(0.3,1.5,0.3);
	f_jorge.prisma2(metalrefri.GLindex, metalrefri.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,9,0);
	glScalef(1.5,0.3,1.5);
	f_jorge.prisma2(metalrefri.GLindex, metalrefri.GLindex);
	glPopMatrix();
}

void sillon(void) {
	glPushMatrix();
	glScalef(9, 2, 2);
	f_jorge.prisma2(pielnegra.GLindex, pielnegra.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1,2);
	glScalef(9, 4, 2);
	f_jorge.prisma2(pielnegra.GLindex, pielnegra.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.3,1,1);
	glScalef(0.7, 1, 3);
	f_jorge.prisma2(pielnegra.GLindex, pielnegra.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.3,1,1);
	glScalef(0.7, 1, 3);
	f_jorge.prisma2(pielnegra.GLindex, pielnegra.GLindex);
	glPopMatrix();
}


void cama(void) {
	glPushMatrix();
	glScalef(6, 0.5, 3);
	f_jorge.prisma2(colcha.GLindex, colcha.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-0.3,0);
	glScalef(6.5, 0.4, 3.5);
	f_jorge.prisma2(cedro.GLindex, cedro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.3,0.4,0);
	glScalef(1, 0.3, 2.5);
	f_jorge.prisma2(almohada.GLindex, almohada.GLindex);
	glPopMatrix();
}

void cuadro(void) {
	glPushMatrix();
	glScalef(5.6, 4.6, 0.1);
	f_jorge.prisma2(madera_ropero.GLindex, madera_ropero.GLindex);
	glPopMatrix();

	glPushMatrix();
	glScalef(4.7, 3.7, 0.1);
	glTranslatef(0,0,0.2);
	f_jorge.prisma2(trooper.GLindex, trooper.GLindex);
	glPopMatrix();
}

void lavadora(void) {
	glPushMatrix();
	glTranslatef(-41.5, 7.6, 9);
	glScalef(5.6, 4.6, 0.1);
	f_jorge.cilindro(1,2, 10,lavad.GLindex);
	glPopMatrix();

}

void tv(void) {
	glPushMatrix();
	glScalef(5, 4, 0.1);
	f_jorge.prisma2(plasticonegro.GLindex, plasticonegro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0.1);
	glScalef(4, 3, 0.1);
	f_jorge.prisma2(fondotv.GLindex, fondotv.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-2.5,0);
	glScalef(1, 1, 0.1);
	f_jorge.prisma2(plasticonegro.GLindex, plasticonegro.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-3,0);
	glScalef(4, 0.1, 1);
	f_jorge.prisma2(plasticonegro.GLindex, plasticonegro.GLindex);
	glPopMatrix();
}

void casa()
{		
	glPushMatrix();//inicio casa
	glTranslatef(0 , 0, 0);
	
	glPushMatrix();//inicio piso
	glTranslatef(-5, 0, -37);
	glScalef(16,1,2.8);
	piso();
	glPopMatrix();//fin piso

	glPushMatrix();//inicio pared
	glTranslatef(75, 10, -27.8);
	glRotatef(90,0,1,0);
	glScalef(0.4,1,0.2);
	pared();
	glPopMatrix();//fin pared

	glPushMatrix();//inicio pared2
	glTranslatef(75, 10, -46.5);
	glRotatef(90,0,1,0);
	glScalef(0.4,1,0.2);
	pared();
	glPopMatrix();//fin pared2

	glPushMatrix();//inicio pared3
	glTranslatef(57.8, 10, -51.1);
	glRotatef(180, 0, 1, 0);
	glScalef(1.5, 1, 0.2);
	pared();
	glPopMatrix();//fin pared3

	glPushMatrix();//inicio pared4
	glTranslatef(46.3, 10, -23.1);
	glRotatef(180, 0, 1, 0);
	glScalef(2.5, 1, 0.2);
	pared();
	glPopMatrix();//fin pared4

	glPushMatrix();//inicio pared5
	glTranslatef(44, 10, -42.9);
	glRotatef(90, 0, 1, 0);
	glScalef(0.7, 1, 0.2);
	pared();
	glPopMatrix();//fin pared5

	glPushMatrix();//inicio pared6
	glTranslatef(30.5, 10, -51.1);
	glRotatef(180, 0, 1, 0);
	glScalef(0.4, 1, 0.2);
	pared();
	glPopMatrix();//fin pared6

	glPushMatrix();//inicio pared7
	glTranslatef(30.5, 10, -42.9);
	glRotatef(90, 0, 1, 0);
	glScalef(0.7, 1, 0.2);
	pared();
	glPopMatrix();//fin pared7

	glPushMatrix();//inicio pared8
	glTranslatef(30.5, 10, -34.9);
	glRotatef(180, 0, 1, 0);
	glScalef(0.5, 1, 0.2);
	pared();
	glPopMatrix();//fin pared8

	glPushMatrix();//inicio pared9
	glTranslatef(14.5, 10, -51.1);
	glRotatef(180, 0, 1, 0);
	glScalef(0.5, 1, 0.2);
	pared();
	glPopMatrix();//fin pared9

	glPushMatrix();//inicio pared10
	glTranslatef(16, 10, -42.9);
	glRotatef(90, 0, 1, 0);
	glScalef(0.7, 1, 0.2);
	pared();
	glPopMatrix();//fin pared10

	glPushMatrix();//inicio pared11
	glTranslatef(16, 10, -34.9);
	glRotatef(180, 0, 1, 0);
	glScalef(0.1, 1, 0.2);
	pared();
	glPopMatrix();//fin pared11

	glPushMatrix();//inicio pared12
	glTranslatef(-18, 10, -23.1);
	glRotatef(180, 0, 1, 0);
	glScalef(2.5, 1, 0.2);
	pared();
	glPopMatrix();//fin pared12

	glPushMatrix();//inicio pared13
	glTranslatef(-12, 10, -51.1);
	glRotatef(180, 0, 1, 0);
	glScalef(0.8, 1, 0.2);
	pared();
	glPopMatrix();//fin pared13

	glPushMatrix();//inicio pared14
	glTranslatef(-12, 10, -42.9);
	glRotatef(90, 0, 1, 0);
	glScalef(0.7, 1, 0.2);
	pared();
	glPopMatrix();//fin pared14

	glPushMatrix();//inicio pared15
	glTranslatef(-2.9, 10, -34.9);
	glRotatef(180, 0, 1, 0);
	glScalef(0.8, 1, 0.2);
	pared();
	glPopMatrix();//fin pared15

	glPopMatrix();//fin casa
}


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	f_enrique.skybox(300.0, 220.0, 300.0, cielo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Creación del Piso/pasto
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glRotatef(90, 0.0, 0.0, 1.0);
	glTranslatef(-30.0, 0.0, 0.0);
	f_enrique.piso(300.8, 1.5, 300, pasto.GLindex, pasto.GLindex, pasto.GLindex, pasto.GLindex, pasto.GLindex, pasto.GLindex);
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//casa
		glTranslatef(0,-29,-35);
		glScalef(1.6,1,2);
		casa();
	glPopMatrix();//fin casa

	glPushMatrix();//buro
		glTranslatef(115,-27.6,-83);
		buro();
	glPopMatrix();//fin buro

	///////////
			glPopMatrix();//Pop para todo el escenario
		glPopMatrix();

		glPopMatrix();//fin
	
	glutSwapBuffers ( );

}



void animacion()
{
	if(giro_ventilador){
		rotVentilador += 1.0;
	}
//
//
//	if(g_fanimacion)
//	{
//		movKit +=1.0;
//		rot += 1.0;
//	}
//
//	if (g_fanimacion2)
//	{
//		movKit -= 1.0;
//		rot  -= 1.0;
//	}
//	
//
//
	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 400.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.4 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.4));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'v':
		case 'V':
			giro_ventilador ^= true;
			break;
		//case ' ':		//Poner algo en movimiento
		//	g_fanimacion = true; //Activamos/desactivamos la animacíon
		//	break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (700, 700);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final CG"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}


/*
	//		glPushMatrix();
	//			//Para que el coche conserve sus colores
	//				glDisable(GL_COLOR_MATERIAL);
	//				glRotatef(90, 0, 1, 0);
	//				glScalef(0.3, 0.3, 0.3);

	//				if (movKit > 100)
	//				{
	//					g_fanimacion = false;
	//					g_fanimacion2 = true;
	//				
	//				}

	//				if (movKit == 0)
	//				{
	//					g_fanimacion2 = false;
	//					g_fanimacion = false;
	//				}


	//				glTranslatef(0, 4, movKit); //movkit
	//				//Pongo aquí la carroceria del carro
	//				kit.GLrender(NULL,_SHADED,1.0);  //_WIRED O _POINTS //Mandar a llamar al carro

	//				glPushMatrix();
	//					glTranslatef(-6.0, -1.0, 7.5);
	//					glRotatef(rot, 1, 0, 0);
	//					llanta.GLrender(NULL,_SHADED,1.0); //LLanta del lado derecho
	//				glPopMatrix();

	//				glPushMatrix();
	//					glTranslatef(6.0, -1.0, 7.5); //Lanta izquierda
	//					glRotatef(180, 0, 1, 0);
	//					glRotatef(-rot, 1, 0, 0);
	//					llanta.GLrender(NULL, _SHADED, 1.0);
	//				glPopMatrix();

	//				glPushMatrix();
	//					glTranslatef(6.0, -1.0, -9.5);//Lanta trasera
	//					glRotatef(180, 0, 1, 0);
	//					glRotatef(-rot, 1, 0, 0);
	//					llanta.GLrender(NULL, _SHADED, 1.0);
	//				glPopMatrix();

	//				glPushMatrix();
	//					glTranslatef(-6.0, -1.0, -9.5); //Llanta trasera
	//					glRotatef(rot, 1, 0, 0);
	//					llanta.GLrender(NULL, _SHADED, 1.0);
	//				glPopMatrix();
	//		glPopMatrix();

	//		//Para que el comando glColor funcione con iluminacion
	//		glEnable(GL_COLOR_MATERIAL);
	//		
	//	glPopMatrix();
	//glPopMatrix();*/



	//			casa();
	//			//glPushMatrix();
	//			//	glEnable(GL_BLEND); //Para las ventanas usar esto
	//			//	glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_COLOR);
	//			//	glRotatef(90, 1.0, 0.0, 0.0);
	//			//	glTranslatef(0.0, 0.0, 0.0);
	//			//	f_enrique.prisma(5.0,8.0,3.0,ventana.GLindex);
	//			//	glDisable(GL_BLEND);
	//			//glPopMatrix();