#include "SceneStageSelect.h"



SceneStageSelect::SceneStageSelect(){
	setNext(nullptr);
}


SceneStageSelect::~SceneStageSelect()
{
}

//\------ ������̂������牺 (   void Scene,,,::run( ) �̂Ȃ�  ) ---------//

void SceneStageSelect::run() {

	while (true) {//  ---------�@���ꃁ�C�����[�v�@�|�|�|�|�E�E



		if (FrameEnd()) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}

}
