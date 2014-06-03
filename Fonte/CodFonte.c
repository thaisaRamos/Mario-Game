

#include <stdio.h> //Imput Output
#include "glut.h" //Janelas etc...
#include "fmod.h" //Som
#include "fmod_errors.h" //Som 

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>


#if !defined(GL_VERSION_1_1)
#define glBindTexture glBindTextureEXT
#define glAreTexturesResident glAreTexturesResidentEXT
#endif

#define Ri  4
#define Ro  8

#define COLORS 12
#define color( c )  glColor3ubv( colors[ COLORS / num_spheres * c ] )

#define num_stars 500

GLint num_textures = 4;

GLenum mode   = GL_MODULATE;
GLenum filter = GL_LINEAR;

GLuint width, height;

#define MAX 4
GLint idText[MAX];

char texnames[4][64] = {
   "C:/Dev-Cpp/smart-car-1.PPM",
   "C:/Dev-Cpp/mariof.PPM",
   "C:/Dev-Cpp/Super_Mario_poster_by_Makotron.PPM",
   "C:/Dev-Cpp/mario6.PPM",
};

unsigned char* ppmRead( char* filename, int* width, int* height ) {

   FILE* fp;
   int i, w, h, d;
   unsigned char* image;
   char head[70];

   fp = fopen( filename, "rb" );
   if ( !fp ) {
      perror(filename);
      return NULL;
   }

   fgets(head, 70, fp);
   if (strncmp(head, "P6", 2)) {
      fprintf(stderr, "%s: Not a raw PPM file\n", filename);
      return NULL;
   }

   i = 0;
   while( i < 3 ) {
      fgets( head, 70, fp );
      if ( head[0] == '#' )
         continue;
      if ( i == 0 )
         i += sscanf( head, "%d %d %d", &w, &h, &d );
      else if ( i == 1 )
         i += sscanf( head, "%d %d", &h, &d );
      else if ( i == 2 )
         i += sscanf( head, "%d", &d );
   }

   image = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
   fread( image, sizeof( unsigned char ), w * h * 3, fp );
   fclose( fp );

   *width = w;
   *height = h;
   return image;

}



void display( void ) {

     static int i, step;
     static char s[16], *p;

   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   
                    glDepthMask(GL_TRUE);
                    glEnable(GL_DEPTH_TEST);
                    glEnable(GL_LIGHTING);                    
                    glMatrixMode(GL_PROJECTION);
              glPopMatrix();
              glMatrixMode(GL_MODELVIEW);
         glPopMatrix();   
}


//Declaracoes das variaveis
GLint mover=0;
GLint movercarro=0;
GLint movercarro2=0;
GLint movermadeira=0;
GLint movermadeira1=0;
GLint movermadeira2=0;
GLint direcao=1;
GLint moversapox=0;
GLint moversapoy=0;
GLint prediox=0;
GLint predioy=0;
GLint tempo=0;
GLint lado=0;


//Desenha a pista
void Pista ()
     {
     
         
           
       	glColor3f(0,0,1);        
        glLineWidth(45);    
        glBegin(GL_LINE_LOOP);
        glVertex2i( 0, 1 );
        glVertex2i( 37.9, 1 );
        glVertex2i( 37.9, 9 );
        glVertex2i( 0, 9 );
        glEnd( );
        
        //primeira faixa de linha
        
	    glColor3f(1,1,1);
        
        glLineWidth(1000);
    	glBegin(GL_LINES);
    	glVertex2i(0,4.9);
		glVertex2i(40.3,4.9);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(2,3);
		glVertex2i(2,4);
		glEnd();		
	
    	        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(4,3);
		glVertex2i(4,4);
		glEnd();
    
    	      
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(6,3);
		glVertex2i(6,4);
		glEnd();
			        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(8,3);
		glVertex2i(8,4);
		glEnd();
			       
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(10,3);
		glVertex2i(10,4);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(12,3);
		glVertex2i(12,4);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(14,3);
		glVertex2i(14,4);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(16,3);
		glVertex2i(16,4);
		glEnd();
		
		       
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(18,3);
		glVertex2i(18,4);
		glEnd();
		       
        glLineWidth(8);
        
    	glBegin(GL_LINES);
    	glVertex2i(20,3);
		glVertex2i(20,4);
		glEnd();
    	
    	     
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(22,3);
		glVertex2i(22,4);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(24,3);
		glVertex2i(24,4);
		glEnd();
		
		    
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(26,3);
		glVertex2i(26,4);
		glEnd();
		
		       
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(28,3);
		glVertex2i(28,4);
		glEnd();
		
	        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(30,3);
		glVertex2i(30,4);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(32,3);
		glVertex2i(32,4);
		glEnd();
    	
    	
    	       
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(34,3);
		glVertex2i(34,4);
		glEnd();
		
		      
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(36,3);
		glVertex2i(36,4);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(38,3);
		glVertex2i(38,4);
		glEnd();
    	
    	      
        glLineWidth(1000);
    	glBegin(GL_LINES);
    	glVertex2i(0,3);
		glVertex2i(40.3,3);
		glEnd();
    	
		//segunda faixa de linha
		
		         
        glLineWidth(1000);
    	glBegin(GL_LINES);
    	glVertex2i(0,6);
		glVertex2i(40.3,6);
		glEnd();
		
		//faixa do meio
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(2,6);
		glVertex2i(2,7);
		glEnd();		
	
    	      
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(4,6);
		glVertex2i(4,7);
		glEnd();
    
    	        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(6,6);
		glVertex2i(6,7);
		glEnd();
			       
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(8,6);
		glVertex2i(8,7);
		glEnd();
			       
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(10,6);
		glVertex2i(10,7);
		glEnd();
		
		      
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(12,6);
		glVertex2i(12,7);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(14,6);
		glVertex2i(14,7);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(16,6);
		glVertex2i(16,7);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(18,6);
		glVertex2i(18,7);
		glEnd();
		        
        glLineWidth(8);
        
    	glBegin(GL_LINES);
    	glVertex2i(20,6);
		glVertex2i(20,7);
		glEnd();
    	
    	        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(22,6);
		glVertex2i(22,7);
		glEnd();
		
		    
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(24,6);
		glVertex2i(24,7);
		glEnd();
		
		      
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(26,6);
		glVertex2i(26,7);
		glEnd();
		
		      
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(28,6);
		glVertex2i(28,7);
		glEnd();
		
		     
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(30,6);
		glVertex2i(30,7);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(32,6);
		glVertex2i(32,7);
		glEnd();
    	
    	
    	        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(34,6);
		glVertex2i(34,7);
		glEnd();
		
		        
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(36,6);
		glVertex2i(36,7);
		glEnd();
		
		      
        glLineWidth(8);
    	glBegin(GL_LINES);
    	glVertex2i(38,6);
		glVertex2i(38,7);
		glEnd();
		
		
		
		       
        glLineWidth(1000);
    	glBegin(GL_LINES);
    	glVertex2i(0,7.5);
		glVertex2i(40.3,7.5);
		glEnd();
		
        
        
        glColor3f(0.5f,0.5f,0.5f);
        //Gramado
	    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(0,9.2);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0,10.0);
		glTexCoord2f(0.0f, 1.0f); glVertex2f( 39.0,10.0);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(39.0,9.2);
        glEnd();      
        
        glBegin(GL_QUADS);
        glColor3f(0.5f,0.5f,0.5f);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(0,0.0);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0,0.8);
		glTexCoord2f(1.0f, 0.0f); glVertex2f( 39.0,0.8);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(39.0,0.0);
        glEnd(); 
        
        
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D ,3);        
       
        glBegin(GL_QUADS);
     
        glColor3f(1,1,1);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(5,10);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(5,13);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(30.0,13);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(30.0,10);
        glEnd(); 
        
          
    
         glDisable(GL_TEXTURE_2D); 
        
        

   //  glutSwapBuffers();
     } 
        
        
     
     
     
     
     
//Desenha o  mario    
void Sapo ()
     {  
          glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D ,2);        
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        
  	    glTexCoord2f(0.0,0.0);glVertex2f (moversapox+15,moversapoy+0.1);
  	    glTexCoord2f(1.0,0.0);glVertex2f (moversapox+15,moversapoy+1.5);
	    glTexCoord2f(1.0,1.0);glVertex2f (moversapox+17,moversapoy+1.5);
	    glTexCoord2f(0.0,1.0);glVertex2f (moversapox+17,moversapoy+0.1);
        glEnd();  	  
         glDisable(GL_TEXTURE_2D); 
     }


void Sapo2()
     {  
          glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D ,4);        
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        
  	    glTexCoord2f(0.0,0.0);glVertex2f (moversapox+15,moversapoy+0.1);
  	    glTexCoord2f(1.0,0.0);glVertex2f (moversapox+15,moversapoy+1.5);
	    glTexCoord2f(1.0,1.0);glVertex2f (moversapox+17,moversapoy+1.5);
	    glTexCoord2f(0.0,1.0);glVertex2f (moversapox+17,moversapoy+0.1);
        glEnd();  	  
         glDisable(GL_TEXTURE_2D); 
     }

          
//Desenha o caminhao
void Caminhao ()
 
        { 
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D ,1);        
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
        
  	    glTexCoord2f(0.0,0.0);glVertex2f (movercarro+2,4.5);
  	    glTexCoord2f(1.0,0.0);glVertex2f (movercarro+2,5.5);
	    glTexCoord2f(1.0,1.0);glVertex2f (movercarro+4,5.5);
	    glTexCoord2f(0.0,1.0);glVertex2f (movercarro+4,4.5);
        glEnd();  	   
         
         glDisable(GL_TEXTURE_2D);
        }

//Desenha o caminhao2
void Caminhao2 ()
        {  
               
               glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D ,1);        
        glColor3f(0,1,0);
        glBegin(GL_QUADS);
        num_textures-1;
  	    glTexCoord2f(0.0,0.0);glVertex2f (movercarro2+2,7.5);
  	    glTexCoord2f(1.0,0.0);glVertex2f (movercarro2+2,8.5);
	    glTexCoord2f(1.0,1.0);glVertex2f (movercarro2+4,8.5);
	    glTexCoord2f(0.0,1.0);glVertex2f (movercarro2+4,7.5);
        glEnd();  	   
         
         glDisable(GL_TEXTURE_2D);
                
        glEnd();      
        }

//Desenha o onibus
void Onibus ()
     {
        {    
             
             
             glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D ,1);        
       // glColor3f(0.5,0,0);
        glColor3f(1,0,1); 
        glBegin(GL_QUADS);
        num_textures-1;
  	    glTexCoord2f(0.0,0.0);glVertex2f (mover+1,1.5);
  	    glTexCoord2f(1.0,0.0);glVertex2f (mover+1,2.5);
	    glTexCoord2f(1.0,1.0);glVertex2f (mover+3,2.5);
	    glTexCoord2f(0.0,1.0);glVertex2f (mover+3,1.5);
        glEnd();  	   
         
         glDisable(GL_TEXTURE_2D);
                
        glEnd();
             
             
             
             
       
        glBegin(GL_QUADS);
  	    
  	    
	    
	    
        glEnd();      
        }
        {
        //Escrevendo um texto na tela
        //posicionamos na tela
        glRasterPos2f(mover+1.0, 2.0);
        //String a ser escrita na tela
        
        }
     }   
     
//Movimentação automatica ir e voltar  (Busao Jiraya)
void movimentar(int passo)
     {
        if(direcao==1)
        {
        mover += 4;
        if(mover==36) direcao = 0;
        }
        else
        {
        mover -= 4;
        if(mover==-8) direcao = 1;
        }

        glutPostRedisplay();
        glutTimerFunc(100-tempo,movimentar, 1);
     }
        
//Movimentação automatica apenas ir 
void movimentacarro(int passo) //Carro verde (Caminhao)
     {
        {
        movercarro -= 4;
        if(movercarro == -8) 
        {
        movercarro = 36;
        }
        glutPostRedisplay();
        glutTimerFunc(100-tempo,movimentacarro, 1);
        }
     }
void movimentacarro2(int passo) //Carro azul (Caminhao2)
     {
        {
        movercarro2 -= 4;
        if(movercarro2 == -8) 
        {
        movercarro2 = 32;
        }
        glutPostRedisplay();
        glutTimerFunc(100-tempo,movimentacarro2, 1);
        }
     }     
//Movimentação automatica ir e voltar  (mover madeira)
void movermad(int passo)
     {
        {
        movermadeira += 2;
        if(movermadeira == 36) 
        {
        movermadeira = -4;
        }
        glutPostRedisplay();
        glutTimerFunc(100-tempo,movermad, 1);
        }
     }       
//Movimentação automatica apenas ir (Madeira)
void movermad1 (int passo) //
     {
        {
        movermadeira1 -= 2;
        if(movermadeira1 == -8) 
        {
        movermadeira1 = 36;
        }
        glutPostRedisplay();
        glutTimerFunc(100-tempo,movermad1, 1);
        }
     }
//Movimentação automatica apenas ir (Madeira)     
void movermad2 (int passo) //
     {
        {
        movermadeira2 -= 2;
        if(movermadeira2 == -8) 
        {
        movermadeira2 = 32;
        }
        glutPostRedisplay();
        glutTimerFunc(100-tempo,movermad2, 1);
        }
     }     
     
     
//Caso o carro passe por cima do sapo, retornar ao inicio     
void Colisao ()
     {
     if ((mover-10 == moversapox+1) && (2 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+2) && (2 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+3) && (2 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+4) && (2 == moversapoy+1)) moversapoy = 0;

if ((mover-10 == moversapox+1) && (2 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+2) && (3 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+3) && (3 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+4) && (3 == moversapoy+1)) moversapoy = 0;

     if ((movercarro-10 == moversapox+1) && (5 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+2) && (5 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+3) && (5 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+4) && (5 == moversapoy+1)) moversapoy = 0;

      if ((movercarro-10 == moversapox+1) && (6 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+2) && (6 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+3) && (6 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+4) && (6 == moversapoy+1)) moversapoy = 0;

     if ((movercarro2-10 == moversapox+1) && (8 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+2) && (8 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+3) && (8 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+4) && (8 == moversapoy+1)) moversapoy = 0;

      if ((movercarro2-10 == moversapox+1) && (9 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+2) && (9 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+3) && (9 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+4) && (9 == moversapoy+1)) moversapoy = 0;
  


     if ((10 == moversapoy+1) && (lado == 0)) lado = 1;  //Mudanca de lado
     if ((10 == moversapoy+1) && (lado == 2)) lado = 3;  //Mudanca de lado
     if ((10 == moversapoy+1) && (lado == 4)) lado = 5;  //Mudanca de lado
              
     glutPostRedisplay();
     }




void Colisao2()
     {
     if ((mover-10 == moversapox+1) && (2 == moversapoy+1)) moversapoy = 9;
     if ((mover-10 == moversapox+2) && (2 == moversapoy+1)) moversapoy = 9;
     if ((mover-10 == moversapox+3) && (2 == moversapoy+1)) moversapoy = 9;
     if ((mover-10 == moversapox+4) && (2 == moversapoy+1)) moversapoy = 9;

     if ((mover-10 == moversapox+1) && (2 == moversapoy+1)) moversapoy = 9;
     if ((mover-10 == moversapox+2) && (3 == moversapoy+1)) moversapoy = 9;
     if ((mover-10 == moversapox+3) && (3 == moversapoy+1)) moversapoy = 9;
     if ((mover-10 == moversapox+4) && (3 == moversapoy+1)) moversapoy = 9;

     if ((movercarro-10 == moversapox+1) && (5 == moversapoy+1)) moversapoy = 9;
     if ((movercarro-10 == moversapox+2) && (5 == moversapoy+1)) moversapoy = 9;
     if ((movercarro-10 == moversapox+3) && (5 == moversapoy+1)) moversapoy = 9;
     if ((movercarro-10 == moversapox+4) && (5 == moversapoy+1)) moversapoy = 9;

      if ((movercarro-10 == moversapox+1) && (6 == moversapoy+1)) moversapoy = 9;
     if ((movercarro-10 == moversapox+2) && (6 == moversapoy+1)) moversapoy = 9;
     if ((movercarro-10 == moversapox+3) && (6 == moversapoy+1)) moversapoy = 9;
     if ((movercarro-10 == moversapox+4) && (6 == moversapoy+1)) moversapoy = 9;

     if ((movercarro2-10 == moversapox+1) && (8 == moversapoy+1)) moversapoy = 9;
     if ((movercarro2-10 == moversapox+2) && (8 == moversapoy+1)) moversapoy = 9;
     if ((movercarro2-10 == moversapox+3) && (8 == moversapoy+1)) moversapoy = 9;
     if ((movercarro2-10 == moversapox+4) && (8 == moversapoy+1)) moversapoy = 9;

     if ((movercarro2-10 == moversapox+1) && (9 == moversapoy+1)) moversapoy = 9;
     if ((movercarro2-10 == moversapox+2) && (9 == moversapoy+1)) moversapoy = 9;
     if ((movercarro2-10 == moversapox+3) && (9 == moversapoy+1)) moversapoy = 9;
     if ((movercarro2-10 == moversapox+4) && (9 == moversapoy+1)) moversapoy = 9;
  
     
     if ((1 == moversapoy+1) && (lado == 1)) lado = 2;  //Mudanca de lado
     if ((1 == moversapoy+1) && (lado == 3)) lado = 4;  //Mudanca de lado 
     if ((1 == moversapoy+1) && (lado == 5)) lado = 6;  //Mudanca de lado  

     
              
     glutPostRedisplay();
     }











     
void iniciaText(){
     GLint w, h, i;
     GLbyte* texture;
     
     glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
     glEnable(GL_TEXTURE_2D);
     for ( i = 0; i < 4; i++ ) {
     glBindTexture(GL_TEXTURE_2D, i+1);
     texture = (GLubyte*) ppmRead(texnames[i], &w, &h);
     gluBuild2DMipmaps(GL_TEXTURE_2D, 3, w, h, GL_RGB, GL_UNSIGNED_BYTE, texture);
     free(texture);
     }
     glDisable(GL_TEXTURE_2D);
      
}

void Comentarios1 ()
     {
        {         
        glColor3f(1,1,1);
        glRasterPos2f(9.0, 8.0);         
        char* p = (char*) "VOCE GANHOU! PARABENS!!!";
        while (*p != '\0')
            {   
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
            }
        }  
        
        {         
        glColor3f(1,1,1);
        glRasterPos2f(9.2, 6.0);         
        char* p = (char*) "Espaco disponivel...";
        while (*p != '\0')
            {   
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
            }
        }   
     }



     
//Chama o desenho
void Desenha(void)
{
     
     
	//Limpa a janela de visualização com a cor de fundo especificada 
    if(lado == 0) 
    {
    tempo = 0;  //Nivel 1, velocidade dos carros   
    glClear(GL_COLOR_BUFFER_BIT);
    Pista();
    Colisao();
    Onibus();
    Caminhao();
    Caminhao2();
    Sapo2();
    glutSwapBuffers();
    }
    if(lado == 1) 
    {
    tempo = 30;  //Nivel 1, velocidade do tronco
    
    glClear(GL_COLOR_BUFFER_BIT);
    Pista();
    Colisao2();
    Onibus();
    Caminhao();
    Caminhao2();
    Sapo();
    
    glutSwapBuffers();  
    }  
    
    if(lado == 2) 
    {
    tempo = 55;  //Nivel 2, velocidade dos carros        
    glClear(GL_COLOR_BUFFER_BIT);
    Pista();
    Colisao();
    Onibus();
    Caminhao();
    Caminhao2();
    Sapo2();
    glutSwapBuffers();
    }
    if(lado == 3) 
    {
    tempo = 45;  //Nivel 2, velocidade do tronco       
    glClear(GL_COLOR_BUFFER_BIT);
    Pista();
    Colisao2();
    Onibus();
    Caminhao();
    Caminhao2();
    Sapo();
        }      
 if(lado == 4) //Final
    {       
    glClear(GL_COLOR_BUFFER_BIT);
    Comentarios1();
    glutSwapBuffers();  
    }  
             
}

//Funcoes para teclado (atribuicoes de teclas especiais)   
void Mover (int key, int x, int y)
  	 {	
     if(key == GLUT_KEY_UP)      { moversapoy += 1; }
	 if(key == GLUT_KEY_DOWN)    { moversapoy -= 1; }
	 if(key == GLUT_KEY_LEFT)    { moversapox -= 1; }
	 if(key == GLUT_KEY_RIGHT)   { moversapox += 1; }

     //Limitando o sapo, para nao sair da tela
	 if (moversapoy < 0)   		 { moversapoy = 0;  } 
	 if (moversapoy > 10)         { moversapoy = 10;  }
     if (moversapox < -13)       { moversapox = -13;}
     if (moversapox > 20)        { moversapox = 20; }
     }          
     
//Funcoes para teclado (atribuicoes de teclas)   
void Teclado ( unsigned char key, int x, int y )
{   
     //Fazer o predio subir e descer com W e S     
     if(key == 119)        { predioy += 1; }
	 if(key == 115)        { predioy -= 1; }
     //Limites minimo e maximo do predio
	 if (predioy < 0)      { predioy = 0;  } 
	 if (predioy > 2)      { predioy = 2;  }
	 //Tela cheia na tecla f
	 if(key == 102)        { glutFullScreen(); }
     //Redesenha o novo valor 
     glutPostRedisplay();
     //Sai ao se precionar a tecla esc
     if(key == 27)  {   exit(0); }
} 

//Funcoes do menu
void MenuJanela(int op)
{
   switch(op) {
            case 0:
                     { glutFullScreen(); }
                     break;
              }
              
    glutPostRedisplay();
} 

//Funcoes do menu      
void MenuSom(int op)
{
   switch(op) {
              case 0:
                     { FSOUND_Close(); }
                     break;
              } 
                
    glutPostRedisplay();
}  

// Gerenciamento do menu principal           
void MenuPrincipal(int op)
{
}
    
//Cria o Menu
void CriaMenu() 
{
    int menu,submenu1,submenu2;

	submenu1 = glutCreateMenu(MenuJanela);
	glutAddMenuEntry("Tela Cheia",0);

    submenu2 = glutCreateMenu(MenuSom);
	glutAddMenuEntry("Desligar o som",0);

    menu = glutCreateMenu(MenuPrincipal);
	glutAddSubMenu("Janela",submenu1);
    glutAddSubMenu("Som",submenu2);
    
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            CriaMenu();
         
    glutPostRedisplay();
}

//Define configuracoes da janela     
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0, 0.0, 0.0, 0.0);
}


// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura) 
		gluOrtho2D (0.0f, 23.0f, 0.0f*altura/largura, 13.0f*altura/largura);
	else 
		gluOrtho2D (0.0f*largura/altura, 23.0f*largura/altura, 0.0f, 13.0f);
}

//Chamada do main
int main(void)
{
//Inicia o som

    FSOUND_SAMPLE *samp1 = 0; //cria um ponteiro para armazenar o som em memória
    if (FSOUND_GetVersion() < FMOD_VERSION) // verificação da versão do fmod caso a versão do FSOUND for menor que a do FMOD retorna uma menssagem de erro
    {
        printf("Error : You are using the wrong DLL version!  You should be using FMOD %.02f\n", FMOD_VERSION);
        return 1;
    }
    //    Seleciona a saída de audio
    FSOUND_SetOutput(FSOUND_OUTPUT_DSOUND);

    //    Seleção do driver
   FSOUND_GetOutput(); // indentifica o tipo de saida
   FSOUND_GetMixer(); // indentifica o mixer
   FSOUND_SetDriver(0); // seta o driver de som que vai ser usado

    //    Inicializando o FMOD
    if (!FSOUND_Init(44100, 32, FSOUND_INIT_GLOBALFOCUS)) // se o valor do FSOUND_Init for 0 execute o tratamento de erro
    {
        printf("Error!\n");
        printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
        return 1;
    }

    // Carrengando o Sample
    // PCM,44,100 Hz, 32 Bit, Mono ou uma mp3 ou outros formatos suportados pelo fmod
    samp1 = FSOUND_Sample_Load(FSOUND_UNMANAGED, "topgear.ogg", FSOUND_NORMAL | FSOUND_HW2D, 0, 0); 
    if (!samp1)
    {
        printf("Error!\n");
        printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
        return 1;
    }

   // Aqui fala qual maneira o sample ira tocar caso falhe excute o tratamento de erro
    if(!FSOUND_Sample_SetMode(samp1, FSOUND_LOOP_NORMAL))// o loop normal toca a musica continuamente ate o programa fechar
   {
   printf("Error!\n");   
    printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
   }
   // Aqui sera tocado o sample ,caso falhe, execute o tratamento de erro
   if(!FSOUND_PlaySound(FSOUND_FREE, samp1))
   {
   printf("Error!\n");   
   printf("%s\n", FMOD_ErrorString(FSOUND_GetError()));
   }
    //Fim do codigo do som \\o  \o/   o//\o/
    //Sleep(10000);  // executa o som durante 10 segundos     (Essa funcao esta desativada no Street Frog)
    printf ("Jogo desenvolvido como Projeto Final para a Disciplina de Computacao Grafica");
    printf ("\nUFRN - CT - DCA");
    printf ("\nPor Claudio Henrique | Paulo Bruno | Thaisa Ramos");
    //printf ("\n");


    //E por fim a chamada para o OpenGL
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB); //Modo para nao exibir rastros na tela
    glutInitWindowSize (890, 550); //Tamanho da janela
    glutInitWindowPosition (50, 50);  //Localizacao inicial da janela
	glutCreateWindow("Ajude o menino a chegar em casa"); //Nome da janela
    glutKeyboardFunc(Teclado); //Chama as funcoes do teclado
    glutSpecialFunc(Mover);  //Chama as funcoes especias do teclado (setas de movimento)
	Inicializa(); 
	iniciaText();
	glutDisplayFunc(Desenha); //Chama o desenho
	glutReshapeFunc(AlteraTamanhoJanela); //Correcao de largura e altura para a janela
    glutTimerFunc(10,movimentar,1);       //Chamada de movimento do carro
    glutTimerFunc(10,movimentacarro,1);   //Chamada de movimento do carro
    glutTimerFunc(10,movimentacarro2,1);  //Chamada de movimento do carro
    glutTimerFunc(10,movermad,1);         //Chamada de movimento da madeira
    glutTimerFunc(10,movermad1,1);        //Chamada de movimento da madeira
    glutTimerFunc(10,movermad2,1);        //Chamada de movimento da madeira
    glutMouseFunc(GerenciaMouse);         //Ativa o botao direito
	glutMainLoop();
	//Final das funcoes do OpenGL
	
    //    limpando a memoria e fechando o fmod (Som)
    FSOUND_Sample_Free(samp1); // limpa a memoria ultilizada pelo ponteiro do sample
    FSOUND_Close();  // encerra a API FMOD

}
