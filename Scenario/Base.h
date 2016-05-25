#include "../gLib.h"

using namespace std;

class Base: public Character{
	private:
		GLuint textureID;
        vector< vector<float> > faces;
		float r, g, b;

    public:
    /* Constructors and Destructors */
        Base();
        virtual ~Base();

		void setColor(float x, float y, float z){ r=x; g=y; b=z;}
    
    /* Class Methods */
        void draw( void );
		void setTex( FILE * );
		void setObj( FILE */*, FILE * */);
};
