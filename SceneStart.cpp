#include "SceneStart.h"
#include "Mouse.h"
#include "Screen.h"


SceneStart::SceneStart(){
	setNext( nullptr );
}

SceneStart::~SceneStart( ) {

}

//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//

void SceneStart::run( ) {

	int haikei = LoadGraph( "gazou/matigai.png" );
	int start = LoadGraph( "gazou/スタート.png" );
	int end = LoadGraph( "gazou/おわり.png" );

	TouchPoint* Buttan_End(new TouchPoint( 90, 90 ) );
	Buttan_End->setPos(10, 10);
	TouchPoint* Buttan_Start(new TouchPoint( 400, 100 ) );
	Buttan_Start->setPos(200, 500);
	TouchPoint* Buttan_Ending(new TouchPoint( 400, 100 ) );
	Buttan_Ending->setPos(200, 650);

	Mouse* mousePtr( new Mouse() );


	while ( true ) {//  ---------　これメインループ　－－－－・・
		mousePtr->update( );

		DrawGraph( 0, 0, haikei, true );
		DrawGraph( 200, 500, start, true );
		DrawGraph( 200, 650, end, true );



		Buttan_End->draw( );

		
		if (Buttan_End->touch( mousePtr, mousePtr->left_in( ) )) {
			break;
		}

		if (Buttan_Start->touch(mousePtr, mousePtr->left_in( ) ) ) {
			break;
		}

		if (Buttan_Ending->touch(mousePtr, mousePtr->left_in( ) ) ) {
			break;
		}

		if ( FrameEnd( ) ) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}

	delete Buttan_End;
	delete mousePtr;

}
