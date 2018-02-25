//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.8
// ���e�@�FSpriteStudio�̋@�\���ȒP�ɂ܂Ƃ߂����[�V�����N���X
//-------------------------------------------------------------
#pragma once
#include <ssbpLib\SS5Player.h>
#include <Device\projector.h>
#include <Color\color.h>
#include <Math\vector3.h>
#include <Math\vector2.h>

namespace MotionSystem
{
	class Motion 
	{
	public:
		///<summary>���[�V�����N���X</summary>
		///<param name="asset_name">ssbp�t�@�C�����i�g���q�����j</param>
		Motion(string asset_name);
		Motion(const Motion&);
		~Motion();

		///<summary>Position�Ȃǂ̏����l��ݒ�</summary>
		void Initialize();
		///<summary>�f�[�^���</summary>
		void Release();
		///<summary>�v���C���郂�[�V����</summary>
		///<param name="motion_name">ssae�t�@�C�����i�g���q�����j/ Animation��</param>
		///<param name="loop">���񃋁[�v���邩(���� = 0)</param>
		void Play(string motion_name, int loop = 0);
		///<summary>�f�[�^���</summary>
		void ChangeSpriteSheet(string sheet_name);

		///<summary>�X�V����</summary>
		void Update(float frame = 1 / 60.0f);
		///<summary>�`�揈��</summary>
		void Draw();

		///<summary>�ʒu�ݒ�</summary>
		void SetPosition(Math::Vector3 position);
		///<summary>�F�ݒ�</summary>
		void SetColor(Color color);
		///<summary>�傫���ݒ�</summary>
		void SetScale(Math::Vector2 scale);
		///<summary>���]���邩</summary>
		///<param name="x">x���ɑ΂��Ĕ��]���邩</param>
		///<param name="y">y���ɑ΂��Ĕ��]���邩</param>
		void Flip(bool x, bool y);
		///<summary>�A�j���[�V�����Đ��I�����i�������[�v�͖����j</summary>
		bool IsCurrentMotionEnd();

		///<summary>Frame���ݒ�</summary>
		void SetFrame(int frame);

	private:
		ss::Player* m_motion_player;						//motion Player
		std::string m_current_motion;						//���݂̃��[�V����
		std::shared_ptr<Device::Projector> m_projector;		//�`��C���p�iCamera�j

		Math::Vector3 m_position;							//�ʒu
		Math::Vector2 m_scale;								//�傫��
	};
}