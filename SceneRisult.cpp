#include "SceneRisult.h"
#include "SceneStart.h"
#include "DataScore.h"
#include "Mouse.h"
#include "TouchPoint.h"


SceneRisult::SceneRisult( DataScore* scorePtr ) :
_scorePtr( scorePtr ) {
	setNext( nullptr );
}

SceneRisult::~SceneRisult( ) {
	delete _scorePtr;
}

void SceneRisult::run( ) {
	Mouse* mousePtr(new Mouse());

	TouchPoint* go_start( new TouchPoint( 100,300 ) );
	go_start->setPos( 400,100 );

	while ( true ) {
		
		DrawFormatString( 100, 100, 0xffffff, "Œ‹‰Ê”­•\II" );
		DrawFormatString( 100,200, 0xffffff,"SCORE = %d", _scorePtr->_score );


		go_start->draw( );
		if( go_start->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneStart( ) );
			break;
		}


	}

}


