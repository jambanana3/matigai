#include "SceneOption.h"



SceneOption::SceneOption( ) {
	setNext( nullptr );
}


SceneOption::~SceneOption( ) {
}


//\------ ������̂������牺 (   void Scene,,,::run( ) �̂Ȃ�  ) ---------//

void SceneOption::run( ) {

	while (true) {//  ---------�@���ꃁ�C�����[�v�@�|�|�|�|�E�E


		if (FrameEnd()) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}

}