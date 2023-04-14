#include <Novice.h>
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<vector.h>

const char kWindowTitle[] = "LC2B_19_�c�d�L�o�V�}�T�~_MT3";



// Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {


	// ���C�u�����̏�����
	Novice::Initialize(kWindowTitle, 1280, 720);

	// �L�[���͌��ʂ��󂯎�锠
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 v1 = {
		1.0f,
		3.0f,
		-5.0f
	};
	Vector3 v2 = {
		4.0f,
		-1.0f,
		2.0f
	};
	float k = 4.0f;

	int krowHeight = 20;

	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();

		// �L�[���͂��󂯎��
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);


		///
		/// ���X�V������������
		///

		Vector3 resultAdd = Add(v1, v2);
		Vector3 resultSubtract = Subtract(v1, v2);
		Vector3 resultMultiply = Multiply(k, v1);
		float resultDot = Dot(v1, v2);
		float resultLength = Length(v1);
		Vector3 resultNormalize = Normalize(v2);

		///
		/// ���X�V���������܂�
		///

		///
		/// ���`�揈����������
		///

		VectorScreenPrintf(0, 0, resultAdd, ": Add");

		VectorScreenPrintf(0, kRowHeight, resultSubtract, ": Subtract");

		VectorScreenPrintf(0, kRowHeight*2, resultMultiply, ": Multiply");

		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f   :Dot", resultDot);

		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f   :Length", resultLength);

		VectorScreenPrintf(0, kRowHeight*5, resultNormalize, ": Normalize");





		///
		/// ���`�揈�������܂�
		///

		// �t���[���̏I��
		Novice::EndFrame();

		// ESC�L�[�������ꂽ�烋�[�v�𔲂���
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ���C�u�����̏I��
	Novice::Finalize();
	return 0;
}
