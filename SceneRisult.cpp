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

	TouchPoint* go_start( new TouchPoint( 300,100 ) );
	go_start->setPos( 100,400 );

	while ( true ) {
		mousePtr->update( );
		
		DrawFormatString( 100, 100, 0xffffff, "���ʔ��\�I�I" );
		DrawFormatString( 100,200, 0xffffff,"SCORE = %d", _scorePtr->_score );

		DrawFormatString( 100 + 20, 400 + 20, 0xffffff, "�X�^�[�g�ɖ߂�" );
		go_start->draw( );
		if( go_start->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneStart( ) );
			break;
		}

		if (FrameEnd()) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}
	delete mousePtr;
	delete go_start;

}


