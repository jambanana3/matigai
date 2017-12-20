#include "SceneTest.h"
#include "SceneStart.h"
#include "Mouse.h"
#include "Screen.h"


SceneTest::SceneTest( ) {
	setNext( nullptr );
}

SceneTest::~SceneTest( ) {
}

void SceneTest::run( ) {
	
	int scr_g = LoadGraph( "Ahaikei.png" );
	bool aaaa = 0;
	int peke_g = LoadGraph( "gazo/64peke.png" );

	TouchPoint* Buttan_End(new TouchPoint( 90, 90 ) );
	Buttan_End->setPos(300, 10);
	Mouse* mousePtr( new Mouse( ) );
	Screen* screen( new Screen( scr_g, 50, 150, 500, 300, 900 ) );

	screen->addTouchPoint( new TouchPoint( 20 ), 20, 20 );
	//screen->addScreenItem(new ScreenItem(peke_g, 64, 64), 32, 32);

	while ( true ) {//  ---------　これメインループ　−−−−・・
		mousePtr->update( );



		//DrawRectGraph( 50, 300, 0, 300, 500, 100, scr_g, true, false );
		screen->update( );
		screen->drawAndItem( );
		if( screen->touch( mousePtr, mousePtr->left_in( ) ) ) {
			
		}



		Buttan_End->draw( );
		if (Buttan_End->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneStart( ) );
			break;
		}

		if ( FrameEnd( ) ) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}

	delete Buttan_End;
	delete mousePtr;


}
