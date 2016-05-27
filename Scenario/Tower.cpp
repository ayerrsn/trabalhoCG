#include "Tower.h"

void Tower::setTex( FILE *fp ){
	Texture aux(fp);
	textureID_t = aux.getTexID();
}

void Tower::setObj( FILE *fp1, FILE *fp2 ){
	ObjParser aux(fp1);
	faces_t = aux.getFaces();

	ObjParser aux2(fp2);
	faces_d = aux2.getFaces();
}

void Tower::draw( void ){
    int i;

    glDisable(GL_BLEND);
    glPushMatrix();
		//glTranslatef( getPosition().getX(), 1/(0.07) + 1.0*(10.0) , getPosition().getZ() );
    	glTranslatef( 0.0 , 1/(0.07) + 1.0*(45.0) , 0.0 );
		glScalef( 0.05 ,0.07 ,0.03 );
		setBarLifeRotate( -45, 180, 0 );
		getLifeBar().draw();
	glPopMatrix();

	// Drawing Tower Base
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, textureID_t);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    

    glPushMatrix();
		glScalef(8,8,8);
		glColor3f( 1.0f, 1.0f, 1.0f );
		for(i = 0; i < faces_t.size(); i++){
		    glNormal3f(faces_t[i][0], faces_t[i][1], faces_t[i][2]);
		    glBegin(GL_TRIANGLES);
		        glVertex3f( faces_t[i][3],faces_t[i][4], faces_t[i][5]);
		        glTexCoord2f( faces_t[i][6], faces_t[i][7]);
		        glVertex3f( faces_t[i][8],faces_t[i][9], faces_t[i][10]);
		        glTexCoord2f( faces_t[i][11], faces_t[i][12]);
		        glVertex3f( faces_t[i][13],faces_t[i][14], faces_t[i][15]);
		        glTexCoord2f( faces_t[i][16], faces_t[i][17]);
		    glEnd();
		}
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    

	// Drawing Diamond
	if(getCharacterLife() > 0){
		glTranslatef(0,45,0);
		glScalef(12,12,12);
	    glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	    glColor4f( r, g, b, 0.5 );
	    for(i = 0; i < faces_d.size(); i++){
	        glNormal3f(faces_d[i][0]*100, faces_d[i][1]*100, faces_d[i][2]*100);
	        glBegin(GL_TRIANGLES);
	            glVertex3f( faces_d[i][3],faces_d[i][4], faces_d[i][5]);
	            //glTexCoord2f( faces_d[i][6], faces_d[i][7]);
	            glVertex3f( faces_d[i][8],faces_d[i][9], faces_d[i][10]);
	            //glTexCoord2f( faces_d[i][11], faces_d[i][12]);
	            glVertex3f( faces_d[i][13],faces_d[i][14], faces_d[i][15]);
	            //glTexCoord2f( faces_d[i][16], faces_d[i][17]);
	        glEnd();
	    }
		glDisable(GL_BLEND);
	    glPopMatrix();

	}
	
    
}

void Tower::controller(){
    
}



