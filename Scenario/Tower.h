//#ifndef TOWER_H
//#define TOWER_H

#include "../gLib.h"
//#include "../Character/Character.cpp"
//#include "../Util/Texture.h"
//#include "../Util/ObjParser.h"

using namespace std;

class Tower{
	private:
		GLuint textureID_d;
        vector< vector<float> > faces_d;
		GLuint textureID_t;
        vector< vector<float> > faces_t;

	public:
    	Tower(){};
    	~Tower(){};

    	// TOWER followed by DIAMOND 
		void setTex( FILE *, FILE * );
		void setObj( FILE *, FILE * );
    	void draw( void );
};
