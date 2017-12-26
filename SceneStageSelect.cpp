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

//\------ ������̂������牺 (   void Scene,,,::run( ) �̂Ȃ�  ) ---------//

void SceneStageSelect::run() {
	Mouse* mousePtr( new Mouse( ) );
	
	TouchPoint* go_game_mo2( new TouchPoint( 300,100 ) );
	go_game_mo2->setPos( 100, 100 );

	TouchPoint* go_game_yu( new TouchPoint( 300,100 ) );
	go_game_yu->setPos( 100, 300 );


	while (true) {//  ---------�@���ꃁ�C�����[�v�@�|�|�|�|�E�E
		mousePtr->update( );

		DrawFormatString( 100+5,300+5,0xffffff, "�X�e�[�W�@yu" );
		go_game_yu->draw( );
		if ( go_game_yu->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneGameYu( ) );
			break;
		}

		DrawFormatString( 100+5,100+5,0xffffff, "�X�e�[�W�@mo" );
		go_game_mo2->draw( );
		if ( go_game_mo2->touch( mousePtr, mousePtr->left_in( ) ) ) {
			setNext( new SceneGameMo2( ) );
			break;
		}



		if (FrameEnd()) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}
	delete mousePtr;
	delete go_game_mo2;
	delete go_game_yu;

}
