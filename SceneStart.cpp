#include "SceneStart.h"
#include "Mouse.h"


SceneStart::SceneStart(){
	setNext( nullptr );
}

SceneStart::~SceneStart( ) {

}

//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//

void SceneStart::run( ) {

	TouchPoint* Buttan_End(new TouchPoint( 90, 90 ) );
	Buttan_End->setPos(10, 10);
	Mouse* mousePtr( new Mouse() );

	while ( true ) {//  ---------　これメインループ　－－－－・・
		mousePtr->update( );



		Buttan_End->draw( );
		if (Buttan_End->touch( mousePtr, mousePtr->left_in( ) )) {
			break;
		}

		if ( FrameEnd( ) ) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}

	delete Buttan_End;
	delete mousePtr;

}
