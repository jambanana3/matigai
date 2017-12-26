#include "SceneGameYu.h"
#include "SceneRisult.h"

#include "Mouse.h"
#include "Screen.h"
#include "TouchPoint.h"
#include "DataScore.h"

SceneGameYu::SceneGameYu(){
	setNext( nullptr );
}


SceneGameYu::~SceneGameYu()
{
}


void SceneGameYu::run( ) {
	DataScore* scorePtr(new DataScore( ) );

	Mouse* mousePtr(new Mouse());
	int scr_g = LoadGraph("gazou/Screen.png");

	Screen* screenPtr(new Screen(scr_g, 50, 50, 500, 480, 640));

	TouchPoint* t_kuwa(new TouchPoint(50)); t_kuwa->setScore(scorePtr, 200);
	screenPtr->addTouchPoint( t_kuwa,105,301 );

	TouchPoint* t_tonbo(new TouchPoint(50)); t_tonbo->setScore(scorePtr, 300);
	screenPtr->addTouchPoint( t_tonbo, 195, 111);

	TouchPoint* t_tentou(new TouchPoint(35)); t_tentou->setScore(scorePtr, 100);
	screenPtr->addTouchPoint( t_tentou,402,198);


	TouchPoint* end_b( new TouchPoint( 100, 700 ) ); 
	end_b->setPos( 620, 50 );


	int g_item_kuwa    = LoadGraph("gazou/100-300_101-111.png");
	int g_item_tonbo   = LoadGraph("gazou/200-100_118-104.png");
	int g_item_tentou  = LoadGraph("gazou/400-200_88-76.png");

	while (true) {//  ---------　これメインループ　－－－－・・
		mousePtr->update( );

		screenPtr->drawAndItem( );
		screenPtr->update( );

		if ( screenPtr->touch( mousePtr, mousePtr->left_in() ) ) {

		}

		DrawFormatString(10, 10, 0xffffff, "SCORE : %d", scorePtr->_score );

		drawItem( 100, 650, g_item_kuwa    );
		drawItem( 250, 650, g_item_tonbo   );
		drawItem( 400, 650, g_item_tentou );

		DrawFormatString( 620 + 10, 400, GetColor( 255,255,255 ), "終わる" );
		end_b->draw(  );
		if ( end_b->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneRisult( scorePtr ) );
			break;
		}

		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}
	delete mousePtr;
	delete screenPtr;
	delete end_b;

	DeleteGraph( g_item_kuwa   );
	DeleteGraph( g_item_tonbo  );
	DeleteGraph( g_item_tentou );
}

void SceneGameYu::drawItem(int x, int y, int g_h) {
	const int size_x = 100;
	const int size_y = 100;

	DrawModiGraph(x, y, x + size_x, y, x + size_x, y + size_y, x, y + size_y, g_h, false);


}
