#include "SceneGameMo.h"
#include "Mouse.h"
#include "Screen.h"
#include "TouchPoint.h"



SceneGameMo::SceneGameMo( ) {
	setNext( nullptr );
}


SceneGameMo::~SceneGameMo( ) {
}

//\------ ������̂������牺 (   void Scene,,,::run( ) �̂Ȃ�  ) ---------//

void SceneGameMo::run() {

	Mouse* mousePtr( new Mouse( ) );

	int scr_g = LoadGraph( "Ahaikei.png" );
	//Screen* screenPtr( new Screen( scr_g,  ) );

	while (true) {//  ---------�@���ꃁ�C�����[�v�@�|�|�|�|�E�E






		if (FrameEnd()) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}

}
