#include "Base.h"

Base::~Base(){}

Base::Base(){
	r = 0.0;
	g = 0.0;
	b = 1.0;
}

void Base::setTex( FILE *fp ){
	Texture aux(fp);
	textureID = aux.getTexID();
}

void Base::setObj( FILE *fp1/*, FILE *fp2 */){
	ObjParser aux(fp1);
	faces = aux.getFaces();

	//ObjParser aux2(fp2);
	//faces_d = aux2.getFaces();
}


void Base::draw(){
	int i;
	
	glTranslatef(0,20,0);
	glScalef(30,30,30);
    glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f( r, g, b, 0.5 );
    for(i = 0; i < faces.size(); i++){
        glNormal3f(faces[i][0]*50, faces[i][1]*50, faces[i][2]*50);
        glBegin(GL_TRIANGLES);
            glVertex3f( faces[i][3],faces[i][4], faces[i][5]);
            //glTexCoord2f( faces[i][6], faces[i][7]);
            glVertex3f( faces[i][8],faces[i][9], faces[i][10]);
            //glTexCoord2f( faces[i][11], faces[i][12]);
            glVertex3f( faces[i][13],faces[i][14], faces[i][15]);
            //glTexCoord2f( faces[i][16], faces[i][17]);
        glEnd();
    }
	glDisable(GL_BLEND);
    glPopMatrix();
}


