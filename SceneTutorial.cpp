#include "SceneTutorial.h"



SceneTutorial::SceneTutorial( ) {
	setNext( nullptr );
}


SceneTutorial::~SceneTutorial( ) {
}

//\------ ������̂������牺 (   void Scene,,,::run( ) �̂Ȃ�  ) ---------//
\
void SceneTutorial::run( ) {

	while (true) {//  ---------�@���ꃁ�C�����[�v�@�|�|�|�|�E�E


		if (FrameEnd()) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}
}