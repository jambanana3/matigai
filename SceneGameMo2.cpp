#include "SceneGameMo2.h"
#include "SceneRisult.h"

#include "Mouse.h"
#include "Screen.h"
#include "ScreenItem.h"
#include "TouchPoint.h"


SceneGameMo2::SceneGameMo2( ) {
	setNext( nullptr );
}

SceneGameMo2::~SceneGameMo2( ) {
}



void SceneGameMo2::run() {
	DataScore* scorePtr(new DataScore( ) );

	int scr_g = LoadGraph( "gazou/mo/umi2.png" );

	Mouse* mousePtr(new Mouse( ) );

	Screen* screenPtr(new Screen(scr_g, 50, 50, 650, 630, 1120));

	TouchPoint* t_same(new TouchPoint(100, 63)); t_same->setScore(scorePtr, 200);
	screenPtr->addTouchPoint( t_same,119,166 );

	TouchPoint* t_niji(new TouchPoint(169,66)); t_niji->setScore(scorePtr, 300);
	screenPtr->addTouchPoint( t_niji, 120,365);

	TouchPoint* t_sirasu(new TouchPoint(162,112)); t_sirasu->setScore(scorePtr, 100);
	screenPtr->addTouchPoint( t_sirasu,170,495);

	TouchPoint* t_tatu(new TouchPoint(170,170)); t_tatu->setScore(scorePtr, 500);
	screenPtr->addTouchPoint( t_tatu,843,60);





	TouchPoint* end_botan( new TouchPoint( 100, 50 ) );
	end_botan->setPos( 700, 700 );


	//   650 いかに出すこと。
	int g_item_same    = LoadGraph("gazou/mo/119-166--100-63.png");
	int g_item_niji    = LoadGraph("gazou/mo/120-165--169-66.png");
	int g_item_siras   = LoadGraph("gazou/mo/170-495--162-112.png");
	int g_item_tatu    = LoadGraph("gazou/mo/843-60--170-170.png");

	while (true) {//  ---------　これメインループ　－－－－・・
		mousePtr->update( );

		screenPtr->drawAndItem( );
		screenPtr->update( );

		if ( screenPtr->touch( mousePtr, mousePtr->left_in( ) ) ) {

		}

		DrawFormatString(10, 10, 0xffffff, "SCORE : %d", scorePtr->_score );

		drawItem( 100, 700, g_item_same    );
		drawItem( 250, 700, g_item_niji   );
		drawItem( 400, 700, g_item_siras );
		drawItem( 550, 700, g_item_tatu    );

		DrawFormatString( 700 + 5, 700 + 5, 0xffffff, "終わる" );
		if( end_botan->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneRisult( scorePtr ) );
			break;
		}

		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}
	delete mousePtr;
	delete screenPtr;
}

void SceneGameMo2::drawItem(int x, int y, int g_h) {
	const int size_x = 100;
	const int size_y = 100;

	DrawModiGraph(x, y, x + size_x, y, x + size_x, y + size_y, x, y + size_y, g_h, false);


}

