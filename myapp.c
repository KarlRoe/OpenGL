#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef GL_BGR
#define GL_BGR 0x80E0
#endif


///////////    Different Materials  ////////////////

GLfloat redDiffuseMaterial[] = {1.0, 1.0, 1.0};
GLfloat whiteSpecularMaterial[] = {1.0, 1.0, 1.0};
GLfloat greenEmissiveMaterial[] = {0.0, 1.0, 0.0};

// Struct for defing a material //

typedef struct material
{
    GLfloat ambient [ 4 ] ;
    GLfloat diffuse[ 4 ] ;
    GLfloat specular[ 4 ] ;
    GLfloat shininess [1];
} material;

// Brass Material //

material brass =
{
    {0.53 , 0.42 , 0.13 , 1.0 } ,
    {0.78 , 0.57 , 0.11 , 1.0 } ,
    {0.99 , 0.91 , 0.81 , 1.0 } ,
    {27.8}
} ;

// Red plastic material //

material red_plastic =
{
    { 0.1 , 0.1 , 0.1 , 1.0 } ,
    { 0.1 , 0.1 , 0.1 , 1.0 } ,
    { 0.1 , 0.1 , 0.1 , 1.0} ,
    {32.0}
};

// Method for assigning materials to objects //

void materials ( material *m)
{
    glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, m->ambient ) ;
    glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, m->diffuse ) ;
    glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR, m->specular ) ;
    glMaterialfv (GL_FRONT_AND_BACK, GL_SHININESS, m->shininess );
}


///////////////////////////////////////////////////



/////// Different Required Variables    ///////////

static GLfloat theta [ ] = {0.0 , 0.0 , 0.0};
static GLint axis = 2;
GLint xPos = 10;
GLint yPos = 5;
GLint zPos = 5;
GLint xPos2 = 0;
GLint yPos2 = 0;
GLint zPos2 = 0;
int light_on = 1;
int light_on2 = 1;
float angle = -200.0f;
float angle2 = -60.0f;
float deltaAngle = 0.0f;
float alphaAngle = 0.0f;
int xOrigin = -1;
int yOrigin = -1;
float lx = 0;
float ly = 0;
float lz = 0;
int i = 1;
int slender = 350;
int obNum = 0;
int movementX = 0;
int tv_on = 0;
int tv_counter = 0;
int lightning = 0;
int light_counter = 0;
float rint = 0;
float gint = 0;
float bint = 0;
int wardRotate = 0;
int closed = 0;
float disk = 0;
int eject = 0;
int inject = 1;

GLUquadricObj* quadObj;

GLuint texture;

//Specifying light position and direction //

GLfloat light_position[] = { 0, 5, 0, 1.0};
GLfloat light_position2[] = { 3, 4, 2, 1.0};
GLfloat light_position3[] = { 0, 8, 0, 1.0};
GLfloat light_direction[] = { 0,-1,0, 0};

///////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////
// Method Declarations //
/////////////////////////

//Primary room methods //
//-----------------------------------------------

void render_room();
void table();
void chair();
void lamp();
void drawer();
void wardrobe();
void fireplace();
void tv(void);
void window(void);
void bed(void);
void addOns(void);

//------------------------------------------------


//Table Methods //
//------------------------------------------------
void base(void);
void leg1(void);
void leg2(void);
void leg3(void);
void leg4(void);
//------------------------------------------------


//chair Methods //
//------------------------------------------------
void bottom(void);
void back(void);
void chair_leg1(void);
void chair_leg2(void);
void chair_leg3(void);
void chair_leg4(void);
//------------------------------------------------


//Drawer Method//
//------------------------------------------------
void drawer_body();
void drawer_leg1();
void drawer_leg2();
void drawer_leg3();
void drawer_leg4();
void drawer_handles();

//-----------------------------------------------


//Fireplace Method//
//------------------------------------------------
void marble_footing();
void arch();
void marble_top();
void wood_logs();

//-----------------------------------------------


//TV Methods//
//------------------------------------------------

void tv_screen(void);
void tv_base(void);
void tv_leg1(void);
void tv_leg2(void);
void tv_leg3(void);
void tv_leg4(void);
void dvd_player(void);

//------------------------------------------------


//Window methods //
//------------------------------------------------
void windowFrame(void);
void windowFrame1(void);
void windowFrame2(void);
void windowFrame3(void);
void windowFrame4(void);
void windowInner1(void);
void windowInner2(void);

//------------------------------------------------


//Wardrobe Method//
//------------------------------------------------
void wardrobe_body(void);
void wardrobe_handles(void);

//------------------------------------------------


//Bed Method //
//------------------------------------------------

void bed_body(void);
void bed_body2(void);
void bed_head(void);
void bed_leg1(void);
void bed_leg2(void);
void bed_leg3(void);
void bed_leg4(void);

//------------------------------------------------

void painting(void);
void painting2(void);
void carpet(void);
void stranger(void);
void linghtningStr();
GLfloat open = 0;



//-----------------------------------------------

//Room architecture//
//------------------------------------------------
void wall(void);
void wall2(void);
void wall3(void);
void wall4(void);
void floor(void);
//------------------------------------------------

void move(int);

// Declaration of Treenode struct //
//------------------------------------------------

typedef struct treenode
{
    int x;
    int y;
    int z;
    int ref;
    GLfloat m[16];
    void (*f) ();
    struct treenode *sibling;
    struct treenode *child;
}treenode;

//------------------------------------------------


//Treenode declarations//
//------------------------------------------------------

treenode room_node;
treenode table_node;
treenode chair_node;
treenode lamp_node;
treenode wall_node;
treenode wall2_node;
treenode wall3_node;
treenode wall4_node;
treenode cubic_wall_node;
treenode floor_node;
treenode body_node;
treenode leg1_node;
treenode leg2_node;
treenode leg3_node;
treenode leg4_node;
treenode bottom_node;
treenode back_node;
treenode chair_leg1_node;
treenode chair_leg2_node;
treenode chair_leg3_node;
treenode chair_leg4_node;
treenode window_node_full;
treenode window_node;
treenode window_node1;
treenode window_node2;
treenode window_node3;
treenode window_node4;
treenode window_node5;
treenode window_node6;
treenode drawer_node;
treenode drawer_body_node;
treenode drawer_leg1_node;
treenode drawer_leg2_node;
treenode drawer_leg3_node;
treenode drawer_leg4_node;
treenode drawer_handles_node;
treenode wardrobe_node;
treenode wardrobe_body_node;
treenode wardrobe_handles_node;
treenode tv_node;
treenode tv_screen_node;
treenode tv_base_node;
treenode tv_leg1_node;
treenode tv_leg2_node;
treenode tv_leg3_node;
treenode tv_leg4_node;
treenode fireplace_node;
treenode arch_node;
treenode marble_footing_node;
treenode marble_top_node;
treenode logs_node;
treenode bed_node;
treenode bed_body_node;
treenode bed_body2_node;
treenode bed_leg1_node;
treenode bed_leg2_node;
treenode bed_leg3_node;
treenode bed_leg4_node;
treenode bed_head_node;
treenode addOns_node;
treenode painting1_node;
treenode painting2_node;
treenode carpet_node;
treenode stranger_node;
treenode dvd_player_node;

//------------------------------------------------------






////////////////////////////////////////////////////////////////////////////////////////////
//                          Method for loading & Freeing Textures from images                       //
////////////////////////////////////////////////////////////////////////////////////////////

GLuint LoadTexture( const char * filename, int width, int height )
{
    GLuint texture;
    unsigned char * data;
    FILE * file;

    //The following code will read in our RAW file
    file = fopen( filename, "rb" );
    if ( file == NULL ) return 0;
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );

    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE ); //set texture environment parameters

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );


    //to the edge of our shape.
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );

    //Generate the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    free( data ); //free the texture
    return texture; //return whether it was successfull
}


void FreeTexture( GLuint texture )
{
  glDeleteTextures( 1, &texture );
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////




static void
drawBox(GLfloat size, GLenum type)
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

  for (i = 5; i >= 0; i--) {
    glBegin(type);
    glNormal3fv(&n[i][0]);
    glColor3f(1,1,1);
    glTexCoord2d(0, 0); glVertex3fv(&v[faces[i][0]][0]);
    glTexCoord2d(1, 0); glVertex3fv(&v[faces[i][1]][0]);
    glTexCoord2d(1, 1); glVertex3fv(&v[faces[i][2]][0]);
    glTexCoord2d(0,1); glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

static void
drawBox2(GLfloat size, GLenum type)
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

  for (i = 5; i >= 0; i--) {
    glBegin(type);
    glNormal3fv(&n[i][0]);
    glColor3f(1,1,1);
    glTexCoord2d(0, 0); glVertex3fv(&v[faces[i][0]][0]);
    glTexCoord2d(10, 0); glVertex3fv(&v[faces[i][1]][0]);
    glTexCoord2d(10, 10); glVertex3fv(&v[faces[i][2]][0]);
    glTexCoord2d(0,10); glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void drawTriangle()
{

    glBegin(GL_TRIANGLES);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0, 1, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);
    glEnd();
}


void APIENTRY glutSolidCube(GLdouble size)
{
  drawBox(size, GL_QUADS);
}


void APIENTRY glutSolidCube2(GLdouble size)
{
  drawBox2(size, GL_QUADS);
}

///////////////////////////////////////////////////////////////////////////


// Initialise Light //
//-------------------------------------------------------------------------

void light_init(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT2);
  //  glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);

    //Setting the colour of each light //

    GLfloat light_colour[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat light_colour2[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light_colour3[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light_colour4[] = {rint, gint, bint, 1.0};
    GLfloat bred[] = {0.0, 0.1, 0.9, 10};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_colour);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_colour);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_colour2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_colour2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_colour3);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_colour3);
    glLightfv(GL_LIGHT4, GL_POSITION, light_position);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light_colour4);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light_colour4);


    //Specifying LIGHT1 & LIGHT2 as spotlights//
    glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 80);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction);
 //   glLightf (GL_LIGHT2, GL_SPOT_CUTOFF, 20);
 //   glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_direction);
}


// Initialise different opengl settings //
//-----------------------------------------------------------

void init(void)
{
   GLfloat material_diffuse[] = { 1.0f, 0, 0, 1.0f };
   GLfloat ambientColour[] = {0.1f, 0.1f, 0.1f, 1.0f};
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat ambient[] = { 0.5, 0.5, 0.5, 1.0 };
   GLfloat mat_shininess[] = { 90 };
   glEnable(GL_DOUBLEBUFFER);
   glEnable(GL_DEPTH_TEST);
  // glEnable(GL_LIGHT2);
  // glEnable(GL_CULL_FACE);
  // glCullFace(GL_BACK);
   quadObj = gluNewQuadric();

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   light_init();


   // Setting up each tree node in the room //

   room_setup();
   table_setup();
   chair_setup();
   window_setup();
   drawer_setup();
   wardrobe_setup();
   tv_setup();
   fireplace_setup();
   bed_setup();
}

//-----------------------------------------------------


//Setting up each node in the room tree //
//-----------------------------------------------------

void room_setup()
{

    room_node.x = 0;
    room_node.y = 0;
    room_node.z = 0;
    room_node.ref = 0;
    room_node.f = render_room;
    room_node.sibling = NULL;
    room_node.child = &floor_node;

    floor_node.x = 0;
    floor_node.y = 0;
    floor_node.z = 0;
    floor_node.ref = 1;
    floor_node.f = floor;
    floor_node.sibling = &wall_node;
    floor_node.child = &table_node;

    wall_node.x = 0;
    wall_node.y = 0;
    wall_node.z = 0;
    wall_node.ref = 2;
    wall_node.f = wall;
    wall_node.sibling = &wall2_node;
    wall_node.child = &window_node_full;


    wall2_node.x = 0;
    wall2_node.y = 0;
    wall2_node.z = 0;
    wall2_node.ref = 3;
    wall2_node.f = wall2;
    wall2_node.sibling = &wall3_node;
    wall2_node.child = NULL;


    wall3_node.x = 0;
    wall3_node.y = 0;
    wall3_node.z = 0;
    wall3_node.ref = 4;
    wall3_node.f = wall3;
    wall3_node.sibling = &wall4_node;
    wall3_node.child = NULL;


    wall4_node.x = 0;
    wall4_node.y = 0;
    wall4_node.z = 0;
    wall4_node.ref = 5;
    wall4_node.f = wall4;
    wall4_node.sibling = &stranger_node;
    wall4_node.child = &fireplace_node;

    table_node.x = 0;
    table_node.y = 0;
    table_node.z = 0;
    table_node.ref = 6;
    table_node.f = table;
    table_node.sibling = &chair_node;
    table_node.child = &lamp_node;


    chair_node.x = 0;
    chair_node.y = 0;
    chair_node.z = 0;
    chair_node.ref = 7;
    chair_node.f = chair;
    chair_node.sibling = &drawer_node;
    chair_node.child = NULL;


    lamp_node.x = 0;
    lamp_node.y = 0;
    lamp_node.z = 0;
    lamp_node.ref = 8;
    lamp_node.f = lamp;
    lamp_node.sibling = NULL;
    lamp_node.child = NULL;


    drawer_node.x = 0;
    drawer_node.y = 0;
    drawer_node.z = 0;
    drawer_node.ref = 9;
    drawer_node.f = drawer;
    drawer_node.sibling = &wardrobe_node;
    drawer_node.child = NULL;


    wardrobe_node.x = 0;
    wardrobe_node.y = 0;
    wardrobe_node.z = 0;
    wardrobe_node.ref = 10;
    wardrobe_node.f = wardrobe;
    wardrobe_node.sibling = &tv_node;
    wardrobe_node.child = NULL;


    tv_node.x = 0;
    tv_node.y = 0;
    tv_node.z = 0;
    tv_node.ref = 11;
    tv_node.f = tv;
    tv_node.sibling = &bed_node;
    tv_node.child = NULL;

    bed_node.x = 0;
    bed_node.y = 0;
    bed_node.z = 0;
    bed_node.ref = 13;
    bed_node.f = bed;
    bed_node.sibling = &carpet_node;
    bed_node.child = NULL;


    fireplace_node.x = 0;
    fireplace_node.y = 0;
    fireplace_node.z = 0;
    fireplace_node.ref = 12;
    fireplace_node.f = fireplace;
    fireplace_node.sibling = &painting2_node;
    fireplace_node.child = NULL;


    window_node_full.x = 0;
    window_node_full.y = 0;
    window_node_full.z = 0;
    window_node_full.ref = 14;
    window_node_full.f = window;
    window_node_full.sibling = &painting1_node;
    window_node_full.child = NULL;


    painting1_node.x = 0;
    painting1_node.y = 0;
    painting1_node.z = 0;
    painting1_node.ref = 15;
    painting1_node.f = painting;
    painting1_node.sibling = NULL;
    painting1_node.child = NULL;

    painting2_node.x = 0;
    painting2_node.y = 0;
    painting2_node.z = 0;
    painting2_node.ref = 16;
    painting2_node.f = painting2;
    painting2_node.sibling = NULL;
    painting2_node.child = NULL;

    carpet_node.x = 0;
    carpet_node.y = 0;
    carpet_node.z = 0;
    carpet_node.ref = 17;
    carpet_node.f = carpet;
    carpet_node.sibling = NULL;
    carpet_node.child = NULL;

    stranger_node.f = stranger;
    stranger_node.sibling = NULL;
    stranger_node.child = NULL;
}

//-------------------------------------------------


//Setting up each node in the wardrobe tree
//-------------------------------------------------

void wardrobe_setup()
{
    wardrobe_body_node.f = wardrobe_body;
    wardrobe_body_node.sibling = &wardrobe_handles_node;
    wardrobe_body_node.child = NULL;

    wardrobe_handles_node.f = wardrobe_handles;
    wardrobe_handles_node.sibling = NULL;
    wardrobe_handles_node.child = NULL;
}

//--------------------------------------------------


//Setting up each node in the tv tree//
//--------------------------------------------------

void tv_setup()
{
    tv_screen_node.f = tv_screen;
    tv_screen_node.sibling = &tv_base_node;
    tv_screen_node.child = NULL;

    tv_base_node.f = tv_base;
    tv_base_node.sibling = &tv_leg1_node;
    tv_base_node.child = &dvd_player_node;

    dvd_player_node.f = dvd_player;
    dvd_player_node.sibling = NULL;
    dvd_player_node.child = NULL;

    tv_leg1_node.f = tv_leg1;
    tv_leg1_node.sibling = &tv_leg2_node;
    tv_leg1_node.child = NULL;

    tv_leg2_node.f = tv_leg2;
    tv_leg2_node.sibling = &tv_leg3_node;
    tv_leg2_node.child = NULL;

    tv_leg3_node.f = tv_leg3;
    tv_leg3_node.sibling = &tv_leg4_node;
    tv_leg3_node.child = NULL;

    tv_leg4_node.f = tv_leg4;
    tv_leg4_node.sibling = NULL;
    tv_leg4_node.child = NULL;
}

//------------------------------------------------


//Setting up each node in the fireplace tree //
//------------------------------------------------

void fireplace_setup()
{
    marble_footing_node.f = marble_footing;
    marble_footing_node.sibling = &marble_top_node;
    marble_footing_node.child = NULL;

    marble_top_node.f = marble_top;
    marble_top_node.sibling = &arch_node;
    marble_top_node.child = NULL;

    arch_node.f = arch;
    arch_node.sibling = &logs_node;
    arch_node.child = NULL;

    logs_node.f = wood_logs;
    logs_node.sibling = NULL;
    logs_node.child = NULL;

}

//-------------------------------------------------


//Setting up each node in the window tree
//-------------------------------------------------

void window_setup()
{
    window_node.f = windowFrame;
    window_node.sibling = NULL;
    window_node.child = &window_node1;

    window_node1.f = windowFrame1;
    window_node1.sibling = &window_node2;
    window_node1.child = NULL;

    window_node2.f = windowFrame2;
    window_node2.sibling = &window_node3;
    window_node2.child = NULL;

    window_node3.f = windowFrame3;
    window_node3.sibling = &window_node4;
    window_node3.child = NULL;

    window_node4.f = windowFrame4;
    window_node4.sibling = &window_node5;
    window_node4.child = NULL;

    window_node5.f = windowInner1;
    window_node5.sibling = &window_node6;
    window_node5.child = NULL;

    window_node6.f = windowInner2;
    window_node6.sibling = NULL;
    window_node6.child = NULL;

}

//-------------------------------------------------


//Setting up each node in the drawer tree
//-------------------------------------------------

void drawer_setup()
{
    drawer_body_node.f = drawer_body;
    drawer_body_node.sibling = &drawer_handles_node;
    drawer_body_node.child = &drawer_leg1_node;

    drawer_leg1_node.f = drawer_leg1;
    drawer_leg1_node.sibling = &drawer_leg2_node;
    drawer_leg1_node.child = NULL;

    drawer_leg2_node.f = drawer_leg2;
    drawer_leg2_node.sibling = &drawer_leg3_node;
    drawer_leg2_node.child = NULL;

    drawer_leg3_node.f = drawer_leg3;
    drawer_leg3_node.sibling = &drawer_leg4_node;
    drawer_leg3_node.child = NULL;

    drawer_leg4_node.f = drawer_leg4;
    drawer_leg4_node.sibling = NULL;
    drawer_leg4_node.child = NULL;

    drawer_handles_node.f = drawer_handles;
    drawer_handles_node.sibling = NULL;
    drawer_handles_node.child = NULL;

}

//-----------------------------------------------------


//Setting up each node in the table tree //
//-----------------------------------------------------

void table_setup()
{
    body_node.f = base;
    body_node.sibling = NULL;
    body_node.child = &leg1_node;

    leg1_node.f = leg1;
    leg1_node.sibling = &leg2_node;
    leg1_node.child = NULL;

    leg2_node.f = leg2;
    leg2_node.sibling = &leg3_node;
    leg2_node.child = NULL;

    leg3_node.f = leg3;
    leg3_node.sibling = &leg4_node;
    leg3_node.child = NULL;

    leg4_node.f = leg4;
    leg4_node.sibling = NULL;
    leg4_node.child = NULL;
}

//---------------------------------------------------------


// Setting up each node in the chair tree //
//---------------------------------------------------------
void chair_setup()
{
    bottom_node.f = bottom;
    bottom_node.sibling = NULL;
    bottom_node.child = &back_node;

    back_node.f = back;
    back_node.sibling = &chair_leg1_node;
    back_node.child = NULL;

    chair_leg1_node.f = chair_leg1;
    chair_leg1_node.sibling = &chair_leg2_node;
    chair_leg1_node.child = NULL;

    chair_leg2_node.f = chair_leg2;
    chair_leg2_node.sibling = &chair_leg3_node;
    chair_leg2_node.child = NULL;

    chair_leg3_node.f = chair_leg3;
    chair_leg3_node.sibling = &chair_leg4_node;
    chair_leg3_node.child = NULL;

    chair_leg4_node.f = chair_leg4;
    chair_leg4_node.sibling = NULL;
    chair_leg4_node.child = NULL;
}

//------------------------------------------------------


//Setting up each node in the room tree //
//------------------------------------------------------

void bed_setup()
{
    bed_body_node.f = bed_body;
    bed_body_node.sibling = NULL;
    bed_body_node.child = &bed_body2_node;

    bed_body2_node.f = bed_body2;
    bed_body2_node.sibling = &bed_head_node;
    bed_body2_node.child = NULL;

    bed_head_node.f = bed_head;
    bed_head_node.sibling = &bed_leg1_node;
    bed_head_node.child = NULL;

    bed_leg1_node.f = bed_leg1;
    bed_leg1_node.sibling = &bed_leg2_node;
    bed_leg1_node.child = NULL;

    bed_leg2_node.f = bed_leg2;
    bed_leg2_node.sibling = &bed_leg3_node;
    bed_leg2_node.child = NULL;

    bed_leg3_node.f = bed_leg3;
    bed_leg3_node.sibling = &bed_leg4_node;
    bed_leg3_node.child = NULL;

    bed_leg4_node.f = bed_leg4;
    bed_leg4_node.sibling = NULL;
    bed_leg4_node.child = NULL;
}


//-------------------------------------------------------------

// Tree Traversal method //

void traverse(treenode *root)
{
    if(root==NULL)
        return;
    glPushMatrix();
    //glMultMatrix(root−>m);
    glTranslatef(root->x, root->y, root->z);
    root->f();
    if(root->child != NULL)
        traverse(root->child);
    glPopMatrix();
    if(root->sibling!=NULL)
        traverse(root->sibling);
}

void movTraverse(treenode *root, int dir)
{
    if(root==NULL)
        return;

    if(root->ref == obNum)
        movement(root, dir);
    if(root->child != NULL)
        movTraverse(root->child, dir);
    if(root->sibling!=NULL)
        movTraverse(root->sibling, dir);
}

void movement(treenode *root, int dir)
{
    if(dir == 1)
    {
        root->x++;
    }

    else if(dir == 2)
    {
        root->x--;
    }

    else if(dir == 3)
    {
        root->y++;
    }

    else if(dir == 4)
    {
        root->y--;
    }

    else if(dir == 5)
    {
        root->z++;
    }

    else if(dir == 6)
    {
        root->z--;
    }

    glutPostRedisplay();
}


// Traverses window treenode and creates window object //

void window()
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 14 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images.bmp",256, 256);
    traverse(&window_node);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
}

//--------------------------------------------------------


// Traverses table treenode and creates table object //

void table()
{
    glPushMatrix();
    glLoadName(1);
    glEnable(GL_TEXTURE_2D);
    if(obNum == 6 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images.bmp",256, 256);
    traverse(&body_node);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

//---------------------------------------------------------

// Traverses chair treenode and creates chair object //

void chair()
{
    glLoadName(2);
    glEnable(GL_TEXTURE_2D);
    if(obNum == 7 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    traverse(&bottom_node);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);

}

//---------------------------------------------------------


//Creates a lamp object //
//---------------------------------------------------------
void lamp(void)
{
    glTranslatef(3,4,2);
    glRotatef (270 ,1.0 , 0,0);

    glEnable(GL_TEXTURE_2D);
    if(obNum == 8 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "cream.bmp",128, 128);
    gluCylinder(quadObj, 1, 0.3, 1.3, 21, 50 );
    glTranslatef(0,0,-1);
    gluCylinder(quadObj, 0.1, 0.1, 2.2, 21, 50 );
    gluCylinder(quadObj, 0.5, 0.5, 0.2 , 21, 50 );
    glTranslatef(0,0,0.2);
    gluDisk(quadObj,0,0.5 ,20,10);
    glDisable(GL_TEXTURE_2D);

   // glDisable(GL_COLOR_MATERIAL);
}

//Traverses tv tree to create tv object //
//-----------------------------------------------

void tv(void)
{
    glTranslatef(6 ,6,-13.5);
    glScalef(7, 4, 0.3);
    traverse(&tv_screen_node);

}

//-----------------------------------------------


//Traverses fireplace tree to create fireplace object //
//-----------------------------------------------
void fireplace(void)
{
  //  glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(7,1,14);
    traverse(&marble_footing_node);
    glDisable(GL_TEXTURE_2D);
}


//Traverses drawer tree to create drawer object //
//-----------------------------------------------
void drawer(void)
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 9 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    traverse(&drawer_body_node);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
}

//-----------------------------------------------


//Traverses drawer tree to create drawer object //
//-----------------------------------------------
void wardrobe(void)
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 10 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    traverse(&wardrobe_body_node);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
}

//------------------------------------------------


//Traverses bed tree to create bed object //
//------------------------------------------------

void bed(void)
{
    glEnable(GL_TEXTURE_2D);
    traverse(&bed_body_node);
    glDisable(GL_TEXTURE_2D);
}

//-------------------------------------------------


void stranger()
{
    glEnable(GL_TEXTURE_2D);
    texture = LoadTexture( "testing.bmp",256, 256);
    glScalef(0.3,8,8);
    glTranslatef(-slender,0.5,1);
    glRotatef(180,1,1,0);
    glutSolidCube (2.0);
    if(slender > 50 )
       slender -= 5;
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
}


void carpet()
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 17 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "carpet.bmp",256, 256);
    glScalef(6,1,10 );
    glTranslatef(0.7,0,0);
    glutSolidCube(1);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
}

void painting()
{

    glEnable(GL_TEXTURE_2D);
    if(obNum == 15 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "Mona.bmp",512, 512);
    glScalef(0.2,4,4 );
    glTranslatef(-48,1.5,-2);
    glRotatef(180,0,1,0);
    glutSolidCube(1);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);

}

void painting2()
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 16 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "painting2.bmp",512, 512);
    glTranslatef(7,8,14);
    glScalef(5,3,0.3 );
    glRotatef(270,0,0,1);
    glutSolidCube(1);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
}




//Rotates the enire scene
void render_room()
{
    lightningStr();
   // gluLookAt( xPos, yPos, zPos, xPos2,  yPos2, zPos2, 0, 1,  0 );
    glRotatef ( theta [0] , 1.0 , 0.0 , 0.0);                       //how the cube rotates
    glRotatef ( theta [1] , 0.0 , 1.0 , 0.0);
    glRotatef ( theta [2] , 0.0 , 0.0 , 1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position3);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_direction);
    glLoadIdentity();
    gluLookAt( xPos, yPos, zPos, xPos2 -lx,  yPos2 - ly, zPos2 + lz, 0, 1,  0 );


    GLfloat light_colour4[] = {rint, gint, bint, 1.0};
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light_colour4);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light_colour4);


    traverse(&room_node);
    glutSwapBuffers();

}


void lightningStr()
{
    if(lightning)
        glDisable(GL_LIGHT0);

    if(light_counter >= 10)
    {
        light_counter++;
        rint -= 0.02;
        gint -= 0.02;
        bint -= 0.02;
        if(closed == 1)
        {
            wardRotate += 2;
            open += 0.03;
        }

        else
        {
            wardRotate -= 2;
            open -= 0.03;
        }

        if(bint <  0.05)
        {
            lightning = 0;
            light_counter = 0;
        }
        glutPostRedisplay();

    }

    if(lightning && light_counter < 10)
    {
        rint = 1.5;
        gint = 1.5;
        bint = 1.5;
        light_counter++;
        glutPostRedisplay();

    }
}

////////////////////////////////////////////////////
//                  Wardrobe methods              //
////////////////////////////////////////////////////

//--------------------------------------------------

void wardrobe_body(void)
{

    glTranslatef(-9,4.5,10);
    //glRotatef(50,0,1,0);
    glScalef(1, 4, 2.5);
   // glTranslatef(-9,1,4.5);
    glutSolidCube (2.0);

    if(obNum == 10 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "phantom.bmp",512, 512);

    glPushMatrix();
    glTranslatef(1.2,0,-0.5);
    glScalef(0.1, 1, 1);
    glTranslatef(-1,0, 0.5);
    glutSolidCube (2.0);
    glPopMatrix();
    FreeTexture(texture);

    glPushMatrix();
    glTranslatef(1.2,0,-0.5);
    glRotatef(wardRotate,0,1,0);
    if(obNum == 10 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    glScalef(0.1, 1, 0.5);
    glTranslatef(0,0, open);
    glutSolidCube (2.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1.2,0,0.5);
    glRotatef(-wardRotate,0,1,0);
    glScalef(0.1, 1, 0.5);
    glTranslatef(0,0, -open);
    glutSolidCube (2.0);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    FreeTexture(texture);
}

void wardrobe_handles(void)
{
    glTranslatef(-7.8, 6, 9.6);
    glutSolidSphere(0.15, 10, 10);
    glTranslatef(0, 0, 0.8);
    glutSolidSphere(0.15, 10, 10);
}

//---------------------------------------------------


////////////////////////////////////////////////////
//                  Fireplace methods              //
////////////////////////////////////////////////////

//--------------------------------------------------

void marble_footing(void)
{
    if(obNum == 12 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images10.bmp",256, 256);
    glScalef(7,1.5,4);
    glutSolidCube (1.0);
    glScalef(0.5,2,0.8);
    glTranslatef(0,0.7,0.6);
    glutSolidCube (1.0);
    FreeTexture(texture);
}

void marble_top(void)
{
    if(obNum == 12 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images10.bmp",256, 256);
    glScalef(1.4,9,0.8);
    glTranslatef(1.6,0,0);
    glutSolidCube (1.0);
    glTranslatef(-3.2,0,0);
    glutSolidCube (1.0);
    glScalef(2.2,0.2,1);
    glTranslatef(0.72,2,0);
    glutSolidCube (1.0);
    FreeTexture(texture);
}

void arch(void)
{

    if(obNum == 12 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images.bmp",256, 256);
    glScalef(0.5,9,1);
    glTranslatef(6.4,0,-0.2);
    glutSolidCube (1.0);

    glTranslatef(-12.8,0,0);
    glutSolidCube (1.0);

    glScalef(13.8,0.05,1);
    glTranslatef(0.46,10.5,0);
    glutSolidCube (1.0);

}

void wood_logs(void)
{
  //  texture = LoadTexture( "images.bmp",256, 256);
    glTranslatef(-0.8,1.4,-0.5);
    glRotatef (90 ,0 , 1,0);
    gluCylinder(quadObj, 0.3, 0.3, 2 , 21, 50 );
    glTranslatef(-0.3,-0.3,0);
    gluCylinder(quadObj, 0.3, 0.3, 2 , 21, 50 );
    glTranslatef(0.8,0,0);
    gluCylinder(quadObj, 0.3, 0.3, 2 , 21, 50 );
    FreeTexture(texture);
}

//-------------------------------------------------


////////////////////////////////////////////////
//               TV methods                   //
////////////////////////////////////////////////

void tv_screen(void)
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 11 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "black.bmp",128, 128);
    glColor4f(200,0,0,1);
    glutSolidCube2 (1.0);
    glTranslatef(0 ,-0.6,0);
    glScalef(0.3, 0.3, 1);
    drawTriangle();

    glTranslatef(0 ,2,0.1);
    glScalef(3, 3, 1);
    if(tv_on)
    {
        if(obNum == 11 || obNum == 0)
            texture = LoadTexture( "blue.bmp",128, 128);
        else
        {
            if(tv_counter <= 50)
            {
                texture = LoadTexture( "nos.bmp",512, 512);
                tv_counter++;
            }
            if(tv_counter > 50)
            {
                texture = LoadTexture( "nos2.bmp",512, 512);
                tv_counter++;
            }

            if(tv_counter > 100)
            {
                tv_counter = 0;
            }
        }
    }
    glutSolidCube (1.0);
    glDisable(GL_TEXTURE_2D);

    FreeTexture(texture);
}

void tv_base(void)
{

    glEnable(GL_TEXTURE_2D);
    if(obNum == 11 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    glTranslatef(0 ,-0.63, 0);
    glScalef(1.8, 0.05, 7);
    glutSolidCube2 (1.0);

    glTranslatef(0 ,-7, 0);
    glutSolidCube2 (1.0);
    glDisable(GL_TEXTURE_2D);
    FreeTexture(texture);
}

void tv_leg1(void)
{

    glTranslatef(0.87 ,-1.4, 2.6);
    glScalef(0.2, 0.05, 7);
    glRotatef (270 ,1.0 , 0,0);
    gluCylinder(quadObj, 0.1, 0.1, 15, 21, 50 );



}

void tv_leg2(void)
{
    glTranslatef(-0.87 ,-1.4, 2.6);
    glScalef(0.2, 0.05, 7);
    glRotatef (270 ,1.0 , 0,0);
    gluCylinder(quadObj, 0.1, 0.1, 15, 21, 50 );


}

void tv_leg3(void)
{
    glTranslatef(0.87 ,-1.4, -2.4);
    glScalef(0.2, 0.05, 7);
    glRotatef (270 ,1.0 , 0,0);
    gluCylinder(quadObj, 0.1, 0.1, 15, 21, 50 );
}
void tv_leg4(void)
{
    glTranslatef(-0.87 ,-1.4, -2.4);
    glScalef(0.2, 0.05, 7);
    glRotatef (270 ,1.0 , 0,0);
    gluCylinder(quadObj, 0.1, 0.1, 15, 21, 50 );
}

void dvd_player(void)
{
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    if(obNum == 11 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "white.bmp",128, 128);
    glTranslatef(0.2 ,2, 0);
    glScalef(0.2,2,1);
    glutSolidCube (1.0);
    FreeTexture(texture);


    if(obNum == 11 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "gray.bmp",128, 128);
    glTranslatef(-2 ,0, 0);
    glutSolidCube (1.1);
    FreeTexture(texture);

    glPopMatrix();

    glTranslatef(0.35 ,9.5, 0);
    glScalef(0.012,5,0.6);
    glutSolidCube (1.0);
    if(obNum == 11 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "gray.bmp",128, 128);
    glTranslatef(0 ,-0.4, 0.05);
    glScalef(1.3,0.4,1);
    glutSolidCube (1.0);
    FreeTexture(texture);

    glTranslatef(2 ,0, 0);
    glScalef(1,0.7,0.7);
    if(obNum == 11 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "white.bmp",128, 128);
    glutSolidCube (1.0);
    glTranslatef(0 ,0.5, -0.2);
    glScalef(0.15,0.2,0.15);
    glutSolidCube (1.0);
    glScalef(3,1,0.3);
    glutSolidCube (1.0);
    FreeTexture(texture);

    glTranslatef(-4.3,9,17.5);
    glPushMatrix();
    glScalef(0.3,6,3);
    if(obNum == 11 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "blue.bmp",128, 128);
    glutSolidCube (1.0);
     glPopMatrix();
     glTranslatef(0,0,-2);
     if(eject && disk < 7)
     {
        disk++;
        glutPostRedisplay();

     }

    else if(inject && disk > -1)
     {
        disk--;
        glutPostRedisplay();

     }
    glTranslatef(0,0,disk);
    glRotatef(90, 0, 1, 0);
    gluCylinder(quadObj, 4, 0.5, 0.1, 51, 100 );
    FreeTexture(texture);

    glDisable(GL_TEXTURE_2D);
}



////////////////////////////////////////////////
//               Window methods               //
////////////////////////////////////////////////
//-----------------------------------------------------------------

void windowFrame(void)
{
    glTranslatef(-9.6,9,5);
    //glutSwapBuffers ();
   // glFlush ();
}

void windowFrame1(void)
{
    glScalef(0.2,0.2,4);
    glutSolidCube (1.0);
}

void windowFrame2(void)
{
    glTranslatef(0,-3.5,0);
    glScalef(0.2,0.2,4);
    glutSolidCube (1.0);
}

void windowFrame3(void)
{
    glTranslatef(0,-1.8,-1.9);
    glScalef(0.2,3.5,0.2);
    glutSolidCube (1.0);
}

void windowFrame4(void)
{
    glTranslatef(0,-1.8,1.9);
    glScalef(0.2,3.5,0.2);
    glutSolidCube (1.0);
}

void windowInner1(void)
{
    glTranslatef(0,-1.8,0);
    glScalef(0.2,3.5,0.2);
    glutSolidCube (1.0);
}

void windowInner2(void)
{
    glTranslatef(0,-1.75,0);
    glScalef(0.2,0.2,4);
    glutSolidCube (1.0);
}


//-----------------------------------------------------------------




////////////////////////////////////////////////
//               Table methods                //
////////////////////////////////////////////////
//-----------------------------------------------------------------

void base(void)
{
    glTranslatef(2,3,0);
    glScalef(4, 0.2, 6);
    glutSolidCube (1.0);
    glScalef(0.05, 15, 0.04);
   // glutSwapBuffers ();
  //  glFlush ();
}

void leg1(void)
{
    glTranslatef(9, -0.49, 12);
    glutSolidCube (1.0);
}

void leg2(void)
{
    glTranslatef(9, -0.49, -12);
    glutSolidCube (1.0);
}

void leg3(void)
{
    glTranslatef(-8.85, -0.49, 12);
    glutSolidCube (1.0);
}

void leg4(void)
{
    glTranslatef(-8.85, -0.49, -12);
    glutSolidCube (1.0);
}

//---------------------------------------------------------------------





////////////////////////////////////////////////
//               Table methods                //
////////////////////////////////////////////////

//---------------------------------------------------------------------

void drawer_body(void)
{
    glTranslatef(-5 ,2.8, -13);
    glScalef(6, 4 , 2.8);
    glutSolidCube (1.0);
    glScalef(0.1, 0.55 , 0.1);
  //  glutSwapBuffers ();
  //  glFlush ();
}

void drawer_leg1(void)
{
    glTranslatef(-3, -0.55, -3);
    glutSolidCube (1.0);
}

void drawer_leg2(void)
{
    glTranslatef(4.3, -0.55, -3);
    glutSolidCube (1.0);
}

void drawer_leg3(void)
{
    glTranslatef(4.3, -0.55, 4);
    glutSolidCube (1.0);
}

void drawer_leg4(void)
{
    glTranslatef(-3, -0.55, 4);
    glutSolidCube (1.0);
}

void drawer_handles(void)
{
    glTranslatef(-5, 4, -11.5);
    glutSolidSphere(0.2, 10, 10);
    glTranslatef(0, -2, 0);
    glutSolidSphere(0.2, 10, 10);
}






//---------------------------------------------------------------------


////////////////////////////////////////////////
//               Chair methods                //
////////////////////////////////////////////////

//---------------------------------------------------------------------

void bottom(void)
{
    glTranslatef(-0.5 ,2.3, 0);
    glScalef(2.8, 0.2, 2.8);
    glutSolidCube (1.0);
    glScalef(0.1, 10, 0.1);
   // glutSwapBuffers ();
   // glFlush ();
}

void back(void)
{
    glScalef(0.5, 1.4, 10);
    glTranslatef(-10, 0.5 , 0);
    glutSolidCube (1.0);
 //   glutSwapBuffers ();
 //   glFlush ();
}

void chair_leg1(void)
{
    glTranslatef(4.3, -0.55, 4);
    glutSolidCube (1.0);
}

void chair_leg2(void)
{
    glTranslatef(-5, -0.55, 4);
    glutSolidCube (1.0);
}

void chair_leg3(void)
{
    glTranslatef(4.3, -0.55, -4);
    glutSolidCube (1.0);
}

void chair_leg4(void)
{
    glTranslatef(-5, -0.55, -4);
    glutSolidCube (1.0);
}

//---------------------------------------------------------------------







////////////////////////////////////////////////
//               Bed methods                  //
////////////////////////////////////////////////
//---------------------------------------------------------------------


void bed_body(void)
{
   // glEnable(GL_COLOR_MATERIAL);
    if(obNum == 13 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "e.bmp",256, 256);
    glScalef(2.5,0.7,5);
    glTranslatef(6.5,4,-1.5);
    glutSolidCube(2);
    FreeTexture(texture);

}

void bed_body2(void)
{
    if(obNum == 13 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    glTranslatef(0,-1.2,0);
    glScalef(1,1,1);
    glutSolidCube(2.1);
    FreeTexture(texture);

}

void bed_head(void)
{
    if(obNum == 13 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    glScalef(1,1.6,0.05);
    glTranslatef(0,1,-19);
    glutSolidCube(2.1);
    FreeTexture(texture);
}

void bed_leg1(void)
{
    if(obNum == 13 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images3.bmp",256, 256);
    glScalef(0.08,1.5,0.05);
    glTranslatef(-11.3,-1,-19);
    glutSolidCube(2);
}

void bed_leg2(void)
{
    glScalef(0.08,1.5,0.05);
    glTranslatef(11.3,-1,-19);
    glutSolidCube(2);
}

void bed_leg3(void)
{
    glScalef(0.08,1.5,0.05);
    glTranslatef(-11.3,-1,18);
    glutSolidCube(2);
}

void bed_leg4(void)
{
    glScalef(0.08,1.5,0.05);
    glTranslatef(11.3,-1,18);
    glutSolidCube(2);
    FreeTexture(texture);
}

//---------------------------------------------------------------------







////////////////////////////////////////////////
//         Room Architecture methods          //
////////////////////////////////////////////////

//----------------------------------------------------------------

void floor(void)
{

    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    if(obNum == 1 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images6.bmp",256, 256);
    glPushMatrix();
    glTranslatef(5,0,0);
    glScalef(30.5, 0.4, 30);
    glutSolidCube2 (2.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    FreeTexture(texture);

}


void wall(void)
{
  //  materials(&brass);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    if(obNum == 2 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images6.bmp",256, 256);
    glTranslatef(-10,5.2,11);
    glScalef(0.4,10, 8.2);
    glutSolidCube2 (1.0);
    glTranslatef(0,0,-2.08);
    glScalef(1,1,2.2);
    glutSolidCube2 (1.0);

    glTranslatef(0,-0.23,0.61 );
    glScalef(1,0.5,0.25);
    glutSolidCube2 (1.0);

    glTranslatef(0,1.335,0);
    glScalef(1,0.25,1);
    glutSolidCube (1.0);
    glDisable(GL_TEXTURE_2D);
    FreeTexture(texture);
    glPopMatrix();
}

void wall2(void)
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 3 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images6.bmp",256, 256);
    glTranslatef(20,5.2,11);
    glScalef(0.4,10, 8.2);
    glutSolidCube2 (1.0);
    glTranslatef(0,0,-2.08);
    glScalef(1,1,2.2);
    glutSolidCube2 (1.0);

    glTranslatef(0,-0.23,0.61 );
    glScalef(1,0.5,0.25);

    glTranslatef(0,1.26,0);
    glScalef(1,0.4,1);
    glutSolidCube (1.0);
    glDisable(GL_TEXTURE_2D);
    FreeTexture(texture);

    doorFrame();
}

void wall3(void)
{
    glEnable(GL_TEXTURE_2D);
    if(obNum == 4 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images6.bmp",256, 256);
    glTranslatef(5,5.2,-15);
    glScalef(30,10, 0.4);
    glutSolidCube2 (1.0);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
}

void wall4(void)
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    if(obNum == 5 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images6.bmp",256, 256);
    glTranslatef(5,5.2,15);
    glScalef(30,10, 0.4);
    glutSolidCube2(1.0);
    FreeTexture(texture);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void doorFrame()
{
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
   // texture = LoadTexture( "images.bmp",256, 256);
    if(obNum == 5 || obNum == 0)
        texture = LoadTexture( "blue.bmp",128, 128);
    else
        texture = LoadTexture( "images.bmp",256, 256);
    glTranslatef(-0.5,-0.5,0);
    glScalef(0.2,0.2,0.9);
    glutSolidCube (1.0);
    glTranslatef(0,-10,-0.5);
    glScalef(1,19,0.065);
    glutSolidCube (1.0);
    glTranslatef(0,0,15);
    glutSolidCube (1.0);
    glPopMatrix();
    FreeTexture(texture);

    glDisable(GL_TEXTURE_2D);

}

//-------------------------------------------------------





// Spins the entire rrom on a specified axis
//-------------------------------------------------------
void spin_room (int direction)
{
    if(direction == 1)
        theta [ axis ] += 2;
    else
        theta [ axis ] -= 2;
    if ( theta [ axis ] > 360.0)
        theta [ axis ] -= 360.0;
    glutPostRedisplay ( );

}


//Moves camera position and  viewing point
void move_camera(int a)
{
    if(a == 1)
    {
        xPos++;
        xPos2++;
    }
    else if(a == 2)
    {
        yPos++;
        yPos2++;
    }
    else if(a == 3)
    {
        zPos++;
        zPos2++;
    }
    else if(a == 4)
    {
        xPos--;
        xPos2--;
    }
    else if(a == 5)
    {
        yPos--;
        yPos2--;
    }
    else if(a == 6)
    {
        zPos--;
        zPos2--;
    }

    glutPostRedisplay ( );
}


//move camera looking point using mouse//
//----------------------------------------------------
void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			angle2 += alphaAngle;
			xOrigin = -1;
			yOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
			yOrigin = y;
		}
	}

    if (button == GLUT_RIGHT_BUTTON) {

		gl_select(x,y);
	}
}

//--------------------------------------------------------

void mouse (int x , int y)
{

	// this will only be true when the left button is down
	if (xOrigin >= 0 && yOrigin >= 0)
    {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;
		alphaAngle = (y - yOrigin) * 0.001f;


		// update camera's direction
		lx = sin(angle + deltaAngle) * 80;
		ly = sin(angle2 + alphaAngle) * 80;
		lz = -cos(angle + deltaAngle) * 80;
		//yPos2 = y;
	 	glutPostRedisplay ( );
	}
  //  */
}

void move(int i)
{
    if(i == 1)
        movementX++;
    glTranslatef(movementX, 0, 0);
    glutPostRedisplay ( );
}


//Key input//
void mykey ( int key )
{

    if( key == '6')
        spin_room(1);
    else if( key == '4' )
        spin_room(2);
    else if( key == '1')
        axis = 0;
    else if( key == '2')
        axis = 1;
    else if( key == '3')
        axis = 2;
    else if( key == 's' || key == 'S' )
        move_camera(1);
    else if( key == 'w' || key == 'W')
        move_camera(4);
    else if( key == 'q' || key == 'Q')
        move_camera(2);
    else if( key == 'z' || key == 'Z')
        move_camera(5);
    else if( key == 'a' || key == 'A')
        move_camera(3);
    else if( key == 'd' || key == 'D')
        move_camera(6);
    else if(key == 'p' || key == 'P' )
    {
        if(light_on == 1)
        {
            glEnable(GL_LIGHT1);
            light_on = 2;
        }
        else
        {
            glDisable(GL_LIGHT1);
            light_on = 1;
        }
        glutPostRedisplay ( );
    }

    else if(key == 'o' || key == 'O ' )
    {
        if(light_on2 == 1)
        {
            glEnable(GL_LIGHT2);
            light_on2 = 2;
        }
        else
        {
            glDisable(GL_LIGHT2);
            light_on2 = 1;
        }
        glutPostRedisplay ( );
    }

    else if(key == 'k' || key == 'K')
        movTraverse(&room_node, 1);

    else if(key == 'i' || key == 'i')
        movTraverse(&room_node, 2);

    else if(key == 'u' || key == 'U')
        movTraverse(&room_node, 3);

    else if(key == 'n' || key == 'N')
        movTraverse(&room_node, 4);

    else if(key == 'j' || key == 'J')
        movTraverse(&room_node, 5);

    else if(key == 'l' || key == 'L')
        movTraverse(&room_node, 6);

    else if(key == 'v' || key == 'V')
    {
        if(obNum < 17)
            obNum++;
        else
            obNum = 1;

        glutPostRedisplay();
    }
    else if(key == 'b' || key == 'B')
    {
        if(obNum > 0)
            obNum--;
        else
            obNum = 17;

        glutPostRedisplay();
    }

    else if(key == 't' || key == 'T')
    {
        if(tv_on)
            tv_on = 0;
        else
            tv_on = 1;

        glutPostRedisplay();
    }

    else if(key == '9')
    {
        if(!eject)
        {
            eject = 1;
            inject = 0;
            glutPostRedisplay();
        }
        else
        {
            inject = 1;
            eject = 0;
            glutPostRedisplay();
        }
    }

    else if(key == 'y' || key == 'Y')
    {
        if(lightning == 0)
        {
            lightning = 1;
            if(closed == 0)
                closed = 1;
            else
                closed = 0;

            tv_on = 1;
            glutPostRedisplay();
        }
    }

}

 void list_hits(GLint hits, GLuint *names)
 {
 	int i;

 	/*
 		For each hit in the buffer are allocated 4 bytes:
 		1. Number of hits selected (always one,
 									beacuse when we draw each object
 									we use glLoadName, so we replace the
 									prevous name in the stack)
 		2. Min Z
 		3. Max Z
 		4. Name of the hit (glLoadName)
 	*/

 	printf("%d hits:\n", hits);

 	for (i = 0; i < hits; i++)
 		printf(	"Number: %d\n"
 				"Min Z: %d\n"
 				"Max Z: %d\n"
 				"Name on stack: %d\n",
 				(GLubyte)names[i * 4],
 				(GLubyte)names[i * 4 + 1],
 				(GLubyte)names[i * 4 + 2],
 				(GLubyte)names[i * 4 + 3]
 				);

 	printf("\n");
 }

 void gl_select(int x, int y)
 {
 	GLuint buff[64] = {0};
 	GLint hits, view[4];
 	int id;

 	/*
 		This choose the buffer where store the values for the selection data
 	*/
 	glSelectBuffer(64, buff);

 	/*
 		This retrieve info about the viewport
 	*/
 	glGetIntegerv(GL_VIEWPORT, view);

 	/*
 		Switching in selecton mode
 	*/
 	glRenderMode(GL_SELECT);

 	/*
 		Clearing the name's stack
 		This stack contains all the info about the objects
 	*/
 	glInitNames();

 	/*
 		Now fill the stack with one element (or glLoadName will generate an error)
 	*/
 	glPushName(0);

 	/*
 		Now modify the vieving volume, restricting selection area around the cursor
 	*/
 	glMatrixMode(GL_PROJECTION);
 	glPushMatrix();
 		glLoadIdentity();

 		/*
 			restrict the draw to an area around the cursor
 		*/
 		gluPickMatrix(x, y, 1.0, 1.0, view);
 		gluPerspective(60, 1.0, 0.0001, 1000.0);

 		/*
 			Draw the objects onto the screen
 		*/
 		glMatrixMode(GL_MODELVIEW);

 		/*
 			draw only the names in the stack, and fill the array
 		*/
 		glutSwapBuffers();
 		table();
 		chair();

 		/*
 			Do you remeber? We do pushMatrix in PROJECTION mode
 		*/
 		glMatrixMode(GL_PROJECTION);
 	glPopMatrix();

 	/*
 		get number of objects drawed in that area
 		and return to render mode
 	*/
 	hits = glRenderMode(GL_RENDER);

 	/*
 		Print a list of the objects
 	*/
 	list_hits(hits, buff);

 	/*
 		uncomment this to show the whole buffer
 	* /
 	gl_selall(hits, buff);
 	*/

 	glMatrixMode(GL_MODELVIEW);
 }




void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 100.0);
   else
      glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 100.0);

   // gluLookAt( 30, 15, 0, 0,  0, 0, 0, 1,  0 );

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (800, 800);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutKeyboardFunc (mykey );
   glutMouseFunc(mouseButton);
   glutMotionFunc(mouse);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
       //Load our texture
   glutMainLoop();
   return 0;
}
