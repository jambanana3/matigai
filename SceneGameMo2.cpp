#include "SceneGameMo2.h"
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

	Mouse* mousePtr(new Mouse());

	int scr_g = LoadGraph("gazo/Ahaikei.png");

	Screen* screenPtr(new Screen(scr_g, 50, 50, 650, 540, 960));

	TouchPoint* t_bel(new TouchPoint(25)); t_bel->setScore(scorePtr, 200);
	screenPtr->addTouchPoint( t_bel,353,115 );

	TouchPoint* t_tori(new TouchPoint(12)); t_tori->setScore(scorePtr, 300);
	screenPtr->addTouchPoint( t_tori, 640, 31);

	TouchPoint* t_sikaku(new TouchPoint(8)); t_sikaku->setScore(scorePtr, 100);
	screenPtr->addTouchPoint( t_sikaku,285,461);

	TouchPoint* t_box(new TouchPoint(27)); t_box->setScore(scorePtr, 500);
	screenPtr->addTouchPoint( t_box,367,467);


	//   650 いかに出すこと。
	int g_item_bel    = LoadGraph("gazo/330-90--45-50.png");
	int g_item_tori   = LoadGraph("gazo/628-19--24-22.png");
	int g_item_sikaku = LoadGraph("gazo/277-453--10-17.png");
	int g_item_box    = LoadGraph("gazo/340-440--55-55.png");

	while (true) {//  ---------　これメインループ　－－－－・・
		mousePtr->update( );

		screenPtr->drawAndItem( );
		screenPtr->update( );

		if ( screenPtr->touch( mousePtr, mousePtr->left_in() ) ) {

		}

		DrawFormatString(10, 10, 0xffffff, "SCORE : %d", scorePtr->_score );

		drawItem( 100, 650, g_item_bel    );
		drawItem( 250, 650, g_item_tori   );
		drawItem( 400, 650, g_item_sikaku );
		drawItem( 550, 650, g_item_box    );


		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}
	delete mousePtr;
	delete screenPtr;
}

void drawItem(int x, int y, int g_h) {
	const int size_x = 100;
	const int size_y = 100;

	DrawModiGraph(x, y, x + size_x, y, x + size_x, y + size_y, x, y + size_y, g_h, false);


}

