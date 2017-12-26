#include "SceneStageSelect.h"
#include "SceneGameMo2.h"
#include "SceneGameYu.h"

#include "DataScore.h"
#include "Mouse.h"
#include "TouchPoint.h"


SceneStageSelect::SceneStageSelect( ) {
	setNext(nullptr);
}


SceneStageSelect::~SceneStageSelect( ) {
}

//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//

void SceneStageSelect::run() {
	Mouse* mousePtr( new Mouse( ) );
	
	TouchPoint* go_game_mo2( new TouchPoint( 300,100 ) );
	go_game_mo2->setPos( 100, 100 );

	TouchPoint* go_game_yu( new TouchPoint( 300,100 ) );
	go_game_yu->setPos( 100, 300 );


	while (true) {//  ---------　これメインループ　－－－－・・
		mousePtr->update( );

		DrawFormatString( 100+5,300+5,0xffffff, "ステージ　yu" );
		go_game_yu->draw( );
		if ( go_game_yu->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneGameYu( ) );
			break;
		}

		DrawFormatString( 100+5,100+5,0xffffff, "ステージ　mo" );
		go_game_mo2->draw( );
		if ( go_game_mo2->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneGameMo2( ) );
			break;
		}



		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}
	delete mousePtr;
	delete go_game_mo2;
	delete go_game_yu;

}
