#include "../gLib.h"

using namespace std;

class Scenario{
    private:
        int width;
        int height;
        vector<SPosition> vertices;
        vector<SPosition> normals;
        vector<SPosition> texture;
        

    public:
        /* Constructors and Destructors */
        //Scenario(int, int);
        Scenario( void );
        virtual ~Scenario();
    
        /* Setters */
        void setDimension( int w, int h ) { width = w; height = h; }
    
        /* Class Methods */
        void draw( void );
	GLuint loadBMP_custom(const char * imagepath);
    
    
};
