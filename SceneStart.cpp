#include "SceneStart.h"
#include "Mouse.h"


SceneStart::SceneStart(){
	setNext( END );
}

SceneStart::~SceneStart( ) {

}

void SceneStart::run( ) {

	TouchPoint* Buttan_End(new TouchPoint( 90, 90 ) );
	Buttan_End->setPos(10, 10);
	Mouse* mousePtr( new Mouse() );

	while ( true ) {
		mousePtr->update( );



		Buttan_End->draw( );
		if (Buttan_End->touch( mousePtr, mousePtr->left_in( ) )) {
			break;
		}

		if ( FrameEnd( ) ) {
			break;
		}
	}

	delete Buttan_End;
	delete mousePtr;

}
