#include "SceneGame.h"



SceneGame::SceneGame(){
	setNext( nullptr );
}


SceneGame::~SceneGame()
{
}

//\------ ������̂������牺 (   void Scene,,,::run( ) �̂Ȃ�  ) ---------//


void SceneGame::run( ) {

	while (true) {//  ---------�@���ꃁ�C�����[�v�@�|�|�|�|�E�E




		if (FrameEnd()) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}

}